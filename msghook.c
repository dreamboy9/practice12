#include "cpcheat.h"

pfnUserMsgHook pTeamInfo = 0;
pfnUserMsgHook pResetHUD = 0;

int
TeamInfo(const char *pszName, int iSize, void *pbuf)
{
    BEGIN_READ(pbuf, iSize);
	int px = READ_BYTE();
	char *teamtext = READ_STRING();
	struct player_s *player = &players[px];

	if(!strcmp(teamtext, "TERRORIST") || !strcmp(teamtext, "Red"))
        player->team = TEAM_RED;
    else if(!strcmp(teamtext, "CT") || !strcmp(teamtext, "Blue"))
        player->team = TEAM_BLUE;
    else
        player->team = TEAM_UNASSIGNED;

    return (*pTeamInfo)(pszName, iSize, pbuf);
}

int
ResetHUD(const char *pszName, int iSize, void *pbuf)
{
    target = 0;
    int i;
    for(i = 0; i <= 31; i++) {
        players[i].pvs = false;
        players[i].gotaimpos = false;
        if(modid != MOD_CS)
            players[i].team = TEAM_UNASSIGNED;
    }
    return (*pResetHUD)(pszName, iSize, pbuf);
}

#define INTERCEPTMSG(name) if(!strcmp(szMsgName, #name)) { p##name = pfn; return Engfuncs.pfnHookUserMsg(szMsgName, name); }

int
pfnHookUserMsg(char *szMsgName, pfnUserMsgHook pfn)
{
    INTERCEPTMSG(TeamInfo);
    INTERCEPTMSG(ResetHUD);
    return Engfuncs.pfnHookUserMsg(szMsgName, pfn);
}
