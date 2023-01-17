#ifndef _DC_ENEMY_MANAGER_
#define _DC_ENEMY_MANAGER_

#include "Enemy.h"
#include "../Contract.h"

#define MAX_ENEMIES 60
#define NUM_TYPE_ENEMIES 4

typedef struct 
{
    Enemy RedEnemies[MAX_ENEMIES];
    u_short NumberRedEnemy;

    Enemy BlueEnemies[MAX_ENEMIES];
    u_short NumberBlueEnemy;

    Enemy YellowEnemies[MAX_ENEMIES];
    u_short NumberYellowEnemy;

    Enemy GreenEnemies[MAX_ENEMIES];
    u_short NumberGreenEnemy;

    VECTOR FarFromPlayerLocations[MAX_ENEMIES];

} EnemyManager;                                                                                                                                                                                                                                                                      

void EM_Init(EnemyManager* EM, SceneMap* Map, Player* ToHunt);
void EM_SpawnEnemy(EnemyManager* EM, EEnemyType EnemyType, Player* ToHunt);
void EM_Update(EnemyManager* EM, Player* ToHunt, ContractData* Contract);
void EM_Draw(EnemyManager* EM, Player* MainPlayer);
void EM_ClearEnemies(EnemyManager* EM);
void EM_GenerateFarFromPlayerLocations(EnemyManager* EM, Player* ToHunt, Enemy* ToFill);

#endif