#include "airport.h"

#include <stdio.h>

#include "dcInput.h"
#include "dcFont.h"
#include "dcAudio.h"
#include "dcPerformance.h"

#include "suitcase.h"
#include "gamestate.h"

#include "meshes/Exit_P1.h"
#include "meshes/Exit_P2.h"
#include "meshes/Path_P1.h"
#include "meshes/Path_P2.h"

#include "meshes/Scanner_P1.h"
#include "meshes/Scanner_P2.h"

#include "meshes/Game_Ground_P1.h"
#include "meshes/Game_Ground_P2.h"

#include "meshes/ScannerQuad_P1.h"
#include "meshes/ScannerQuad_P2.h"

#include "meshes/Divider.h"

static int gSpawnTimerBase  = 100;
static int gSpawnTimerRange = 50;
static int gScannerWaitTime = 50;
static int gSuitcaseSpeed   = 8; 
static int gStartLives      = 5; 
static int gDifficultyScoreUpgrade = 5; 
static int gDiffiultyLevel  = 0; 

static bool gCheatInvicible = false; 

static int gRedColorIntensity = 255; 
static int gBlueColorIntensity = 150; 

static int gPathOffset = 0; 
static int gBeltSpeed = 4;

SDC_DrawParams drawParamsBackground = {
    .tim = NULL,
    .constantColor = {255, 255, 255},
    .bLighting = 1,
    .bUseConstantColor = 1
};

SDC_DrawParams drawParamsBackgroundBlack = {
    .tim = NULL,
    .constantColor = {0,0,0},
    .bLighting = 1,
    .bUseConstantColor = 1
};

// Diff:
// 0) single red belt | 2 options | Slow 
// 1) double belt | 2 options | slow 
// 2) double belt | 2 options | medium 
// 3) double belt | 3 options | medium 
// 4) double belt | 4 options | medium 
// 5) double belt | 4 options | fast  

extern unsigned long _binary_data_Path_Texture_tim_start[];
extern unsigned long _binary_data_Path_Texture2_tim_start[];
extern unsigned long _binary_data_Game_Ground_P1_tim_start[];
extern unsigned long _binary_data_Game_Ground_P2_tim_start[];
extern unsigned long _binary_data_Scanners_Texture_tim_start[];

extern unsigned long _binary_data_CamisetaRoja_tim_start[];
extern unsigned long _binary_data_BombaRoja_tim_start[];
extern unsigned long _binary_data_DrogasRoja_tim_start[];
extern unsigned long _binary_data_AbuelaRoja_tim_start[];
extern unsigned long _binary_data_CamisetaAzul_tim_start[];
extern unsigned long _binary_data_BombaAzul_tim_start[];
extern unsigned long _binary_data_DrogasAzul_tim_start[];
extern unsigned long _binary_data_AbuelaAzul_tim_start[];
extern unsigned long _binary_data_SocksRoja_tim_start[];
extern unsigned long _binary_data_PistolaRoja_tim_start[];
extern unsigned long _binary_data_JeringaRoja_tim_start[];
extern unsigned long _binary_data_MermaidRoja_tim_start[];
extern unsigned long _binary_data_SocksAzul_tim_start[];
extern unsigned long _binary_data_PistolaAzul_tim_start[];
extern unsigned long _binary_data_JeringaAzul_tim_start[];
extern unsigned long _binary_data_MermaidAzul_tim_start[];

extern unsigned long _binary_data_HeartEmpty_tim_start[];
extern unsigned long _binary_data_HeartFull_tim_start[];
extern unsigned long _binary_data_ButtonTriangle_tim_start[];
extern unsigned long _binary_data_ButtonSquare_tim_start[];
extern unsigned long _binary_data_ButtonCircle_tim_start[];

// Audios
extern unsigned long _binary_data_HeartLoose_vag_start[];
extern unsigned long _binary_data_ItemOK_vag_start[];

extern SDC_Audio gAudio;

SDC_TIM_IMAGE gContentScans[2][MAX_ITEM_CATEGORIES][ITEM_VARIANTS];
SDC_TIM_IMAGE gHeartFull; 
SDC_TIM_IMAGE gHeartEmpty; 
SDC_TIM_IMAGE gButtonTriangle; 
SDC_TIM_IMAGE gButtonSquare; 
SDC_TIM_IMAGE gButtonCircle; 

