#include "GameOverGameState.h"
#include "engine.h"

void GOGS_Init(FGameOverGameState* GameState)
{
    strcpy(GameState->GameOverText, "GAME OVER");
    strcpy(GameState->PressStartText, "PRESS START");
    GameState->bActivatePressStartEffet = 0;
    
    dcSprite_SetAnimation(&GameState->EnemyRedSprite, &EnemyRedAnimations);
    dcSprite_SetAnimation(&GameState->EnemyBlueSprite, &EnemyBlueAnimations);
    dcSprite_SetAnimation(&GameState->EnemyGreenSprite, &EnemyGreenAnimations);
    dcSprite_SetAnimation(&GameState->EnemyYellowSprite, &EnemyYellowAnimations);
    
    if(GEngineInstance.CanPlayAudio)
    {
        dcAudio_MusicPlay(GEngineInstance.AudioPtr, 0);
    }
}

void GOGS_Update(FGameOverGameState* GameState)
{
    int pad = 0;
    if (GEngineInstance.CurrentGameState == GS_GAME_OVER)
    {
        dcSprite_Update(&GameState->EnemyRedSprite);
        dcSprite_Update(&GameState->EnemyBlueSprite);
        dcSprite_Update(&GameState->EnemyYellowSprite);
        dcSprite_Update(&GameState->EnemyGreenSprite);

        // Input
        pad = PadRead(0);
        if(pad & PADstart)
        {
            GEngineInstance.DesiredGameState = GS_MAIN_MENU;
            GameState->bActivatePressStartEffet = 1;
            dcAudio_SfxPlay(&SwordAudio);
        }

        CVECTOR ColorSprit = {128, 128, 128};
        dcSprite_Render(GEngineInstance.RenderPtr, &GameState->EnemyRedSprite, RENDER_WIDTH / 2 - 80, RENDER_HEIGHT / 2 - 16, &ColorSprit);
        dcSprite_Render(GEngineInstance.RenderPtr, &GameState->EnemyBlueSprite, RENDER_WIDTH / 2 - 30, RENDER_HEIGHT / 2 - 16, &ColorSprit);
        dcSprite_Render(GEngineInstance.RenderPtr, &GameState->EnemyYellowSprite, RENDER_WIDTH / 2 + 20, RENDER_HEIGHT / 2 - 16, &ColorSprit);
        dcSprite_Render(GEngineInstance.RenderPtr, &GameState->EnemyGreenSprite, RENDER_WIDTH / 2 + 70, RENDER_HEIGHT / 2 - 16, &ColorSprit);
        
        dcFont_Print(GEngineInstance.RenderPtr, RENDER_WIDTH / 2 - 5 * RENDER_FONT_CHAR_SIZE,  7 * RENDER_FONT_CHAR_SIZE, &ColorSprit, GameState->GameOverText);
        dcFont_Print(GEngineInstance.RenderPtr, RENDER_WIDTH / 2 - 6 * RENDER_FONT_CHAR_SIZE, RENDER_HEIGHT - 8 * RENDER_FONT_CHAR_SIZE, &ColorSprit, GameState->PressStartText);
    }
}

void GOGS_Close(FGameOverGameState* GameState)
{
    GameState->bActivatePressStartEffet = 0;
}