#pragma once
#include "tdGameplay.h"
#include "casa.h"

#include "lonchaBase.h"

extern unsigned long _binary_assets_textures_casaTexture_tim_start[];

extern unsigned long _binary_assets_textures_waterTilesetFinal_tim_start[];

tdActor levelData_LVL_Loncha_12_actors[] = {
{.position = {2770,0,1400}, .meshData={.mesh=&casa_Mesh, .texture_tim=_binary_assets_textures_casaTexture_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {1210,0,1400}, .meshData={.mesh=&casa_Mesh, .texture_tim=_binary_assets_textures_casaTexture_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-650,0,-1380}, .meshData={.mesh=&casa_Mesh, .texture_tim=_binary_assets_textures_casaTexture_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {0,0,0}, .meshData={.mesh=&lonchaBase_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}}
};
SDC_OOBB levelData_LVL_Loncha_12_collisions[] = {
{.center={2770,430,1140}, .halfSize={-807,706,-605}, .rotation={0,0,0}, .userData=2},
{.center={1210,430,1140}, .halfSize={-807,706,-605}, .rotation={0,0,0}, .userData=2},
{.center={-650,430,-1640}, .halfSize={-807,706,-605}, .rotation={0,0,0}, .userData=2}
};
tdLoncha levelData_LVL_Loncha_12 = { .actors = levelData_LVL_Loncha_12_actors,  .numActors = sizeof(levelData_LVL_Loncha_12_actors) / sizeof(levelData_LVL_Loncha_12_actors[0]),
.collisions = levelData_LVL_Loncha_12_collisions,  .numCollisions = sizeof(levelData_LVL_Loncha_12_collisions) / sizeof(levelData_LVL_Loncha_12_collisions[0])
};