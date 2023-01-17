#ifndef _DC_GAME_LOOP_GAMESTATE_
#define _DC_GAME_LOOP_GAMESTATE_

#include "dcMath.h"
#include "dcCamera.h"
#include "dcSprite.h"
#include "scene/scene.h"
#include "player/player.h"
#include "characters/EnemyManager.h"

#define GOAL_TIME 60

typedef struct
{
    Player PlayerInstance;
    SceneMap SceneData;
    ContractData Contract;
    EnemyManager MyEnemyManager;
    int CurrentTicks;
    long CurrentSeconds;
} FGameLoopGameState;

void GLGS_Init(FGameLoopGameState* GameState);
void GLGS_Update(FGameLoopGameState* GameState);
void GLGS_Close(FGameLoopGameState* GameState);

void InitPlayer(FGameLoopGameState* GameState);

#endif