#ifndef _PROJECTILE_
#define _PROJECTILE_

#include <stdlib.h>
#include <libetc.h>
#include <libgte.h>
#include <stdio.h>
#include "dcLibPsx/include/dcLevel.h"


void UpdateProjectile(SDC_Level* Level, SDC_Projectile* Projectile, int IndexInArray);
void InitProjectile(SDC_Projectile* Projectile);

#endif