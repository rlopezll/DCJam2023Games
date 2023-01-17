#pragma once
#include "tdGameplay.h"
#include "lonchaBase.h"

#include "obstacle01.h"

#include "obstacleDepth.h"

extern unsigned long _binary_assets_textures_waterTilesetFinal_tim_start[];

tdActor levelData_LVL_Loncha_05_actors[] = {
{.position = {0,0,0}, .meshData={.mesh=&lonchaBase_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-10,0,1970}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-20,0,1210}, .meshData={.mesh=&obstacleDepth_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}}
};
SDC_OOBB levelData_LVL_Loncha_05_collisions[] = {
{.center={-10,0,2200}, .halfSize={-636,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={-20,0,-70}, .halfSize={-636,706,-1817}, .rotation={0,0,0}, .userData=0}
};
tdLoncha levelData_LVL_Loncha_05 = { .actors = levelData_LVL_Loncha_05_actors,  .numActors = sizeof(levelData_LVL_Loncha_05_actors) / sizeof(levelData_LVL_Loncha_05_actors[0]),
.collisions = levelData_LVL_Loncha_05_collisions,  .numCollisions = sizeof(levelData_LVL_Loncha_05_collisions) / sizeof(levelData_LVL_Loncha_05_collisions[0])
};