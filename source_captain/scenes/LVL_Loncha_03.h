#pragma once
#include "tdGameplay.h"
#include "lonchaBase.h"

#include "obstacleWide.h"

extern unsigned long _binary_assets_textures_waterTilesetFinal_tim_start[];

tdActor levelData_LVL_Loncha_03_actors[] = {
{.position = {0,0,0}, .meshData={.mesh=&lonchaBase_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {340,-20,-2000}, .meshData={.mesh=&obstacleWide_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-3140,-20,1840}, .meshData={.mesh=&obstacleWide_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}}
};
SDC_OOBB levelData_LVL_Loncha_03_collisions[] = {
{.center={1670,-20,-1720}, .halfSize={-1918,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={-1810,-20,2120}, .halfSize={-1918,706,-302}, .rotation={0,0,0}, .userData=0}
};
tdLoncha levelData_LVL_Loncha_03 = { .actors = levelData_LVL_Loncha_03_actors,  .numActors = sizeof(levelData_LVL_Loncha_03_actors) / sizeof(levelData_LVL_Loncha_03_actors[0]),
.collisions = levelData_LVL_Loncha_03_collisions,  .numCollisions = sizeof(levelData_LVL_Loncha_03_collisions) / sizeof(levelData_LVL_Loncha_03_collisions[0])
};