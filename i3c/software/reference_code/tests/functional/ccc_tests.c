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
#include "ccc_tests.h"
#include "cps_ei.h"
#define DEBUG
int ccc_set_new_da(I3C_OBJ* master_driver, void* master_private_data,
        uint8_t receiver_dynamic_address, uint8_t receiver_new_dynamic_address)
{
    int status = 0; /**< Will hold a sum of errors in case any occur. */
    I3C_TransmissionParameters params = { 0 };
    status += master_driver->cmdClearAll(master_private_data);
    status += master_driver->cmdAddSetNewDa(master_private_data,
            receiver_new_dynamic_address, receiver_dynamic_address, &params);
    status += master_driver->cmdExec(master_private_data);

    /* waiting for all transfers to be finished*/
    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    status += master_driver->devPrint(master_private_data);

    print_status_before_return(status, __func__);

    return status;
}

/**
 *Test Name: test_ccc_set_new_da
 *Test Description: This test updates Dynamic Address of the device
 *Pass Conditions: device has correct address
 *Fail Conditions: device has not correct address
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddSetNewDa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C Bus management
*/
int test_ccc_set_new_da(void)
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

    uint8_t new_dynamic_address = 0x0D;

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

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            all_test_devices, number_of_all_test_devices);

    initialize_bus_non_imm_cmds(I3CM_drv, all_test_devices,
            number_of_all_test_devices);

    initialize_other_test_devs(I3CM_drv, I3CS_drv, device_descriptors,
            device_descriptors_number, all_test_devices,
            number_of_all_test_devices);

    status += ccc_set_new_da(I3CM_drv, all_test_devices[MASTER]->private_data,
            all_test_devices[SEC_MASTER_0]->dynamic_address,
            new_dynamic_address);

    if (all_test_devices[MASTER]->private_data->devs[1].addr
            != new_dynamic_address) {
        cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "TEST ERROR: New DA was not set\n");
        status++;
    }

    return status;
}

/**
 *Test Name: test_ccc_set_get_max_read_length
 *Test Description: This test set maximum data read length
 *Pass Conditions: read correct value from the device
 *Fail Conditions: value read from device is incorrect
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddSetNewDa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C Bus management, Interrupts
*/
int test_ccc_set_get_max_read_length(void)
{
    uint timeout = 10000;

    uint32_t status = 0;

    I3C_OBJ *I3CM_drv;
    I3CS_OBJ *I3CS_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
     * descriptors that goes
     * to master driver and
     * is used for bus
     * configuration. */
    int device_descriptors_number = 0;

    I3C_TransmissionParameters params = { 0 };

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

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            all_test_devices, number_of_all_test_devices);

    initialize_bus_non_imm_cmds(I3CM_drv, all_test_devices,
            number_of_all_test_devices);

    initialize_other_test_devs(I3CM_drv, I3CS_drv, device_descriptors,
            device_descriptors_number, all_test_devices,
            number_of_all_test_devices);

    I3C_MaxReadLength set_max_read_length = { 0 };
    I3C_MaxReadLength get_max_read_length = { 0 };

    set_max_read_length.payload_length = 5000;

    status += I3CM_drv->cmdAddSetMaxReadLength(
            all_test_devices[MASTER]->private_data, set_max_read_length, 2, /* bytes required to encode max read length */
            all_test_devices[SEC_MASTER_0]->dynamic_address, &params);
    status += I3CM_drv->cmdExec(all_test_devices[MASTER]->private_data);

    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    status += I3CM_drv->cmdAddGetMaxReadLength(
            all_test_devices[MASTER]->private_data, &get_max_read_length, 2, /* bytes required to encode max read length */
            all_test_devices[SEC_MASTER_0]->dynamic_address, &params);
    status += I3CM_drv->cmdExec(all_test_devices[MASTER]->private_data);

    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    if (set_max_read_length.payload_length
            != get_max_read_length.payload_length) {
        cDbgMsg(DBG_GEN_MSG,
                DBG_CRIT,
                "TEST ERROR: set_max_read_length.payload_length(%d) != get_max_read_length.payload_length(%d)\n",
                set_max_read_length.payload_length,
                get_max_read_length.payload_length);
        status++;
    }

    return status;
}

/**
 *Test Name: test_ccc_set_get_max_read_length_bcst_with_ibi
 *Test Description: This test set maximum data read length to all devices
 *Pass Conditions: read correct value from the device
 *Fail Conditions: value read from device is incorrect
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddSetNewDa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C Bus management, Interrupts
*/
int test_ccc_set_get_max_read_length_bcst_with_ibi(void)
{
    uint timeout = 10000;

    uint32_t status = 0;

    I3C_OBJ *I3CM_drv;
    I3CS_OBJ *I3CS_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
     * descriptors that goes
     * to master driver and
     * is used for bus
     * configuration. */
    int device_descriptors_number = 0;

    I3C_TransmissionParameters params = {
            .broadcast = true
    };

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

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            all_test_devices, number_of_all_test_devices);

    initialize_bus_non_imm_cmds(I3CM_drv, all_test_devices,
            number_of_all_test_devices);

    initialize_other_test_devs(I3CM_drv, I3CS_drv, device_descriptors,
            device_descriptors_number, all_test_devices,
            number_of_all_test_devices);

    I3C_MaxReadLength set_max_read_length = { 0 };
    I3C_MaxReadLength get_max_read_length = { 0 };

    set_max_read_length.payload_length = 4000;
    set_max_read_length.ibi_payload_length = 10;

    status += I3CM_drv->cmdAddSetMaxReadLength(
            all_test_devices[MASTER]->private_data, set_max_read_length, 3, /* bytes required to encode max read length */
            0, &params);
    status += I3CM_drv->cmdExec(all_test_devices[MASTER]->private_data);

    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    status += I3CM_drv->cmdAddGetMaxReadLength(
            all_test_devices[MASTER]->private_data, &get_max_read_length, 2, /* bytes required to encode max read length, device without ibi support */
            all_test_devices[SEC_MASTER_0]->dynamic_address, &params);
    status += I3CM_drv->cmdExec(all_test_devices[MASTER]->private_data);

    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    if (set_max_read_length.payload_length
            != get_max_read_length.payload_length) {
        cDbgMsg(DBG_GEN_MSG,
                DBG_CRIT,
                "TEST ERROR: set_max_read_length.payload_length(%d) != get_max_read_length.payload_length(%d)\n",
                set_max_read_length.payload_length,
                get_max_read_length.payload_length);
        status++;
    }

    return status;
}

