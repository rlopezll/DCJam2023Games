#include "GameLoopGameState.h"
#include "engine.h"
#include "render.h"
#include "characters/EnemyManager.h"
#include "Contract.h"
#include "dcMisc.h"
#include <assert.h>

void InitScene(FGameLoopGameState *GameState);

void GLGS_Init(FGameLoopGameState *GameState)
{
    // Contract setup.
    ContractInit(&GameState->Contract);

    //  Setup player data.
    InitPlayer(GameState);

    //  Setup scene data.
    InitScene(GameState);

    // Init enemy manager
    EM_Init(&GameState->MyEnemyManager, &GameState->SceneData, &GameState->PlayerInstance);

    if(GEngineInstance.CanPlayAudio)
    {
        dcAudio_MusicPlay(GEngineInstance.AudioPtr, 1);
    }

    int InitSpawnAmount = GameState->Contract.InitSpawnEnemies / TOTAL_ENEMIES;

    for (int i = 0; i < InitSpawnAmount; i++)
    {
        EM_SpawnEnemy(&GameState->MyEnemyManager, ENEMY_BLUE, &GameState->PlayerInstance);
        EM_SpawnEnemy(&GameState->MyEnemyManager, ENEMY_RED, &GameState->PlayerInstance);
        EM_SpawnEnemy(&GameState->MyEnemyManager, ENEMY_YELLOW, &GameState->PlayerInstance);
        EM_SpawnEnemy(&GameState->MyEnemyManager, ENEMY_GREEN, &GameState->PlayerInstance); 
    }

    GameState->CurrentTicks = 0;
    GameState->CurrentSeconds = 0;
}

void HandlePlayerInput(FGameLoopGameState *GameState)
{
}

void GLGS_Update(FGameLoopGameState *GameState)
{
    // Calc time
    int currentTicksDebug = ++GameState->CurrentTicks;
    if(currentTicksDebug == RENDER_FRAMERATE)
    {
        ++GameState->CurrentSeconds;
        GameState->CurrentTicks = 0;
    }
    
    if (ContractCheckWon(&GameState->Contract))
    {
        ChangeGameState(&GEngineInstance, GS_GAME_VICTORY);
    }
    else if(ContractCheckDefeat(&GameState->Contract) || (GOAL_TIME - GameState->CurrentSeconds == 0))
    {
        ChangeGameState(&GEngineInstance, GS_GAME_OVER);
    }
    else
    {

        //  Player input.
        PlayerInput(&GameState->PlayerInstance, &GameState->SceneData);

        //  Update player logic.
        PlayerUpdate(&GameState->PlayerInstance);

        //  Update enemy manager.
        EM_Update(&GameState->MyEnemyManager, &GameState->PlayerInstance, &GameState->Contract);

        // Draw UI 
        // draw balls and score first
        DVECTOR UV = {0, 0};
        CVECTOR Color = {128, 128, 128};
        char TimeStr[4] = "";
        char CurrentBlueEnemiesStr[3] = "";
        char EnemiesToLoseStr[3] = "";
        sprintf( TimeStr, "%d", GOAL_TIME - GameState->CurrentSeconds );
        sprintf( CurrentBlueEnemiesStr, "%d", GameState->Contract.BlueEnemiesToPick - GameState->Contract.CurrentPickedBlues);
        sprintf( EnemiesToLoseStr, "%d", GameState->Contract.EnemiesToLose);
        dcFont_Print(GEngineInstance.RenderPtr, 15, 10, &Color, "KILL");
        dcFont_Print(GEngineInstance.RenderPtr, 70, 10, &Color, "AVOID");
        dcFont_Print(GEngineInstance.RenderPtr, RENDER_WIDTH - 4 * RENDER_FONT_CHAR_SIZE, 10, &Color, TimeStr);
        
        dcRender_DrawSpriteRect(GEngineInstance.RenderPtr, &TimBlueBall, 15, 20, 16, 16, &UV, &Color);
        dcFont_Print(GEngineInstance.RenderPtr, 35, 25, &Color, CurrentBlueEnemiesStr);
        
        dcRender_DrawSpriteRect(GEngineInstance.RenderPtr, &TimRedBall, 65, 20, 16, 16, &UV, &Color);
        dcRender_DrawSpriteRect(GEngineInstance.RenderPtr, &TimGreenBall, 81, 20, 16, 16, &UV, &Color);
        dcRender_DrawSpriteRect(GEngineInstance.RenderPtr, &TimYellowBall, 97, 20, 16, 16, &UV, &Color);
        dcFont_Print(GEngineInstance.RenderPtr, 115, 25, &Color, EnemiesToLoseStr);
        
        //  Draw hero.
        PlayerDraw(&GameState->PlayerInstance);
        
        //  Draw enemy.
        EM_Draw(&GameState->MyEnemyManager, &GameState->PlayerInstance);

        //  Draw scene.
        SceneMap_Draw(&GameState->SceneData, &GameState->PlayerInstance.CameraPosition);
    }
}

void GLGS_Close(FGameLoopGameState *GameState)
{
    GameState->CurrentTicks = 0;
    GameState->CurrentSeconds = 0;
}

void InitPlayer(FGameLoopGameState *GameState)
{
    PlayerInit(&GameState->PlayerInstance, &GameState->SceneData);
}

void InitScene(FGameLoopGameState *GameState)
{
    SceneMap_Init(&GameState->SceneData);
}