typedef struct 
{
    unsigned char beltId; 
    char          prevNode; 
    char          nextNode;
    int           timer; 
    int           totalTimer; 
} SuitcaseState;

typedef struct
{
    SDC_Input input[2];
    int scanners[2];
    int outputs[2];
    int nextSpawn[2];
    unsigned char beltSize[2];
    SDC_TIM_IMAGE pathTexture;
    SDC_TIM_IMAGE groundP1;
    SDC_TIM_IMAGE groundP2;
    SDC_TIM_IMAGE scannersTex;
    SDC_Sfx       heartLoose;
    SDC_Sfx       itemOK;

    SuitcaseState gSuitcaseStates[MAX_SUITCASES];

    int score; 
    int lives; 

    bool paused; 

} Airport;

static Airport gAirport; 

VECTOR gNodesA[] = {
{-957, 81, -390}, // _NodeA_01_0_0
{-470, 81, -390}, // _NodeA_02_0_1
{-60, 81, -390}, // _NodeA_03_0_2
{-32, 81, -378}, // _NodeA_03_0_3
{-20, 81, -351}, // _NodeA_03_0_4
{-20, 81, -230}, // _NodeA_04_0_2
{-39, 81, -205}, // _NodeA_04_0_3
{-63, 81, -188}, // _NodeA_04_0_4
{-152, 81, -182}, // _NodeA_05_0_0
{-166, 81, -169}, // _NodeA_05_0_001
{-190, 81, -150}, // _NodeA_05_0_002
{-189, 81, 175}, // _NodeA_06_0_0
{-174, 81, 199}, // _NodeA_06_0_001
{-150, 81, 215}, // _NodeA_06_0_002
{119, 81, 213}, // _NodeA_07_0_0
{144, 81, 230}, // _NodeA_07_0_001
{160, 81, 254}, // _NodeA_07_0_002
{160, 81, 359}, // _NodeA_08_0_0
{175, 81, 383}, // _NodeA_08_0_001
{200, 81, 400}, // _NodeA_08_0_002
{678, 81, 394}, // _NodeA_09_0_1
{934, 81, 394} // _NodeA_10_0_2
};
VECTOR gNodesB[] = {
{957, 12, -396}, // _NodeB_01_0_001
{545, 20, -400}, // _NodeB_01_0_002
{169, 12, -400}, // _NodeB_01_0_003
{144, 12, -386}, // _NodeB_01_0_004
{131, 12, -359}, // _NodeB_01_0_005
{129, 12, -240}, // _NodeB_01_0_006
{149, 12, -211}, // _NodeB_01_0_007
{169, 12, -200}, // _NodeB_01_0_008
{300, 12, -200}, // _NodeB_01_0_009
{324, 12, -184}, // _NodeB_01_0_010
{340, 12, -160}, // _NodeB_01_0_011
{340, 12, -31}, // _NodeB_01_0_012
{324, 12, -6}, // _NodeB_01_0_013
{299, 12, 9}, // _NodeB_01_0_014
{-310, 12, 9}, // _NodeB_01_0_015
{-335, 12, 26}, // _NodeB_01_0_016
{-350, 12, 49}, // _NodeB_01_0_017
{-349, 12, 340}, // _NodeB_01_0_018
{-365, 12, 364}, // _NodeB_01_0_019
{-389, 12, 380}, // _NodeB_01_0_020
{-680, 12, 380}, // _NodeB_01_0_021
{-943, 12, 379} // _NodeB_01_0_022
};

VECTOR* GetNodes(unsigned char beltId)
{ 
    return beltId == 0? gNodesA : gNodesB;
}

int GetAirportScore()
{
    return gAirport.score; 
}

//BeltNode 

int GetRandomNumber(int base, int range) 
{ 
    return base + (rand() % range); 
}

int lerpS(int start, int dest, unsigned pos) {
    return (start * (256 - pos) + dest * pos) >> 8; 
};

void CreateGraph()
{
    gAirport.beltSize[0] = sizeof(gNodesA)/sizeof(gNodesA[0]);
    gAirport.beltSize[1] = sizeof(gNodesB)/sizeof(gNodesB[0]); 

    gAirport.scanners[0] = 1;
    gAirport.scanners[1] = 1;

    gAirport.outputs[0] = gAirport.beltSize[0] - 2;
    gAirport.outputs[1] = gAirport.beltSize[1] - 2;
}

