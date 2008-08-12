#ifndef _AIMBOT_H
#define _AIMBOT_H

void findtarget();
void drawaimpos(player_t *player);
void doaim(float *viewangles);
int target;
float viewheight[3];
float angles[3];

#endif
