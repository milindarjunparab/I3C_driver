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
#include "init_tests.h"
#include "cps_ei.h"


/**
 *Test Name: test_init_params
 *Test Description: This test checks if initial parameters are correct
 *Pass Conditions: parameters are correct
 *Fail Conditions: any other status
 *APIs called: I3C_Probe, I3C_Init, I3C_Start, I3C_EnableCore, I3C_DisableCore
 *Use Case: Common architecture, Driver auto configuration
*/
int test_init_params(void)
{
    uint32_t status = 0;

    I3C_OBJ *I3CM_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
         * descriptors that goes
         * to master driver and
         * is used for bus
         * configuration. */
    int device_descriptors_number = 0;

    i3c_IrqInit();

    I3CM_drv = I3C_GetInstance();

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

    /* checks if command count is empty */
    if(I3CM_drv->cmdCount(all_test_devices[MASTER]->private_data) != 0U) {
        status++;
    }
    /* checks if command mac count is value assigned duting initialization */
    if(I3CM_drv->cmdMaxCount(all_test_devices[MASTER]->private_data) != 4) {
        status++;
    }

    return status;
}

/**
 *Test Name: test_init_sec_master_disable_interrupts
 *Test Description: This test tries to initialize secondary master with all interrupts disabled
 *Pass Conditions: interrupts are configured properly
 *Fail Conditions: any other status
 *APIs called: I3C_Probe, I3C_Init, I3C_Start, I3C_EnableCore, I3C_DisableCore
 *Use Case: Common architecture, Driver auto configuration
*/
int test_init_sec_master_disable_interrupts(void)
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

    I3C_SlaveInterruptConfig intCfg = {
    .sdrWrComplete = false,
    .sdrRdComplete = false,
    .ddrWrComplete = false,
    .ddrRdComplete = false,
    .sdrTxDataFifoOverflow = false,
    .sdrRxDataFifoUnderflow = false,
    .ddrTxDataFifoOverflow = false,
    .ddrRxDataFifoUnderflow = false,
    .sdrTxFifoThreshold = false,
    .sdrRxFifoThreshold = false,
    .ddrTxFifoThreshold = false,
    .ddrRxFifoThreshold = false,
    .masterReadAbort = false,
    .ddrFail = false,
    .sdrFail = false,
    .dynamicAddrUpdated = false,
    .ibiDone = false,
    .ibiNack = false,
    .hotJoinDone = false,
    .hotJoinNack = false,
    .eventUpdate = false,
    .protocolError = false,
    .testMode = false
    };

    status += I3CM_drv->slaveModeConfigure(all_test_devices[SEC_MASTER_0]->private_data, &intCfg);

    return status;
}

/**
 *Test Name: test_init_parts_core_enabled
 *Test Description: This test tries to execute functions which requires core to be disabled
 *Pass Conditions: core is enabled
 *Fail Conditions: any other status
 *APIs called: I3C_Probe, I3C_Init, I3C_Start, I3C_EnableCore, I3C_DisableCore
 *Use Case: Common architecture, Driver auto configuration
*/
int test_init_parts_core_enabled(void)
{
    uint32_t status = 0;

    I3C_OBJ *I3CM_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
         * descriptors that goes
         * to master driver and
         * is used for bus
         * configuration. */
    int device_descriptors_number = 0;

    i3c_IrqInit();

    I3CM_drv = I3C_GetInstance();

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

    if(I3CM_drv->enableCore(all_test_devices[MASTER]->private_data)
            != 0U) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Cannot enable core\n");
    }

    /* Initialize device once again when core is enabled */
    I3C_Config config = {0};
    I3C_Callbacks callbacks = {0};
    if(I3CM_drv->init(all_test_devices[MASTER]->private_data,
            &config, &callbacks) != CDN_EIO) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Core is not enabled\n");
        status++;
    }

    if(I3CM_drv->configureDevices(all_test_devices[MASTER]->private_data,
            device_descriptors, 0) != CDN_EIO) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Core is not enabled\n");
        status++;
    }

    I3C_InterruptConfig interrupt_config = {0};
    if(I3CM_drv->configureInterrupts(all_test_devices[MASTER]->private_data,
            &interrupt_config) != CDN_EIO) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Core is not enabled\n");
        status++;
    }

    I3C_ThresholdConfig threshold_config = {0};
    if(I3CM_drv->configureThresholds(all_test_devices[MASTER]->private_data,
            &threshold_config) != CDN_EIO) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Core is not enabled\n");
        status++;
    }

    I3C_SlaveInterruptConfig slave_int_config = {0};
    if(I3CM_drv->configureSlaveInterrupts(all_test_devices[MASTER]->private_data,
            &slave_int_config) != CDN_EIO) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Core is not enabled\n");
        status++;
    }
    
    if(I3CM_drv->configureDevice(all_test_devices[MASTER]->private_data,
				 &device_descriptors[2], 
				 2) != CDN_EIO) {
    	DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Core is not enabled\n");
    	status++;
    }
    
    if(I3CM_drv->disableCore(all_test_devices[MASTER]->private_data) != 0U) {
	DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Cannot disable core\n");
    }
    
    if(I3CM_drv->clearRrOfDevice(all_test_devices[MASTER]->private_data, 1) != CDN_EIO) {
	DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Core is not disabled\n");
	status++;
    }

    return status;
}

