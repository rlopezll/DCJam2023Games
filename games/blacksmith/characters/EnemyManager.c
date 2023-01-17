#include "EnemyManager.h"
#include "../engine.h"

void EM_CreateEnemy(EnemyManager* EM, Enemy * EnemyToFill, EEnemyType EnemyType, Player* ToHunt);

void EM_Init(EnemyManager* EM, SceneMap* Map, Player* ToHunt)
{
     EM->NumberRedEnemy = 0;
     EM->NumberBlueEnemy = 0;
     EM->NumberGreenEnemy = 0;
     EM->NumberYellowEnemy = 0;
}

void EM_CreateEnemy(EnemyManager* EM, Enemy * EnemyToFill, EEnemyType EnemyType, Player* ToHunt)
{
    EnemyToFill->Type = EnemyType;
    switch (EnemyType)
    {
        case ENEMY_RED:
            EnemyToFill->Velocity = ENEMY_RED_VELOCITY;
            EnemyToFill->Color = EnemyRedColor;
        break;
        case ENEMY_BLUE:
            EnemyToFill->Velocity = ENEMY_BLUE_VELOCITY;
            EnemyToFill->Color = EnemyBlueColor;
        break;
        case ENEMY_YELLOW:
            EnemyToFill->Velocity = ENEMY_YELLOW_VELOCITY;
            EnemyToFill->Color = EnemyYellowColor;
        break;
        case ENEMY_GREEN:
            EnemyToFill->Velocity = ENEMY_GREEN_VELOCITY;
            EnemyToFill->Color = EnemyGreenColor;
        break;
    default:
        break;
    }

    EM_GenerateFarFromPlayerLocations(EM, ToHunt, EnemyToFill);
    EnemyInit(EnemyToFill);

}

void EM_SpawnEnemy(EnemyManager* EM, EEnemyType EnemyType, Player* ToHunt)
{
    switch (EnemyType)
    {
        case ENEMY_RED:
            if(EM->NumberRedEnemy < MAX_ENEMIES)
            {
                EM_CreateEnemy(EM, &EM->RedEnemies[EM->NumberRedEnemy], ENEMY_RED, ToHunt);
                EM->NumberRedEnemy++;
            }
        break;
        case ENEMY_BLUE:
            if(EM->NumberBlueEnemy < MAX_ENEMIES)
            {
                EM_CreateEnemy(EM, &EM->BlueEnemies[EM->NumberBlueEnemy], ENEMY_BLUE, ToHunt);
                EM->NumberBlueEnemy++;
            }
        break;
        case ENEMY_YELLOW:
            if(EM->NumberYellowEnemy < MAX_ENEMIES)
            {
                EM_CreateEnemy(EM, &EM->YellowEnemies[EM->NumberYellowEnemy], ENEMY_YELLOW, ToHunt);
                EM->NumberYellowEnemy++;
            }
        break;
        case ENEMY_GREEN:
            if(EM->NumberGreenEnemy < MAX_ENEMIES)
            {
                EM_CreateEnemy(EM, &EM->GreenEnemies[EM->NumberGreenEnemy], ENEMY_GREEN, ToHunt);
                EM->NumberGreenEnemy++;
            }
        break;
    default:
        break;
    }
}

