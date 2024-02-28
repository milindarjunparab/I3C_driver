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
 * asf_tests.c
 * Contains implementation of tests
 ******************************************************************************/
#include "cdn_errno.h"
#include "asf_if.h"
#include "asf_priv.h"
#include "asf_trace.h"
#include "asf_common.h"
#include "cps.h"


/**
 *Test Name: Test BIST1
 *Test Description: Test uses ASF_SelfTest function and is intended to checking whether all emulated event will be reported.
 *Pass Conditions: ASF is supported.
 *Fail Conditions: All other status
 *APIs called: ASF_SelfTest
 *Use Case: ASF self test
 */
uint32_t ASF_testBIST1(ASF_PrivateData *priv) {

    const ASF_Callbacks nullCallbacks = { NULL };
    const ASF_Callbacks prevCallbacks = priv->callbacks;

    /* reset all callbacks to NULL and run SelfTest */
    priv->callbacks = nullCallbacks;

    /* all fault condition will be generated one by one */
    if (ASF_SelfTest(priv) != CDN_EOK) {
        return CDN_EINVAL;
    }

    /* restore original callbacks and run SelfTest */
    priv->callbacks = prevCallbacks;

    if (ASF_SelfTest(priv) != CDN_EOK) {
        return CDN_EINVAL;
    }

    return CDN_EOK;
}

/**
 *Test Name: Test BIST2
 *Test Description: Test uses function ASF_TestEvent to trigger all emulated fault events.
 *Pass Conditions: ll events should be generated as expected.
 *Fail Conditions: All other status
 *APIs called: ASF_EnableAllEvents, ASF_TestEvent, ASF_CheckIfASFSupported, ASF_GetStatistic, ASF_DisableAllEvents
 *Use Case: Information about fault events, ASF Interrupts
 */
uint32_t ASF_testBIST2(ASF_PrivateData *priv) {
    uint32_t i = 0;
    ASF_StatInfo stats;

    const uint32_t supported = priv->supportedFeatures;
    const uint32_t notSupported = supported & (ASF_INTEGRITY - 1U);

    if (ASF_EnableAllEvents(priv) != CDN_EOK) {
        return CDN_EINVAL;
    }

    for(i = 0; i <= ASF_INTEGRITY; i++) {

        if (ASF_CheckIfASFSupported(priv, (ASF_EventErrorType)i) != CDN_EOK) {
            continue;
        }

        if (ASF_TestEvent(priv, (ASF_EventErrorType)i) != CDN_EOK) {
            return CDN_EINVAL;
        }

        if (ASF_GetStatistic(priv, &stats) != CDN_EOK) {
            return CDN_EINVAL;
        }
  
        ASF_TraceExtendedStatInfo(&stats);
    }

    /* check for feature out of integrity range */
    if(ASF_CheckIfASFSupported(priv, (ASF_INTEGRITY + 1U)) != CDN_EINVAL) {
        return CDN_EINVAL;
    }

    /* simulate that feature is not supproted */
    priv->supportedFeatures = notSupported;

    /* check for not supported feature */
    if (ASF_CheckIfASFSupported(priv, notSupported) != CDN_EOPNOTSUPP) {
        return CDN_EINVAL;
    }

    /* restore original value of supportedFeatures */
    priv->supportedFeatures = supported;

    if (ASF_DisableAllEvents(priv) != CDN_EOK) {
        return CDN_EINVAL;
    }

    return CDN_EOK;
}

/**
 *Test Name: ASF_DisableAllEvents
 *Test Description: Tests if DisableAllEvents function work correct. Test disable detection of all events, then starts generating of all event by using ASF_TestEvent function. For each emulated event function should receive timeout error.
 *Pass Conditions: No event should be generated.
 *Fail Conditions: All other status
 *APIs called: ASF_DisableAllEvents, ASF_CheckIfASFSupported, ASF_TestEvent
 *Use Case: ASF Interrupts, ASF Self Test
 */
uint32_t ASF_testDisableAllEventsFunc(ASF_PrivateData *priv) {
    uint32_t i = 0;
    uint32_t ret = 0;

    /* disable all interrupts */
    ASF_DisableAllEvents(priv);

    /* checking if all interrupts are disabled */
    for(i = 0; i <= ASF_INTEGRITY; i++) {
        ret = ASF_CheckIfASFSupported(priv, (ASF_EventErrorType)i);
        /* only for supported features */
        if(ret == CDN_EOK) {
             ret = ASF_TestEvent(priv, (ASF_EventErrorType)i);
             /* interrupt are disabled so we should  get CDN_EPROTO error code */
             if(ret == CDN_EPROTO) {
                 continue;
             } else {
                 return CDN_EINVAL; /* test failed */
             }
        }
    }
    return CDN_EOK;
}

/**
 *Test Name: ASF_EnableAllEvents
 *Test Description: Function disables detection all events then checks if all events were disabled. In next step enables all events. After enabling events, function trigger all events and checks whether they were reported
 *Pass Conditions: All events should be generated.
 *Fail Conditions: All other status
 *APIs called: ASF_EnableAllEvents, ASF_CheckIfASFSupported, ASF_TestEvent
 *Use Case: ASF Interrupts, ASF Self Test
 */
uint32_t ASF_testEnableAllEventsFunc(ASF_PrivateData *priv) {
    uint32_t i = 0;
    uint32_t ret = 0;

    /* disable all interrupts and check if are disabled */
    if(ASF_testDisableAllEventsFunc(priv) != CDN_EOK)
        return CDN_EINVAL; /* test failed */


    if(ASF_EnableAllEvents(priv) != CDN_EOK)
        return CDN_EINVAL; /* test failed */

    /* checking if all interrupts are enabled */
    for(i = 0; i <= ASF_INTEGRITY; i++) {
        ret = ASF_CheckIfASFSupported(priv, (ASF_EventErrorType)i);
        /* only for supported features */
        if(ret == CDN_EOK) {
             ret = ASF_TestEvent(priv, (ASF_EventErrorType)i);
             /* interrupt are disabled so we should  get CDN_EPROTO error code */
             if(ret == CDN_EOK) {
                 continue;
             } else {
                 return CDN_EINVAL; /* test failed */
             }
        }
    }
    return CDN_EOK;
}

