#ifndef _DC_SCENEMAP_
#define _DC_SCENEMAP_

#include "dcMath.h"
#include "dcRender.h"
#include "dcSprite.h"

#define SceneTileWidth 20
#define SceneTileHeight 20
#define SceneTileDim 32

typedef struct
{
    VECTOR Coordinates;
    VECTOR TopLeft;
    RealTIMImage RealImage;
} Tile;

typedef struct
{
    Tile MapTiles[SceneTileWidth][SceneTileHeight];
    int TotalCells;
} SceneMap;

/* Scena Map Methods  */

void SceneMap_Init(SceneMap * MapPtr);
void SceneMap_Draw(SceneMap * MapPtr, VECTOR * CameraPosition);
VECTOR GetRandomLocation(SceneMap * MapPtr);
VECTOR Scene_GetMapCenter();
char Scene_IsInsidedBounds(VECTOR * PointToCheck);
int GetGridSize(SceneMap * MapPtr);

#endif