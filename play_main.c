#include <stdio.h>
#if 0
#include "fsmapp_door.h"

void main(void)
{
    char flag = 0;
    cfsm_mode_start(&fsmObj_door,FSMNODEINDEX_door_opened);
    while(1)
    {
        cfsm_mode_run(&fsmObj_door);

        // if(flag != 0)
        // {
        //     flag =0;
        //     fsmObj_door.curIndex = FSMNODEINDEX_door_closed;
        //     // printf("current index:%d\r\n",fsmObj_door.curIndex);
        //     // fsmObj_door.modePool[fsmObj_door.curIndex].processTab[0].ActionFun(\
        //     // fsmObj_door.modePool[fsmObj_door.curIndex].processTab[0].nextModeIndex);

        //     // printf("current index:%d\r\n",fsmObj_door.curIndex);
        // }
        // else
        // {
        //     flag =1;
        //     fsmObj_door.curIndex = FSMNODEINDEX_door_opened;
        //     // printf("current index:%d\r\n",fsmObj_door.curIndex);
        //     //             fsmObj_door.modePool[fsmObj_door.curIndex].processTab[0].ActionFun(\
        //     // fsmObj_door.modePool[fsmObj_door.curIndex].processTab[0].nextModeIndex);
        //     // printf("current index:%d\r\n",fsmObj_door.curIndex);
        // }

    }
}
#endif
#include "play_sm.h"
#include "string.h"

struct door{
    struct fsmContext _fsm;
};

struct door DOOR_ctxt;

void Init(struct door *this)
{
    memset(this,0,sizeof(struct door));
    fsmContext_Init(&this->_fsm,this);
    printf("fsm init success\r\n");
}
//打印hello word
//打印hello word


void main(void)
{
    char flag = 0;
    Init(&DOOR_ctxt);
    fsmContext_EnterStartState(&DOOR_ctxt);
    fsmContext_condition_to_close(&DOOR_ctxt);
    fsmContext_condition_to_open(&DOOR_ctxt);
    // while(1)
    // {

    //     printf("test is ok\r\n");
    // }
}
