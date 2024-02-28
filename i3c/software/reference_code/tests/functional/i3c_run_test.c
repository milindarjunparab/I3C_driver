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
 ******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cdn_errno.h"
#include "csp.h"

#include "functional_test_callbacks.h"
#include "functional_test_helpers.h"
#include "functional_test_defs.h"
#include "unit_test_defs.h"
#include "map_system_memory.h"
#include "system.h"

static TestData testData;

/** test setup function */
uint32_t I3C_RunFunctionalTests() {
    
    testData.groupName = "I3C Functional tests";
    testData.groupIndex = 0;
    
    START_TESTING(testData);
    
    test_t *test = functional_tests;

    while (test->name) {
        if (csp_get_id_flow() == CSP_IF_TLM && test->skip_on_tlm) {
            ++test;
            continue;
        }

        cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "\nRunning: \t- %s\n", test->name);
        if(test->run() == CDN_EOK) 
            TESTING_TEST_PASSED(test->name, testData);
        else 
            TESTING_TEST_FAILED(test->name, testData);
        ++test;
    }

    TESTING_SUMMARY(testData);

    return !((testData.passed == testData.calls) && (testData.calls > 0));
}
