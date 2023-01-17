#include "suitcase.h"

#include <stdio.h>
#include <stddef.h>

#include "dcMisc.h"

#include "meshes/Baggage_A.h"
#include "meshes/Baggage_B.h"
#include "meshes/Baggage_C.h"
#include "meshes/Baggage_D.h"
#include "meshes/Baggage_E.h"
#include "meshes/Baggage_Triforce.h"

SDC_Mesh3D* gSuitcaseShapes[MAX_SHAPES] = { &Baggage_A_Mesh, &Baggage_B_Mesh, &Baggage_C_Mesh, &Baggage_D_Mesh, &Baggage_E_Mesh, &Baggage_Triforce_Mesh }; //TODO ~ ramonv ~ to be implemented
CVECTOR gSuitcasesColors[MAX_PATTERNS] = { {127, 0, 0},{127, 127, 0},{127, 0, 127},{0, 127, 0},{0, 127, 127} };

Suitcase gSuitcases[MAX_SUITCASES];
bool     gSuitcasesActives[MAX_SUITCASES];

SDC_DrawParams gSuitDrawParams = {
    .tim = NULL,
    .constantColor = {127,127,127},
    .bLighting = 1,
    .bUseConstantColor = 1
};

void ResetSuitcases()
{ 
    for (int i = 0; i< MAX_SUITCASES; ++i)
    { 
        gSuitcasesActives[i] = false; 
    }
} 

void ResetSuitcase(Suitcase* suitcase)
{
    suitcase->position.vx = 0; 
    suitcase->position.vy = 0; 
    suitcase->position.vz = 0; 

    suitcase->yaw = 0; 
    suitcase->pitch = 0; 
}

Suitcase* SpawnSuitcase()
{     
    for (int i = 0; i< MAX_SUITCASES; ++i)
    { 
        if ( !gSuitcasesActives[i] )
        { 
            gSuitcasesActives[i] = true;
            ResetSuitcase(&(gSuitcases[i]));
            return &(gSuitcases[i]);
        }
    }

    return NULL;
}

int GetSuitcaseIndex(Suitcase* suitcase)
{
    return suitcase ? suitcase - gSuitcases : -1;
}

Suitcase* GetSuitcase(int index)
{
    return index < MAX_SUITCASES ? &(gSuitcases[index]) : NULL;
}

bool IsSuitcaseActive(int index)
{ 
    return gSuitcasesActives[index];
}

void DestroySuitcase(Suitcase* input)
{ 
    for (int i = 0; i< MAX_SUITCASES; ++i)
    {
        if ( input == &(gSuitcases[i]) )
        {
            gSuitcasesActives[i] = false;
            return;
        }
    }
}

void SetupSuitcase(Suitcase* suitcase, unsigned int shape, unsigned int pattern, unsigned char content, unsigned char contentVariation)
{
    suitcase->content = content % MAX_ITEM_CATEGORIES; 
    suitcase->contentVariation = contentVariation % ITEM_VARIANTS; 
    suitcase->mesh = gSuitcaseShapes[shape % MAX_SHAPES];
    suitcase->color = gSuitcasesColors[pattern % MAX_PATTERNS];
}

void SuitcaseUpdateRotation(Suitcase* suitcase)
{
    SVECTOR rotation = {.vx = suitcase->pitch, .vy = suitcase->yaw, .vz = 0};
    RotMatrix(&rotation,&suitcase->rotMtx);
}

void RenderSuitcase(SDC_Render* render, SDC_Camera* camera, Suitcase* suitcase)
{
    gSuitDrawParams.constantColor = suitcase->color;
    MATRIX transform = suitcase->rotMtx;
    TransMatrix(&transform, &(suitcase->position));

    dcCamera_ApplyCameraTransform(camera, &transform, &transform);
    dcRender_DrawMeshFast(render, suitcase->mesh, &transform, &gSuitDrawParams, 0);
}

void RenderSuitcases(SDC_Render* render, SDC_Camera* camera)
{
    for (int i = 0; i< MAX_SUITCASES; ++i)
    {
        if (gSuitcasesActives[i])
        { 
            RenderSuitcase(render, camera, &(gSuitcases[i])); 
        }
    }
}