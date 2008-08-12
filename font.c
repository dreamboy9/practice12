#include "cpcheat.h"

int sizes[255]; // ascii

void
fontdrawstring(BOOL center, BOOL bg, int x, int y, int r, int g, int b, int a, char* text)
{
    unsigned int i;

    int skipx = 0;
    if(center) {
        int tempx = 0;
        for(i = 0; i < strlen(text); i++)
            tempx += sizes[tolower(text[i])];
        x -= tempx/2;
    }

    for(i = 0; i < strlen(text); i++) {
        switch(tolower(text[i])) {
            case ' ':
                if(bg)
                    fillRGBA(x+skipx, y, 5, 7, 0, 0, 0, a);
                skipx += 5;
                break;
            case 'a':
                skipx += drawA(x+skipx, y, r, g, b, a, bg);
                break;
            case 'b':
                skipx += drawB(x+skipx, y, r, g, b, a, bg);
                break;
            case 'c':
                skipx += drawC(x+skipx, y, r, g, b, a, bg);
                break;
            case 'd':
                skipx += drawD(x+skipx, y, r, g, b, a, bg);
                break;
            case 'e':
                skipx += drawE(x+skipx, y, r, g, b, a, bg);
                break;
            case 'f':
                skipx += drawF(x+skipx, y, r, g, b, a, bg);
                break;
            case 'g':
                skipx += drawG(x+skipx, y, r, g, b, a, bg);
                break;
            case 'h':
                skipx += drawH(x+skipx, y, r, g, b, a, bg);
                break;
            case 'i':
                skipx += drawI(x+skipx, y, r, g, b, a, bg);
                break;
            case 'j':
                skipx += drawJ(x+skipx, y, r, g, b, a, bg);
                break;
            case 'k':
                skipx += drawK(x+skipx, y, r, g, b, a, bg);
                break;
            case 'l':
                skipx += drawL(x+skipx, y, r, g, b, a, bg);
                break;
            case 'm':
                skipx += drawM(x+skipx, y, r, g, b, a, bg);
                break;
            case 'n':
                skipx += drawN(x+skipx, y, r, g, b, a, bg);
                break;
            case 'o':
                skipx += drawO(x+skipx, y, r, g, b, a, bg);
                break;
            case 'p':
                skipx += drawP(x+skipx, y, r, g, b, a, bg);
                break;
            case 'q':
                skipx += drawQ(x+skipx, y, r, g, b, a, bg);
                break;
            case 'r':
                skipx += drawR(x+skipx, y, r, g, b, a, bg);
                break;
            case 's':
                skipx += drawS(x+skipx, y, r, g, b, a, bg);
                break;
            case 't':
                skipx += drawT(x+skipx, y, r, g, b, a, bg);
                break;
            case 'u':
                skipx += drawU(x+skipx, y, r, g, b, a, bg);
                break;
            case 'v':
                skipx += drawV(x+skipx, y, r, g, b, a, bg);
                break;
            case 'w':
                skipx += drawW(x+skipx, y, r, g, b, a, bg);
                break;
            case 'x':
                skipx += drawX(x+skipx, y, r, g, b, a, bg);
                break;
            case 'y':
                skipx += drawY(x+skipx, y, r, g, b, a, bg);
                break;
            case 'z':
                skipx += drawZ(x+skipx, y, r, g, b, a, bg);
                break;

            case '-':
                skipx += drawDash(x+skipx, y, r, g, b, a, bg);
                break;
            case '_':
                skipx += drawUnderline(x+skipx, y, r, g, b, a, bg);
                break;
            case ':':
                skipx += drawColon(x+skipx, y, r, g, b, a, bg);
                break;
            case '.':
                skipx += drawDot(x+skipx, y, r, g, b, a, bg);
                break;
            case ',':
                skipx += drawDot(x+skipx, y, r, g, b, a, bg);
                break;
            case '@':
                skipx += drawAT(x+skipx, y, r, g, b, a, bg);
                break;
            case '!':
                skipx += drawExMark(x+skipx, y, r, g, b, a, bg);
                break;
            case '/':
                skipx += drawSlash(x+skipx, y, r, g, b, a, bg);
                break;
            case ')':
                skipx += drawLBrace(x+skipx, y, r, g, b, a, bg);
                break;
            case '(':
                skipx += drawRBrace(x+skipx, y, r, g, b, a, bg);
                break;
            case ']':
                skipx += drawLBracket(x+skipx, y, r, g, b, a, bg);
                break;
            case '[':
                skipx += drawRBracket(x+skipx, y, r, g, b, a, bg);
                break;
            case '+':
                skipx += drawPlus(x+skipx, y, r, g, b, a, bg);
                break;
            case '|':
                skipx += drawSep(x+skipx, y, r, g, b, a, bg);
                break;

            case '1':
                skipx += draw1(x+skipx, y, r, g, b, a, bg);
                break;
            case '2':
                skipx += draw2(x+skipx, y, r, g, b, a, bg);
                break;
            case '3':
                skipx += draw3(x+skipx, y, r, g, b, a, bg);
                break;
            case '4':
                skipx += draw4(x+skipx, y, r, g, b, a, bg);
                break;
            case '5':
                skipx += drawS(x+skipx, y, r, g, b, a, bg);
                break;
            case '6':
                skipx += draw6(x+skipx, y, r, g, b, a, bg);
                break;
            case '7':
                skipx += draw7(x+skipx, y, r, g, b, a, bg);
                break;
            case '8':
                skipx += draw8(x+skipx, y, r, g, b, a, bg);
                break;
            case '9':
                skipx += draw9(x+skipx, y, r, g, b, a, bg);
                break;
            case '0':
                skipx += drawO(x+skipx, y, r, g, b, a, bg);
                break;
            case '>':
                skipx += drawRArrow(x+skipx, y, r, g, b, a, bg);
                break;


/*            default:
                if(bg)
                    fillRGBA(x+skipx, y, 5, 7, 0, 0, 0, a);
                skipx += 5;
                break;*/
        }
    }
}

