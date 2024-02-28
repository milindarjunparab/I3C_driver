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
 * asf_common.h
 * Common helper Functions for tests
 *****************************************************************************/
#ifndef ASF_COMMON_H
#define ASF_COMMON_H

#define  ASF_INSTANCE_NUMBER 1

/*Error codes used in tests*/
#define TEST_ERR_PROBE 1
#define TEST_ERR_INIT 2

extern ASF_Callbacks callback;

/**
 * ASF instance object 
 * Holds information related to single instance of ASF 
*/
typedef struct ASF_Instance_s {
  /** Core drvier private data. */
  ASF_PrivateData priv;
  /** Core driver configuration object. */
  ASF_Config config;
  /** ID of this instance of driver*/
  uint8_t id;
  /** status of inititialization */
  uint32_t status;
  /** holds information about last reported event*/
  ASF_EventInfo lastReportedEvent;
  /** inform that lastReportedEvent field was updated */
  uint8_t eventChanged;
} ASF_Instance;

extern ASF_Instance asfInstances[/*ASF_INSTANCE_NUMBER*/];

/**
 * Clears information about last reported event.
 * @param[in] privateData Driver state info specific to this instance.
 * @return void 
*/
void ASF_clearEventInfoObj(ASF_PrivateData *priv);

/**
 * Compare event object with given parameters 
 * @event[in] compared event object
 * @param[in] expectedVersion Expected controller Version
 * @param[in] expectedName Expected controller Name
 * @param[in] expectedErrorCode Expected error code 
 * @param[in] expectedFatalEvent Expceted fatal parameter
 * @return CDN_EOK if event is correct else CDN_EINVAL
*/
uint32_t ASF_checkEventObj(ASF_EventInfo *event, 
                          const char *expectedVersion, 
                          const char *expectedName, 
                          const ASF_EventErrorType expectedErrorCode,
                          const uint8_t expectedFatalEvent);

/**
 * Gets Id number of instance related to privateData 
 * @param[in] privateData Driver state info specific to this instance.
 * @return ID number
*/
uint8_t getInstanceId(ASF_PrivateData *privetData);

/**
 * Function saves last reported eventInfo object. 
 * @param[in] privateData Driver state info specific to this instance.
 * @param[in] eventInfo Reported event that wil lbe saved in ASF_Instance->lastReportedEvent
 * @return void
*/
void copyLastEventObject(ASF_PrivateData* privetData, ASF_EventInfo* eventInfo);

/**
 * Stops and destroys instance of driver 
 * @param[in] inst Instance that will be cleared 
 * @return void
*/
void ASF_ClearSingleInstance(ASF_Instance * inst);

/**
 * Stops and destroys all instance of driver 
 * @return void
*/
void ASF_ClearAllInstance();

/**
 * Function initializes single ASF intstance
  * @param[in] inst Initialised instance
  * @return 0 on success else TEST_ERR_PROBE or TEST_ERR_INIT error code
*/
uint32_t ASF_InitSingleInstance(ASF_Instance * inst);

/**
 * Function initializes all ASF Instances defined in asfInstance object. 
*/
uint32_t ASf_InitAllInstances();

uint32_t ASF_CompareStatisticObj(ASF_StatInfo *stat1, ASF_StatInfo *stat2);

#endif  //ASF_COMMON_H
