#include "cpcheat.h"

struct command_s *cmdbase = 0;
char szaddcmd[] = "Cmd_AddCommand after host_initialized";

void antislowhack();

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
    antislowhack();
}

void*
interceptcmd(char* name, void* func)
{
    void* retval = 0;

    command_t *cmd = cmdbase;
    while(cmd && cmd->next) {
        cmd = cmd->next;
        if(!strcmp(name, cmd->name)) {
            retval = cmd->func;
            cmd->func = func;
            break;
        }
    }

    return retval;
}

void
dummy()
{
    addline("WARNING: Command execution prevented due to antislowhack.");
}

void
antislowhack()
{
    interceptcmd("kill", &dummy);
    interceptcmd("unbind", &dummy);
    interceptcmd("unbindall", &dummy);
    interceptcmd("dropclient", &dummy);
}