void StartAirport()
{
    ResetSuitcases(); 
    dcInput_InitializePad(&(gAirport.input[0]), 0);
    dcInput_InitializePad(&(gAirport.input[1]), 1);    

    gAirport.lives = gStartLives; 
    gAirport.score = 0; 
    gAirport.paused = false;
    gDiffiultyLevel = 0;

    CreateGraph(); 

    for (int i=0;i<2;++i)
    { 
        int spawnerTime = gDiffiultyLevel > 1? 80 : gSpawnTimerBase;
        spawnerTime = gDiffiultyLevel > 4? 20 : spawnerTime;
        int range = gDiffiultyLevel > 4? 10 : gSpawnTimerRange;
        gAirport.nextSpawn[i] = GetRandomNumber(spawnerTime,range);
    }
    // load textures
    dcRender_LoadTexture(&gAirport.pathTexture, _binary_data_Path_Texture2_tim_start);
    dcRender_LoadTexture(&gAirport.pathTexture, _binary_data_Path_Texture_tim_start);
    dcRender_LoadTexture(&gAirport.groundP1, _binary_data_Game_Ground_P1_tim_start);
    dcRender_LoadTexture(&gAirport.groundP2, _binary_data_Game_Ground_P2_tim_start);
    dcRender_LoadTexture(&gAirport.scannersTex, _binary_data_Scanners_Texture_tim_start);

    dcRender_LoadTexture(&gHeartEmpty, _binary_data_HeartEmpty_tim_start);
    dcRender_LoadTexture(&gHeartFull, _binary_data_HeartFull_tim_start);

    dcRender_LoadTexture(&gButtonTriangle, _binary_data_ButtonTriangle_tim_start);
    dcRender_LoadTexture(&gButtonSquare, _binary_data_ButtonSquare_tim_start);
    dcRender_LoadTexture(&gButtonCircle, _binary_data_ButtonCircle_tim_start);

    //Icons
    dcRender_LoadTexture( &gContentScans[0][0][0], _binary_data_CamisetaRoja_tim_start); 
    dcRender_LoadTexture( &gContentScans[0][0][1], _binary_data_SocksRoja_tim_start); 
    dcRender_LoadTexture( &gContentScans[0][1][0], _binary_data_BombaRoja_tim_start); 
    dcRender_LoadTexture( &gContentScans[0][1][1], _binary_data_PistolaRoja_tim_start);  
    dcRender_LoadTexture( &gContentScans[0][2][0], _binary_data_DrogasRoja_tim_start); 
    dcRender_LoadTexture( &gContentScans[0][2][1], _binary_data_JeringaRoja_tim_start); 
    dcRender_LoadTexture( &gContentScans[0][3][0], _binary_data_AbuelaRoja_tim_start); 
    dcRender_LoadTexture( &gContentScans[0][3][1], _binary_data_MermaidRoja_tim_start); 

    dcRender_LoadTexture( &gContentScans[1][0][0], _binary_data_CamisetaAzul_tim_start); 
    dcRender_LoadTexture( &gContentScans[1][0][1], _binary_data_SocksAzul_tim_start); 
    dcRender_LoadTexture( &gContentScans[1][1][0], _binary_data_BombaAzul_tim_start); 
    dcRender_LoadTexture( &gContentScans[1][1][1], _binary_data_PistolaAzul_tim_start); 
    dcRender_LoadTexture( &gContentScans[1][2][0], _binary_data_DrogasAzul_tim_start); 
    dcRender_LoadTexture( &gContentScans[1][2][1], _binary_data_JeringaAzul_tim_start);          
    dcRender_LoadTexture( &gContentScans[1][3][0], _binary_data_AbuelaAzul_tim_start); 
    dcRender_LoadTexture( &gContentScans[1][3][1], _binary_data_MermaidAzul_tim_start);  

    //load audios
    dcAudio_SfxLoad(&gAudio, &gAirport.heartLoose, (u_char *)_binary_data_HeartLoose_vag_start);
    dcAudio_SfxLoad(&gAudio, &gAirport.itemOK, (u_char *)_binary_data_ItemOK_vag_start);
}

