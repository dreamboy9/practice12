#ifndef _ENGINE_H
#define _ENGINE_H

struct cl_enginefuncs_s *pEngfuncs;
struct cl_enginefuncs_s Engfuncs;
struct engine_studio_api_s *pStudio;
struct r_studio_interface_s **ppStudioInterface;

int centerX, centerY;

void setupdisplaycenter();
void findengine();
void engdrawstring(int x, int y, int r, int g, int b, BOOL center, char* text);
void hookengine();

#endif
