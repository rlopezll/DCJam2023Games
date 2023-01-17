#include "gameover.h"

#include <stdio.h>

#include "airport.h"
#include "dcInput.h"
#include "dcFont.h"
#include "gamestate.h"

SDC_Input input[2]; 

SDC_TIM_IMAGE gGameOverLogo;
extern unsigned long _binary_data_GameOver_tim_start[];

int gGameOverFlipTextTimer = 0; 
bool gGameOverShowPrompt = false;

void InitGameOver() {
    dcInput_InitializePad(&input[0], 0);
    dcInput_InitializePad(&input[1], 1);
    dcRender_LoadTexture(&gGameOverLogo, _binary_data_GameOver_tim_start);
}

void UpdateGameOver(int elapsed) {
    dcInput_UpdateInput(&input[0]);
    dcInput_UpdateInput(&input[1]);

     gGameOverFlipTextTimer -= elapsed;

    if ( gGameOverFlipTextTimer < 0 )
    { 
        gGameOverShowPrompt = !gGameOverShowPrompt; 
        gGameOverFlipTextTimer = gGameOverShowPrompt? 50 : 10;
    }

    if ( dcInput_BecomesPressed(&input[0],PADstart) ||  dcInput_BecomesPressed(&input[1],PADstart) )
    {
        GameState_ChangeGameState(MAINMENU_GAMESTATE);
    }
}

void RenderGameOver(SDC_Render* render, SDC_Camera* camera) 
{
    int score = GetAirportScore();

    CVECTOR color = {127, 127, 127};

    DVECTOR uv;
    uv.vx = 0;
    uv.vy = 0;
    dcRender_DrawSpriteRect(render, &gGameOverLogo, 192, 50, 256, 128, &uv, &color);

    //Render UI / Score
    dcFont_Print(render, 300, 115, &color, "SCORE:");

    char txt[256];
    sprintf(txt, "%d\n", score);
    dcFont_Print(render, 300, 130, &color, txt);

    if ( gGameOverShowPrompt )
    { 
        dcFont_Print(render, 220, 190, &color, "PRESS START TO GO BACK MENU\n");
    }
}