void TrySpawnSuitcaseAtBelt(unsigned char beltId)
{
    Suitcase* newSuitcase = SpawnSuitcase();
    if ( newSuitcase )
    { 
        //Setup Suitcase 
        int maxContentAllowed = 2; 
        if ( gDiffiultyLevel > 2 ) { ++maxContentAllowed; }
        if ( gDiffiultyLevel > 3 ) { ++maxContentAllowed; }

        SetupSuitcase(newSuitcase, GetRandomNumber(0,MAX_SHAPES), GetRandomNumber(0,MAX_PATTERNS), GetRandomNumber(0,maxContentAllowed), GetRandomNumber(0, ITEM_VARIANTS));

        const int suitcaseIndex = GetSuitcaseIndex(newSuitcase);

        gAirport.gSuitcaseStates[suitcaseIndex].beltId   = beltId;
        gAirport.gSuitcaseStates[suitcaseIndex].prevNode = -1;
        gAirport.gSuitcaseStates[suitcaseIndex].nextNode = 0;
        gAirport.gSuitcaseStates[suitcaseIndex].timer    = 0; //force recompute
        gAirport.gSuitcaseStates[suitcaseIndex].totalTimer = 1; //force recompute

        //Locate initial suitcase position
        newSuitcase->position = GetNodes(beltId)[0];
        newSuitcase->yaw = GetRandomNumber(0,4096); 
        
        SuitcaseUpdateRotation(newSuitcase);
    }
}

bool IsSpawnNode(int nodeId)
{
    return nodeId == 0;
}

bool IsScannerNode(int beltId, int nodeId )
{
    return gAirport.scanners[beltId] == nodeId;
}

bool IsOutputNode(int beltId, int nodeId)
{
    return gAirport.outputs[beltId] == nodeId;
}

int FindNextNode(int beltId, int nodeId)
{
    int newNodeId = nodeId + 1; 
    return newNodeId < gAirport.beltSize[beltId] ? newNodeId : -1;
}

void ValidateSuitcase(int index)
{
    //TODO ~ add some feedback 
    const int beltId = gAirport.gSuitcaseStates[index].beltId;

    unsigned char content = GetSuitcase(index)->content;

    char validator = 0; 
    if ( dcInput_IsPressed(&gAirport.input[beltId], PADRup) )    { validator |= 2; }
    if ( dcInput_IsPressed(&gAirport.input[beltId], PADRleft) )  { validator |= 4; }
    if ( dcInput_IsPressed(&gAirport.input[beltId], PADRright) ) { validator |= 8; }
    if ( dcInput_IsPressed(&gAirport.input[beltId], PADRdown) )  { validator |= 16; }

    char contentMask = content == 0? 0 : 1 << content;

    //printf("Validating... %d against %d\n", contentMask, validator);

    if ( contentMask == validator ) 
    { 
        ++gAirport.score;
        dcAudio_SfxPlay(&gAirport.itemOK);
    }
    else if ( !gCheatInvicible )
    { 
        --gAirport.lives;
        dcAudio_SfxPlay(&gAirport.heartLoose);
        if ( gAirport.lives <= 0 )
        { 
            GameState_ChangeGameState(GAMEOVER_GAMESTATE);
        }
    }
}

