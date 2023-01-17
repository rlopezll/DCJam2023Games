#ifndef _DC_LEVEL_
#define _DC_LEVEL_
#include "dcRender.h"
#include <stdlib.h>
#include <libgte.h>
#include <libgpu.h>
#include <libgs.h>
#include "dcAudio.h"

typedef struct SDC_Object SDC_Object;
typedef struct SDC_Character SDC_Character;

typedef struct SDC_Object
{
    VECTOR Location;
    VECTOR Scale;
    SVECTOR Rotation;
    SDC_Mesh3D* Mesh;
    SDC_DrawParams* DrawParams;
    SDC_Object* Parent;
    SDC_Character* CharacterParent;
    int bHasCollision;
    VECTOR BoxHalfSize;
    MATRIX WorldTransform;
}SDC_Object;

typedef struct SDC_Projectile
{
    int Dmg;
    int Vox;
    int Vy;
    int Voy;
    int ExplosionRange;
    VECTOR Location;
    SVECTOR Rotation;
    SDC_Mesh3D* Mesh;
    SVECTOR Direction;
    SDC_DrawParams* DrawParams;
    SDC_Character* Character;
}SDC_Projectile;

typedef struct SDC_Explotion
{
    int ExpansionSpeed;
    int InitRadius;
    int CurrentRadius;
    int MaxRadius;
    int bHasCollision;
    SDC_Mesh3D* Mesh;
    VECTOR Location;
    SVECTOR Rotation;
    VECTOR Scale;
    SDC_DrawParams* DrawParams;

}SDC_Explotion;

typedef struct  SDC_Character
{
    int Lives;
    int InitLives;
    int PlayerIndex;
    VECTOR Location;
    SVECTOR Rotation;
    SDC_Mesh3D* Mesh;
    SVECTOR Direction;
    SDC_DrawParams* DrawParams;
    SVECTOR FrontVector;
    short CameraAngle;
    SDC_Object* Pala;
    TIM_IMAGE* tim_projectile;

    MATRIX WorldTransform;
    //Abilities
    //Dash
    int bDoingDash;
    int DashRemaining;
    int DashDistance;
    int DashVelocity;

    int DashCooldown;
    int DashCurrentCooldown;

    //Fire
    int bHoldingFire;
    int ProjectileSpeed;
    int ProjectileStrength;
    
    int FireCooldown;
    int FireCurrentCooldown;

    //Parry
    int bDoingParry;    
    int bCanParry;
    int ParryFrames;
    int ParryCurrentFrame;
    int ParryCooldown;
    int ParryCurrentCooldown;

}SDC_Character;

typedef struct SDC_Level
{
    SDC_Sfx HitSfx;
    SDC_Sfx FireSfx;
    SDC_Sfx MissSfx;
    int bGameOver;
    SDC_Object** Objects;
    SDC_Character** Characters;
    SDC_Projectile** Projectiles;
    SDC_Explotion** Explotions;
    int NumCharacters;
    int NumProjectiles;
    int NumExplotions;
    int NumObjects;
    int MaxObjects;
    SDC_Mesh3D* ExplosionMesh;
    TIM_IMAGE* White;
    SDC_Audio Audio;

// Back color  
CVECTOR  AmbientColor;
// Light rotation angle - used to calculate the world direction of the light in each object
SVECTOR LightAngle; 
// These will be used to store the light rotation matrix, cube rotation matrix, and composite light matrix.
MATRIX  RotLight, RotObject, WorldLightMatrix;
  
 // Local Light Matrix : Direction and reach of each light source. 
// Each light points in the direction aligned with the axis, hence direction is in the same coordinate system as the PSX (see l.23-30 of this file)
// Negative/positive value denotes light direction on corresponding axis
// -4096 > Value < 4096 denotes reach/intensity of light source
MATRIX LocalLightMatrix;
// Local Color Matrix
// Set color of each light source (L)
// Value range : 0 > x < 4096
MATRIX ColorMatrix;    
}SDC_Level;


void dcLevel_InitLight(SDC_Level* Level, CVECTOR* AmbientColor);
void dcLevel_SetLight(SDC_Level* Level, int LightIndex, SVECTOR* LightDirection, SVECTOR* LightColor);
SDC_Object* dcLevel_AddObject(SDC_Level* Level, SDC_Mesh3D* Mesh, VECTOR* Location, SVECTOR* Rotation, VECTOR* Scale, SDC_DrawParams* DrawParams, SDC_Object* Parent, int bHasCollision, VECTOR* BoxHalfCollision);
SDC_Object* dcLevel_AddObjectOnCharacter(SDC_Level* Level, SDC_Mesh3D* Mesh, VECTOR* Location, SVECTOR* Rotation, SDC_DrawParams* DrawParams, SDC_Character* Parent, int bHasCollision, VECTOR* BoxHalfCollision);

void dcLevel_AddExplotion(SDC_Level *Level, SDC_Mesh3D* Mesh, VECTOR Location, SDC_DrawParams* DrawParams);
void dcLevel_AddProjectile(SDC_Level* Level, SDC_Mesh3D* Mesh, VECTOR* Location, SVECTOR* Direction, int Strength,  SDC_DrawParams* DrawParams, SDC_Character* Character);
void dcLevel_DestroyProjectile(SDC_Level* Level, int i);

SDC_Character* dcLevel_InitCharacter(SDC_Level* Level, SDC_Mesh3D* Mesh, VECTOR* Location, SDC_DrawParams* DrawParams);
void GetParentTransform(SDC_Object* Object, MATRIX* Transform, MATRIX* OutTransform);
void dcLevel_DestroyExplotion(SDC_Level* Level, int i);

#endif /* _DC_LEVEL_H */
