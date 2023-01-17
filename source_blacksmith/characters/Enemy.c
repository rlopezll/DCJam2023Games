#include "Enemy.h"
#include "../Resources.h"
#include "../engine.h"
#include <assert.h>

char PositionIsInRadius(VECTOR FirstPosition, VECTOR SecondPosition, long Radius);
char CharactersCollide(VECTOR PlayerPosition, VECTOR OtherPosition, long OtherRadius);
long GetDistanceBetweenTwoPoints(VECTOR FirstPosition, VECTOR SecondPosition);

void EnemyInit(Enemy* Self)
{
    Self->Radius = 32;
    Self->FrameSkip = 0;
    switch (Self->Type)
    {
        case ENEMY_RED:
        {
            dcSprite_SetAnimation(&Self->CurrentSprite, &EnemyRedAnimations);
        }
        break;
        case ENEMY_BLUE:
        {
            dcSprite_SetAnimation(&Self->CurrentSprite, &EnemyBlueAnimations);
        }
        break;
        case ENEMY_YELLOW:
        {
            dcSprite_SetAnimation(&Self->CurrentSprite, &EnemyYellowAnimations);
        }
        break;
        case ENEMY_GREEN:
        {
            dcSprite_SetAnimation(&Self->CurrentSprite, &EnemyGreenAnimations);
        }
        break;
        case TOTAL_ENEMIES:
        {
            break;
        }
    }
}


void EnemyUpdate(Enemy* Self, Player* ToHunt)
{
    if (Self->FrameSkip == 0)
    {
        // Move to player
        Self->FrameSkip = 2;
        int MovementXDirection = 0;
        int MovementYDirection = 0;

        const int CheckUpSide = rand() % 10;
        if(CheckUpSide > 5)
        {
            if (Self->Position.vy < ToHunt->PlayerPosition.vy)
            {
                MovementYDirection = Self->Velocity;
            }
            else if (Self->Position.vy > ToHunt->PlayerPosition.vy)
            {
                MovementYDirection = -Self->Velocity;
            }    
        }
        else{
            
            if (Self->Position.vx < ToHunt->PlayerPosition.vx)
            {
                MovementXDirection = Self->Velocity;
            }
            else if (Self->Position.vx > ToHunt->PlayerPosition.vx)
            {
                MovementXDirection = -Self->Velocity;
            }
        }
        
        /*
        VECTOR ExpectedPos = {Self->PlayerPosition.vx + MovemementSide, Self->PlayerPosition.vy + MovementFront, 0, 0};
        if (Scene_IsInsidedBounds(&ExpectedPos))
        {
            Self->Position.vx += MovementXDirection;
            Self->Position.vy += MovementYDirection;
        }
        */

        Self->Position.vx += MovementXDirection;
        Self->Position.vy += MovementYDirection;
    }
    else
    {
        --Self->FrameSkip;
    }
}

char EnemyCheckCollision(Enemy* Self, Player* ToHunt)
{
    char Collide = CharactersCollide(ToHunt->PlayerPosition, Self->Position, Self->Radius);
    if(Collide)
    {
        PlayerAttack(ToHunt);
    }

    return Collide;
}

void EnemyDraw(Enemy* Self, Player* MainPlayer)
{
    CVECTOR ColorSprit = {128, 128, 128, 128};

    if(Self->AudioFrameSkip > 0)
    {
        Self->AudioFrameSkip--;
        if(Self->AudioFrameSkip == 0)
        {
            dcAudio_SfxPlay(&MonsterAudio);
        }
    }
    
    dcSprite_Update(&Self->CurrentSprite);

    int TopLeftX = Self->Position.vx - MainPlayer->CameraPosition.vx;
    int TopLefty = Self->Position.vy - MainPlayer->CameraPosition.vy;
    dcSprite_Render(GEngineInstance.RenderPtr, &Self->CurrentSprite, TopLeftX, TopLefty, &ColorSprit);
}

void EnemyDie(Enemy* Self)
{
    // Quitar el enemigo de la lista en el enemy manager.
    Self->AudioFrameSkip = 4;
}

/**
 *     long DistX = PlayerPosition.vx - OtherPosition.vx;
    long DistY = PlayerPosition.vy - OtherPosition.vy;
    return DistX < OtherRadius || DistY < OtherRadius;
 * 
*/

char PositionIsInRadius(VECTOR FirstPosition, VECTOR SecondPosition, long Radius)
{
    // Calculate the distance^2 between FirstPosition and SecondPosition
    long Distance = GetDistanceBetweenTwoPoints(FirstPosition, SecondPosition);
    long FinalRadius = DC_MUL(Radius, Radius);
    // Position is in radius if Distance^2 < Radius^2
    return (Distance < FinalRadius);
}

char CharactersCollide(VECTOR PlayerPosition, VECTOR OtherPosition, long OtherRadius)
{
    VECTOR PlayerCenter;
    PlayerCenter.vx = PlayerPosition.vx + 8; 
    PlayerCenter.vy = PlayerPosition.vy + 18; 
    long DistX = abs(PlayerCenter.vx - OtherPosition.vx);
    long DistY = abs(PlayerCenter.vy - OtherPosition.vy);
    
    long Distance = SquareRoot0(DistX * DistX + DistY * DistY);
    return Distance < OtherRadius;
}

long GetDistanceBetweenTwoPoints(VECTOR FirstPosition, VECTOR SecondPosition)
{
    long XDistance = (FirstPosition.vx - SecondPosition.vx);
    long YDistance = (FirstPosition.vy - SecondPosition.vy);

    long Distance = DC_MUL(XDistance, XDistance) + DC_MUL(YDistance, YDistance);
    return Distance;
}