
#include "dcCollision.h"
#include "dcMath.h"
#include <stdio.h>
#include "dcRender.h"
#include "tdGameplay.h"

//#define DEBUGCOLLISIONS

void DrawCollBox(SVECTOR min, SVECTOR max, MATRIX* transform, SDC_Render* render,  SDC_Camera* camera, CVECTOR* drawColor)
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

long dcCollision_RaySphereInteresct( VECTOR* rayOrigin, SVECTOR* rayDir, VECTOR* sphereCenter, long sphereRadius )
{
    // Note: I'm using shl instead of integer multiply because it's probably faster. But I'm just guessing it.
    
    // Translate sphere to the origin
    VECTOR s = { rayOrigin->vx - sphereCenter->vx, rayOrigin->vy - sphereCenter->vy, rayOrigin->vz - sphereCenter->vz };

    // compute quadratic equation coefficients
    long a = DC_DOT(rayDir, rayDir);
    long b = DC_DOT64(&s, rayDir) << 1; // shl1 instead of x2
    long c = DC_DOT64(&s, &s) - DC_MUL64(sphereRadius, sphereRadius);

    long discriminant = DC_MUL64(b, b) - (DC_MUL64(a, c) << 2); // b^2 - 4ac (shl2 instead of x4)
    if(discriminant < 0)
    {
        return 0;
    }

    long discSqrt = SquareRoot12(discriminant);
    long t1 = DC_DIV( -b - discSqrt, a << 1 );
    long t2 = DC_DIV( -b + discSqrt, a << 1 );
    
    // return closest intersection point which is in front of ray, or closest intersection point if both are behind.
    long minT = DC_MIN(t1, t2);
    return minT >= 0 ? minT : DC_MAX(t1, t2);
}

long dcCollision_RayPlaneInteresct( VECTOR* rayOrigin, SVECTOR* rayDir, SVECTOR* planeNormal, long planeHeight )
{
    return 0;
}

long dcCollision_RayAABBInteresct( VECTOR* rayOrigin, SVECTOR* rayDir, VECTOR* boxHalfSize, VECTOR* boxCenter )
{
    return 0;
}

long dcCollision_RayBOXInteresct( VECTOR* rayOrigin, SVECTOR* rayDir, VECTOR* boxHalfSize, MATRIX* boxTransform )
{
    return 0;
}

long dcCollision_SpheresOverlap( VECTOR* sphere1Center, VECTOR* sphere2center, long sphere1Radius, long sphere2Radius )
{
    long radiusSum = sphere1Radius + sphere2Radius;
    return DC_SQDIST32(sphere1Center, sphere2center) - DC_MUL64(radiusSum, radiusSum);
}

long dcCollision_SphereAABBOverlap( VECTOR* boxHalfSize, VECTOR* boxCenter, VECTOR* sphereCenter, long sphereRadius )
{
    VECTOR p = { .vx = sphereCenter->vx - boxCenter->vx, .vy = sphereCenter->vy - boxCenter->vy, .vz = sphereCenter->vz - boxCenter->vz };
    p.vx = abs(p.vx) - boxHalfSize->vx;
    p.vy = abs(p.vy) - boxHalfSize->vy;
    p.vz = abs(p.vz) - boxHalfSize->vz;

    VECTOR maxP0 = { DC_MAX(p.vx, 0), DC_MAX(p.vy, 0), DC_MAX(p.vz, 0) };
    long dist = DC_LENGTH(&maxP0) + DC_MIN( DC_MAX(p.vx, DC_MAX(p.vy, p.vz)), 0 ) - sphereRadius;

    // printf("Sphere( p: %d, %d, %d r: %d ) collides with AABB( p: %d, %d, %d hs: %d %d %d) -> %s\n",
    //     sphereCenter->vx, sphereCenter->vy, sphereCenter->vz, sphereRadius,
    //     boxCenter->vx, boxCenter->vy, boxCenter->vz, boxHalfSize->vx, boxHalfSize->vy, boxHalfSize->vz,
    //     dist < 0 ? "YES" : "NO"
    // );

    return dist;
}

long dcCollision_SphereBOXOverlap( VECTOR* boxHalfSize, MATRIX* boxInvTransform,  VECTOR* sphereCenter, long sphereRadius )
{
    VECTOR transformedSphereCenter;
    SetRotMatrix(boxInvTransform);
    SetTransMatrix(boxInvTransform);
    long flag;
    TransRot_32(sphereCenter, &transformedSphereCenter, &flag);

    VECTOR boxCenter = { 0 };
    return dcCollision_SphereAABBOverlap(boxHalfSize, &boxCenter, &transformedSphereCenter, sphereRadius );

}


void dcBF_Init(SDC_Broadphase* bf, unsigned maxShapes)
{
    bf->shapes = malloc3(maxShapes * sizeof(SDC_Shape));
    bf->entries = malloc3(maxShapes * sizeof(SDC_ShapeEntry));
    bf->numShapes = 0;
    bf->maxShapes = maxShapes;
    bf->freeEntry = 0;
    for(int i = 0; i < maxShapes; ++i)
    {
        bf->entries[i].bAlive = 0;
        bf->entries[i].idx = i + 1;
    }
    bf->entries[maxShapes - 1].idx = -1;
}

unsigned dcBF_addShape( SDC_Broadphase* bf, SDC_Shape* shape )
{
    if( bf->freeEntry != -1 )
    {
        unsigned retVal = bf->freeEntry;
        bf->freeEntry = bf->entries[retVal].idx;
        bf->entries[retVal].bAlive = 1;
        bf->entries[retVal].idx = bf->numShapes;
        bf->shapes[bf->numShapes] = *shape;
        bf->shapes[bf->numShapes].shapeId = retVal;
        bf->numShapes++;
        return retVal;
    }
    return -1;
}