void
initfont()
{
    sizes['k'] = 6;
    sizes['m'] = 6;
    sizes['n'] = 6;
    sizes['p'] = 6;
    sizes['q'] = 6;
    sizes['r'] = 6;
    sizes['t'] = 6;
    sizes['v'] = 6;
    sizes['w'] = 6;
    sizes['x'] = 6;
    sizes['y'] = 6;
    sizes['4'] = 6;
    sizes['@'] = 6;
    sizes['+'] = 6;
    sizes[' '] = 5;
    sizes['a'] = 5;
    sizes['b'] = 5;
    sizes['c'] = 5;
    sizes['d'] = 5;
    sizes['e'] = 5;
    sizes['f'] = 5;
    sizes['g'] = 5;
    sizes['h'] = 5;
    sizes['j'] = 5;
    sizes['l'] = 5;
    sizes['o'] = 5;
    sizes['s'] = 5;
    sizes['u'] = 5;
    sizes['z'] = 5;
    sizes['2'] = 5;
    sizes['3'] = 5;
    sizes['6'] = 5;
    sizes['7'] = 5;
    sizes['8'] = 5;
    sizes['9'] = 5;
    sizes['-'] = 5;
    sizes['_'] = 5;
    sizes['/'] = 5;
    sizes['1'] = 3;
    sizes[')'] = 3;
    sizes['('] = 3;
    sizes[']'] = 3;
    sizes['['] = 3;
    sizes['i'] = 2;
    sizes['.'] = 2;
    sizes[':'] = 2;
    sizes['!'] = 2;
    sizes['|'] = 2;
    sizes['>'] = 4;
}

int
drawA(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 5, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 7, r, g, b, a); // first vertical line
    fillRGBA(x+1, y, 2, 1, r, g, b, a); // first bar
    fillRGBA(x+1, y+3, 2, 1, r, g, b, a); // second bar
    fillRGBA(x+3, y, 1, 7, r, g, b, a); // last vertical line
    return 5;
}

int
drawB(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 5, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 7, r, g, b, a); // first vertical line
    fillRGBA(x+1, y, 2, 1, r, g, b, a); // first bar
    fillRGBA(x+1, y+3, 2, 1, r, g, b, a); // second bar
    fillRGBA(x+1, y+6, 2, 1, r, g, b, a); // last bar
    fillRGBA(x+3, y, 1, 7, r, g, b, a); // last vertical line
    return 5;
}

