#include "cpcheat.h"

char*
finddata(void* base, void* end, void* data, unsigned int size)
{
    char* a;
    unsigned int b;

    for(a = (char*)base; a < (char*)end; a++) {
        if(IsBadReadPtr((void*)a, size))
            return 0;
        if(!memcmp(a, data, size)) return a;
    }
    return 0;
}

void
fillRGBA(GLfloat x, GLfloat y, GLfloat w, GLfloat h, int r, int g, int b, int a)
{
	glPushMatrix();
	glLoadIdentity();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4ub(r,g,b,a);
	  glBegin(GL_QUADS);
	    glVertex2f(x,y);
		glVertex2f(x+w,y);
		glVertex2f(x+w,y+h);
		glVertex2f(x,y+h);
	  glEnd();
	glDisable(GL_BLEND);

	glPopMatrix();
	glEnable(GL_TEXTURE_2D);
}

BOOL
hookiat(char* module, char* funcname, DWORD ownfunc, PDWORD orgfunc)
{
    DWORD base = (DWORD)GetModuleHandle(NULL);
    PIMAGE_DOS_HEADER doshdr = (PIMAGE_DOS_HEADER)base;
    PIMAGE_NT_HEADERS nthdr = (PIMAGE_NT_HEADERS)(base + doshdr->e_lfanew);
    DWORD ImportData = (DWORD)nthdr->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
    PIMAGE_IMPORT_DESCRIPTOR importdescriptor = (PIMAGE_IMPORT_DESCRIPTOR)(base + ImportData);
    while(importdescriptor->Name != 0)
    {
        if(!strcmp((char*)(base + importdescriptor->Name), module))
            break;
        importdescriptor++;
    }
    if(importdescriptor->Name == 0) return FALSE;
    PIMAGE_THUNK_DATA thunk = (PIMAGE_THUNK_DATA)(base + importdescriptor->FirstThunk);
    DWORD gpaorgfunc = (DWORD)GetProcAddress(GetModuleHandle(module), funcname);
    while(thunk->u1.Ordinal != 0)
    {
        if(thunk->u1.Function == gpaorgfunc)
        {
            *orgfunc = gpaorgfunc;
            DWORD oldprot = 0;
            VirtualProtect((void*)&thunk->u1.Function, 4, PAGE_EXECUTE_READWRITE, &oldprot);
            thunk->u1.Function = ownfunc;
            VirtualProtect((void*)&thunk->u1.Function, 4, oldprot, &oldprot);
            if(thunk->u1.Function == ownfunc)
                return TRUE;
            else
                return FALSE;
        }
        thunk++;
    }
    return FALSE;
}

void
engdrawstring(int x, int y, int r, int g, int b, BOOL center, char* text)
{
    if(center) {
        int len, wid;
        Engfuncs.pfnDrawConsoleStringLen(text, &len, &wid);
        x -= len/2;
    }

    Engfuncs.pfnDrawSetTextColor((float)r/255.0f, (float)g/255.0f, (float)b/255.0f);
    Engfuncs.pfnDrawConsoleString(x, y, text);
}

void
VectorTransform (float *in1, float in2[3][4], float *out)
{
    out[0] = DotProduct(in1, in2[0]) + in2[0][3];
    out[1] = DotProduct(in1, in2[1]) + in2[1][3];
    out[2] = DotProduct(in1, in2[2]) + in2[2][3];
}
