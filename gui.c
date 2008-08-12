#include "cpcheat.h"

void
drawstring(int x, int y, int r, int g, int b, int a, BOOL center, BOOL bg, char* format, ...)
{
    char buffer[1024];
    va_list arglist;
    va_start(arglist, format);
    vsnprintf(buffer, 1024, format, arglist);

    if(settings.font->value == 1.0f) {
        fontdrawstring(center, bg, x, y, r, g, b, a, buffer);
        return;
    }
    engdrawstring(x, y, r, g, b, center, buffer);
}

void
drawwindow(int x, int y, int w, int h, int a, char* title)
{
    int Y;

    y -= 10;
    fillRGBA(x-1, y-1, w+2, 1, 0, 0, 0, a); // upper bar
    fillRGBA(x-1, y, 1, 10, 0, 0, 0, a); // left bar
    fillRGBA(x+w, y, 1, 10, 0, 0, 0, a); // right bar

    for(Y = 0; Y < 10; Y++) {
        fillRGBA(x, y+Y, w, 1, 212-Y*2, 167-Y*2, 81-Y*2, a);
    }

    fontdrawstring(false, false, x+3, y+2, 0, 0, 0, a, title);
    fontdrawstring(false, false, x+2, y+1, 255, 255, 255, a, title);

    y += 10;

    for(Y = 0; Y < h; Y++) {
        fillRGBA(x, y+Y, w, 1, 100-Y*.25f, 100-Y*.25f, 100-Y*.25f, a);
    }

    fillRGBA(x, y, w, 1, 0, 0, 0, a); // upper bar
    fillRGBA(x-1, y, 1, h, 0, 0, 0, a); // left bar
    fillRGBA(x+w, y, 1, h, 0, 0, 0, a); // right bar
    fillRGBA(x, y+h, w, 1, 0, 0, 0, a); // lower bar

}
