// screw you code formatter, this one needs to stay on top
#include <stdlib.h>
// now we need to have libgte.h
#include <libgte.h>
// then, these can work; the psyq library is badly written and won't include what it uses
#include <libetc.h>
#include <libgpu.h>
#include <stdio.h>
#include <types.h>
#include <stdbool.h>

#include "dcMath.h"
#include "dcCamera.h"
#include "dcRender.h"
#include "dcLevel.h"
#include "character.h"
#include "dcMemory.h"
#include "dcMisc.h"
#include "dcSprite.h"
#include "dcCollision.h"
#include "dcAudio.h"
#include "dcRender.h"
#include "dcFont.h"
#include "projectile.h"
#include "explotion.h"
#include "../third_party/modplayer/modplayer.h"

// cubo letras👍
#include "meshes/Box003.h"
#include "meshes/wall.h"

//tank pieces
#include "meshes/body.h"
#include "meshes/Bonifacio.h"

#include "meshes/wall.h"

#define CUBESIZE 196 

#ifndef TRACKS_MUSIC_OFFSET
#define TRACKS_MUSIC_OFFSET 0
#endif

SDC_Audio Audio;
SDC_Render Render;
SDC_Render FirstPlayerRender;
SDC_Camera Camera;
SDC_Camera FirstPlayerCamera;
SDC_Level MainLevel;
SDC_Character* FirstCharacter;
SDC_Character* SecondCharacter;


extern unsigned long _binary_textures_colorpallete_tim_start[];
extern unsigned long _binary_textures_smile_tim_start[];
extern unsigned long _binary_textures_Letra_A_tim_start[];
extern unsigned long _binary_textures_Pala_tim_start[];
extern unsigned long _binary_textures_floor_texture_tim_start[];
extern unsigned long _binary_textures_blue_tank_texture_tim_start[];
extern unsigned long _binary_textures_red_tank_texture_tim_start[];
extern unsigned long _binary_textures_white_tim_start[];


extern unsigned long _binary_data_Fire_vag_start[];
extern unsigned long _binary_data_Hit_vag_start[];
extern unsigned long _binary_data_Miss_vag_start[];

int GameOverSeconds;
int CurrentGameOverSeconds;
VECTOR CharacterInitialLocation = {300,0, 300, 0};
VECTOR Character2InitialLocation = {-300, 0, 300, 0};

void InitGame()
{
    GameOverSeconds = 60;
    CurrentGameOverSeconds = 0;
    dcMemory_Init();
    PadInit(0);
    InitGeom();   

    int  width = 640;
    int  height = 240;

    CVECTOR bgColor = {60, 120, 120};        
    dcRender_Init(&Render, width, height, bgColor, 4096, 8192 * 6, RENDER_MODE_NTCS, 1);
    dcRender_Init(&FirstPlayerRender, width, height, bgColor, 4096, 8192 * 6 , RENDER_MODE_NTCS, 0);
    dcCamera_SetScreenResolution(&Camera, width, height);
    Camera.PlayerCameraIndex = 0;
    dcCamera_SetScreenResolution(&FirstPlayerCamera, width, height);
    FirstPlayerCamera.PlayerCameraIndex = 1;
    
    MainLevel.ExplosionMesh = dcMisc_generateSphereMesh(200,2,2);
}

