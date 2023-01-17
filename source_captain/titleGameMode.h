#ifndef TITLE_GAME_MODE_H
#define TITLE_GAME_MODE_H

#include "tdGameplay.h"
#include "dcSprite.h"

struct SDC_Render;

extern tdGameMode titleGameMode;

void titleInitScene(tdGameMode* gameMode);
void titleUpdateScene(tdGameMode* gameMode);
void titleDrawScene(tdGameMode* gameMode, SDC_Render* render);

#endif