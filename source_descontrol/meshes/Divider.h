#ifndef _DIVIDER_MESH_
#define _DIVIDER_MESH_

#include <types.h>
#include "dcRender.h"

static SDC_VertexColor Divider_Vertices[] = {
    { -14, 5, -754, 0, 73, 69, 38, 0 },
    { -14, 5, 754, 0, 67, 185, 142, 0 },
    { 14, 5, -754, 0, 250, 155, 205, 0 },
    { 14, 5, 754, 0, 50, 243, 12, 0 }
};
static u_short Divider_Indices[] = {
    0, 2, 1, 2, 3, 1
};
static SDC_Mesh3D Divider_Mesh = {Divider_Vertices, Divider_Indices, NULL, 6, 4, POLIGON_VERTEX_COLOR};
#endif