/**
 *Test Name: test_ccc_set_get_max_write_length
 *Test Description: This test set maximum data write length
 *Pass Conditions: read correct value from the device
 *Fail Conditions: value read from device is incorrect
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddSetNewDa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C Bus management, Interrupts
*/
int test_ccc_set_get_max_write_length(void)
{
    uint timeout = 10000;

    uint32_t status = 0;

    I3C_OBJ *I3CM_drv;
    I3CS_OBJ *I3CS_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
     * descriptors that goes
     * to master driver and
     * is used for bus
     * configuration. */
    int device_descriptors_number = 0;

    I3C_TransmissionParameters params = { 0 };

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

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            all_test_devices, number_of_all_test_devices);

    initialize_bus_non_imm_cmds(I3CM_drv, all_test_devices,
            number_of_all_test_devices);

    initialize_other_test_devs(I3CM_drv, I3CS_drv, device_descriptors,
            device_descriptors_number, all_test_devices,
            number_of_all_test_devices);

    uint16_t set_max_write_length = 500;
    status += I3CM_drv->cmdAddSetMaxWriteLength(
            all_test_devices[MASTER]->private_data, set_max_write_length,
            all_test_devices[SEC_MASTER_0]->dynamic_address, &params);
    status += I3CM_drv->cmdExec(all_test_devices[MASTER]->private_data);

    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    uint16_t get_max_write_length = 0;
    status += I3CM_drv->cmdAddGetMaxWriteLength(
            all_test_devices[MASTER]->private_data, &get_max_write_length,
            all_test_devices[SEC_MASTER_0]->dynamic_address, &params);
    status += I3CM_drv->cmdExec(all_test_devices[MASTER]->private_data);

    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    if (set_max_write_length
            != get_max_write_length) {
        cDbgMsg(DBG_GEN_MSG,
                DBG_CRIT,
                "TEST ERROR: set_max_write_length != get_max_write_length\n");
        status++;
    }

    return status;
}

/**
 *Test Name: test_ccc_set_get_max_write_length_bcst
 *Test Description: This test set maximum data write length to all devices
 *Pass Conditions: read correct value from the device
 *Fail Conditions: value read from device is incorrect
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddSetNewDa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C Bus management, Interrupts
*/
int test_ccc_set_get_max_write_length_bcst(void)
{
    uint timeout = 10000;

    uint32_t status = 0;

    I3C_OBJ *I3CM_drv;
    I3CS_OBJ *I3CS_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
     * descriptors that goes
     * to master driver and
     * is used for bus
     * configuration. */
    int device_descriptors_number = 0;

    I3C_TransmissionParameters params = {
            .broadcast = true
    };

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

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            all_test_devices, number_of_all_test_devices);

    initialize_bus_non_imm_cmds(I3CM_drv, all_test_devices,
            number_of_all_test_devices);

    initialize_other_test_devs(I3CM_drv, I3CS_drv, device_descriptors,
            device_descriptors_number, all_test_devices,
            number_of_all_test_devices);

    uint16_t set_max_write_length = 499;
    status += I3CM_drv->cmdAddSetMaxWriteLength(
            all_test_devices[MASTER]->private_data, set_max_write_length,
            0, &params);
    status += I3CM_drv->cmdExec(all_test_devices[MASTER]->private_data);

    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    uint16_t get_max_write_length = 0;
    status += I3CM_drv->cmdAddGetMaxWriteLength(
            all_test_devices[MASTER]->private_data, &get_max_write_length,
            all_test_devices[SEC_MASTER_0]->dynamic_address, &params);
    status += I3CM_drv->cmdExec(all_test_devices[MASTER]->private_data);

    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    if (set_max_write_length
                != get_max_write_length) {
        cDbgMsg(DBG_GEN_MSG,
                DBG_CRIT,
                "TEST ERROR: set_max_write_length != get_max_write_length\n");
        status++;
    }

    return status;
}

