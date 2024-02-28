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
#ifndef FUNCTIONAL_TEST_DEFS_H
#define FUNCTIONAL_TEST_DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <cdn_stdtypes.h>
#include <cdn_log.h>
#include "test_harness_log.h"


/* Include header files with test declarations */
#include "sdr_tests.h"
#include "ddr_tests.h"
#include "imm_tests.h"
#include "hot_join_tests.h"
#include "ibi_tests.h"
#include "mastership_request_tests.h"
#include "ccc_tests.h"
#include "asf_tests.h"
#include "init_tests.h"
#include "i2c_tests.h"
#include "ei_tests.h"
#include "api_tests.h"
#include "i3c_target.h"
/**
 * Simple test structure containing only name of the test and pointer to a
 * function that will perform it.
 * @field name Test name.
 * @field run Pointer to function that performs test.
 * @field done Set when test status is reported.
 */
typedef struct {
    char *name;
    int (*run)(void);
    bool done;
    bool skip_on_tlm;
} test_t;

extern test_t functional_tests[];


#endif /* FUNCTIONAL_TEST_DEFS_H */
