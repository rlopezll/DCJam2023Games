#ifndef RIVER_GAME_MODE_H
#define RIVER_GAME_MODE_H

#include "tdGameplay.h"
#include "dcSprite.h"

struct SDC_Render;

extern tdGameMode riverGameMode;

void riverInitScene(tdGameMode* gameMode);
void riverUpdateScene(tdGameMode* gameMode);
void riverDrawScene(tdGameMode* gameMode, SDC_Render* render);

void riverUpdateUI();
void riverDrawUI(tdGameMode* gameMode, SDC_Render* render);

typedef enum
{
    IDLE,
    DAMAGE,
    SPEED,
    GAMEOVER

} ECapitanState;

void SetCapitanState(ECapitanState newState);

typedef struct
{
    SDC_Sprite captainSprite;

    SDC_SpriteAnimation captainDefaultAnim;
    SDC_SpriteAnimation captainDamageAnim;
    SDC_SpriteAnimation captainGameOverAnim;
    SDC_SpriteAnimation captainSpeedAnim;

    ECapitanState capitainState;
    int timeInState;

    RECT captainDrawLocation;

    /* data */
} tdRiverUI;


#endif