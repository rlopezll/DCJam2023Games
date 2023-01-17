#ifndef _DC_PLAYERINSTANCE_
#define _DC_PLAYERINSTANCE_

#include "dcAudio.h"
#include "dcMath.h"
#include "dcCamera.h"
#include "dcSprite.h"
#include "../scene/scene.h"

typedef enum
{
    PLAYER_MOVING,
    PLAYER_ATTACKING,
    PLAYER_NUM_ANIMATIONS
} PLAYER_ACTION;

typedef struct 
{
    VECTOR PlayerPosition;
    VECTOR CameraPosition;
    int Speed;
    int RadiusColision;
    int CountDown;

    SDC_Sprite CurrentSprite[PLAYER_NUM_ANIMATIONS];
    SDC_SpriteAnimation Animations[PLAYER_NUM_ANIMATIONS];
    PLAYER_ACTION CurrentPlayerAction;
} Player;

/* Player Methods  */

void PlayerInit(Player* Self, SceneMap* Map);
void PlayerInput(Player* Self, SceneMap* Map);
void PlayerUpdate(Player* Self);
void PlayerDraw(Player* Self);
void PlayerDie(Player* Self);
void PlayerAttack(Player* Self);

char CanMove(Player* Self, SceneMap* Map);
char LiesOnLeftHand(VECTOR EdgePosition1, VECTOR EdgePosition2, VECTOR PlayerPosition);
#endif