/**
 *Test Name: test_init_stop_interrupt
 *Test Description: This test tries to call API isr implementation when core has been stopped
 *Pass Conditions: interrupt is not handled
 *Fail Conditions: any other status
 *APIs called: I3C_Probe, I3C_Isr, I3C_Init, I3C_Start, I3C_EnableCore, I3C_DisableCore
 *Use Case: Common architecture, Driver auto configuration
*/
int test_init_stop_interrupt(void)
{
    uint32_t status = 0;

    I3C_OBJ *I3CM_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
         * descriptors that goes
         * to master driver and
         * is used for bus
         * configuration. */
    int device_descriptors_number = 0;

    i3c_IrqInit();

    I3CM_drv = I3C_GetInstance();

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

    status += I3CM_drv->stop(all_test_devices[MASTER]->private_data);

    status += I3CM_drv->isr(all_test_devices[MASTER]->private_data);

    return status;
}

/**
 *Test Name: test_init_destroy
 *Test Description: This test tries to destroy driver
 *Pass Conditions: driver destroyed
 *Fail Conditions: any other status
 *APIs called: I3C_Probe, I3C_Init, I3C_Start, I3C_EnableCore, I3C_DisableCore
 *Use Case: Common architecture, Driver auto configuration
*/
int test_init_destroy(void)
{
    uint32_t status = 0;

    I3C_OBJ *I3CM_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
         * descriptors that goes
         * to master driver and
         * is used for bus
         * configuration. */
    int device_descriptors_number = 0;

    i3c_IrqInit();

    I3CM_drv = I3C_GetInstance();

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

    status += I3CM_drv->destroy(all_test_devices[MASTER]->private_data);

    return status;
}

/**
 *Test Name: test_init_bus_mode
 *Test Description: This test checks if correct bus mode is set
 *Pass Conditions: correct bus mode
 *Fail Conditions: any other status
 *APIs called: I3C_Probe, I3C_Init, I3C_Start, I3C_EnableCore, I3C_DisableCore
 *Use Case: Common architecture, Driver auto configuration
*/
int test_init_bus_mode(void)
{
    uint32_t status = 0;

    I3C_OBJ *I3CM_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
         * descriptors that goes
         * to master driver and
         * is used for bus
         * configuration. */
    int device_descriptors_number = 0;

    i3c_IrqInit();

    I3CM_drv = I3C_GetInstance();

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

    I3C_BusMode mode = I3C_BUS_MODE_INVALID;

    I3CM_drv->setBusMode(all_test_devices[MASTER]->private_data, I3C_BUS_MODE_PURE);
    I3CM_drv->getBusMode(all_test_devices[MASTER]->private_data, &mode);

    if(mode != I3C_BUS_MODE_PURE) {
        status++;
    }

    I3CM_drv->setBusMode(all_test_devices[MASTER]->private_data, I3C_BUS_MODE_INVALID);
    I3CM_drv->getBusMode(all_test_devices[MASTER]->private_data, &mode);

    if(mode != I3C_BUS_MODE_INVALID) {
        status++;
    }


    I3CM_drv->setBusMode(all_test_devices[MASTER]->private_data, I3C_BUS_MODE_MIXED_FAST);
    I3CM_drv->getBusMode(all_test_devices[MASTER]->private_data, &mode);

    if(mode != I3C_BUS_MODE_MIXED_FAST) {
        status++;
    }


    I3CM_drv->setBusMode(all_test_devices[MASTER]->private_data, I3C_BUS_MODE_MIXED_SLOW);
    I3CM_drv->getBusMode(all_test_devices[MASTER]->private_data, &mode);

    if(mode != I3C_BUS_MODE_MIXED_SLOW) {
        status++;
    }

    return status;
}

