#include "image.h"

void Image_Load(SImage* image, u_long* texture) {
    TIM_IMAGE tim;                         
    OpenTIM(texture);                         // Open the tim binary data, feed it the address of the data in memory
    ReadTIM(&tim);                            // This read the header of the TIM data and sets the corresponding members of the SDC_TIM_IMAGE structure
    LoadImage( tim.prect, tim.paddr );        // Transfer the data from memory to VRAM at position prect.x, prect.y
    DrawSync(0);  

    image->mode = tim.mode;
    image->paddr = tim.paddr;
    image->prect = *tim.prect;
}

void Image_LoadPalette(SPalette* palette, u_long* texture) {
    TIM_IMAGE tim;
    OpenTIM(texture);                          // Open the tim binary data, feed it the address of the data in memory
    ReadTIM(&tim);                             // This read the header of the TIM data and sets the corresponding members of the SDC_TIM_IMAGE structure

    if( tim.mode & 0x8 ) {                     // check 4th bit       // If 4th bit == 1, TIM has a CLUT
        LoadImage( tim.crect, tim.caddr );     // Load it to VRAM at position crect.x, crect.y
    }
    DrawSync(0);  

    palette->caddr = tim.caddr;
    palette->crect = *tim.crect;
}

SDC_TIM_IMAGE Image_GetTIM(SPalette* palette, SImage* image) {
    SDC_TIM_IMAGE tim;
    tim.mode = image->mode;
    tim.prect = image->prect;
    tim.crect = palette->crect;
    return tim;
}