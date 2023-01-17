#include "MenuGameState.h"
#include "engine.h"

void MGS_Init(MenuGameState* MGSPtr)
{
    strcpy(MGSPtr->PressStartText, "PRESS START");
    strcpy(MGSPtr->TeamName, "DEMO1 - GAMEDEVCHALLENGE 2023");
    MGSPtr->bActivatePressStartEffet = 0;
    MGSPtr->PressAnimationFrames = 0;
    MGSPtr->TotalFrames = 0;
    
    if(GEngineInstance.CanPlayAudio)
    {
        dcAudio_MusicPlay(GEngineInstance.AudioPtr, 0);
    }
}

extern RealTIMImage Tim;

void MGS_Update(MenuGameState* MGSPtr)
{
    if(GEngineInstance.CurrentGameState == GS_MAIN_MENU) 
    {
        CVECTOR Color = {95, 39, 37};
        CVECTOR PermColor = {128, 128, 128};
        
        // Input
        int pad = 0;
        pad = PadRead(0);
        // if(pad & PADRup)  //△
        if(pad & PADstart)
        {
            MGSPtr->bActivatePressStartEffet = 1;
            dcAudio_SfxPlay(&SwordAudio);
            // GEngineInstance.DesiredGameState = GS_GAME_LOOP;
        }
        if(MGSPtr->bActivatePressStartEffet)
        {
            ++MGSPtr->TotalFrames;
            ++MGSPtr->PressAnimationFrames;
            // Set text
            if(MGSPtr->PressAnimationFrames >= FRAMES_PER_STATE_ANIM)
            {
                if(Color.r == 0)
                {
                    Color.r = 95;
                    Color.g = 39;
                    Color.b = 37;
                }
                else
                {
                    Color.r = 128;
                    Color.g = 128;
                    Color.b = 128;
                }
                MGSPtr->PressAnimationFrames = 0;
            }
            
            if(MGSPtr->TotalFrames >= ANIM_TIME)
            {
                MGSPtr->bActivatePressStartEffet = 0;
                GEngineInstance.DesiredGameState = GS_GAME_LOOP;
            }    

        }
        // Draw texts
        DVECTOR UV = {0, 0};
        dcFont_Print(GEngineInstance.RenderPtr, (RENDER_WIDTH / 2 - 6 * RENDER_FONT_CHAR_SIZE) + 2, RENDER_HEIGHT - 40, &Color, MGSPtr->PressStartText);
        dcFont_Print(GEngineInstance.RenderPtr, RENDER_WIDTH / 4 , RENDER_HEIGHT - 12, &PermColor, MGSPtr->TeamName);            
        dcRender_DrawSpriteRect(GEngineInstance.RenderPtr, &TimTitleScreen, 32, 0, 256, 256, &UV, &PermColor);
    }
}

void MGS_Close(MenuGameState* MGSPtr)
{
   printf("MenuGameState::OnExit\n");
}