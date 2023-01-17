#include "gamestate.h"
#include <stdlib.h>
#include <libgte.h>
#include <libgpu.h>
#include <libgs.h>

#include "dcAudio.h"
#include "airport.h"
#include "main_menu.h"
#include "gameover.h"
#include "intro.h"

SGameState *CurrentGameState = NULL;
extern SDC_Audio gAudio;

SGameState GameStates[] = { {StartAirport, UpdateAirport, RenderAirport},
                            {InitMainMenu, UpdateMainMenu, RenderMainMenu}, 
                            {InitGameOver, UpdateGameOver, RenderGameOver}, 
                            {InitIntro,    UpdateIntro,    RenderIntro} };

void GameState_ChangeGameStateEx(SGameState *NewGameState) {
    CurrentGameState = NewGameState;
    if(!CurrentGameState)
        return;

    CurrentGameState->InitFunc();
}

void GameState_ChangeGameState(enum EGameStates state)
{
    switch (state)
    {
    case AIRPORT_GAMESTATE:
        dcAudio_MusicPlay(&gAudio, 1);
        break;
    case MAINMENU_GAMESTATE:
        dcAudio_MusicPlay(&gAudio, 0);
        break;
    case GAMEOVER_GAMESTATE:
        dcAudio_MusicPlay(&gAudio, 0);
        break;        
    case INTRO_GAMESTATE:
        break;
    }
    GameState_ChangeGameStateEx(&GameStates[state]);
}

void GameState_Update(int elapsed) {
    if(!CurrentGameState)
        return;
    CurrentGameState->UpdateFunc(elapsed);
}

void GameState_Render(SDC_Render* render, SDC_Camera* camera) {
    if(!CurrentGameState)
        return;
    CurrentGameState->RenderFunc(render, camera);
}