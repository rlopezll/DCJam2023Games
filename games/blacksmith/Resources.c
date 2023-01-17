#include "engine.h"

/*  Texture Animations Resources */

extern unsigned long _binary_textures_tile1_tim_start[];
extern unsigned long _binary_textures_tile2_tim_start[];
extern unsigned long _binary_textures_tile3_tim_start[];
extern unsigned long _binary_textures_tile4_tim_start[];
extern unsigned long _binary_textures_tile5_tim_start[];
extern unsigned long _binary_textures_tile6_tim_start[];
extern unsigned long _binary_textures_titlescreen_tim_start[];
extern unsigned long _binary_textures_blue_ball_tim_start[];
extern unsigned long _binary_textures_red_ball_tim_start[];
extern unsigned long _binary_textures_yellow_ball_tim_start[];
extern unsigned long _binary_textures_green_ball_tim_start[];

RealTIMImage TimTile1;
RealTIMImage TimTile2;
RealTIMImage TimTile3;
RealTIMImage TimTile4;
RealTIMImage TimTile5;
RealTIMImage TimTile6;
RealTIMImage TimTitleScreen;
RealTIMImage TimVignette;
RealTIMImage TimBlueBall;
RealTIMImage TimRedBall;
RealTIMImage TimYellowBall;
RealTIMImage TimGreenBall;

void Resources_LoadTextureResources()
{
    TIM_IMAGE Image;
    dcRender_LoadTexture(&Image, _binary_textures_tile1_tim_start);
    TimTile1.crect = *Image.crect;
    TimTile1.mode = Image.mode;
    TimTile1.prect = *Image.prect;

    dcRender_LoadTexture(&Image, _binary_textures_tile2_tim_start);
    TimTile2.crect = *Image.crect;
    TimTile2.mode = Image.mode;
    TimTile2.prect = *Image.prect;

    dcRender_LoadTexture(&Image, _binary_textures_tile3_tim_start);
    TimTile3.crect = *Image.crect;
    TimTile3.mode = Image.mode;
    TimTile3.prect = *Image.prect;

    dcRender_LoadTexture(&Image, _binary_textures_tile4_tim_start);
    TimTile4.crect = *Image.crect;
    TimTile4.mode = Image.mode;
    TimTile4.prect = *Image.prect;

    dcRender_LoadTexture(&Image, _binary_textures_tile5_tim_start);
    TimTile5.crect = *Image.crect;
    TimTile5.mode = Image.mode;
    TimTile5.prect = *Image.prect;

   dcRender_LoadTexture(&Image, _binary_textures_tile6_tim_start);
   TimTile6.crect = *Image.crect;
   TimTile6.mode = Image.mode;
   TimTile6.prect = *Image.prect;

   dcRender_LoadTexture(&Image, _binary_textures_titlescreen_tim_start);
   TimTitleScreen.crect = *Image.crect;
   TimTitleScreen.mode = Image.mode;
   TimTitleScreen.prect = *Image.prect;

   dcRender_LoadTexture(&Image, _binary_textures_blue_ball_tim_start);
   TimBlueBall.crect = *Image.crect;
   TimBlueBall.mode = Image.mode;
   TimBlueBall.prect = *Image.prect;

   dcRender_LoadTexture(&Image, _binary_textures_red_ball_tim_start);
   TimRedBall.crect = *Image.crect;
   TimRedBall.mode = Image.mode;
   TimRedBall.prect = *Image.prect;

   dcRender_LoadTexture(&Image, _binary_textures_yellow_ball_tim_start);
   TimYellowBall.crect = *Image.crect;
   TimYellowBall.mode = Image.mode;
   TimYellowBall.prect = *Image.prect;

   dcRender_LoadTexture(&Image, _binary_textures_green_ball_tim_start);
   TimGreenBall.crect = *Image.crect;
   TimGreenBall.mode = Image.mode;
   TimGreenBall.prect = *Image.prect;
}

/* Sprite Animations Header. */

// Hero Run Animation.
SDC_SpriteFrame HeroIdleWalkFrames[] =
{
    {5,0,18,64}, {26,0,18,64}, {47,0,18,64}, {67,0,18,64}, {87,0,18,64}, {107, 0, 18, 64}
};

