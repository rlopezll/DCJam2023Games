#ifndef _GAMESTATE_
#define _GAMESTATE_

#include "dcRender.h"
#include "dcCamera.h"

enum EGameStates {
    AIRPORT_GAMESTATE = 0,
    MAINMENU_GAMESTATE = 1, 
    GAMEOVER_GAMESTATE = 2,
    INTRO_GAMESTATE = 3,
};

typedef struct {
    void (*InitFunc)();
    void (*UpdateFunc)(int);
    void (*RenderFunc)(SDC_Render* render, SDC_Camera* camera);
} SGameState;

void GameState_ChangeGameStateEx(SGameState *NewGameState);
void GameState_ChangeGameState(enum EGameStates state);
void GameState_Update(int elapsed);
void GameState_Render(SDC_Render* render, SDC_Camera* camera);

#endif