#include "intro.h"

#include "gamestate.h"

static int gIntroState = 0; 
static int gIntroTimer = 0;  
static int gIntroTransparency = 0; 

static int kFadeInTime  = 50; 
static int kStayTime    = 175; 
static int kFadeOutTime = 50; 
static int kInBetweenTime = 25; 

static SDC_Render* gHackRender = NULL; 

extern unsigned long _binary_data_DESCONTROL_tim_start[];
extern unsigned long _binary_data_GameDev_tim_start[];
SDC_TIM_IMAGE gIntroLogo;

void InitIntro()
{
    dcRender_LoadTexture(&gIntroLogo, _binary_data_GameDev_tim_start);
}

void UpdateIntro(int elapsed)
{
    gIntroTimer -= elapsed; 

    if ( gIntroTimer < 0 )
    {
        ++gIntroState;
        if ( gIntroState == 1 )
        { 
            gIntroTimer = kFadeInTime; 
        }
        else if ( gIntroState == 2)
        { 
            gIntroTimer = kStayTime; 
        }
        else if ( gIntroState == 3)
        {
            gIntroTimer = kFadeOutTime; 
        }
        else if ( gIntroState == 4)
        {
            dcRender_LoadTexture(&gIntroLogo, _binary_data_DESCONTROL_tim_start);
            gIntroTimer = kInBetweenTime; 
        }
        else if ( gIntroState == 5)
        {
            gIntroTimer = kFadeInTime; 
        }
        else
        { 
            GameState_ChangeGameState(MAINMENU_GAMESTATE);
        }
    }
    else 
    {
         if ( gIntroState == 1 )
        { 
            gIntroTransparency = 255 - ((255 * gIntroTimer) / kFadeInTime);
        }
        else if ( gIntroState == 2)
        { 
            gIntroTransparency = 255; 
        }
        else if ( gIntroState == 3)
        {
            gIntroTransparency =  (255 * gIntroTimer) / kFadeOutTime;
        }
        else if ( gIntroState == 4)
        { 
            gIntroTransparency = 0; 
        }
        else if ( gIntroState == 5)
        { 
            gIntroTransparency = 255 - ((255 * gIntroTimer) / kFadeInTime);
        }
        else
        { 
            gIntroTransparency = 0; 
        }
    }
}

void RenderIntro(SDC_Render* render, SDC_Camera* camera)
{
    u_char realModifier = gIntroTransparency / 2; 
    CVECTOR color = {realModifier, realModifier, realModifier};

    DVECTOR uv;
    uv.vx = 0;
    uv.vy = 0;

    dcRender_DrawSpriteRect(render, &gIntroLogo, 192, gIntroState < 4 ? 60 : 50, 256, 128, &uv, &color);
}