#ifndef _SCANNERQUAD_P1_MESH_
#define _SCANNERQUAD_P1_MESH_

#include <types.h>
#include "dcRender.h"

static SDC_VertexTextured ScannerQuad_P1_Vertices[] = {
    { -354, 194, -490, 0, 63, 0 },
    { -584, 194, -490, 0, 0, 0 },
    { -584, 194, -260, 0, 0, 63 },
    { -354, 194, -260, 0, 63, 63 }
};
static u_short ScannerQuad_P1_Indices[] = {
    0, 2, 1, 0, 3, 2
};
static SDC_Mesh3D ScannerQuad_P1_Mesh = {ScannerQuad_P1_Vertices, ScannerQuad_P1_Indices, NULL, 6, 4, POLIGON_VERTEX_TEXTURED};
#endif