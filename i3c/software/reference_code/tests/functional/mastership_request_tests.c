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
#include "mastership_request_tests.h"

int mastership_request_master_set_enec(I3C_OBJ *master_driver,
			     fn_test_i3c_device* master,
                 fn_test_i3c_device* sec_master)
{
    int status = 0;   /**< Will hold errors if any occur. */

    I3C_TransmissionParameters params = {
	.broadcast = true,
	.immediate = false
    };

    status += master_driver->cmdClearAll(master->private_data);

    status += master_driver->cmdAddSetSlaveEvents(master->private_data,
						  I3C_SLAVE_EVENT_MASTERSHIP_REQ,
						  true,
						  sec_master->dynamic_address,
						  &params);

    status += master_driver->cmdExec(master->private_data);

    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    print_status_before_return(status, __func__);

    return status;
}

int mastership_request_master_configure_sir(I3C_OBJ *master_driver,
					    fn_test_i3c_device* master,
					    fn_test_i3c_device* ibi_issuer,
					    uint16_t payload_size)
{
    int status = 0;   /**< Will hold errors if any occur. */

    I3C_IbiSirConfiguration ibi_sir_cfg[1];
    uint8_t num_sir_cfgs = 1;

    ibi_sir_cfg[0].ibiResp = I3C_IBI_RESP_ACK;
    ibi_sir_cfg[0].addr = ibi_issuer->dynamic_address;
    ibi_sir_cfg[0].ibiPayloadSize = payload_size;
    ibi_sir_cfg[0].ibiPayloadSpeedLimit = I3C_IBI_DATA_SPEED_NOT_LIMITED;
    ibi_sir_cfg[0].ibiReqDevRole = I3C_IBI_REQUESTING_DEV_ROLE_MASTER;

    status += master_driver->ibiConfigureDevices(master->private_data, ibi_sir_cfg, num_sir_cfgs);

    print_status_before_return(status, __func__);

    return status;
}


int sec_master_request_mastership(I3C_OBJ *master_driver,
				  fn_test_i3c_device* mastership_requester)
{
    int status = 0;   /**< Will hold errors if any occur. */

    status += master_driver->slaveModeMastershipReq(mastership_requester->private_data);

    print_status_before_return(status, __func__);

    return status;
}

int master_get_mastership_ack(I3C_OBJ *master_driver,
			      fn_test_i3c_device* master,
			      fn_test_i3c_device* mastership_requester)
{
    int status = 0;   /**< Will hold errors if any occur. */

    uint8_t mastership_ack;

    I3C_TransmissionParameters params = {
    	.immediate = true
    };

    status += master_driver->cmdAddGetAccMst(master->private_data,
					     &mastership_ack,
					     mastership_requester->dynamic_address,
					     &params);

    print_status_before_return(status, __func__);

    return status;
}


int master_check_op_mode_after_mastership_handover(I3C_OBJ *master_driver, fn_test_i3c_device* master)
{
    int status = 0;   /**< Will hold errors if any occur. */

    I3C_OperationMode operationMode;
    status += master_driver->checkOperationMode(master->private_data, &operationMode);
    if (operationMode != I3C_OP_MODE_SLAVE) {
    	status++;
    }

    print_status_before_return(status, __func__);

    return status;

}

int sec_master_check_op_mode_after_mastership_handover(I3C_OBJ *master_driver,
						       fn_test_i3c_device* mastership_requester)
{
    int status = 0;   /**< Will hold errors if any occur. */

    I3C_OperationMode operationMode;
    status += master_driver->checkOperationMode(mastership_requester->private_data, &operationMode);
	if (operationMode != I3C_OP_MODE_MASTER) {
		status++;
	}

	print_status_before_return(status, __func__);

    return status;
}

