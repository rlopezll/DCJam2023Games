#ifndef _NOVARAMA_MESH_
#define _NOVARAMA_MESH_

#include <types.h>
#include "dcRender.h"

static SDC_VertexTextured novarama_Vertices[] = {
    { 636, 214, 0, 0, 127, 0 },
    { -636, 214, 0, 0, 0, 0 },
    { -636, -214, 0, 0, 0, 63 },
    { 636, -214, 0, 0, 127, 63 }
};
static u_short novarama_Indices[] = {
    0, 2, 1, 0, 3, 2
};
static SDC_Mesh3D novarama_Mesh = {novarama_Vertices, novarama_Indices, NULL, 6, 4, POLIGON_VERTEX_TEXTURED};
#endif