int
drawC(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 5, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 7, r, g, b, a); // first vertical line
    fillRGBA(x+1, y, 3, 1, r, g, b, a); // first bar
    fillRGBA(x+1, y+6, 3, 1, r, g, b, a); // last bar
    return 5;
}

int
drawD(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 5, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 7, r, g, b, a); // first vertical line
    fillRGBA(x+1, y, 2, 1, r, g, b, a); // first bar
    fillRGBA(x+1, y+6, 2, 1, r, g, b, a); // last bar
    fillRGBA(x+3, y+1, 1, 5, r, g, b, a); // last vertical line
    return 5;
}

int
drawE(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 5, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 7, r, g, b, a); // first vertical line
    fillRGBA(x+1, y, 3, 1, r, g, b, a); // first bar
    fillRGBA(x+1, y+3, 3, 1, r, g, b, a); // second bar
    fillRGBA(x+1, y+6, 3, 1, r, g, b, a); // last bar
    return 5;
}

int
drawF(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 5, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 7, r, g, b, a); // first vertical line
    fillRGBA(x+1, y, 3, 1, r, g, b, a); // first bar
    fillRGBA(x+1, y+3, 3, 1, r, g, b, a); // second bar
    return 5;
}

int
drawG(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 5, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 7, r, g, b, a); // first vertical line
    fillRGBA(x+1, y, 3, 1, r, g, b, a); // first bar
    fillRGBA(x+2, y+3, 2, 1, r, g, b, a); // second bar
    fillRGBA(x+1, y+6, 3, 1, r, g, b, a); // last bar
    fillRGBA(x+3, y+4, 1, 2, r, g, b, a); // last vertical line
    return 5;
}

int
drawH(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 5, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 7, r, g, b, a); // first vertical line
    fillRGBA(x+1, y+3, 2, 1, r, g, b, a); // middle bar
    fillRGBA(x+3, y, 1, 7, r, g, b, a); // last vertical line
    return 5;
}

int
drawI(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 2, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 7, r, g, b, a); // vertical line
    return 2;
}

int
drawJ(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 5, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 3, 1, r, g, b, a); // first bar
    fillRGBA(x+2, y+1, 1, 5, r, g, b, a); // vertical line
    fillRGBA(x, y+6, 3, 1, r, g, b, a); // last bar
    return 5;
}

int
drawK(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 6, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 7, r, g, b, a); // first vertical line
    fillRGBA(x+1, y+3, 1, 1, r, g, b, a); // first dot

    fillRGBA(x+2, y+2, 1, 1, r, g, b, a); // first upper dot
    fillRGBA(x+3, y+1, 1, 1, r, g, b, a); // second upper dot
    fillRGBA(x+4, y, 1, 1, r, g, b, a); // third upper dot

    fillRGBA(x+2, y+4, 1, 1, r, g, b, a); // first lower dot
    fillRGBA(x+3, y+5, 1, 1, r, g, b, a); // second lower dot
    fillRGBA(x+4, y+6, 1, 1, r, g, b, a); // third lower dot
    return 6;
}

int
drawL(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 5, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 7, r, g, b, a); // first vertical line
    fillRGBA(x+1, y+6, 3, 1, r, g, b, a); // lower bar
    return 5;
}

int
drawM(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 6, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 7, r, g, b, a); // vertical line

    fillRGBA(x+1, y+1, 1, 1, r, g, b, a); // first dot down
    fillRGBA(x+2, y+2, 1, 1, r, g, b, a); // middle dot
    fillRGBA(x+3, y+1, 1, 1, r, g, b, a); // first dot up

    fillRGBA(x+4, y, 1, 7, r, g, b, a);
    return 6;
}

int
drawN(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 6, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 7, r, g, b, a); // vertical line
    fillRGBA(x+1, y, 1, 2, r, g, b, a); // doubledot 1
    fillRGBA(x+2, y+2, 1, 2, r, g, b, a); // doubledot 2
    fillRGBA(x+3, y+4, 1, 3, r, g, b, a); // doubledot 3
    fillRGBA(x+4, y, 1, 7, r, g, b, a); // vertical line
    return 6;
}

