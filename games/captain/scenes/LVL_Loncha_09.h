#pragma once
#include "tdGameplay.h"
#include "casa.h"

#include "lonchaBase.h"

extern unsigned long _binary_assets_textures_casaTexture_tim_start[];

extern unsigned long _binary_assets_textures_waterTilesetFinal_tim_start[];

tdActor levelData_LVL_Loncha_09_actors[] = {
{.position = {60,0,-2260}, .meshData={.mesh=&casa_Mesh, .texture_tim=_binary_assets_textures_casaTexture_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-1660,0,1360}, .meshData={.mesh=&casa_Mesh, .texture_tim=_binary_assets_textures_casaTexture_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {2090,0,1200}, .meshData={.mesh=&casa_Mesh, .texture_tim=_binary_assets_textures_casaTexture_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {0,0,0}, .meshData={.mesh=&lonchaBase_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}}
};
SDC_OOBB levelData_LVL_Loncha_09_collisions[] = {
{.center={-1660,430,1100}, .halfSize={-807,706,-605}, .rotation={0,0,0}, .userData=2},
{.center={2090,430,940}, .halfSize={-807,706,-605}, .rotation={0,0,0}, .userData=2},
{.center={60,430,-2520}, .halfSize={-807,706,-605}, .rotation={0,0,0}, .userData=2}
};
tdLoncha levelData_LVL_Loncha_09 = { .actors = levelData_LVL_Loncha_09_actors,  .numActors = sizeof(levelData_LVL_Loncha_09_actors) / sizeof(levelData_LVL_Loncha_09_actors[0]),
.collisions = levelData_LVL_Loncha_09_collisions,  .numCollisions = sizeof(levelData_LVL_Loncha_09_collisions) / sizeof(levelData_LVL_Loncha_09_collisions[0])
};