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

#include "dcMemory.h"
#include "dcMath.h"
#include "dcCamera.h"
#include "dcRender.h"
#include "dcAudio.h"

#include "dcMisc.h"
#include "dcCollision.h"

#include "tdGameplay.h"
#include "riverGameMode.h"
#include "titleGameMode.h"
#include "scenes/LVL_TestScene.h"
#include "scenes/LVL_Lonchas.h"

#define RCntIntr		0x1000				/*Interrupt mode*/
unsigned int perftest_lastcounter; // the last sampled counter value
unsigned int perftest_numcycles; // the number of completed test cycles
unsigned int perftest_currtest; // which test is currently running

extern unsigned long _binary_assets_audio_hit_vag_start[];
extern unsigned long _binary_assets_audio_wallhit_vag_start[];
extern unsigned long _binary_assets_audio_jump_vag_start[];

SDC_Sfx hitSfx;
SDC_Sfx wallHitSfx;
SDC_Sfx jumpSfx;

extern int totalPrimitives;

SDC_Render render;
SDC_Audio audio;
SDC_DrawParams drawParams = {
    .tim = NULL,
    .constantColor = {255, 255, 255},
    .bLighting = 0,
    .bUseConstantColor = 1
};

SVECTOR rotation = {0};
VECTOR translation = {-512, 600, -512, 0};
MATRIX transform;

SDC_Camera camera;
long distance = 800;
long cameraHeight = 600;

tdGameMode* currentGameMode = NULL;
tdGameMode* nextGameMode = NULL;
extern tdTIMDataHandler timData[10];

int bDrawHouses = 0;

SVECTOR cameraOffset = {0, 0, 0};

int bEpicDebugMode = 0;

SDC_Broadphase Broadphase;

void InitGameMode(tdGameMode* gameMode)
{
    if (gameMode->initFunction)
    {
        gameMode->initFunction(gameMode);
    }
}

void UpdateGameMode(tdGameMode* gameMode)
{
    if (gameMode->updateLoopFunction)
    {
        gameMode->updateLoopFunction(gameMode);
    }
}

void DrawGameMode(tdGameMode* gameMode, SDC_Render* render)
{
    if (gameMode->drawFunction)
    {
        gameMode->drawFunction(gameMode, render);
    }
}

int main(void) 
{
    dcMemory_Init();

    int CounterMaxValue = 240; /*This means this counter resets every 240 HBlanks*/
    SetRCnt(RCntCNT1, CounterMaxValue, RCntIntr);
    StartRCnt(RCntCNT1);

    PadInit(0);
    InitGeom();
    
    CVECTOR bgColor = {60, 120, 120};
    dcRender_Init(&render, SCREEN_WIDTH, SCREEN_HEIGHT, bgColor, 4096, 16384*10, RENDER_MODE_PAL);
    dcAudio_Init(&audio, 16);

    //load sfx
    dcAudio_SfxLoad(&audio, &hitSfx, (u_char *)_binary_assets_audio_hit_vag_start);
    dcAudio_SfxLoad(&audio, &wallHitSfx, (u_char *)_binary_assets_audio_wallhit_vag_start);
    dcAudio_SfxLoad(&audio, &jumpSfx, (u_char *)_binary_assets_audio_jump_vag_start);

    dcBF_Init(&Broadphase, 64);
    for(int i = 0; i < levelData_LVL_Lonchas.numCollisions; ++i)
    {
        // SDC_Shape shape;
        // shape.shapeType = ST_OOBB;
        // shape.oobb.center = levelData_LVL_Lonchas.collisions[i].center;
        // shape.oobb.halfSize.vx = abs(levelData_LVL_Lonchas.collisions[i].halfSize.vx);
        // shape.oobb.halfSize.vy = abs(levelData_LVL_Lonchas.collisions[i].halfSize.vy);
        // shape.oobb.halfSize.vz = abs(levelData_LVL_Lonchas.collisions[i].halfSize.vz);
        // shape.oobb.rotation = levelData_LVL_Lonchas.collisions[i].rotation;


       // dcBF_addShape(&Broadphase, &shape);

    }

    dcCamera_SetScreenResolution(&camera, SCREEN_WIDTH, SCREEN_HEIGHT);
    dcCamera_SetCameraPosition(&camera, 0, cameraHeight, distance);
    dcCamera_LookAt(&camera, &VECTOR_ZERO);
    
    RotMatrix(&rotation, &transform);
    TransMatrix(&transform, &translation);

    u_long prevSelectState = 0;
    currentGameMode = &titleGameMode;
    InitGameMode(currentGameMode);

    //int counterToUse = RCntCNT1;

    while (1)
    {
        //int primitivesBeforeFrame = totalPrimitives;
        // Cycle game-modes by pressing start
        u_long padState = PadRead(0);
        if( nextGameMode != NULL)
        {
            currentGameMode = nextGameMode;
            nextGameMode = NULL;
            InitGameMode(currentGameMode);
        }

        // Debug mode using select
        int currentSelectState = (_PAD(0,PADselect ) & padState );
        if(!currentSelectState && prevSelectState)
        {
            bEpicDebugMode = bEpicDebugMode ? 0 : 1;
        }
        prevSelectState = currentSelectState;

        // Update and draw the current game mode
        //int counterBeforeUpdate = GetRCnt(counterToUse);
        UpdateGameMode(currentGameMode);
        //int counterAfterUpdate = GetRCnt(counterToUse);
        //int counterBeforeDraw = GetRCnt(counterToUse);
        DrawGameMode(currentGameMode, &render);
        //int counterAfterDraw = GetRCnt(counterToUse);
        //int counterBeforeSwap = GetRCnt(counterToUse);
        dcRender_SwapBuffers(&render);
        //int counterAfterSwap = GetRCnt(counterToUse);

        //int updateDuration = counterAfterUpdate - counterBeforeUpdate;
        //int drawDuration = counterAfterDraw - counterBeforeDraw;
        //int swapDuration = counterAfterSwap - counterBeforeSwap;
        //int drawnPrimitives = totalPrimitives - primitivesBeforeFrame;

        //FntPrint("Update: %d Draw: %d Swap: %d \nPrimitives: %d\n", updateDuration, drawDuration, swapDuration, drawnPrimitives);
        
    }

    return 0;
}
