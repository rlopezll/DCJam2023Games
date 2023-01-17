#ifndef _GAME_GROUND_P2_MESH_
#define _GAME_GROUND_P2_MESH_

#include <types.h>
#include "dcRender.h"

static SDC_VertexTexturedNormal Game_Ground_P2_Vertices[] = {
    { 0, 0, -754, 0, 0, 4096, 0, 0, 0, 0 },
    { 1000, 0, 754, 0, 0, 4096, 0, 0, 63, 63 },
    { 1000, 0, -754, 0, 0, 4096, 0, 0, 63, 0 },
    { 0, 0, 755, 0, 0, 4096, 0, 0, 0, 63 }
};
static u_short Game_Ground_P2_Indices[] = {
    0, 2, 1, 1, 3, 0
};
static SDC_Mesh3D Game_Ground_P2_Mesh = {Game_Ground_P2_Vertices, Game_Ground_P2_Indices, NULL, 6, 4, POLIGON_VERTEX_TEXTURED_NORMAL};
#endif