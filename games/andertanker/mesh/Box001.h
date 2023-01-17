#ifndef _BOX001_MESH_
#define _BOX001_MESH_

#include <types.h>
#include "dcRender.h"

static SDC_VertexTexturedNormal Box001_Vertices[] = {
    { 158, 19, -13, 0, 0, -4096, 0, 0, 126, 104 },
    { -158, 19, -13, 0, 0, -4096, 0, 0, 0, 104 },
    { -158, 19, 13, 0, 0, -4096, 0, 0, 0, 118 },
    { 158, 19, 13, 0, 0, -4096, 0, 0, 126, 118 },
    { 158, 19, 13, 0, 0, 0, 4096, 0, 126, 118 },
    { -158, 19, 13, 0, 0, 0, 4096, 0, 0, 118 },
    { -158, 0, 13, 0, 0, 0, 4096, 0, 0, 127 },
    { 158, 0, 13, 0, 0, 0, 4096, 0, 126, 127 }
};
static u_short Box001_Indices[] = {
    0, 2, 1, 0, 3, 2, 4, 6, 5, 4, 7, 6
};
static SDC_Mesh3D Box001_Mesh = {Box001_Vertices, Box001_Indices, NULL, 12, 8, POLIGON_VERTEX_TEXTURED_NORMAL};
#endif