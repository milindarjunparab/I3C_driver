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
#include "ddr_tests.h"

int ddr_master_write(I3C_OBJ* master_driver,
         void* master_private_data,
         uint16_t receiver_dynamic_address,
         uint16_t* tx_data,
         size_t tx_data_size)
{
    int status = 0;			/**< Will hold a sum of errors in case any occur. */

    I3C_ThresholdConfig thresholdConfig = {
	.txFifoThreshold = 32,
	.rxFifoThreshold = 32,
	.cmdrFifoThreshold = 2,
	.ibirFifoThreshold = 1
    };
    
    status += master_driver->disableCore(master_private_data);
    status += master_driver->configureThresholds(master_private_data,
				       &thresholdConfig);
  
    I3C_PayloadData payload_data = {
        .sdr_payload = NULL,
        .ddr_payload = tx_data,
        .payloadSize = tx_data_size
    };

    I3C_TransmissionParameters params = { 
        .rsbc = true
    };

    status += master_driver->setBusMode(master_private_data,
          I3C_BUS_MODE_MIXED_FAST);

    status += master_driver->cmdClearAll(master_private_data);

    status += master_driver->cmdAddEnterHdrMode(master_private_data,
                  I3C_HDR_MODE_DDR,
                  &params);

    status += master_driver->cmdAddDdrWrite(master_private_data,
              receiver_dynamic_address,
              0,
              I3C_HDR_MODE_DDR,
              &payload_data);

    status += master_driver->cmdExec(master_private_data);

    print_status_before_return(status, __func__);

    return status;
}

int ddr_master_read(I3C_OBJ* master_driver,
        void* master_private_data,
        uint8_t transmitter_dynamic_address,
        uint16_t* rx_data,
        size_t rx_data_size)
{
    int status = 0;			/**< Will hold errors if any occur. */

    I3C_ThresholdConfig thresholdConfig = {
	.txFifoThreshold = 32,
	.rxFifoThreshold = 32,
	.cmdrFifoThreshold = 2,
	.ibirFifoThreshold = 1
    };
    
    status += master_driver->disableCore(master_private_data);
    status += master_driver->configureThresholds(master_private_data,
				       &thresholdConfig);
  
    I3C_PayloadData payload_data = {
        .sdr_payload = NULL,
        .ddr_payload = rx_data,
        .payloadSize = rx_data_size
    };

    I3C_TransmissionParameters params = { 0 };

    status += master_driver->setBusMode(master_private_data,
          I3C_BUS_MODE_MIXED_FAST);

    status += master_driver->cmdClearAll(master_private_data);

    status += master_driver->cmdAddEnterHdrMode(master_private_data,
            I3C_HDR_MODE_DDR,
            &params);

    status += master_driver->cmdAddDdrRead(master_private_data,
             transmitter_dynamic_address,
             0x80,
             0,
             &payload_data);

    status += master_driver->cmdExec(master_private_data);

    print_status_before_return(status, __func__);

    return status;
}


int ddr_secondary_master_write(I3C_OBJ *master_driver,
             void* secondary_master_private_data,
             uint16_t* tx_data,
             size_t tx_data_size)
{
    int status = 0;			/**< Will hold errors if any occur. */

    status += master_driver->slaveModeReqDdrWrite(secondary_master_private_data, tx_data, tx_data_size);

    print_status_before_return(status, __func__);

    return status;
}


int ddr_secondary_master_read(I3C_OBJ *master_driver,
            void* secondary_master_private_data,
            uint16_t* rx_data,
            size_t rx_data_size)
{
    int status = 0;			/**< Will hold errors if any occur. */

    status += master_driver->slaveModeReqDdrRead(secondary_master_private_data, rx_data, rx_data_size);

    print_status_before_return(status, __func__);

    return status;
}

int ddr_slave_write(I3CS_OBJ *slave_driver,
        I3CS_PrivData* slave_private_data,
        uint16_t* tx_data,
        size_t tx_data_size)
{
    int status = 0;			/**< Will hold errors if any occur. */

    status += slave_driver->reqDdrWrite(slave_private_data, tx_data, tx_data_size);

    print_status_before_return(status, __func__);

    return status;
}


int ddr_slave_read(I3CS_OBJ *slave_driver,
       I3CS_PrivData* slave_private_data,
       uint16_t* rx_data,
       size_t rx_data_size)
{
    int status = 0;			/**< Will hold errors if any occur. */

    status += slave_driver->reqDdrRead(slave_private_data, rx_data, rx_data_size);

    print_status_before_return(status, __func__);

    return status;
}

