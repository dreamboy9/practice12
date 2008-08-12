#ifndef _CONSOLE_H
#define _CONSOLE_H

BOOL consoleactive;

void initconsole();
void destroyconsole();
void drawconsole();
void addline(char* format, ...);
void conreportkey(int keynum);

#endif
