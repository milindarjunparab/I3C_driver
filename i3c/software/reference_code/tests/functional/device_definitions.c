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
#include "device_definitions.h"

fn_test_i3c_device master_0_primary = {
    .private_data = NULL,
    .static_address = 0x8,
    .dynamic_address = 0x20,
    .has_static_address = 0,
    .pid = 0,
    .role = I3C_ROLE_MASTER,
    .is_active = 1,
    .is_legacy_i2c_device = 0,
    .has_apb = 1,
    .registers_base = I3C_MST0_REGS_BASE,
    .hdr_capable = 1,
    .ibi_capable = 1,
};

fn_test_i3c_device master_1_secondary = {
    .private_data = NULL,
    .static_address = 0x34,
    .dynamic_address = 0x42,
    .has_static_address = 1,
    .pid = 0,
    .role = I3C_ROLE_SECONDAY_MASTER,
    .is_active = 1,
    .is_legacy_i2c_device = 0,
    .has_apb = 1,
    .registers_base = I3C_MST1_REGS_BASE,
    .hdr_capable = 0,
    .ibi_capable = 0,
};

fn_test_i3c_device master_2_secondary = {
    .private_data = NULL,
    .static_address = 0x35,
    .dynamic_address = 0x44,
    .has_static_address = 0,
    .pid = 0,
    .role = I3C_ROLE_SECONDAY_MASTER,
    .is_active = 1,
    .is_legacy_i2c_device = 0,
    .has_apb = 1,
    .registers_base = I3C_MST2_REGS_BASE,
    .hdr_capable = 1,
    .ibi_capable = 1,
};

fn_test_i3c_device slave_0 = {
    .private_data = NULL,
    .static_address = 0x36,
    .dynamic_address = 0x45,
    .has_static_address = 0,
    .pid = 0,
    .role = I3C_ROLE_SLAVE,
    .is_active = 1,
    .is_legacy_i2c_device = 0,
    .has_apb = 1,
    .registers_base = I3C_SLV0_REGS_BASE,
    .hdr_capable = 0,
    .ibi_capable = 0,
};

fn_test_i3c_device slave_1 = {
    .private_data = NULL,
    .static_address = 0x37,
    .dynamic_address = 0x0C,
    .has_static_address = 0,
    .pid = 0,
    .role = I3C_ROLE_SLAVE,
    .is_active = 1,
    .is_legacy_i2c_device = 0,
    .has_apb = 1,
    .registers_base = I3C_SLV1_REGS_BASE,
    .hdr_capable = 1,
    .ibi_capable = 1,
};

fn_test_i3c_device slave_2 = {
    .private_data = NULL,
    .static_address = 0x38,
    .dynamic_address = 0xAD,
    .has_static_address = 1,
    .pid = 0,
    .role = I3C_ROLE_SLAVE,
    .is_active = 1,
    .is_legacy_i2c_device = 0,
    .has_apb = 1,
    .registers_base = I3C_SLV2_REGS_BASE,
    .hdr_capable = 0,
    .ibi_capable = 0,
};

fn_test_i3c_device i2c_slave = {
    .private_data = NULL,
    .static_address = 0x10,
    .dynamic_address = 0x10,
    .has_static_address = 1,
    .pid = 0,
    .role = I2C_ROLE_SLAVE,
    .is_active = 1,
    .is_legacy_i2c_device = 1,
    .is_i2c_10b_addr = 0,
    .is_i2c_fm_plus = 0,
    .has_apb = 1,
    .registers_base = I2C1_REGS_BASE,
    .hdr_capable = 0,
    .ibi_capable = 0,
};

fn_test_i3c_device i2c_slave_fm = {
    .private_data = NULL,
    .static_address = 0x10,
    .dynamic_address = 0x10,
    .has_static_address = 1,
    .pid = 0,
    .role = I2C_ROLE_SLAVE,
    .is_active = 1,
    .is_legacy_i2c_device = 1,
    .is_i2c_10b_addr = 1,
    .is_i2c_fm_plus = 1,
    .has_apb = 1,
    .registers_base = I2C1_REGS_BASE,
    .hdr_capable = 0,
    .ibi_capable = 0,
};

fn_test_i3c_device* all_test_devices[] = {
    &master_0_primary,
    &master_1_secondary,
    &master_2_secondary,
    &slave_0,
    &slave_1,
};

int number_of_all_test_devices = 5;