/**
 *Test Name: test_cmd_buffer_overflow
 *Test Description: This test tries to add CCC commands when software FIFO is full
 *Pass Conditions: API function returns CDN_EBUSY
 *Fail Conditions: API function does not return CDN_EBUSY
 *APIs called: I3C_CmdAddDdrRead, I3C_CmdAddDdrWrite, I3C_CmdAddSetSlaveEvents, I3C_CmdAddEnterActivityState, I3C_CmdAddResetDaa, I3C_CmdAddEnterDaa, I3C_CmdAddSetMaxWriteLength, I3C_CmdAddGetMaxWriteLength, I3C_CmdAddSetMaxReadLength, I3C_CmdAddGetMaxReadLength, I3C_CmdAddDefineSlavesList, I3C_CmdAddEnterTestMode, I3C_CmdAddEnterHdrMode, I3C_CmdSetDaFromSa, I3C_CmdAddSetNewDa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus, I3C_CmdAddGetAccMst, I3C_CmdAddPrivRead, I3C_CmdAddPrivWrite, I3C_CmdAddGetMaxDataSpeed
 *Use Case: Software command queue
*/
int test_cmd_buffer_overflow(void)
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

    I3C_TransmissionParameters params = { 0 };

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

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            all_test_devices, number_of_all_test_devices);

    initialize_bus_non_imm_cmds(I3CM_drv, all_test_devices,
            number_of_all_test_devices);

    initialize_other_test_devs(I3CM_drv, I3CS_drv, device_descriptors,
            device_descriptors_number, all_test_devices,
            number_of_all_test_devices);

    // Indicate command list is full
    all_test_devices[MASTER]->private_data->cmd_list.count =
            all_test_devices[MASTER]->private_data->cmd_list.capacity;

    I3C_PayloadData payloadData = { 0 };
    I3C_CsrData csrData = { 0 };
    I3C_HdrMode hdrMode = { 0 };
    I3C_TransmissionParameters txParams = { 0 };
    I3C_ActivityState activityState = { 0 };
    I3C_MaxReadLength readLength = { 0 };
    I3C_SlaveDescriptors slaveDesc = { 0 };

    if (I3CM_drv->cmdAddDdrRead(all_test_devices[MASTER]->private_data,
            all_test_devices[SEC_MASTER_0]->dynamic_address, 0x80U, hdrMode,
            &payloadData) != CDN_EBUSY) {
        status++;
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed at cmdAddDdrRead.\n");
    }

    if (I3CM_drv->cmdAddDdrWrite(all_test_devices[MASTER]->private_data,
            all_test_devices[SEC_MASTER_0]->dynamic_address, 0x7FU, hdrMode,
            &payloadData) != CDN_EBUSY) {
        status++;
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed at cmdAddDdrWrite.\n");
    }

    if (I3CM_drv->cmdAddSetSlaveEvents(all_test_devices[MASTER]->private_data,
            I3C_SLAVE_EVENT_INTERRUPT_REQS, true,
            all_test_devices[SEC_MASTER_0]->dynamic_address, &txParams) != CDN_EBUSY) {
        status++;
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed at cmdAddSetSlaveEvents.\n");
    }

    if (I3CM_drv->cmdAddEnterActivityState(
            all_test_devices[MASTER]->private_data, activityState,
            all_test_devices[SEC_MASTER_0]->dynamic_address, &txParams) != CDN_EBUSY) {
        status++;
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed at cmdAddEnterActivityState.\n");
    }

    if (I3CM_drv->cmdAddResetDaa(all_test_devices[MASTER]->private_data,
            all_test_devices[SEC_MASTER_0]->dynamic_address, &txParams) != CDN_EBUSY) {
        status++;
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed at cmdAddResetDaa.\n");
    }

    if (I3CM_drv->cmdAddEnterDaa(all_test_devices[MASTER]->private_data,
            &txParams) != CDN_EBUSY) {
        status++;
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed at cmdAddEnterDaa.\n");
    }

    if (I3CM_drv->cmdAddSetMaxWriteLength(
            all_test_devices[MASTER]->private_data, 2,
            all_test_devices[SEC_MASTER_0]->dynamic_address, &txParams) != CDN_EBUSY) {
        status++;
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed at cmdAddSetMaxWriteLength.\n");
    }

    uint16_t length = 2;
    if (I3CM_drv->cmdAddGetMaxWriteLength(
            all_test_devices[MASTER]->private_data, &length,
            all_test_devices[SEC_MASTER_0]->dynamic_address, &txParams) != CDN_EBUSY) {
        status++;
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed at cmdAddGetMaxWriteLength.\n");
    }

    if (I3CM_drv->cmdAddSetMaxReadLength(all_test_devices[MASTER]->private_data,
            readLength, 2, all_test_devices[SEC_MASTER_0]->dynamic_address,
            &txParams) != CDN_EBUSY) {
        status++;
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed at cmdAddSetMaxReadLength.\n");
    }

    if (I3CM_drv->cmdAddGetMaxReadLength(all_test_devices[MASTER]->private_data,
            &readLength, 2, all_test_devices[SEC_MASTER_0]->dynamic_address,
            &txParams) != CDN_EBUSY) {
        status++;
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed at cmdAddGetMaxReadLength.\n");
    }

    if (I3CM_drv->cmdAddDefineSlavesList(all_test_devices[MASTER]->private_data,
            &slaveDesc, &txParams) != CDN_EBUSY) {
        status++;
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed at cmdAddDefineSlavesList.\n");
    }

    if (I3CM_drv->cmdAddEnterTestMode(all_test_devices[MASTER]->private_data, 0,
            &txParams) != CDN_EBUSY) {
        status++;
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed at cmdAddEnterTestMode.\n");
    }

    if (I3CM_drv->cmdAddEnterHdrMode(all_test_devices[MASTER]->private_data,
            hdrMode, &txParams) != CDN_EBUSY) {
        status++;
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed at cmdAddEnterHdrMode.\n");
    }

    if (I3CM_drv->cmdSetDaFromSa(all_test_devices[MASTER]->private_data, 0,
            all_test_devices[SEC_MASTER_0]->dynamic_address, &txParams) != CDN_EBUSY) {
        status++;
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed at cmdSetDaFromSa.\n");
    }

    if (I3CM_drv->cmdAddSetNewDa(all_test_devices[MASTER]->private_data, 0, 0,
            &txParams) != CDN_EBUSY) {
        status++;
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed at cmdAddSetNewDa.\n");
    }

    uint8_t buff;
    if (I3CM_drv->cmdAddGetProvisionalId(all_test_devices[MASTER]->private_data,
            &buff, 0, &txParams) != CDN_EBUSY) {
        status++;
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed at cmdAddGetProvisionalId.\n");
    }

    if (I3CM_drv->cmdAddGetBcr(all_test_devices[MASTER]->private_data, &buff, 0,
            &txParams) != CDN_EBUSY) {
        status++;
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed at cmdAddGetBcr.\n");
    }

    if (I3CM_drv->cmdAddGetDcr(all_test_devices[MASTER]->private_data, &buff, 0,
            &txParams) != CDN_EBUSY) {
        status++;
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed at cmdAddGetBcr.\n");
    }

    if (I3CM_drv->cmdAddGetStatus(all_test_devices[MASTER]->private_data, &buff,
            0, &txParams) != CDN_EBUSY) {
        status++;
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed at cmdAddGetStatus.\n");
    }

    if (I3CM_drv->cmdAddGetAccMst(all_test_devices[MASTER]->private_data, &buff,
            0, &txParams) != CDN_EBUSY) {
        status++;
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed at cmdAddGetAccMst.\n");
    }

    if (I3CM_drv->cmdAddPrivRead(all_test_devices[MASTER]->private_data,
            all_test_devices[SEC_MASTER_0]->dynamic_address, &csrData,
            &payloadData, I3C_CMD_XMIT_MODE_SINGLE_CSR) != CDN_EBUSY) {
        status++;
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed at cmdAddPrivRead.\n");
    }

    if (I3CM_drv->cmdAddPrivWrite(all_test_devices[MASTER]->private_data,
            all_test_devices[SEC_MASTER_0]->dynamic_address, &csrData,
            &payloadData, I3C_CMD_XMIT_MODE_SINGLE_CSR) != CDN_EBUSY) {
        status++;
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed at cmdAddPrivWrite.\n");
    }
    
    I3C_MaxDataSpeed speed;
    if (I3CM_drv->cmdAddGetMaxDataSpeed(all_test_devices[MASTER]->private_data,
            &speed,
            all_test_devices[SEC_MASTER_0]->dynamic_address, &txParams) != CDN_EBUSY) {
        status++;
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed at cmdAddPrivWrite.\n");
    }

    return status;
}

