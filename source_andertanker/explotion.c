#include "explotion.h"
#include "dcMath.h"
#include "dcLevel.h"
#include "dcMisc.h"

void UpdateExplotion(SDC_Level* Level, SDC_Explotion* Explotion, int IndexInArray)
{
     if(Explotion->CurrentRadius < Explotion->MaxRadius)
     {
          Explotion->CurrentRadius += Explotion->ExpansionSpeed * 2;
          Explotion->Scale = (VECTOR){Explotion->CurrentRadius * 20,Explotion->CurrentRadius * 20,Explotion->CurrentRadius * 20};
          //SDC_Mesh3D* TempSphere = dcMisc_generateSphereMesh(Explotion->CurrentRadius,8,8);
          //Explotion->Mesh =  TempSphere;
     }
     else{
          dcLevel_DestroyExplotion(Level, IndexInArray);
     }

}
