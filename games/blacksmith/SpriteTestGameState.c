#include "SpriteTestGameState.h"
#include "engine.h"

extern unsigned long _binary_sonic_tim_start[];

    CVECTOR Color = {128, 128, 128};
SDC_SpriteFrame sonic_run_frames[] = {
    {29-13,0,28,42}, {58-13,0,37,42}, {96-13,0,38,42}, {135-13,0,26,42},
    {162-13,0,27,42}, {190-13,0,39,42}, {217,0,39,42}
};

SDC_SpriteAnimation sonic_run = {sonic_run_frames, NULL, 3, 7, 0, 0};
    SDC_Sprite sonic_sprite;

void STGS_Init(FSpriteTestGameState* GameState)
{
    dcSprite_LoadAnimationTex(&sonic_run, _binary_sonic_tim_start);
    dcSprite_SetAnimation(&sonic_sprite, &sonic_run);
}

void STGS_Update(FSpriteTestGameState* GameState)
{
    dcSprite_Update(&sonic_sprite);
    dcSprite_Render(GEngineInstance.RenderPtr, &sonic_sprite, 64, 64, &Color);
}

void STGS_Close(FSpriteTestGameState* GameState)
{

}