#include "dcRender.h"
#include <malloc.h>
#include <libetc.h>
#include <stdio.h>
#include <assert.h>
#include <memory.h>
#include "dcCamera.h"
#include "dcLevel.h"

int totalPrimitives = 0;

void _dcRender_IncPrimitive(SDC_Render* render, size_t offset)
{
    render->nextPrimitive += offset;
    ++totalPrimitives;
}

void _dcRender_ReportPrimitivesSize(SDC_Render* render) {
    u_char* base_ptr = render->primitives[render->doubleBufferIndex];
    size_t nbytes = sizeof(u_char) * render->bytesPrimitives;
    size_t curr_offset = render->nextPrimitive - base_ptr; 
    printf("Primitives bytes '%d/%d' totalPrimitives %d\n", curr_offset, nbytes, totalPrimitives);
    totalPrimitives = 0;
}

void dcRender_Init(SDC_Render* render, int width, int height, CVECTOR bgColor, int orderingTableCount, int bytesPrimitives, EDC_Mode mode, int bFirstInit) {
	if(bFirstInit)
    {
    InitGeom();

    ResetGraph( 0 );
    SetGraphDebug(0);
    }
    render->orderingTableCount = orderingTableCount;
    render->bytesPrimitives = bytesPrimitives;
    render->doubleBufferIndex = 0;
    render->width = width;
    render->height = height;
    render->bgColor = bgColor;

    render->orderingTable[0] = (u_long*)malloc3(sizeof(u_long) * orderingTableCount);
    render->orderingTable[1] = (u_long*)malloc3(sizeof(u_long) * orderingTableCount);
    
    ClearOTagR( render->orderingTable[0], orderingTableCount );
    ClearOTagR( render->orderingTable[1], orderingTableCount );
    
    render->primitives[0] = (u_char*)malloc3(sizeof(u_char) * bytesPrimitives);
    render->primitives[1] = (u_char*)malloc3(sizeof(u_char) * bytesPrimitives);
    
    render->nextPrimitive = render->primitives[0];

if(bFirstInit)
{
    SetDefDrawEnv( &render->drawEnvironment[0],    0, 0,      width/2, height );
    SetDefDrawEnv( &render->drawEnvironment[1],    0, height, width/2, height );

    SetDefDispEnv( &render->displayEnvironment[0], 0, height, width, height );
    SetDefDispEnv( &render->displayEnvironment[1], 0, 0,      width, height );
}
else
{
    SetDefDrawEnv( &render->drawEnvironment[0],    width/2, 0,      width/2, height );
    SetDefDrawEnv( &render->drawEnvironment[1],    width/2, height,       width/2, height );

    SetDefDispEnv( &render->displayEnvironment[0], 0, height,       width, height );
    SetDefDispEnv( &render->displayEnvironment[1], 0, 0,      width, height );
}
    setRGB0( &render->drawEnvironment[0], bgColor.r, bgColor.g, bgColor.b );
    render->drawEnvironment[0].isbg = 1;
    render->drawEnvironment[0].dtd = 1;
    render->displayEnvironment[0].isinter = 1;

    setRGB0( &render->drawEnvironment[1], bgColor.r, bgColor.g, bgColor.b );
    render->drawEnvironment[1].isbg = 1;
    render->drawEnvironment[1].dtd = 1;
    render->displayEnvironment[1].isinter = 1;
	if(bFirstInit)
    {
    SetDispMask(1);    
	// Set GTE offset (recommended method  of centering)
    SetGeomOffset((width/2)>>1, height>>1);
	// Set screen depth (basically FOV control, W/2 works best)
	SetGeomScreen((width/2) >> 1);
    SetVideoMode(mode==RENDER_MODE_NTCS?MODE_NTSC:MODE_PAL);


    //Debug font (to remove)
    FntLoad(960, 256);
    SetDumpFnt(FntOpen(16, 16, 320, 64, 0, 512));
    }
        if(mode==RENDER_MODE_PAL) {
        render->displayEnvironment[0].screen.y += 8;
        render->displayEnvironment[1].screen.y += 8;
    }
    PutDispEnv( &render->displayEnvironment[render->doubleBufferIndex] );
    PutDrawEnv( &render->drawEnvironment[render->doubleBufferIndex] );

    dcRender_ResetLights(render);
   
}

void dcRender_ResetLights(SDC_Render* render)
{
    memset(&render->lightColorMatrix, 0, sizeof(MATRIX));
    memset(&render->lightDirMatrix, 0, sizeof(MATRIX));

    SetLightMatrix(&render->lightDirMatrix);
    SetColorMatrix(&render->lightColorMatrix);
}