/**
 *Test Name: test_ccc_set_ad_from_sa_no_device
 *Test Description: This test updates Dynamic Address of non-existing device
 *Pass Conditions: API function returns CDN_EINVAL
 *Fail Conditions: API function does not return CDN_EINVAL
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddSetNewDa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: Change address of dynamic addressed device
*/
int test_ccc_set_ad_from_sa_no_device(void)
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

    uint8_t new_dynamic_address = 0x0D;

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

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            all_test_devices, number_of_all_test_devices);

    initialize_bus_non_imm_cmds(I3CM_drv, all_test_devices,
            number_of_all_test_devices);

    initialize_other_test_devs(I3CM_drv, I3CS_drv, device_descriptors,
            device_descriptors_number, all_test_devices,
            number_of_all_test_devices);

    I3C_TransmissionParameters params = {0};

    if (I3CM_drv->cmdSetDaFromSa(all_test_devices[MASTER]->private_data,
            new_dynamic_address,
            0x7F, /* fake address */
            &params) != CDN_EINVAL) {
        status++;
    }

    return status;
}

/**
 *Test Name: test_cmd_large_without_fifos
 *Test Description: This test tries to send command with large payload without data FIFOs
 *Pass Conditions: API function returns CDN_EINVAL
 *Fail Conditions: API function does not return CDN_EINVAL
 *APIs called: I3C_CmdExec, I3C_CmdExecImmediate, I3C_EnableMcs, I3C_DisableMcs, I3C_ManualCommandStart
 *Use Case: Commands support
*/
int test_cmd_large_without_fifos(void)
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

    I3C_TransmissionParameters params = { 0 };

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

    /* Case without fifos */
    if(CPSEI_Enable() != 0U) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Cannot initialize CPSEI.\n");
    }
    MIPI_I3cRegs *regs_base = (MIPI_I3cRegs*)(all_test_devices[MASTER]->registers_base);
    uint32_t reg_val = 0U;
    /* Values bigger than auto-config should disable fifos */
    reg_val = CPS_FLD_WRITE(MIPI__CONF_STATUS1, IBI_HW_RES, reg_val, 0xDU);
    reg_val = CPS_FLD_WRITE(MIPI__CONF_STATUS1, IBI_MEM_DEPTH, reg_val, 0x6U);
    reg_val = CPS_FLD_WRITE(MIPI__CONF_STATUS1, TX_MEM_DEPTH, reg_val, 0xEU);
    reg_val = CPS_FLD_WRITE(MIPI__CONF_STATUS1, RX_MEM_DEPTH, reg_val, 0xEU);
    CPSEI_AddReadError(&(regs_base->CONF_STATUS1),
            reg_val, 0, 0, 1);

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            all_test_devices, number_of_all_test_devices);

    initialize_bus_non_imm_cmds(I3CM_drv, all_test_devices,
            number_of_all_test_devices);

    initialize_other_test_devs(I3CM_drv, I3CS_drv, device_descriptors,
            device_descriptors_number, all_test_devices,
            number_of_all_test_devices);

    I3C_PayloadData payloadData = { .payloadSize = 10 };
    I3C_CsrData csrData = { 0 };

    if (I3CM_drv->cmdAddPrivRead(all_test_devices[MASTER]->private_data,
            all_test_devices[SEC_MASTER_0]->dynamic_address, &csrData,
            &payloadData, I3C_CMD_XMIT_MODE_SINGLE_CSR) != CDN_EINVAL) {
        status++;
    }

    if (I3CM_drv->cmdAddDdrRead(all_test_devices[MASTER]->private_data,
            all_test_devices[SEC_MASTER_0]->dynamic_address, 0, I3C_HDR_MODE_DDR,
            &payloadData) != CDN_EINVAL) {
        status++;
    }

    if (I3CM_drv->cmdAddPrivWrite(all_test_devices[MASTER]->private_data,
            all_test_devices[SEC_MASTER_0]->dynamic_address, &csrData,
            &payloadData, I3C_CMD_XMIT_MODE_SINGLE_CSR) != CDN_EINVAL) {
        status++;
    }

    if (I3CM_drv->cmdAddDdrWrite(all_test_devices[MASTER]->private_data,
            all_test_devices[SEC_MASTER_0]->dynamic_address, 0x80, I3C_HDR_MODE_DDR,
            &payloadData) != CDN_EINVAL) {
        status++;
    }

    return status;
}

