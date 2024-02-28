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
#include "ibi_tests.h"
#include "cps_ei.h"

int configure_ibi_devices(I3C_OBJ* master_driver,
			  fn_test_i3c_device* master,
			  fn_test_i3c_device* slave,
			  I3C_IbiResponse response,
			  int i3c_tx_buf_size)
{
    I3C_IbiSirConfiguration ibi_sir_cfg[2];
    uint8_t num_sir_cfgs = sizeof(ibi_sir_cfg)/sizeof(I3C_IbiSirConfiguration);

    ibi_sir_cfg[0].ibiResp = response;
    ibi_sir_cfg[0].addr = slave->dynamic_address;
    ibi_sir_cfg[0].ibiPayloadSize = i3c_tx_buf_size;
    ibi_sir_cfg[0].ibiPayloadSpeedLimit = I3C_IBI_DATA_SPEED_NOT_LIMITED;
    ibi_sir_cfg[0].ibiReqDevRole = I3C_IBI_REQUESTING_DEV_ROLE_SLAVE;
    
    ibi_sir_cfg[1].ibiResp = response;
    ibi_sir_cfg[1].addr = slave->dynamic_address;
    ibi_sir_cfg[1].ibiPayloadSize = i3c_tx_buf_size;
    ibi_sir_cfg[1].ibiPayloadSpeedLimit = I3C_IBI_DATA_SPEED_NOT_LIMITED;
    ibi_sir_cfg[1].ibiReqDevRole = I3C_IBI_REQUESTING_DEV_ROLE_SLAVE;

    return master_driver->ibiConfigureDevices(master->private_data, ibi_sir_cfg, num_sir_cfgs);
}

int modify_ibi_config(I3C_OBJ* master_driver,
		      fn_test_i3c_device* master,
		      fn_test_i3c_device* slave,
		      I3C_IbiResponse response,
		      int i3c_tx_buf_size)
{
    I3C_IbiSirConfiguration ibi_sir_cfg[1];
    uint8_t num_sir_cfgs = sizeof(ibi_sir_cfg)/sizeof(I3C_IbiSirConfiguration);

    ibi_sir_cfg[0].ibiResp = response;
    ibi_sir_cfg[0].addr = slave->dynamic_address;
    ibi_sir_cfg[0].ibiPayloadSize = i3c_tx_buf_size;
    ibi_sir_cfg[0].ibiPayloadSpeedLimit = I3C_IBI_DATA_SPEED_NOT_LIMITED;
    ibi_sir_cfg[0].ibiReqDevRole = I3C_IBI_REQUESTING_DEV_ROLE_SLAVE;

    return master_driver->ibiModifyDeviceConfig(master->private_data,
						ibi_sir_cfg,
						slave->dynamic_address);
}

int do_ibi(I3C_OBJ* master_driver,
     I3CS_OBJ* slave_driver,
     fn_test_i3c_device* master,
     fn_test_i3c_device* slave)
{
    int status = 0;
    uint8_t ibi_issuer_addr;
    int i3c_tx_buf_size = 10;

    uint8_t* i3c_tx_buf = (uint8_t*)malloc(sizeof(uint8_t) * i3c_tx_buf_size);
    uint8_t* i3c_rx_buf = (uint8_t*)malloc(sizeof(uint8_t) * i3c_tx_buf_size);
        
    generate_uint8_test_data(i3c_tx_buf, i3c_tx_buf_size);

    status += configure_ibi_devices(master_driver,
				    master,
				    slave,
				    I3C_IBI_RESP_ACK,
				    i3c_tx_buf_size);
    
    I3C_TransmissionParameters txParams = {
	.immediate = true
    };
    
    /* enable In-Band Interrupt */
    status += master_driver->cmdAddSetSlaveEvents(master->private_data,
						  I3C_SLAVE_EVENT_INTERRUPT_REQS,
						  true,
						  slave->dynamic_address,
						  &txParams);

    status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));

    /* load some payload to slave's buffer */
    //slave_driver->writeIbiPayload(slave->private_data, i3c_tx_buf, (uint8_t)i3c_tx_buf_size);
    master_driver->slaveModeWriteIbiPayload(slave->private_data, i3c_tx_buf, (uint8_t)i3c_tx_buf_size);

    /* request ibi */
    //slave_driver->requestIbi(slave->private_data);
    master_driver->slaveModeRequestIbi(slave->private_data, 0, false);
    //TODO check IBI pending register in slave

    status += wait_for_global_status(&(global_i3c_status.inband_interrupt));

    ibi_issuer_addr = master_driver->ibiGetAddressOfIssuer(master->private_data);
    if (slave->dynamic_address != ibi_issuer_addr) {
        status ++;
    }

    master_driver->ibiGetData(master->private_data, i3c_rx_buf, i3c_tx_buf_size);
    print_data_compare(i3c_tx_buf, i3c_rx_buf, i3c_tx_buf_size);
    if (0 != strncmp(i3c_tx_buf, i3c_rx_buf, i3c_tx_buf_size)) {
        status ++;
    }

    free(i3c_tx_buf);
    free(i3c_rx_buf);
    return status;
}