/**
 *Test Name: ASF_EnableEvent
 *Test Description: Tests ASF_EnableEvent function. At the beginning function disables all events. In next step in loop enables single event, trigger enabled event and  checks if correct event was detected. In nested loop function tests if  all disabled events returns CDN_EPROTO error code.
 *Pass Conditions: A single event should be generated.
 *Fail Conditions: All other status
 *APIs called: ASF_EnableEvent, ASF_DisableEvent, ASF_CheckIfASFSupported, ASF_TestEvent
 *Use Case: Information about fault event, ASF Interrupts
 */
uint32_t ASF_testEnableEventFunc(ASF_PrivateData *priv) {
    uint8_t i = 0, j = 0;
    uint32_t ret = 0;
    uint32_t supported = CDN_EOK;

    /* disable all interrupts and check if are disabled */
    if(ASF_testDisableAllEventsFunc(priv) != CDN_EOK)
        return CDN_EINVAL; //test failed

    /* enable handling all features - one by one */
    for(i = 0; i <= ASF_INTEGRITY; i++) {
        ret = ASF_CheckIfASFSupported(priv, (ASF_EventErrorType)i);
        /* only for supported features */
        if(ret == CDN_EOK) {
            /* enable features */
            if(ASF_EnableEvent(priv, (ASF_EventErrorType)i) != CDN_EOK)
                return CDN_EINVAL; /* test failed */

            /* trigger event */
            ret = ASF_TestEvent(priv, (ASF_EventErrorType)i);
            /* tested feature is enabled so function should get CDN_EOK code */
            if(ret != CDN_EOK) {
                return CDN_EINVAL; /* test failed */
            }

            /* check if all others features are disabled */
            for(j = 0; j <= ASF_INTEGRITY; j++) {
                if(j == i) {
                    continue;
                }

                supported = ASF_CheckIfASFSupported(priv, (ASF_EventErrorType)j);
                if (supported == CDN_EOK) {
                    ret = ASF_TestEvent(priv, (ASF_EventErrorType)j);
                    if(ret != CDN_EPROTO) {
                        return CDN_EINVAL;  /* test failed */
                    }
                }
            }

            if(ASF_DisableEvent(priv, (ASF_EventErrorType)i) != CDN_EOK)
                return CDN_EINVAL; /* test failed */
        }
    }
    return CDN_EOK;
}

/**
 *Test Name: ASF_SetEventAsNonFatal
 *Test Description: Function tests ASF_SetEventAsNonFatal function for given instance. Function enables and sets all events as fatal. Then one by one set single event as non fatal and trigger events, and checks if generated events are correct.
 *Pass Conditions: A single event should be generated as non fatal.
 *Fail Conditions: All other status
 *APIs called: ASF_SetEventAsFatal, ASF_SetEventAsNonFatal, ASF_CheckIfASFSupported, ASF_TestEvent
 *Use Case: Information about fault event, ASF Interrupts
 */
uint32_t ASF_testSetEventAsNonFatalFunc(ASF_PrivateData *priv, uint8_t instId) {
    uint8_t i = 0, j = 0;
    uint32_t ret = CDN_EOK;
    uint32_t supported = CDN_EOK;

    if(instId >= ASF_INSTANCE_NUMBER) {
        return CDN_EINVAL;
    }

    if(ASF_EnableAllEvents(priv) != CDN_EOK) {
      return CDN_EINVAL;
    }

    for(i = 0; i<= ASF_INTEGRITY; i++) {
        supported = ASF_CheckIfASFSupported(priv, (ASF_EventErrorType)i);
        if (supported == CDN_EOK) {
            ret = ASF_SetEventAsFatal(priv, (ASF_EventErrorType)i);
            if(ret != CDN_EOK) {
                return CDN_EINVAL;
            }
        }
    }

    /* set one by one faults as fatal, trigger event and check */
    /* if received event is reported as non fatal. */
    for(i = 0; i<= ASF_INTEGRITY; i++) {
        supported = ASF_CheckIfASFSupported(priv, (ASF_EventErrorType)i);
        if (supported == CDN_EOK) {
            /* set event type "i" as nonFatal */
            ret = ASF_SetEventAsNonFatal(priv, (ASF_EventErrorType)i);
            if(ret != CDN_EOK) {
                return CDN_EINVAL;
            }

            /* trigger all events - only one can be reported as non fatal */
            for(j = 0; j<= ASF_INTEGRITY; j++) {
                /* clear place for holding reported event object */
                ASF_clearEventInfoObj(priv);

                supported = ASF_CheckIfASFSupported(priv, (ASF_EventErrorType)j);
                if (supported == CDN_EOK) {
                    /* trigger event */
                    ret = ASF_TestEvent(priv, (ASF_EventErrorType)j);

                    if(ret == CDN_EOK) {
                        ASF_EventInfo *event = &asfInstances[instId].lastReportedEvent;

                        if(!asfInstances[instId].eventChanged) {
                            /* e.g babble interrupt */
                            continue;
                        }

                        /* if expect non Fatal interrupt */
                        if(i == j) {
                            ret = ASF_checkEventObj(event,
                                                    NULL,
                                                    NULL,
                                                    (ASF_EventErrorType)j,
                                                    0);
                            if(ret != CDN_EOK)
                                return CDN_EINVAL; /* test failed */
                        } else {
                            ret = ASF_checkEventObj(event,
                                                    NULL,
                                                    NULL,
                                                    (ASF_EventErrorType)j,
                                                    1);
                            if(ret != CDN_EOK)
                                return CDN_EINVAL; /* test failed */
                        }

                    } else  {
                        return CDN_EINVAL; /* test failed */
                    }
                }
            }
            ret = ASF_SetEventAsFatal(priv, (ASF_EventErrorType)i);
        }
    }
    return ret;
}

/**
 *Test Name: ASF_DisableEvent
 *Test Description: Tests ASF_DisableEvent function. At the beginning function enable all events. Then disables one by one only single event and verify if it was disabled.
 *Pass Conditions: A single event should be disabled.
 *Fail Conditions: All other status
 *APIs called: ASF_DisableEvent, ASF_EnableEvent, ASF_CheckIfASFSupported, ASF_TestEvent
 *Use Case: Information about fault event, ASF Interrupts
 */
