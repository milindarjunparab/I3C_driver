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
 * run_tests.c
 * Entry point for tests 
 *****************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cdn_errno.h"
#include "map_system_memory.h"
#include "asf_priv.h"
#include "asf_trace.h"
#include "asf_common.h"
#include "asf_tests.h"

#include "test_harness_log.h"
#include "cdn_log.h"

#define ASF_INSTANCE_NUMBER 1

static TestData testData;

ASF_Instance asfInstances[ASF_INSTANCE_NUMBER] = {
    { 
        .config = {
        .regBase = (ASF_Regs*)(I3C_MST0_REGS_BASE + 0x300),
        .controllerName = {"IP CORE with ASF"},
        .controllerVersion = {"1.0.0"},
        .transactionTimeoutValue = 100    
        },
        .id = 0,
        .status = 0
    }
};


void sramCorrectableEvent(ASF_PrivateData* privetData, ASF_EventInfo* eventInfo) {  
    copyLastEventObject(privetData, eventInfo); 
    ASF_traceEvent(eventInfo);
}
void sramUncorrectableEvent(ASF_PrivateData* privetData, ASF_EventInfo* eventInfo) {
    copyLastEventObject(privetData, eventInfo);
    ASF_traceEvent(eventInfo);
}

void dataAdressParityEvent(ASF_PrivateData* privetData, ASF_EventInfo* eventInfo) {
    copyLastEventObject(privetData, eventInfo);
    ASF_traceEvent(eventInfo);
}

void configStatusRegiseterEvent(ASF_PrivateData* privetData, ASF_EventInfo* eventInfo) {
    copyLastEventObject(privetData, eventInfo);
    ASF_traceEvent(eventInfo);
}

void transactionTimeoutEvent(ASF_PrivateData* privetData, ASF_EventInfo* eventInfo) {
    copyLastEventObject(privetData, eventInfo);
    ASF_traceEvent(eventInfo);
}
void protocolEvent(ASF_PrivateData* privetData, ASF_EventInfo* eventInfo) {
    copyLastEventObject(privetData, eventInfo);
    ASF_traceEvent(eventInfo);
}
void integrityEvent(ASF_PrivateData* privetData, ASF_EventInfo* eventInfo) {
    copyLastEventObject(privetData, eventInfo);
    ASF_traceEvent(eventInfo);
}
    
ASF_Callbacks callback = {
    .sramCorrectableEvent = sramCorrectableEvent,
    .sramUncorrectableEvent = sramUncorrectableEvent,
    .dataAdressParityEvent = dataAdressParityEvent,
    .configStatusRegiseterEvent = configStatusRegiseterEvent,
    .transactionTimeoutEvent = transactionTimeoutEvent,
    .protocolEvent = protocolEvent,
    .integrityEvent = integrityEvent
};

void ASF_Isr1() {
    ASF_Isr(&asfInstances[0].priv);
}


/**
 * Prints test result 
 */
void testResult(char* testName, uint32_t errorCode){
    if(errorCode == CDN_EOK) 
        TESTING_TEST_PASSED(testName, testData);        
    else 
        TESTING_TEST_FAILED(testName, testData);        
}

/** test setup function */
uint32_t ASF_RunFunctionalTests() {
    uint32_t i = 0;
    uint32_t ret =0;
    ASF_StatInfo stats;

    testData.groupName = "ASF Functional tests";
    testData.groupIndex = 0;    
    
    START_TESTING(testData);          
    ASf_InitAllInstances();
    
    for(i=0; i< ASF_INSTANCE_NUMBER; i++) {      
        ASF_PrivateData *priv = &asfInstances[i].priv;
        ASF_Start(priv);
        ASF_traceConfigSetting(priv);

        if(!asfInstances[i].status) {

            ret = ASF_testStopStartReinit(priv);
            testResult("ASF_testStopStartReinit", ret);

            // continue testing procedure only if driver reinitialization passed
            if (ret == CDN_EOK) {

                ret = ASF_testIncorrectDriverState(priv);
                testResult("ASF_testIncorrectDriverState", ret);

                ret = ASF_testBIST1(&asfInstances[i].priv);
                testResult("ASF_testBIST1", ret);

                ret = ASF_GetStatistic(&asfInstances[i].priv, &stats);
                ASF_TraceExtendedStatInfo(&stats);

                ret = ASF_testBIST2(&asfInstances[i].priv);
                testResult("ASF_testBIST2", ret);    

                ret = ASF_testDisableAllEventsFunc(priv);
                testResult("ASF_testDisableAllEventsFunc", ret);

                ret = ASF_testEnableAllEventsFunc(priv);
                testResult("ASF_testEnableAllEventsFunc", ret);

                ret = ASF_testEnableEventFunc(priv);
                testResult("ASF_testEnableEventFunc", ret);

                ret = ASF_testDisableEventFunc(priv);
                testResult("ASF_testDisableEventFunc", ret);

                ret = ASF_testSetEventAsNonFatalFunc(priv, i);
                testResult("ASF_testSetEventAsNonFatalFunc", ret);

                ret = ASF_testEnableProtocolEventByMaskFunc(priv);
                testResult("ASF_testEnableProtocolEventByMaskFunc", ret);

                ret = ASF_testDisableProtocolEventByMaskFunc(priv);
                testResult("ASF_testDisableProtocolEventByMaskFunc", ret);

                ret = ASF_testEnableProtocolEventByIDFunc(priv);
                testResult("ASF_testEnableProtocolEventByIDFunc", ret);

                ret = ASF_testDisableProtocolEventByIDFunc(priv);
                testResult("ASF_testDisableProtocolEventByIDFunc", ret);

                ret = ASF_testEnableTimeoutEventByMaskFunc(priv);
                testResult("ASF_testEnableTimeoutEventByMaskFunc", ret);

                ret = ASF_testDisableTimeoutEventByMaskFunc(priv);
                testResult("ASF_testDisableTimeoutEventByMaskFunc", ret);

                ret = ASF_testEnableTimeoutEventByIDFunc(priv);
                testResult("ASF_testEnableTimeoutEventByIDFunc", ret);

                ret = ASF_testDisableTimeoutEventByIDFunc(priv);
                testResult("ASF_testDisableTimeoutEventByIDFunc", ret);
    
                ret = ASF_testStatisticFunc(priv);
                testResult("ASF_testStatisticFunc", ret);
            }

        } else {
            vDbgMsg(DBG_GEN_MSG, DBG_FYI, "ERROR: ASF Instance id: %d, name %s, status%d\n", asfInstances[i].id, asfInstances[i].config.controllerName, asfInstances[i].status);
        }
    }    
    TESTING_SUMMARY(testData);        
    ASF_ClearAllInstance();

    return !((testData.passed == testData.calls) && (testData.calls > 0));
}