int
drawO(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 5, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 7, r, g, b, a); // first vertical line
    fillRGBA(x+1, y, 2, 1, r, g, b, a); // first bar
    fillRGBA(x+1, y+6, 2, 1, r, g, b, a); // last bar
    fillRGBA(x+3, y, 1, 7, r, g, b, a); // last vertical line
    return 5;
}

int
drawP(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 6, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 7, r, g, b, a); // first vertical line
    fillRGBA(x+1, y, 3, 1, r, g, b, a); // first bar
    fillRGBA(x+1, y+3, 3, 1, r, g, b, a); // last bar
    fillRGBA(x+4, y+1, 1, 2, r, g, b, a); // vertical bar
    return 6;
}

int
drawQ(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 6, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 7, r, g, b, a); // first vertical line
    fillRGBA(x+1, y, 2, 1, r, g, b, a); // first bar
    fillRGBA(x+1, y+6, 2, 1, r, g, b, a); // last bar
    fillRGBA(x+3, y, 1, 7, r, g, b, a); // last vertical line

    fillRGBA(x+2, y+5, 1, 1, r, g, b,a); // inner dot
    fillRGBA(x+4, y+6, 1, 1, r, g, b,a); // outer dot
    return 6;
}

int
drawR(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 6, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 7, r, g, b, a); // first vertical line
    fillRGBA(x+1, y, 3, 1, r, g, b, a); // first bar
    fillRGBA(x+1, y+3, 3, 1, r, g, b, a); // last bar
    fillRGBA(x+4, y+1, 1, 2, r, g, b, a); // vertical bar

    fillRGBA(x+2, y+4, 1, 1, r, g, b, a); // first lower dot
    fillRGBA(x+3, y+5, 1, 1, r, g, b, a); // second lower dot
    fillRGBA(x+4, y+6, 1, 1, r, g, b, a); // third lower dot
    return 6;
}

int
drawS(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 5, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 4, 1, r, g, b, a); // first line
    fillRGBA(x, y+3, 4, 1, r, g, b, a); // second line
    fillRGBA(x, y+6, 4, 1, r, g, b, a); // third line

    fillRGBA(x, y+1, 1, 2, r, g, b, a); // first vertical line
    fillRGBA(x+3, y+4, 1, 2, r, g, b, a); // last vertical line
    return 5;
}

int
drawT(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 6, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 5, 1, r, g, b, a); // first bar
    fillRGBA(x+2, y+1, 1, 6, r, g, b, a); // vertical line
    return 6;
}

int
drawU(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 5, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 7, r, g, b, a); // first vertical line
    fillRGBA(x+1, y+6, 2, 1, r, g, b, a); // middle bar
    fillRGBA(x+3, y, 1, 7, r, g, b, a); // last vertical line
    return 5;
}

int
drawV(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 6, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 5, r, g, b, a); // first vertical line
    fillRGBA(x+1, y+5, 1, 1, r, g, b, a); // first mid dot
    fillRGBA(x+2, y+6, 1, 1, r, g, b, a); // lower dot
    fillRGBA(x+3, y+5, 1, 1, r, g, b, a); // third mid dot
    fillRGBA(x+4, y, 1, 5, r, g, b, a); // last vertical line
    return 6;
}

int
drawW(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 6, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 6, r, g, b, a); // left vertical line
    fillRGBA(x+4, y, 1, 6, r, g, b, a); // right vertical line
    fillRGBA(x+2, y+4, 1, 2, r, g, b, a); // vertical dash
    fillRGBA(x+1, y+6, 3, 1, r, g, b, a); // dash
    return 6;
}

int
drawX(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 6, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 1, r, g, b, a); // upper left dot
    fillRGBA(x+4, y, 1, 1, r, g, b, a); // upper right dot
    fillRGBA(x, y+6, 1, 1, r, g, b, a); // lower left dot
    fillRGBA(x+4, y+6, 1, 1, r, g, b, a); // lower right dot
    fillRGBA(x+1, y+1, 1, 2, r, g, b, a); // upper left bar
    fillRGBA(x+3, y+1, 1, 2, r, g, b, a); // upper right bar
    fillRGBA(x+1, y+4, 1, 2, r, g, b, a); // lower left bar
    fillRGBA(x+3, y+4, 1, 2, r, g, b, a); // lower right bar
    fillRGBA(x+2, y+3, 1, 1, r, g, b, a); // middle dot
    return 6;
}