int do_ibi_nack(I3C_OBJ* master_driver,
		I3CS_OBJ* slave_driver,
		fn_test_i3c_device* master,
		fn_test_i3c_device* slave)
{
    int status = 0;
    uint8_t ibi_issuer_addr;
    int i3c_tx_buf_size = 10;

    uint8_t* i3c_tx_buf = (uint8_t*)malloc(sizeof(uint8_t) * i3c_tx_buf_size);

    generate_uint8_test_data(i3c_tx_buf, i3c_tx_buf_size);

    status += configure_ibi_devices(master_driver,
				    master,
				    slave,
				    I3C_IBI_RESP_ACK,
				    i3c_tx_buf_size);

    status += modify_ibi_config(master_driver,
				master,
				slave,
				I3C_IBI_RESP_NACK,
				i3c_tx_buf_size);

    /* load some payload to slave's buffer */
    //slave_driver->writeIbiPayload(slave->private_data, i3c_tx_buf, (uint8_t)i3c_tx_buf_size);
    master_driver->slaveModeWriteIbiPayload(slave->private_data, i3c_tx_buf, (uint8_t)i3c_tx_buf_size);

    /* request ibi */
    //slave_driver->requestIbi(slave->private_data);
    master_driver->slaveModeRequestIbi(slave->private_data, 0 ,false);

    if (wait_for_global_status(&(global_i3c_status.inband_interrupt)) == 0) {
	status++;
    }

    free(i3c_tx_buf);

    return status;
}

/**
 *Test Name: test_ibi
 *Test Description: This test performs In-Band Interrupt
 *Pass Conditions: ibi is acked
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus, I3C_IbiConfigureDevices, I3C_IbiModifyDeviceConfig, I3C_IbiGetAddressOfIssuer, I3C_IbiGetData
 *Use Case: I3C Bus management, Interrupts, In-Band Interrupts
*/
int test_ibi(void)
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

    i3c_IrqInit();

    I3CM_drv = I3C_GetInstance();
    I3CS_drv = I3CS_GetInstance();

    cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "clk freq: %d\n", csp_get_clock_frequency());

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
                status += do_ibi(I3CM_drv,
                I3CM_drv,
                all_test_devices[MASTER],
                all_test_devices[i]);
        }
    }

    return status;
}

/**
 *Test Name: test_ibi_nack
 *Test Description: This test performs In-Band Interrupt when IBI is disabled
 *Pass Conditions: ibi is nacked
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus, I3C_IbiConfigureDevices, I3C_IbiModifyDeviceConfig, I3C_IbiGetAddressOfIssuer, I3C_IbiGetData
 *Use Case: In-Band Interrupts
*/
int test_ibi_nack(void)
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

    i3c_IrqInit();

    I3CM_drv = I3C_GetInstance();
    I3CS_drv = I3CS_GetInstance();

    cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "clk freq: %d\n", csp_get_clock_frequency());

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
	    status += do_ibi_nack(I3CM_drv,
				  I3CM_drv,
				  all_test_devices[MASTER],
				  all_test_devices[i]);
	}
    }

    return status;
}

