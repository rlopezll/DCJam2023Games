
#include "tdGameplay.h"
#include <limits.h>
#include <stdio.h>
#include "dcCamera.h"
#include "dcRender.h"
#include "dcMath.h"


tdTIMDataHandler timData[10];

void GetActorTransform(tdActor* actor, MATRIX* outTransform)
{
    GetActorTransformOffset(actor, VECTOR_ZERO, outTransform);
}

void DrawActor(tdActor* actor, SDC_Render* render, SDC_Camera* camera)
{
    DrawActorOffset(actor, VECTOR_ZERO, render, camera);
}

void DrawActorBoundingBox(tdActor* actor, SDC_Render* render,  SDC_Camera* camera)
{
    DrawActorBoundingBoxOffset(actor, VECTOR_ZERO, render, camera);
}

void DrawActorArray(tdActor actorArray[],int numActors, SDC_Render* render, SDC_Camera* camera, int bDrawBoundingBoxes)
{
    DrawActorArrayOffset(actorArray, numActors, VECTOR_ZERO, render, camera, bDrawBoundingBoxes);
}


void GetActorTransformOffset(tdActor* actor, VECTOR offset, MATRIX* outTransform)
{
    VECTOR finalPos = actor->position;
    finalPos.vx += offset.vx;
    finalPos.vy += offset.vy;
    finalPos.vz += offset.vz;
    RotMatrix(&actor->rotation, outTransform);
    TransMatrix(outTransform, &finalPos);
    ScaleMatrix(outTransform, &actor->scale);
}

void DrawActorOffset(tdActor* actor, VECTOR offset, SDC_Render* render, SDC_Camera* camera)
{
    // Actor transform
    MATRIX transform;
    GetActorTransformOffset(actor, offset, &transform);
    dcCamera_ApplyCameraTransform(camera, &transform, &transform);

    // Actor draw params
    SDC_DrawParams drawParams;
    drawParams.bLighting = 0;
    drawParams.backFaceCullMode = 0;
    drawParams.bUseConstantColor = 1;
    CVECTOR drawColor = {120,120,120};
    drawParams.constantColor = drawColor;

    // Draw the actual actor
    dcRender_DrawMesh(render, actor->meshData.mesh, &transform, &drawParams);
}

void DrawActorArrayOffset(tdActor actorArray[], int numActors, VECTOR offset, SDC_Render* render, SDC_Camera* camera, int bDrawBoundingBoxes)
{
    for (int i = 0; i < numActors; ++i)
    {
        tdActor actorToDraw = actorArray[i];
        DrawActorOffset(&actorToDraw, offset, render, camera);
        if(bDrawBoundingBoxes)
        {
            DrawActorBoundingBoxOffset(&actorToDraw, offset, render, camera);
        }
    }
}

void DrawLoncha(tdLoncha* loncha, VECTOR offset, SDC_Render* render, SDC_Camera* camera)
{
    DrawActorArrayOffset(loncha->actors, loncha->numActors, offset, render, camera, 0);
}

void DrawLonchaCollisions(tdLoncha* loncha, VECTOR offset, SDC_Render* render, SDC_Camera* camera)
{
    for (int i = 0; i < loncha->numCollisions; ++i)
    {
        DrawOOBBDebugOffset(&loncha->collisions[i], offset, render, camera);
    }
}

void DrawBox(SVECTOR min, SVECTOR max, MATRIX* transform, SDC_Render* render,  SDC_Camera* camera, CVECTOR* drawColor)
{
    // Cube vertexs
    SVECTOR v000 = { min.vx, min.vy, min.vz};
    SVECTOR v001 = { min.vx, min.vy, max.vz};
    SVECTOR v010 = { min.vx, max.vy, min.vz};
    SVECTOR v011 = { min.vx, max.vy, max.vz};
    SVECTOR v100 = { max.vx, min.vy, min.vz};
    SVECTOR v101 = { max.vx, min.vy, max.vz};
    SVECTOR v110 = { max.vx, max.vy, min.vz};
    SVECTOR v111 = { max.vx, max.vy, max.vz};

    // Cube edges
    dcRender_DrawLine(render, &v000, &v100, transform, drawColor, 2);
    dcRender_DrawLine(render, &v000, &v010, transform, drawColor, 2);
    dcRender_DrawLine(render, &v000, &v001, transform, drawColor, 2);

    dcRender_DrawLine(render, &v110, &v111, transform, drawColor, 2);
    dcRender_DrawLine(render, &v011, &v111, transform, drawColor, 2);
    dcRender_DrawLine(render, &v101, &v111, transform, drawColor, 2);

    dcRender_DrawLine(render, &v001, &v101, transform, drawColor, 2);
    dcRender_DrawLine(render, &v001, &v011, transform, drawColor, 2);

    dcRender_DrawLine(render, &v010, &v011, transform, drawColor, 2);
    dcRender_DrawLine(render, &v010, &v110, transform, drawColor, 2);

    dcRender_DrawLine(render, &v100, &v101, transform, drawColor, 2);
    dcRender_DrawLine(render, &v100, &v110, transform, drawColor, 2);
}

