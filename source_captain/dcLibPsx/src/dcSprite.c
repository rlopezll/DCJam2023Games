#include "dcSprite.h"
#include "dcRender.h"
#include <malloc.h>
#include <libetc.h>
#include <stdio.h>
#include <assert.h>

void dcSprite_LoadAnimationTex(SDC_SpriteAnimation* animation, u_long *image_data) {
    TIM_IMAGE tim;
    dcRender_LoadTexture(&tim, image_data);  
    animation->timImage.crect = *tim.crect;
    animation->timImage.prect = *tim.prect;
    animation->timImage.mode = tim.mode;
}

void dcSprite_SetAnimation(SDC_Sprite* sprite, SDC_SpriteAnimation* animation) {
    sprite->currAnimation = animation;
    sprite->currAnimFrame = 0;
    sprite->currCounter = 0;
}

void dcSprite_Update(SDC_Sprite* sprite) {
    if(sprite->currCounter > sprite->currAnimation->speed) 
    {
        sprite->currCounter = 0;
        ++sprite->currAnimFrame;
        if(sprite->currAnimFrame >= sprite->currAnimation->nframes)
            sprite->currAnimFrame = 0;
    } else
    {
        ++sprite->currCounter;
    }
}

void dcSprite_Render(SDC_Render* render, SDC_Sprite* sprite, u_short x, u_short y, CVECTOR* Color) {
    assert(sprite && sprite->currAnimation && sprite->currAnimation->timImage);
    assert(render);
    assert(sprite->currAnimFrame < sprite->currAnimation->nframes);
    SDC_SpriteFrame* currFrame = &sprite->currAnimation->frames[sprite->currAnimFrame];
    assert(currFrame);
    DVECTOR UVs = {currFrame->x,currFrame->y};
    dcRender_DrawSpriteRect(render, &sprite->currAnimation->timImage, x, y, currFrame->w, currFrame->h, &UVs, Color);
}
