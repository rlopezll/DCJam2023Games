#include "character.h"
#include "dcCollision.h"
#include <stdio.h>
#include "dcRender.h"
#include "dcMath.h"
#include "dcAudio.h"
#include "meshes/Proyectil.h"
#include "dcAudio.h"

extern unsigned long _binary_data_Hit_vag_start[];
SDC_Sfx HitSfx;

void UpdateCharacter(SDC_Character* Character, SDC_Level* Level)
{
    int PlayerIndex = Character->PlayerIndex;
    u_long PadState = PadRead(0);
    int Speed = 100;
    if(Level->bGameOver == 1){
        return;
    }
    SVECTOR IncrementalPosition = {0,0,0};
    if( _PAD(PlayerIndex,PADLup ) & PadState )
    {
        IncrementalPosition.vz += (-Character->FrontVector.vz/ Speed);        
        IncrementalPosition.vx += (-Character->FrontVector.vx / Speed);
    }
    if( _PAD(PlayerIndex,PADLdown ) & PadState )
    {
        IncrementalPosition.vz += (Character->FrontVector.vz / Speed);        
        IncrementalPosition.vx += (Character->FrontVector.vx / Speed);
    }
    if( _PAD(PlayerIndex,PADLright ) & PadState )
    {        
        IncrementalPosition.vx += (Character->FrontVector.vz/ Speed);        
        IncrementalPosition.vz += (-Character->FrontVector.vx / Speed);
    }
    if( _PAD(PlayerIndex,PADLleft ) & PadState )
    {
        IncrementalPosition.vx += (-Character->FrontVector.vz/ Speed);        
        IncrementalPosition.vz += (Character->FrontVector.vx / Speed);
    }
    if( _PAD(PlayerIndex,PADR1 ) & PadState )
    {
        Character->CameraAngle += 50;
    }
    if( _PAD(PlayerIndex,PADL1 ) & PadState )
    {
        Character->CameraAngle -= 50;
    }
    if( _PAD(PlayerIndex,PADRleft ) & PadState )
    {
        //Dash
        if(!Character->bDoingDash  && Character->DashCurrentCooldown <= 0)
        {
        Character->bDoingDash = 1;
        Character->DashRemaining = 700;//Character->DashDistance;        
           Character->DashCurrentCooldown = Character->DashCooldown;
        }

    }
    if( _PAD(PlayerIndex,PADRright ) & PadState )
    {
        if(!Character->bDoingParry && Character->ParryCurrentCooldown <= 0)
        {
            //Sound
            dcAudio_SfxPlay(&Level->MissSfx);

            Character->bDoingParry = 1;
            Character->ParryCurrentFrame = 0;
           Character->ParryCurrentCooldown = Character->ParryCooldown;
           Character->Pala->Scale = (VECTOR){ONE,ONE,ONE};
        }

    }
    if( _PAD(PlayerIndex,PADRdown ) & PadState )
    {
        if(Character->FireCurrentCooldown <= 0)
        {
            Character->bHoldingFire = 1;
            Character->ProjectileStrength += 2;
        }
    }
    else
    {
        if(Character->bHoldingFire)
        {
            //FIRE
            SDC_DrawParams DrawParams = {
                .tim = Character->tim_projectile,
                .constantColor = {255, 255, 255},
                .bLighting = 1,
                .bUseConstantColor = 1
            };

            SDC_DrawParams* DrawParamsPtr = (SDC_DrawParams*)malloc3(sizeof(SDC_DrawParams));
            *DrawParamsPtr = DrawParams;

            dcLevel_AddProjectile(Level, &Proyectil_Mesh, &Character->Location, &Character->FrontVector, Character->ProjectileStrength, DrawParamsPtr, Character); 
            Character->bHoldingFire = 0;
            Character->ProjectileStrength = 0;
            Character->FireCurrentCooldown = Character->FireCooldown;
        }

            Character->FireCurrentCooldown--;
    }

    //Calculate character collision to check if it can move
     VECTOR FutureLocation = {Character->Location.vx, Character->Location.vy, Character->Location.vz};
     if(Character->bDoingParry)
     { 
        Character->ParryCurrentFrame++;
        Character->Rotation.vy -= ONE / Character->ParryFrames;
        if(Character->ParryCurrentFrame > Character->ParryFrames)
        {
            Character->bDoingParry = 0;      
            Character->bCanParry = 1;      
           Character->Pala->Scale = (VECTOR){0,0,0};
        }
        if(Character->bCanParry)
        {
        for(int i = 0; i < Level->NumProjectiles; i++)
        {
            VECTOR ProjectileLocation = Level->Projectiles[i]->Location;
            VECTOR CharacterLocation = Character->Location;
            VECTOR Diff = {ProjectileLocation.vx - CharacterLocation.vx,ProjectileLocation.vy - CharacterLocation.vy,ProjectileLocation.vz - CharacterLocation.vz};
            int Dist =  SquareRoot12( DC_MUL(Diff.vx , Diff.vx) + DC_MUL(Diff.vy , Diff.vy) + DC_MUL(Diff.vz , Diff.vz));
 
            if(Dist  < 200)
            {
                SVECTOR Dir = Level->Projectiles[i]->Direction;
                Level->Projectiles[i]->Direction = (SVECTOR){-Dir.vx, -Dir.vy, -Dir.vz};
                Level->Projectiles[i]->Vox *= 3;
                Level->Projectiles[i]->Vy = 0;
                Level->Projectiles[i]->Character = Character;          
                Character->bCanParry = 0;
            }
        }
        }
     }
     else{
        
        Character->ParryCurrentCooldown--;
     }
    if(Character->bDoingDash)
    {
        FutureLocation.vx = Character->Location.vx + ((Character->Direction.vx * 200) >> 12);    
        FutureLocation.vz = Character->Location.vz + ((Character->Direction.vz * 200) >> 12);
        Character->DashRemaining -= 100;
        if(Character->DashRemaining <= 0)
        {
            Character->Rotation.vx = 0;            
            Character->Rotation.vz = 0;
            
            Character->bDoingDash = 0;
        }
    }
    else
    {
        Character->DashCurrentCooldown--;
        if(IncrementalPosition.vx != 0 || IncrementalPosition.vz != 0)
        {
    
            if(!Character->bDoingParry)
            {
                SVECTOR Dir;    
                VectorNormalSS(&IncrementalPosition, &Dir);
                SVECTOR Diff = {Dir.vx -  Character->Direction.vx,Dir.vy -  Character->Direction.vy,Dir.vz -  Character->Direction.vz};
                int LerpSpeed = 2;
                SVECTOR DIffDivided = {Diff.vx / LerpSpeed, Diff.vy / LerpSpeed, Diff.vz / LerpSpeed};
                SVECTOR Summ = {Character->Direction.vx + DIffDivided.vx, Character->Direction.vy + DIffDivided.vy, Character->Direction.vz + DIffDivided.vz};
                Character->Direction =  Summ;

                long atan2 = ratan2(Character->Direction.vx, Character->Direction.vz);
                Character->Rotation.vy = atan2;
            }
        FutureLocation.vx = Character->Location.vx + IncrementalPosition.vx;    
        FutureLocation.vz =  Character->Location.vz + IncrementalPosition.vz;
        }
    }
    int bCanMove = 1;
    VECTOR CharacterLocation = Character->Location;
    for(int i = 0; i < Level->NumObjects; i++)
    {
        if( !Level->Objects[i]->bHasCollision)
        continue;
        VECTOR ObjectLocation = Level->Objects[i]->Location;
       VECTOR Dist = {ObjectLocation.vx - CharacterLocation.vx,ObjectLocation.vy - CharacterLocation.vy,ObjectLocation.vz - CharacterLocation.vz};
        if(Dist.vx > 200 || Dist.vz > 200)
        continue;
        if(dcCollision_SphereOverlapBox(&FutureLocation, 50, &Level->Objects[i]->Location, &Level->Objects[i]->BoxHalfSize))
        {
            bCanMove = 0;
            break;
        }

    }

    //Collision with map limits
    if(FutureLocation.vx > 3500 || FutureLocation.vx < -3500)
    {
        bCanMove = 0;
    }
    if(FutureLocation.vz > 3500 || FutureLocation.vz < -3500)
    {
        bCanMove = 0;
    }
    if(bCanMove)
    {
        Character->Location = FutureLocation;
    }
    short S = csin(Character->CameraAngle);
    short C = ccos(Character->CameraAngle);
    Character->FrontVector.vx = C;
    Character->FrontVector.vz = S;
}
