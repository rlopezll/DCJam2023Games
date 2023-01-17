#ifndef _CAIXA_MESH_
#define _CAIXA_MESH_

#include <types.h>
#include "dcRender.h"

static SDC_VertexTextured caixa_Vertices[] = {
    { 400, 573, 0, 0, 127, 64 },
    { -400, 1142, 0, 0, 95, 32 },
    { -400, 573, 0, 0, 95, 64 },
    { 2000, 0, 0, 0, 127, 64 },
    { 2000, 573, 0, 0, 127, 32 },
    { 1200, 573, 0, 0, 95, 32 },
    { 2000, 573, 0, 0, 127, 64 },
    { 2000, 1142, 0, 0, 127, 32 },
    { 1200, 1142, 0, 0, 95, 32 },
    { -400, 573, 0, 0, 127, 64 },
    { -400, 1142, 0, 0, 127, 32 },
    { -1200, 1142, 0, 0, 95, 32 },
    { 1200, 1142, 0, 0, 95, 64 },
    { 2000, 1142, -799, 0, 127, 32 },
    { 400, 1142, -799, 0, 95, 32 },
    { 2000, 1142, 0, 0, 127, 64 },
    { 400, 1142, 0, 0, 127, 32 },
    { 400, 573, 0, 0, 95, 64 },
    { 1200, 573, 0, 0, 127, 64 },
    { 1200, 1142, 0, 0, 127, 32 },
    { 1200, 573, 0, 0, 95, 64 },
    { 400, 1142, 0, 0, 95, 32 },
    { 400, 1142, 0, 0, 95, 64 },
    { 400, 1142, -799, 0, 127, 32 },
    { -400, 1142, 0, 0, 95, 64 },
    { -1200, 1142, -799, 0, 95, 32 },
    { -1200, 1142, 0, 0, 95, 64 },
    { -400, 1142, 0, 0, 127, 64 },
    { -1200, 1142, -799, 0, 127, 32 },
    { -2000, 1142, 0, 0, 95, 64 },
    { -2000, 1142, -799, 0, 95, 32 },
    { 2000, 1142, 0, 0, 95, 32 },
    { 2000, 573, 0, 0, 95, 32 },
    { 2000, 0, -800, 0, 127, 64 },
    { 2000, 0, 0, 0, 95, 64 },
    { -1200, 573, 0, 0, 127, 32 },
    { -2000, 573, 0, 0, 95, 32 },
    { -2000, 0, 0, 0, 95, 64 },
    { -400, 573, 0, 0, 127, 32 },
    { 400, 573, 0, 0, 127, 32 },
    { 1200, 573, 0, 0, 127, 32 },
    { -2000, 0, -800, 0, 95, 64 },
    { -2000, 0, 0, 0, 127, 64 },
    { -2000, 573, 0, 0, 127, 64 },
    { -2000, 1142, 0, 0, 127, 32 },
    { -1200, 1142, 0, 0, 127, 32 },
    { -1200, 573, 0, 0, 95, 64 },
    { -2000, 573, 0, 0, 95, 64 },
    { -2000, 1142, 0, 0, 95, 32 }
};
static u_short caixa_Indices[] = {
    0, 2, 1, 3, 5, 4, 6, 8, 7, 9, 11, 10, 12, 14, 13, 12, 13, 15, 16, 17, 1, 16, 18, 17, 19, 6, 20, 19, 20, 21, 22, 23, 12, 
    22, 24, 23, 25, 23, 24, 26, 28, 27, 26, 29, 28, 28, 29, 30, 13, 32, 31, 33, 32, 13, 32, 33, 34, 35, 37, 36, 38, 37, 35, 38, 3, 
    37, 3, 38, 39, 3, 39, 40, 41, 43, 42, 30, 43, 41, 43, 30, 44, 45, 9, 46, 45, 46, 47, 45, 47, 48
};
static SDC_Mesh3D caixa_Mesh = {caixa_Vertices, caixa_Indices, NULL, 90, 49, POLIGON_VERTEX_TEXTURED};
#endif