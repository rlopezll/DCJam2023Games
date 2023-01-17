#pragma once
#include "tdGameplay.h"
#include "lonchaBase.h"

#include "caixa.h"

extern unsigned long _binary_assets_textures_waterTilesetFinal_tim_start[];

extern unsigned long _binary_assets_textures_casaTexture_tim_start[];

tdActor levelData_LVL_Loncha_08_actors[] = {
{.position = {0,0,0}, .meshData={.mesh=&lonchaBase_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {2230,0,2060}, .meshData={.mesh=&caixa_Mesh, .texture_tim=_binary_assets_textures_casaTexture_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-2060,0,-1070}, .meshData={.mesh=&caixa_Mesh, .texture_tim=_binary_assets_textures_casaTexture_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}}
};
SDC_OOBB levelData_LVL_Loncha_08_collisions[] = {
{.center={2230,430,1750}, .halfSize={-1918,706,-302}, .rotation={0,0,0}, .userData=2},
{.center={-2060,430,-1380}, .halfSize={-1918,706,-302}, .rotation={0,0,0}, .userData=2}
};
tdLoncha levelData_LVL_Loncha_08 = { .actors = levelData_LVL_Loncha_08_actors,  .numActors = sizeof(levelData_LVL_Loncha_08_actors) / sizeof(levelData_LVL_Loncha_08_actors[0]),
.collisions = levelData_LVL_Loncha_08_collisions,  .numCollisions = sizeof(levelData_LVL_Loncha_08_collisions) / sizeof(levelData_LVL_Loncha_08_collisions[0])
};