/**
 *Test Name: test_ibi_address_of_issuer
 *Test Description: This test injects error into SIR MAP registers
 *Pass Conditions: correct addresses are returned
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus, I3C_IbiConfigureDevices, I3C_IbiModifyDeviceConfig, I3C_IbiGetAddressOfIssuer, I3C_IbiGetData
 *Use Case: In-Band Interrupts
*/
int test_ibi_address_of_issuer(void)
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

    i3c_IrqInit();

    I3CM_drv = I3C_GetInstance();

    cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "clk freq: %d\n", csp_get_clock_frequency());

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

    I3C_PrivData *pd = all_test_devices[MASTER]->private_data;
    uint8_t ibi_issuer_address[2] = { 0x7A, 0x7B };

    uint32_t reg_val = 0U;
    reg_val = CPS_FLD_WRITE(MIPI__SIR_MAP0, DEVID0_DA, reg_val, ibi_issuer_address[0]);
    reg_val = CPS_FLD_WRITE(MIPI__SIR_MAP0, DEVID1_DA, reg_val, ibi_issuer_address[1]);

    if(CPSEI_Enable() != 0U) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Cannot initialize CPSEI.\n");
    }

    /* Inject values of SIR MAP registers */
    CPSEI_AddReadError(&(pd->regs_base->SIR_MAP0),
                reg_val, 0, 0, 2);
    CPSEI_SkipHwRead(&(pd->regs_base->SIR_MAP0), true);

    CPSEI_AddReadError(&(pd->regs_base->SIR_MAP1),
                reg_val, 0, 0, 2);
    CPSEI_SkipHwRead(&(pd->regs_base->SIR_MAP1), true);

    CPSEI_AddReadError(&(pd->regs_base->SIR_MAP2),
                reg_val, 0, 0, 2);
    CPSEI_SkipHwRead(&(pd->regs_base->SIR_MAP2), true);

    CPSEI_AddReadError(&(pd->regs_base->SIR_MAP3),
                reg_val, 0, 0, 2);
    CPSEI_SkipHwRead(&(pd->regs_base->SIR_MAP3), true);

    CPSEI_AddReadError(&(pd->regs_base->SIR_MAP4),
                reg_val, 0, 0, 2);
    CPSEI_SkipHwRead(&(pd->regs_base->SIR_MAP4), true);

    CPSEI_AddReadError(&(pd->regs_base->SIR_MAP5),
                reg_val, 0, 0, 2);
    CPSEI_SkipHwRead(&(pd->regs_base->SIR_MAP5), true);

    uint8_t number_of_ibi_capable_devices = 12;
    uint8_t address;
    for (i = 0; i<number_of_ibi_capable_devices; ++i) {
        pd->ibi.slv_id = i;
        address = I3CM_drv->ibiGetAddressOfIssuer(pd);
        if (address != ibi_issuer_address[i % 2]) {
            status++;
            DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Address mismatch. %d. Expected: 0x%.2X, Actual: 0x%.2X.\n",
                    i, ibi_issuer_address[i % 2], address);
        }
    }
    
    pd->ibi.slv_id = 13;
    address = I3CM_drv->ibiGetAddressOfIssuer(pd);
    if (address != 0U) {
	status++;
    }

    return status;
}

