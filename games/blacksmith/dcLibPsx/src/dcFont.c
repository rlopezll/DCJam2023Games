#include "dcFont.h"
#include <types.h>



SFont GMainFont;

void dcFont_Load(unsigned long *texture) {
    GMainFont.firstChar = 32;
    GMainFont.charsPerLine = 16;
    GMainFont.charWidth = 8;
    GMainFont.charHeight = 8;
    GMainFont.lineWidth = GMainFont.charsPerLine*GMainFont.charWidth;
    dcRender_LoadTexture(&GMainFont.tim, texture);
}

// #pragma GCC push_options
// #pragma GCC optimize ("O0")

void dcFont_Print(SDC_Render* render, int x, int y, CVECTOR *color, const char *text) {
    int idx = 0;
    DVECTOR uv;
    while(text[idx] != 0) {
        int idxFont = text[idx] - GMainFont.firstChar;
        uv.vx = (idxFont * GMainFont.charWidth) % (GMainFont.lineWidth);
        uv.vy = (idxFont/GMainFont.charsPerLine) * GMainFont.charHeight;
        dcRender_DrawSpriteRectNotReal(render, &GMainFont.tim, x, y, GMainFont.charWidth, GMainFont.charHeight, &uv, color);
        ++idx;
        x += GMainFont.charWidth;
    }
}

// #pragma GCC pop_options
