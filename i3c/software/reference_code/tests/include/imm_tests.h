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
#ifndef IMM_TESTS_H
#define IMM_TESTS_H

#include <cdn_errno.h>
#include <cdn_stdtypes.h>
#include <cps.h>
#include <cdn_log.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functional_test_helpers.h"
#include "functional_test_defs.h"
#include "i3c_if.h"
#include "i3c_obj_if.h"
#include "i3c_common.h"
#include "map_system_memory.h"
#include "mipi_i3c_regs.h"

/* This test initializes bus with non-immediate commands and runs SDR
   transfer. */
int test_non_imm_bus_init(void);

/* This test initializes bus with immediate commands only and runs SDR
   transfer. */
int test_imm_bus_init(void);

/* This test initializes bus with a mix of non-immediate and immediate
   commands and runs SDR transfer. */
int test_imm_non_imm_mix_bus_init(void);

int test_imm_in_progress(void);

int test_imm_inject(void);

#endif /* IMM_TESTS_H */