void EM_Update(EnemyManager* EM, Player* ToHunt, ContractData* Contract)
{
    for(int i=0;i<EM->NumberRedEnemy;i++)
    {
        EnemyUpdate(&EM->RedEnemies[i], ToHunt);
        if (EnemyCheckCollision(&EM->RedEnemies[i], ToHunt))
        {
            int LastRedEnemyIndex = EM->NumberRedEnemy - 1;
            if (LastRedEnemyIndex >= 0)
            {
                Enemy LastRedEnemy = EM->RedEnemies[LastRedEnemyIndex];
                EM->RedEnemies[i] = LastRedEnemy;
                --i;
            }

            EnemyDie(&EM->BlueEnemies[i]);
            EM->NumberRedEnemy--;
            EM_SpawnEnemy(EM, ENEMY_RED, ToHunt);
            ContractPickedRed(Contract);
        }
    }
    
    for(int i=0;i<EM->NumberBlueEnemy;i++)
    {
        EnemyUpdate(&EM->BlueEnemies[i], ToHunt);
        if (EnemyCheckCollision(&EM->BlueEnemies[i], ToHunt))
        {
            int LastBlueEnemyIndex = EM->NumberBlueEnemy - 1;
            if (LastBlueEnemyIndex >= 0)
            {
                Enemy LastBlueEnemy = EM->BlueEnemies[LastBlueEnemyIndex];
                EM->BlueEnemies[i] = LastBlueEnemy;
                --i;
            }

            EnemyDie(&EM->BlueEnemies[i]);
            EM->NumberBlueEnemy--;
            int RandomEnemy = rand() % ENEMY_GREEN;
            EM_SpawnEnemy(EM, ENEMY_BLUE, ToHunt);
            EM_SpawnEnemy(EM, RandomEnemy, ToHunt);
            ContractPickedBlue(Contract);
        }
    }

    for(int i=0;i<EM->NumberYellowEnemy;i++)
    {
        EnemyUpdate(&EM->YellowEnemies[i], ToHunt);
        if (EnemyCheckCollision(&EM->YellowEnemies[i], ToHunt))
        {
            int LastYellowIndex = EM->NumberYellowEnemy - 1;
            if (LastYellowIndex >= 0)
            {
                Enemy LastYelloyEnemy = EM->YellowEnemies[LastYellowIndex];
                EM->YellowEnemies[i] = LastYelloyEnemy;
                --i;
            }

            EnemyDie(&EM->BlueEnemies[i]);
            EM->NumberYellowEnemy--;
            EM_SpawnEnemy(EM, ENEMY_YELLOW, ToHunt);
            ContractPickedYellow(Contract);
        }
    }

    for(int i=0;i<EM->NumberGreenEnemy;i++)
    {
        EnemyUpdate(&EM->GreenEnemies[i], ToHunt);
        if (EnemyCheckCollision(&EM->GreenEnemies[i], ToHunt))
        {
            int LastGreenIndex = EM->NumberGreenEnemy - 1;
            if (LastGreenIndex >= 0)
            {
                Enemy LastGreen = EM->GreenEnemies[LastGreenIndex];
                EM->GreenEnemies[i] = LastGreen;
                --i;
            }

            EnemyDie(&EM->BlueEnemies[i]);
            EM->NumberGreenEnemy--;
            EM_SpawnEnemy(EM, ENEMY_GREEN, ToHunt);
            ContractPickedYellow(Contract);
        }
    }
}

void EM_Draw(EnemyManager* EM, Player* MainPlayer)
{
    for(int i=0;i<EM->NumberRedEnemy;i++)
    {
        EnemyDraw(&EM->RedEnemies[i], MainPlayer);
    }
    
    for(int i=0;i<EM->NumberBlueEnemy;i++)
    {
        EnemyDraw(&EM->BlueEnemies[i], MainPlayer);
    }

    for(int i=0;i<EM->NumberYellowEnemy;i++)
    {
        EnemyDraw(&EM->YellowEnemies[i], MainPlayer);
    }

    for(int i=0;i<EM->NumberGreenEnemy;i++)
    {
        EnemyDraw(&EM->GreenEnemies[i], MainPlayer);
    }
}

void EM_ClearEnemies(EnemyManager* EM)
{

}

void EM_GenerateFarFromPlayerLocations(EnemyManager* EM, Player* ToHunt, Enemy* ToFill)
{
    VECTOR PlayerPosition = ToHunt->PlayerPosition;
    int IsPositiveX = rand() % 2;
    int IsPositiveY = rand() % 2;
    int PosX = rand() % RENDER_WIDTH;
    
    if (PosX < RENDER_WIDTH)
    {
        PosX = PosX + RENDER_WIDTH / 4;
    }

    if (IsPositiveX)
    {
        PlayerPosition.vx += PosX;
    }
    else
    {
        PlayerPosition.vx -= PosX;
    }
    int PosY = rand() % RENDER_HEIGHT;
    if (PosY < RENDER_HEIGHT)
    {
        PosY = PosY + RENDER_HEIGHT / 4;
    }
    if (IsPositiveY)
    {
        PlayerPosition.vy += PosY;
    }
    else
    {
        PlayerPosition.vy -= PosY;
    }

    ToFill->Position = PlayerPosition;
    
}