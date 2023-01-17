#ifndef _BAGGAGE_TRIFORCE_MESH_
#define _BAGGAGE_TRIFORCE_MESH_

#include <types.h>
#include "dcRender.h"

static SDC_VertexNormal Baggage_Triforce_Vertices[] = {
    { 51, 33, -30, 0, 3547, 0, 2047, 0 },
    { 0, 33, 60, 0, 3547, 0, 2047, 0 },
    { 0, 0, 60, 0, 3547, 0, 2047, 0 },
    { 51, 0, -30, 0, 3547, 0, 2047, 0 },
    { -51, 33, -29, 0, 0, 0, -4096, 0 },
    { 51, 33, -30, 0, 0, 0, -4096, 0 },
    { 51, 0, -30, 0, 0, 0, -4096, 0 },
    { -51, 0, -29, 0, 0, 0, -4096, 0 },
    { 0, 33, 60, 0, -3547, 0, 2048, 0 },
    { -51, 33, -29, 0, -3547, 0, 2048, 0 },
    { -51, 0, -29, 0, -3547, 0, 2048, 0 },
    { 0, 0, 60, 0, -3547, 0, 2048, 0 },
    { -51, 33, -29, 0, 0, 4096, 0, 0 },
    { 0, 33, 60, 0, 0, 4096, 0, 0 },
    { 51, 33, -30, 0, 0, 4096, 0, 0 }
};
static u_short Baggage_Triforce_Indices[] = {
    0, 2, 1, 0, 3, 2, 4, 6, 5, 4, 7, 6, 8, 10, 9, 8, 11, 10, 12, 14, 13
};
static SDC_Mesh3D Baggage_Triforce_Mesh = {Baggage_Triforce_Vertices, Baggage_Triforce_Indices, NULL, 21, 15, POLIGON_VERTEX_NORMAL};
#endif