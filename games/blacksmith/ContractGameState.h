#ifndef _DC_CONTRACT_GAMESTATE
#define _DC_CONTRACT_GAMESTATE

typedef struct
{
    int Manel;
} FContractGameState;

void CGS_Init(FContractGameState* GameState);
void CGS_Update(FContractGameState* GameState);
void CGS_Close(FContractGameState* GameState);

#endif