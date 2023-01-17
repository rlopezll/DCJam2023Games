#include "engine.h"
#include <malloc.h>

Engine GEngineInstance;

/* Forward declarations. */

void UpdateGameState(Engine * EnginePtr);
void OnChangeGameState(Engine * EnginePtr);
// Debug
char* GetCurrentGSString(Engine * EnginePtr);

/* Engine Methods  */

void Init(Engine * EnginePtr)
{
    // Setup engine start vars.
    EnginePtr->CurrentGameState = GS_UNDEFINED;
    EnginePtr->DesiredGameState = GS_UNDEFINED;

    // Start PSX systems.
    dcMemory_Init();
    PadInit(0);
    InitGeom();
    
    EnginePtr->RenderPtr = (SDC_Render*)malloc3(sizeof(SDC_Render));
    CVECTOR BackgroundColor = {0, 0, 0};
    dcRender_Init( EnginePtr->RenderPtr, RENDER_WIDTH, RENDER_HEIGHT, BackgroundColor, 4096, RENDER_PRIMITIVES_LIST_SIZE, RENDER_MODE_PAL);
    
    //  Init Audio.
    EnginePtr->AudioPtr = (SDC_Audio*)malloc3(sizeof(SDC_Audio));
    EnginePtr->CanPlayAudio = 0;
    dcAudio_Init(EnginePtr->AudioPtr, 16);

    dcAudio_MusicPlay(EnginePtr->AudioPtr, 0);

    //  Resources.
    Resources_LoadFont();
    Resources_LoadTextureResources();
    Resources_LoadSpriteResources();
    Resources_LoadAudio();

    //  Init game state.
    EnginePtr->GameLoopGameState = (FGameLoopGameState*)malloc3(sizeof(FGameLoopGameState));
    EnginePtr->ContractGameState = (FContractGameState*)malloc3(sizeof(FContractGameState));
    EnginePtr->GameOverGameState = (FGameOverGameState*)malloc3(sizeof(FGameOverGameState));
    EnginePtr->VictoryGameState = (FGameVictoryGameState*)malloc3(sizeof(FGameVictoryGameState));
    EnginePtr->MenuGameState = (MenuGameState*)malloc3(sizeof(MenuGameState));

    GLGS_Init(EnginePtr->GameLoopGameState);
    CGS_Init(EnginePtr->ContractGameState);
    GOGS_Init(EnginePtr->GameOverGameState);
    MGS_Init(EnginePtr->MenuGameState);
    GVGS_Init(EnginePtr->VictoryGameState);

    EnginePtr->CanPlayAudio = 1;
    
    //  Start game state.
    ChangeGameState(EnginePtr, GS_MAIN_MENU);
}

void Update(Engine * EnginePtr)
{
    if(EnginePtr->CurrentGameState != EnginePtr->DesiredGameState)
    {
        OnChangeGameState(EnginePtr);
    }

    // RENDER DEBUG
    // CVECTOR FontDefaultColor = {255, 255, 255}; 
    // char debugGS[50] = "CURRENT GS: ";
    // char currentGS[15] = "";
    // strcpy(currentGS, GetCurrentGSString(EnginePtr));
    // strcat(debugGS, currentGS);
    // dcFont_Print(EnginePtr->RenderPtr, 10, 220, &FontDefaultColor, debugGS);

    UpdateGameState(EnginePtr);
    
    dcAudio_Update(EnginePtr->AudioPtr);
    dcRender_SwapBuffers(EnginePtr->RenderPtr);
}

void Close(Engine * EnginePtr)
{

}

/* Gamestate Change */

void UpdateGameState(Engine * EnginePtr)
{
    switch(EnginePtr->CurrentGameState)
    {
        case GS_MAIN_MENU:
            MGS_Update(EnginePtr->MenuGameState);
        break;
        case GS_CONTRACT:
            CGS_Update(EnginePtr->ContractGameState);
        break;
        case GS_GAME_LOOP:
            GLGS_Update(EnginePtr->GameLoopGameState);
        break;
        case GS_GAME_OVER:
            GOGS_Update(EnginePtr->GameOverGameState);
        break;
        case GS_GAME_VICTORY:
            GVGS_Update(EnginePtr->VictoryGameState);
        break;
        default:
        break;
    }
}

void ChangeGameState(Engine * EnginePtr, EGameState NewGameState)
{
    EnginePtr->DesiredGameState = NewGameState;
}

void OnChangeGameState(Engine * EnginePtr)
{
    // Exit game state
    switch(EnginePtr->CurrentGameState)
    {
        case GS_MAIN_MENU:
            MGS_Close(EnginePtr->MenuGameState);
        break;
        case GS_CONTRACT:
            CGS_Close(EnginePtr->ContractGameState);
        break;
        case GS_GAME_LOOP:
            GLGS_Close(EnginePtr->GameLoopGameState);
        break;
        case GS_GAME_OVER:
            GOGS_Update(EnginePtr->GameOverGameState);
        break;
        case GS_GAME_VICTORY:
            GVGS_Update(EnginePtr->VictoryGameState);
        break;
        default:
        break;
    }

    EnginePtr->CurrentGameState = EnginePtr->DesiredGameState;\

    switch(EnginePtr->CurrentGameState)
    {
        case GS_MAIN_MENU:
            MGS_Init(EnginePtr->MenuGameState);
        break;
        case GS_CONTRACT:
            CGS_Init(EnginePtr->ContractGameState);
        break;
        case GS_GAME_LOOP:
            GLGS_Init(EnginePtr->GameLoopGameState);
        break;
        case GS_GAME_OVER:
            GOGS_Init(EnginePtr->GameOverGameState);
        break;
        case GS_GAME_VICTORY:
            GVGS_Init(EnginePtr->VictoryGameState);
        break;
        default:
        break;
    }
}

// DEBUG
char* GetCurrentGSString(Engine * EnginePtr)
{
    char* CurrentGSString;
    switch (EnginePtr->CurrentGameState)
    {
        case GS_MAIN_MENU:
            CurrentGSString = "GS_MAIN_MENU";
        break;
        case GS_CONTRACT:
            CurrentGSString = "GS_CONTRACT";
        break;
        case GS_GAME_LOOP:
            CurrentGSString = "GS_GAME_LOOP";
        break;
        case GS_GAME_OVER:
            CurrentGSString = "GS_GAME_OVER";
        break;
        default:
            CurrentGSString = "";
        break;
    }
    return CurrentGSString;
}