#ifndef _PROYECTIL_MESH_
#define _PROYECTIL_MESH_

#include <types.h>
#include "dcRender.h"

static SDC_VertexTexturedNormal Proyectil_Vertices[] = {
    { 0, -37, 0, 0, 0, 4096, 0, 0, 4, 7 },
    { 0, 37, 0, 0, 0, 4096, 0, 0, 4, 2 },
    { -37, 0, 0, 0, 0, 4096, 0, 0, 1, 4 },
    { 37, 0, 0, 0, 0, 4096, 0, 0, 6, 4 },
    { 0, -44, -52, 0, 0, -618, -4049, 0, 11, 14 },
    { 37, 0, 0, 0, 4059, 547, 0, 0, 13, 9 },
    { 0, -37, 0, 0, 0, 547, -4059, 0, 11, 9 },
    { 44, 0, -52, 0, 4049, -618, 0, 0, 13, 14 },
    { -44, 0, -52, 0, -4049, -618, 0, 0, 8, 14 },
    { -37, 0, 0, 0, -4059, 547, 0, 0, 9, 9 },
    { 0, 44, -52, 0, 0, -618, 4049, 0, 11, 14 },
    { 0, 37, 0, 0, 0, 547, 4059, 0, 11, 9 },
    { 0, -44, -52, 0, 0, -618, -4049, 0, 6, 9 },
    { 0, 0, -138, 0, 0, -4096, 0, 0, 3, 12 },
    { 44, 0, -52, 0, 4049, -618, 0, 0, 6, 14 },
    { -44, 0, -52, 0, -4049, -618, 0, 0, 1, 9 },
    { 0, 44, -52, 0, 0, -618, 4049, 0, 1, 14 }
};
static u_short Proyectil_Indices[] = {
    0, 2, 1, 1, 3, 0, 4, 6, 5, 5, 7, 4, 8, 9, 6, 6, 4, 8, 10, 11, 9, 9, 8, 10, 7, 5, 11, 11, 10, 7, 12, 14, 13, 
    15, 12, 13, 16, 15, 13, 14, 16, 13
};
static SDC_Mesh3D Proyectil_Mesh = {Proyectil_Vertices, Proyectil_Indices, NULL, 42, 17, POLIGON_VERTEX_TEXTURED_NORMAL};
#endif