uint32_t ASF_testDisableEventFunc(ASF_PrivateData *priv) {
    uint8_t i = 0, j = 0;
    uint32_t ret = 0;
    uint32_t supported = CDN_EOK;

    if(ASF_testEnableAllEventsFunc(priv) != CDN_EOK) {
        return CDN_EINVAL; /* test failed */
    }

   /* enable handling all features - one by one */
    for(i = 0; i <= ASF_INTEGRITY; i++) {
        supported = ASF_CheckIfASFSupported(priv, (ASF_EventErrorType)i);
        /* only for supported features */
        if(supported == CDN_EOK) {
            //enable features
            if(ASF_DisableEvent(priv, (ASF_EventErrorType)i) != CDN_EOK)
                return CDN_EINVAL; /* test failed */

            /* trigger event */
            ret = ASF_TestEvent(priv, (ASF_EventErrorType)i);
            /* tested feature  is disabled so we should  get CDN_EPROTO error code */
            if(ret == CDN_EOK) {
                return CDN_EINVAL; /* test failed */
            }

            /* check if all others features are enabled */
            for(j = 0; j <= ASF_INTEGRITY; j++) {
                if(j == i) {
                    continue;
                }

                supported = ASF_CheckIfASFSupported(priv, (ASF_EventErrorType)j);
                if (supported == CDN_EOK) {
                    ret = ASF_TestEvent(priv, (ASF_EventErrorType)j);
                    if(ret != CDN_EOK) {
                        return CDN_EINVAL;  /* test failed */
                    }
                }
            }

            /* enable again interrupt */
            if(ASF_EnableEvent(priv, (ASF_EventErrorType)i) != CDN_EOK)
                return CDN_EINVAL; /* test failed */

        }
    }
    return CDN_EOK;
}

/**
 *Test Name: ASF_EnableProtocolEventByMask
 *Test Description: Tests ASF_EnableProtocolEventByMask function.
 *Pass Conditions: All events should be enabled.
 *Fail Conditions: All other status
 *APIs called: ASF_GetSupportedProtocolErrors, ASF_SetEventAsFatal, ASF_DisableProtocolEventByMask, ASF_EnableProtocolEventByMask
 *Use Case: Information about fault event, ASF Configuration
 */
uint32_t ASF_testEnableProtocolEventByMaskFunc(ASF_PrivateData *priv) {
    uint8_t i = 0;
    uint32_t supported = 0;
    uint32_t notSupported = 0;
    uint32_t reg = 0;
    uint32_t expected = 0;
    uint32_t ret = CDN_EOK;
    uint32_t flag = 0;
    uint32_t mask = 0;

    if(ASF_EnableAllEvents(priv) != CDN_EOK) {
         return CDN_EINVAL;
    }
    for(i = 0; i<= ASF_INTEGRITY; i++) {
        ret = ASF_SetEventAsFatal(priv, (ASF_EventErrorType)i);
        if(ret != CDN_EOK) {
            return CDN_EINVAL;
        }
    }

    ret = ASF_GetSupportedProtocolErrors(priv, &flag);
    supported = flag;
    if (supported == 0U) {
        /* hardware does not support protocol error detection */
        return CDN_EOK;
    }
    notSupported = ~supported;
    if(ret != CDN_EOK) {
        return CDN_EINVAL;
    }

    /* Disable all interrupts */
    if(ASF_DisableProtocolEventByMask(priv, supported) != CDN_EOK) {
        return CDN_EINVAL;
    }

    /* Incorrect situation - function should return CDN_EOPNOTSUPP */
    if (ASF_EnableProtocolEventByMask(priv, notSupported) != CDN_EOPNOTSUPP) {
        return CDN_EINVAL;
    }

    /* correct situation, but function should enable only supported events */
    if(ASF_EnableProtocolEventByMask(priv, notSupported | supported) != CDN_EOK) {
        return CDN_EINVAL;
    }


    /* correct situation - enable all supported interrupts */
    if(ASF_EnableProtocolEventByMask(priv, supported) != CDN_EOK) {
        return CDN_EINVAL;
    }

    /* firmware can't use in this place ASF_TestEvent function so
       test function checks only if interrupts was enabled */
    reg = CPS_UncachedRead32(&priv->regs->protocol_fault_mask);

    expected = ~flag & supported;

    if(reg  != expected) {
        return CDN_EINVAL;
    }

    if(ASF_DisableProtocolEventByMask(priv, supported) != CDN_EOK) {
        return CDN_EINVAL;
    }

    reg = CPS_UncachedRead32(&priv->regs->protocol_fault_mask);
    if(reg != supported) {
        return CDN_EINVAL;
    }

    flag = 0;
    for(i = 0; i < ASF_MAX_NUMBER_EXTENDED_EVENTS; i++) {
        mask = 1 << i;

        flag = flag | mask;
        ret = ASF_EnableProtocolEventByMask(priv, mask);
        if(supported & mask) {
            if(ret != CDN_EOK) {
                return CDN_EINVAL;
            }
        } else {
            if (ret != CDN_EOPNOTSUPP) {
                return CDN_EINVAL;
            }
        }
       reg = CPS_UncachedRead32(&priv->regs->protocol_fault_mask);
       expected = ~flag & supported;

       if(reg  != expected) {
           return CDN_EINVAL;
       }
    }

    reg = CPS_UncachedRead32(&priv->regs->protocol_fault_mask);
    /* all interrupts should be enabled */
    expected = 0;
    if(reg  != expected) {
        return CDN_EINVAL;
    }

    return CDN_EOK;
}

/**
 *Test Name: ASF_DisableProtocolEventByMask
 *Test Description: Tests ASF_DisableProtocolEventByMask function.
 *Pass Conditions: No events should be enabled.
 *Fail Conditions: All other status
 *APIs called: ASF_GetSupportedProtocolErrors, ASF_SetEventAsFatal, ASF_DisableProtocolEventByMask, ASF_EnableProtocolEventByMask
 *Use Case: Information about fault event, ASF Configuration
 */
