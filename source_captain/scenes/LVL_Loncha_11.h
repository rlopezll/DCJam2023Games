#pragma once
#include "tdGameplay.h"
#include "lonchaBase.h"

#include "caixa.h"

#include "obstacle01.h"

#include "obstacleWide.h"

extern unsigned long _binary_assets_textures_waterTilesetFinal_tim_start[];

extern unsigned long _binary_assets_textures_casaTexture_tim_start[];

tdActor levelData_LVL_Loncha_11_actors[] = {
{.position = {0,0,0}, .meshData={.mesh=&lonchaBase_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-320,0,2210}, .meshData={.mesh=&caixa_Mesh, .texture_tim=_binary_assets_textures_casaTexture_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-2420,0,-1630}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {1000,0,-1560}, .meshData={.mesh=&obstacleWide_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}}
};
SDC_OOBB levelData_LVL_Loncha_11_collisions[] = {
{.center={-320,430,1900}, .halfSize={-1918,706,-302}, .rotation={0,0,0}, .userData=2},
{.center={-2420,0,-1400}, .halfSize={-636,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={2330,0,-1280}, .halfSize={-1918,706,-302}, .rotation={0,0,0}, .userData=0}
};
tdLoncha levelData_LVL_Loncha_11 = { .actors = levelData_LVL_Loncha_11_actors,  .numActors = sizeof(levelData_LVL_Loncha_11_actors) / sizeof(levelData_LVL_Loncha_11_actors[0]),
.collisions = levelData_LVL_Loncha_11_collisions,  .numCollisions = sizeof(levelData_LVL_Loncha_11_collisions) / sizeof(levelData_LVL_Loncha_11_collisions[0])
};