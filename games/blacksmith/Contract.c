#include "Contract.h"

void ContractInit(ContractData* Data)
{
    //  Constants.
    Data->BlueEnemiesToPick  = 15;
    Data->CurrentPickedBlues = 0;

    Data->RedEnemiesToEvade = 15;
    Data->GreenEnemiesToEvade = 15;
    Data->YellowEnemiesToEvade  = 15;
    Data->EnemiesToLose = 15;
    Data->InitSpawnEnemies = 36;
}

void ContractPickedBlue(ContractData* Data)
{
   Data->CurrentPickedBlues++; 
}

void ContractPickedRed(ContractData* Data)
{
    Data->RedEnemiesToEvade--;
    Data->EnemiesToLose--;
}

void ContractPickedGreen(ContractData* Data)
{
   Data->GreenEnemiesToEvade--;
   Data->EnemiesToLose--;
}

void ContractPickedYellow(ContractData* Data)
{
   Data->YellowEnemiesToEvade--;
   Data->EnemiesToLose--;
}

int ContractCheckWon(ContractData* Data)
{
    return Data->BlueEnemiesToPick <= Data->CurrentPickedBlues;
}

int ContractCheckDefeat(ContractData* Data)
{
    return Data->EnemiesToLose < 1;
}