uint32_t ASF_testDisableProtocolEventByMaskFunc(ASF_PrivateData *priv) {
    uint8_t i = 0;
    uint32_t supported = 0;
    uint32_t notSupported = 0;
    uint32_t reg = 0;
    uint32_t expected = 0;
    uint32_t ret = CDN_EOK;
    uint32_t flag = 0;
    uint32_t mask = 0;

    if(ASF_EnableAllEvents(priv) != CDN_EOK) {
         return CDN_EINVAL;
    }

    for(i = 0; i<= ASF_INTEGRITY; i++) {
        ret = ASF_SetEventAsFatal(priv, (ASF_EventErrorType)i);
        if(ret != CDN_EOK) {
            return CDN_EINVAL;
        }
    }

    ret = ASF_GetSupportedProtocolErrors(priv, &flag);
    supported = flag;
    if (supported == 0U) {
        /* hardware does not support protocol error detection */
        return CDN_EOK;
    }
    notSupported = ~supported;
    if(ret != CDN_EOK) {
        return CDN_EINVAL;
    }

    /* Enable all interrupts */
    if(ASF_EnableProtocolEventByMask(priv, supported) != CDN_EOK) {
        return CDN_EINVAL;
    }

    /* Incorrect situation - function should return CDN_EOPNOTSUPP */
    if (ASF_DisableProtocolEventByMask(priv, notSupported) != CDN_EOPNOTSUPP) {
        return CDN_EINVAL;
    }

    /* correct situation, but function should enable only supported events */
    if(ASF_DisableProtocolEventByMask(priv, notSupported | supported) != CDN_EOK) {
        return CDN_EINVAL;
    }


    /* correct situation - enable all supported interrupts */
    if(ASF_DisableProtocolEventByMask(priv, supported) != CDN_EOK) {
        return CDN_EINVAL;
    }

    /* firmware can't use in this place ASF_TestEvent function so
       test function checks only if interrupts was enabled */
    reg = CPS_UncachedRead32(&priv->regs->protocol_fault_mask);

    expected =  supported;
    if(reg  != expected) {
        return CDN_EINVAL;
    }

    if(ASF_EnableProtocolEventByMask(priv, supported) != CDN_EOK) {
        return CDN_EINVAL;
    }

    reg = CPS_UncachedRead32(&priv->regs->protocol_fault_mask);
    if(reg != 0) {
        return CDN_EINVAL;
    }

    flag = 0;
    for(i = 0; i < ASF_MAX_NUMBER_EXTENDED_EVENTS; i++) {
        mask = 1 << i;

        flag = flag | mask;
        ret = ASF_DisableProtocolEventByMask(priv, mask);
        if(supported & mask) {
            if(ret != CDN_EOK) {
                return CDN_EINVAL;
            }
        } else {
            if (ret != CDN_EOPNOTSUPP) {
                return CDN_EINVAL;
            }
        }
       reg = CPS_UncachedRead32(&priv->regs->protocol_fault_mask);
       expected = flag & supported;

       if(reg  != expected) {
           return CDN_EINVAL;
       }
    }

    reg = CPS_UncachedRead32(&priv->regs->protocol_fault_mask);
    /* all interrupts should be disabled */
    expected = supported;
    if(reg  != expected) {
        return CDN_EINVAL;
    }

    return CDN_EOK;
}

/**
 *Test Name: ASF_EnableProtocolEventByIDFunc
 *Test Description: Tests ASF_EnableProtocolEventByIDFunc function.
 *Pass Conditions: All events should be enabled.
 *Fail Conditions: All other status
 *APIs called: ASF_GetSupportedProtocolErrors, ASF_SetEventAsFatal, ASF_DisableProtocolEventByMask, ASF_EnableProtocolEventByID
 *Use Case: Information about fault event, ASF Configuration
 */
uint32_t ASF_testEnableProtocolEventByIDFunc(ASF_PrivateData *priv) {
    uint8_t i = 0;
    uint32_t supported = 0;
    uint32_t notSupported = 0;
    uint32_t reg = 0;
    uint32_t expected = 0;
    uint32_t ret = CDN_EOK;
    uint32_t flag = 0;
    uint32_t mask = 0;
    if(ASF_EnableAllEvents(priv) != CDN_EOK) {
         return CDN_EINVAL;
    }

    for(i = 0; i<= ASF_INTEGRITY; i++) {
        ret = ASF_SetEventAsFatal(priv, (ASF_EventErrorType)i);
        if(ret != CDN_EOK) {
            return CDN_EINVAL;
        }
    }


    ret = ASF_GetSupportedProtocolErrors(priv, &flag);
    supported = flag;
    if (supported == 0U) {
        /* hardware does not support protocol error detection */
        return CDN_EOK;
    }
    notSupported = ~supported;
    if(ret != CDN_EOK) {
        return CDN_EINVAL;
    }

    /* Disable all interrupts */
    if(ASF_DisableProtocolEventByMask(priv, supported) != CDN_EOK) {
        return CDN_EINVAL;
    }

    flag = 0;
    for(i = 0; i < ASF_MAX_NUMBER_EXTENDED_EVENTS; i++) {
        mask = 1 << i;

        flag = flag | mask;
        ret = ASF_EnableProtocolEventByID(priv, i);

        if(supported & mask) {
            if(ret != CDN_EOK) {
                return CDN_EINVAL;
            }
        } else {
            if (ret != CDN_EOPNOTSUPP) {
                return CDN_EINVAL;
            }
        }
        reg = CPS_UncachedRead32(&priv->regs->protocol_fault_mask);
        expected = ~flag & supported;

        if(reg  != expected) {
           return CDN_EINVAL;
        }
    }

    reg = CPS_UncachedRead32(&priv->regs->protocol_fault_mask);
    /* all interrupts should be enabled */
    expected = 0;
    if(reg  != expected) {
        return CDN_EINVAL;
    }

    return CDN_EOK;
}

/**
 *Test Name: ASF_DisableProtocolEventByIDFunc
 *Test Description: Tests ASF_DisableProtocolEventByIDFunc function.
 *Pass Conditions: All events should be disabled.
 *Fail Conditions: All other status
 *APIs called: ASF_GetSupportedProtocolErrors, ASF_SetEventAsFatal, ASF_EnableProtocolEventByMask, ASF_DisableProtocolEventByID
 *Use Case: Information about fault event, ASF Configuration
 */
