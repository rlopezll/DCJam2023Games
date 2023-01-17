#ifndef _IMAGE_
#define _IMAGE_

#include <stdlib.h>
#include <libgte.h>
#include <libgpu.h>
#include <libgs.h>
#include <types.h>

#include "dcRender.h"

typedef struct {
    RECT	crect;		/* CLUT rectangle on frame buffer */
    u_long	*caddr;		/* CLUT address on main memory */ 
} SPalette;

typedef struct {
	u_long  mode;		/* pixel mode */
	RECT	prect;		/* texture image rectangle on frame buffer */
	u_long	*paddr;		/* texture image address on main memory */ 
} SImage;

void Image_Load(SImage* image, u_long* texture);
void Image_LoadPalette(SPalette* palette, u_long* texture);
SDC_TIM_IMAGE Image_GetTIM(SPalette* palette, SImage* image);

#endif