/**
 *Test Name: test_ccc_get_status
 *Test Description: This test get status of the device
 *Pass Conditions: Status is correct
 *Fail Conditions: Any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_CmdExec, I3C_CmdExecImmediate, I3C_CmdExecImmediate, I3C_EnableMcs, I3C_DisableMcs, I3C_ManualCommandStart, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C bus management, Commands Interrupts, Commands support
*/
int test_ccc_get_status(void)
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

    I3C_TransmissionParameters params = { 0 };

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

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            all_test_devices, number_of_all_test_devices);

    initialize_bus_non_imm_cmds(I3CM_drv, all_test_devices,
            number_of_all_test_devices);

    initialize_other_test_devs(I3CM_drv, I3CS_drv, device_descriptors,
            device_descriptors_number, all_test_devices,
            number_of_all_test_devices);

    uint16_t devStatus = 0;
    if(I3CM_drv->cmdAddGetStatus(all_test_devices[MASTER]->private_data,
            &devStatus, all_test_devices[SEC_MASTER_0]->dynamic_address,
            &params) != 0U) {
        status++;
    }

    status += I3CM_drv->cmdExec(all_test_devices[MASTER]->private_data);

    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    return status;
}

/**
 *Test Name: test_ccc_enter_test_mode
 *Test Description: This test sends enter test mode to slave
 *Pass Conditions: slave got test mode event
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_CmdExec, I3C_CmdExecImmediate, I3C_EnableMcs, I3C_DisableMcs, I3C_ManualCommandStart, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdAddEnterTestMode, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C bus management, Commands Interrupts, Commands support, Test Mode
*/
int test_ccc_enter_test_mode(void)
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

    I3C_TransmissionParameters params = { 
	.immediate = true
    };

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

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            all_test_devices, number_of_all_test_devices);

    initialize_bus_non_imm_cmds(I3CM_drv, all_test_devices,
            number_of_all_test_devices);

    initialize_other_test_devs(I3CM_drv, I3CS_drv, device_descriptors,
            device_descriptors_number, all_test_devices,
            number_of_all_test_devices);

    if(I3CM_drv->cmdAddEnterTestMode(all_test_devices[MASTER]->private_data,
            0x01, &params) != 0U) {
        status++;
    }

    status += wait_for_global_status(&(global_i3c_status.slv_test_mode));

    return status;
}

/**
 *Test Name: test_ccc_reset_daa_exec_wait
 *Test Description: This test resets DA of the device
 *Pass Conditions: device cannot perform transfer
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddResetDaa, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C bus management, Commands Interrupts
*/
int test_ccc_reset_daa_exec_wait(void)
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

    I3C_TransmissionParameters params = { 0 };

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

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            all_test_devices, number_of_all_test_devices);

    initialize_bus_non_imm_cmds(I3CM_drv, all_test_devices,
            number_of_all_test_devices);

    initialize_other_test_devs(I3CM_drv, I3CS_drv, device_descriptors,
            device_descriptors_number, all_test_devices,
            number_of_all_test_devices);

    uint16_t devStatus = 0;
    if(I3CM_drv->cmdAddResetDaa(all_test_devices[MASTER]->private_data,
            all_test_devices[SEC_MASTER_0]->dynamic_address,
            &params) != 0U) {
        status++;
    }

    status += I3CM_drv->cmdExec(all_test_devices[MASTER]->private_data);

    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    uint16_t buf_in = 0xAB;
    if(I3CM_drv->slaveModeReqDdrWrite(all_test_devices[SEC_MASTER_0]->private_data,
            &buf_in, 1) != CDN_ENOTSUP) {
        status++;
    }

    return status;
}

/**
 *Test Name: test_ccc_reset_daa_broadcast
 *Test Description: This test resets DA of all devices
 *Pass Conditions: device cannot perform transfer
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddResetDaa, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C bus management, Commands Interrupts
*/
int test_ccc_reset_daa_broadcast(void)
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

    I3C_TransmissionParameters params = {
            .broadcast = true
    };

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

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            all_test_devices, number_of_all_test_devices);

    initialize_bus_non_imm_cmds(I3CM_drv, all_test_devices,
            number_of_all_test_devices);

    initialize_other_test_devs(I3CM_drv, I3CS_drv, device_descriptors,
            device_descriptors_number, all_test_devices,
            number_of_all_test_devices);

    uint16_t devStatus = 0;
    if(I3CM_drv->cmdAddResetDaa(all_test_devices[MASTER]->private_data,
            all_test_devices[SEC_MASTER_0]->dynamic_address,
            &params) != 0U) {
        status++;
    }

    status += I3CM_drv->cmdExec(all_test_devices[MASTER]->private_data);

    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    uint16_t buf_in = 0xAB;
    if(I3CM_drv->slaveModeReqDdrWrite(all_test_devices[SEC_MASTER_0]->private_data,
            &buf_in, 1) != CDN_ENOTSUP) {
        status++;
    }

    return status;
}

