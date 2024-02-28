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
#include "sdr_tests.h"
#include "imm_tests.h"

/**
 *Test Name: test_non_imm_bus_init
 *Test Description: This test initializes the bus using non-immediate commands
 *Pass Conditions: data transfer after initialization passed
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C Bus management, Immediate commands, Prescaler configuration
*/
int test_non_imm_bus_init(void)
{
    uint32_t status = 0;

    I3C_OBJ *I3CM_drv;
    I3CS_OBJ *I3CS_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
                 * descriptors that goes
                 * to master driver and
                 * is used for bus
                 * configuration. */
    int device_descriptors_number = 0;

    int i3c_tx_buf_size = 10;
    uint8_t* i3c_tx_buf = (uint8_t*)malloc(sizeof(uint8_t) * i3c_tx_buf_size);

    generate_uint8_test_data(i3c_tx_buf, i3c_tx_buf_size);

    i3c_IrqInit();

    I3CM_drv = I3C_GetInstance();
    I3CS_drv = I3CS_GetInstance();

    reset_devices(RST_ALL);

    // wait for slave 1ms ON delay
    // additional 270us is needed
    // so for fclk=50MHz and actual clock 2.451
    /* following does the job */

    delay_ms(3);


    setup_device_descriptors(&device_descriptors, &device_descriptors_number,
           all_test_devices, number_of_all_test_devices);

    initialize_master(I3CM_drv,
          device_descriptors,
          device_descriptors_number,
          all_test_devices,
          number_of_all_test_devices);


    initialize_bus_non_imm_cmds(I3CM_drv,
        all_test_devices,
        number_of_all_test_devices);


    initialize_other_test_devs(I3CM_drv,
             I3CS_drv,
             device_descriptors,
             device_descriptors_number,
             all_test_devices,
             number_of_all_test_devices);


    /*****************/
    /* SDR Transfers */
    /*****************/
    status = 0;
    status += sdr_send_to_secondary_master(I3CM_drv,
             all_test_devices[0],
             all_test_devices[1],
             i3c_tx_buf,
             i3c_tx_buf_size);

    free(i3c_tx_buf);

    return status;
}

/**
 *Test Name: test_imm_bus_init
 *Test Description: This test initializes the bus using immediate commands
 *Pass Conditions: data transfer after initialization passed
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C Bus management, Immediate commands, Prescaler configuration
*/
int test_imm_bus_init(void)
{
    uint32_t status = 0;

    I3C_OBJ *I3CM_drv;
    I3CS_OBJ *I3CS_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
                 * descriptors that goes
                 * to master driver and
                 * is used for bus
                 * configuration. */
    int device_descriptors_number = 0;

    int i3c_tx_buf_size = 10;
    uint8_t* i3c_tx_buf = (uint8_t*)malloc(sizeof(uint8_t) * i3c_tx_buf_size);

    generate_uint8_test_data(i3c_tx_buf, i3c_tx_buf_size);

    i3c_IrqInit();

    I3CM_drv = I3C_GetInstance();
    I3CS_drv = I3CS_GetInstance();

    reset_devices(RST_ALL);

    // wait for slave 1ms ON delay
    // additional 270us is needed
    // so for fclk=50MHz and actual clock 2.451
    /* following does the job */

    delay_ms(3);


    setup_device_descriptors(&device_descriptors, &device_descriptors_number,
           all_test_devices, number_of_all_test_devices);

    initialize_master(I3CM_drv,
          device_descriptors,
          device_descriptors_number,
          all_test_devices,
          number_of_all_test_devices);


    initialize_bus_imm_cmds(I3CM_drv,
          all_test_devices,
          number_of_all_test_devices);


    initialize_other_test_devs(I3CM_drv,
             I3CS_drv,
             device_descriptors,
             device_descriptors_number,
             all_test_devices,
             number_of_all_test_devices);


    /*****************/
    /* SDR Transfers */
    /*****************/
    status = 0;
    status += sdr_send_to_secondary_master(I3CM_drv,
             all_test_devices[0],
             all_test_devices[1],
             i3c_tx_buf,
             i3c_tx_buf_size);

    free(i3c_tx_buf);

    return status;
}

