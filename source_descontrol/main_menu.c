#include "main_menu.h"

#include "dcInput.h"
#include "dcFont.h"
#include "dcAudio.h"
#include "gamestate.h"

SDC_Input inputMenu[2];

int gMenuFlipTextTimer = 0; 
bool gMenuShowPrompt = false;

SDC_TIM_IMAGE gMainMenuLogo;
SDC_Sfx       gPressStartSfx;

extern SDC_Audio gAudio;

extern unsigned long _binary_data_DESCONTROL_tim_start[];
extern unsigned long _binary_data_PressStart_vag_start[];

void InitMainMenu() 
{
    dcInput_InitializePad(&inputMenu[0], 0);
    dcInput_InitializePad(&inputMenu[1], 1);

    dcRender_LoadTexture(&gMainMenuLogo, _binary_data_DESCONTROL_tim_start);
    dcAudio_SfxLoad(&gAudio, &gPressStartSfx, (u_char *)_binary_data_PressStart_vag_start);
}

bool menuBecomedPressed(int key)
{
    return dcInput_BecomesPressed(&inputMenu[0],key) ||  dcInput_BecomesPressed(&inputMenu[1],key);
}

void UpdateMainMenu(int elapsed) 
{
    dcInput_UpdateInput(&inputMenu[0]);
    dcInput_UpdateInput(&inputMenu[1]);

    gMenuFlipTextTimer -= elapsed;

    if ( gMenuFlipTextTimer < 0 )
    { 
        gMenuShowPrompt = !gMenuShowPrompt; 
        gMenuFlipTextTimer = gMenuShowPrompt? 50 : 10;
    }

    if ( menuBecomedPressed(PADstart) )
    {
        dcAudio_SfxPlay(&gPressStartSfx);
        GameState_ChangeGameState(AIRPORT_GAMESTATE);
    }
}

void RenderMainMenu(SDC_Render* render, SDC_Camera* camera) 
{
    CVECTOR color = {127, 127, 127};

    DVECTOR uv;
    uv.vx = 0;
    uv.vy = 0;
    dcRender_DrawSpriteRect(render, &gMainMenuLogo, 192, 50, 256, 128, &uv, &color);

    if ( gMenuShowPrompt )
    { 
        dcFont_Print(render, 250, 190, &color, "PRESS START TO PLAY\n");
    }
}