#include "projectile.h"
#include "dcMath.h"
#include "dcLevel.h"
#include "dcCollision.h"


void UpdateProjectile(SDC_Level* Level, SDC_Projectile* Projectile, int IndexInArray)
{
     int bProjectileDead = 0;
     Projectile->Location.vx -= DC_MUL(Projectile->Vox , Projectile->Direction.vx);     
     Projectile->Location.vz -= DC_MUL(Projectile->Vox , Projectile->Direction.vz);
     Projectile->Vy = Projectile->Vy - 1;
     Projectile->Location.vy = Projectile->Location.vy + Projectile->Vy;
   
     VECTOR FutureLocation = {Projectile->Location.vx, Projectile->Location.vy, Projectile->Location.vz};

     int bCanMove = 1;
     VECTOR ProjectileLocation = Projectile->Location;
     for(int i = 0; i < Level->NumObjects; i++)
     {
          VECTOR ObjectLocation = Level->Objects[i]->Location;
          VECTOR Dist = {ObjectLocation.vx - ProjectileLocation.vx,ObjectLocation.vy - ProjectileLocation.vy,ObjectLocation.vz - ProjectileLocation.vz};
     if(Dist.vx > 200 || Dist.vz > 200)
     continue;
          if(dcCollision_SphereOverlapBox(&Projectile->Location, 50, &Level->Objects[i]->Location, &Level->Objects[i]->BoxHalfSize))
          {
               bCanMove = 0;
               break;
          }
     }
     if(bCanMove)
     {
          Projectile->Location = FutureLocation;
     }
     else{
        dcLevel_DestroyProjectile(Level, IndexInArray);  
        bProjectileDead = 1;
     }

     //Check dmg character
     for(int i = 0; i < Level->NumCharacters; i++)
     {
          //if(dcCollision_SphereOverlapBox(Projectile->Location,Projectile->ExplosionRange,Level->Characters[i]->Location,Level->Characters[i]->))
          SVECTOR Diff = {Projectile->Location.vx -  Level->Characters[i]->Location.vx,0, Projectile->Location.vz - Level->Characters[i]->Location.vz};
          int Dist =  SquareRoot12( DC_MUL(Diff.vx , Diff.vx) + DC_MUL(Diff.vz , Diff.vz));

          if((Dist < 100) && (Projectile->Character->PlayerIndex != i) && (!Level->bGameOver)){

               if(!bProjectileDead)
               {
                    dcLevel_DestroyProjectile(Level, IndexInArray);
                    bProjectileDead = 1;
               }
          }
     }

    if( (Projectile->Location.vy < 0) && (!bProjectileDead))
     {
        
          dcLevel_DestroyProjectile(Level, IndexInArray);
     }
      
}