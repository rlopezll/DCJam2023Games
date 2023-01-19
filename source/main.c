// screw you code formatter, this one needs to stay on top
#include <stdlib.h>
// now we need to have libgte.h
#include <libgte.h>
// then, these can work; the psyq library is badly written and won't include what it uses
#include <libetc.h>
#include <libgpu.h>
#include <stdio.h>
#include <types.h>
#include <libapi.h>

#include "dcMath.h"
#include "dcRender.h"
#include "dcMemory.h"
#include "dcFont.h"

#define WITH_CD 1

#ifndef WITH_CD
#define WITH_CD 0
#endif

extern unsigned long _binary_assets_bgCropped_tim_start[];
SDC_TIM_IMAGE backgroundTim;

extern unsigned long _binary_assets_tv_overlay_tim_start[];
SDC_TIM_IMAGE tvOverlayTim;

char* jamApps[] = { "cdrom:\\TANKE.EXE;1","cdrom:\\ROGUE.EXE;1","cdrom:\\BARCO.EXE;1", "cdrom:\\MALETA.EXE;1" };
char* gameNames[] = 
{
    "     ANDERTANKER     \0",
    " BLACKSMITH SURVIVORS\0",
    "    CAPTAIN RUBENS   \0",
    " D.E.S.C.O.N.T.R.O.L \0",
    "       CREDITS       \0"
};
// 193 character bytes, add padding to align at 4 bytes
char padding[3];
int numApps = 5;

void UpdateMenu();
void DrawMenu();

void UpdateCredits();
void DrawCredits();

void UpdateIntro();
void DrawIntro();

typedef enum
{
    INTRO,
    MENU,
    CREDITS

} ELoaderState;

void SetLoaderState(ELoaderState newState);

void drawQuad(SDC_Render *render, SDC_TIM_IMAGE* tex, RECT* xywh, RECT* uvwh, int otz, int semiTrans )
{
    u_long *orderingTable = render->orderingTable[render->doubleBufferIndex];
    POLY_FT4 *quad = (POLY_FT4 *)render->nextPrimitive;
    setPolyFT4(quad);

    setSemiTrans(quad, semiTrans );

    setXY4(
        quad,
        xywh->x, xywh->y,
        xywh->x + xywh->w, xywh->y,
        xywh->x, xywh->y + xywh->h,
        xywh->x + xywh->w, xywh->y + xywh->h
    );

    setRGB0(quad, 127, 127, 127);

    u_short tpageXStart = (tex->prect.x + uvwh->x) & ~0x003f;
    u_short tpageYStart = (tex->prect.y + uvwh->y) & ~0x00ff;

    quad->tpage = getTPage(tex->mode, 0, tpageXStart, tpageYStart);
    setClut(quad, tex->crect.x, tex->crect.y);
    setUVWH(quad, (tex->prect.x + uvwh->x) & 0x003f, (tex->prect.y + uvwh->y) & 0x00ff, uvwh->w, uvwh->h);

    addPrim(&orderingTable[otz], quad);
    render->nextPrimitive += sizeof(POLY_FT4);
};

void drawBackground(SDC_Render *render)
{
    long otz = render->orderingTableCount - 1;

    short halfWidth = 160;
    short halfHeight = 120;

    short xOffsets[] = {0, halfWidth};
    short yOffsets[] = {0, halfHeight};

    for ( int xi = 0; xi < 2; ++xi)
    {
        for ( int yi = 0; yi < 2; ++yi)
        {
            short xOffset = xOffsets[xi];
            short yOffset = yOffsets[yi];

            RECT xywh = {xOffset, yOffset, halfWidth, halfHeight};
            RECT uvwh = {xOffset, yOffset, halfWidth, halfHeight };
            drawQuad(render, &backgroundTim, &xywh, &uvwh, otz, 0);
        }
    }
}

SDC_Render render;
ELoaderState state;