void MoveSuitcase(int index, int elapsed)
{
    if ( !IsSuitcaseActive(index) )
    { 
        return;
    }
    
    //FntPrint("Case %d is %d \n", index, GetSuitcase(index)->content );  

    int belt     = gAirport.gSuitcaseStates[index].beltId; 
    int prevNode = gAirport.gSuitcaseStates[index].prevNode; 
    int nextNode = gAirport.gSuitcaseStates[index].nextNode; 

    gAirport.gSuitcaseStates[index].timer -= elapsed; 
    if (gAirport.gSuitcaseStates[index].timer <= 0)
    { 
        //State change 
        const int extraElapsed = -gAirport.gSuitcaseStates[index].timer;
        gAirport.gSuitcaseStates[index].prevNode = nextNode; //Advance node 

        GetSuitcase(index)->position = GetNodes(belt)[nextNode];

        if ( IsScannerNode(belt,nextNode) && prevNode != nextNode )
        { 
            //We just arrived to a scanner

            //TODO ~ ramonv ~ perform scanner wait 
            
            gAirport.gSuitcaseStates[index].timer = gScannerWaitTime; 
            gAirport.gSuitcaseStates[index].totalTimer = gScannerWaitTime;
            MoveSuitcase(index, extraElapsed);
        }
        else 
        { 
            if ( IsOutputNode(belt,nextNode) )
            {
                //We just arrives to the output
                ValidateSuitcase(index); 
            }

            int newNextNode = FindNextNode(belt, nextNode); 
            int newPrevNode = nextNode; 
            gAirport.gSuitcaseStates[index].nextNode = newNextNode; 

            if ( newNextNode < 0 )
            { 
                //Path Termination / Despawn 
                DestroySuitcase( GetSuitcase(index) ); 
            }
            else 
            { 
                VECTOR prevPos = GetNodes(belt)[newPrevNode];
                VECTOR nextPos = GetNodes(belt)[newNextNode];

                //Regular advance
                long dx = nextPos.vx - prevPos.vx; 
                long dy = nextPos.vy - prevPos.vy; 
                long dz = nextPos.vz - prevPos.vz; 
                long distance2 = dx*dx + dy*dy + dz*dz; 
                long distance = csqrt(distance2 << 12) >> 12;
                int timeToNext = distance / gSuitcaseSpeed; 

                gAirport.gSuitcaseStates[index].timer      = timeToNext; 
                gAirport.gSuitcaseStates[index].totalTimer = timeToNext;

                MoveSuitcase(index, extraElapsed);
            }
        }
    }
    else if ( prevNode != nextNode )
    { 
        //interpolate between first position and the last 

        const int totalTime = gAirport.gSuitcaseStates[index].totalTimer;
        const int remainingtime =  gAirport.gSuitcaseStates[index].timer;
        const int factor = (256*(totalTime - remainingtime)) / totalTime; 

        VECTOR prevPos = GetNodes(belt)[prevNode];
        VECTOR nextPos = GetNodes(belt)[nextNode];

        //move positions to the positive space, interpolate and bring back 

        const long positiveOffset = 4096; 

        Suitcase* suitcase = GetSuitcase(index);
        suitcase->position.vx = lerpS(prevPos.vx + positiveOffset,nextPos.vx + positiveOffset,factor) - positiveOffset;
        suitcase->position.vy = lerpS(prevPos.vy + positiveOffset,nextPos.vy + positiveOffset,factor) - positiveOffset;
        suitcase->position.vz = lerpS(prevPos.vz + positiveOffset,nextPos.vz + positiveOffset,factor) - positiveOffset;

        //TODO ~ ramonv ~ orient yaw ( optional )
    } 
}

void UpdateCheats(int padId)
{     
    if ( dcInput_IsPressed(&gAirport.input[padId], PADL1) && dcInput_IsPressed(&gAirport.input[padId], PADR1) )
    { 
        if ( dcInput_BecomesPressed(&gAirport.input[padId],PADLup))
        { 
            gAirport.score += gDifficultyScoreUpgrade;
        }

        if ( dcInput_BecomesPressed(&gAirport.input[padId],PADLdown))
        { 
            gAirport.score -= gDifficultyScoreUpgrade;
            if ( gAirport.score < 0 ) gAirport.score = 0; 
        }

        if ( dcInput_BecomesPressed(&gAirport.input[padId],PADstart))
        { 
            GameState_ChangeGameState(GAMEOVER_GAMESTATE);
        }

        if ( dcInput_BecomesPressed(&gAirport.input[padId],PADRdown))
        { 
            gCheatInvicible = !gCheatInvicible;
        }
    }

    if ( dcInput_IsPressed(&gAirport.input[padId], PADL2) && dcInput_IsPressed(&gAirport.input[padId], PADR2) )
    {
        if ( dcInput_BecomesPressed(&gAirport.input[padId],PADLup))
        { 
            gRedColorIntensity += dcInput_IsPressed(&gAirport.input[padId],PADRdown)? 10 : 1; 
            if ( gRedColorIntensity > 255 ) gRedColorIntensity = 255;
            printf("Red Intensity to %d\n", gRedColorIntensity);
        }
        
        if ( dcInput_BecomesPressed(&gAirport.input[padId],PADLdown))
        { 
            gRedColorIntensity -= dcInput_IsPressed(&gAirport.input[padId],PADRdown)? 10 : 1; 
            if ( gRedColorIntensity < 0 ) gRedColorIntensity = 0;
            printf("Red Intensity to %d\n", gRedColorIntensity);
        }

        if ( dcInput_BecomesPressed(&gAirport.input[padId],PADLright))
        { 
            gBlueColorIntensity += dcInput_IsPressed(&gAirport.input[padId],PADRdown)? 10 : 1; 
            if ( gBlueColorIntensity > 255 ) gBlueColorIntensity = 255;
            printf("Blue Intensity to %d\n", gBlueColorIntensity);
        }
        
        if ( dcInput_BecomesPressed(&gAirport.input[padId],PADLleft))
        { 
            gBlueColorIntensity -= dcInput_IsPressed(&gAirport.input[padId],PADRdown)? 10 : 1; 
            if ( gBlueColorIntensity < 0 ) gBlueColorIntensity = 0;
            printf("Blue Intensity to %d\n", gBlueColorIntensity);
        }

        if ( dcInput_IsPressed(&gAirport.input[padId],PADRdown))
        { 
            FntPrint("COLOR BOOSTER, RED: %d BLUE: %d\n", gRedColorIntensity, gBlueColorIntensity);
        }
    }
}

