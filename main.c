#include <stdio.h>
#include "fsmapp_door.h"

void main(void)
{
    char flag = 0;
    cfsm_mode_start(&fsmObj_door,FSMNODEINDEX_door_opened);
    while(1)
    {
        cfsm_mode_run(&fsmObj_door);

    }
}
