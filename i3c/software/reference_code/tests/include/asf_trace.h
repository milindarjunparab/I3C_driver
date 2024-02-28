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
 * asf_trace.h
 * debugging functions header file
 *****************************************************************************/
#ifndef ASF_TRACE_H
#define ASF_TRACE_H

//#define TRACE_ENABLED

#ifdef TRACE_ENABLED
/**
 * Display configuration information related with ASF controller 
 * @param[in] privateData Driver state info specific to this instance.
 * @return Error code
*/
uint32_t ASF_traceConfigSetting(ASF_PrivateData * priv); 

/**
 * Displays generic statistic information
 * @param[in] stat Statistic information object
 * @return void
*/
void ASF_TraceSimpleStatInfo(ASF_StatInfo *stat);

/**
 * Displays extended statistic information
 * In addition to the generic information function display 
 * information about reported timeout and protocol errors.
 * @param[in] stat Statistic information object
 * @return void
*/
void ASF_TraceExtendedStatInfo(ASF_StatInfo *stat);


/**
 * Function changes event error code to strintg 
 * param[in] eventErrorCode ASF event error code
 * return Event error in string form
*/
char * ASF_EventErrorTypeToString(ASF_EventErrorType eventErrorCode);

/**
 * Function display information about event
 * param[in] eventInfo object containg information related to detected fault condition
 * return void
*/
void ASF_traceEvent(ASF_EventInfo* eventInfo);
#else 
#define ASF_traceConfigSetting(priv)
#define ASF_TraceSimpleStatInfo(stat)
#define ASF_TraceExtendedStatInfo(stat)
#define ASF_EventErrorTypeToString(eventErrorCode)
#define ASF_traceEvent(eventInfo)
#endif

#endif //ASF_TRACE_H