void dcBF_removeShape( SDC_Broadphase* bf, unsigned shapeId )
{
    unsigned shapeIdx = bf->entries[shapeId].idx;
    bf->shapes[shapeIdx] = bf->shapes[bf->numShapes - 1];
    bf->entries[bf->shapes[shapeIdx].shapeId].idx = shapeIdx;
    bf->numShapes--;
    bf->entries[shapeId].bAlive = 0;
    bf->entries[shapeId].idx = bf->freeEntry;
    bf->freeEntry = shapeId;
}
//   ST_SPHERE,
 //   ST_OOBB,
  //  ST_AABB
void dcBF_scrollAllShapes(SDC_Broadphase* bf, long offset )
{
    for (int i = 0 ; i< bf->numShapes ; ++i)
    {
        if (bf->shapes[i].shapeType == ST_SPHERE)
        {
            bf->shapes[i].sphere.center.vz -= offset;
        }
        if (bf->shapes[i].shapeType == ST_OOBB)
        {
            bf->shapes[i].oobb.center.vz -= offset;
        }
        if (bf->shapes[i].shapeType == ST_AABB)
        {
            bf->shapes[i].aabb.vmax.vz -= offset;
            bf->shapes[i].aabb.vmin.vz -= offset;
        }
    };
}

void dcBF_moveShape( SDC_Broadphase* bf, unsigned shapeId, SVECTOR* newPos )
{

}

SDC_Shape* dcBF_shapeCollides( SDC_Broadphase* bf, SDC_Shape* shape , SDC_Render* DebugRenderer, SDC_Camera* camera)
{
    //DRAW DEBUG
    #ifdef DEBUGCOLLISIONS
    if (DebugRenderer && shape->shapeType == ST_SPHERE)
    {
        SVECTOR min = { -shape->sphere.radius, -shape->sphere.radius, -shape->sphere.radius};
        SVECTOR max = { shape->sphere.radius, shape->sphere.radius,  shape->sphere.radius};

        CVECTOR drawColor = {255,255,60};
        MATRIX transform;
        transform.t[0] = shape->sphere.center.vx;
        transform.t[1] = shape->sphere.center.vy;
        transform.t[2] = shape->sphere.center.vz;
        SVECTOR zeroRot = {0};
        RotMatrix(&zeroRot, &transform);
        dcCamera_ApplyCameraTransform(camera, &transform, &transform);
        
        DrawCollBox(min, max, &transform, DebugRenderer, camera, &drawColor);
    }
    #endif


    for(int i = 0; i < bf->numShapes; ++i)
    {
        //printf("%d - OOBB at: ( %d, %d, %d )\n", i, bf->shapes[i].oobb.center.vx, bf->shapes[i].oobb.center.vy, bf->shapes[i].oobb.center.vz );
        if( dcCollision_shapesCollide(&bf->shapes[i], shape, DebugRenderer,camera) )
        {
            return &bf->shapes[i];
        }
    }
    return NULL;
}

int dcCollision_shapesCollide(SDC_Shape* shapeA, SDC_Shape* shapeB, SDC_Render* DebugRenderer, SDC_Camera* camera)
{
    // int swap = shapeA->shapeType > shapeB->shapeType;
    // if(swap)
    // {
    //     SDC_Shape* aux = shapeA;
    //     shapeA = shapeB;
    //     shapeB = aux;
    // }

    if(shapeB->shapeType != ST_SPHERE )
    {
        return 0;
    }

    switch(shapeA->shapeType)
    {
        case ST_AABB:
        {
            VECTOR center = 
            {
                .vx = (shapeA->aabb.vmin.vx + shapeA->aabb.vmax.vx) >> 1,
                .vy = (shapeA->aabb.vmin.vy + shapeA->aabb.vmax.vy) >> 1,
                .vz = (shapeA->aabb.vmin.vz + shapeA->aabb.vmax.vz) >> 1
            };
            VECTOR halfSize = 
            {
                .vx = shapeA->aabb.vmax.vx - center.vx,
                .vy = shapeA->aabb.vmax.vy - center.vy,
                .vz = shapeA->aabb.vmax.vz - center.vz
            };
            return dcCollision_SphereAABBOverlap(&halfSize, &center, &shapeB->sphere.center, shapeB->sphere.radius) < 0;
        }
        case ST_OOBB:
        {
            MATRIX m = {0};
            SVECTOR invRot = {-shapeA->oobb.rotation.vx, -shapeA->oobb.rotation.vy, -shapeA->oobb.rotation.vz};
            VECTOR invTrans = {-shapeA->oobb.center.vx, -shapeA->oobb.center.vy, -shapeA->oobb.center.vz};
            
            RotMatrix(&invRot, &m );
            TransMatrix( &m, &invTrans );

            #ifdef DEBUGCOLLISIONS
                DrawOOBBDebug(&shapeA->oobb,DebugRenderer,camera);
            #endif

            return dcCollision_SphereBOXOverlap(&shapeA->oobb.halfSize, &m, &shapeB->sphere.center, shapeB->sphere.radius) < 0;
        }
        case ST_SPHERE:
        {
            return dcCollision_SpheresOverlap( &shapeA->sphere.center, &shapeB->sphere.center, shapeA->sphere.radius, shapeB->sphere.radius ) < 0;
        }
    }

    return 0;
}