/**
 *Test Name: test_init_without_devs
 *Test Description: This test tries to initialize master without devices on the bus
 *Pass Conditions: master not initialized
 *Fail Conditions: any other status
 *APIs called: I3C_Probe, I3C_Init, I3C_Start, I3C_EnableCore, I3C_DisableCore
 *Use Case: Common architecture, Driver auto configuration
*/
int test_init_without_devs(void)
{
    uint32_t status = 0;

    I3C_OBJ *I3CM_drv;

    I3C_DeviceDescriptor* device_descriptors = NULL; /**< Array of i3c device
         * descriptors that goes
         * to master driver and
         * is used for bus
         * configuration. */
    int device_descriptors_number = 1;

    i3c_IrqInit();

    I3CM_drv = I3C_GetInstance();

    reset_devices(RST_ALL);

    // wait for slave 1ms ON delay
    // additional 270us is needed
    // so for fclk=50MHz and actual clock 2.451
    /* following does the job */

    delay_ms(3);

    if (initialize_master(I3CM_drv,
			  device_descriptors,
			  device_descriptors_number,
			  all_test_devices,
			  number_of_all_test_devices) == 0) {
	status++;
    }

    return status;
}

/**
 *Test Name: test_init_core_idle
 *Test Description: This test injects error, core cannot be disabled
 *Pass Conditions: core not disabled, CDN_EIO returned
 *Fail Conditions: any other status
 *APIs called: I3C_Probe, I3C_Init, I3C_Start, I3C_EnableCore, I3C_DisableCore, I3C_ConfigureInterrupts, I3C_ConfigureThresholds
 *Use Case: Common architecture, Interrupts
*/
int test_init_core_idle(void)
{
    uint32_t status = 0;

    I3C_OBJ *I3CM_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
         * descriptors that goes
         * to master driver and
         * is used for bus
         * configuration. */
    int device_descriptors_number = 0;

    i3c_IrqInit();

    I3CM_drv = I3C_GetInstance();

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

    if(CPSEI_Enable() != 0U) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Cannot initialize CPSEI.\n");
    }

    uint32_t reg_val = 0U;
    reg_val = CPS_FLD_WRITE(MIPI__MST_STATUS0, IDLE, reg_val, 1);

    I3C_PrivData *pd = all_test_devices[MASTER]->private_data;
    /* Driver waits 1000 iterations for core to be idle */
    CPSEI_AddReadError(&(pd->regs_base->MST_STATUS0),
                reg_val, MIPI__MST_STATUS0__IDLE_MASK, 0, 1100);
    CPSEI_SkipHwRead(&(pd->regs_base->MST_STATUS0), true);

    /* Set bus mode disables core  */
    if (I3CM_drv->setBusMode(all_test_devices[MASTER]->private_data, 
			     I3C_BUS_MODE_MIXED_FAST) != CDN_EIO) {
	status++;
    }

    return status;
}

