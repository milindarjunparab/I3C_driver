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
#ifndef INIT_TESTS_H
#define INIT_TESTS_H

#include <cdn_errno.h>
#include <cdn_stdtypes.h>
#include <cps.h>
#include <cdn_log.h>
#include <string.h>

#include "functional_test_helpers.h"
#include "functional_test_defs.h"
#include "i3c_if.h"
#include "i3c_obj_if.h"
#include "i3c_common.h"
#include "map_system_memory.h"
#include "mipi_i3c_regs.h"

int test_init_params(void);
int test_init_sec_master_disable_interrupts(void);
int test_init_parts_core_enabled(void);
int test_init_stop_interrupt(void);
int test_init_destroy(void);
int test_init_bus_mode(void);
int test_init_without_devs(void);
int test_init_core_idle_timeout(void);
int test_init_core_idle(void);
int test_init_too_many_devs(void);
int test_init_pure_bus(void);
int test_init_prescalers_with_no_timings(void);

#endif /* INIT_TESTS_H */