//This should go to a separate .h so we can modify the level without having conflicts
void InitLevel()
{ 
    MainLevel.NumObjects = 0;  
    SetColorMatrix(&MainLevel.ColorMatrix);

    TIM_IMAGE* tim_smile = (TIM_IMAGE*)malloc3(sizeof(TIM_IMAGE));
    TIM_IMAGE* tim_Pala = (TIM_IMAGE*)malloc3(sizeof(TIM_IMAGE));    
    TIM_IMAGE* tim_floor = (TIM_IMAGE*)malloc3(sizeof(TIM_IMAGE));
    TIM_IMAGE* tim_red_tank = (TIM_IMAGE*)malloc3(sizeof(TIM_IMAGE));
    TIM_IMAGE* tim_blue_tank = (TIM_IMAGE*)malloc3(sizeof(TIM_IMAGE));
    TIM_IMAGE* tim_white = (TIM_IMAGE*)malloc3(sizeof(TIM_IMAGE));

    //We can move this structure initialization to a function
    SDC_DrawParams DrawParamsCrash = {
        .tim = tim_red_tank,
        .constantColor = {255, 255, 255},
        .bLighting = 1,
        .bUseConstantColor = 1
    };    
    SDC_DrawParams DrawParamsCrash2 = {
        .tim = tim_blue_tank,
        .constantColor = {255, 255, 255},
        .bLighting = 1,
        .bUseConstantColor = 1
    };
    SDC_DrawParams DrawParams = {
        .tim = tim_smile,
        .constantColor = {255, 255, 255},
        .bLighting = 1,
        .bUseConstantColor = 1
    };
       
    SDC_DrawParams DrawParamsFloor = {
        .tim = tim_floor,
        .constantColor = {255, 255, 255},
        .bLighting = 1,
        .bUseConstantColor = 1
    };
 SDC_DrawParams DrawPalaParams = {
        .tim = tim_Pala,
        .constantColor = {255, 255, 255},
        .bLighting = 1,
        .bUseConstantColor = 1
    };
     SDC_DrawParams DrawWhiteParams = {
        .tim = tim_white,
        .constantColor = {0, 50, 100},
        .bLighting = 1,
        .bUseConstantColor = 1
    };
//printf("\n", DrawParamsFloor.bLighting);
    SDC_DrawParams* DrawParamsFloorPtr = (SDC_DrawParams*)malloc3(sizeof(SDC_DrawParams));
    *DrawParamsFloorPtr = DrawParamsFloor;
        SDC_DrawParams* DrawParamsWhitePtr = (SDC_DrawParams*)malloc3(sizeof(SDC_DrawParams));
    *DrawParamsWhitePtr = DrawWhiteParams;
    SDC_DrawParams* DrawParamsCrashPtr = (SDC_DrawParams*)malloc3(sizeof(SDC_DrawParams));
    *DrawParamsCrashPtr = DrawParamsCrash;

    SDC_DrawParams* DrawParamsPalaPtr = (SDC_DrawParams*)malloc3(sizeof(SDC_DrawParams));
    *DrawParamsPalaPtr = DrawPalaParams;


        SDC_DrawParams* DrawParamsCrashPtr2 = (SDC_DrawParams*)malloc3(sizeof(SDC_DrawParams));
    *DrawParamsCrashPtr2 = DrawParamsCrash2;
    SDC_DrawParams* DrawParamsPtr = (SDC_DrawParams*)malloc3(sizeof(SDC_DrawParams));
    *DrawParamsPtr = DrawParams;

    dcRender_LoadTexture(tim_smile, _binary_textures_Letra_A_tim_start);
    dcRender_LoadTexture(tim_Pala, _binary_textures_Pala_tim_start);
    dcRender_LoadTexture(tim_floor, _binary_textures_floor_texture_tim_start);
    dcRender_LoadTexture(tim_white, _binary_textures_white_tim_start);
    dcRender_LoadTexture(tim_red_tank, _binary_textures_red_tank_texture_tim_start);
    dcRender_LoadTexture(tim_blue_tank, _binary_textures_blue_tank_texture_tim_start);
    MainLevel.White = tim_white;


    //localizaciones cajas para luego crear los actores
    VECTOR BoxLocarion = {000,0, 0, 0};
    VECTOR BoxLocation4 = {375,0, 0, 0};
    VECTOR BoxLocation5 = {-500,0, 125, 0};
    VECTOR BoxLocation6 = {-125,0, -500, 0};



    VECTOR BoxLocation7 = {-125,0, 900, 0};
    VECTOR BoxLocation8 = {500,0, 0, 0};

    VECTOR palaLocation = {10,50, 0, 0};       
    VECTOR BoxHalfSize = {20,20,20};
    SVECTOR BoxRotation = {0,0,0};
    VECTOR BoxScale = {ONE, ONE, ONE};
    dcLevel_AddObject(&MainLevel, &Box003_Mesh, &BoxLocarion, &BoxRotation, &BoxScale, DrawParamsPtr, NULL, 1 ,&BoxHalfSize);
    dcLevel_AddObject(&MainLevel, &Box003_Mesh, &BoxLocation4,&BoxRotation, &BoxScale,  DrawParamsPtr, NULL, 1 ,&BoxHalfSize);
    dcLevel_AddObject(&MainLevel, &Box003_Mesh, &BoxLocation5, &BoxRotation, &BoxScale, DrawParamsPtr, NULL, 1 ,&BoxHalfSize);
    dcLevel_AddObject(&MainLevel, &Box003_Mesh, &BoxLocation6,&BoxRotation,  &BoxScale, DrawParamsPtr, NULL, 1 ,&BoxHalfSize);
    dcLevel_AddObject(&MainLevel, &Box003_Mesh, &BoxLocation7, &BoxRotation, &BoxScale, DrawParamsPtr, NULL, 1 ,&BoxHalfSize);
    dcLevel_AddObject(&MainLevel, &Box003_Mesh, &BoxLocation8,&BoxRotation,  &BoxScale, DrawParamsPtr, NULL, 1 ,&BoxHalfSize);


VECTOR WallHalfSize = {0, 0,0};
VECTOR Wall1Location = {2000, -100, -4000};
VECTOR Wall1Location2 = {-2000, -100, -4000};
VECTOR Wall2Location = {2000, -100, 4000};
VECTOR Wall2Location2 = {-2000, -100, 4000};
VECTOR Wall3Location = {-4000, -100, 2000};
VECTOR Wall3Location2 = {-4000, -100, -2000};
VECTOR Wall4Location = {4000, -100, 2000};
VECTOR Wall4Location2 = {4000, -100, -2000};

SVECTOR Wall2Rotation = {0, 2048, 0};
SVECTOR Wall3Rotation = {0, 1024, 0};
SVECTOR Wall4Rotation = {0, -1024, 0};
VECTOR WallScale = { ONE * 1.3,  ONE * 6,  ONE * 1.3};
    dcLevel_AddObject(&MainLevel, &wall_Mesh, &Wall1Location,&BoxRotation, &WallScale, DrawParamsFloorPtr, NULL, 1 ,&WallHalfSize); 
    dcLevel_AddObject(&MainLevel, &wall_Mesh, &Wall1Location2,&BoxRotation, &WallScale, DrawParamsFloorPtr, NULL, 1 ,&WallHalfSize);    
    dcLevel_AddObject(&MainLevel, &wall_Mesh, &Wall2Location,&Wall2Rotation,&WallScale, DrawParamsFloorPtr, NULL, 1 ,&WallHalfSize);
    dcLevel_AddObject(&MainLevel, &wall_Mesh, &Wall2Location2,&Wall2Rotation, &WallScale, DrawParamsFloorPtr, NULL, 1 ,&WallHalfSize);      
    dcLevel_AddObject(&MainLevel, &wall_Mesh, &Wall3Location,&Wall3Rotation,&WallScale, DrawParamsFloorPtr, NULL, 1 ,&WallHalfSize);
    dcLevel_AddObject(&MainLevel, &wall_Mesh, &Wall3Location2,&Wall3Rotation, &WallScale, DrawParamsFloorPtr, NULL, 1 ,&WallHalfSize);      
    dcLevel_AddObject(&MainLevel, &wall_Mesh, &Wall4Location,&Wall4Rotation,&WallScale, DrawParamsFloorPtr, NULL, 1 ,&WallHalfSize);
    dcLevel_AddObject(&MainLevel, &wall_Mesh, &Wall4Location2,&Wall4Rotation, &WallScale, DrawParamsFloorPtr, NULL, 1 ,&WallHalfSize);  


    FirstCharacter = dcLevel_InitCharacter(&MainLevel, &body_Mesh, &CharacterInitialLocation, DrawParamsCrashPtr);
    SecondCharacter =dcLevel_InitCharacter(&MainLevel, &body_Mesh, &Character2InitialLocation, DrawParamsCrashPtr2);    


    SVECTOR PalaRotation = {2048, 0 ,1024};
    SDC_Object* Pala = dcLevel_AddObjectOnCharacter(&MainLevel, &Bonifacio_Mesh, &palaLocation, &PalaRotation, DrawParamsPalaPtr, FirstCharacter, 1 ,&BoxHalfSize);
    FirstCharacter->Pala = Pala;
    SDC_Object* Pala2 = dcLevel_AddObjectOnCharacter(&MainLevel, &Bonifacio_Mesh, &palaLocation, &PalaRotation, DrawParamsPalaPtr, SecondCharacter, 1 ,&BoxHalfSize);
    FirstCharacter->Pala = Pala;
    FirstCharacter->tim_projectile = tim_smile;
        SecondCharacter->Pala = Pala2;
    SecondCharacter->tim_projectile = tim_smile;

//Save world Matrix
    MATRIX Transform;
   for(int i = 0; i < MainLevel.NumObjects; i++)
    {  
        MATRIX WorldTransform;
        RotMatrix(&MainLevel.Objects[i]->Rotation, &Transform);
        TransMatrix(&Transform,  &MainLevel.Objects[i]->Location);
        ScaleMatrixL(&Transform, &MainLevel.Objects[i]->Scale);
        if(MainLevel.Objects[i]->CharacterParent == NULL)
        {
            GetParentTransform(MainLevel.Objects[i], &Transform, &WorldTransform);
        }
        MainLevel.Objects[i]->WorldTransform = WorldTransform;
    }    
}       