void UpdateBelts(int elapsed)
{ 
    gPathOffset -= elapsed * gBeltSpeed;
    while (gPathOffset < 0) { gPathOffset += 64; }
}

void UpdateAirport(int elapsed)
{
    //Update pause
    if ( dcInput_BecomesPressed(&gAirport.input[0], PADstart) || dcInput_BecomesPressed(&gAirport.input[1], PADstart))
    {
        gAirport.paused = !gAirport.paused;
    }

    UpdateCheats(0);
    UpdateCheats(1);

    if ( gAirport.paused )
    { 
        return; 
    }

    // Update World 
    UpdateBelts(elapsed);

    // Move current suitcases
    for (int i=0;i<MAX_SUITCASES;++i)
    { 
        MoveSuitcase(i, elapsed); 
    }    

    // Update Difficulty
    gDiffiultyLevel = gAirport.score / gDifficultyScoreUpgrade;

    // Trigger new spawns 
    const int numBelts = gDiffiultyLevel > 0 ? 2 : 1; 
    for (int i=0;i<numBelts;++i)
    { 
        gAirport.nextSpawn[i] -= elapsed;

        if ( gAirport.nextSpawn[i] < 0 )
        {           
            //reset timer
            gAirport.nextSpawn[i] = GetRandomNumber(gSpawnTimerBase,gSpawnTimerRange);
            TrySpawnSuitcaseAtBelt(i);
        }
    }
}

void RenderBackground(SDC_Render* render, SDC_Camera* camera) {
    MATRIX MVP = camera->viewMatrix;

    drawParamsBackground.tim = &gAirport.scannersTex;
    dcRender_DrawMeshFast(render, &Exit_P1_Mesh, &MVP, &drawParamsBackground, 0 );
    dcRender_DrawMeshFast(render, &Exit_P2_Mesh, &MVP, &drawParamsBackground, 0 );

    dcRender_DrawMeshFast(render, &Scanner_P1_Mesh, &MVP, &drawParamsBackground, 0 );
    dcRender_DrawMeshFast(render, &Scanner_P2_Mesh, &MVP, &drawParamsBackground, 0 );

    drawParamsBackground.tim = &gAirport.groundP1;
    dcRender_DrawMeshFast(render, &Game_Ground_P1_Mesh, &MVP, &drawParamsBackground, 0 );
    drawParamsBackground.tim = &gAirport.groundP2;
    dcRender_DrawMeshFast(render, &Game_Ground_P2_Mesh, &MVP, &drawParamsBackground, 0 );

    drawParamsBackground.tim = &gAirport.pathTexture;
    dcRender_DrawMeshFast(render, &Path_P1_Mesh, &MVP, &drawParamsBackground, gPathOffset );
    dcRender_DrawMeshFast(render, &Path_P2_Mesh, &MVP, &drawParamsBackground, gPathOffset );    

    dcRender_DrawMeshFast(render, &Divider_Mesh, &MVP, &drawParamsBackgroundBlack, 0 );
}

void RenderScanners(SDC_Render* render, SDC_Camera* camera)
{
    SDC_DrawParams drawParams = {
        .tim = NULL,
        .constantColor = {127, 127, 127},
        .bLighting = 0,
        .bUseConstantColor = 1
    };

    for (int i=0;i<MAX_SUITCASES;++i)
    {
        unsigned char beltId = gAirport.gSuitcaseStates[i].beltId;
        char prevNode = gAirport.gSuitcaseStates[i].prevNode;
        char nextNode = gAirport.gSuitcaseStates[i].nextNode;
        if ( prevNode == nextNode && IsScannerNode(beltId, nextNode) )
        {
            unsigned char thisContent = GetSuitcase(i)->content;
            unsigned char thisContentVariation = GetSuitcase(i)->contentVariation;
            
            SDC_Mesh3D* mesh = beltId ? &ScannerQuad_P2_Mesh : &ScannerQuad_P1_Mesh;
            SDC_TIM_IMAGE* tim = &(gContentScans[beltId][thisContent][thisContentVariation]);
            if ( beltId == 0 )
            {
                drawParams.constantColor.r = gRedColorIntensity;
                drawParams.constantColor.g = gRedColorIntensity; 
                drawParams.constantColor.b = gRedColorIntensity; 
            }
            else 
            { 
                drawParams.constantColor.r = gBlueColorIntensity;
                drawParams.constantColor.g = gBlueColorIntensity; 
                drawParams.constantColor.b = gBlueColorIntensity; 
            }
            drawParams.tim = tim;
            dcRender_DrawMeshFast(render, mesh, &camera->viewMatrix, &drawParams, 0 );
        }
    }
}

