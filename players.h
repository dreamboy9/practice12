#ifndef _PLAYERS_H
#define _PLAYERS_H

typedef enum {
    TEAM_UNASSIGNED = 0,
    TEAM_BLUE,
    TEAM_RED
} team_t;

typedef struct player_s
{
    vec3_t origin;

    vec3_t aimpos;
    BOOL gotaimpos;

    BOOL pvs;
    int idx;
    team_t team;
    struct cl_entity_s *ent;
    struct hud_player_info_s playerinfo;
} player_t;

struct player_s players[32];

void initplayers();
void inline playeresp();
void inline clearplayerstates();
void updatelocalplayer();
BOOL get2dcoords(vec3_t* origin, float *out);

#endif
