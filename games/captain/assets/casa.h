#ifndef _CASA_MESH_
#define _CASA_MESH_

#include <types.h>
#include "dcRender.h"

static SDC_VertexTextured casa_Vertices[] = {
    { -800, 799, 400, 0, 31, 64 },
    { -517, 1200, 159, 0, 31, 32 },
    { -517, 1200, -399, 0, 31, 32 },
    { 517, 1200, -399, 0, 31, 32 },
    { 0, 1200, 159, 0, 0, 64 },
    { 517, 1200, 159, 0, 31, 64 },
    { 800, 800, -1199, 0, 31, 64 },
    { 517, 1200, -959, 0, 31, 32 },
    { 800, 0, 400, 0, 31, 127 },
    { 0, 399, 400, 0, 0, 96 },
    { 0, 0, 400, 0, 0, 127 },
    { 800, 799, 400, 0, 31, 64 },
    { 0, 799, 400, 0, 0, 64 },
    { -800, 399, 400, 0, 31, 96 },
    { -800, 0, -1200, 0, 0, 127 },
    { -800, 799, 400, 0, 0, 64 },
    { -400, 799, 400, 0, 0, 64 },
    { -517, 1200, 159, 0, 0, 32 },
    { -517, 1200, -959, 0, 0, 32 },
    { -800, 800, -1199, 0, 0, 64 },
    { 517, 1200, 159, 0, 0, 32 },
    { 800, 0, 400, 0, 0, 127 },
    { 800, 0, -1200, 0, 31, 127 },
    { -800, 0, 400, 0, 31, 127 },
    { 0, 399, 400, 0, 95, 64 },
    { -400, 799, 400, 0, 63, 32 },
    { -400, 399, 400, 0, 63, 64 },
    { 0, 799, 400, 0, 95, 32 },
    { -400, 399, 400, 0, 31, 96 },
    { -800, 799, 400, 0, 0, 64 },
    { -800, 399, 400, 0, 0, 96 },
    { -400, 799, 400, 0, 31, 64 },
    { 0, 1200, 159, 0, 31, 32 },
    { 0, 799, 400, 0, 31, 64 },
    { 517, 1200, 159, 0, 31, 32 },
    { 0, 799, 400, 0, 0, 64 },
    { 800, 799, 400, 0, 31, 64 },
    { 0, 1200, 159, 0, 0, 32 },
    { 0, 0, 400, 0, 31, 127 },
    { 0, 399, 400, 0, 31, 96 },
    { -800, 0, 400, 0, 0, 127 },
    { -517, 1200, -399, 0, 0, 32 },
    { -517, 1200, 159, 0, 0, 64 },
    { 517, 1200, -399, 0, 31, 64 }
};
static u_short casa_Indices[] = {
    0, 2, 1, 3, 5, 4, 6, 3, 7, 8, 10, 9, 11, 9, 12, 13, 14, 2, 15, 17, 16, 2, 19, 18, 3, 11, 20, 3, 22, 21, 3, 6, 22, 
    21, 11, 3, 0, 13, 2, 2, 14, 19, 14, 13, 23, 11, 21, 9, 24, 26, 25, 24, 25, 27, 28, 30, 29, 28, 29, 31, 17, 32, 16, 16, 32, 
    33, 34, 36, 35, 34, 35, 37, 38, 28, 39, 40, 28, 38, 30, 28, 40, 41, 4, 42, 4, 41, 43, 43, 41, 7, 7, 41, 18
};
static SDC_Mesh3D casa_Mesh = {casa_Vertices, casa_Indices, NULL, 93, 44, POLIGON_VERTEX_TEXTURED};
#endif