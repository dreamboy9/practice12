#include "cpcheat.h"

struct player_s players[32];

int
getteambymodel(char* model)
{
    if((strstr(model, "arctic") || strstr(model, "guerilla") || strstr(model, "leet") || strstr(model, "terror")))
        return TEAM_RED;
    else
        return TEAM_BLUE;

}

void
addglowshells(int idx)
{
    struct player_s *player = &players[idx];
    color24 color = { 0, 255, 0 };
    if(target != player->idx) {
        switch(player->team) {
            case TEAM_BLUE:
            color.g = 174;
            color.b = 255;
            break;
            case TEAM_RED:
            color.r = 255;
            color.g = color.b = 46;
            break;
        }
    }
    player->ent->curstate.renderfx = kRenderFxGlowShell;
    player->ent->curstate.rendercolor.r = color.r;
    player->ent->curstate.rendercolor.g = color.g;
    player->ent->curstate.rendercolor.b = color.b;
    player->ent->curstate.renderamt = 5;
}

void
drawespforplayer(player_t *player)
{
    float coords2d[2] = { 0.0f, 0.0f };
    color24 color = { 0, 255, 0 };

    if(!get2dcoords(&player->origin, coords2d)) return;

    if(target != player->idx) {
        switch(player->team) {
            case TEAM_BLUE:
            color.g = 174;
            color.b = 255;
            break;
            case TEAM_RED:
            color.r = 255;
            color.g = color.b = 46;
            break;
        }
    }
    drawstring((int)coords2d[0], (int)coords2d[1], color.r, color.g, color.b, 255, true, true, "%s", player->playerinfo.name);
}

void inline
playeresp()
{
    struct player_s *player = 0;
    int i;

    for(i = 1; i <= 31; i++) {
        player = &players[i];
        if(!player->pvs) continue;
        if(player->team == TEAM_UNASSIGNED) player->team = getteambymodel(player->playerinfo.model);

        if(settings.esp->value) drawespforplayer(player);
        if(settings.drawaimpos->value) drawaimpos(player);
    }
}


BOOL
get2dcoords(vec3_t* origin, float *out)
{
    if(Engfuncs.GetLocalPlayer() == NULL) return false;
    int result = Engfuncs.pTriAPI->WorldToScreen((float*)origin, out);
    if( out[0] < 1 && out[1] < 1 && out[0] > -1 && out [1] > -1 && !result )
    {
        out[0] = out[0] * centerX + centerX;
        out[1] = -out[1] * centerY + centerY;
        return true;
    }
    return false;
}

void inline
clearplayerstates()
{
    int i;
    for(i = 0; i <= 31; i++) {
        players[i].pvs = false;
        players[i].gotaimpos = false;
    }
}

void
updatelocalplayer()
{
    player_t *player = &players[Engfuncs.GetLocalPlayer()->index];
    player->ent = Engfuncs.GetEntityByIndex(player->idx);
    Engfuncs.pfnGetPlayerInfo(player->idx, &player->playerinfo);
    if(modid == MOD_CS) return;
    if(modid == MOD_HLDM) {
        player->team = TEAM_RED;
        return;
    }
    if(player->ent->curstate.team) {
        if(player->ent->curstate.team == TEAM_RED)
            player->team = TEAM_RED;
        else
            player->team = TEAM_BLUE;
        return;
    }
    player->team = getteambymodel(player->playerinfo.model);
}

void
initplayers()
{
    int i;
    for(i = 0; i <= 31; i++) {
        players[i].team = TEAM_UNASSIGNED;
        players[i].ent = 0;
        players[i].idx = i;
        players[i].pvs = false;

        memset(&players[i].playerinfo, 0, sizeof(struct hud_player_info_s));
    }
}
