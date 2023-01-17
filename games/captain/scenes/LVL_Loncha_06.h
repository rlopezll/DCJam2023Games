#pragma once
#include "tdGameplay.h"
#include "lonchaBase.h"

#include "obstacle01.h"

#include "obstacleDepth.h"

extern unsigned long _binary_assets_textures_waterTilesetFinal_tim_start[];

tdActor levelData_LVL_Loncha_06_actors[] = {
{.position = {0,0,0}, .meshData={.mesh=&lonchaBase_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-1700,0,2670}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-10,0,1910}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-40,0,830}, .meshData={.mesh=&obstacleDepth_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-1690,0,1740}, .meshData={.mesh=&obstacleDepth_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}}
};
SDC_OOBB levelData_LVL_Loncha_06_collisions[] = {
{.center={-1700,0,2900}, .halfSize={-636,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={-10,0,2140}, .halfSize={-636,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={-40,0,-450}, .halfSize={-636,706,-1817}, .rotation={0,0,0}, .userData=0},
{.center={-1690,0,460}, .halfSize={-636,706,-1817}, .rotation={0,0,0}, .userData=0}
};
tdLoncha levelData_LVL_Loncha_06 = { .actors = levelData_LVL_Loncha_06_actors,  .numActors = sizeof(levelData_LVL_Loncha_06_actors) / sizeof(levelData_LVL_Loncha_06_actors[0]),
.collisions = levelData_LVL_Loncha_06_collisions,  .numCollisions = sizeof(levelData_LVL_Loncha_06_collisions) / sizeof(levelData_LVL_Loncha_06_collisions[0])
};