SDC_SpriteFrame HeroAttackFrames[] =
{
    {26,64, 20, 64} , {48,64,29,64} , {79,64,27,64} , {107,64,18,64}
};

SDC_SpriteFrame EnemyBlueFrames[] =
{
    {2,0,16,32} , {21,0,14,32} , {37,0, 14,32} , {54,0, 11, 32} , {68,0, 21,32} , {92,0,18,32}
};

SDC_SpriteFrame EnemyRedFrames[] =
{
    {3,0, 11, 32} , {17, 0, 11, 32} , {31, 0, 11, 32} , {45, 0, 11, 32} , {59, 0, 11, 32} , {73, 0, 11, 32}
};

SDC_SpriteFrame EnemyGreenFrames[] =
{
    {3,0,16,32} , {20,0,15,32} , {41,0,15,32} , {60, 0, 14, 32} , {78, 0, 13, 32} , {93,0, 13, 32}
};

SDC_SpriteFrame EnemyYellowFrames[] =
{
    {3,0,22,32}, {28,0,28,32}, {59,0,29,32}, {90,0,30,32}
};

SDC_SpriteFrame TitleScreenFrames[] =
{
    {0,0,256,256}
};

//SDC_SpriteAnimation HeroIdleAnimations = {HeroIdleWalkFrames, NULL, 3, 6, 0, 0};
SDC_SpriteAnimation HeroWalkAnimations = {HeroIdleWalkFrames, NULL, 3, 6, 0, 0};
SDC_SpriteAnimation HeroAttackAnimations = {HeroAttackFrames, NULL, 1, 4, 0, 0};

SDC_SpriteAnimation EnemyBlueAnimations = {EnemyBlueFrames, NULL, 2, 6, 0, 0};
SDC_SpriteAnimation EnemyRedAnimations = {EnemyRedFrames, NULL, 2, 6, 0, 0};
SDC_SpriteAnimation EnemyGreenAnimations = {EnemyGreenFrames, NULL, 2, 6, 0, 0};
SDC_SpriteAnimation EnemyYellowAnimations = {EnemyYellowFrames, NULL, 2, 4, 0, 0};
// SDC_SpriteAnimation TitleScreenAnimations = {TitleScreenFrames, NULL, 1, 1, 0, 0};


extern unsigned long _binary_textures_HeroWalk_tim_start[];
extern unsigned long _binary_textures_EnemyBlue_tim_start[];
extern unsigned long _binary_textures_EnemyRed_tim_start[];
extern unsigned long _binary_textures_EnemyGreen_tim_start[];
extern unsigned long _binary_textures_EnemyYellow_tim_start[];

void Resources_LoadSpriteResources()
{
    //dcSprite_LoadAnimationTex(&HeroIdleAnimations, _binary_textures_HeroIdle_tim_start);
    dcSprite_LoadAnimationTex(&HeroWalkAnimations, _binary_textures_HeroWalk_tim_start);
    dcSprite_LoadAnimationTex(&HeroAttackAnimations, _binary_textures_HeroWalk_tim_start);
    
    dcSprite_LoadAnimationTex(&EnemyBlueAnimations, _binary_textures_EnemyBlue_tim_start);
    dcSprite_LoadAnimationTex(&EnemyRedAnimations, _binary_textures_EnemyRed_tim_start);
    dcSprite_LoadAnimationTex(&EnemyGreenAnimations, _binary_textures_EnemyGreen_tim_start);
    dcSprite_LoadAnimationTex(&EnemyYellowAnimations, _binary_textures_EnemyYellow_tim_start);
}

extern unsigned long _binary_textures_fnt_tim_start[];
void Resources_LoadFont()
{
    dcFont_Load(_binary_textures_fnt_tim_start);
}

SDC_Sfx SwordAudio;
SDC_Sfx MonsterAudio;

extern unsigned long _binary_audios_sword_vag_start[];
extern unsigned long _binary_audios_monster_vag_start[];
void Resources_LoadAudio()
{
    dcAudio_SfxLoad(GEngineInstance.AudioPtr, &SwordAudio, (u_char *)_binary_audios_sword_vag_start);
    dcAudio_SfxLoad(GEngineInstance.AudioPtr, &MonsterAudio, (u_char *)_binary_audios_monster_vag_start);
}