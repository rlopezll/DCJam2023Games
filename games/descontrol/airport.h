#ifndef _INC_AIRPORT_H_
#define _INC_AIRPORT_H_

#include "dcRender.h"
#include "dcCamera.h"

void StartAirport(); 
void UpdateAirport(int elapsed); 
void RenderAirport(SDC_Render* render, SDC_Camera* camera);
int GetAirportScore();

#endif //_INC_AIRPORT_H_