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
#ifndef _FUNCTIONAL_TEST_HELPERS_H_
#define _FUNCTIONAL_TEST_HELPERS_H_

#include <stdio.h>
#include <stdlib.h>
#include <cdn_stdtypes.h>
#include <cdn_log.h>

#include "i3c_if.h"
#include "i3c_structs_if.h"
#include "i3cs_if.h"
#include "i3cs_structs_if.h"
#include "device_definitions.h"
#include "functional_test_callbacks.h"
#include "i3c_obj_if.h"
#include "i3cs_obj_if.h"
#include "map_system_memory.h"
#include "system.h"
#include "test_harness_log.h"

/**
 * @name check_if_i3c_device_is_of_role - checks if passed device is
 * of passed role (ex. if passed device if i3c slave)
 * @param i3c_device -  pointer to i3c device
 * @param i3c_role -  i3c role
 * @return error code, non zero means error
 */
int check_if_i3c_device_is_of_role(fn_test_i3c_device* i3c_device,
           fn_test_i3c_role i3c_role);

/**
 * @name print_status_before_return - prints info to user about status
 * of function, useful to call this function at the end of function
 * returning numerical status code
 * @param status - integer that represents status, zero for status OK
 * @param function_name - name of the function where status variable
 * was written
 * @return void
 */
void print_status_before_return(int status,
        const char* function_name);

uint32_t wait_for_global_status(volatile bool* i3c_status);

static void (*i2c_post_isr_handler)(void) = NULL;

//selective soft reset defines
#define RST_ALL  0xFF
#define RST_MST  0x01
#define RST_DEV1 0x02
#define RST_DEV2 0x04
#define RST_DEV3 0x08
#define RST_DEV4 0x10
#define RST_DEV5 0x20
#define RST_DEV6 0x40
#define RST_DEV7 0x80

void generate_uint8_test_data(uint8_t* data, int number_of_samples);
void generate_uint16_test_data(uint16_t* data, int number_of_samples);
void print_data_compare(uint8_t *exp, uint8_t *act, size_t size);
void reset_devices(uint8_t rst_msk);
void delay_us(unsigned int us);
void delay_ms(unsigned int ms);
uint32_t i3c_reg_read(fn_test_i3c_device* i3c_device, uint32_t reg);
void i3c_reg_write(fn_test_i3c_device* i3c_device, uint32_t reg, uint32_t val);
static void I3CM_TH_InterruptHandler(uint32_t num);
void i3c_IrqInit(void);
/* # ifndef div_round_up */
/* inline uint32_t div_round_up(uint32_t divident, uint32_t divider); */
/* # endif */
int setup_device_descriptors(I3C_DeviceDescriptor** device_descriptors, int* device_descriptors_number,
           fn_test_i3c_device** all_test_devices, int number_of_all_test_devices);
int initialize_master(I3C_OBJ *master_driver,
          I3C_DeviceDescriptor* device_descriptors,
          int device_descriptors_number,
          fn_test_i3c_device** all_test_devices,
          int number_of_all_test_devices);
int initialize_secondary_master(I3C_OBJ *master_driver,
        I3C_DeviceDescriptor* device_descriptors,
        int device_descriptors_number,
        fn_test_i3c_device* secondary_master);
int initialize_other_test_devs(I3C_OBJ *master_driver,
             I3CS_OBJ *slave_driver,
             I3C_DeviceDescriptor* device_descriptors,
             int device_descriptors_number,
             fn_test_i3c_device** all_test_devices,
             int number_of_all_test_devices);
void initialize_slave_i2c(fn_test_i3c_device* i2c_dev);

/* This function initializes bus with use of non-immediate commands
   only. */
void initialize_bus_non_imm_cmds(I3C_OBJ *drv,
         fn_test_i3c_device** all_test_devices,
         int number_of_all_test_devices);

/* This function initializes bus with use of immediate commands
   only. */
void initialize_bus_imm_cmds(I3C_OBJ *drv,
          fn_test_i3c_device** all_test_devices,
          int number_of_all_test_devices);

/* This function initializes bus with a mix of immediate and
   non-immediate commands. */
void initialize_bus_imm_non_imm_mix(I3C_OBJ *drv,
            fn_test_i3c_device** all_test_devices,
            int number_of_all_test_devices);

#endif	/* _FUNCTIONAL_TEST_HELPERS_H_ */
