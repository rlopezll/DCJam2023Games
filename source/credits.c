
#include <string.h>

const char *creditsArray[] =
{
    "GAMEDEV CHALLENGE\0",
    "2023 PSX\0",
    "\0",
    "ALBERT DEL ARCO\0",
    "ALEX XAMENA\0",
    "ANDER CELAYA\0",
    "ARTURO GALBETE\0",
    "DANI GALACHO\0",
    "DAVID SERRAT\0",
    "DAVID SOLER\0",
    "ENRIQUE RUBIO\0",
    "GABI ARROYO\0",
    "JAMES PHELAN\0",
    "JOAN ARMEN\0",
    "MANEL HIDALGO\0",
    "MIQUEL IZQUIERDO\0",
    "MIRIAM ARANDA\0",
    "OSCAR BOIX\0",
    "QUIM ROMO\0",
    "RAMON GARCIA\0",
    "RAMON VILADOMAT\0",
    "RUBEN LOPEZ\0"
};

//char creditsPadding[2];

int numCreditsNames = sizeof(creditsArray) / sizeof(char*);
int creditsLineLength[sizeof(creditsArray) / sizeof(char*)];

void InitCreditsLength()
{
    for( int i = 0; i < numCreditsNames; ++i)
    {
        creditsLineLength[i] = strlen(creditsArray[i]);
    }
}