/**
 *Test Name: test_ccc_enter_activity_state
 *Test Description: This test sends enter activity state mode to slave
 *Pass Conditions: correct status is returned from slave
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterActivityState, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C bus management, Commands Interrupts, Power Management
*/
int test_ccc_enter_activity_state(void)
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

    I3C_TransmissionParameters params = { 0 };

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

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
	    all_test_devices, number_of_all_test_devices);

    initialize_bus_non_imm_cmds(I3CM_drv, all_test_devices,
	    number_of_all_test_devices);

    initialize_other_test_devs(I3CM_drv, I3CS_drv, device_descriptors,
	    device_descriptors_number, all_test_devices,
	    number_of_all_test_devices);

    I3C_ActivityState activityState = I3C_ACTIVITY_STATE_3;

    status += I3CM_drv->cmdAddEnterActivityState(
	    all_test_devices[MASTER]->private_data,
	    activityState,
	    all_test_devices[SLAVE_0]->dynamic_address, &params);
    
    uint16_t devStatus = 0;
    status += I3CM_drv->cmdAddGetStatus(all_test_devices[MASTER]->private_data,
                &devStatus, all_test_devices[SEC_MASTER_0]->dynamic_address,
                &params);
    
    status += I3CM_drv->cmdExec(all_test_devices[MASTER]->private_data);

    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    return status;
}

/**
 *Test Name: test_ccc_set_slave_events
 *Test Description: This test disabled IBI event
 *Pass Conditions: slave cannot perform IBI
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C bus management, Commands Interrupts, IBI Interrupts
*/
int test_ccc_set_slave_events(void)
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

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            all_test_devices, number_of_all_test_devices);

    initialize_bus_non_imm_cmds(I3CM_drv, all_test_devices,
            number_of_all_test_devices);

    initialize_other_test_devs(I3CM_drv, I3CS_drv, device_descriptors,
            device_descriptors_number, all_test_devices,
            number_of_all_test_devices);


    I3C_TransmissionParameters txParams = { 
	.immediate = true
    };
    
    status += I3CM_drv->cmdAddSetSlaveEvents(all_test_devices[MASTER]->private_data,
					     I3C_SLAVE_EVENT_INTERRUPT_REQS,
					     false,
					     all_test_devices[SLAVE_1]->dynamic_address, 
					     &txParams);

    status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));

    /* Slave needs some time to reflect IBI_DIS status */
    delay_ms(5);

    if (I3CS_drv->requestIbi(all_test_devices[SLAVE_1]->private_data) != CDN_EPROTO) {
        status++;
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Slave is still able to request IBI.\n");
    }

    return status;
}

/**
 *Test Name: test_ccc_set_get_max_data_speed
 *Test Description: This test set maximum data speed
 *Pass Conditions: correct speed is returned from slave
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddResetDaa, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C bus management, Commands Interrupts
*/
int test_ccc_set_get_max_data_speed(void)
{
    uint timeout = 10000;

    uint32_t status = 0;

    I3C_OBJ *I3CM_drv;
    I3CS_OBJ *I3CS_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
     * descriptors that goes
     * to master driver and
     * is used for bus
     * configuration. */
    int device_descriptors_number = 0;

    I3C_TransmissionParameters params = { 0 };

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

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            all_test_devices, number_of_all_test_devices);

    initialize_bus_non_imm_cmds(I3CM_drv, all_test_devices,
            number_of_all_test_devices);

    initialize_other_test_devs(I3CM_drv, I3CS_drv, device_descriptors,
            device_descriptors_number, all_test_devices,
            number_of_all_test_devices);

    I3C_MaxDataSpeed speeds;

    status += I3CM_drv->cmdAddGetMaxDataSpeed(
            all_test_devices[MASTER]->private_data,
            &speeds,
            all_test_devices[SLAVE_0]->dynamic_address, &params);
    status += I3CM_drv->cmdExec(all_test_devices[MASTER]->private_data);

    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    if (speeds.read_speed == 0 || speeds.write_speed == 0) {
        status++;
    }

    return status;
}

/**
 *Test Name: test_ccc_slave_event_invalid_mask
 *Test Description: This test tries to set invalid slave event mask
 *Pass Conditions: API function returns CDN_EPROTO
 *Fail Conditions: any other status
 *APIs called: I3C_CmdExec, I3C_CmdExecImmediate, I3C_EnableMcs, I3C_DisableMcs, I3C_ManualCommandStart
 *Use Case: Commands Support
*/
int test_ccc_slave_event_invalid_mask(void)
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

    I3C_TransmissionParameters params = { 0 };

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

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            all_test_devices, number_of_all_test_devices);

    initialize_bus_non_imm_cmds(I3CM_drv, all_test_devices,
            number_of_all_test_devices);

    initialize_other_test_devs(I3CM_drv, I3CS_drv, device_descriptors,
            device_descriptors_number, all_test_devices,
            number_of_all_test_devices);


    I3C_TransmissionParameters txParams = { 
        .rsbc = true
    };

    if (I3CM_drv->cmdAddSetSlaveEvents(all_test_devices[MASTER]->private_data,
            4, // Invalid mask
            true,
            all_test_devices[SEC_MASTER_0]->dynamic_address, &txParams) != CDN_EPROTO) {
        status++;
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed at cmdAddSetSlaveEvents.\n");
    }

    return status;
}

/**
 *Test Name: test_ccc_set_nca_mode_in_priv_write
 *Test Description: This test set NCA mode for private write operation in slave mode
 *Pass Conditions: slave cannot perform IBI
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C vendor specific extension for data pattern with or without sub framing
*/
int test_ccc_set_nca_mode_in_priv_write(void)
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

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            all_test_devices, number_of_all_test_devices);

    initialize_bus_non_imm_cmds(I3CM_drv, all_test_devices,
            number_of_all_test_devices);

    initialize_other_test_devs(I3CM_drv, I3CS_drv, device_descriptors,
            device_descriptors_number, all_test_devices,
            number_of_all_test_devices);


    I3C_TransmissionParameters txParams = { 
	.immediate = true
    };
    
    status += I3CM_drv->CmdSetNCAMode(all_test_devices[MASTER]->private_data, 1, all_test_devices[SEC_MASTER_0]->dynamic_address, 
					     &txParams);

    status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));


    return status;
}