void DrawOOBBDebug(SDC_OOBB* oobb, SDC_Render* render,  SDC_Camera* camera)
{
    MATRIX transform = {0};
    RotMatrix(&oobb->rotation, &transform);
    TransMatrix(&transform, &oobb->center);
    dcCamera_ApplyCameraTransform(camera, &transform, &transform);

    SVECTOR min = { - oobb->halfSize.vx, -oobb->halfSize.vy, -oobb->halfSize.vz};
    SVECTOR max = { oobb->halfSize.vx, oobb->halfSize.vy,  oobb->halfSize.vz};

    CVECTOR drawColor = {255,255,60};
    DrawBox(min, max, &transform, render, camera, &drawColor);
}

void DrawOOBBDebugOffset(SDC_OOBB* oobb, VECTOR offset, SDC_Render* render,  SDC_Camera* camera)
{
    MATRIX transform = {0};
    VECTOR location = {oobb->center.vx + offset.vx, oobb->center.vy + offset.vy, oobb->center.vz + offset.vz};
    RotMatrix(&oobb->rotation, &transform);
    TransMatrix(&transform, &location);
    dcCamera_ApplyCameraTransform(camera, &transform, &transform);

    SVECTOR min = { - oobb->halfSize.vx, -oobb->halfSize.vy, -oobb->halfSize.vz};
    SVECTOR max = { oobb->halfSize.vx, oobb->halfSize.vy,  oobb->halfSize.vz};

    CVECTOR drawColor = {255,255,60};
    DrawBox(min, max, &transform, render, camera, &drawColor);
}


void DrawActorBoundingBoxOffset(tdActor* actor, VECTOR offset, SDC_Render* render,  SDC_Camera* camera)
{
    // Actor transform
    MATRIX transform;
    GetActorTransformOffset(actor, offset, &transform);
    dcCamera_ApplyCameraTransform(camera, &transform, &transform);

    CVECTOR drawColor = {255,60,60};

    tdBoundingBox* boundingBox = &actor->physicsData.boundingBox;
    DrawBox(boundingBox->min, boundingBox->max, &transform, render, camera, &drawColor);
}

