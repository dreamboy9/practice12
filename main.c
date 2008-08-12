#include "cpcheat.h"

char watermark[] = "IH CP.C0M (§";

typedef FARPROC (_stdcall *GetProcAddress_t)(HMODULE, LPCSTR);
GetProcAddress_t pGetProcAddress = 0;

FARPROC _stdcall
_GetProcAddress(HMODULE hModule, LPCSTR lpProcName)
{
    FARPROC result = (*pGetProcAddress)(hModule, lpProcName);

    if(HIWORD(lpProcName)) {
        if(!lstrcmp(lpProcName, "GetProcAddress"))
            return (FARPROC)&_GetProcAddress;
        if(!lstrcmp(lpProcName, "HUD_GetStudioModelInterface") && !hModule)
        {
            char* retaddress = (char*)__builtin_return_address(0)/*gcc _ReturnAddress*/;
            pStudio = *(struct engine_studio_api_s**)(retaddress+0xA); // engstudio
            ppStudioInterface = *(struct r_studio_interface_s***)(retaddress+0xF); // studio interface
            retaddress++;
            DWORD exporttableaddr = *(DWORD*)retaddress - 0x9C; // exporttable
            exporttable = (struct exporttable_s*)(exporttableaddr);

            CreateThread(0, 0, (LPTHREAD_START_ROUTINE)hookclient, 0, 0, 0);
        }
    }

    return result;
}

void
initcheat()
{
    initsettings();
    initfont();
    initplayers();
}

void
cleanup()
{
    destroysettings();
    destroyconsole();
}

void __attribute__ ((noinline))
junkfunc()
{
    destroyconsole();
    void *junk = calloc(753, 912);
    if(junk) goto end;
    free(junk);
end:
    printf("%X%s%i", 0x1553434, watermark, 757843);
}

extern
BOOL APIENTRY DllMain(HINSTANCE hinst, DWORD reason, LPVOID reserved)
{
    if(reason == DLL_PROCESS_ATTACH) {
        junkfunc();
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)findengine, 0, 0, 0);
        if(!hookiat("KERNEL32.dll", "GetProcAddress", (DWORD)&_GetProcAddress, (PDWORD)&pGetProcAddress))
            return FALSE;
        initcheat();
    }
    else if(reason == DLL_PROCESS_DETACH) {
        cleanup();
    }
    return TRUE;
}
