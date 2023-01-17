#ifndef _DC_MAINMENUGAMESTATE_
#define _DC_MAINMENUGAMESTATE_
#include "dcSprite.h"

#define FRAMES_PER_STATE_ANIM 10
#define ANIM_TIME 75// 1.5s = 1.5 * 50 = 75

typedef struct
{
    char PressStartText[12];
    char TeamName[30];
    char bActivatePressStartEffet;
    char PressAnimationFrames;
    int  TotalFrames;
    SDC_Sprite TitleScreenSprite;

} MenuGameState; 

void MGS_Init(MenuGameState* MGSPtr);
void MGS_Update(MenuGameState* MGSPtr);
void MGS_Close(MenuGameState* MGSPtr);

#endif
