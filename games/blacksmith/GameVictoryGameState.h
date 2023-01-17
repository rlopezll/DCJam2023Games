#ifndef _DC_GAMEVICTORY_GAMESTATE_
#define _DC_GAMEVICTORY_GAMESTATE_

#include "dcSprite.h"

typedef struct
{
    char VictoryText[10];
    char PressStartText[35];
    char bActivatePressStartEffet;

    SDC_Sprite PlayerSprite;


} FGameVictoryGameState;

void GVGS_Init(FGameVictoryGameState* GameState);
void GVGS_Update(FGameVictoryGameState* GameState);
void GVGS_Close(FGameVictoryGameState* GameState);

#endif