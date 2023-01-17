#ifndef _DC_SPRITETEST_GAMESTATE
#define _DC_SPRITETEST_GAMESTATE

typedef struct
{
} FSpriteTestGameState;

void STGS_Init(FSpriteTestGameState* GameState);
void STGS_Update(FSpriteTestGameState* GameState);
void STGS_Close(FSpriteTestGameState* GameState);

#endif