int send_slave_list(I3C_OBJ *master_driver,
		    fn_test_i3c_device* master)
{
    int status = 0;   /**< Will hold errors if any occur. */

    I3C_SlaveDescriptors slave_descs; /*!< Will hold slave data */

    I3C_TransmissionParameters params = { 0 };

    status += master_driver->getSlavesList(master->private_data, &slave_descs);

    status += master_driver->cmdAddDefineSlavesList(master->private_data,
						    &slave_descs,
						    &params);

    status += master_driver->cmdExec(master->private_data);

    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    return status;
}


int master_sec_master_mastership_request(I3C_OBJ *master_driver,
					 fn_test_i3c_device* master,
					 fn_test_i3c_device* mastership_requester)
{
    int status = 0;   /**< Will hold errors if any occur. */

    status += send_slave_list(master_driver, master);

    /* configure sir  */
    int payload_size = 4;
    status += mastership_request_master_configure_sir(master_driver,
						      master,
						      mastership_requester,
						      payload_size);

    status += mastership_request_master_set_enec(master_driver, master, mastership_requester);

    /* slave request masteship */
    status += sec_master_request_mastership(master_driver, mastership_requester);

    status += wait_for_global_status(&(global_i3c_status.mastership_request));

    status += master_get_mastership_ack(master_driver,
					master,
					mastership_requester);

    status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));

    status += wait_for_global_status(&(global_i3c_status.mastership_done));

    /* check op mode of master */
    status += master_check_op_mode_after_mastership_handover(master_driver,
							     master);

    /* check op mode of sec master */
    status += sec_master_check_op_mode_after_mastership_handover(master_driver, mastership_requester);

    print_status_before_return(status, __func__);

    return status;
}

/**
 *Test Name: test_mastership_request_sec_mster
 *Test Description: This test tries to request mastership as a secondary master
 *Pass Conditions: secondary master changed operation mode
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdAddDefineSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus, I3C_CmdAddGetAccMst, I3C_ConfigureSlaveInterrupts, I3C_SlaveModeConfigure, I3C_SlaveModeReqSdrRead, I3C_SlaveModeReqSdrWrite, I3C_SlaveModeReqDdrRead, I3C_SlaveModeReqDdrWrite, I3C_SlaveModeRequestHotJoin, I3C_SlaveModeMastershipReq, I3C_GetAsfInfo, I3C_CheckOperationMode
 *Use Case: I3C Bus management, Mastership request, Slave mode functions
*/
int test_mastership_request_sec_mster(void)
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

    fn_test_i3c_device* mastership_test_devices[] = { 
	&master_0_primary,
	&master_1_secondary,
	&master_2_secondary,
	&slave_0,
	&slave_1,
	&i2c_slave_fm 
    };
    
    int number_of_devices = 6;

    /**********************/
    /* Bus initialization */
    /**********************/
    setup_device_descriptors(&device_descriptors, &device_descriptors_number,
			     mastership_test_devices, number_of_devices);

    initialize_master(I3CM_drv,
		      device_descriptors,
		      device_descriptors_number,
		      mastership_test_devices,
		      number_of_devices);


    initialize_bus_non_imm_cmds(I3CM_drv,
		   all_test_devices,
		   number_of_all_test_devices);

    initialize_other_test_devs(I3CM_drv,
			       I3CS_drv,
			       device_descriptors,
			       device_descriptors_number,
			       mastership_test_devices,
			       number_of_devices);

    ////////////////////////////////////////////////////////////////////////////////////////
    // MASTERSHIP REQUEST
    ////////////////////////////////////////////////////////////////////////////////////////

    for (i = 1; i < number_of_devices; i++) {
	    if (mastership_test_devices[i]->ibi_capable == 1 &&
	        mastership_test_devices[i]->role == I3C_ROLE_SECONDAY_MASTER) {
	            status += master_sec_master_mastership_request(I3CM_drv,
				mastership_test_devices[MASTER],
				mastership_test_devices[i]);
	    }
    }

    return status;

}
