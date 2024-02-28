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
#include "functional_test_defs.h"

test_t functional_tests[] = {
    /* SDR tests */
    {.name = "test_sdr_master_sec_master_tx", .run = test_sdr_master_sec_master_tx},
    {.name = "test_sdr_master_sec_master_rx", .run = test_sdr_master_sec_master_rx},
    {.name = "test_sdr_master_sec_master_tx_threshold", .run = test_sdr_master_sec_master_tx_threshold},
    {.name = "test_sdr_master_sec_master_rx_threshold", .run = test_sdr_master_sec_master_rx_threshold},
    {.name = "test_sdr_master_sec_master_tx_multiple", .run = test_sdr_master_sec_master_tx_multiple},
    {.name = "test_sdr_master_slave_tx", .run = test_sdr_master_slave_tx},
    {.name = "test_sdr_master_slave_rx", .run = test_sdr_master_slave_rx},

    /* DDR tests */
    {.name = "test_ddr_master_sec_master_tx", .run = test_ddr_master_sec_master_tx},
    {.name = "test_ddr_master_sec_master_rx", .run = test_ddr_master_sec_master_rx},
    {.name = "test_ddr_master_sec_master_tx_threshold", .run = test_ddr_master_sec_master_tx_threshold},
    {.name = "test_ddr_master_sec_master_rx_threshold", .run = test_ddr_master_sec_master_rx_threshold},
    {.name = "test_ddr_master_slave_tx", .run = test_ddr_master_slave_tx},
    {.name = "test_ddr_master_slave_rx", .run = test_ddr_master_slave_rx},
    {.name = "test_sec_master_tx_no_data", .run = test_sec_master_tx_no_data},
    {.name = "test_sec_master_rx_without_daa", .run = test_sec_master_rx_without_daa},

    /* Bus init tests */
    {.name = "test_non_imm_bus_init", .run = test_non_imm_bus_init},
    {.name = "test_imm_bus_init", .run = test_imm_bus_init},
    {.name = "test_imm_non_imm_mix_bus_init", .run = test_imm_non_imm_mix_bus_init},
    {.name = "test_imm_in_progress", .run = test_imm_in_progress},
    {.name = "test_imm_inject", .run = test_imm_inject},

    /* Hot join tests */
    {.name = "test_hot_join_sec_mster", .run = test_hot_join_sec_mster},
    {.name = "test_hot_join_slave", .run = test_hot_join_slave},

    /* IBI tests */
    {.name = "test_ibi", .run = test_ibi},
    {.name = "test_ibi_nack", .run = test_ibi_nack},
    {.name = "test_ibi_address_of_issuer", .run = test_ibi_address_of_issuer},
    {.name = "test_ibi_slot_overflow", .run = test_ibi_slot_overflow},
    {.name = "test_ibi_tcam0_event", .run = test_ibi_tcam0_event},

    /* Mastership request tests */
    {.name = "test_mastership_request_sec_mster", .run = test_mastership_request_sec_mster},

    /* CCC tests */
    {.name = "test_ccc_set_new_da", .run = test_ccc_set_new_da},
    {.name = "test_ccc_set_ad_from_sa_no_device", .run = test_ccc_set_ad_from_sa_no_device},
    {.name = "test_ccc_set_get_max_read_length", .run = test_ccc_set_get_max_read_length},
    {.name = "test_ccc_set_get_max_read_length_bcst_with_ibi", .run = test_ccc_set_get_max_read_length_bcst_with_ibi},
    {.name = "test_ccc_set_get_max_write_length", .run = test_ccc_set_get_max_write_length},
    {.name = "test_ccc_set_get_max_write_length_bcst", .run = test_ccc_set_get_max_write_length_bcst},
    {.name = "test_cmd_buffer_overflow", .run = test_cmd_buffer_overflow},
    {.name = "test_cmd_large_without_fifos", .run = test_cmd_large_without_fifos},
    {.name = "test_ccc_get_status", .run = test_ccc_get_status},
    {.name = "test_ccc_enter_test_mode", .run = test_ccc_enter_test_mode},
//    {.name = "test_ccc_reset_daa_exec_wait", .run = test_ccc_reset_daa_exec_wait},
    {.name = "test_ccc_reset_daa_broadcast", .run = test_ccc_reset_daa_broadcast},
    {.name = "test_ccc_enter_activity_state", .run = test_ccc_enter_activity_state},
    {.name = "test_ccc_set_get_max_data_speed", .run = test_ccc_set_get_max_data_speed},
    {.name = "test_ccc_slave_event_invalid_mask", .run = test_ccc_slave_event_invalid_mask},
    {.name = "test_ccc_set_slave_events", .run = test_ccc_set_slave_events},
    {.name = "test_ccc_set_nca_mode_in_priv_write", .run = test_ccc_set_nca_mode_in_priv_write},
//    {.name = "test_ccc_set_slave_mrl_mwl", .run = test_ccc_set_slave_mrl_mwl},
    {.name = "test_ccc_set_slave_buscon", .run = test_ccc_set_slave_buscon},
    {.name = "test_ccc_set_target_reset", .run = test_ccc_set_target_reset_broadcast},
    {.name = "test_ccc_set_time_control", .run = test_ccc_set_time_control},
    {.name = "test_ccc_get_time_control", .run = test_ccc_get_time_control},
    {.name = "test_ccc_set_group_address", .run = test_ccc_set_group_address},
//    {.name = "test_ccc_set_define_group_list", .run = test_ccc_set_define_group_list}, // not required
    {.name = "test_ccc_reset_group_address", .run = test_ccc_reset_group_address},

    /* Device init tests */
    {.name = "test_init_params", .run = test_init_params},
    {.name = "test_init_sec_master_disable_interrupts", .run = test_init_sec_master_disable_interrupts},
    {.name = "test_init_parts_core_enabled", .run = test_init_parts_core_enabled},
    {.name = "test_init_stop_interrupt", .run = test_init_stop_interrupt},
    {.name = "test_init_destroy", .run = test_init_destroy},
    {.name = "test_init_bus_mode", .run = test_init_bus_mode},
    {.name = "test_init_without_devs", .run = test_init_without_devs},
    {.name = "test_init_core_idle", .run = test_init_core_idle},
    {.name = "test_init_too_many_devs", .run = test_init_too_many_devs},
    {.name = "test_init_pure_bus", .run = test_init_pure_bus},
    {.name = "test_init_prescalers_with_no_timings", .run = test_init_prescalers_with_no_timings},

    /* I2C tests */
    {.name = "test_i2c_write", .run = test_i2c_write, .skip_on_tlm = true},
    {.name = "test_i2c_read", .run = test_i2c_read, .skip_on_tlm = true},
    {.name = "test_i2c_inactive_device_init", .run = test_i2c_inactive_device_init},

    /* Error Injected tests */
    {.name = "test_isr_no_interrupt", .run = test_isr_no_interrupt},
    {.name = "test_isr_tx_rx_thr_cmd_list_empty", .run = test_isr_tx_rx_thr_cmd_list_empty},
    {.name = "test_auto_configuration", .run = test_auto_configuration},
    {.name = "test_transfer_to_non_existing_device", .run = test_transfer_to_non_existing_device},

    /* API tests */
    {.name = "test_get_asf_info", .run = test_getasfinfo},
    {.name = "test_cmd_add_ddr_write", .run = test_cmdaddddrwrite},
    {.name = "test_cmd_add_ddr_read", .run = test_cmdaddddrread},
    {.name = "test_cmd_exec", .run = test_cmdexec},

    /* I3C get/set tests */
    {.name = "test_get_slave_mrl_mwl", .run = test_get_slave_mrl_mwl},
    {.name = "test_sdr_master_slave_fill_lvl", .run = test_sdr_master_slave_fill_lvl},
    {.name = "test_sdr_slave_flush_done", .run = test_sdr_slave_flush_done},
    { NULL, NULL },
};
