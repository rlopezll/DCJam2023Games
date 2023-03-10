#ifndef _HEAD_MESH_
#define _HEAD_MESH_

#include <types.h>
#include "dcRender.h"

static SDC_VertexTexturedNormal head_Vertices[] = {
    { 14, 54, 14, 0, 0, -638, -4045, 0, 31, 0 },
    { 14, 41, -14, 0, 0, 0, -4096, 0, 0, 0 },
    { 14, 54, -14, 0, 0, -638, -4045, 0, 0, 0 },
    { 14, 41, 14, 0, 0, 0, -4096, 0, 31, 0 },
    { 14, 54, -14, 0, -4079, -337, -141, 0, 0, 0 },
    { 0, 41, -14, 0, -4096, 0, 0, 0, 0, 16 },
    { 0, 55, -14, 0, -4073, -429, 0, 0, 0, 7 },
    { 14, 41, -14, 0, -4096, 0, 0, 0, 0, 0 },
    { 10, 65, -11, 0, 0, -1373, -3858, 0, 0, 0 },
    { 10, 65, 11, 0, 0, -1373, -3858, 0, 31, 0 },
    { 2, 65, 3, 0, 0, -4096, 0, 0, 31, 16 },
    { 10, 65, 11, 0, 0, -4096, 0, 0, 31, 0 },
    { 8, 65, 3, 0, 0, -4096, 0, 0, 31, 0 },
    { 0, 65, 14, 0, 0, -4096, 0, 0, 31, 16 },
    { 10, 65, -11, 0, 0, -4096, 0, 0, 0, 0 },
    { 8, 65, -4, 0, 0, -4096, 0, 0, 0, 0 },
    { 2, 65, -4, 0, 0, -4095, 0, 0, 0, 16 },
    { 0, 65, -13, 0, 0, -4096, 0, 0, 0, 16 },
    { 0, 65, -13, 0, 0, -4095, 0, 0, 0, 16 },
    { 0, 65, 14, 0, 0, -4095, 0, 0, 31, 16 },
    { 2, 65, 3, 0, 0, -4095, 0, 0, 31, 16 },
    { 2, 65, -4, 0, 0, -4096, 0, 0, 0, 16 },
    { 0, 54, 17, 0, 4016, -803, 0, 0, 31, 16 },
    { 14, 41, 14, 0, 3909, -378, -1160, 0, 31, 0 },
    { 14, 54, 14, 0, 3888, -750, -1046, 0, 31, 0 },
    { 0, 41, 19, 0, 4076, -394, 0, 0, 31, 16 },
    { 0, 65, -13, 0, -4014, -814, 0, 0, 0, 16 },
    { 10, 65, -11, 0, -4000, -811, -339, 0, 0, 0 },
    { 0, 65, 14, 0, 3909, -1221, 0, 0, 31, 16 },
    { 10, 65, 11, 0, 3814, -1191, -896, 0, 31, 0 },
    { -14, 54, 14, 0, 0, -638, 4045, 0, 31, 0 },
    { -14, 54, -14, 0, 0, -638, 4045, 0, 0, 0 },
    { -14, 41, -14, 0, 0, 0, 4096, 0, 0, 0 },
    { -14, 41, 14, 0, 0, 0, 4096, 0, 31, 0 },
    { -14, 54, -14, 0, -4079, -337, 141, 0, 0, 0 },
    { -14, 41, -14, 0, -4096, 0, 0, 0, 0, 0 },
    { -10, 65, -11, 0, 0, -1373, 3858, 0, 0, 0 },
    { -10, 65, 11, 0, 0, -1373, 3858, 0, 31, 0 },
    { -2, 65, 3, 0, 0, -4096, 0, 0, 31, 16 },
    { -10, 65, 11, 0, 0, -4096, 0, 0, 31, 0 },
    { -8, 65, 3, 0, 0, -4096, 0, 0, 31, 0 },
    { -10, 65, -11, 0, 0, -4096, 0, 0, 0, 0 },
    { -8, 65, -4, 0, 0, -4096, 0, 0, 0, 0 },
    { -2, 65, -4, 0, 0, -4095, 0, 0, 0, 16 },
    { -2, 65, 3, 0, 0, -4095, 0, 0, 31, 16 },
    { -2, 65, -4, 0, 0, -4096, 0, 0, 0, 16 },
    { -14, 54, 14, 0, 3888, -750, 1046, 0, 31, 0 },
    { -14, 41, 14, 0, 3909, -378, 1160, 0, 31, 0 },
    { -10, 65, -11, 0, -4000, -811, 339, 0, 0, 0 },
    { -10, 65, 11, 0, 3814, -1191, 896, 0, 31, 0 }
};
static u_short head_Indices[] = {
    0, 2, 1, 1, 3, 0, 4, 6, 5, 5, 7, 4, 8, 0, 9, 8, 2, 0, 10, 12, 11, 11, 13, 10, 14, 11, 12, 12, 15, 14, 15, 16, 14, 
    14, 16, 17, 18, 20, 19, 18, 21, 20, 22, 24, 23, 23, 25, 22, 26, 6, 27, 27, 6, 4, 28, 29, 22, 29, 24, 22, 30, 32, 31, 30, 33, 
    32, 34, 35, 5, 5, 6, 34, 30, 31, 36, 36, 37, 30, 38, 13, 39, 39, 40, 38, 40, 39, 41, 41, 42, 40, 43, 41, 17, 43, 42, 41, 18, 
    19, 44, 44, 45, 18, 22, 47, 46, 22, 25, 47, 48, 6, 26, 6, 48, 34, 28, 22, 49, 49, 22, 46
};
static SDC_Mesh3D head_Mesh = {head_Vertices, head_Indices, NULL, 120, 50, POLIGON_VERTEX_TEXTURED_NORMAL};
#endif