#include "titleGameMode.h"
#include "tdGameplay.h"
#include "dcMath.h"
#include "tdConfig.h"
#include <libetc.h>
#include <stdio.h>
#include "riverGameMode.h"

SDC_Camera titleCamera;

int titleInitializeTexture = 0;
SDC_Texture titleBackground;
extern unsigned long _binary_assets_textures_sky_psx_tim_start[];
extern unsigned long _binary_assets_textures_main_title_tim_start[];

int titleFrameCounter = 0;
int framesToStart = 300;

tdGameMode titleGameMode = 
{
    .camera = &titleCamera,
    .initFunction = &titleInitScene,
    .updateLoopFunction = &titleUpdateScene,
    .drawFunction = &titleDrawScene
};

void titleInitScene(tdGameMode* gameMode)
{
    if (!titleInitializeTexture)
    {
        TIM_IMAGE timImage;
        dcRender_LoadTexture(&timImage, _binary_assets_textures_main_title_tim_start);
        titleBackground.mode = timImage.mode;
        titleBackground.crect = *timImage.crect;
        titleBackground.prect = *timImage.prect;

        titleInitializeTexture = 1;
    }

    dcCamera_SetScreenResolution(gameMode->camera, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void titleUpdateScene(tdGameMode* gameMode)
{
    int startGame = 0;

    ++titleFrameCounter;
    if (titleFrameCounter >= framesToStart)
    {
        startGame = 1;
    }

    u_long padState = PadRead(0);
    if( _PAD(0,PADstart ) & padState )
    {
        startGame = 1;
    }

    if (startGame)
    {
        nextGameMode = &riverGameMode;
    }
}

void titleDrawScene(tdGameMode* gameMode, SDC_Render* render)
{
    dcRender_DrawTitle(render, &titleBackground);
}