int main(void) 
{
    InitGeom();
    dcMemory_Init();
    PadInit(0);

    #if WITH_CD
    _96_init();
    #endif
    
    int  width = 320;
    int  height = 240;
    CVECTOR bgColor = {255, 0, 0};
    
    dcRender_Init(&render, width, height, bgColor, 64, 8192, RENDER_MODE_NTCS);
    dcRender_LoadTexture(&backgroundTim, _binary_assets_bgCropped_tim_start);
    dcRender_LoadTexture(&tvOverlayTim, _binary_assets_tv_overlay_tim_start);

    dcFont_UseSystemFont();

    SetLoaderState(MENU);

    while (1) 
    {

        switch (state)
        {
            case INTRO:
                UpdateIntro();
                break;
            case MENU:
                UpdateMenu();
                break;
            case CREDITS:
                UpdateCredits();
                break;
        }

        drawBackground(&render);

        switch (state)
        {
            case INTRO:
                DrawIntro();
                break;
            case MENU:
                DrawMenu();
                break;
            case CREDITS:
                DrawCredits();
                break;
        }

        // Draw tv overlay
        RECT overlayQuad = {74, 70, 175, 98 };
        RECT overlayUVs = {0, 0, 175, 98 };
        drawQuad(&render, &tvOverlayTim, &overlayQuad, &overlayUVs, 1, 1 );

        dcRender_SwapBuffers(&render);
    }

    return 0;
}


int selectedApp = 0;
int prevPadUp = 0;
int prevPadDown = 0;
int prevXDown = 0;

void UpdateMenu()
{
    // Read pad state and move primitive
    u_long padState = PadRead(0);

    if( _PAD(0,PADLup ) & padState )
    {
        if( !prevPadUp)
        {
            selectedApp = DC_MAX( selectedApp - 1, 0);
            prevPadUp = 1;
        }
    }
    else prevPadUp = 0;

    if( _PAD(0,PADLdown ) & padState )
    {
        if(!prevPadDown)
        {
            selectedApp = DC_MIN( selectedApp + 1, numApps - 1);
            prevPadDown = 1;
        }
    }
    else prevPadDown = 0;

    if( _PAD(0,PADRdown ) & padState )
    {
        if( !prevXDown )
        {
            prevXDown = 1;
            if( selectedApp == 4)
            {
                SetLoaderState(CREDITS);
            }
            else{
            #if WITH_CD
                struct EXEC exec;
                if(Load(jamApps[selectedApp], &exec))
                {
                    printf("Loaded %s successfully!\n", jamApps[selectedApp]);
                    ResetGraph(3);
                    PadStop();
                    StopCallback();
                    EnterCriticalSection();
                    Exec(&exec, 0, 0);
                }
                else printf("Failed to load %s!\n", jamApps[selectedApp]);
            #endif
            }
        
        }            

    }
    else prevXDown = 0;
}

void DrawMenu()
{
    CVECTOR normalColor = {70, 70, 70};
    CVECTOR selectedColor = {127, 127, 127};
    int y = 85;
    
    for(int i = 0; i < numApps; ++i)
    {
        CVECTOR* color = i == selectedApp ? &selectedColor : &normalColor;
        dcFont_PrintZ(&render,78, y, 2, color, gameNames[i]);
        y += 15;
    }

}

int creditsY = 190;
int creditTicks = 0;
extern const char* creditsArray[];
extern int numCreditsNames;

void UpdateCredits()
{
    creditTicks++;
    if( creditTicks > 5)
    {
        creditsY--;
        creditTicks = 0;
    }
    if( creditsY + 15 * numCreditsNames < 60 )
    {
        SetLoaderState(MENU);
    }
}

void DrawCredits()
{
    CVECTOR color = {127, 127, 127};
    int y = creditsY;

    for(int i = 0; i < numCreditsNames; ++i)
    {
        if(y > 75 && y < 160)
        {
            dcFont_PrintZ(&render, 115, y, 2, &color, creditsArray[i]);
        }
        y += 15;
    }

}

void UpdateIntro()
{

}

void DrawIntro()
{
    
}

void SetLoaderState(ELoaderState newState)
{
    state = newState;

    if(state == CREDITS)
    {
        creditsY = 190; 
        creditTicks = 0;
    }

}