void RenderUI(SDC_Render* render)
{ 
    DVECTOR uv;
    uv.vx = 0;
    uv.vy = 0;

    int legendY = 85; 
    int legendYStride = 20;
    int legendTextOffsetY = 5; 

    CVECTOR color = {127, 127, 127};
    CVECTOR colorBlack = {0, 0, 0};
    char txt[256];
    sprintf(txt, "%d %s\n", gAirport.score, gCheatInvicible? "[GOD]": "");
    dcFont_Print(render, 520, 85 + legendTextOffsetY, &colorBlack, "SCORE:");
    dcFont_Print(render, 520, 95 + legendTextOffsetY, &colorBlack, txt);

    //Legend 
    dcRender_DrawSpriteRect(render, &gButtonTriangle, 20, legendY, 32, 16, &uv, &color);
    dcFont_Print(render, 60, legendY + legendTextOffsetY, &colorBlack, "WEAPONS");

    legendY += legendYStride;
    dcRender_DrawSpriteRect(render, &gButtonSquare, 20, legendY, 32, 16, &uv, &color);
    dcFont_Print(render, 60, legendY + legendTextOffsetY, &colorBlack, "DRUGS");

    legendY += legendYStride;
    dcRender_DrawSpriteRect(render, &gButtonCircle, 20, legendY, 32, 16, &uv, &color);
    dcFont_Print(render, 60, legendY + legendTextOffsetY, &colorBlack, "IMMIGRATION");

    //Hearts
    int startX = 210; 
    for ( int i=0;i<gAirport.lives;++i)
    { 
        dcRender_DrawSpriteRect(render, i >= gAirport.lives? &gHeartEmpty : &gHeartFull, startX, 210, 32, 16, &uv, &color);
        startX += 32+5;
    }

    //Render difficulty bar
    int diffBar = gDiffiultyLevel > 5 ? 5 : gDiffiultyLevel; 

    CVECTOR color5 = {255,0,0};
    CVECTOR color4 = {127,0,0};
    CVECTOR color3 = {127,0,0};
    CVECTOR color2 = {0,127,0};
    CVECTOR color1 = {0,127,0};
    CVECTOR color0 = {0,255,0};

    CVECTOR diffColor =  gDiffiultyLevel > 4 ? color5 : 
                        (gDiffiultyLevel > 3 ? color4 : 
                        (gDiffiultyLevel > 2 ? color3 : 
                        (gDiffiultyLevel > 1 ? color2 : 
                        (gDiffiultyLevel > 0 ? color1 : 
                        color0 )))) ; 

    dcRender_DrawSpriteRect(render, NULL, 210, 225, 39*diffBar, 2, NULL, &diffColor);

    if ( gAirport.paused )
    {
        dcFont_Print(render, 256, 200, &colorBlack, "PAUSED");
    }
}

void RenderAirport(SDC_Render* render, SDC_Camera* camera)
{
    for (int i=0;i<2;++i)
    {
        dcInput_UpdateInput(&gAirport.input[i]);
    }

    // dcPerformance_BeginCounter();
    RenderBackground(render, camera); 
    // dcPerformance_EndCounterPrintf("RenderBackground");

    // dcPerformance_BeginCounter();
    RenderSuitcases(render, camera);
    // dcPerformance_EndCounterPrintf("RenderSuitcases");

    // dcPerformance_BeginCounter();
    RenderScanners(render, camera);
    // dcPerformance_EndCounterPrintf("RenderScanners");

    // dcPerformance_BeginCounter();
    RenderUI(render);
    // dcPerformance_EndCounterPrintf("RenderUI");
   
}