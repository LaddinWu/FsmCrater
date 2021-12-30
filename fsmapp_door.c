#include "fsmapp_door.h"
#include <stdio.h>

static inline void fsmDebug_out(char *str)
{
	printf(str);
}

/*状态机: door 自动生成 不要编辑↓*/

/*opened 门打开状态*/
static void door_openedInitFun(cfsm_modeIndex_Type lastModeIndex);
static void door_openedLoopFun(void);
static cfsm_modeSwitchFlag_type door_ConditionFun_opened_to_closed(cfsm_modeIndex_Type nextModeIndex);
static void door_ActionFun_opened_to_closed(cfsm_modeIndex_Type nextModeIndex);
static const cfsm_process_Type door_opened_processTab[]=
{
    {FSMNODEINDEX_door_closed,door_ConditionFun_opened_to_closed,door_ActionFun_opened_to_closed},

    {cfsm_modeIndex_Invalid,(void*)0,(void*)0},
};
/*closed 门关闭状态*/
static void door_closedInitFun(cfsm_modeIndex_Type lastModeIndex);
static void door_closedLoopFun(void);
static cfsm_modeSwitchFlag_type door_ConditionFun_closed_to_opened(cfsm_modeIndex_Type nextModeIndex);
static void door_ActionFun_closed_to_opened(cfsm_modeIndex_Type nextModeIndex);
static const cfsm_process_Type door_closed_processTab[]=
{
    {FSMNODEINDEX_door_opened,door_ConditionFun_closed_to_opened,door_ActionFun_closed_to_opened},

    {cfsm_modeIndex_Invalid,(void*)0,(void*)0},
};
static const cfsm_mode_Type ModeTab_door[]=
{
    [FSMNODEINDEX_door_opened]={door_openedInitFun,door_openedLoopFun,(cfsm_process_Type *)door_opened_processTab},
    [FSMNODEINDEX_door_closed]={door_closedInitFun,door_closedLoopFun,(cfsm_process_Type *)door_closed_processTab},
};
cfsm_Type fsmObj_door=
{
    cfsm_modeIndex_Invalid,
    (cfsm_mode_Type *)ModeTab_door
};
/*状态机: door 自动生成 不要编辑↑*/

/*状态机: door 用户代码区↓*/

/************************这部分代码由用户实现*************************/
unsigned int count = 0;
/************************这部分代码由用户实现*************************/

    /*opened 门打开状态↓*/
static void door_openedInitFun(cfsm_modeIndex_Type lastModeIndex)
{
    fsmDebug_out("node init: the state is opened\r\n");
}
static void door_openedLoopFun(void)
{
  /************************这部分代码由用户实现*************************/
    count++;
    printf("this is open loop .count=%d\r\n",count);
  /************************这部分代码由用户实现*************************/
}
        /*转移条件函数: [opened 门打开状态]->[closed 门关闭状态]*/
static cfsm_modeSwitchFlag_type door_ConditionFun_opened_to_closed(cfsm_modeIndex_Type nextModeIndex)
{
  /************************这部分代码由用户实现*************************/
    printf("this is open switch close condition\r\n");
    if(count > 150)
    {
        return cfsm_modeSwitchFlag_valid;
    }
  /************************这部分代码由用户实现*************************/
    return cfsm_modeSwitchFlag_invalid;
}
        /*转移动作函数: [opened 门打开状态]->[closed 门关闭状态]*/
static void door_ActionFun_opened_to_closed(cfsm_modeIndex_Type nextModeIndex)
{
  /************************这部分代码由用户实现*************************/
    count = 0;
    printf("this is open to closed action\r\n");
  /************************这部分代码由用户实现*************************/
}
    /*opened 门打开状态↑*/

    /*closed 门关闭状态↓*/
static void door_closedInitFun(cfsm_modeIndex_Type lastModeIndex)
{
    fsmDebug_out("node init: the state is closed\r\n");
}
static void door_closedLoopFun(void)
{
  /************************这部分代码由用户实现*************************/
    count++;
    printf("this is close loop. count=%d\r\n",count);
  /************************这部分代码由用户实现*************************/
}
        /*转移条件函数: [closed 门关闭状态]->[opened 门打开状态]*/
static cfsm_modeSwitchFlag_type door_ConditionFun_closed_to_opened(cfsm_modeIndex_Type nextModeIndex)
{
  /************************这部分代码由用户实现*************************/
    printf("this is close switch open condition\r\n");
        if(count > 100)
    {
        return cfsm_modeSwitchFlag_valid;
    }
  /************************这部分代码由用户实现*************************/
    return cfsm_modeSwitchFlag_invalid;
}
        /*转移动作函数: [closed 门关闭状态]->[opened 门打开状态]*/
static void door_ActionFun_closed_to_opened(cfsm_modeIndex_Type nextModeIndex)
{
  /************************这部分代码由用户实现*************************/
    count = 0;
    printf("this is close to open action\r\n");
  /************************这部分代码由用户实现*************************/
}
    /*closed 门关闭状态↑*/

/*状态机: door 用户代码区↑*/

