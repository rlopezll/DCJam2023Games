#ifndef TEST_TILE_H
#define TEST_TILE_H

#include "tdGameplay.h"
#include "Cube.h"

tdActor levelData_TestTile[] =
{
    {
        .position = {200,0,0},
        .meshData={.mesh=&cubeMesh},
        .scale = {4000,4000,4000},
        .rotation={0, 0, 0}
    },
    {
        .position = {-200,0,0},
        .meshData={.mesh=&cubeMesh},
        .scale = {4000,4000,4000},
        .rotation={0, 0, 0}
    }
};

#endif