uint32_t ASF_testDisableProtocolEventByIDFunc(ASF_PrivateData *priv) {
    uint8_t i = 0;
    uint32_t supported = 0;
    uint32_t notSupported = 0;
    uint32_t reg = 0;
    uint32_t expected = 0;
    uint32_t ret = CDN_EOK;
    uint32_t flag = 0;
    uint32_t mask = 0;

    if(ASF_EnableAllEvents(priv) != CDN_EOK) {
         return CDN_EINVAL;
    }

    for(i = 0; i<= ASF_INTEGRITY; i++) {
        ret = ASF_SetEventAsFatal(priv, (ASF_EventErrorType)i);
        if(ret != CDN_EOK) {
            return CDN_EINVAL;
        }
    }


    ret = ASF_GetSupportedProtocolErrors(priv, &flag);
    supported = flag;
    if (supported == 0U) {
        /* hardware does not support protocol error detection */
        return CDN_EOK;
    }
    notSupported = ~supported;
    if(ret != CDN_EOK) {
        return CDN_EINVAL;
    }

    /* Enable all interrupts */
    if(ASF_EnableProtocolEventByMask(priv, supported) != CDN_EOK) {
        return CDN_EINVAL;
    }

    flag = 0;
    for(i = 0; i < ASF_MAX_NUMBER_EXTENDED_EVENTS; i++) {
        mask = 1 << i;

        flag = flag | mask;
        ret = ASF_DisableProtocolEventByID(priv, i);
        if(supported & mask) {
            if(ret != CDN_EOK) {
                return CDN_EINVAL;
            }
        } else {
            if (ret != CDN_EOPNOTSUPP) {
                return CDN_EINVAL;
            }
        }
       reg = CPS_UncachedRead32(&priv->regs->protocol_fault_mask);
       expected = flag & supported;
       if(reg  != expected) {
           return CDN_EINVAL;
       }
    }

    reg = CPS_UncachedRead32(&priv->regs->protocol_fault_mask);
    /* all interrupts should be disabled */
    expected = supported;
    if(reg  != expected) {
        return CDN_EINVAL;
    }

    return CDN_EOK;
}

/**
 *Test Name: ASF_EnableTimoutEventByMask
 *Test Description: Tests ASF_EnableTimeoutEventByMask function.
 *Pass Conditions: All events should be enabled.
 *Fail Conditions: All other status
 *APIs called: ASF_GetSupportedTimeoutErrors, ASF_SetEventAsFatal, ASF_EnableTimeoutEventByMask, ASF_DisableTimeoutEventByMask
 *Use Case: Information about fault event, ASF Configuration
 */
uint32_t ASF_testEnableTimeoutEventByMaskFunc(ASF_PrivateData *priv) {
    uint8_t i = 0;
    uint32_t supported = 0;
    uint32_t notSupported = 0;
    uint32_t reg = 0;
    uint32_t expected = 0;
    uint32_t ret = CDN_EOK;
    uint32_t flag = 0;
    uint32_t mask = 0;

    if(ASF_EnableAllEvents(priv) != CDN_EOK) {
         return CDN_EINVAL;
    }

    for(i = 0; i<= ASF_INTEGRITY; i++) {
        ret = ASF_SetEventAsFatal(priv, (ASF_EventErrorType)i);
        if(ret != CDN_EOK) {
            return CDN_EINVAL;
        }
    }

    ret = ASF_GetSupportedTimeoutErrors(priv, &flag);
    supported = flag;
    notSupported = ~supported;
    if(ret != CDN_EOK) {
        return CDN_EINVAL;
    }

    /* Disable all interrupts */
    if(ASF_DisableTimeoutEventByMask(priv, supported) != CDN_EOK) {
        return CDN_EINVAL;
    }

    /* Incorrect situation - function should return CDN_EOPNOTSUPP */
    if (ASF_EnableTimeoutEventByMask(priv, notSupported) != CDN_EOPNOTSUPP) {
        return CDN_EINVAL;
    }

    /* correct situation, but function should enable only supported events */
    if(ASF_EnableTimeoutEventByMask(priv, notSupported | supported) != CDN_EOK) {
        return CDN_EINVAL;
    }

    /* correct situation - enable all supported interrupts */
    if(ASF_EnableTimeoutEventByMask(priv, supported) != CDN_EOK) {
        return CDN_EINVAL;
    }

    //firmware can't use in this place ASF_TestEvent function so
    // test function checks only if interrupts was enabled
    reg = CPS_UncachedRead32(&priv->regs->trans_to_fault_mask);

    expected = ~flag & supported;

    if(reg  != expected) {
        return CDN_EINVAL;
    }

    if(ASF_DisableTimeoutEventByMask(priv, supported) != CDN_EOK) {
        return CDN_EINVAL;
    }

    reg = CPS_UncachedRead32(&priv->regs->trans_to_fault_mask);
    if(reg != supported) {
        return CDN_EINVAL;
    }

    flag = 0;
    for(i = 0; i < ASF_MAX_NUMBER_EXTENDED_EVENTS; i++) {
        mask = 1 << i;

        flag = flag | mask;
        ret = ASF_EnableTimeoutEventByMask(priv, mask);
        if(supported & mask) {
            if(ret != CDN_EOK) {
                return CDN_EINVAL;
            }
        } else {
            if (ret != CDN_EOPNOTSUPP) {
                return CDN_EINVAL;
            }
        }
       reg = CPS_UncachedRead32(&priv->regs->trans_to_fault_mask);
       expected = ~flag & supported;

       if(reg  != expected) {
           return CDN_EINVAL;
       }
    }

    reg = CPS_UncachedRead32(&priv->regs->trans_to_fault_mask);
    /* all interrupts should be enabled */
    expected = 0;
    if(reg  != expected) {
        return CDN_EINVAL;
    }

    return CDN_EOK;
}

/**
 *Test Name: ASF_DisableTimoutEventByMask
 *Test Description: Tests ASF_DisableTimeoutEventByMask function.
 *Pass Conditions: All events should be disabled.
 *Fail Conditions: All other status
 *APIs called: ASF_GetSupportedTimeoutErrors, ASF_SetEventAsFatal, ASF_EnableTimeoutEventByMask, ASF_DisableTimeoutEventByMask
 *Use Case: Information about fault event, ASF Configuration
 */