void dcRender_SetLight(SDC_Render* render, u_short lightIdx, const SVECTOR* lightDirection, const SVECTOR* lightColor)
{
    render->lightColorMatrix.m[0][lightIdx] = lightColor->vx;
    render->lightColorMatrix.m[1][lightIdx] = lightColor->vy;
    render->lightColorMatrix.m[2][lightIdx] = lightColor->vz;

    render->lightDirMatrix.m[lightIdx][0] = lightDirection->vx;
    render->lightDirMatrix.m[lightIdx][1] = lightDirection->vy;
    render->lightDirMatrix.m[lightIdx][2] = lightDirection->vz;

    SetLightMatrix(&render->lightDirMatrix);
    SetColorMatrix(&render->lightColorMatrix);
}

void dcRender_SetAmbientColor(SDC_Render* render, CVECTOR* ambientColor)
{
    render->ambientColor = *ambientColor;
    SetBackColor(render->ambientColor.r, render->ambientColor.g, render->ambientColor.b);
}

void dcRender_SwapBuffers(SDC_Render* render) {
    // _dcRender_ReportPrimitivesSize(render);

    
    render->doubleBufferIndex = !render->doubleBufferIndex;    
     ClearImage(&render->drawEnvironment[render->doubleBufferIndex].clip,60, 120, 120);
    PutDrawEnv( &render->drawEnvironment[render->doubleBufferIndex] );
    PutDispEnv( &render->displayEnvironment[render->doubleBufferIndex] );
    
    DrawOTag( render->orderingTable[!render->doubleBufferIndex]+(render->orderingTableCount-1) );
    FntFlush(-1); // Font Debug
    
    ClearOTagR( render->orderingTable[render->doubleBufferIndex], render->orderingTableCount );
    render->nextPrimitive = render->primitives[render->doubleBufferIndex];    
}

void dcRender_LoadTexture(TIM_IMAGE* tim, u_long* texture) {
    OpenTIM(texture);                            // Open the tim binary data, feed it the address of the data in memory
    ReadTIM(tim);                                // This read the header of the TIM data and sets the corresponding members of the TIM_IMAGE structure

    LoadImage( tim->prect, tim->paddr );        // Transfer the data from memory to VRAM at position prect.x, prect.y

    if( tim->mode & 0x8 ) {                     // check 4th bit       // If 4th bit == 1, TIM has a CLUT
        LoadImage( tim->crect, tim->caddr );    // Load it to VRAM at position crect.x, crect.y
    }
    DrawSync(0);                                // Wait for drawing to end
}

void dcRender_DrawSpriteRect(SDC_Render* render, const TIM_IMAGE *tim, short x, short y, short w, short h, const DVECTOR *uv, const CVECTOR *color) {
    SPRT *sprt = (SPRT*)render->nextPrimitive;

    setSprt(sprt);
    setXY0(sprt, x, y);
    setWH(sprt, w, h);
    setRGB0(sprt, color->r, color->g, color->b);
    setUV0(sprt, uv->vx, uv->vy);
    setClut(sprt, tim->crect->x, tim->crect->y);

    addPrim(render->orderingTable[render->doubleBufferIndex], sprt);

    _dcRender_IncPrimitive(render, sizeof(SPRT));

    DR_TPAGE *tpri = (DR_TPAGE*)render->nextPrimitive;
    u_short tpage = getTPage(tim->mode, 0, tim->prect->x, tim->prect->y);
    setDrawTPage(tpri, 0, 0, tpage);
    addPrim(render->orderingTable[render->doubleBufferIndex], tpri);
    _dcRender_IncPrimitive(render, sizeof(DR_TPAGE));
}

// #pragma GCC push_options
// #pragma GCC optimize ("O0")

