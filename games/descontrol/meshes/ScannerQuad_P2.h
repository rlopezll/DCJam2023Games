#ifndef _SCANNERQUAD_P2_MESH_
#define _SCANNERQUAD_P2_MESH_

#include <types.h>
#include "dcRender.h"

static SDC_VertexTextured ScannerQuad_P2_Vertices[] = {
    { 647, 190, -499, 0, 63, 0 },
    { 417, 190, -499, 0, 0, 0 },
    { 417, 190, -269, 0, 0, 63 },
    { 647, 190, -269, 0, 63, 63 }
};
static u_short ScannerQuad_P2_Indices[] = {
    0, 2, 1, 0, 3, 2
};
static SDC_Mesh3D ScannerQuad_P2_Mesh = {ScannerQuad_P2_Vertices, ScannerQuad_P2_Indices, NULL, 6, 4, POLIGON_VERTEX_TEXTURED};
#endif