void InitializeActorBoundingBoxBasedOnMesh(tdActor* actor)
{
    tdBoundingBox* boundingBox = &actor->physicsData.boundingBox;
    boundingBox->min.vx = SHRT_MAX;
    boundingBox->min.vy = SHRT_MAX;
    boundingBox->min.vz = SHRT_MAX;
    boundingBox->max.vx = SHRT_MIN;
    boundingBox->max.vy = SHRT_MIN;
    boundingBox->max.vz = SHRT_MIN;

    const SDC_Mesh3D* mesh = actor->meshData.mesh;

    // // We need to get the data size from the vertex type
    // short dataSize = 0;
    // switch(mesh->polygonVertexType)
    // {
    //     case POLIGON_VERTEX:
    //     {
    //         dataSize = sizeof(SDC_Vertex);
    //     }
    //     break;
    //     case POLIGON_VERTEX_COLOR:
    //     {
    //         dataSize = sizeof(SDC_Vertex);
    //     }
    //     break;
    //     case POLIGON_VERTEX_COLOR_NORMAL:
    //     {
    //         dataSize = sizeof(SDC_VertexColorNormal);
    //     } break;
    //     case POLIGON_VERTEX_NORMAL:
    //     {
    //         dataSize = sizeof(SDC_VertexNormal);
    //     } break;
    //     case POLIGON_VERTEX_TEXTURED:
    //     {
    //         dataSize = sizeof(SDC_VertexTextured);
    //     }
    //     break;
    //     case POLIGON_VERTEX_TEXTURED_COLOR:
    //     {
    //         dataSize = sizeof(SDC_VertexTextured);
    //     }
    //     break;
    //     case POLIGON_VERTEX_TEXTURED_NORMAL:
    //     {
    //         dataSize = sizeof(SDC_VertexTexturedNormal);
    //     }
    //     break;
    // }

    //int dataIndex = (int)actor->meshData.mesh->vertexs;

    for( int i = 0; i<mesh->numVertices; ++i)
    {
        SVECTOR position = { 0, 0, 0};

        switch(mesh->polygonVertexType)
        {
            case POLIGON_VERTEX:
            {
                SDC_Vertex* dataPtr = (SDC_Vertex*) mesh->vertexs;
                position = dataPtr[i].position;
            }
            break;
            case POLIGON_VERTEX_COLOR:
            {
                SDC_VertexColor* dataPtr = (SDC_VertexColor*) mesh->vertexs;
                position = dataPtr[i].position;
            }
            break;
            case POLIGON_VERTEX_COLOR_NORMAL:
            {
                SDC_VertexColorNormal* dataPtr = (SDC_VertexColorNormal*) mesh->vertexs;
                position = dataPtr[i].position;
            } break;
            case POLIGON_VERTEX_NORMAL:
            {
                SDC_VertexNormal* dataPtr = (SDC_VertexNormal*) mesh->vertexs;
                position = dataPtr[i].position;
            } break;
            case POLIGON_VERTEX_TEXTURED:
            {
                SDC_VertexTextured* dataPtr = (SDC_VertexTextured*) mesh->vertexs;
                position = dataPtr[i].position;
            }
            break;
            case POLIGON_VERTEX_TEXTURED_COLOR:
            {
                SDC_VertexColorTextured* dataPtr = (SDC_VertexColorTextured*) mesh->vertexs;
                position = dataPtr[i].position;
            }
            break;
            case POLIGON_VERTEX_TEXTURED_NORMAL:
            {
                SDC_VertexTexturedNormal* dataPtr = (SDC_VertexTexturedNormal*) mesh->vertexs;
                position = dataPtr[i].position;
            }
            break;
        }

        // // The goal was to only get the position of all types without caring for type, but it did not work
        // // Dereference position as position is always the first element in the vertex struct
        //SVECTOR* positionPtr = (SVECTOR*) ( mesh->vertexs + dataIndex);
        //SVECTOR position = *positionPtr;

        //printf("Vertex Pos:: %d %d %d\n", 
        //   position.vx, position.vy,position.vz);

        // Re-assign values if needed
        boundingBox->min.vx = position.vx < boundingBox->min.vx ? position.vx : boundingBox->min.vx;
        boundingBox->min.vy = position.vy < boundingBox->min.vy ? position.vy : boundingBox->min.vy;
        boundingBox->min.vz = position.vz < boundingBox->min.vz ? position.vz : boundingBox->min.vz;
        boundingBox->max.vx = position.vx > boundingBox->max.vx ? position.vx : boundingBox->max.vx;
        boundingBox->max.vy = position.vy > boundingBox->max.vy ? position.vy : boundingBox->max.vy;
        boundingBox->max.vz = position.vz > boundingBox->max.vz ? position.vz : boundingBox->max.vz;

        // // Increment verted data iterator
        //dataIndex += dataSize;
    }

    //printf("Bounding box:: min: %d %d %d max: %d %d %d\n", 
    //    boundingBox->min.vx, boundingBox->min.vy,boundingBox->min.vz,
    //    boundingBox->max.vx, boundingBox->max.vy,boundingBox->max.vz);
}


SDC_Texture* GetTextureDataAndLoadIfNeeded(u_long* tim_identifier)
{
    SDC_Texture* textureData = NULL;
    int timDataID = 0;
    int bInitialized = 0;
    for(int j=0;j<10;++j)
    {
        if(timData[j].tim_identifier == tim_identifier )
        {
            timDataID = j;
            bInitialized = 1;
            break;
        }
    }

    if(!bInitialized)
    {
        TIM_IMAGE timImage;
        dcRender_LoadTexture(&timImage, tim_identifier);
        timData[timDataID].textureData.mode = timImage.mode;
        timData[timDataID].textureData.crect = *timImage.crect;
        timData[timDataID].textureData.prect = *timImage.prect;
        timData[timDataID].tim_identifier = tim_identifier;
        
    }
    
    textureData = &timData[timDataID].textureData;

    return textureData;
}

int RandomBetween(int min, int max)
{
    if (min > max)
        return RandomBetween(max, min);

    int range = max - min;
    int r = rand() % range;
    return min + r;
}