int
drawY(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 6, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 1, r, g, b, a); // left - first dot
    fillRGBA(x+1, y+1, 1, 1, r, g, b, a); // left - second dot
    fillRGBA(x+4, y, 1, 1, r, g, b, a); // right - first dot
    fillRGBA(x+3, y+1, 1, 1, r, g, b, a); // right - second dot
    fillRGBA(x+2, y+2, 1, 5, r, g, b, a); // vertical line
    return 6;
}

int
drawZ(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 5, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 4, 1, r, g, b, a); // first bar
    fillRGBA(x+3, y+1, 1, 2, r, g, b, a); // upper right vertical bar
    fillRGBA(x, y+4, 1, 2, r, g, b, a); // lower left vertical bar
    fillRGBA(x+1, y+3, 2, 1, r, g, b, a); // middle bar
    fillRGBA(x, y+6, 4, 1, r, g, b, a); // last bar
    return 5;
}

int
draw1(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 3, 7, 0, 0, 0, a); // background
    fillRGBA(x, y+1, 1, 1, r, g, b, a); // dot
    fillRGBA(x+1, y, 1, 7, r, g, b, a); // vertical line
    return 3;
}

int
draw2(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 5, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 1, r, g, b, a); // dot
    fillRGBA(x+1, y, 3, 1, r, g, b, a); // first bar
    fillRGBA(x+3, y+1, 1, 2, r, g, b, a); // upper right vertical bar
    fillRGBA(x, y+4, 1, 2, r, g, b, a); // lower left vertical bar
    fillRGBA(x+1, y+3, 2, 1, r, g, b, a); // middle bar
    fillRGBA(x, y+6, 4, 1, r, g, b, a); // last bar
    return 5;
}

int
draw3(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 5, 7, 0, 0, 0, a); // background
    fillRGBA(x+3, y, 1, 7, r, g, b, a); // first vertical line
    fillRGBA(x, y, 3, 1, r, g, b, a); // first bar
    fillRGBA(x, y+3, 3, 1, r, g, b, a); // second bar
    fillRGBA(x, y+6, 3, 1, r, g, b, a); // last bar
    return 5;
}

int
draw4(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 6, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 4, r, g, b, a); // left bar
    fillRGBA(x+4, y, 1, 7, r, g, b, a); // right bar
    fillRGBA(x+1, y+3, 3, 1, r, g, b, a); // middle bar
    return 6;
}

int
draw6(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 5, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 7, r, g, b, a); // first vertical line
    fillRGBA(x+1, y, 3, 1, r, g, b, a); // first bar
    fillRGBA(x+1, y+3, 3, 1, r, g, b, a); // second bar
    fillRGBA(x+1, y+6, 3, 1, r, g, b, a); // last bar
    fillRGBA(x+3, y+4, 1, 2, r, g, b, a); // last vertical line
    return 5;
}

int
draw7(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 5, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 4, 1, r, g, b, a); // upper bar
    fillRGBA(x+3, y+1, 1, 6, r, g, b, a); // vertical line
    return 5;
}

int
draw8(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 5, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 7, r, g, b, a); // left line
    fillRGBA(x+3, y, 1, 7, r, g, b, a); // right line
    fillRGBA(x+1, y, 3, 1, r, g, b, a); // first bar
    fillRGBA(x+1, y+3, 3, 1, r, g, b, a); // second bar
    fillRGBA(x+1, y+6, 3, 1, r, g, b, a); // second bar
    return 5;
}

int
draw9(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 5, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 4, r, g, b, a); // left line
    fillRGBA(x+3, y, 1, 7, r, g, b, a); // right line
    fillRGBA(x+1, y, 3, 1, r, g, b, a); // first bar
    fillRGBA(x+1, y+3, 3, 1, r, g, b, a); // second bar
    fillRGBA(x, y+6, 4, 1, r, g, b, a); // last bar
    return 5;
}

int
drawDash(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 5, 7, 0, 0, 0, a); // background
    fillRGBA(x, y+4, 4, 1, r, g, b, a); // dash
    return 5;
}

int
drawUnderline(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 5, 7, 0, 0, 0, a); // background
    fillRGBA(x, y+6, 4, 1, r, g, b, a); // underline
    return 5;
}

