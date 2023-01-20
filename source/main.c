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
#include "dcMisc.h"
#include "dcAudio.h"

//#define WITH_CD 0

#ifndef WITH_CD
#define WITH_CD 0
#endif

#ifndef TRACKS_MUSIC_OFFSET
#define TRACKS_MUSIC_OFFSET 0
#endif

extern unsigned long _binary_assets_accept_vag_start[];
extern unsigned long _binary_assets_select_vag_start[];

SDC_Sfx       gAcceptSfx;
SDC_Sfx       gSelectSfx;


extern unsigned long _binary_assets_bgCropped_tim_start[];
SDC_TIM_IMAGE backgroundTim;

char* jamApps[] = { "\\TANKE.EXE;1","\\ROGUE.EXE;1","\\BARCO.EXE;1", "\\MALETA.EXE;1" };
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

void InitCreditsLength();

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
    long otz = 1; //render->orderingTableCount - 1;

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
SDC_Audio audio;

int main(void) 
{
    InitGeom();
    dcMemory_Init();
    PadInit(0);

    int  width = 320;
    int  height = 240;
    CVECTOR bgColor = {14, 114, 120};
    
    dcRender_Init(&render, width, height, bgColor, 64, 12000, RENDER_MODE_NTCS);
    dcRender_LoadTexture(&backgroundTim, _binary_assets_bgCropped_tim_start);

    dcFont_UseSystemFont();

    InitCreditsLength();

    SetLoaderState(INTRO);

    // Audio
    dcAudio_Init(&audio, 16);
    dcAudio_MusicPlay(&audio, TRACKS_MUSIC_OFFSET+0);

    dcAudio_SfxLoad(&audio, &gAcceptSfx, (u_char *)_binary_assets_accept_vag_start);
    dcAudio_SfxLoad(&audio, &gSelectSfx, (u_char *)_binary_assets_select_vag_start);

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

        dcAudio_Update(&audio);
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
            dcAudio_SfxPlay(&gSelectSfx);
        }
    }
    else prevPadUp = 0;

    if( _PAD(0,PADLdown ) & padState )
    {
        if(!prevPadDown)
        {
            selectedApp = DC_MIN( selectedApp + 1, numApps - 1);
            prevPadDown = 1;
            dcAudio_SfxPlay(&gSelectSfx);
        }
    }
    else prevPadDown = 0;

    if( _PAD(0,PADRdown ) & padState )
    {
        if( !prevXDown )
        {
            dcAudio_SfxPlay(&gAcceptSfx);
            prevXDown = 1;
            if( selectedApp == 4)
            {
                SetLoaderState(CREDITS);
            }
            else{
            #if WITH_CD
                struct EXEC* exec = CdReadExec(jamApps[selectedApp]);
                if(exec)
                {
                    printf("Loaded %s successfully!\n", jamApps[selectedApp]);
                    ResetGraph(3);
                    PadStop();
                    StopCallback();
                    EnterCriticalSection();
                    Exec(exec, 0, 0);
                    ExitCriticalSection();
                }
                else {
                    printf("Failed to load %s!\n", jamApps[selectedApp]);
                }
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
        dcFont_PrintZ(&render,78, y, 16, color, gameNames[i]);
        y += 15;
    }

}

int creditsY = 0;
int creditTicks = 0;
extern const char* creditsArray[];
extern int numCreditsNames;
extern int creditsLineLength[];

void UpdateCredits()
{
    creditTicks++;
    if( creditTicks > 5)
    {
        creditsY--;
        creditTicks = 0;
    }
    if( creditsY + 15 * numCreditsNames < 55 )
    {
        SetLoaderState(MENU);
    }
    else if( _PAD(0,PADRdown ) & PadRead(0) )
    {
        if(!prevXDown)
        {
            SetLoaderState(MENU);
            dcAudio_SfxPlay(&gAcceptSfx);
        }
        prevXDown = 1;
    }
    else prevXDown = 0;
}

RECT tvArea = {74, 70, 175, 98 };

void DrawCredits()
{
    CVECTOR bgColor = {7, 57, 60};
    CVECTOR textColor = {127, 127, 127};
    CVECTOR color;

    int y = creditsY;

    DVECTOR characterSize;
    dcFont_GetCharacterSize(&characterSize);

    for(int i = 0; i < numCreditsNames; ++i)
    {
        int textSize = creditsLineLength[i] * characterSize.vx;
        int xOffset = (tvArea.w - textSize) >> 1;
        long alpha = (DC_MIN( 50 - abs(DC_CLAMP( DC_MAX(y - 65, 0), 0, 100) - 50), 16 ) << 12) >> 4;
        DC_LERP_COLOR( &bgColor, &textColor, alpha, &color );
        dcFont_PrintZ(&render, tvArea.x + xOffset, y, 2, &color, creditsArray[i]);
        y += 16;
    }

}

int ticksInIntro = 0;
int maxTicksInIntro = 500;
int maxTicksIntroAnimation = 200;

void UpdateIntro()
{

    ticksInIntro++;
    if(ticksInIntro >= maxTicksInIntro)
    {
        SetLoaderState(MENU);
    }
}

void DrawIntro()
{

    CVECTOR textColor = {128, 92, 37};

    DVECTOR characterSize;
    dcFont_GetCharacterSize(&characterSize);

    long yFinal = tvArea.y + ( tvArea.h >> 1 ) - characterSize.vy;

    char text[] = {0, 0};
    
    // Chache some random values and reuse later instead of computing it for each character
    long alphas[] = { 
        dcMath_EaseOutBounce(( DC_MIN(ticksInIntro, maxTicksIntroAnimation + 50)  << 12 ) / (maxTicksIntroAnimation + 50)),
        dcMath_EaseOutBounce(( DC_MIN(ticksInIntro, maxTicksIntroAnimation - 50)  << 12 ) / (maxTicksIntroAnimation - 50)),
        dcMath_EaseOutBounce(( DC_MIN(ticksInIntro, maxTicksIntroAnimation + 25)  << 12 ) / (maxTicksIntroAnimation + 25)),
        dcMath_EaseOutBounce(( DC_MIN(ticksInIntro, maxTicksIntroAnimation - 25)  << 12 ) / (maxTicksIntroAnimation - 25)),
        dcMath_EaseOutBounce(( DC_MIN(ticksInIntro, maxTicksIntroAnimation + 13)  << 12 ) / (maxTicksIntroAnimation + 13)),
        dcMath_EaseOutBounce(( DC_MIN(ticksInIntro, maxTicksIntroAnimation - 14)  << 12 ) / (maxTicksIntroAnimation - 14)),
        dcMath_EaseOutBounce(( DC_MIN(ticksInIntro, maxTicksIntroAnimation)  << 12 ) / maxTicksIntroAnimation),
        dcMath_EaseOutBounce(( DC_MIN(ticksInIntro, maxTicksIntroAnimation + 37)  << 12 ) / (maxTicksIntroAnimation + 37))
    };
    
    for(int i = 0; i < 2; ++i)
    {
        int textSize = creditsLineLength[i] * characterSize.vx;
        int xOffset = (tvArea.w - textSize) >> 1;


        if(ticksInIntro < maxTicksIntroAnimation + 100 )
        {
            for(int charIdx = 0; charIdx < creditsLineLength[i]; ++ charIdx)
            {
                long randYOffset = 70 - ( abs(dcMisc_Noise(xOffset, i, charIdx)) >> 5 );
                long randAlphaOffset = dcMisc_Noise( i, charIdx, xOffset );
                int randIdx = (randYOffset ^ randAlphaOffset) & 0x07;

                int randAlpha = alphas[randIdx] + DC_MAX(ticksInIntro - maxTicksIntroAnimation, 0);

                long animatedY = DC_LERP(randYOffset, yFinal, randAlpha );
                animatedY = DC_MIN(animatedY, yFinal);
                
                text[0] = creditsArray[i][charIdx];
                dcFont_PrintZ(&render, tvArea.x + xOffset, animatedY, 2, &textColor, text);

                xOffset += characterSize.vx;
            }
        }
        else
        {
            dcFont_PrintZ(&render, tvArea.x + xOffset, yFinal, 2, &textColor, creditsArray[i]);
        }

        yFinal += 16;
    }
    
}

void SetLoaderState(ELoaderState newState)
{
    state = newState;

    if(state == CREDITS)
    {
        creditsY = 150; 
        creditTicks = 0;
    }
    if(state == INTRO)
    {
        ticksInIntro = 0;
    }

}
