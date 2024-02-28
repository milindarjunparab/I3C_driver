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
#include "functional_test_callbacks.h"
#include <cdn_log.h>

i3c_sts_t global_i3c_status;

void cmd_response_threshold_cb(void *pd){
    cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s\n", __func__);
    global_i3c_status.cmd_response_threshold = true;
}
void cmd_descriptor_threshold_cb(void *pd){
    cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s\n", __func__);
    global_i3c_status.cmd_descriptor_threshold = true;
}
void tx_threshold_cb(void *pd){
    cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s\n", __func__);
    global_i3c_status.tx_threshold = true;
}
void rx_threshold_cb(void *pd){
    cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s\n", __func__);
    global_i3c_status.rx_threshold = true;
}
void ibi_response_threshold_cb(void *pd){
    cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s\n", __func__);
    global_i3c_status.ibi_response_threshold = true;
}
void ibi_data_threshold_cb(void *pd){
    cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s\n", __func__);
    global_i3c_status.ibi_data_threshold = true;
}
void immediate_command_complete_cb(void *pd){
    cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "%s\n", __func__);
    global_i3c_status.immediate_command_complete = true;
}
void mastership_done_cb(void *pd){
    cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s\n", __func__);
    global_i3c_status.mastership_done = true;
}
void halted_cb(void *pd){
    cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s\n", __func__);
    global_i3c_status.halted = true;
}

void cmd_buffer_empty_cb(void *pd)
{
    cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s\n", __func__);
    global_i3c_status.cmd_buffer_empty = true;
}

void command_complete_cb(void *pd)
{
    cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s\n", __func__);
    global_i3c_status.command_complete = true;
}

void daa_complete_cb(void *pd)
{
    cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s\n", __func__);
    global_i3c_status.daa_complete = true;
}

void mastership_request_cb(void *pd)
{
  cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s\n", __func__);
  global_i3c_status.mastership_request = true;
}

void hot_join_cb(void *pd)
{
  cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s\n", __func__);
  global_i3c_status.hot_join = true;
}
void inband_interrupt_cb(void *pd)
{
  cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s\n", __func__);
  global_i3c_status.inband_interrupt = true;
}

void slv_sdr_read_comp_cb(void *pd)
{
  cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s\n", __func__);
  global_i3c_status.slv_sdr_read_comp = true;
}

void slv_sdr_write_comp_cb(void *pd)
{
  cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s\n", __func__);
  global_i3c_status.slv_sdr_write_comp = true;
}

void slv_ddr_read_comp_cb(void *pd)
{
  cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s\n", __func__);
  global_i3c_status.slv_ddr_read_comp = true;
}

void slv_ddr_write_comp_cb(void *pd)
{
  cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s\n", __func__);
  global_i3c_status.slv_ddr_write_comp = true;
}

void slv_ibi_done_cb(void *pd)
{
  cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s\n", __func__);
  global_i3c_status.slv_ibi_done = true;
}

void slv_sdrError_cb(void *pd)
{
  cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s\n", __func__);
  cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "If NACK_NXT_PR is HIGH then private read currupted.\n", __func__);
  global_i3c_status.slv_sdrError = true;
}

void slv_test_mode_cb(void *pd)
{
  cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s\n", __func__);
  global_i3c_status.slv_test_mode = true;
}

void slv_mwlChange_cb(void *pd)
{
  cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s\n", __func__);
  global_i3c_status.slv_mwl_change = true;
}

void slv_mrlChange_cb(void *pd)
{
  cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s\n", __func__);
  global_i3c_status.slv_mrl_change = true;
}

void slv_resetDaa_cb(void *pd)
{
  cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s\n", __func__);
  global_i3c_status.slv_rstDaa = true;
}

void slv_busconUp_cb(void *pd)
{
  cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s\n", __func__);
  global_i3c_status.slv_busconUp = true;
}

void slv_flushDone_cb(void *pd)
{
  cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s\n", __func__);
  global_i3c_status.slv_flushDone = true;
}
