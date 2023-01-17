#pragma once
#include "tdGameplay.h"
#include "lonchaBase.h"

#include "obstacleWide.h"

extern unsigned long _binary_assets_textures_waterTilesetFinal_tim_start[];

tdActor levelData_LVL_Loncha_02_actors[] = {
{.position = {0,0,0}, .meshData={.mesh=&lonchaBase_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-20,-20,-2150}, .meshData={.mesh=&obstacleWide_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {1340,-20,1860}, .meshData={.mesh=&obstacleWide_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-3930,-20,1980}, .meshData={.mesh=&obstacleWide_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}}
};
SDC_OOBB levelData_LVL_Loncha_02_collisions[] = {
{.center={1310,-20,-1870}, .halfSize={-1918,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={2670,-20,2140}, .halfSize={-1918,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={-2600,-20,2260}, .halfSize={-1918,706,-302}, .rotation={0,0,0}, .userData=0}
};
tdLoncha levelData_LVL_Loncha_02 = { .actors = levelData_LVL_Loncha_02_actors,  .numActors = sizeof(levelData_LVL_Loncha_02_actors) / sizeof(levelData_LVL_Loncha_02_actors[0]),
.collisions = levelData_LVL_Loncha_02_collisions,  .numCollisions = sizeof(levelData_LVL_Loncha_02_collisions) / sizeof(levelData_LVL_Loncha_02_collisions[0])
};