#ifndef _WALL_MESH_
#define _WALL_MESH_

#include <types.h>
#include "dcRender.h"

static SDC_VertexTexturedNormal wall_Vertices[] = {
    { -1581, 199, 132, 0, 0, -4096, 0, 0, 0, 118 },
    { 1581, 199, 132, 0, 0, -4096, 0, 0, 127, 118 },
    { -1581, 199, -132, 0, 0, -4096, 0, 0, 0, 105 },
    { 1581, 199, -132, 0, 0, -4096, 0, 0, 127, 105 },
    { -1581, 0, 132, 0, 0, 0, 4096, 0, 0, 127 },
    { 1581, 0, 132, 0, 0, 0, 4096, 0, 127, 127 },
    { -1581, 199, 132, 0, 0, 0, 4096, 0, 0, 118 },
    { 1581, 199, 132, 0, 0, 0, 4096, 0, 127, 118 }
};
static u_short wall_Indices[] = {
    0, 2, 1, 3, 1, 2, 4, 6, 5, 7, 5, 6
};
static SDC_Mesh3D wall_Mesh = {wall_Vertices, wall_Indices, NULL, 12, 8, POLIGON_VERTEX_TEXTURED_NORMAL};
#endif