int ddr_send_to_secondary_master(I3C_OBJ *master_driver,
         fn_test_i3c_device* master,
         fn_test_i3c_device* secondary_master,
         uint16_t* tx_data,
         size_t data_size)
{
    int status = 0;   /**< Will hold errors if any occur. */
    uint16_t* rx_data; /**< Buffer for data received by secondary slave. */

    rx_data = (uint16_t*)malloc(data_size * sizeof(uint16_t));

    if (check_if_i3c_device_is_of_role(master, I3C_ROLE_MASTER)) {
  cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "%s, i3c device passed as master is not master\n", __func__);
    }

    status += ddr_master_write(master_driver,
             master->private_data,
             secondary_master->dynamic_address,
             tx_data,
             data_size);

    /* waiting for all transfers to be finished*/
    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    status += ddr_secondary_master_read(master_driver,
          secondary_master->private_data,
          rx_data,
          data_size);

    if (memcmp(tx_data, rx_data, data_size * sizeof(uint16_t))) {
      status++;
      print_data_compare(tx_data, rx_data, data_size * 2);
    }

    free(rx_data);

    print_status_before_return(status, __func__);

    return status;

}

int ddr_send_from_secondary_master(I3C_OBJ *master_driver,
           fn_test_i3c_device* master,
           fn_test_i3c_device* secondary_master,
           uint16_t* tx_data,
           size_t data_size)
{
    int status = 0;   /**< Will hold errors if any occur. */
    uint16_t* rx_data; /**< Buffer for data received by master. */

    rx_data = (uint16_t*)malloc(data_size * sizeof(uint16_t));

    if (check_if_i3c_device_is_of_role(master, I3C_ROLE_MASTER)) {
  cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "%s, i3c device passed as master is not master\n", __func__);
    }

    status += ddr_secondary_master_write(master_driver,
           secondary_master->private_data,
           tx_data,
           data_size);

    status += ddr_master_read(master_driver,
            master->private_data,
            secondary_master->dynamic_address,
            rx_data,
            data_size);

    /* waiting for all transfers to be finished*/
    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    if (memcmp(tx_data, rx_data, data_size * sizeof(uint16_t))) {
  status++;
  print_data_compare(tx_data, rx_data, data_size * 2);
    }

    free(rx_data);

    print_status_before_return(status, __func__);

    return status;
}


int ddr_send_to_slave(I3C_OBJ *master_driver,
          I3CS_OBJ* slave_driver,
          fn_test_i3c_device* master,
          fn_test_i3c_device* slave,
          uint16_t* tx_data,
          size_t data_size)
{
    int status = 0;   /**< Will hold errors if any occur. */
    uint16_t* rx_data; /**< Buffer for data received by secondary slave. */

    rx_data = (uint16_t*)malloc(data_size * sizeof(uint16_t));

    if (check_if_i3c_device_is_of_role(master, I3C_ROLE_MASTER)) {
  cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "%s, i3c device passed as master is not master\n", __func__);
    }

    status += ddr_master_write(master_driver,
             master->private_data,
             slave->dynamic_address,
             tx_data,
             data_size);

    /* waiting for all transfers to be finished*/
    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    status += ddr_slave_read(slave_driver,
           slave->private_data,
           rx_data,
           data_size);

    if (memcmp(tx_data, rx_data, data_size * sizeof(uint16_t))) {
      status++;
    }

    free(rx_data);

    print_status_before_return(status, __func__);

    return status;

}

int ddr_send_from_slave(I3C_OBJ *master_driver,
      I3CS_OBJ* slave_driver,
      fn_test_i3c_device* master,
      fn_test_i3c_device* slave,
      uint16_t* tx_data,
      size_t data_size)
{
    int status = 0;   /**< Will hold errors if any occur. */
    uint16_t* rx_data; /**< Buffer for data received by master. */

    rx_data = (uint16_t*)malloc(data_size * sizeof(uint16_t));

    if (check_if_i3c_device_is_of_role(master, I3C_ROLE_MASTER)) {
  cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "%s, i3c device passed as master is not master\n", __func__);
    }

    status += ddr_slave_write(slave_driver,
            slave->private_data,
            tx_data,
            data_size);

    status += ddr_master_read(master_driver,
            master->private_data,
            slave->dynamic_address,
            rx_data,
            data_size);

    /* waiting for all transfers to be finished*/
    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    if (memcmp(tx_data, rx_data, data_size * sizeof(uint16_t))) {
  status++;
    }

    free(rx_data);

    print_status_before_return(status, __func__);

    return status;
}



