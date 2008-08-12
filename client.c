#include "cpcheat.h"

struct exporttable_s orgexporttable;
struct exporttable_s *exporttable;

BOOL alive = true;

int
HUD_Redraw(float flTime, int intermission)
{
    int result = orgexporttable.HUD_Redraw(flTime, intermission);
    updatelocalplayer();

    findtarget();
    drawstring(100, 100, 255, 0, 0, 255, false, false, "target: %i", target);
    drawstring(100, 110, 255, 0, 0, 255, false, false, "my team: %i", players[Engfuncs.GetLocalPlayer()->index].team);
    playeresp();
    if(consoleactive) drawconsole();

    clearplayerstates();
    return result;
}

int
HUD_Key_Event(int down, int keynum, const char *pszCurrentBinding)
{
    int retval = orgexporttable.HUD_Key_Event(down, keynum, pszCurrentBinding);
    if(down && keynum == 147) {
        consoleactive = !consoleactive;
        return 0;
    }
    else if(down && keynum != 147 && consoleactive) {
        conreportkey(tolower(keynum));
        return 0;
    }
    return retval;
}

int
HUD_AddEntity(int type, struct cl_entity_s* ent, const char *modelname)
{
    int idx = ent->index;

    if(ent->player && ent->curstate.solid) {
        ent->curstate.rendermode = kRenderNormal;
        struct player_s *player = &players[idx];

        if(!player->team) {
            if(ent->curstate.team == TEAM_RED)
                player->team = TEAM_RED;
            else
                player->team = TEAM_BLUE;
        }

        player->ent = ent;
        if((ent->curstate.weaponmodel && (modid == MOD_HLDM || modid == MOD_DOD)) || (modid != MOD_HLDM && modid != MOD_DOD))
            player->pvs = true;
        VectorCopy(ent->origin, player->origin);
        Engfuncs.pfnGetPlayerInfo(idx, &player->playerinfo);
        if(settings.glowshells->value) addglowshells(idx);
    }

    return orgexporttable.HUD_AddEntity(type, ent, modelname);
}

void
HUD_PlayerMove(struct playermove_s *ppmove, int server)
{
    Engfuncs.pEventAPI->EV_LocalPlayerViewheight(viewheight);
    viewheight[0] += ppmove->origin[0];
	viewheight[1] += ppmove->origin[1];
	viewheight[2] += ppmove->origin[2];
    orgexporttable.HUD_PlayerMove(ppmove, server);
    VectorCopy(ppmove->angles, angles);
}

float punchangle[3];
void
CL_CreateMove(float frametime, struct usercmd_s *cmd, int active)
{
    orgexporttable.CL_CreateMove(frametime, cmd, active);

    if(target && alive && settings.aimbot->value) {
        doaim(cmd->viewangles);
        Engfuncs.SetViewAngles(cmd->viewangles);
    }

    cmd->viewangles[0] -= punchangle[0];
    cmd->viewangles[1] -= punchangle[1];
}

void
V_CalcRefdef(struct ref_params_s *pparams)
{
    static float aimangles[3];

    VectorCopy(pparams->punchangle, punchangle);
    pparams->punchangle[0] = pparams->punchangle[1] = pparams->punchangle[2] = 0;

    /*if(target && alive && settings.aimbot->value) {
        doaim(aimangles);
        VectorCopy(aimangles, pparams->viewangles);
        VectorCopy(aimangles, pparams->cl_viewangles);
    }*/

    orgexporttable.V_CalcRefdef(pparams);
}

void
hookclient()
{

    setupdisplaycenter();

    const char *gamedir = Engfuncs.pfnGetGameDirectory();
    if(!strcmp(gamedir, "cstrike"))
        modid = MOD_CS;
    else if(!strcmp(gamedir, "dod"))
        modid = MOD_DOD;
    else if(!strcmp(gamedir, "tfc"))
        modid = MOD_TFC;
    else if(!strcmp(gamedir, "valve"))
        modid = MOD_HLDM;

    addline("running on mod %s", gamedir);

    while(!exporttable->HUD_Init)
        Sleep(50);
    memcpy(&orgexporttable, exporttable, sizeof(struct exporttable_s));

    exporttable->HUD_Redraw = &HUD_Redraw;
    exporttable->HUD_Key_Event = &HUD_Key_Event;
    exporttable->HUD_AddEntity = &HUD_AddEntity;
    exporttable->HUD_PlayerMove = &HUD_PlayerMove;
    exporttable->CL_CreateMove = &CL_CreateMove;
    exporttable->V_CalcRefdef = &V_CalcRefdef;
}
