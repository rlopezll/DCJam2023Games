#ifndef _OBSTACLEDEPTH_MESH_
#define _OBSTACLEDEPTH_MESH_

#include <types.h>
#include "dcRender.h"

static SDC_VertexTextured obstacleDepth_Vertices[] = {
    { 400, 474, 400, 0, 31, 32 },
    { 800, 0, 800, 0, 0, 1 },
    { 800, 0, -3300, 0, 0, 64 },
    { -800, 0, -1800, 0, 95, 64 },
    { -400, 475, -1399, 0, 63, 32 },
    { -400, 475, -3300, 0, 63, 64 },
    { 400, 475, -3300, 0, 31, 64 },
    { 400, 475, -1399, 0, 31, 64 },
    { -400, 475, -3300, 0, 63, 64 },
    { 0, 475, -1399, 0, 31, 32 },
    { 0, 475, -3300, 0, 31, 64 },
    { -400, 475, -1399, 0, 63, 32 },
    { 400, 475, -1399, 0, 63, 32 },
    { 400, 475, -3300, 0, 63, 64 },
    { 0, 475, -1399, 0, 63, 64 },
    { 400, 474, 400, 0, 31, 32 },
    { 400, 475, -1399, 0, 31, 64 },
    { 0, 474, 400, 0, 63, 32 },
    { -400, 475, -1399, 0, 31, 64 },
    { -400, 474, 400, 0, 31, 32 },
    { -800, 0, 800, 0, 95, 1 },
    { -400, 474, 400, 0, 63, 32 },
    { 400, 474, 400, 0, 31, 32 },
    { 0, 474, 400, 0, 31, 32 }
};
static u_short obstacleDepth_Indices[] = {
    0, 2, 1, 3, 5, 4, 6, 2, 7, 7, 2, 0, 8, 10, 9, 8, 9, 11, 10, 13, 12, 10, 12, 9, 14, 16, 15, 14, 15, 17, 18, 14, 17, 
    18, 17, 19, 4, 21, 20, 4, 20, 3, 1, 23, 22, 23, 1, 20, 23, 20, 21
};
static SDC_Mesh3D obstacleDepth_Mesh = {obstacleDepth_Vertices, obstacleDepth_Indices, NULL, 51, 24, POLIGON_VERTEX_TEXTURED};
#endif