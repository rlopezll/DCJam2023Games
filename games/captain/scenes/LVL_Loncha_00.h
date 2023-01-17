#pragma once
#include "tdGameplay.h"
#include "lonchaBase.h"

extern unsigned long _binary_assets_textures_waterTilesetFinal_tim_start[];

tdActor levelData_LVL_Loncha_00_actors[] = {
{.position = {0,0,0}, .meshData={.mesh=&lonchaBase_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}}
};
SDC_OOBB levelData_LVL_Loncha_00_collisions[] = {

};
tdLoncha levelData_LVL_Loncha_00 = { .actors = levelData_LVL_Loncha_00_actors,  .numActors = sizeof(levelData_LVL_Loncha_00_actors) / sizeof(levelData_LVL_Loncha_00_actors[0]),
.collisions = levelData_LVL_Loncha_00_collisions,  .numCollisions = 0
};