#include "engine.h"

int main(void) 
{   
    Init(&GEngineInstance);

    while (1)
    {
        Update(&GEngineInstance);
    }
    
    Close(&GEngineInstance);

    return 0;
}