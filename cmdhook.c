#include "cpcheat.h"

struct command_s *cmdbase = 0;
char szaddcmd[] = "Cmd_AddCommand after host_initialized";

void
hookcmd()
{
    static unsigned char findbuf[5] = { 0x68, 0, 0, 0, 0 };
    char* szcmdaddr = 0;

    szcmdaddr = finddata((void*)GetModuleHandle(0), (void*)(GetModuleHandle(0)+0x02116000), szaddcmd, strlen(szaddcmd));
    if(szcmdaddr) {
        *(unsigned int*)(&(findbuf[1])) = (unsigned int)szcmdaddr;
        szcmdaddr = finddata((void*)GetModuleHandle(0), (void*)(GetModuleHandle(0)+0x02116000), &findbuf, 5);
        if(szcmdaddr)
            szcmdaddr += 0x3A;
            cmdbase = *(command_t**)szcmdaddr;
            Engfuncs.Con_Printf("cmdbase: 0x%X\n", cmdbase);
    }

    addline("commandbase found at: 0x%X", cmdbase);
}
