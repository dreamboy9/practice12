#ifndef _UTILS_H
#define _UTILS_H

char* finddata(void* base, void* end, void* data, unsigned int size);
BOOL hookiat(char* module, char* funcname, DWORD ownfunc, PDWORD orgfunc);

void VectorTransform (float *in1, float in2[3][4], float *out);

void fillRGBA(GLfloat x, GLfloat y, GLfloat w, GLfloat h, int r, int g, int b, int a);
void engdrawstring(int x, int y, int r, int g, int b, BOOL center, char* text);

#endif