void dcRender_DrawMesh(SDC_Render* render,  SDC_Mesh3D* mesh, MATRIX* transform, SDC_DrawParams* drawParams) 
{
    assert(render && mesh && transform);
    u_long *orderingTable = render->orderingTable[render->doubleBufferIndex];
    int orderingTableCount = render->orderingTableCount;
    long p, otz, flg;
    int nclip;

    SetRotMatrix(transform);
    SetTransMatrix(transform);

    CVECTOR* color = drawParams && drawParams->bUseConstantColor ? &drawParams->constantColor : NULL;
    
        CVECTOR curr_color = {255, 255, 255};

        POLY_GT3* polyGT3; 
        u_short index0;
        u_short index1;
        u_short index2;

        SDC_VertexTexturedNormal *vertexs = (SDC_VertexTexturedNormal *)mesh->vertexs;
    for (int i = 0; i < mesh->numIndices; i += 3) {               
        index0 = mesh->indices[i];
        index1 = mesh->indices[i+1];
        index2 = mesh->indices[i+2];
        if(color) 
            curr_color = *color;

        polyGT3 = (POLY_GT3*)render->nextPrimitive;
                SetPolyGT3(polyGT3);

                if(drawParams && drawParams->tim) {                    
                    polyGT3->tpage = getTPage(drawParams->tim->mode, 0, drawParams->tim->prect->x, drawParams->tim->prect->y);/*texture page*/
                    setClut(polyGT3,drawParams->tim->crect->x, drawParams->tim->crect->y);
                }
                nclip = RotAverageNclip3(&vertexs[index0].position, &vertexs[index1].position, &vertexs[index2].position,
                                        (long *)&polyGT3->x0, (long *)&polyGT3->x1, (long *)&polyGT3->x2, &p, &otz, &flg);
                               
                if (nclip <= 0) continue;
                if (((otz <= 0) || (otz >= orderingTableCount)) && !mesh->CheckDraw) continue;


                setRGB0(polyGT3, curr_color.r, curr_color.g, curr_color.b);
                setRGB1(polyGT3, curr_color.r, curr_color.g, curr_color.b);
                setRGB2(polyGT3, curr_color.r, curr_color.g, curr_color.b);

                if(mesh->polygonVertexType == POLIGON_VERTEX_TEXTURED_NORMAL)
                 {
                setUV3(polyGT3, vertexs[index0].u , vertexs[index0].v, vertexs[index1].u , vertexs[index1].v, vertexs[index2].u , vertexs[index2].v);
                 }
                 else
                 {
                    setRGB0(polyGT3, 128, 128, 128);
                    setRGB1(polyGT3, 128, 128, 128);
                    setRGB2(polyGT3, 128, 128, 128);
                 }

				addPrim(&orderingTable[otz], polyGT3);
                _dcRender_IncPrimitive(render, sizeof(POLY_GT3));       
        }
    }


void dcRender_DrawLine(SDC_Render* render, SVECTOR* v0, SVECTOR* v1, MATRIX* transform, CVECTOR* color, u_short segments )
{
    
    assert(render && v0 && v1 && transform && segments > 0);
    u_long *orderingTable = render->orderingTable[render->doubleBufferIndex];
    int orderingTableCount = render->orderingTableCount;
    long p, flg;

    SetRotMatrix(transform);
    SetTransMatrix(transform);
    
    CVECTOR curr_color = {255, 255, 255};

    if(color) 
    {
        curr_color = *color;
    }

    short xDelta = (v1->vx - v0->vx) / segments;
    short yDelta = (v1->vy - v0->vy) / segments;
    short zDelta = (v1->vz - v0->vz) / segments;

    SVECTOR p0 = *v0;

    for(u_short i = 0; i < segments; ++ i)
    {
        SVECTOR p1 = {p0.vx + xDelta, p0.vy + yDelta, p0.vz + zDelta};

        void *poly = render->nextPrimitive;
        LINE_F2* lineF2 = (LINE_F2*)poly;
        SetLineF2(lineF2);
        long otz = RotTransPers(&p0, (long*)&lineF2->x0, &p, &flg);
        long otz1 = RotTransPers(&p1, (long*)&lineF2->x1, &p, &flg);

        otz = (otz + otz1) >> 1;

        p0 = p1;
        if ((otz < 0) || (otz >= orderingTableCount)) continue;

        setRGB0(lineF2, curr_color.r, curr_color.g, curr_color.b);
        addPrim(orderingTable[otz], lineF2);
        _dcRender_IncPrimitive(render, sizeof(LINE_F2)); 
    }
}


void dcRender_PreDrawMesh(SDC_Level* Level, SDC_Camera* Camera, VECTOR *Location, SVECTOR *Rotation, MATRIX *Transform)
{
    return;
    RotMatrix_gte(&Level->LightAngle, &Level->RotLight);
        RotMatrix_gte(Rotation, &Level->RotObject);  
        // RotMatrix cube * RotMatrix light
        MulMatrix0(&Level->RotObject, &Level->RotLight, &Level->RotLight);
        // Light Matrix * RotMatrix light 
        MulMatrix0(&Level->LocalLightMatrix, &Level->RotLight, &Level->WorldLightMatrix);
        // Set new light matrix 
        SetLightMatrix(&Level->WorldLightMatrix);

}

//#pragma GCC pop_options
