#include "cpcheat.h"
#include <stdio.h>

struct cl_enginefuncs_s *pEngfuncs;
struct cl_enginefuncs_s Engfuncs;
struct engine_studio_api_s *pStudio;
struct r_studio_interface_s **ppStudioInterface;
struct r_studio_interface_s StudioInterface;

int centerX = 0, centerY = 0;
SCREENINFO scrinfo;

int
StudioDrawPlayer(int flags, struct entity_state_s *pplayer)
{
    unsigned int i;

    if(settings.wallhack->value) {
        glDepthRange(0.0, 0.5);
        StudioInterface.StudioDrawPlayer(flags, pplayer);
        glDepthRange(0.0, 1.0); // logged with glGetFloatv to get previous value, is constant
    }

    getheadpos(pplayer->number);
    return StudioInterface.StudioDrawPlayer(flags, pplayer);
}

void
setupdisplaycenter()
{
    scrinfo.iSize = sizeof(SCREENINFO);
    Engfuncs.pfnGetScreenInfo(&scrinfo);
    centerX = scrinfo.iWidth/2;
    centerY = scrinfo.iHeight/2;

    initconsole();
}

void
findengine()
{
    unsigned int i;

    while(TRUE) {
        HANDLE hHL = GetModuleHandle(NULL);
        char* pData = (char*)hHL;
        char* pszScreenFade = NULL;

        for(i = 0; i < 0x1EEEEEE; i++) {
            if(pData[0+i] == 'e' && pData[1+i] == 'n' && pData[2+i] == 'F' && pData[3+i] == 'a') {
                pszScreenFade = &pData[i-4];
                break;
            }
        }
        if(pszScreenFade) {
            char Pattern[5] = { 0x68, 0x00, 0x00, 0x00, 0x00 };
            memcpy((void*)((char*)(&Pattern)+1), &pszScreenFade, 4);
            for(i = 0; i < 0x1EEEEEE; i++) {
                if(pData[0+i] == Pattern[0] && pData[1+i] == Pattern[1] && pData[2+i] == Pattern[2] && pData[3+i] == Pattern[3] && pData[4+i] == Pattern[4]) {
                    pEngfuncs = *(struct cl_enginefuncs_s**)(pData+i+13);
                    hookengine();
                    return;
                }
            }
        }

        Sleep(50);
    }
}

void
hookengine()
{
    memcpy(&Engfuncs, pEngfuncs, sizeof(struct cl_enginefuncs_s));

    pEngfuncs->pfnHookUserMsg = &pfnHookUserMsg;

    while(IsBadReadPtr(ppStudioInterface, sizeof(int)))
        Sleep(50);
    struct r_studio_interface_s *pStudioInterface = *ppStudioInterface;
    memcpy(&StudioInterface, pStudioInterface, sizeof(struct r_studio_interface_s));
    pStudioInterface->StudioDrawPlayer = &StudioDrawPlayer;

    hookcmd();
}
