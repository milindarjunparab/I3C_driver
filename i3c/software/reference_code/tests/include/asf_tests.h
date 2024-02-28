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
 * asf_tests.h
 * Header file containing declaration of tests
 *****************************************************************************/
#ifndef ASF_TEST_H
#define ASF_TEST_H

#include  "asf_priv.h"
#include "cdn_stdtypes.h"

uint32_t ASF_testStopStartReinit(ASF_PrivateData *priv);
uint32_t ASF_testIncorrectDriverState(ASF_PrivateData *priv);
uint32_t ASF_testBIST1(ASF_PrivateData *priv);
uint32_t ASF_testBIST2(ASF_PrivateData *priv);
uint32_t ASF_testDisableAllEventsFunc(ASF_PrivateData *priv);
uint32_t ASF_testEnableAllEventsFunc(ASF_PrivateData *priv);
uint32_t ASF_testEnableEventFunc(ASF_PrivateData *priv);
uint32_t ASF_testSetEventAsNonFatalFunc(ASF_PrivateData *priv, uint8_t instId);
uint32_t ASF_testDisableEventFunc(ASF_PrivateData *priv);
uint32_t ASF_testEnableProtocolEventByMaskFunc(ASF_PrivateData *priv);
uint32_t ASF_testDisableProtocolEventByMaskFunc(ASF_PrivateData *priv);
uint32_t ASF_testEnableProtocolEventByIDFunc(ASF_PrivateData *priv);
uint32_t ASF_testDisableProtocolEventByIDFunc(ASF_PrivateData *priv);
uint32_t ASF_testEnableTimeoutEventByMaskFunc(ASF_PrivateData *priv);
uint32_t ASF_testDisableTimeoutEventByMaskFunc(ASF_PrivateData *priv);
uint32_t ASF_testEnableTimeoutEventByIDFunc(ASF_PrivateData *priv);
uint32_t ASF_testDisableTimeoutEventByIDFunc(ASF_PrivateData *priv);
uint32_t ASF_testStatisticFunc(ASF_PrivateData *priv);

#endif