/**
 *Test Name: test_ddr_master_sec_master_tx
 *Test Description: This test transfers data from master to secondary master in HDR mode
 *Pass Conditions: data transfer is success
 *Fail Conditions: data mismatch
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddDdrWrite, I3C_CmdAddDdrRead, I3C_CmdAddEnterActivityState, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdAddEnterHdrMode, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C Bus management, Interrupts, DDR mode
*/
int test_ddr_master_sec_master_tx(void)
{
    uint32_t status = 0;
    int i = 0;
    I3C_OBJ *I3CM_drv;
    I3CS_OBJ *I3CS_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
                 * descriptors that goes
                 * to master driver and
                 * is used for bus
                 * configuration. */
    int device_descriptors_number = 0;

    int ddr_tx_buffer_size = 3; /**< Number of 16-bit words
         * for DDR transfer. */
    uint16_t* ddr_tx_buffer = (uint16_t*)malloc(sizeof(uint16_t) * ddr_tx_buffer_size);

    generate_uint16_test_data(ddr_tx_buffer, ddr_tx_buffer_size);

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

    status = 0;

    for (i = 1; i < number_of_all_test_devices; i++) {
        if (all_test_devices[i]->hdr_capable == 1 &&
            all_test_devices[i]->role == I3C_ROLE_SECONDAY_MASTER) {
            status += ddr_send_to_secondary_master(I3CM_drv,
                     all_test_devices[MASTER],
                     all_test_devices[i],
                     ddr_tx_buffer,
                     ddr_tx_buffer_size);
        }
    }

    free(ddr_tx_buffer);

    return status;
}

/**
 *Test Name: test_ddr_master_sec_master_tx_threshold
 *Test Description: This test transfers data from master to secondary master in HDR mode
 *Pass Conditions: data transfer is success
 *Fail Conditions: data mismatch
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddDdrWrite, I3C_CmdAddDdrRead, I3C_CmdAddEnterActivityState, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdAddEnterHdrMode, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C Bus management, Interrupts, DDR mode
*/
int test_ddr_master_sec_master_tx_threshold(void)
{
    uint32_t status = 0;
    int i = 0;
    I3C_OBJ *I3CM_drv;
    I3CS_OBJ *I3CS_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
                 * descriptors that goes
                 * to master driver and
                 * is used for bus
                 * configuration. */
    int device_descriptors_number = 0;

    int ddr_tx_buffer_size = 40; /**< Number of 16-bit words
          * for DDR transfer. */
    uint16_t* ddr_tx_buffer = (uint16_t*)malloc(sizeof(uint16_t) * ddr_tx_buffer_size);

    generate_uint16_test_data(ddr_tx_buffer, ddr_tx_buffer_size);

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

    status = 0;

    for (i = 1; i < number_of_all_test_devices; i++) {
        if (all_test_devices[i]->hdr_capable == 1 &&
            all_test_devices[i]->role == I3C_ROLE_SECONDAY_MASTER) {
            status += ddr_send_to_secondary_master(I3CM_drv,
                      all_test_devices[0],
                      all_test_devices[i],
                      ddr_tx_buffer,
                     ddr_tx_buffer_size);
        }
    }

    free(ddr_tx_buffer);

    return status;
}

// parasoft-begin-suppress CDD-DUPM-2 "Avoid function duplication, DRV-4265"