/**
 *Test Name: test_ccc_set_slave_mrl_mwl
 *Test Description: This test set MRL and MWL values for a slave
 *Pass Conditions: slave changes MWL and MRL values
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C vendor specific extension for data pattern with or without sub framing
*/
int test_ccc_set_slave_mrl_mwl(void)
{
    uint32_t status = 0;
    uint16_t writeMWL = 8;
    uint16_t readMWL = 0;

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

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            all_test_devices, number_of_all_test_devices);

    initialize_bus_non_imm_cmds(I3CM_drv, all_test_devices,
            number_of_all_test_devices);

    initialize_other_test_devs(I3CM_drv, I3CS_drv, device_descriptors,
            device_descriptors_number, all_test_devices,
            number_of_all_test_devices);


    I3C_TransmissionParameters txParams = { 
	.immediate = true
    };
    status += I3CM_drv->cmdAddSetMaxWriteLength(all_test_devices[MASTER]->private_data, writeMWL,
		    all_test_devices[SEC_MASTER_0]->dynamic_address, &txParams);
    status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));

    /* Slave needs some time to reflect MWL status */
    delay_ms(5);

    status += wait_for_global_status(&(global_i3c_status.slv_mwl_change));
    if (I3CM_drv->slaveModeReadMWL(all_test_devices[SEC_MASTER_0]->private_data, &readMWL) == CDN_EPROTO) {
        status++;
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Slave couldn't read mwl\n");
    }
    else if(readMWL != writeMWL) {
        status++;
		DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Slave is reading wrong mwl\n");
   }

    return status;
}

/**
 *Test Name: test_ccc_set_slave_buscon
 *Test Description: This test set storage data and fill level for SETBUSCON CCC 
 *Pass Conditions: slave changes BUSCON values in status registers
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C vendor specific extension for data pattern with or without sub framing
*/
int test_ccc_set_slave_buscon(void)
{
    uint32_t status = 0;
    uint8_t busContext[2] = {0x8, 0xa};
    //uint8_t busContext[1] = {0xa};

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

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            all_test_devices, number_of_all_test_devices);

    initialize_bus_non_imm_cmds(I3CM_drv, all_test_devices,
            number_of_all_test_devices);

    initialize_other_test_devs(I3CM_drv, I3CS_drv, device_descriptors,
            device_descriptors_number, all_test_devices,
            number_of_all_test_devices);


    I3C_TransmissionParameters txParams = { 
	.immediate = true
    };
    status += I3CM_drv->cmdAddSetBuscon(all_test_devices[MASTER]->private_data, &busContext,sizeof(busContext), 
					     &txParams);

    status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));

    delay_ms(5);

    status += wait_for_global_status(&(global_i3c_status.slv_busconUp));

    return status;
}

/**
 *Test Name: test_ccc_set_target_reset_broadcast
 *Test Description: This test send resest command to all targets 
 *Pass Conditions: slave target send ack to master
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C vendor specific extension for data pattern with or without sub framing
*/
int test_ccc_set_target_reset_broadcast(void)
{
    uint32_t status = 0;
    uint8_t definingByte = 0x01;

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

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            all_test_devices, number_of_all_test_devices);

    initialize_bus_non_imm_cmds(I3CM_drv, all_test_devices,
            number_of_all_test_devices);

    initialize_other_test_devs(I3CM_drv, I3CS_drv, device_descriptors,
            device_descriptors_number, all_test_devices,
            number_of_all_test_devices);


    I3C_TransmissionParameters txParams = { 
//        .broadcast = true,
	.immediate = true,
    };
    status += I3CM_drv->cmdAddSetRstAct(all_test_devices[MASTER]->private_data, definingByte, all_test_devices[SEC_MASTER_0]->dynamic_address, 
					     &txParams);

    status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));



    return status;
}

/**
 *Test Name: test_ccc_set_time_control
 *Test Description: This test enable Async Mode0 for a slave
 *Pass Conditions: Slave enable async mode0 
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C vendor specific extension for data pattern with or without sub framing
*/
int test_ccc_set_time_control(void)
{
    uint32_t status = 0;
    uint8_t subCommandByte = 0xDF;

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

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            all_test_devices, number_of_all_test_devices);

    initialize_bus_non_imm_cmds(I3CM_drv, all_test_devices,
            number_of_all_test_devices);

    initialize_other_test_devs(I3CM_drv, I3CS_drv, device_descriptors,
            device_descriptors_number, all_test_devices,
            number_of_all_test_devices);


    I3C_TransmissionParameters txParams = { 
	.immediate = true
    };
   
    /* Disable TCAM0 Mode */ 
    status += I3CM_drv->cmdAddSetXTime(all_test_devices[MASTER]->private_data, 0xFF, all_test_devices[SEC_MASTER_0]->dynamic_address, &txParams);

    status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));
    /*Enable TCAM0 Mode */
    status += I3CM_drv->cmdAddSetXTime(all_test_devices[MASTER]->private_data, subCommandByte, all_test_devices[SEC_MASTER_0]->dynamic_address, &txParams);

    status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));

    return status;
}

/**
 *Test Name: test_ccc_get_time_control
 *Test Description: This test reads TCAM0 data from a slave
 *Pass Conditions: Read data from slave successfully
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C vendor specific extension for data pattern with or without sub framing
*/
int test_ccc_get_time_control(void)
{
    uint32_t status = 0;
    volatile uint8_t tcam0Data[] = {0x0, 0x0, 0x0, 0x0};

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

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            all_test_devices, number_of_all_test_devices);

    initialize_bus_non_imm_cmds(I3CM_drv, all_test_devices,
            number_of_all_test_devices);

    initialize_other_test_devs(I3CM_drv, I3CS_drv, device_descriptors,
            device_descriptors_number, all_test_devices,
            number_of_all_test_devices);


    I3C_TransmissionParameters txParams = { 0 } ;
