 /******************************************************************************
 *
 * Copyright (C) 2012-2021 Cadence Design Systems, Inc.
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
 *
 * mechanical_test_defs.c
 *
 * Helper Functions for I3C Master mechanical tests
 *
 ******************************************************************************
 */

#ifdef MECHANICAL_TESTS

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <cdn_errno.h>
# include <cdn_stdint.h>

# include "mechanical_test_defs.h"

# define log(F_, ...) printf("[MECH_TH] " F_, ##__VA_ARGS__)

# if I3C_REGS_SIZE > 0x00010000
#  error "I3C Master registers space seems to be quite big."
# endif

static uint32_t I3C_REGS[I3C_REGS_SIZE / sizeof(uint32_t)];

uint32_t API_TEST_testSetup(I3C_OBJ *i3c, I3C_PrivData **pd)
{
    I3C_SysReq req = { 0 };
    I3C_Config cfg = { 0 };

    uint32_t result;

    if (!i3c) {
        log("Error. No driver instance!\n");
        return EINVAL;
    }

    if (!pd) {
        log("Error. Argument pd is NULL!\n");
        return EINVAL;
    }

    if ((result = i3c->probe(&cfg, &req))) {
        log("Error. Failed to probe config. Errno: %d\n", result);
        return ECANCELED;
    }

    if ((*pd = (I3C_PrivData*)malloc(req.memReq)) == NULL) {
        log("Error. Failed to alocate memory for driver private data\n");
        return ENOMEM;
    }

    // There is no need to set the callback pointers inside to NULL for mech tests
    memset(*pd, 0, req.memReq);

    // Clear "registers" before each test
    memset(I3C_REGS, 0, sizeof(I3C_REGS));

    // No need for real registers access
    // (+ first field of the I3C_PrivData struct is regs_base:
    //  volatile uint32_t *)
    *((volatile uint32_t *)*pd) = (uintptr_t)&I3C_REGS;

    return 0;
}

void API_TEST_testTearDown(I3C_OBJ *i3c, I3C_PrivData *pd)
{
    // Not calling i3c->destroy(), because it requires working HW.

    if (pd) {
        free(pd);
    } else {
        log("Warning. No private data!\n");
    }
}

#endif

