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
#include "hot_join_tests.h"

int hot_join_master_set_enec(I3C_OBJ *master_driver,
			     fn_test_i3c_device* master)
{
    int status = 0;   /**< Will hold errors if any occur. */

    I3C_TransmissionParameters params = {
	.broadcast = true,
	.immediate = true
    };

    status += master_driver->cmdClearAll(master->private_data);

    status += master_driver->cmdAddSetSlaveEvents(master->private_data,
						  I3C_SLAVE_EVENT_HOT_JOIN,
						  true,
						  0,
						  &params);

    status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));
    
    print_status_before_return(status, __func__);

    return status;
}


int hot_join_master_config_response(I3C_OBJ *master_driver,
				    fn_test_i3c_device* master)
{
    int status = 0;   /**< Will hold errors if any occur. */

    status += master_driver->hjConfigureResponse(master->private_data,
						 I3C_HJ_RESP_ACK,
						 I3C_HJ_REQ_SLAVE_NOT_DISABLE);

    print_status_before_return(status, __func__);

    return status;
}

int secondary_master_request_hot_join(I3C_OBJ *master_driver,
				      fn_test_i3c_device* secondary_master)
{
    int status = 0;   /**< Will hold errors if any occur. */

    status += master_driver->slaveModeRequestHotJoin(secondary_master->private_data);

    print_status_before_return(status, __func__);

    return status;
}

int slave_request_hot_join(I3CS_OBJ *slave_driver,
			   fn_test_i3c_device* slave)
{
    int status = 0;   /**< Will hold errors if any occur. */

    status += slave_driver->requestHotJoin(slave->private_data);

    print_status_before_return(status, __func__);

    return status;
}

int master_wait_for_hot_join(I3C_OBJ *master_driver,
			     fn_test_i3c_device* master)
{
    int status = 0;   /**< Will hold errors if any occur. */
    
    status += wait_for_global_status(&(global_i3c_status.hot_join));
    global_i3c_status.daa_complete = false;
    status += master_driver->enableCore(master->private_data);
    status += wait_for_global_status(&(global_i3c_status.daa_complete));

    print_status_before_return(status, __func__);

    return status;
}

int master_validate_joined_device(I3C_OBJ *master_driver,
				  fn_test_i3c_device* master,
				  uint16_t exp_device_num)
{
    int status = 0;
    uint16_t device_num = 0U;

    status += master_driver->getNewDevices(master->private_data,
						 &device_num);

    if ((device_num == 0U) || (device_num != exp_device_num)) {
	DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Expected device: %.4x, Actual device: %.4x\n",
	       exp_device_num, device_num);
	status++;
    }
    
    print_status_before_return(status, __func__);

    return status;
}

int master_sec_master_hot_join_requrest(I3C_OBJ *master_driver,
					fn_test_i3c_device* master,
					fn_test_i3c_device* ibi_requestster)
{
    int status = 0;   /**< Will hold errors if any occur. */
    
    /* reset second device so it would loose it's dynamic address */
    reset_devices(RST_DEV2);
    delay_ms(5);

    /* 2nd device has been enumerated in this test before, retaining
       register corresponding to this device has to be cleared so it
       is possible to assign the same dynamic address once again to
       this device */
    status += master_driver->clearRrOfDevice(master->private_data, SEC_MASTER_1);

    /* enec here */
    status += hot_join_master_set_enec(master_driver,
				       master);

    /* configure master's response */

    status += hot_join_master_config_response(master_driver,
					      master);

    /* slave request hot join */
    status += secondary_master_request_hot_join(master_driver,
						ibi_requestster);

    /* master waint for hot join */
    status += master_wait_for_hot_join(master_driver,
				       master);
    
    
    /* checks if correct device joined the bus */
    status += master_validate_joined_device(master_driver,
					    master,
					    SEC_MASTER_1);
    
    print_status_before_return(status, __func__);

    return status;
}

int master_slave_hot_join_requrest(I3C_OBJ *master_driver,
				   I3CS_OBJ *slave_driver,
				   fn_test_i3c_device* master,
				   fn_test_i3c_device* ibi_requestster)
{
  int status = 0;   /**< Will hold errors if any occur. */
    reset_devices(RST_DEV4);
    delay_ms(5);

    status += master_driver->clearRrOfDevice(master->private_data, SLAVE_1);
    
    /* enec here */
    status += hot_join_master_set_enec(master_driver,
				       master);

    /* configure master's response */
    status += hot_join_master_config_response(master_driver,
					      master);

    /* slave request hot join */
    status += slave_request_hot_join(slave_driver,
				     ibi_requestster);

    /* master waint for hot join */
    status += master_wait_for_hot_join(master_driver,
				       master);
    
    
    /* checks if correct device joined the bus */
    status += master_validate_joined_device(master_driver,
					    master,
					    SLAVE_1);
    
    print_status_before_return(status, __func__);

    return status;
}

/**
 *Test Name: test_hot_join_sec_mster
 *Test Description: This test adds new secondary master device to the bus
 *Pass Conditions: appropriate device joined the bus
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus, I3C_HjConfigureResponse
 *Use Case: I3C Bus management, Hotjoin
*/
int test_hot_join_sec_mster(void)
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

    status += master_sec_master_hot_join_requrest(I3CM_drv,
						  all_test_devices[MASTER],
						  all_test_devices[SEC_MASTER_1]);

    return status;
}

/**
 *Test Name: test_hot_join_slave
 *Test Description: This test adds new slave device to the bus
 *Pass Conditions: appropriate device joined the bus
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus, I3C_HjConfigureResponse
 *Use Case: I3C Bus management, Hotjoin
*/
int test_hot_join_slave(void)
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

    status += master_slave_hot_join_requrest(I3CM_drv,
					     I3CS_drv,
					     all_test_devices[MASTER],
					     all_test_devices[SLAVE_1]);

    return status;
}
