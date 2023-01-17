#pragma once
#include "tdGameplay.h"
#include "lonchaBase.h"

#include "caixa.h"

extern unsigned long _binary_assets_textures_waterTilesetFinal_tim_start[];

extern unsigned long _binary_assets_textures_casaTexture_tim_start[];

tdActor levelData_LVL_Loncha_10_actors[] = {
{.position = {0,0,0}, .meshData={.mesh=&lonchaBase_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {120,0,710}, .meshData={.mesh=&caixa_Mesh, .texture_tim=_binary_assets_textures_casaTexture_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}}
};
SDC_OOBB levelData_LVL_Loncha_10_collisions[] = {
{.center={120,430,400}, .halfSize={-1918,706,-302}, .rotation={0,0,0}, .userData=2}
};
tdLoncha levelData_LVL_Loncha_10 = { .actors = levelData_LVL_Loncha_10_actors,  .numActors = sizeof(levelData_LVL_Loncha_10_actors) / sizeof(levelData_LVL_Loncha_10_actors[0]),
.collisions = levelData_LVL_Loncha_10_collisions,  .numCollisions = sizeof(levelData_LVL_Loncha_10_collisions) / sizeof(levelData_LVL_Loncha_10_collisions[0])
};