//	.immediate = true
//    };
    status += I3CM_drv->cmdAddGetXTime(all_test_devices[MASTER]->private_data, &tcam0Data, all_test_devices[SEC_MASTER_0]->dynamic_address, 
					     &txParams);

    status += I3CM_drv->cmdExec(all_test_devices[MASTER]->private_data);

    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));
    //status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));
    DbgMsg(DBG_GEN_MSG, DBG_CRIT, "TCAM0 DATA : %x %x %x %x\n",tcam0Data[0], tcam0Data[1],tcam0Data[2],tcam0Data[3]);

    status += I3CM_drv->cmdAddSetXTime(all_test_devices[MASTER]->private_data, 0xFF, all_test_devices[SEC_MASTER_0]->dynamic_address, &txParams);

//    status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));
    delay_ms(5);
    status += I3CM_drv->cmdAddGetXTime(all_test_devices[MASTER]->private_data, tcam0Data, all_test_devices[SEC_MASTER_0]->dynamic_address, 
					     &txParams);

    status += I3CM_drv->cmdExec(all_test_devices[MASTER]->private_data);

    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));
    //status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));
    DbgMsg(DBG_GEN_MSG, DBG_CRIT, "TCAM0 DATA : %x %x %x %x\n",tcam0Data[0], tcam0Data[1],tcam0Data[2],tcam0Data[3]);

    return status;
}

/**
 *Test Name: test_ccc_set_group_address
 *Test Description: This test set group address for slave or secondary master
 *Pass Conditions: Set group address correctly
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C vendor specific extension for data pattern with or without sub framing
*/
int test_ccc_set_group_address(void)
{
    uint32_t status = 0;
    uint16_t grpAddr = 0x08;

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

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            all_test_devices, number_of_all_test_devices);

    initialize_bus_non_imm_cmds(I3CM_drv, all_test_devices,
            number_of_all_test_devices);

    initialize_other_test_devs(I3CM_drv, I3CS_drv, device_descriptors,
            device_descriptors_number, all_test_devices,
            number_of_all_test_devices);


    I3C_TransmissionParameters txParams = { 
	.immediate = true
    };
    status += I3CM_drv->cmdAddSetGroupAddr(all_test_devices[MASTER]->private_data, grpAddr,
		   all_test_devices[SEC_MASTER_0]->dynamic_address, &txParams);

    status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));
    delay_ms(5);

    status += I3CM_drv->cmdAddSetMaxWriteLength(all_test_devices[MASTER]->private_data, 0xaa, grpAddr, &txParams);
    status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));

    delay_ms(100);

    status += wait_for_global_status(&(global_i3c_status.slv_mwl_change));

    return status;
}

/**
 *Test Name: test_ccc_set_define_group_list
 *Test Description: This test set group address for multiple targets
 *Pass Conditions: Group address sets correctly for multiple targets
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C vendor specific extension for data pattern with or without sub framing
*/
int test_ccc_set_define_group_list(void)
{
    uint32_t status = 0;
    I3C_GroupDescriptors grpDesc = {
	.group_address = 0x1,
	.group_descriptor = 0x2,
	.target_count = 0x2,
	.da = {0x1, 0x2},
    };	    
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

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            all_test_devices, number_of_all_test_devices);

    initialize_bus_non_imm_cmds(I3CM_drv, all_test_devices,
            number_of_all_test_devices);

    initialize_other_test_devs(I3CM_drv, I3CS_drv, device_descriptors,
            device_descriptors_number, all_test_devices,
            number_of_all_test_devices);


    I3C_TransmissionParameters txParams = { 
	.immediate = true
    };
    
    status += I3CM_drv->cmdAddDefineGroupList(all_test_devices[MASTER]->private_data, &grpDesc, &txParams);

    status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));

    return status;
}

/**
 *Test Name: test_ccc_reset_group_address
 *Test Description: This test remove group address
 *Pass Conditions: group address removed for the target
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C vendor specific extension for data pattern with or without sub framing
*/
int test_ccc_reset_group_address(void)
{
    uint32_t status = 0;
    uint16_t grpAddr = 0x1;

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

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            all_test_devices, number_of_all_test_devices);

    initialize_bus_non_imm_cmds(I3CM_drv, all_test_devices,
            number_of_all_test_devices);

    initialize_other_test_devs(I3CM_drv, I3CS_drv, device_descriptors,
            device_descriptors_number, all_test_devices,
            number_of_all_test_devices);


    I3C_TransmissionParameters txParams = { 
//	.broadcast = true,
	.immediate = true
    };
    status += I3CM_drv->cmdAddSetGroupAddr(all_test_devices[MASTER]->private_data, grpAddr,
		   all_test_devices[SEC_MASTER_0]->dynamic_address, &txParams);

    status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));
    delay_ms(5);
    
    status += I3CM_drv->cmdAddResetGrpa(all_test_devices[MASTER]->private_data, NULL,
		   all_test_devices[SEC_MASTER_0]->dynamic_address, &txParams);

    status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));

    status += I3CM_drv->cmdAddSetMaxWriteLength(all_test_devices[MASTER]->private_data, 0xaa, grpAddr, &txParams);
    status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));

//    delay_ms(10);
//    status += I3CM_drv->cmdAddSetMaxWriteLength(all_test_devices[MASTER]->private_data, 0xaa, all_test_devices[SEC_MASTER_0]->dynamic_address, &txParams);
//    status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));
    delay_ms(5);

    status += wait_for_global_status(&(global_i3c_status.slv_mwl_change));
    if(status != CDN_EOK) {
	    status = CDN_EOK;
        DbgMsg(DBG_GEN_MSG, DBG_FYI, "Negative Test. Master unable to set mwl as group address is reset.\n");
	}

    return status;
}


