#ifndef _MAINMENU_
#define _MAINMENU_

#include "dcRender.h"
#include "dcCamera.h"

void InitMainMenu(); 
void UpdateMainMenu(int elapsed); 
void RenderMainMenu(SDC_Render* render, SDC_Camera* camera);

#endif