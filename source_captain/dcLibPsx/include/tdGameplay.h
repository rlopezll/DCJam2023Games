#pragma once
#include <sys/types.h>
#include <libgte.h>
#include <stdint.h>
#include <libgpu.h>
#include <dcrender.h>
#include "dcCamera.h"
#include "dcCollision.h"

struct tdActor;
struct tdMesh;
struct tdPhysicsData;
struct tdBoundingBox;
struct tdGameMode;

typedef void (*InitFunction)(struct tdGameMode* gameMode);
typedef void (*UpdateLoopFunction)(struct tdGameMode*);
typedef void (*DrawFunction)(struct tdGameMode*, SDC_Render* render);

typedef struct tdGameMode{
    SDC_Camera* camera;
    InitFunction initFunction;
    UpdateLoopFunction updateLoopFunction;
    DrawFunction drawFunction;
    char* name; 
} tdGameMode;

// Holds bounding box of the actor
typedef struct tdBoundingBox{
    SVECTOR min;
    SVECTOR max;
} tdBoundingBox;

// Physics data such as velocity, gravity or bounding box
typedef struct tdPhysicsData{
    SVECTOR velocity;
    int mass;
    tdBoundingBox boundingBox;
} tdPhysicsData;

// Actual mesh data, mesh + texture
typedef struct tdMesh{
    SDC_Mesh3D* mesh;
    u_long* texture_tim;
} tdMesh;

// Basic actor with transform, physics data and mesh data
typedef struct tdActor{
    VECTOR position;
    SVECTOR rotation;
    VECTOR scale;
    tdPhysicsData physicsData;
    tdMesh meshData;
} tdActor;

typedef struct tdLoncha{
    tdActor* actors;
    int numActors;
    SDC_OOBB* collisions;
    int numCollisions;
} tdLoncha;

typedef struct tdTIMDataHandler{
    u_long* tim_identifier;
    TIM_IMAGE timImage;
    SDC_Texture textureData;
}tdTIMDataHandler;

extern tdGameMode* nextGameMode;
extern tdTIMDataHandler timData[10];
SDC_Texture* GetTextureDataAndLoadIfNeeded(u_long* tim_identifier);

// Draws and actor using a camera
void DrawActor(tdActor* actor, SDC_Render* render,  SDC_Camera* camera);
// Draws bounding box of an actor given a camera
void DrawActorBoundingBox(tdActor* actor, SDC_Render* render,  SDC_Camera* camera);
// Calculates the actor bounding box automatically
// Warning, if mesh data is null this will crash
void InitializeActorBoundingBoxBasedOnMesh(tdActor* actor);
// Computs the actor transform taking into account position/rotation/scale
void GetActorTransform(tdActor* actor, MATRIX* outTransform);
void DrawLoncha(tdLoncha* loncha, VECTOR offset, SDC_Render* render, SDC_Camera* camera);
void DrawLonchaCollisions(tdLoncha* loncha, VECTOR offset, SDC_Render* render, SDC_Camera* camera);
// Draws an array of actors
void DrawActorArray(tdActor actorArray[], int numActors, SDC_Render* render, SDC_Camera* camera, int bDrawBoundingBox);
void DrawOOBBDebug(SDC_OOBB* oobb, SDC_Render* render,  SDC_Camera* camera);
void DrawOOBBDebugOffset(SDC_OOBB* oobb, VECTOR offset, SDC_Render* render,  SDC_Camera* camera);
void GetActorTransformOffset(tdActor* actor, VECTOR offset, MATRIX* outTransform);
void DrawActorOffset(tdActor* actor, VECTOR offset, SDC_Render* render, SDC_Camera* camera);
void DrawActorArrayOffset(tdActor actorArray[], int numActors, VECTOR offset, SDC_Render* render, SDC_Camera* camera, int bDrawBoundingBox);
void DrawActorBoundingBoxOffset(tdActor* actor, VECTOR offset, SDC_Render* render,  SDC_Camera* camera);

int RandomBetween(int min, int max);