void Display(SDC_Render* InRender, SDC_Camera* InCamera)
{
     MATRIX OutTransform;

     //DrawCharacters
    for(int i = 0; i < MainLevel.NumCharacters; i++)
    {
        dcCamera_ApplyCameraTransform(InCamera,  &MainLevel.Characters[i]->WorldTransform,  &OutTransform);
        dcRender_DrawMesh(InRender, MainLevel.Characters[i]->Mesh, &OutTransform, MainLevel.Characters[i]->DrawParams);        
    } 


    //Draw Objects
   for(int i = 0; i < MainLevel.NumObjects; i++)
    {        
        if(MainLevel.Objects[i]->Scale.vx == 0 && MainLevel.Objects[i]->Scale.vy == 0)
        {
            continue;
        }        

        if(MainLevel.Objects[i]->CharacterParent != NULL )
        {
            if(MainLevel.Objects[i]->WorldTransform.m[0][0] != 0 || MainLevel.Objects[i]->WorldTransform.m[1][1] != 0)
            {
            MATRIX Transform;
            RotMatrix(&MainLevel.Objects[i]->Rotation, &Transform);
            TransMatrix(&Transform,  &MainLevel.Objects[i]->Location);
            ScaleMatrixL(&Transform, &MainLevel.Objects[i]->Scale);
            
            RotMatrix(&MainLevel.Objects[i]->CharacterParent->Rotation, &OutTransform);
            TransMatrix(&OutTransform, &MainLevel.Objects[i]->CharacterParent->Location);     
            
            CompMatrix(&OutTransform, &Transform, &OutTransform);   
            }
        }
        else{
            
        OutTransform = MainLevel.Objects[i]->WorldTransform;
        }

        dcCamera_ApplyCameraTransform(InCamera,  &OutTransform,  &OutTransform);
        dcRender_DrawMesh(InRender, MainLevel.Objects[i]->Mesh, &OutTransform, MainLevel.Objects[i]->DrawParams);
    }

    for(int i = 0; i < MainLevel.NumProjectiles; i++)
    {
        RotMatrix(&MainLevel.Projectiles[i]->Rotation, &OutTransform);
        TransMatrix(&OutTransform,  &MainLevel.Projectiles[i]->Location);         
        dcCamera_ApplyCameraTransform(InCamera,  &OutTransform,  &OutTransform);
        dcRender_DrawMesh(InRender, MainLevel.Projectiles[i]->Mesh, &OutTransform, MainLevel.Projectiles[i]->DrawParams);
    }

        for(int i = 0; i < MainLevel.NumExplotions; i++)
    {
        RotMatrix(&MainLevel.Explotions[i]->Rotation, &OutTransform);
        TransMatrix(&OutTransform,  &MainLevel.Explotions[i]->Location);
        ScaleMatrix(&OutTransform,  &MainLevel.Explotions[i]->Scale);
        dcCamera_ApplyCameraTransform(InCamera,  &OutTransform,  &OutTransform);
        dcRender_DrawMesh(InRender, MainLevel.Explotions[i]->Mesh, &OutTransform, MainLevel.Explotions[i]->DrawParams);
    }
    dcRender_SwapBuffers(InRender);

}


