#ifndef _ESCENA_CUBE_H
#define _ESCENA_CUBE_H

#include <types.h>
#include "dcRender.h"

#define CUBESIZE 196 

static SDC_Vertex cube_vertices[] = {
    {{-CUBESIZE / 2, -CUBESIZE / 2, -CUBESIZE / 2, 0}}, {{CUBESIZE / 2, -CUBESIZE / 2, -CUBESIZE / 2, 0}},
    {{CUBESIZE / 2, CUBESIZE / 2, -CUBESIZE / 2, 0}},   {{-CUBESIZE / 2, CUBESIZE / 2, -CUBESIZE / 2, 0}},
    {{-CUBESIZE / 2, -CUBESIZE / 2, CUBESIZE / 2, 0}},  {{CUBESIZE / 2, -CUBESIZE / 2, CUBESIZE / 2, 0}},
    {{CUBESIZE / 2, CUBESIZE / 2, CUBESIZE / 2, 0}},    {{-CUBESIZE / 2, CUBESIZE / 2, CUBESIZE / 2, 0}},
};

static u_short cube_indices[] = {
    0, 2, 1, 2, 0, 3,  1, 6, 5, 6, 1, 2,  5, 7, 4, 7, 5, 6,  4, 3, 0, 3, 4, 7,  4, 1, 5, 1, 4, 0,  6, 3, 7, 3, 6, 2,
};

static SDC_Mesh3D cubeMesh = { cube_vertices, cube_indices, NULL, 36, 8, POLIGON_VERTEX };

#endif