#ifndef _DC_ENEMY_
#define _DC_ENEMY_

#include "dcAudio.h"
#include "dcSprite.h"
#include "../player/player.h"

#define ENEMY_RED_VELOCITY 2
#define ENEMY_BLUE_VELOCITY 1     
#define ENEMY_YELLOW_VELOCITY 3   
#define ENEMY_GREEN_VELOCITY 3 

typedef enum
{
    ENEMY_RED,
    ENEMY_YELLOW,
    ENEMY_GREEN,
    ENEMY_BLUE,

    TOTAL_ENEMIES
} EEnemyType;

typedef struct 
{
    int Velocity;
    EEnemyType Type;
    VECTOR Position;
    SDC_Sprite CurrentSprite;
    SDC_SpriteAnimation SpriteAnimation;
    int Radius;
    
    int AudioFrameSkip;
    // debug
    CVECTOR Color;
    int FrameSkip;
} Enemy;

static const CVECTOR EnemyRedColor = {255, 0, 0, 255};
static const CVECTOR EnemyBlueColor = {0, 0, 255, 255};
static const CVECTOR EnemyYellowColor = {0, 255, 255, 255};
static const CVECTOR EnemyGreenColor = {0, 255, 0, 255};

void EnemyInit(Enemy* Self);
void EnemyUpdate(Enemy* Self, Player* ToHunt);
char EnemyCheckCollision(Enemy* Self, Player* ToHunt);
void EnemyDraw(Enemy* Self,Player* MainPlayer);
void EnemyDie(Enemy* Self);

#endif