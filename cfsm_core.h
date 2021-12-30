#ifndef __CFSM_CORE_H__
#define __CFSM_CORE_H__

#ifndef NULL
#define NULL ((void*)0)
#endif
typedef unsigned char cfsm_modeIndex_Type;
#define cfsm_modeIndex_Invalid (0xffu)
typedef unsigned char cfsm_modeSwitchFlag_type;
#define cfsm_modeSwitchFlag_invalid      0
#define cfsm_modeSwitchFlag_valid        1
typedef void (*cfsm_modeInitFun_Type)(cfsm_modeIndex_Type lastModeIndex);
typedef void (*cfsm_modeLoopFun_Type)();
typedef void (*cfsm_modeSwitchActionFun_Type)(cfsm_modeIndex_Type nextModeIndex);
typedef cfsm_modeSwitchFlag_type (*cfsm_modeSwitchConditionFun_Type)(cfsm_modeIndex_Type nextModeIndex);



typedef struct
{
    cfsm_modeIndex_Type                  nextModeIndex;
    cfsm_modeSwitchConditionFun_Type     ConditionFun;
    cfsm_modeSwitchActionFun_Type        ActionFun;
}cfsm_process_Type;

typedef struct
{
    cfsm_modeInitFun_Type                InitFun;
    cfsm_modeLoopFun_Type                LoopFun;
    cfsm_process_Type                    *processTab;
}cfsm_mode_Type;

typedef struct
{
    cfsm_modeIndex_Type                  curIndex;
    cfsm_mode_Type                       *modePool;
    
}cfsm_Type;

extern void cfsm_mode_start(cfsm_Type *fsm, cfsm_modeIndex_Type firstModeIndex);
extern void cfsm_mode_run(cfsm_Type *fsm);
#endif /*__CFSM_CORE_H__*/

