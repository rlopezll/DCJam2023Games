#ifndef _DC_FONT_H
#define _DC_FONT_H

#include "dcRender.h"

typedef struct {
    TIM_IMAGE tim;
    u_short firstChar;
    u_short charsPerLine;
    u_short charWidth;
    u_short charHeight;
    u_short lineWidth;
} SFont;

extern SFont GMainFont;

void dcFont_Load(unsigned long *texture);
void dcFont_Print(SDC_Render* render, int x, int y, CVECTOR *color, const char *text);

#endif