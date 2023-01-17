
#ifndef _DC_COLLISION_H
#define _DC_COLLISION_H

#include <stddef.h>
#include <libgte.h>
#include "dcRender.h"
#include "dcCamera.h"

/* RAY INTERSECTIONS */

long dcCollision_RaySphereInteresct( VECTOR* rayOrigin, SVECTOR* rayDir, VECTOR* sphereCenter, long sphereRadius );
long dcCollision_RayPlaneInteresct( VECTOR* rayOrigin, SVECTOR* rayDir, SVECTOR* planeNormal, long planeHeight );
long dcCollision_RayAABBInteresct( VECTOR* rayOrigin, SVECTOR* rayDir, VECTOR* boxHalfSize, VECTOR* boxCenter );
long dcCollision_RayBOXInteresct( VECTOR* rayOrigin, SVECTOR* rayDir, VECTOR* boxHalfSize, MATRIX* boxTransform );

/* SHAPE OVERLAPS */

long dcCollision_SpheresOverlap( VECTOR* sphere1Center, VECTOR* sphere2center, long sphere1Radius, long sphere2Radius );

long dcCollision_SphereAABBOverlap( VECTOR* boxHalfSize, VECTOR* boxCenter, VECTOR* sphereCenter, long sphereRadius );
long dcCollision_SphereBOXOverlap( VECTOR* boxHalfSize, MATRIX* boxInvTransform,  VECTOR* sphereCenter, long sphereRadius );


typedef enum
{
    ST_SPHERE,
    ST_OOBB,
    ST_AABB

} EDC_ShapeType;

typedef struct
{
    VECTOR center;
    VECTOR halfSize;
    SVECTOR rotation;
    int userData;
} SDC_OOBB;

typedef struct
{
    VECTOR center;
    long radius;

} SDC_Sphere;

typedef struct
{
    VECTOR vmin;
    VECTOR vmax;

} SDC_AABB;

typedef struct 
{
    EDC_ShapeType shapeType;
    union
    {
        SDC_AABB aabb;
        SDC_OOBB oobb;
        SDC_Sphere sphere;
    };
    unsigned shapeId;
    int userData;
} SDC_Shape;

typedef struct
{
    unsigned idx : 31;
    unsigned bAlive : 1;

} SDC_ShapeEntry;

typedef struct
{
    SDC_Shape* shapes;
    SDC_ShapeEntry* entries;
    unsigned numShapes;
    unsigned maxShapes;
    unsigned freeEntry;

} SDC_Broadphase;

void dcBF_Init(SDC_Broadphase* bf, unsigned maxShapes);
unsigned dcBF_addShape( SDC_Broadphase* bf, SDC_Shape* shape );
void dcBF_removeShape( SDC_Broadphase* bf, unsigned shapeId );
void dcBF_scrollAllShapes(SDC_Broadphase* bf, long offset );
void dcBF_moveShape( SDC_Broadphase* bf, unsigned shapeId, SVECTOR* newPos );
SDC_Shape* dcBF_shapeCollides( SDC_Broadphase* bf, SDC_Shape* shape , SDC_Render* DebugRenderer, SDC_Camera* camera);
int dcCollision_shapesCollide(SDC_Shape* shapeA, SDC_Shape* shapeB, SDC_Render* DebugRenderer, SDC_Camera* camera);


#endif /* _DC_COLLISION_H */
