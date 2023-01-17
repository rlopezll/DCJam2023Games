#ifndef _INC_GAMEOVER_H_
#define _INC_GAMEOVER_H_

#include "dcRender.h"
#include "dcCamera.h"

void InitGameOver();
void UpdateGameOver(int elapsed);
void RenderGameOver(SDC_Render* render, SDC_Camera* camera);

#endif //_INC_GAMEOVER_H_