uint32_t ASF_testDisableTimeoutEventByMaskFunc(ASF_PrivateData *priv) {
    uint8_t i = 0;
    uint32_t supported = 0;
    uint32_t notSupported = 0;
    uint32_t reg = 0;
    uint32_t expected = 0;
    uint32_t ret = CDN_EOK;
    uint32_t flag = 0;
    uint32_t mask = 0;

    if(ASF_EnableAllEvents(priv) != CDN_EOK) {
         return CDN_EINVAL;
    }

    for(i = 0; i<= ASF_INTEGRITY; i++) {
        ret = ASF_SetEventAsFatal(priv, (ASF_EventErrorType)i);
        if(ret != CDN_EOK) {
            return CDN_EINVAL;
        }
    }

    ret = ASF_GetSupportedTimeoutErrors(priv, &flag);
    supported = flag;
    notSupported = ~supported;
    if(ret != CDN_EOK) {
        return CDN_EINVAL;
    }

    /* Enable all interrupts */
    if(ASF_EnableTimeoutEventByMask(priv, supported) != CDN_EOK) {
        return CDN_EINVAL;
    }

    /* Incorrect situation - function should return CDN_EOPNOTSUPP */
    if (ASF_DisableTimeoutEventByMask(priv, notSupported) != CDN_EOPNOTSUPP) {
        return CDN_EINVAL;
    }

    /* correct situation, but function should enable only supported events */
    if(ASF_DisableTimeoutEventByMask(priv, notSupported | supported) != CDN_EOK) {
        return CDN_EINVAL;
    }

    /* correct situation - enable all supported interrupts */
    if(ASF_DisableTimeoutEventByMask(priv, supported) != CDN_EOK) {
        return CDN_EINVAL;
    }

    /* firmware can't use in this place ASF_TestEvent function so
       test function checks only if interrupts was enabled */
    reg = CPS_UncachedRead32(&priv->regs->trans_to_fault_mask);

    expected =  supported;
    if(reg  != expected) {
        return CDN_EINVAL;
    }

    if(ASF_EnableTimeoutEventByMask(priv, supported) != CDN_EOK) {
        return CDN_EINVAL;
    }

    reg = CPS_UncachedRead32(&priv->regs->trans_to_fault_mask);
    if(reg != 0) {
        return CDN_EINVAL;
    }

    flag = 0;
    for(i = 0; i < ASF_MAX_NUMBER_EXTENDED_EVENTS; i++) {
        mask = 1 << i;

        flag = flag | mask;
        ret = ASF_DisableTimeoutEventByMask(priv, mask);
        if(supported & mask) {
            if(ret != CDN_EOK) {
                return CDN_EINVAL;
            }
        } else {
            if (ret != CDN_EOPNOTSUPP) {
                return CDN_EINVAL;
            }
        }
       reg = CPS_UncachedRead32(&priv->regs->trans_to_fault_mask);
       expected = flag & supported;

       if(reg  != expected) {
           return CDN_EINVAL;
       }
    }

    reg = CPS_UncachedRead32(&priv->regs->trans_to_fault_mask);
    /* all interrupts should be disabled */
    expected = supported;
    if(reg  != expected) {
        return CDN_EINVAL;
    }

    return CDN_EOK;
}

/**
 *Test Name: ASF_EnableTimoutEventByID
 *Test Description: Tests ASF_EnableTimeoutEventByID function.
 *Pass Conditions: All events should be enabled.
 *Fail Conditions: All other status
 *APIs called: ASF_GetSupportedTimeoutErrors, ASF_SetEventAsFatal, ASF_EnableTimeoutEventByID, ASF_DisableTimeoutEventByMask
 *Use Case: Information about fault event, ASF Configuration
 */
uint32_t ASF_testEnableTimeoutEventByIDFunc(ASF_PrivateData *priv) {
    uint8_t i = 0;
    uint32_t supported = 0;
    uint32_t notSupported = 0;
    uint32_t reg = 0;
    uint32_t expected = 0;
    uint32_t ret = CDN_EOK;
    uint32_t flag = 0;
    uint32_t mask = 0;
    if(ASF_EnableAllEvents(priv) != CDN_EOK) {
         return CDN_EINVAL;
    }

    for(i = 0; i<= ASF_INTEGRITY; i++) {
        ret = ASF_SetEventAsFatal(priv, (ASF_EventErrorType)i);
        if(ret != CDN_EOK) {
            return CDN_EINVAL;
        }
    }


    ret = ASF_GetSupportedTimeoutErrors(priv, &flag);
    supported = flag;
    notSupported = ~supported;
    if(ret != CDN_EOK) {
        return CDN_EINVAL;
    }

    /* Disable all interrupts */
    if(ASF_DisableTimeoutEventByMask(priv, supported) != CDN_EOK) {
        return CDN_EINVAL;
    }

    flag = 0;
    for(i = 0; i < ASF_MAX_NUMBER_EXTENDED_EVENTS; i++) {
        mask = 1 << i;

        flag = flag | mask;
        ret = ASF_EnableTimeoutEventByID(priv, i);

        if(supported & mask) {
            if(ret != CDN_EOK) {
                return CDN_EINVAL;
            }
        } else {
            if (ret != CDN_EOPNOTSUPP) {
                return CDN_EINVAL;
            }
        }
        reg = CPS_UncachedRead32(&priv->regs->trans_to_fault_mask);
        expected = ~flag & supported;

        if(reg  != expected) {
           return CDN_EINVAL;
        }
    }

    reg = CPS_UncachedRead32(&priv->regs->trans_to_fault_mask);
    /* all interrupts should be enabled */
    expected = 0;
    if(reg  != expected) {
        return CDN_EINVAL;
    }

    return CDN_EOK;
}

/**
 *Test Name: ASF_DisableTimoutEventByID
 *Test Description: Tests ASF_DisableTimeoutEventByID function.
 *Pass Conditions: All events should be disabled.
 *Fail Conditions: All other status
 *APIs called: ASF_GetSupportedTimeoutErrors, ASF_SetEventAsFatal, ASF_EnableTimeoutEventByMask, ASF_DisableTimeoutEventByID
 *Use Case: Information about fault event, ASF Configuration
 */
uint32_t ASF_testDisableTimeoutEventByIDFunc(ASF_PrivateData *priv) {
    uint8_t i = 0;
    uint32_t supported = 0;
    uint32_t notSupported = 0;
    uint32_t reg = 0;
    uint32_t expected = 0;
    uint32_t ret = CDN_EOK;
    uint32_t flag = 0;
    uint32_t mask = 0;

    if(ASF_EnableAllEvents(priv) != CDN_EOK) {
         return CDN_EINVAL;
    }

    for(i = 0; i<= ASF_INTEGRITY; i++) {
        ret = ASF_SetEventAsFatal(priv, (ASF_EventErrorType)i);
        if(ret != CDN_EOK) {
            return CDN_EINVAL;
        }
    }


    ret = ASF_GetSupportedTimeoutErrors(priv, &flag);
    supported = flag;
    notSupported = ~supported;
    if(ret != CDN_EOK) {
        return CDN_EINVAL;
    }

    /* Enable all interrupts */
    if(ASF_EnableTimeoutEventByMask(priv, supported) != CDN_EOK) {
        return CDN_EINVAL;
    }


    flag = 0;
    for(i = 0; i < ASF_MAX_NUMBER_EXTENDED_EVENTS; i++) {
        mask = 1 << i;

        flag = flag | mask;
        ret = ASF_DisableTimeoutEventByID(priv, i);
        if(supported & mask) {
            if(ret != CDN_EOK) {
                return CDN_EINVAL;
            }
        } else {
            if (ret != CDN_EOPNOTSUPP) {
                return CDN_EINVAL;
            }
        }
       reg = CPS_UncachedRead32(&priv->regs->trans_to_fault_mask);
       expected = flag & supported;

       if(reg  != expected) {
           return CDN_EINVAL;
       }
    }

    reg = CPS_UncachedRead32(&priv->regs->trans_to_fault_mask);
    /* all interrupts should be disabled */
    expected = supported;
    if(reg  != expected) {
        return CDN_EINVAL;
    }

    return CDN_EOK;
}


