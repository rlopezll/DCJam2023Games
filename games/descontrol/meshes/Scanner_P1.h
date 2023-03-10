#ifndef _SCANNER_P1_MESH_
#define _SCANNER_P1_MESH_

#include <types.h>
#include "dcRender.h"

static SDC_VertexTexturedNormal Scanner_P1_Vertices[] = {
    { -342, 168, -246, 0, 0, 4096, 0, 0, 3, 45 },
    { -628, 168, -525, 0, 0, 4096, 0, 0, 14, 56 },
    { -628, 168, -246, 0, 0, 4096, 0, 0, 14, 45 },
    { -342, 168, -525, 0, 0, 4096, 0, 0, 3, 56 },
    { -628, 148, -539, 0, 0, 0, -4096, 0, 14, 57 },
    { -342, 148, -539, 0, 0, 0, -4096, 0, 3, 57 },
    { -342, 0, -539, 0, 0, 0, -4096, 0, 3, 62 },
    { -628, 0, -539, 0, 0, 0, -4096, 0, 14, 62 },
    { -342, 148, -232, 0, 0, 0, 4096, 0, 3, 44 },
    { -628, 148, -232, 0, 0, 0, 4096, 0, 14, 44 },
    { -628, 0, -232, 0, 0, 0, 4096, 0, 14, 39 },
    { -342, 0, -232, 0, 0, 0, 4096, 0, 3, 39 },
    { -342, 135, -492, 0, 4096, 0, 0, 0, 12, 29 },
    { -342, 0, -539, 0, 4095, 0, 0, 0, 14, 35 },
    { -342, 148, -539, 0, 4096, 0, 0, 0, 14, 29 },
    { -342, -1, -492, 0, 4096, 0, 0, 0, 12, 35 },
    { -342, 168, -246, 0, 4096, 0, 0, 0, 2, 28 },
    { -342, 168, -525, 0, 4096, 0, 0, 0, 13, 28 },
    { -342, 135, -279, 0, 4096, 0, 0, 0, 4, 29 },
    { -342, 0, -232, 0, 4095, 0, 0, 0, 2, 35 },
    { -342, -1, -279, 0, 4096, 0, 0, 0, 4, 35 },
    { -342, 148, -232, 0, 4096, 0, 0, 0, 2, 29 },
    { -628, 135, -492, 0, 0, 0, 4096, 0, 48, 5 },
    { -342, -1, -492, 0, 0, 0, 4096, 0, 59, 10 },
    { -342, 135, -492, 0, 0, 0, 4096, 0, 59, 5 },
    { -628, -1, -492, 0, 0, 0, 4096, 0, 48, 10 },
    { -342, 135, -279, 0, 0, 0, -4096, 0, 25, 14 },
    { -628, -1, -279, 0, 0, 0, -4096, 0, 30, 3 },
    { -628, 135, -279, 0, 0, 0, -4096, 0, 25, 3 },
    { -342, -1, -279, 0, 0, 0, -4096, 0, 30, 14 },
    { -342, 148, -539, 0, 0, 2354, -3351, 0, 3, 57 },
    { -628, 148, -539, 0, 0, 2354, -3351, 0, 14, 57 },
    { -342, 168, -525, 0, 0, 2354, -3351, 0, 3, 56 },
    { -628, 168, -525, 0, 0, 2354, -3351, 0, 14, 56 },
    { -628, 148, -232, 0, 0, 2354, 3351, 0, 14, 44 },
    { -342, 148, -232, 0, 0, 2354, 3351, 0, 3, 44 },
    { -628, 168, -246, 0, 0, 2354, 3351, 0, 14, 45 },
    { -342, 168, -246, 0, 0, 2354, 3351, 0, 3, 45 },
    { -628, 148, -539, 0, -4096, 0, 0, 0, 16, 18 },
    { -628, 0, -539, 0, -4095, 0, 0, 0, 16, 24 },
    { -628, 135, -492, 0, -4096, 0, 0, 0, 18, 19 },
    { -628, -1, -492, 0, -4095, 0, 0, 0, 18, 24 },
    { -628, 168, -246, 0, -4096, 0, 0, 0, 27, 17 },
    { -628, 168, -525, 0, -4096, 0, 0, 0, 17, 17 },
    { -628, 135, -279, 0, -4096, 0, 0, 0, 26, 19 },
    { -628, 0, -232, 0, -4095, 0, 0, 0, 28, 24 },
    { -628, 148, -232, 0, -4096, 0, 0, 0, 28, 18 },
    { -628, -1, -279, 0, -4096, 0, 0, 0, 26, 24 }
};
static u_short Scanner_P1_Indices[] = {
    0, 2, 1, 1, 3, 0, 4, 6, 5, 4, 7, 6, 8, 10, 9, 8, 11, 10, 12, 14, 13, 13, 15, 12, 16, 17, 12, 12, 18, 16, 18, 20, 19, 
    19, 21, 18, 22, 24, 23, 23, 25, 22, 26, 28, 27, 27, 29, 26, 17, 14, 12, 16, 18, 21, 30, 32, 31, 33, 31, 32, 34, 36, 35, 37, 35, 
    36, 38, 40, 39, 40, 41, 39, 42, 44, 43, 44, 40, 43, 44, 46, 45, 45, 47, 44, 43, 40, 38, 42, 46, 44
};
static SDC_Mesh3D Scanner_P1_Mesh = {Scanner_P1_Vertices, Scanner_P1_Indices, NULL, 90, 48, POLIGON_VERTEX_TEXTURED_NORMAL};
#endif