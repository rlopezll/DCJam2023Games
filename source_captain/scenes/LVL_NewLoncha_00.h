#pragma once
#include "tdGameplay.h"
#include "td_TILE_plain.h"

extern unsigned long _binary_assets_textures_texturaEpica_tim_start[];

tdActor levelData_LVL_NewLoncha_00_actors[] = {
{.position = {0,0,0}, .meshData={.mesh=&td_TILE_plain_Mesh, .texture_tim=_binary_assets_textures_texturaEpica_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}}
};
SDC_OOBB levelData_LVL_NewLoncha_00_collisions[] = {
{.center={3270,0,0}, .halfSize={100,5000,4000}, .rotation={0,0,0}, .userData=1},
{.center={-3300,0,0}, .halfSize={100,5000,4000}, .rotation={0,0,0}, .userData=1}
};
tdLoncha levelData_LVL_NewLoncha_00 = { .actors = levelData_LVL_NewLoncha_00_actors,  .numActors = sizeof(levelData_LVL_NewLoncha_00_actors) / sizeof(levelData_LVL_NewLoncha_00_actors[0]),
.collisions = levelData_LVL_NewLoncha_00_collisions,  .numCollisions = sizeof(levelData_LVL_NewLoncha_00_collisions) / sizeof(levelData_LVL_NewLoncha_00_collisions[0])
};