/**
 * Helper function to generate event and update statsExpected object.
 * @param[in] priv Driver state info specific to this instance.
 *        CDN_EOK on success
 *        CDN_EINVAL -  test failed
 * @param[in/out] statsExpected object holding expected results of test.
 * @param[in] numOfEvent triggered event.
 *
 */
static uint32_t generateStatsEvents(ASF_PrivateData *priv, ASF_StatInfo *statsExpected, uint32_t numeOfEvent) {
     uint32_t ret = 0;
     uint32_t i = 0;
     uint32_t eventType = 0;

     for(i = 0; i <= numeOfEvent; i++) {
        /*generate number from 0 to ASF_INTEGRITY*/
         eventType  = (ASF_EventErrorType)(rand() % (ASF_INTEGRITY) + 1U);

        ret = ASF_CheckIfASFSupported(priv, (ASF_EventErrorType)eventType);
        //only for supported features
        if(ret == CDN_EOK) {
            //trigger event
            ret = ASF_TestEvent(priv, (ASF_EventErrorType)eventType);
            /*tested feature is enabled so function should get CDN_EOK code*/
            if(ret != CDN_EOK) {
                return CDN_EINVAL; //test failed
            }

            switch(eventType) {
                case ASF_SRAM_CORRECTABLE:
                    statsExpected->sramCorrectableErrCounter++;
                break;
                case ASF_SRAM_UNCORRECTABLE:
                    statsExpected->sramUncorrectableErrCounter++;
                break;
                case ASF_DATA_PARITY:
                    statsExpected->dataAdressParityErrCounter++;
                break;
                case ASF_CONFIGURATION:
                    statsExpected->configStatusErrCounter++;
                break;
                /** this event cannot be used in this test becaouse
                 *  emulated interrupt doesn't update other registers
                 *  related to  for this fault conditions
                */
                case ASF_TRANSACTION_TIMEOUT:
                case ASF_PROTOCOL:
                    continue;
                case ASF_INTEGRITY:
                     statsExpected->integrityErrCounter++;
                break;
                default:
                    return CDN_EINVAL;
           }
        }
    }

    return CDN_EOK;
}

/**
 *Test Name: ASF_Statistic
 *Test Description: Tests ASF_ClearStatistic, ASF_RestoreStatistic
 *Pass Conditions: Value of counters should be as expected.
 *Fail Conditions: All other status
 *APIs called: ASF_EnableAllEvents, ASF_ClearStatistic, ASF_RestoreStatistic, ASF_GetStatistic, ASF_GetSupportedProtocolErrors, ASF_GetSupportedTimeoutErrors, ASF_EnableProtocolEventByMask, ASF_SetEventAsFatal
 *Use Case: ASF Events Statistic
 */
uint32_t ASF_testStatisticFunc(ASF_PrivateData *priv) {
    ASF_StatInfo statsExpected;
    ASF_StatInfo statsCurrent;
    uint32_t supportedProtocols = 0;
    uint32_t supportedTimeouts= 0;
    uint32_t numOfIteration = 100;

    uint32_t ret = 0;
    uint8_t i = 0;

    /* Initializes random number generator */
    srand(1234);

    if(ASF_EnableAllEvents(priv) != CDN_EOK) {
      return CDN_EINVAL;
    }

    for(i = 0; i<= ASF_INTEGRITY; i++) {
        ret = ASF_SetEventAsFatal(priv, (ASF_EventErrorType)i);
        if(ret != CDN_EOK) {
            return CDN_EINVAL;
        }
    }

    ret = ASF_GetSupportedProtocolErrors(priv, &supportedProtocols);
    if(ret != CDN_EOK) {
        return CDN_EINVAL;
    }

    ret = ASF_GetSupportedTimeoutErrors(priv, &supportedTimeouts);
    if(ret != CDN_EOK) {
        return CDN_EINVAL;
    }

    if (supportedProtocols != 0U) {
      /* hardware supports protocol error detection
         Disable all interrupts */
      if(ASF_EnableProtocolEventByMask(priv, supportedProtocols) != CDN_EOK) {
        return CDN_EINVAL;
      }
    }

    /* Disable all interrupts */
    if(ASF_EnableTimeoutEventByMask(priv, supportedTimeouts) != CDN_EOK) {
        return CDN_EINVAL;
    }

    memset(&statsExpected, 0, sizeof(statsExpected));

    strcpy((char*)statsExpected.name, (char*)priv->controllerName);
    strcpy((char*)statsExpected.version, (char*)priv->controllerVersion);

    /* clear stat object except name and version fields */
    if(ASF_ClearStatistic(priv)!= CDN_EOK) {
        return CDN_EINVAL;
    }

    ret = generateStatsEvents(priv, &statsExpected, numOfIteration);
    if(ret != CDN_EOK) {
        return CDN_EINVAL;
    }

    ret = ASF_GetStatistic(priv, &statsCurrent);
    if(ret != CDN_EOK) {
        return CDN_EINVAL;
    }

    if(ASF_CompareStatisticObj(&statsExpected, &statsCurrent) != CDN_EOK) {
        return CDN_EINVAL;
    }

    /* clear internal statistic object */
    ret = ASF_ClearStatistic(priv);
    if(ret != CDN_EOK) {
        return CDN_EINVAL;
    }

    /* restore statistic object */
    ASF_RestoreStatistic(priv, &statsExpected);

    /* generate new events */
    ret = generateStatsEvents(priv, &statsExpected, numOfIteration);
    if(ret != CDN_EOK) {
        return CDN_EINVAL;
    }

    /* get updated statistic object */
    ret = ASF_GetStatistic(priv, &statsCurrent);
    if(ret != CDN_EOK) {
        return CDN_EINVAL;
    }

    /* compare again */
    if(ASF_CompareStatisticObj(&statsExpected, &statsCurrent) != CDN_EOK) {
        return CDN_EINVAL;
    }

    return CDN_EOK;
}

