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
/**
 * This file holds basic callbacks that just print messages. More
 * sophisticated callbacks should be used in real life.
 */

#ifndef _FUNCTIONAL_TEST_CALLBACKS_H_
#define _FUNCTIONAL_TEST_CALLBACKS_H_

#include <stdio.h>
#include <stdlib.h>
#include <cdn_stdtypes.h>

#include "i3c_if.h"
#include "i3c_obj_if.h"

typedef struct {
	bool cmd_response_threshold;
	bool cmd_descriptor_threshold;
	bool tx_threshold;
	bool rx_threshold;
	bool ibi_response_threshold;
	bool ibi_data_threshold;
    bool immediate_command_complete;
    bool mastership_done;
    bool halted;
    bool cmd_buffer_empty;
    bool command_complete;
    bool daa_complete;
    bool mastership_request;
    bool hot_join;
    bool inband_interrupt;
    bool slv_sdr_read_comp;
    bool slv_sdr_write_comp;
    bool slv_ddr_read_comp;
    bool slv_ddr_write_comp;
    bool slv_ibi_done;
    bool slv_sdrError;
    bool slv_test_mode;
    bool slv_mwl_change;
    bool slv_mrl_change;
    bool slv_rstDaa;
    bool slv_busconUp;
    bool slv_flushDone;
} i3c_sts_t;

extern i3c_sts_t global_i3c_status;
extern I3C_CommandStatus global_command_status;

void cmd_response_threshold_cb(void *pd);
void cmd_descriptor_threshold_cb(void *pd);
void tx_threshold_cb(void *pd);
void rx_threshold_cb(void *pd);
void ibi_response_threshold_cb(void *pd);
void ibi_data_threshold_cb(void *pd);
void immediate_command_complete_cb(void *pd);
void mastership_done_cb(void *pd);
void halted_cb(void *pd);
void cmd_buffer_empty_cb(void *pd);
void command_complete_cb(void *pd);
void daa_complete_cb(void *pd);
void mastership_request_cb(void *pd);
void hot_join_cb(void *pd);
void inband_interrupt_cb(void *pd);
void slv_sdr_read_comp_cb(void *pd);
void slv_sdr_write_comp_cb(void *pd);
void slv_ddr_read_comp_cb(void *pd);
void slv_ddr_write_comp_cb(void *pd);
void slv_ibi_done_cb(void *pd);
void slv_sdrError_cb(void *pd);
void slv_test_mode_cb(void *pd);
void slv_resetDaa_cb(void *pd);
void slv_busconUp_cb(void *pd);
void slv_flushDone_cb(void *pd);
void slv_mwlChange_cb(void *pd);
void slv_mrlChange_cb(void *pd);
#endif	/* _FUNCTIONAL_TEST_CALLBACKS_H_ */
