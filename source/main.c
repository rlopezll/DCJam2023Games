// screw you code formatter, this one needs to stay on top
#include <stdlib.h>
// now we need to have libgte.h
#include <libgte.h>
// then, these can work; the psyq library is badly written and won't include what it uses
#include <libetc.h>
#include <libgpu.h>
#include <stdio.h>
#include <types.h>
#include <libapi.h>

#include "dcMath.h"
#include "dcRender.h"
#include "dcMemory.h"

#define TLOAD_ADDR 0x80100000;

char* jamApps[] = { "cdrom:\\TANKE.EXE;1","cdrom:\\ROGUE.EXE;1","cdrom:\\BARCO.EXE;1", "cdrom:\\MALETA.EXE;1" };
char padding[3];
long appLoadAddress[4];
struct EXEC execs[4];
int numApps = 4;


int main(void) 
{
restart: 
    dcMemory_Init();
    PadInit(0);
    _96_init();

    SDC_Render render;
    int  width = 640;
    int  height = 240;
    CVECTOR bgColor = {60, 120, 120};
    dcRender_Init(&render, width, height, bgColor, 4096, 8192, RENDER_MODE_PAL);

    int selectedApp = 0;
    int prevPadUp = 0;
    int prevPadDown = 0;
    int prevXDown = 0;


    for(int i = 0; i < numApps; i++)
    {
        appLoadAddress[i] = LoadTest(jamApps[i], &execs[i]);
    }
    

    while (1) {

        // Read pad state and move primitive
        u_long padState = PadRead(0);

        if( _PAD(0,PADLup ) & padState )
        {
            if( !prevPadUp)
            {
                selectedApp = DC_MAX( selectedApp - 1, 0);
                prevPadUp = 1;
            }
        }
        else prevPadUp = 0;

        if( _PAD(0,PADLdown ) & padState )
        {
            if(!prevPadDown)
            {
                selectedApp = DC_MIN( selectedApp + 1, numApps - 1);
                prevPadDown = 1;
            }
        }
        else prevPadDown = 0;

        if( _PAD(0,PADRdown ) & padState )
        {
            if( !prevXDown )
            {
                prevXDown = 1;

                struct EXEC exec;
                if(Load(jamApps[selectedApp], &exec))
                {
                    printf("Loaded %s successfully!\n", jamApps[selectedApp]);
                    ResetGraph(3);
                    PadStop();
	                StopCallback();
                    EnterCriticalSection();
                    Exec(&exec, 0, 0);
                }
                else printf("Failed to load %s!\n", jamApps[selectedApp]);
            }            

        }
        else prevXDown = 0;

        FntPrint(
            "GameDev Challenge 2023 Launcher\n"
            "Selected app: %s\nLoad @ %08x\n"
            ".text @0x%08x %d bytes\n"
            ".data @0x%08x %d bytes\n"
            ".bss @0x%08x %d bytes\n"
            ".stack @0x%08x %d bytes\n"
            , jamApps[selectedApp], appLoadAddress[selectedApp], 
            execs[selectedApp].t_addr, execs[selectedApp].t_size,
            execs[selectedApp].d_addr, execs[selectedApp].d_size,
            execs[selectedApp].b_addr, execs[selectedApp].b_size,
            execs[selectedApp].s_addr, execs[selectedApp].s_size
        );

        dcRender_SwapBuffers(&render);
    }

    return 0;
}