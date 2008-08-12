#include "cpcheat.h"

typedef char line_t[1024];

BOOL consoleactive = false;
BOOL isinit = false;
unsigned int linecount;
line_t *lines;
line_t input = { '\0' };

void
drawconsole()
{
    unsigned int i;

    drawwindow(centerX/2, centerY/2, centerX, centerY, 180, "cpcheat");
    fillRGBA(centerX/2, centerY/2+centerY-11, centerX, 1, 0, 0, 0, 180);
    for(i = 0; i < linecount; i++) {
        fontdrawstring(false, false, centerX/2+3, centerY/2+3+i*9, 200, 200, 200, 255, lines[i]);
    }
    fontdrawstring(false, false, centerX/2+2, centerY/2+centerY-9, 255, 255, 255, 255, input);
}

void
conreportkey(int keynum)
{
    if(keynum == 13) {
        addline(input);
        parseinput(input);
        input[0] = '\0';
    }
    else if(keynum == 127) { // backspace
        input[strlen(input)-1] = '\0';
    }
    else if(keynum == '.' || keynum == 32 || (keynum >= 48 || keynum <= 58) || (keynum >= 97 && keynum <= 122)) {
        int inputlen = strlen(input);
        if(inputlen == 1024) return; // overflow protection, although 1024 byte input is unlikely
        input[inputlen] = keynum;
        input[inputlen+1] = '\0';
    }
}

void
addline(char* format, ...)
{
    if(!isinit) return; // don't use before initialized

    unsigned int i;

    char buffer[1024];
    va_list arglist;
    va_start(arglist, format);
    vsnprintf(buffer, 1024, format, arglist);

    for(i = 1; i <= linecount; i++) {
        strcpy(lines[i-1], lines[i]);
    }
    strcpy(lines[linecount-1], buffer);
}

void
initconsole()
{
    linecount = (centerY/9)-1;
    lines = malloc(1024*linecount);
    memset(lines, 0, 1024*linecount);
    isinit = true;

    addline("cpcheat by h1web");
    addline("http://www.cheat-project.com");
    addline("");
}

void
destroyconsole()
{
    free(lines);
}
