#pragma once
#include "tdGameplay.h"
#include "casa.h"

#include "novarama.h"

#include "lonchaBase.h"

extern unsigned long _binary_assets_textures_casaTexture_tim_start[];

extern unsigned long _binary_assets_textures_novarama1_tim_start[];

extern unsigned long _binary_assets_textures_waterTilesetFinal_tim_start[];

tdActor levelData_LVL_Loncha_casaRuben_actors[] = {
{.position = {210,0,-100}, .meshData={.mesh=&casa_Mesh, .texture_tim=_binary_assets_textures_casaTexture_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {210,570,360}, .meshData={.mesh=&novarama_Mesh, .texture_tim=_binary_assets_textures_novarama1_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {0,0,0}, .meshData={.mesh=&lonchaBase_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}}
};
SDC_OOBB levelData_LVL_Loncha_casaRuben_collisions[] = {
{.center={210,430,-360}, .halfSize={-807,706,-605}, .rotation={0,0,0}, .userData=2}
};
tdLoncha levelData_LVL_Loncha_casaRuben = { .actors = levelData_LVL_Loncha_casaRuben_actors,  .numActors = sizeof(levelData_LVL_Loncha_casaRuben_actors) / sizeof(levelData_LVL_Loncha_casaRuben_actors[0]),
.collisions = levelData_LVL_Loncha_casaRuben_collisions,  .numCollisions = sizeof(levelData_LVL_Loncha_casaRuben_collisions) / sizeof(levelData_LVL_Loncha_casaRuben_collisions[0])
};