int main(void) 
{    
    InitGame();   
    InitLevel();

    //Sound
    dcAudio_Init(&Audio, 16);
    dcAudio_SfxLoad(&Audio, &MainLevel.HitSfx, (u_char *)_binary_data_Hit_vag_start);
    dcAudio_SfxLoad(&Audio, &MainLevel.FireSfx, (u_char *)_binary_data_Fire_vag_start);
    dcAudio_SfxLoad(&Audio, &MainLevel.MissSfx, (u_char *)_binary_data_Miss_vag_start);

    dcAudio_MusicPlay(&Audio, TRACKS_MUSIC_OFFSET+0);

    dcFont_UseSystemFont();
    RotMatrix_gte(&MainLevel.LightAngle, &MainLevel.RotLight);
/*
        SVECTOR ObjectNullRotation = {0,0,0};
        RotMatrix_gte(&MainLevel.LightAngle, &MainLevel.RotLight);
        RotMatrix_gte(&ObjectNullRotation, &MainLevel.RotObject);  
        // RotMatrix cube * RotMatrix light
        MulMatrix0(&MainLevel.RotObject, &MainLevel.RotLight, &MainLevel.RotLight);
        // Light Matrix * RotMatrix light 
        MulMatrix0(&MainLevel.LocalLightMatrix, &MainLevel.RotLight, &MainLevel.WorldLightMatrix);
        // Set new light matrix 
        SetLightMatrix(&MainLevel.WorldLightMatrix);    */
        int TimeToChangeScreen = 0;
        int bIsScreenSwapped = 0; 
    while (1) 
    {      
        if(MainLevel.bGameOver == 1) {
        if(CurrentGameOverSeconds < GameOverSeconds)
        {
            CurrentGameOverSeconds++;
        }
        else{
            //Reinit Game
            FirstCharacter->Location = CharacterInitialLocation;
            FirstCharacter->Lives = FirstCharacter->InitLives;
            SecondCharacter->Location = Character2InitialLocation;
            SecondCharacter->Lives = SecondCharacter->InitLives;
            MainLevel.bGameOver = 0;
            CurrentGameOverSeconds = 0;
        }    
        }
    TimeToChangeScreen++;
    if(TimeToChangeScreen > 200)
    {
        TimeToChangeScreen = 0;
        bIsScreenSwapped = !bIsScreenSwapped;

        if(bIsScreenSwapped)
        { 
            SetDefDrawEnv( &FirstPlayerRender.drawEnvironment[0],    0, 0,      640/2, 240 );
            SetDefDrawEnv( &FirstPlayerRender.drawEnvironment[1],    0, 240, 640/2, 240 );

            SetDefDispEnv( &FirstPlayerRender.displayEnvironment[0], 0, 240, 640, 240 );
            SetDefDispEnv( &FirstPlayerRender.displayEnvironment[1], 0, 0,      640, 240 );

            SetDefDrawEnv( &Render.drawEnvironment[0],    640/2, 0,      640/2, 240 );
            SetDefDrawEnv( &Render.drawEnvironment[1],    640/2, 240, 640/2, 240 );

            SetDefDispEnv( &Render.displayEnvironment[0], 0, 240, 640, 240 );
            SetDefDispEnv( &Render.displayEnvironment[1], 0, 0,      640, 240 );
        }
        else
        {
            SetDefDrawEnv( &Render.drawEnvironment[0],    0, 0,      640/2, 240 );
            SetDefDrawEnv( &Render.drawEnvironment[1],    0, 240, 640/2, 240 );

            SetDefDispEnv( &Render.displayEnvironment[0], 0, 240, 640, 240 );
            SetDefDispEnv( &Render.displayEnvironment[1], 0, 0,      640, 240 );

            SetDefDrawEnv( &FirstPlayerRender.drawEnvironment[0],    640/2, 0,      640/2, 240 );
            SetDefDrawEnv( &FirstPlayerRender.drawEnvironment[1],    640/2, 240, 640/2, 240 );

            SetDefDispEnv( &FirstPlayerRender.displayEnvironment[0], 0, 240, 640, 240 );
            SetDefDispEnv( &FirstPlayerRender.displayEnvironment[1], 0, 0,      640, 240 );
        }
        dcAudio_Update(&Audio);
    }   



    
    // Init Pad
   
    // Store input values    




    for(int i = 0; i < MainLevel.NumProjectiles; i++)
    {
        //printf("AAAA\n");
        UpdateProjectile(&MainLevel, MainLevel.Projectiles[i], i);
    }
        for(int i = 0; i < MainLevel.NumExplotions; i++)
    {
        UpdateExplotion(&MainLevel, MainLevel.Explotions[i], i);
    }

    for(int i = 0; i < MainLevel.NumCharacters; i++)
    {
        SDC_Camera* InCamera = i == 0 ? &Camera : &FirstPlayerCamera;
        
        SDC_Render* InRender = i == 0 ? &Render : &FirstPlayerRender;
            UpdateCharacter(MainLevel.Characters[i], &MainLevel);
            SVECTOR CameraLocation = MainLevel.Characters[i]->FrontVector;
            dcCamera_SetCameraPosition(InCamera, MainLevel.Characters[i]->Location.vx + CameraLocation.vx / 20, MainLevel.Characters[i]->Location.vy + 200, MainLevel.Characters[i]->Location.vz + CameraLocation.vz / 20);
            VECTOR LookAt =  MainLevel.Characters[i]->Location;
            LookAt.vy += 150;
            dcCamera_LookAt(InCamera, &LookAt);

                    
        //Draw UI:
        CVECTOR fontColor = {127, 127, 127};
        char PlayerTxt[256];
        sprintf(PlayerTxt, "LIVES: %i\n", MainLevel.Characters[i]->Lives);
        VECTOR TxtPos = {100,10};

        //GameOver
        if(MainLevel.bGameOver == 1){
            if(MainLevel.Characters[i]->Lives > 0)
            {
                sprintf(PlayerTxt, "WINNER!!\n");
            }
            else{
                 sprintf(PlayerTxt, "LOSER\n");
            }
        }
        dcFont_Print(InRender, TxtPos.vx, TxtPos.vy,&fontColor,PlayerTxt);
            
        RotMatrix(&MainLevel.Characters[i]->Rotation, &MainLevel.Characters[i]->WorldTransform);            
        TransMatrix(&MainLevel.Characters[i]->WorldTransform,  &MainLevel.Characters[i]->Location);
           
    }
        Display(&Render, &Camera);
         Display(&FirstPlayerRender, &FirstPlayerCamera);
         DVECTOR uv = {0,0};
         
        CVECTOR Red = {255, 0, 0};        
        CVECTOR Blue = {0, 0, 255};
        dcRender_DrawSpriteRect(&Render, MainLevel.White, 310, 0,10, 240, &uv, &Red);        
        dcRender_DrawSpriteRect(&Render, MainLevel.White, 0, 0,320, 10, &uv, &Red);      
        dcRender_DrawSpriteRect(&Render, MainLevel.White, 0, 310,320, 10, &uv, &Red);
        dcRender_DrawSpriteRect(&Render, MainLevel.White, 0, 0,10, 240, &uv, &Red);
        
        dcRender_DrawSpriteRect(&FirstPlayerRender, MainLevel.White, 310, 0,10, 240, &uv, &Blue);        
        dcRender_DrawSpriteRect(&FirstPlayerRender, MainLevel.White, 0, 0,320, 10, &uv, &Blue);      
        dcRender_DrawSpriteRect(&FirstPlayerRender, MainLevel.White, 0, 310,320, 10, &uv, &Blue);
        dcRender_DrawSpriteRect(&FirstPlayerRender, MainLevel.White, 0, 0,10, 240, &uv, &Blue);
        VSync( 0 );
        DrawSync( 0 );
        SetDispMask( 1 );
    }

    return 0;
}