/**
 *Test Name: ASF_testStopStartReinit
 *Test Description: Test purpose is to check if Start, Stop and Destroy functions work correctly.
 *Pass Conditions: Functions should work as expected.
 *Fail Conditions: All other status
 *APIs called: ASF_Stop, ASF_Start, ASF_Destroy
 *Use Case: Common architecture
 */
uint32_t ASF_testStopStartReinit(ASF_PrivateData *priv) {
    const uint32_t securityTag = priv->tagSecurity;

    ASF_Stop(priv);
    if(priv->state != ASF_STOPPED) {
        return CDN_EINVAL;
    }

    /* stop when actually stopped */
    ASF_Stop(priv);

    ASF_Start(priv);
    if(priv->state != ASF_STARTED) {
        return CDN_EINVAL;
    }

    /* try to start when actually started */
    ASF_Start(priv);

    /* assign incorrect security tag */
    priv->tagSecurity = ~securityTag;

    ASF_Stop(priv);
    if(priv->state == ASF_STOPPED) {
        return CDN_EINVAL;
    }

    priv->tagSecurity = securityTag;
    /* stop */
    ASF_Stop(priv);
    if(priv->state != ASF_STOPPED) {
        return CDN_EINVAL;
    }

    /* assign incorrect security tag */
    priv->tagSecurity = ~securityTag;

    /* start with incorrect tag */
    ASF_Start(priv);
    if(priv->state == ASF_STARTED) {
        return CDN_EINVAL;
    }

    priv->tagSecurity = securityTag;

    ASF_Start(priv);
    if(priv->state != ASF_STARTED) {
        return CDN_EINVAL;
    }

    ASF_Destroy(priv);
    if(priv->state != ASF_DESTROYED) {
        return CDN_EINVAL;
    }

    if (ASF_InitSingleInstance((ASF_Instance*)priv) != CDN_EOK) {
        return CDN_EINVAL;
    }

    return CDN_EOK;
}

/**
 *Test Name: ASF_testIncorrectDriverState
 *Test Description: In that test there is an attempt to use some API functions which should not be used when driver was not initialized properly. That is simulated through private data.
 *Pass Conditions: Functions should work as expected.
 *Fail Conditions: All other status
 *APIs called: all API functions
 *Use Case: Common architecture
 */
uint32_t ASF_testIncorrectDriverState(ASF_PrivateData *priv) {
    ASF_StatInfo stats;

    /* variables needed only as arguments in functions, not used for other purpose */
    uint32_t timeoutErrorsMask = 0U;
    uint32_t protocolErrorsMask = 0U;
    uint32_t supported = 0U;
    uint32_t mask = 0U;

    /* save previous driver state */
    const uint32_t prevState = priv->state;

    if (ASF_GetSupportedASF(priv, &supported) != CDN_EOK) {
        return CDN_EINVAL;
    }

    mask = supported & 1U;

    /* simulate incorrect state */
    priv->state = ASF_DESTROYED;

    if (ASF_CheckIfASFSupported(priv, mask) != CDN_EINVAL) {
        return CDN_EINVAL;
    }

    if (ASF_GetSupportedASF(priv, &supported) != CDN_EINVAL) {
        return CDN_EINVAL;
    }

    if (ASF_GetSupportedTimeoutErrors(priv, &timeoutErrorsMask) != CDN_EINVAL) {
        return CDN_EINVAL;
    }

    if (ASF_GetSupportedProtocolErrors(priv, &protocolErrorsMask) != CDN_EINVAL) {
        return CDN_EINVAL;
    }

    if (ASF_TestEvent(priv, mask) != CDN_EINVAL) {
        return CDN_EINVAL;
    }

    if (ASF_SelfTest(priv) != CDN_EINVAL) {
        return CDN_EINVAL;
    }

    if (ASF_EnableEvent(priv, mask) != CDN_EINVAL) {
        return CDN_EINVAL;
    }

    if (ASF_DisableEvent(priv, mask) != CDN_EINVAL) {
        return CDN_EINVAL;
    }

    if (ASF_EnableAllEvents(priv) != CDN_EINVAL) {
        return CDN_EINVAL;
    }

    if (ASF_DisableAllEvents(priv) != CDN_EINVAL) {
        return CDN_EINVAL;
    }

    if (ASF_SetEventAsNonFatal(priv, mask) != CDN_EINVAL) {
        return CDN_EINVAL;
    }

    if (ASF_SetEventAsFatal(priv, mask) != CDN_EINVAL) {
        return CDN_EINVAL;
    }

    if (ASF_EnableProtocolEventByMask(priv, mask) != CDN_EINVAL) {
        return CDN_EINVAL;
    }

    if (ASF_EnableProtocolEventByID(priv, mask) != CDN_EINVAL) {
        return CDN_EINVAL;
    }

    if (ASF_DisableProtocolEventByMask(priv, mask) != CDN_EINVAL) {
        return CDN_EINVAL;
    }

    if (ASF_DisableProtocolEventByID(priv, mask) != CDN_EINVAL) {
        return CDN_EINVAL;
    }

    if (ASF_EnableTimeoutEventByMask(priv, mask) != CDN_EINVAL) {
        return CDN_EINVAL;
    }

    if (ASF_EnableTimeoutEventByID(priv, mask) != CDN_EINVAL) {
        return CDN_EINVAL;
    }

    if (ASF_DisableTimeoutEventByMask(priv, mask) != CDN_EINVAL) {
        return CDN_EINVAL;
    }

    if (ASF_DisableTimeoutEventByID(priv, mask) != CDN_EINVAL) {
        return CDN_EINVAL;
    }

    if (ASF_GetStatistic(priv, &stats) != CDN_EINVAL) {
        return CDN_EINVAL;
    }

    if (ASF_ClearStatistic(priv) != CDN_EINVAL) {
        return CDN_EINVAL;
    }

    if (ASF_RestoreStatistic(priv, &stats) != CDN_EINVAL) {
        return CDN_EINVAL;
    }

    /* restore state */
    priv->state = prevState;

    return CDN_EOK;
}
