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
#ifndef _DDR_TESTS_H_
#define _DDR_TESTS_H_

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

int ddr_master_write(I3C_OBJ* master_driver,
         void* master_private_data,
         uint16_t receiver_dynamic_address,
         uint16_t* tx_data,
         size_t tx_data_size);

int ddr_master_read(I3C_OBJ* master_driver,
        void* master_private_data,
        uint8_t transmitter_dynamic_address,
        uint16_t* rx_data,
        size_t rx_data_size);

int ddr_secondary_master_write(I3C_OBJ *master_driver,
             void* secondary_master_private_data,
             uint16_t* tx_data,
             size_t tx_data_size);

int ddr_secondary_master_read(I3C_OBJ *master_driver,
            void* secondary_master_private_data,
            uint16_t* rx_data,
            size_t rx_data_size);

int ddr_send_to_secondary_master(I3C_OBJ *master_driver,
         fn_test_i3c_device* master,
         fn_test_i3c_device* secondary_master,
         uint16_t* tx_data,
         size_t data_size);

int test_ddr_master_sec_master_tx(void);
int test_ddr_master_sec_master_rx(void);
int test_ddr_master_sec_master_tx_threshold(void);
int test_ddr_master_sec_master_rx_threshold(void);
int test_ddr_master_slave_tx(void);
int test_ddr_master_slave_rx(void);
int test_sec_master_tx_no_data(void);
int test_sec_master_rx_without_daa(void);

#endif	/* _DDR_TESTS_H_ */