int
drawColon(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 2, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 2, r, g, b, a); // upper bar
    fillRGBA(x, y+5, 1, 2, r, g, b, a); // lower bar
    return 2;
}

int
drawDot(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 2, 7, 0, 0, 0, a); // background
    fillRGBA(x, y+6, 1, 1, r, g, b, a); // dot
    return 2;
}

int
drawAT(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 6, 7, 0, 0, 0, a); // background
    fillRGBA(x+1, y, 4, 1, r, g, b, a); // upper bar
    fillRGBA(x, y+1, 1, 5, r, g, b, a); // left bar
    fillRGBA(x+4, y+1, 1, 4, r, g, b, a); // right bar
    fillRGBA(x+2, y+2, 1, 3, r, g, b, a); // inner left bar
    fillRGBA(x+3, y+2, 1, 1, r, g, b, a); // upper dot
    fillRGBA(x+3, y+4, 1, 1, r, g, b, a); // lower dot
    fillRGBA(x+1, y+6, 4, 1, r, g, b, a); // lower bar

    return 6;
}

int
drawExMark(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 2, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 5, r, g, b, a); // vertical line
    fillRGBA(x, y+6, 1, 1, r, g, b, a); // dot
    return 2;
}

int
drawSlash(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 5, 7, 0, 0, 0, a); // background
    fillRGBA(x+3, y, 1, 2, r, g, b, a); // first bar
    fillRGBA(x+2, y+2, 1, 2, r, g, b, a); // third bar
    fillRGBA(x+1, y+3, 1, 2, r, g, b, a); // fourth bar
    fillRGBA(x, y+5, 1, 2, r, g, b, a); // fifth bar
    return 5;
}

int
drawLBrace(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 3, 7, 0, 0, 0, a); // background
    fillRGBA(x+1, y+1, 1, 5, r, g, b, a); // line
    fillRGBA(x, y, 1, 1, r, g, b, a); // upper dot
    fillRGBA(x, y+6, 1, 1, r, g, b, a); // lower dot
    return 3;
}

int
drawRBrace(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 3, 7, 0, 0, 0, a); // background
    fillRGBA(x, y+1, 1, 5, r, g, b, a); // line
    fillRGBA(x+1, y, 1, 1, r, g, b, a); // upper dot
    fillRGBA(x+1, y+6, 1, 1, r, g, b, a); // lower dot
    return 3;
}

int
drawLBracket(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 3, 7, 0, 0, 0, a); // background
    fillRGBA(x+1, y+1, 1, 5, r, g, b, a); // line
    fillRGBA(x, y, 2, 1, r, g, b, a); // upper bar
    fillRGBA(x, y+6, 2, 1, r, g, b, a); // lower bar
    return 3;
}

int
drawRBracket(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 3, 7, 0, 0, 0, a); // background
    fillRGBA(x, y+1, 1, 5, r, g, b, a); // line
    fillRGBA(x, y, 2, 1, r, g, b, a); // upper bar
    fillRGBA(x, y+6, 2, 1, r, g, b, a); // lower bar
    return 3;
}

int
drawPlus(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 6, 7, 0, 0, 0, a); // background
    fillRGBA(x, y+3, 5, 1, r, g, b, a); // horizontal bar
    fillRGBA(x+2, y, 1, 7, r, g, b, a); // vertical line
    return 6;
}

int
drawSep(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 2, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 7, r, g, b, a); // line
    return 2;
}

int
drawRArrow(int x, int y, int r, int g, int b, int a, BOOL bg)
{
    if (bg)
        fillRGBA(x, y, 4, 7, 0, 0, 0, a); // background
    fillRGBA(x, y, 1, 1, r, g, b, a); // upper dot 1
    fillRGBA(x, y+6, 1, 1, r, g, b, a); // lower dot 1
    fillRGBA(x+1, y+1, 1, 1, r, g, b, a); // upper dot 2
    fillRGBA(x+1, y+5, 1, 1, r, g, b, a); // lower dot 2
    fillRGBA(x+2, y+2, 1, 1, r, g, b, a); // upper dot 3
    fillRGBA(x+2, y+4, 1, 1, r, g, b, a); // lower dot 3
    fillRGBA(x+3, y+3, 1, 1, r, g, b, a); // final dot
}
