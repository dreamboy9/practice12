#include "cpcheat.h"

int target = 0;
float viewheight[3];
float angles[3];

BOOL
pathfree(float *from, float *to)
{
    pmtrace_t tr;
    Engfuncs.pEventAPI->EV_PlayerTrace(from, to, PM_GLASS_IGNORE, Engfuncs.GetLocalPlayer()->index, &tr);
    return (tr.fraction == 1.0);
}

double
GetAimingFov(player_t *player)
{
	double vec[3], view[3];
	double dot;

	float* origin = player->ent->origin;
	view[0] = origin[0] - viewheight[0];
	view[1] = origin[1] - viewheight[1];
	view[2] = origin[2] - viewheight[2];

	dot = sqrt(view[0] * view[0] + view[1] * view[1] + view[2] * view[2]);
	dot = 1/dot;

	vec[0] = view[0] * dot;
	vec[1] = view[1] * dot;
	vec[2] = view[2] * dot;

	view[0] =  sin((angles[1] + 90) * (M_PI / 180));
	view[1] = -cos((angles[1] + 90) * (M_PI / 180));
	view[2] = -sin(angles[0] * (M_PI / 180));

	dot = view[0] * vec[0] + view[1] * vec[1] + view[2] * vec[2];

	return dot;
}

void
getheadpos(int index)
{
    player_t *player = &players[index];
    if(!player->gotaimpos && player->pvs) {
        vec3_t min, max;

        model_t *model = pStudio->SetupPlayerModel(index);
        studiohdr_t *studioheader = (studiohdr_t*)pStudio->Mod_Extradata(model);
        TransformMatrix *pbonetransform = (TransformMatrix*)pStudio->StudioGetBoneTransform();
        mstudiobone_t *pbones = (mstudiobone_t *)((byte *)studioheader + studioheader->boneindex);

        unsigned int i;
        for(i = 0; i < studioheader->numbones; i++) {
            if(strstr(pbones[i].name, "Head")) {
                // Bone 7 = Bip01 Head = Hitbox 11
                player->aimpos[ 0 ] = (*pbonetransform)[ 7 ][ 0 ][ 3 ];
                player->aimpos[ 1 ] = (*pbonetransform)[ 7 ][ 1 ][ 3 ];
                player->aimpos[ 2 ] = (*pbonetransform)[ 7 ][ 2 ][ 3 ] + 5.0f; // seems to work well
                if(GetAimingFov(player) < (40.0-180.0)/-180.0) {
                    VectorCopy(player->ent->origin, player->aimpos);
                }
                player->gotaimpos = true;
            }
        }
    }
}

void
drawaimpos(player_t *player)
{
    float out[2];
    if(!get2dcoords(&player->aimpos, out)) return;
    Engfuncs.pfnFillRGBA((int)out[0], (int)out[1], 1, 1, 255, 255, 255, 255);
}

BOOL isValidEnt(cl_entity_t *ent)
{
 if(ent && (ent != pEngfuncs->GetLocalPlayer()) && ent->player && !ent->curstate.spectator && ent->curstate.solid && !(ent->curstate.messagenum < pEngfuncs->GetLocalPlayer()->curstate.messagenum))
     return true;
 else
     return false;
}

void
findtarget()
{
    int i;
    BOOL visible;
    target = 0;

    int myteam = players[Engfuncs.GetLocalPlayer()->index].team;

    for(i = 1; i <= 31; i++) {
        if(!players[i].pvs || myteam == players[i].team || i == Engfuncs.GetLocalPlayer()->index) continue;
        if(!isValidEnt(players[i].ent)) continue;
        if(pathfree(viewheight, players[i].aimpos)) {
            target = i;
            return;
        }
        continue;
    }
}

void VectorAngles( const float *forward, float *angles )
{
	float	tmp, yaw, pitch;

	if (forward[1] == 0 && forward[0] == 0)
	{
		yaw = 0;
		if (forward[2] > 0)
			pitch = 90.0;
		else
			pitch = 270.0;
	}
	else
	{
		yaw = (float)(atan2(forward[1], forward[0]) * 180.0 / M_PI);

		if (yaw < 0) yaw += 360.0;

		tmp = (float)sqrt (forward[0]*forward[0] + forward[1]*forward[1]);

		pitch = (float)(atan2(forward[2], tmp) * 180 / M_PI);
	}

	angles[0] = -pitch;
	angles[1] = yaw;
	angles[2] = 0;
}

struct r_studio_interface_s StudioInterface;

void
doaim(float *viewangles)
{
    vec3_t angle, delta;
    player_t *player = &players[target];

    delta[0] = player->aimpos[0] - viewheight[0];
    delta[1] = player->aimpos[1] - viewheight[1];
    delta[2] = player->aimpos[2] - viewheight[2];

	VectorAngles(delta, angle);

	if (angle[0]>180) angle[0]-=360;
	if (angle[1]>180) angle[1]-=360;

    VectorCopy(angle, viewangles);
}
