#ifndef _DC_SPRITETEST_GAMESTATE
#define _DC_SPRITETEST_GAMESTATE

/*  Texture Animations Resources */
extern RealTIMImage TimTile1;
extern RealTIMImage TimTile2;
extern RealTIMImage TimTile3;
extern RealTIMImage TimTile4;
extern RealTIMImage TimTile5;
extern RealTIMImage TimTile6;
extern RealTIMImage TimTitleScreen;
extern RealTIMImage TimBlueBall;
extern RealTIMImage TimRedBall;
extern RealTIMImage TimYellowBall;
extern RealTIMImage TimGreenBall;
void Resources_LoadTextureResources();

/* Sprite Animations Resources */

//extern SDC_SpriteAnimation HeroIdleAnimations;
extern SDC_SpriteAnimation HeroWalkAnimations;
extern SDC_SpriteAnimation HeroAttackAnimations;

extern SDC_SpriteAnimation EnemyBlueAnimations;
extern SDC_SpriteAnimation EnemyRedAnimations;
extern SDC_SpriteAnimation EnemyGreenAnimations;
extern SDC_SpriteAnimation EnemyYellowAnimations;

extern SDC_SpriteAnimation TitleScreenAnimations;

/* Audio */

extern SDC_Sfx SwordAudio;
extern SDC_Sfx MonsterAudio;

void Resources_LoadSpriteResources();
void Resources_LoadAudio();
void Resources_LoadFont();

#endif