/**
 *Test Name: test_ddr_master_sec_master_rx
 *Test Description: This test transfers data from secondary master to master in HDR mode
 *Pass Conditions: data transfer is success
 *Fail Conditions: data mismatch
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddDdrWrite, I3C_CmdAddDdrRead, I3C_CmdAddEnterActivityState, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdAddEnterHdrMode, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C Bus management, Interrupts, DDR mode
*/
int test_ddr_master_sec_master_rx(void)
{
    uint32_t status = 0;
    int i = 0;
    I3C_OBJ *I3CM_drv;
    I3CS_OBJ *I3CS_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
                 * descriptors that goes
                 * to master driver and
                 * is used for bus
                 * configuration. */
    int device_descriptors_number = 0;

    int ddr_tx_buffer_size = 7;	/**< Number of 16-bit words for
         * DDR  transfer. */
    uint16_t* ddr_tx_buffer = (uint16_t*)malloc(sizeof(uint16_t) * ddr_tx_buffer_size);

    generate_uint16_test_data(ddr_tx_buffer, ddr_tx_buffer_size);

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

    status = 0;

    for (i = 1; i < number_of_all_test_devices; i++) {
        if (all_test_devices[i]->hdr_capable == 1 &&
            all_test_devices[i]->role == I3C_ROLE_SECONDAY_MASTER) {
            status += ddr_send_from_secondary_master(I3CM_drv,
                     all_test_devices[MASTER],
                     all_test_devices[i],
                     ddr_tx_buffer,
                     ddr_tx_buffer_size);
        }
    }

    free(ddr_tx_buffer);

    return status;
}

/**
 *Test Name: test_ddr_master_sec_master_rx_threshold
 *Test Description: This test transfers data from secondary master to master using threshold mechanism in HDR mode
 *Pass Conditions: data transfer is success
 *Fail Conditions: data mismatch
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddDdrWrite, I3C_CmdAddDdrRead, I3C_CmdAddEnterActivityState, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdAddEnterHdrMode, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C Bus management, Interrupts, DDR mode
*/
int test_ddr_master_sec_master_rx_threshold(void)
{
    uint32_t status = 0;
    int i = 0;
    I3C_OBJ *I3CM_drv;
    I3CS_OBJ *I3CS_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
                 * descriptors that goes
                 * to master driver and
                 * is used for bus
                 * configuration. */
    int device_descriptors_number = 0;

    int ddr_tx_buffer_size = 7; /**< Number of 16-bit words
          * for DDR transfer. */
    uint16_t* ddr_tx_buffer = (uint16_t*)malloc(sizeof(uint16_t) * ddr_tx_buffer_size);

    generate_uint16_test_data(ddr_tx_buffer, ddr_tx_buffer_size);

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

    status = 0;
    for (i = 1; i < number_of_all_test_devices; i++) {
        if (all_test_devices[i]->hdr_capable == 1 &&
            all_test_devices[i]->role == I3C_ROLE_SECONDAY_MASTER) {
            status += ddr_send_from_secondary_master(I3CM_drv,
                     all_test_devices[MASTER],
                     all_test_devices[i],
                     ddr_tx_buffer,
                     ddr_tx_buffer_size);
        }
    }

    free(ddr_tx_buffer);

    return status;
}
// parasoft-end-suppress CDD-DUPM-2 "Avoid function duplication, DRV-4265"

/**
 *Test Name: test_ddr_master_slave_tx
 *Test Description: This test transfers data to slave in HDR mode
 *Pass Conditions: data transfer is success
 *Fail Conditions: data mismatch
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddDdrWrite, I3C_CmdAddDdrRead, I3C_CmdAddEnterActivityState, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdAddEnterHdrMode, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C Bus management, Interrupts, DDR mode
*/
int test_ddr_master_slave_tx(void)
{
    uint32_t status = 0;
    int i = 0;
    I3C_OBJ *I3CM_drv;
    I3CS_OBJ *I3CS_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
                 * descriptors that goes
                 * to master driver and
                 * is used for bus
                 * configuration. */
    int device_descriptors_number = 0;

    int ddr_tx_buffer_size = 3; /**< Number of 16-bit words
         * for DDR transfer. */
    uint16_t* ddr_tx_buffer = (uint16_t*)malloc(sizeof(uint16_t) * ddr_tx_buffer_size);

    generate_uint16_test_data(ddr_tx_buffer, ddr_tx_buffer_size);

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

    status = 0;
    for (i = 1; i < number_of_all_test_devices; i++) {
        if (all_test_devices[i]->hdr_capable == 1 &&
            all_test_devices[i]->role == I3C_ROLE_SLAVE) {
            status += ddr_send_to_slave(I3CM_drv,
              I3CS_drv,
              all_test_devices[MASTER],
              all_test_devices[i],
              ddr_tx_buffer,
              ddr_tx_buffer_size);
        }
    }

    free(ddr_tx_buffer);

    return status;
}