/**
 *Test Name: test_ibi_slot_overflow
 *Test Description: This test tries to overflow IBI slots
 *Pass Conditions: API function returns CDN_EINVAL
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus, I3C_IbiConfigureDevices, I3C_IbiModifyDeviceConfig, I3C_IbiGetAddressOfIssuer, I3C_IbiGetData
 *Use Case: In-Band Interrupts
*/
int test_ibi_slot_overflow(void)
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

    i3c_IrqInit();

    I3CM_drv = I3C_GetInstance();
    I3CS_drv = I3CS_GetInstance();

    cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "clk freq: %d\n", csp_get_clock_frequency());

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

    I3C_IbiSirConfiguration ibi_sir_cfg[3];
    uint8_t num_sir_cfgs = sizeof(ibi_sir_cfg)/sizeof(I3C_IbiSirConfiguration);
    
    ibi_sir_cfg[0].ibiResp = I3C_IBI_RESP_ACK;
    ibi_sir_cfg[0].addr = all_test_devices[SLAVE_0]->dynamic_address;
    ibi_sir_cfg[0].ibiPayloadSize = 10;
    ibi_sir_cfg[0].ibiPayloadSpeedLimit = I3C_IBI_DATA_SPEED_NOT_LIMITED;
    ibi_sir_cfg[0].ibiReqDevRole = I3C_IBI_REQUESTING_DEV_ROLE_SLAVE;

    // Try to configure more IBI devices than HW allows
    if(I3CM_drv->ibiConfigureDevices(all_test_devices[MASTER]->private_data,
				     &ibi_sir_cfg,
				     num_sir_cfgs) != CDN_EINVAL) {
	status++;
    }

    return status;
}

int do_ibi_tcam0(I3C_OBJ* master_driver,
     I3CS_OBJ* slave_driver,
     fn_test_i3c_device* master,
     fn_test_i3c_device* slave)
{
    int status = 0;
    uint8_t ibi_issuer_addr;
    uint8_t ibi_tcam0_event = 01;
    int i3c_rx_buf_size = 9;
    int i;

    uint8_t* i3c_rx_buf = (uint8_t*)malloc(sizeof(uint8_t) * i3c_rx_buf_size);
        
    status += configure_ibi_devices(master_driver,
				    master,
				    slave,
				    I3C_IBI_RESP_ACK,
				    i3c_rx_buf_size);
    
    I3C_TransmissionParameters txParams = {
	.immediate = true
    };

    status += master_driver->enableTc(master->private_data);
    /* enable In-Band Interrupt */
    status += master_driver->cmdAddSetSlaveEvents(master->private_data,
						  I3C_SLAVE_EVENT_INTERRUPT_REQS,
						  true,
						  slave->dynamic_address,
						  &txParams);

    status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));

    /* request ibi */
    master_driver->slaveModeRequestIbi(slave->private_data, ibi_tcam0_event, true);

    status += wait_for_global_status(&(global_i3c_status.inband_interrupt));

    ibi_issuer_addr = master_driver->ibiGetAddressOfIssuer(master->private_data);
    if (slave->dynamic_address != ibi_issuer_addr) {
        status ++;
    }

    master_driver->ibiGetData(master->private_data, i3c_rx_buf, i3c_rx_buf_size);
    for(i=0; i < i3c_rx_buf_size; i++) {
       DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Byte %d:\t Data(0x%.2X),\n", i, i3c_rx_buf[i]);
    }

    free(i3c_rx_buf);
    return status;
}



/**
 *Test Name: test_ibi_tcam0_event
 *Test Description: This test tries to overflow IBI slots
 *Pass Conditions: API function returns CDN_EINVAL
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus, I3C_IbiConfigureDevices, I3C_IbiModifyDeviceConfig, I3C_IbiGetAddressOfIssuer, I3C_IbiGetData
 *Use Case: In-Band Interrupts
*/
int test_ibi_tcam0_event(void)
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

    i3c_IrqInit();

    I3CM_drv = I3C_GetInstance();
    I3CS_drv = I3CS_GetInstance();

    cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "clk freq: %d\n", csp_get_clock_frequency());

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
                status += do_ibi_tcam0(I3CM_drv,
                I3CM_drv,
                all_test_devices[MASTER],
                all_test_devices[i]);
        }
    }

    return status;
}
