#ifndef _DC_ENGINE_
#define _DC_ENGINE_

// screw you code formatter, this one needs to stay on top
#include <stdlib.h>
// now we need to have libgte.h
#include <libgte.h>
// then, these can work; the psyq library is badly written and won't include what it uses
#include <libetc.h>
#include <libgpu.h>
#include <stdio.h>
#include <types.h>
#include <string.h>

#include "configuration/GlobalVars.h"
#include "dcAudio.h"
#include "dcMath.h"
#include "dcCamera.h"
#include "dcFont.h"
#include "render.h"
#include "dcMemory.h"
#include "dcMisc.h"
#include "dcCollision.h"
#include "dcSprite.h"
#include "Resources.h"
#include "GameLoopGameState.h"
#include "ContractGameState.h"
#include "GameOverGameState.h"
#include "MenuGameState.h"
#include "GameVictoryGameState.h"

typedef enum
{
    GS_UNDEFINED,
    GS_MAIN_MENU,
    GS_CONTRACT,
    GS_GAME_LOOP,
    GS_GAME_OVER,
    GS_GAME_VICTORY
} EGameState;

typedef struct
{
    SDC_Render * RenderPtr;
    SDC_Audio * AudioPtr;
    int CanPlayAudio;

    EGameState CurrentGameState;
    EGameState DesiredGameState;
    FGameLoopGameState* GameLoopGameState;
    FContractGameState* ContractGameState;
    FGameOverGameState* GameOverGameState;
    FGameVictoryGameState* VictoryGameState;
    MenuGameState* MenuGameState;
    
} Engine;

// Global var.
extern Engine GEngineInstance;

/* Engine Methods  */

void Init(Engine * EnginePtr);

void Update(Engine * EnginePtr);

void Close(Engine * EnginePtr);

/* Gamestate Change */

void ChangeGameState(Engine * EnginePtr, EGameState NewGameState);

#endif