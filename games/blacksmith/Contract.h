#ifndef _DC_CONTRACT_DATA
#define _DC_CONTRACT_DATA

typedef struct
{
    int BlueEnemiesToPick;
    int CurrentPickedBlues;

    int RedEnemiesToEvade;
    int GreenEnemiesToEvade;
    int YellowEnemiesToEvade;
    int EnemiesToLose;
    int InitSpawnEnemies;
} ContractData;

void ContractInit(ContractData* Data);

void ContractPickedBlue(ContractData* Data);
void ContractPickedRed(ContractData* Data);
void ContractPickedGreen(ContractData* Data);
void ContractPickedYellow(ContractData* Data);

int ContractCheckWon(ContractData* Data);
int ContractCheckDefeat(ContractData* Data);

#endif