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
#ifndef CCC_TESTS_H
#define CCC_TESTS_H

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

int test_ccc_set_new_da(void);
int test_ccc_set_get_max_read_length(void);
int test_ccc_set_get_max_read_length_bcst_with_ibi(void);
int test_ccc_set_get_max_write_length(void);
int test_ccc_set_get_max_write_length_bcst(void);
int test_cmd_buffer_overflow(void);
int test_cmd_large_without_fifos(void);
int test_ccc_get_status(void);
int test_ccc_enter_test_mode(void);
int test_ccc_reset_daa_exec_wait(void);
int test_ccc_reset_daa_broadcast(void);
int test_ccc_set_ad_from_sa_no_device(void);
int test_ccc_enter_activity_state(void);
int test_ccc_set_get_max_data_speed(void);
int test_ccc_slave_event_invalid_mask(void);
int test_ccc_set_slave_events(void);
int test_ccc_set_nca_mode_in_priv_write(void);
int test_ccc_set_slave_mrl_mwl(void);
int test_ccc_set_slave_buscon(void);
int test_ccc_set_target_reset_broadcast(void);
int test_ccc_set_time_control(void);
int test_ccc_get_time_control(void);
int test_ccc_set_group_address(void);
int test_ccc_set_define_group_list(void);
int test_ccc_reset_group_address(void);
#endif /* CCC_TESTS_H */
