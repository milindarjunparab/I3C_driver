/******************************************************************************
 *
 * Copyright (C) 2012-2024 Cadence Design Systems, Inc.
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
#include "i3c_target.h"
#include "cps_ei.h"

/**
 *Test Name: test_get_slave_mrl_mwl
 *Test Description: This test reads mrl and mwl value from slave
 *Pass Conditions: mrl and mwl values read correctly
 *Fail Conditions: any other status
 *Use Case: I3C Bus management, status read from target
*/
int test_get_slave_mrl_mwl(void)
{
    uint32_t status = 0;
    int i;
    I3C_OBJ *I3CM_drv;
    I3CS_OBJ *I3CS_drv;
    uint16_t maxWriteLength = 0;
    uint16_t maxReadLength = 0;
    uint8_t ibiPayloadSize = 0;

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


    /**********************/
    /* Bus initialization */
    /**********************/
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

    for (i = 1; i < number_of_all_test_devices; i++) {
        if (all_test_devices[i]->role == I3C_ROLE_SECONDAY_MASTER) {
                status += I3CM_drv->slaveModeReadMWL(all_test_devices[i]->private_data, &maxWriteLength);
                status += I3CM_drv->slaveModeReadMRL(all_test_devices[i]->private_data, &maxReadLength, &ibiPayloadSize);
		cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "%s, Device %d MWL = %x MRL= %x IBIPayload = %x\n", __func__,
			       	i, maxWriteLength, maxReadLength, ibiPayloadSize);
        }
    }

    return status;
}

/**
 *Test Name: test_sdr_master_slave_fill_lvl
 *Test Description: This test reads fill level from slave
 *Pass Conditions: mrl and mwl values read correctly
 *Fail Conditions: any other status
 *Use Case: I3C Bus management, status read from target
*/
int test_sdr_master_slave_fill_lvl(void)
{
    uint32_t status = 0;
    int i = 0;
    uint16_t fillLvl_tx = 0;
    uint16_t fillLvl_rx = 0;
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


    /**********************/
    /* Bus initialization */
    /**********************/
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

    for (i = 0; i < 3; i++) {
                status += I3CM_drv->getFifoFillLvl(all_test_devices[i]->private_data, &fillLvl_tx, &fillLvl_rx);
		cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "%s, Device %d TX_Fill_lvl = %x RX_Fill_lvl= %x\n", __func__, i, fillLvl_tx, fillLvl_rx);
    }

    return status;
}

/**
 *Test Name: test_sdr_slave_flush_done
 *Test Description: This test initiate flush at Target side
 *Pass Conditions: flush data from fifo
 *Fail Conditions: any other status
 *Use Case: I3C Bus management, status read from target
*/
int test_sdr_slave_flush_done(void)
{
    uint32_t status = 0;
    int i = 0;
    bool flush_tx = true;
    bool flush_rx = false;
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


    /**********************/
    /* Bus initialization */
    /**********************/
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

    for (i = 1; i < number_of_all_test_devices; i++) {
        if (all_test_devices[i]->ibi_capable == 1 &&
            all_test_devices[i]->role == I3C_ROLE_SECONDAY_MASTER) {
                status += I3CM_drv->setSdrFifoFlush(all_test_devices[i]->private_data, flush_tx, flush_rx);
		cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "%s, Device %d Set flush Cmd for TX %d RX %d\n", __func__, i, flush_tx, flush_rx);
        }
    }


    delay_ms(5);

    status += wait_for_global_status(&(global_i3c_status.slv_flushDone));
    return status;
}
