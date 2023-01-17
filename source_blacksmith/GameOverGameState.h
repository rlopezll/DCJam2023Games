#ifndef _DC_GAMEOVER_GAMESTATE
#define _DC_GAMEOVER_GAMESTATE

#include "dcSprite.h"

typedef struct
{
    char GameOverText[10];
    char PressStartText[12];
    char bActivatePressStartEffet;

    SDC_Sprite EnemyRedSprite;
    SDC_Sprite EnemyBlueSprite;
    SDC_Sprite EnemyGreenSprite;
    SDC_Sprite EnemyYellowSprite;


} FGameOverGameState;

void GOGS_Init(FGameOverGameState* GameState);
void GOGS_Update(FGameOverGameState* GameState);
void GOGS_Close(FGameOverGameState* GameState);

#endif