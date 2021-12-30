#include "cfsm_core.h"



void cfsm_mode_start(cfsm_Type *fsm, cfsm_modeIndex_Type firstModeIndex)
{
    fsm->curIndex=firstModeIndex;
    if(fsm->modePool[firstModeIndex].InitFun!=NULL){
        fsm->modePool[firstModeIndex].InitFun(cfsm_modeIndex_Invalid);
    }
}

void cfsm_mode_run(cfsm_Type *fsm)
{
    cfsm_modeIndex_Type i=0;
    cfsm_modeIndex_Type lastindex=cfsm_modeIndex_Invalid;
    unsigned char changedFlag=0;

    do
    {
        changedFlag=0;
        i=0;
        while(fsm->modePool[fsm->curIndex].processTab[i].nextModeIndex!=cfsm_modeIndex_Invalid)
        {
            if(fsm->modePool[fsm->curIndex].processTab[i].ConditionFun!=NULL)
            {
                if(fsm->modePool[fsm->curIndex].processTab[i].ConditionFun(\
                    fsm->modePool[fsm->curIndex].processTab[i].nextModeIndex)==cfsm_modeSwitchFlag_valid)
                {
                    if(fsm->modePool[fsm->curIndex].processTab[i].ActionFun!=NULL)
                    {
                        fsm->modePool[fsm->curIndex].processTab[i].ActionFun(\
                            fsm->modePool[fsm->curIndex].processTab[i].nextModeIndex);
                    }
                    lastindex=fsm->curIndex;
                    fsm->curIndex=fsm->modePool[fsm->curIndex].processTab[i].nextModeIndex;
                    if(fsm->modePool[fsm->curIndex].InitFun!=NULL){
                        fsm->modePool[fsm->curIndex].InitFun(lastindex);
                    }
                    changedFlag=1;
                    break;
                }
            }
            i++;
        }
    }
    while(changedFlag);
    
    fsm->modePool[fsm->curIndex].LoopFun();

    
    
}