/**
 *Test Name: test_ddr_master_slave_rx
 *Test Description: This test transfers data from slave in HDR mode
 *Pass Conditions: data transfer is success
 *Fail Conditions: data mismatch
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddDdrWrite, I3C_CmdAddDdrRead, I3C_CmdAddEnterActivityState, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdAddEnterHdrMode, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C Bus management, Interrupts, DDR mode
*/
int test_ddr_master_slave_rx(void)
{
    uint32_t status = 0;
    int i = 0;
    I3C_OBJ *I3CM_drv;
    I3CS_OBJ *I3CS_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
                 * descriptors that goes
                 * to master driver and
                 * is used for bus
                 * configuration. */
    int device_descriptors_number = 0;

    int ddr_tx_buffer_size = 16;	/**< Number of 16-bit words for
         * DDR  transfer. */
    uint16_t* ddr_tx_buffer = (uint16_t*)malloc(sizeof(uint16_t) * ddr_tx_buffer_size);

    generate_uint16_test_data(ddr_tx_buffer, ddr_tx_buffer_size);

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

    status = 0;
    for (i = 1; i < number_of_all_test_devices; i++) {
        if (all_test_devices[i]->hdr_capable == 1 &&
            all_test_devices[i]->role == I3C_ROLE_SLAVE) {
            status += ddr_send_from_slave(I3CM_drv,
                I3CS_drv,
                all_test_devices[MASTER],
                all_test_devices[i],
                ddr_tx_buffer,
                ddr_tx_buffer_size);
        }
    }

    free(ddr_tx_buffer);

    return status;
}

/**
 *Test Name: test_sec_master_tx_no_data
 *Test Description: This test tries to transfer data when payload is empty
 *Pass Conditions: data transfer is success
 *Fail Conditions: data mismatch
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddDdrWrite, I3C_CmdAddDdrRead, I3C_CmdAddEnterActivityState, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdAddEnterHdrMode, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C Bus management, Interrupts, DDR mode
*/
int test_sec_master_tx_no_data(void)
{
    uint32_t status = 0;
    int i = 0;
    I3C_OBJ *I3CM_drv;
    I3CS_OBJ *I3CS_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
                 * descriptors that goes
                 * to master driver and
                 * is used for bus
                 * configuration. */
    int device_descriptors_number = 0;

    int ddr_tx_buffer_size = 3; /**< Number of 16-bit words
         * for DDR transfer. */
    uint16_t* ddr_tx_buffer = (uint16_t*)malloc(sizeof(uint16_t) * ddr_tx_buffer_size);

    generate_uint16_test_data(ddr_tx_buffer, ddr_tx_buffer_size);

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


    initialize_other_test_devs(I3CM_drv,
             I3CS_drv,
             device_descriptors,
             device_descriptors_number,
             all_test_devices,
             number_of_all_test_devices);

    if(ddr_secondary_master_read(I3CM_drv,
                all_test_devices[SEC_MASTER_1]->private_data,
                ddr_tx_buffer,
                ddr_tx_buffer_size) != CDN_ENOENT) {
	status++;
    }

    free(ddr_tx_buffer);

    return status;
}

/**
 *Test Name: test_sec_master_rx_without_daa
 *Test Description: This test tries to transfer data without Dynamic Address
 *Pass Conditions: API function returns CDN_ENOTSUP/otherwise
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddDdrWrite, I3C_CmdAddDdrRead, I3C_CmdAddEnterActivityState, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdAddEnterHdrMode, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: DDR mode
*/
int test_sec_master_rx_without_daa(void)
{
    uint32_t status = 0;
    int i = 0;
    I3C_OBJ *I3CM_drv;
    I3CS_OBJ *I3CS_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
                 * descriptors that goes
                 * to master driver and
                 * is used for bus
                 * configuration. */
    int device_descriptors_number = 0;

    int ddr_tx_buffer_size = 3; /**< Number of 16-bit words for
         * DDR  transfer. */
    uint16_t* ddr_tx_buffer = (uint16_t*)malloc(sizeof(uint16_t) * ddr_tx_buffer_size);

    generate_uint16_test_data(ddr_tx_buffer, ddr_tx_buffer_size);

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

    initialize_other_test_devs(I3CM_drv,
             I3CS_drv,
             device_descriptors,
             device_descriptors_number,
             all_test_devices,
             number_of_all_test_devices);

    if (ddr_secondary_master_write(I3CM_drv,
                all_test_devices[SEC_MASTER_1]->private_data,
                ddr_tx_buffer,
                ddr_tx_buffer_size) != CDN_ENOTSUP) {
	status++;
    }

    free(ddr_tx_buffer);

    return status;
}