/**
 *Test Name: test_imm_non_imm_mix_bus_init
 *Test Description: This test initializes the bus using mixed immediate and non-immediate commands
 *Pass Conditions: data transfer after initialization passed
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C Bus management, Immediate commands, Prescaler configuration
*/
int test_imm_non_imm_mix_bus_init(void)
{
    uint32_t status = 0;

    I3C_OBJ *I3CM_drv;
    I3CS_OBJ *I3CS_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
                 * descriptors that goes
                 * to master driver and
                 * is used for bus
                 * configuration. */
    int device_descriptors_number = 0;

    int i3c_tx_buf_size = 10;
    uint8_t* i3c_tx_buf = (uint8_t*)malloc(sizeof(uint8_t) * i3c_tx_buf_size);

    generate_uint8_test_data(i3c_tx_buf, i3c_tx_buf_size);

    i3c_IrqInit();

    I3CM_drv = I3C_GetInstance();
    I3CS_drv = I3CS_GetInstance();

    reset_devices(RST_ALL);

    // wait for slave 1ms ON delay
    // additional 270us is needed
    // so for fclk=50MHz and actual clock 2.451
    /* following does the job */

    delay_ms(3);


    setup_device_descriptors(&device_descriptors, &device_descriptors_number,
           all_test_devices, number_of_all_test_devices);

    initialize_master(I3CM_drv,
          device_descriptors,
          device_descriptors_number,
          all_test_devices,
          number_of_all_test_devices);


    initialize_bus_imm_non_imm_mix(I3CM_drv,
           all_test_devices,
           number_of_all_test_devices);


    initialize_other_test_devs(I3CM_drv,
             I3CS_drv,
             device_descriptors,
             device_descriptors_number,
             all_test_devices,
             number_of_all_test_devices);


    /*****************/
    /* SDR Transfers */
    /*****************/
    status = 0;
    status += sdr_send_to_secondary_master(I3CM_drv,
             all_test_devices[0],
             all_test_devices[1],
             i3c_tx_buf,
             i3c_tx_buf_size);

    free(i3c_tx_buf);

    return status;
}

/**
 *Test Name: test_imm_in_progress
 *Test Description: This test tries to send immediate command when other immediate command is in progress
 *Pass Conditions: API function returns CDN_EBUSY
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: Immediate commands
*/
int test_imm_in_progress(void)
{
    uint32_t status = 0;

    I3C_OBJ *I3CM_drv;
    I3CS_OBJ *I3CS_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
                 * descriptors that goes
                 * to master driver and
                 * is used for bus
                 * configuration. */
    int device_descriptors_number = 0;

    i3c_IrqInit();

    I3CM_drv = I3C_GetInstance();
    I3CS_drv = I3CS_GetInstance();

    reset_devices(RST_ALL);

    // wait for slave 1ms ON delay
    // additional 270us is needed
    // so for fclk=50MHz and actual clock 2.451
    /* following does the job */

    delay_ms(3);


    setup_device_descriptors(&device_descriptors, &device_descriptors_number,
           all_test_devices, number_of_all_test_devices);

    initialize_master(I3CM_drv,
          device_descriptors,
          device_descriptors_number,
          all_test_devices,
          number_of_all_test_devices);


    initialize_bus_imm_non_imm_mix(I3CM_drv,
           all_test_devices,
           number_of_all_test_devices);


    initialize_other_test_devs(I3CM_drv,
             I3CS_drv,
             device_descriptors,
             device_descriptors_number,
             all_test_devices,
             number_of_all_test_devices);


    I3C_TransmissionParameters params = {
            .immediate = true
    };

    if(I3CM_drv->cmdAddEnterTestMode(all_test_devices[MASTER]->private_data,
                0, &params) != 0U) {
        status++;
    }

    if(I3CM_drv->cmdAddEnterTestMode(all_test_devices[MASTER]->private_data,
                    0, &params) != CDN_EBUSY) {
        status++;
    }

    return status;
}

/**
 *Test Name: test_imm_inject
 *Test Description: This test injects immediate command between non-immediate commands
 *Pass Conditions: immediate command is execute first
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C Bus management, Immediate commands
*/
int test_imm_inject(void)
{
    uint32_t status = 0;
    int i;

    I3C_OBJ *I3CM_drv;
    I3CS_OBJ *I3CS_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
                 * descriptors that goes
                 * to master driver and
                 * is used for bus
                 * configuration. */
    int device_descriptors_number = 0;

    i3c_IrqInit();

    I3CM_drv = I3C_GetInstance();
    I3CS_drv = I3CS_GetInstance();

    reset_devices(RST_ALL);

    // wait for slave 1ms ON delay
    // additional 270us is needed
    // so for fclk=50MHz and actual clock 2.451
    /* following does the job */

    delay_ms(3);


    setup_device_descriptors(&device_descriptors, &device_descriptors_number,
           all_test_devices, number_of_all_test_devices);

    initialize_master(I3CM_drv,
          device_descriptors,
          device_descriptors_number,
          all_test_devices,
          number_of_all_test_devices);


    initialize_bus_imm_non_imm_mix(I3CM_drv,
           all_test_devices,
           number_of_all_test_devices);


    initialize_other_test_devs(I3CM_drv,
             I3CS_drv,
             device_descriptors,
             device_descriptors_number,
             all_test_devices,
             number_of_all_test_devices);


    I3C_TransmissionParameters params = { 0 };

    for(i = 0; i<20; i++) {
	I3CM_drv->cmdAddEnterTestMode(all_test_devices[MASTER]->private_data, 0, &params);
    }
    I3CM_drv->cmdExec(all_test_devices[MASTER]->private_data);

    params.immediate = true;
    I3CM_drv->cmdAddEnterTestMode(all_test_devices[MASTER]->private_data, 0, &params);

    status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));

    if(I3CM_drv->cmdCount(all_test_devices[MASTER]->private_data) == 0) {
	status++;
    }

    return status;
}
