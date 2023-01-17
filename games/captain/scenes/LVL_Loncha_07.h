#pragma once
#include "tdGameplay.h"
#include "casa.h"

#include "lonchaBase.h"

extern unsigned long _binary_assets_textures_casaTexture_tim_start[];

extern unsigned long _binary_assets_textures_waterTilesetFinal_tim_start[];

tdActor levelData_LVL_Loncha_07_actors[] = {
{.position = {-1110,0,1360}, .meshData={.mesh=&casa_Mesh, .texture_tim=_binary_assets_textures_casaTexture_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {1620,0,-1480}, .meshData={.mesh=&casa_Mesh, .texture_tim=_binary_assets_textures_casaTexture_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {0,0,0}, .meshData={.mesh=&lonchaBase_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}}
};
SDC_OOBB levelData_LVL_Loncha_07_collisions[] = {
{.center={-1110,430,1100}, .halfSize={-807,706,-605}, .rotation={0,0,0}, .userData=2},
{.center={1620,430,-1740}, .halfSize={-807,706,-605}, .rotation={0,0,0}, .userData=2}
};
tdLoncha levelData_LVL_Loncha_07 = { .actors = levelData_LVL_Loncha_07_actors,  .numActors = sizeof(levelData_LVL_Loncha_07_actors) / sizeof(levelData_LVL_Loncha_07_actors[0]),
.collisions = levelData_LVL_Loncha_07_collisions,  .numCollisions = sizeof(levelData_LVL_Loncha_07_collisions) / sizeof(levelData_LVL_Loncha_07_collisions[0])
};