/******************************************************************************
 *
 * Copyright (C) 2012-2023 Cadence Design Systems, Inc.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 * asf_common.c
 * Common helper Functions for tests
 ******************************************************************************/
#include <string.h>
#include <stdio.h>
#include "cdn_errno.h"
#include "asf_priv.h"
#include "asf_if.h"
#include "asf_common.h"

#include "cdn_log.h"

extern ASF_Instance asfInstances[];
extern ASF_Callbacks callback;

uint8_t getInstanceId(ASF_PrivateData *privetData) {
    uint8_t i=0;
    for(i=0; i < ASF_INSTANCE_NUMBER; i++) {
        if(&asfInstances[i].priv == privetData) {
            return i;
        }
    }
    return 0;
}

void ASF_clearEventInfoObj(ASF_PrivateData *priv) {
    uint8_t id = getInstanceId(priv);
    
    memset((void*)&asfInstances[id].lastReportedEvent, 0, sizeof(asfInstances[id].lastReportedEvent));
    asfInstances[id].eventChanged = 0;
}

uint32_t ASF_checkEventObj(ASF_EventInfo *event, 
                          const char *expectedVersion, 
                          const char *expectedName, 
                          const ASF_EventErrorType expectedErrorCode,
                          const uint8_t expectedFatalEvent) {
    
    if(expectedVersion) {
        if(!strcmp((char*)event->version, expectedVersion)) 
            return CDN_EINVAL;
    }

    if(expectedName) {
        if(!strcmp((char*)event->name, expectedName)) 
            return CDN_EINVAL;
    }
    
    if(event->eventErrorCode != expectedErrorCode)
      return CDN_EINVAL;
      
    if(event->fatalEvent != expectedFatalEvent)
      return CDN_EINVAL;
  
    return CDN_EOK;          
}


void copyLastEventObject(ASF_PrivateData* privetData, ASF_EventInfo* eventInfo){
    uint8_t id = getInstanceId(privetData) ;
    asfInstances[id].eventChanged = 1;
    asfInstances[id].lastReportedEvent = *eventInfo;
}

void ASF_ClearSingleInstance(ASF_Instance * inst) {
    
    ASF_Stop(&inst->priv);
    ASF_Destroy(&inst->priv);
}

void ASF_ClearAllInstance() {
  uint8_t i; 
  
  /*Initialize all ASF inctance*/
  for(i=0; i < ASF_INSTANCE_NUMBER; i++) {    
    ASF_ClearSingleInstance(&asfInstances[i]);    
  }
 
}

uint32_t ASF_InitSingleInstance(ASF_Instance * inst) {
    ASF_SysReq memReq;  

    uint32_t ret;
  
    inst->status = 0;	   
    memset(&memReq,0,sizeof(memReq));
 
    ASF_Probe(&inst->config, &memReq);
    
    /*Clear privateData memory*/
    memset(&inst->priv,0,sizeof(ASF_PrivateData));
    
    //set all parameters:
    ret = ASF_Init(&inst->priv, &inst->config, &callback);

    if (ret != 0) {
        inst->status = TEST_ERR_INIT;	
    } 
  
    return inst->status;
}

uint32_t ASf_InitAllInstances(ASF_StatInfo * stat) {
  uint8_t i; 
  uint32_t ret=0;
  
  /*Initialize all ASF inctance*/
  for(i=0; i < ASF_INSTANCE_NUMBER; i++) {
    ret = ASF_InitSingleInstance(&asfInstances[i]);
    if(ret) {
      /*Error detected druing initialization this ASF instance*/
      continue;
    }
  }
  return ret;
}

uint32_t ASF_CompareStatisticObj(ASF_StatInfo *stat1, ASF_StatInfo *stat2) {
    /** Name of controller associated with ASF module. */
    if(strcmp((char*)stat1->name, (char*)stat2->name) != 0U) {
        vDbgMsg(DBG_GEN_MSG, DBG_FYI, "Different names: %s != %s\n", (char*)stat1->name, (char*)stat2->name);
        return CDN_EINVAL;
    }

    if(stat1->integrityErrCounter != stat2->integrityErrCounter) {
        vDbgMsg(DBG_GEN_MSG, DBG_FYI, "integrityErrCounter, %d != %d\n", stat1->integrityErrCounter, stat2->integrityErrCounter);
        return CDN_EINVAL;      
    }
    
    if(stat1->configStatusErrCounter != stat2->configStatusErrCounter) {
        vDbgMsg(DBG_GEN_MSG, DBG_FYI, "configStatusErrCounter, %d != %d\n", stat1->configStatusErrCounter, stat2->configStatusErrCounter);
        return CDN_EINVAL;      
    }

    if(stat1->dataAdressParityErrCounter != stat2->dataAdressParityErrCounter) {
        vDbgMsg(DBG_GEN_MSG, DBG_FYI, "dataAdressParityErrCounter, %d != %d\n", stat1->dataAdressParityErrCounter, stat2->dataAdressParityErrCounter);
        return CDN_EINVAL;      
    }
  
    if(stat1->sramUncorrectableErrCounter != stat2->sramUncorrectableErrCounter) {
        vDbgMsg(DBG_GEN_MSG, DBG_FYI, "sramUncorrectableErrCounter, %d != %d\n", stat1->sramUncorrectableErrCounter, stat2->sramUncorrectableErrCounter);
        return CDN_EINVAL;      
    }

    if(stat1->sramCorrectableErrCounter != stat2->sramCorrectableErrCounter) {
        vDbgMsg(DBG_GEN_MSG, DBG_FYI, "sramCorrectableErrCounter, %d != %d\n", stat1->sramCorrectableErrCounter, stat2->sramCorrectableErrCounter);
        return CDN_EINVAL;      
    }

    if(stat1->allProtocolErrCounter != stat2->allProtocolErrCounter) {
        vDbgMsg(DBG_GEN_MSG, DBG_FYI, "allProtocolErrCounter, %d != %d\n", stat1->allProtocolErrCounter, stat2->allProtocolErrCounter);
        return CDN_EINVAL;      
    }

    // if(stat1->allTimeoutErrCounter != stat2->allTimeoutErrCounter) {
    //     vDbgMsg(DBG_GEN_MSG, DBG_FYI, "allTimeoutErrCounter, %d != %d\n", stat1->allTimeoutErrCounter, stat2->allTimeoutErrCounter);
    //     return CDN_EINVAL;      
    // }
    
    //TODO: compare lastSramCorrectableErr, lastSramUncorrectableErr, protocolErrCounter and timeoutErrCounter
    return CDN_EOK;
}
