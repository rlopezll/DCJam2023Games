#ifndef _FLOOR_MESH_MESH_
#define _FLOOR_MESH_MESH_

#include <types.h>
#include "dcRender.h"

static SDC_VertexTexturedNormal floor_mesh_Vertices[] = {
    { -625, 0, -625, 0, 0, -4096, 0, 0, 0, 0 },
    { -625, 0, 625, 0, 0, -4096, 0, 0, 0,1 },
    { 625, 0, -625, 0, 0, -4096, 0, 0, 1, 0 },
    { 625, 0, 625, 0, 0, -4096, 0, 0, 1, 1 }
};
static u_short floor_mesh_Indices[] = {
    0, 2, 1, 3, 1, 2
};
static SDC_Mesh3D floor_mesh_Mesh = {floor_mesh_Vertices, floor_mesh_Indices, NULL, 6, 4, POLIGON_VERTEX_TEXTURED_NORMAL};
#endif