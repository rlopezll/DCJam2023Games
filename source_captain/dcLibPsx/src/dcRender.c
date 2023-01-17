#include "dcRender.h"
#include <malloc.h>
#include <libetc.h>
#include <stdio.h>
#include <assert.h>
#include <memory.h>
#include "dcMath.h"

int totalPrimitives = 0;

static inline void _dcRender_IncPrimitive(SDC_Render* render, size_t offset)
{
    //u_char* base_ptr = render->primitives[render->doubleBufferIndex];
    // size_t nbytes = sizeof(u_char) * render->bytesPrimitives;
    // size_t curr_offset = render->nextPrimitive - base_ptr; 
    // if( curr_offset + offset >= nbytes) {
    //     printf("Error!! Limit Primitives bytes '%d/%d'\n", curr_offset + offset, nbytes);
    // }
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

void dcRender_Init(SDC_Render* render, int width, int height, CVECTOR bgColor, int orderingTableCount, int bytesPrimitives, EDC_Mode mode) {
	InitGeom();

    ResetGraph( 0 );
    SetGraphDebug(0);

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

    SetDefDrawEnv( &render->drawEnvironment[0],    0, 0,      width, height );
    SetDefDrawEnv( &render->drawEnvironment[1],    0, height, width, height );

    SetDefDispEnv( &render->displayEnvironment[0], 0, height, width, height );
    SetDefDispEnv( &render->displayEnvironment[1], 0, 0,      width, height );

    setRGB0( &render->drawEnvironment[0], bgColor.r, bgColor.g, bgColor.b );
    render->drawEnvironment[0].isbg = 0;
    render->drawEnvironment[0].dtd = 1;
    render->displayEnvironment[0].isinter = 0;

    setRGB0( &render->drawEnvironment[1], bgColor.r, bgColor.g, bgColor.b );
    render->drawEnvironment[1].isbg = 0;
    render->drawEnvironment[1].dtd = 1;
    render->displayEnvironment[1].isinter = 0;

    SetDispMask(1);    
	// Set GTE offset (recommended method  of centering)
    SetGeomOffset(width>>1, height>>1);
	// Set screen depth (basically FOV control, W/2 works best)
	SetGeomScreen(width >> 1);
    SetVideoMode(mode==RENDER_MODE_NTCS?MODE_NTSC:MODE_PAL);

    //Debug font (to remove)
    FntLoad(960, 256);
    SetDumpFnt(FntOpen(16, 16, 320, 64, 0, 512));
        
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
    
    DrawSync( 0 );
    VSync( 0 );
    SetDispMask( 1 );
    
    render->doubleBufferIndex = !render->doubleBufferIndex;
    
    ClearImage(&render->drawEnvironment[render->doubleBufferIndex].clip, render->bgColor.r, render->bgColor.g, render->bgColor.b);

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

void dcRender_DrawSpriteRect(SDC_Render* render, SDC_Texture* texture, short x, short y, short w, short h, const DVECTOR *uv, const CVECTOR *color) {
    SPRT *sprt = (SPRT*)render->nextPrimitive;

    // X align 64 -> 6
    // Y align 256 --> 8
    u_short tpageX = texture->prect.x & ~0x003f;
    u_short tpageY = texture->prect.y & ~0x00ff;

    setSprt(sprt);
    setXY0(sprt, x, y);
    setWH(sprt, w, h);
    setRGB0(sprt, color->r, color->g, color->b);
    setUV0(sprt, uv->vx + (texture->prect.x & 0x003f), uv->vy + (texture->prect.y & 0x00ff));
    setClut(sprt, texture->crect.x, texture->crect.y);

    addPrim(render->orderingTable[render->doubleBufferIndex], sprt);

    _dcRender_IncPrimitive(render, sizeof(SPRT));

    DR_TPAGE *tpri = (DR_TPAGE*)render->nextPrimitive;

    u_short tpage = getTPage(texture->mode, 0, tpageX, tpageY);
    setDrawTPage(tpri, 0, 0, tpage);
    addPrim(render->orderingTable[render->doubleBufferIndex], tpri);
    _dcRender_IncPrimitive(render, sizeof(DR_TPAGE));
}

void dcRender_DrawSpriteBg(SDC_Render* render, SDC_Texture* texture, short x, short y, short w, short h, const DVECTOR *uv, const CVECTOR *color)
{
    SPRT *sprt = (SPRT*)render->nextPrimitive;

    setSprt(sprt);
    setXY0(sprt, x, y);
    setWH(sprt, w, h);
    setRGB0(sprt, color->r, color->g, color->b);
    setUV0(sprt, uv->vx, uv->vy);
    setClut(sprt, texture->crect.x, texture->crect.y);

    addPrim(render->orderingTable[render->orderingTableCount - 1], sprt);

    _dcRender_IncPrimitive(render, sizeof(SPRT));

    DR_TPAGE *tpri = (DR_TPAGE*)render->nextPrimitive;
    u_short tpage = getTPage(texture->mode, 0, texture->prect.x, texture->prect.y);
    setDrawTPage(tpri, 0, 0, tpage);
    addPrim(render->orderingTable[render->orderingTableCount - 1], tpri);
    _dcRender_IncPrimitive(render, sizeof(DR_TPAGE));
}

// #pragma GCC push_options
// #pragma GCC optimize ("O0")

#define CALC_WARP_Y(z, maxYoffset) (DC_LERP(0, (maxYoffset), DC_MUL((z), (z))))
#define WARP_POLY_Y(p3, z, maxYOffset) { short yWarpOffset = CALC_WARP_Y(z, maxYOffset); p3->y0 += yWarpOffset; p3->y1 += yWarpOffset; p3->y2 += yWarpOffset; }

typedef void (*VertexRenderFunction)(SDC_Mesh3D* mesh, SDC_Render* render, CVECTOR* color);

void DrawPolyVertex(SDC_Mesh3D* mesh, SDC_Render* render, CVECTOR* color)
{
    CVECTOR curr_color = {255, 255, 255};
    if(color) 
        curr_color = *color;

    for (int i = 0; i < mesh->numIndices; i += 3) {
        u_short index0 = mesh->indices[i];
        u_short index1 = mesh->indices[i+1];
        u_short index2 = mesh->indices[i+2];
        // assert(index0 < mesh->numVertices);
        // assert(index1 < mesh->numVertices);
        // assert(index2 < mesh->numVertices);
        void *poly = render->nextPrimitive;  

        u_long *orderingTable = render->orderingTable[render->doubleBufferIndex];
        int orderingTableCount = render->orderingTableCount;
        long p, otz, flg;
        int nclip;

        POLY_F3* polyF3 = (POLY_F3*)poly;
        setPolyF3(polyF3);
        SDC_Vertex *vertexs = (SDC_Vertex *)mesh->vertexs;
        nclip = RotAverageNclip3(&vertexs[index0].position, &vertexs[index1].position, &vertexs[index2].position,
            (long *)&polyF3->x0, (long *)&polyF3->x1, (long *)&polyF3->x2, &p, &otz, &flg);

        
        setRGB0(polyF3, curr_color.r, curr_color.g, curr_color.b);

        if (nclip <= 0) continue;
        if ((otz <= 0) || (otz >= orderingTableCount)) continue;

        addPrim(orderingTable[otz], polyF3);
        _dcRender_IncPrimitive(render, sizeof(POLY_F3));
    }
}

void DrawPolyVertexTextured(SDC_Mesh3D* mesh, SDC_Render* render, CVECTOR* color)
{
    u_short clut = getClut(mesh->textureData.crect.x, mesh->textureData.crect.y); /*texture CLUT*/

    u_short tpage = getTPage(mesh->textureData.mode, 0, mesh->textureData.prect.x & ~0x3f, mesh->textureData.prect.y & ~0xff); /*texture page*/
    u_long *orderingTable = render->orderingTable[render->doubleBufferIndex];
    int orderingTableCount = render->orderingTableCount;

    short u_off = mesh->textureData.prect.x & 0x3f;
    short v_off = mesh->textureData.prect.y & 0xff;

    for (int i = 0; i < mesh->numIndices; i += 3) {
        u_short index0 = mesh->indices[i];
        u_short index1 = mesh->indices[i+1];
        u_short index2 = mesh->indices[i+2];
        void *poly = render->nextPrimitive;

        long p, otz, flg;
        int nclip;

        POLY_FT3* polyFT3 = (POLY_FT3*)poly;
        SDC_VertexTextured *vertexs = (SDC_VertexTextured *)mesh->vertexs;

        nclip = RotAverageNclip3(&vertexs[index0].position, &vertexs[index1].position, &vertexs[index2].position,
                                (long *)&polyFT3->x0, (long *)&polyFT3->x1, (long *)&polyFT3->x2, &p, &otz, &flg);
        if (nclip <= 0) continue;
        if ((otz <= 0) || (otz >= orderingTableCount)) continue;

        setPolyFT3(polyFT3);
        setRGB0(polyFT3, 128, 128, 128);
        setUV3(polyFT3, vertexs[index0].u + u_off, vertexs[index0].v + v_off, vertexs[index1].u + u_off, vertexs[index1].v + v_off, vertexs[index2].u + u_off, vertexs[index2].v + v_off);
        polyFT3->tpage = tpage;
        polyFT3->clut = clut;

        WARP_POLY_Y(polyFT3, otz, 64)
        addPrim(&orderingTable[otz], polyFT3);

        _dcRender_IncPrimitive(render, sizeof(POLY_FT3));
    }
}

// TODO implement other functions if needed
VertexRenderFunction vertexRenderFunctions[] = {
    &DrawPolyVertex, //    POLIGON_VERTEX,
    &DrawPolyVertex, //    POLIGON_VERTEX_COLOR,
    &DrawPolyVertex, //    POLIGON_VERTEX_NORMAL,  //Gouraud-shaded
    &DrawPolyVertex, //    POLIGON_VERTEX_COLOR_NORMAL,  //Gouraud-shaded
    &DrawPolyVertexTextured, //    POLIGON_VERTEX_TEXTURED,
    &DrawPolyVertex, //    POLIGON_VERTEX_TEXTURED_COLOR, //Gouraud-shaded
    &DrawPolyVertex //    POLIGON_VERTEX_TEXTURED_NORMAL //Gouraud-shaded (TODO)
};

void dcRender_DrawMesh(SDC_Render* render,  SDC_Mesh3D* mesh, MATRIX* transform, SDC_DrawParams* drawParams) 
{
    // assert(render && mesh && transform);
    u_long *orderingTable = render->orderingTable[render->doubleBufferIndex];
    int orderingTableCount = render->orderingTableCount;
    long p, otz, flg;
    int nclip;

    SetRotMatrix(transform);
    SetTransMatrix(transform);

    const u_short bLighting = drawParams && drawParams->bLighting;
    CVECTOR* color = drawParams && drawParams->bUseConstantColor ? &drawParams->constantColor : NULL;

    VertexRenderFunction renderFunction = vertexRenderFunctions[mesh->polygonVertexType];
    renderFunction(mesh, render, color);

    /// We don't do these things below as they are slow
    return;

    for (int i = 0; i < mesh->numIndices; i += 3) {               
        u_short index0 = mesh->indices[i];
        u_short index1 = mesh->indices[i+1];
        u_short index2 = mesh->indices[i+2];
        // assert(index0 < mesh->numVertices);
        // assert(index1 < mesh->numVertices);
        // assert(index2 < mesh->numVertices);
        void *poly = render->nextPrimitive;  

        CVECTOR c0, c1, c2;  
        CVECTOR curr_color = {255, 255, 255};
        if(color) 
            curr_color = *color;

        switch(mesh->polygonVertexType)
        {
            case POLIGON_VERTEX:
            {
                POLY_F3* polyF3 = (POLY_F3*)poly;
                SetPolyF3(polyF3);
                SDC_Vertex *vertexs = (SDC_Vertex *)mesh->vertexs;
                nclip = RotAverageNclip3(&vertexs[index0].position, &vertexs[index1].position, &vertexs[index2].position,
                    (long *)&polyF3->x0, (long *)&polyF3->x1, (long *)&polyF3->x2, &p, &otz, &flg);
                setRGB0(polyF3, curr_color.r, curr_color.g, curr_color.b);

                if (nclip <= 0) continue;
                if ((otz <= 0) || (otz >= orderingTableCount)) continue;

				addPrim(orderingTable[otz], polyF3);
                _dcRender_IncPrimitive(render, sizeof(POLY_F3));
            }
            break;
            case POLIGON_VERTEX_COLOR:
            {
                POLY_G3* polyG3 = (POLY_G3*)poly;
                SDC_VertexColor *vertexs = (SDC_VertexColor *)mesh->vertexs;

                SetPolyG3(polyG3);
                if(color) {
                    setRGB0(polyG3, color->r, color->g, color->b);
                    setRGB1(polyG3, color->r, color->g, color->b);
                    setRGB2(polyG3, color->r, color->g, color->b);
                }
                else {
                    setRGB0(polyG3, vertexs[index0].color.r, vertexs[index0].color.g, vertexs[index0].color.b);
                    setRGB1(polyG3, vertexs[index1].color.r, vertexs[index1].color.g, vertexs[index1].color.b);
                    setRGB2(polyG3, vertexs[index2].color.r, vertexs[index2].color.g, vertexs[index2].color.b);
                }

                nclip = RotAverageNclip3(&vertexs[index0].position, &vertexs[index1].position, &vertexs[index2].position,
                                        (long *)&polyG3->x0, (long *)&polyG3->x1, (long *)&polyG3->x2, &p, &otz, &flg);
                if (nclip <= 0) continue;
                if ((otz <= 0) || (otz >= orderingTableCount)) continue;

				addPrim(&orderingTable[otz], polyG3);
                _dcRender_IncPrimitive(render, sizeof(POLY_G3));
            }
            break;
            case POLIGON_VERTEX_COLOR_NORMAL:
            {
                POLY_G3* polyG3 = (POLY_G3*)poly;
                SDC_VertexColorNormal *vertexs = (SDC_VertexColorNormal *)mesh->vertexs;

                SetPolyG3(polyG3);

                if(bLighting)
                {
                    nclip = RotAverageNclipColorCol3
                    (
                        &vertexs[index0].position, &vertexs[index1].position, &vertexs[index2].position, // positions
                        &vertexs[index0].normal, &vertexs[index1].normal, &vertexs[index2].normal, // normals
                        color ? color : &vertexs[index0].color, // input color
                        (long *)&polyG3->x0, (long *)&polyG3->x1, (long *)&polyG3->x2, // out 2d positions
                        &c0, &c1, &c2, // out colors
                        &otz, &flg
                    );
                    
                    /**
                     * TODO: we could pass white as input color to the above function and then multiply the output colors 
                     * by each vertex color to get different colors per vertex.
                    */

                    setRGB0(polyG3, c0.r, c0.g, c0.b);
                    setRGB1(polyG3, c1.r, c1.g, c1.b);
                    setRGB2(polyG3, c2.r, c2.g, c2.b);
                }
                else
                {
                    nclip = RotAverageNclip3(&vertexs[index0].position, &vertexs[index1].position, &vertexs[index2].position,
                                            (long *)&polyG3->x0, (long *)&polyG3->x1, (long *)&polyG3->x2, &p, &otz, &flg);

                    if(color) {
                        setRGB0(polyG3, color->r, color->g, color->b);
                        setRGB1(polyG3, color->r, color->g, color->b);
                        setRGB2(polyG3, color->r, color->g, color->b);
                    }
                    else {
                        setRGB0(polyG3, vertexs[index0].color.r, vertexs[index0].color.g, vertexs[index0].color.b);
                        setRGB1(polyG3, vertexs[index1].color.r, vertexs[index1].color.g, vertexs[index1].color.b);
                        setRGB2(polyG3, vertexs[index2].color.r, vertexs[index2].color.g, vertexs[index2].color.b);
                    }
                }

                if (nclip <= 0) continue;
                if ((otz <= 0) || (otz >= orderingTableCount)) continue;

				addPrim(&orderingTable[otz], polyG3);
                _dcRender_IncPrimitive(render, sizeof(POLY_G3));

            } break;
            case POLIGON_VERTEX_NORMAL:
            {
                POLY_G3* polyG3 = (POLY_G3*)poly;
                SDC_VertexNormal *vertexs = (SDC_VertexNormal *)mesh->vertexs;

                SetPolyG3(polyG3);

                if(bLighting)
                {
                    nclip = RotAverageNclipColorCol3
                    (
                        &vertexs[index0].position, &vertexs[index1].position, &vertexs[index2].position, // positions
                        &vertexs[index0].normal, &vertexs[index1].normal, &vertexs[index2].normal, // normals
                        &curr_color, // input color
                        (long *)&polyG3->x0, (long *)&polyG3->x1, (long *)&polyG3->x2, // out 2d positions
                        &c0, &c1, &c2, // out colors
                        &otz, &flg
                    );
                    
                    /**
                     * TODO: we could pass white as input color to the above function and then multiply the output colors 
                     * by each vertex color to get different colors per vertex.
                    */

                    setRGB0(polyG3, c0.r, c0.g, c0.b);
                    setRGB1(polyG3, c1.r, c1.g, c1.b);
                    setRGB2(polyG3, c2.r, c2.g, c2.b);
                }
                else
                {
                    nclip = RotAverageNclip3(&vertexs[index0].position, &vertexs[index1].position, &vertexs[index2].position,
                                            (long *)&polyG3->x0, (long *)&polyG3->x1, (long *)&polyG3->x2, &p, &otz, &flg);

                    setRGB0(polyG3, curr_color.r, curr_color.g, curr_color.b);
                    setRGB1(polyG3, curr_color.r, curr_color.g, curr_color.b);
                    setRGB2(polyG3, curr_color.r, curr_color.g, curr_color.b);
                }

                if (nclip <= 0) continue;
                if ((otz <= 0) || (otz >= orderingTableCount)) continue;

				addPrim(&orderingTable[otz], polyG3);
                _dcRender_IncPrimitive(render, sizeof(POLY_G3));

            } break;
            case POLIGON_VERTEX_TEXTURED:
            {
                POLY_FT3* polyFT3 = (POLY_FT3*)poly;
                SDC_VertexTextured *vertexs = (SDC_VertexTextured *)mesh->vertexs;

                SetPolyFT3(polyFT3);
                setRGB0(polyFT3, curr_color.r, curr_color.g, curr_color.b);
                setUV3(polyFT3, vertexs[index0].u , vertexs[index0].v, vertexs[index1].u , vertexs[index1].v, vertexs[index2].u , vertexs[index2].v);
                {
                    polyFT3->tpage = getTPage(mesh->textureData.mode, 0, mesh->textureData.prect.x, mesh->textureData.prect.y); /*texture page*/
                    polyFT3->clut = GetClut (mesh->textureData.crect.x, mesh->textureData.crect.y); /*texture CLUT*/
                }



                nclip = RotAverageNclip3(&vertexs[index0].position, &vertexs[index1].position, &vertexs[index2].position,
                                        (long *)&polyFT3->x0, (long *)&polyFT3->x1, (long *)&polyFT3->x2, &p, &otz, &flg);
                if (nclip <= 0) continue;
                if ((otz <= 0) || (otz >= orderingTableCount)) continue;

                WARP_POLY_Y(polyFT3, otz, 64)
				addPrim(&orderingTable[otz], polyFT3);

                _dcRender_IncPrimitive(render, sizeof(POLY_FT3));
            }
            break;
            case POLIGON_VERTEX_TEXTURED_COLOR:
            {
                POLY_GT3* polyGT3 = (POLY_GT3*)poly;
                SDC_VertexColorTextured *vertexs = (SDC_VertexColorTextured *)mesh->vertexs;
                SetPolyGT3(polyGT3);

                setRGB0(polyGT3, curr_color.r, curr_color.g, curr_color.b);
                setRGB1(polyGT3, curr_color.r, curr_color.g, curr_color.b);
                setRGB2(polyGT3, curr_color.r, curr_color.g, curr_color.b);

                setUV3(polyGT3, vertexs[index0].u , vertexs[index0].v, vertexs[index1].u , vertexs[index1].v, vertexs[index2].u , vertexs[index2].v);

                nclip = RotAverageNclip3(&vertexs[index0].position, &vertexs[index1].position, &vertexs[index2].position,
                                        (long *)&polyGT3->x0, (long *)&polyGT3->x1, (long *)&polyGT3->x2, &p, &otz, &flg);
                if (nclip <= 0) continue;
                if ((otz <= 0) || (otz >= orderingTableCount)) continue;

				addPrim(&orderingTable[otz], polyGT3);
                _dcRender_IncPrimitive(render, sizeof(POLY_GT3));
            }
            break;
            case POLIGON_VERTEX_TEXTURED_NORMAL:
            {
                POLY_GT3* polyGT3 = (POLY_GT3*)poly;
                SDC_VertexTexturedNormal *vertexs = (SDC_VertexTexturedNormal *)mesh->vertexs;
                SetPolyGT3(polyGT3);

                nclip = RotAverageNclip3(&vertexs[index0].position, &vertexs[index1].position, &vertexs[index2].position,
                                        (long *)&polyGT3->x0, (long *)&polyGT3->x1, (long *)&polyGT3->x2, &p, &otz, &flg);
                if (nclip <= 0) continue;
                if ((otz <= 0) || (otz >= orderingTableCount)) continue;

                if(bLighting)
                {
                    NormalColorCol3(
                        &vertexs[index0].normal, &vertexs[index1].normal, &vertexs[index2].normal, // input normal
                        &curr_color, // input base color
                        &c0, &c1, &c2 // output colors
                    );
                    
                    setRGB0(polyGT3, c0.r, c0.g, c0.b);
                    setRGB1(polyGT3, c1.r, c1.g, c1.b);
                    setRGB2(polyGT3, c2.r, c2.g, c2.b);
                }
                else
                {
                    setRGB0(polyGT3, curr_color.r, curr_color.g, curr_color.b);
                    setRGB1(polyGT3, curr_color.r, curr_color.g, curr_color.b);
                    setRGB2(polyGT3, curr_color.r, curr_color.g, curr_color.b);
                }

                setUV3(polyGT3, vertexs[index0].u , vertexs[index0].v, vertexs[index1].u , vertexs[index1].v, vertexs[index2].u , vertexs[index2].v);
                if(drawParams && drawParams->tim) {
                    polyGT3->tpage = getTPage(drawParams->tim->mode, 0, drawParams->tim->prect->x, drawParams->tim->prect->y); /*texture page*/
                    polyGT3->clut = GetClut (drawParams->tim->crect->x, drawParams->tim->crect->y); /*texture CLUT*/
                }

				addPrim(&orderingTable[otz], polyGT3);
                _dcRender_IncPrimitive(render, sizeof(POLY_GT3));

            }
            break;
        }
    }
}

void dcRender_DrawBillboard(SDC_Render* render, SDC_Texture* texture, MATRIX* transform, SVECTOR position, SVECTOR size)
{
    u_long *orderingTable = render->orderingTable[render->doubleBufferIndex];
    int orderingTableCount = render->orderingTableCount;
    long p, flg;

    SetRotMatrix(transform);
    SetTransMatrix(transform);

    SVECTOR spos;
    long otz = RotTransPers(&position, (long*)&spos.vx, &p, &flg);

    if (p == 0) return;
    if ((otz <= 0) || (otz >= orderingTableCount)) return;

    void *poly = render->nextPrimitive;

    POLY_FT4* polyGT4 = (POLY_FT4*)poly;
    setPolyFT4(polyGT4);

    setXY4(polyGT4,
        spos.vx-size.vx, spos.vy-size.vy,
        spos.vx+size.vx, spos.vy-size.vy,
        spos.vx-size.vx, spos.vy+size.vy,
        spos.vx+size.vx, spos.vy+size.vy);
    setRGB0(polyGT4, 128, 128, 128);

    polyGT4->tpage = getTPage(texture->mode, 0, texture->prect.x, texture->prect.y);
    setClut(polyGT4, texture->crect.x, texture->crect.y);
    setUVWH(polyGT4, texture->prect.x, texture->prect.y, texture->prect.w, texture->prect.h);

    addPrim(&orderingTable[otz], polyGT4);
    _dcRender_IncPrimitive(render, sizeof(POLY_FT4));
}

void dcRender_DrawBackground(SDC_Render* render, SDC_Texture* texture)
{
    //assert(render && transform);
    u_long *orderingTable = render->orderingTable[render->doubleBufferIndex];
    int orderingTableCount = render->orderingTableCount;
    long otz = orderingTableCount - 1;

    void *poly = render->nextPrimitive;

    POLY_FT4* polyGT4 = (POLY_FT4*)poly;
    setPolyFT4(polyGT4);

    setXY4(polyGT4, 0, 0, SCREEN_WIDTH, 0, 0, SCREEN_HEIGHT >> 1, SCREEN_WIDTH, SCREEN_HEIGHT >> 1);
    setRGB0(polyGT4, 128, 128, 128);

    polyGT4->tpage = getTPage(texture->mode, 0, 640, 256);
    setClut(polyGT4, texture->crect.x, texture->crect.y);
    setUVWH(polyGT4, 0, 0, 128, 128);

    addPrim(&orderingTable[otz], polyGT4);
    _dcRender_IncPrimitive(render, sizeof(POLY_FT4));
}

void dcRender_DrawTitle(SDC_Render* render, SDC_Texture* texture)
{
    //assert(render && transform);
    u_long *orderingTable = render->orderingTable[render->doubleBufferIndex];
    long otz = 1;

    void *poly = render->nextPrimitive;

    POLY_FT4* polyGT4 = (POLY_FT4*)poly;
    setPolyFT4(polyGT4);

    setXY4(polyGT4, 0, 0, SCREEN_WIDTH, 0, 0, SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT);
    setRGB0(polyGT4, 128, 128, 128);

    polyGT4->tpage = getTPage(texture->mode, 0, 768, 128);
    setClut(polyGT4, texture->crect.x, texture->crect.y);
    setUVWH(polyGT4, 0, 127, 128, 128);
	//polyGT4->u0 = 0;   polyGT4->v0 = 128;				
	//polyGT4->u1 = 128;  polyGT4->v1 = 128;				
	//polyGT4->u2 = 0;   polyGT4->v2 = 255;			
	//polyGT4->u3 = 128; polyGT4->v3 = 255;

    addPrim(&orderingTable[otz], polyGT4);
    _dcRender_IncPrimitive(render, sizeof(POLY_FT4));
}

void dcRender_DrawQuad(SDC_Render* render, SDC_Texture* texture, RECT* screenLocation)
{
    //assert(render && transform);
    u_long *orderingTable = render->orderingTable[render->doubleBufferIndex];
    long otz = 1;

    void *poly = render->nextPrimitive;

    POLY_FT4* polyGT4 = (POLY_FT4*)poly;
    setPolyFT4(polyGT4);

    setXY4(
        polyGT4, 
        screenLocation->x, screenLocation->y, 
        screenLocation->x + screenLocation->w, screenLocation->y, 
        screenLocation->x, screenLocation->y + screenLocation->h, 
        screenLocation->x + screenLocation->w, screenLocation->y + screenLocation->h
    );
    
    setRGB0(polyGT4, 127, 127, 127);
    setSemiTrans(&polyGT4, 0);

    u_short tpageX = texture->prect.x & ~0x003f;
    u_short tpageY = texture->prect.y & ~0x00ff;

    polyGT4->tpage = getTPage(texture->mode, 0, tpageX, tpageY);
    setClut(polyGT4, texture->crect.x, texture->crect.y);
    setUVWH(polyGT4, texture->prect.x & 0x003f, texture->prect.y & 0x00ff, texture->prect.w, texture->prect.h);

    addPrim(&orderingTable[otz], polyGT4);
    _dcRender_IncPrimitive(render, sizeof(POLY_FT4));
}



void dcRender_DrawLine(SDC_Render* render, SVECTOR* v0, SVECTOR* v1, MATRIX* transform, CVECTOR* color, u_short segments )
{
    
    //assert(render && v0 && v1 && transform && segments > 0);
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

u_long dcRender_VertexSize( EDC_PolygonVertexType vertexType )
{
    switch(vertexType)
    {
        case POLIGON_VERTEX: return sizeof(SDC_Vertex);
        case POLIGON_VERTEX_COLOR: return sizeof(SDC_VertexColor);
        case POLIGON_VERTEX_NORMAL: return sizeof(SDC_VertexNormal);
        case POLIGON_VERTEX_COLOR_NORMAL: return sizeof(SDC_VertexColorNormal);
        case POLIGON_VERTEX_TEXTURED: return sizeof(SDC_VertexTextured);
        case POLIGON_VERTEX_TEXTURED_COLOR: return sizeof(SDC_VertexColorTextured);
        case POLIGON_VERTEX_TEXTURED_NORMAL: return sizeof(SDC_VertexTexturedNormal);
    };
    
    assert(0);
    return 0;
}

//#pragma GCC pop_options