/**
 *Test Name: test_init_too_many_devs
 *Test Description: This test tries to initialize master with too many devices
 *Pass Conditions: master not initialized
 *Fail Conditions: any other status
 *APIs called: I3C_Probe, I3C_Init, I3C_Start, I3C_EnableCore, I3C_DisableCore, I3C_ConfigureInterrupts, I3C_ConfigureThresholds
 *Use Case: Common architecture, Interrupts
*/
int test_init_too_many_devs(void)
{
    uint32_t status = 0;

    I3C_OBJ *I3CM_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
         * descriptors that goes
         * to master driver and
         * is used for bus
         * configuration. */
    int device_descriptors_number = 0;

    i3c_IrqInit();

    I3CM_drv = I3C_GetInstance();

    reset_devices(RST_ALL);

    // wait for slave 1ms ON delay
    // additional 270us is needed
    // so for fclk=50MHz and actual clock 2.451
    /* following does the job */

    delay_ms(3);

    setup_device_descriptors(&device_descriptors, &device_descriptors_number,
       all_test_devices, number_of_all_test_devices);

    if (initialize_master(I3CM_drv,
			  device_descriptors,
			  15, /* fake device count */
			  all_test_devices,
			  number_of_all_test_devices) == 0) {
	status++;
    }

    return status;
}

/**
 *Test Name: test_init_pure_bus
 *Test Description: This test initializes driver with HDR capable devices only
 *Pass Conditions: bus is pure after initialization
 *Fail Conditions: any other status
 *APIs called: I3C_Probe, I3C_Init, I3C_Start, I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ClearRrOfDevice, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetStatus
 *Use Case: Common architecture, Various I3C Bus modes, I3C Bus management
*/
int test_init_pure_bus(void)
{
    uint32_t status = 0;

    I3C_OBJ *I3CM_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
         * descriptors that goes
         * to master driver and
         * is used for bus
         * configuration. */
    int device_descriptors_number = 0;

    i3c_IrqInit();

    I3CM_drv = I3C_GetInstance();

    reset_devices(RST_ALL);

    // wait for slave 1ms ON delay
    // additional 270us is needed
    // so for fclk=50MHz and actual clock 2.451
    /* following does the job */

    delay_ms(3);

    int number_of_hdr_capable_devs = 3;

    fn_test_i3c_device* hdr_devs[] = {
            &master_0_primary,
            &master_2_secondary,
            &slave_1
    };

    setup_device_descriptors(&device_descriptors, &device_descriptors_number,
            hdr_devs, number_of_hdr_capable_devs);

    status += initialize_master(I3CM_drv,
      device_descriptors,
      device_descriptors_number,
      hdr_devs,
      number_of_hdr_capable_devs);
    
    I3C_BusMode busMode = I3C_BUS_MODE_INVALID;
    status += I3CM_drv->getBusMode(hdr_devs[MASTER]->private_data, &busMode);
    if (busMode != I3C_BUS_MODE_PURE) {
	status++;
    }

    return status;
}

/**
 *Test Name: test_init_prescalers_with_no_timings
 *Test Description: This test tries to reconfigure prescalers
 *Pass Conditions: operation passed
 *Fail Conditions: any other status
 *APIs called: I3C_Probe, I3C_Init, I3C_Start, I3C_SetBusMode, I3C_GetBusMode, I3C_ConfigurePrescalers, I3C_DevPrint
 *Use Case: Common architecture, Various I3C Bus modes, Prescaler configuration
*/
int test_init_prescalers_with_no_timings(void)
{
    uint32_t status = 0;

    I3C_OBJ *I3CM_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
         * descriptors that goes
         * to master driver and
         * is used for bus
         * configuration. */
    int device_descriptors_number = 0;

    i3c_IrqInit();

    I3CM_drv = I3C_GetInstance();

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

    /* Re-configure prescalers without timings */
    I3C_Config config = {0};
    config.i2cFreq = 400000;
    config.sdrFreq = 10000000;
    I3C_Callbacks callbacks = {0};
    if(I3CM_drv->configurePrescalers(all_test_devices[MASTER]->private_data,
            &config) != 0U) {
        status++;
    }
    

    return status;
}
