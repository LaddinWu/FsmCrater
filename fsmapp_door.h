#ifndef __FSMAPP_DOOR_H__
#define __FSMAPP_DOOR_H__


#include "cfsm_core.h"

#define FSMNODEINDEX_door_opened        (1)    /* 门打开状态 */
#define FSMNODEINDEX_door_closed        (2)    /* 门关闭状态 */

extern cfsm_Type fsmObj_door;


#if 0/*demo*/
void main(void)
{
    cfsm_mode_start(&fsmObj_door,FSMNODEINDEX_door_opened);
    while(1)
    {
        cfsm_mode_run(&fsmObj_door);
    }
}
#endif

#endif

