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
#include "ei_tests.h"
#include "cps_ei.h"

/**
 *Test Name: test_isr_no_interrupt
 *Test Description: This test tries to call API isr implementation when interrupt did not occured
 *Pass Conditions: operation passed
 *Fail Conditions: any other status
 *APIs called: I3C_Probe, I3C_Init, I3C_Start, I3C_Isr
 *Use Case: Interrupts
*/
int test_isr_no_interrupt(void)
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

    I3C_PrivData *pd = all_test_devices[MASTER]->private_data;
    CPSEI_AddReadError(&(pd->regs_base->MST_ISR),
                0, 0, 0, 1);
    CPSEI_SkipHwRead(&(pd->regs_base->MST_ISR), true);

    status += I3CM_drv->isr(all_test_devices[MASTER]->private_data);

    return status;
}

/**
 *Test Name: test_isr_tx_rx_thr_cmd_list_empty
 *Test Description: This test tries to call API isr implementation with threshold interrupts
 *Pass Conditions: operation passed
 *Fail Conditions: any other status
 *APIs called: I3C_Probe, I3C_Init, I3C_Start, I3C_Isr
 *Use Case: Interrupts
*/
int test_isr_tx_rx_thr_cmd_list_empty(void)
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
    
    reg_val = CPS_FLD_SET(MIPI__MST_ISR, RX_THR, 1U);
    I3C_PrivData *pd = all_test_devices[MASTER]->private_data;
    CPSEI_AddReadError(&(pd->regs_base->MST_ISR),
		reg_val, 0, 0, 1);
    CPSEI_SkipHwRead(&(pd->regs_base->MST_ISR), true);

    status += I3CM_drv->isr(all_test_devices[MASTER]->private_data);

    reg_val = 0U;
    reg_val = CPS_FLD_SET(MIPI__MST_ISR, TX_THR, 1U);
    CPSEI_AddReadError(&(pd->regs_base->MST_ISR),
    		reg_val, 0, 0, 1);
    CPSEI_SkipHwRead(&(pd->regs_base->MST_ISR), true);

    status += I3CM_drv->isr(all_test_devices[MASTER]->private_data);

    return status;
}

/**
 *Test Name: test_auto_configuration
 *Test Description: This test tries to inject error in auto-configuration feature
 *Pass Conditions: configuration is reflected in private data
 *Fail Conditions: any other status
 *APIs called: I3C_Probe, I3C_Init, I3C_Start
 *Use Case: Driver auto configuration
*/
int test_auto_configuration(void)
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

    if(CPSEI_Enable() != 0U) {
      DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Cannot initialize CPSEI.\n");
    }

    uint32_t reg_val = 0U;
    
    reg_val = CPS_FLD_WRITE(MIPI__CONF_STATUS1, IBI_MEM_DEPTH, reg_val, 7U);

    MIPI_I3cRegs *regs = (MIPI_I3cRegs*) (all_test_devices[MASTER]->registers_base);
    CPSEI_AddReadError(&regs->CONF_STATUS1,
	    reg_val, 0, 0, 15);
    CPSEI_SkipHwRead(&regs->CONF_STATUS1, true);
    
    initialize_master(I3CM_drv,
      device_descriptors,
      device_descriptors_number,
      all_test_devices,
      number_of_all_test_devices);
    
    

    if (all_test_devices[MASTER]->private_data->ibi_fifo_size != 0U) {
	DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. IBI FIFO SIZE is: %d\n",
	       all_test_devices[MASTER]->private_data->ibi_fifo_size);
	status++;
    }

    return status;
}

/**
 *Test Name: test_transfer_to_non_existing_device
 *Test Description: This test performs transfer to non-existing device
 *Pass Conditions: API function returns CDN_EINVAL
 *Fail Conditions: any other status
 *APIs called: I3C_Probe, I3C_Init, I3C_Start, I3C_CmdAddPrivRead, I3C_CmdAddPrivWrite, I3C_CmdAddDdrWrite, I3C_CmdAddDdrRead
 *Use Case: Change address of dynamic addressed device
*/
int test_transfer_to_non_existing_device(void)
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

    I3C_CsrData csrData = {0};
    I3C_PayloadData payloadData = {0};
    
    if (I3CM_drv->cmdAddPrivRead(all_test_devices[MASTER]->private_data,
			     0xFA, // missing device
			     &csrData,
			     &payloadData,
			     I3C_CMD_XMIT_MODE_SINGLE_CSR) != CDN_EINVAL) {
	status++;
    }
    
    if (I3CM_drv->cmdAddPrivWrite(all_test_devices[MASTER]->private_data,
    			     0xFA, // missing device
    			     &csrData,
    			     &payloadData,
			     I3C_CMD_XMIT_MODE_SINGLE_CSR) != CDN_EINVAL) {
    	status++;
    }
    
    if (I3CM_drv->cmdAddDdrWrite(all_test_devices[MASTER]->private_data,
				 0xFA, // missing device
				 0x01,
				 I3C_HDR_MODE_DDR,
				 &payloadData) != CDN_EINVAL) {
	    status++;
    }
    
    if (I3CM_drv->cmdAddDdrRead(all_test_devices[MASTER]->private_data,
				 0xFA, // missing device
				 0x80,
				 I3C_HDR_MODE_DDR,
				 &payloadData) != CDN_EINVAL) {
	    status++;
    }

    return status;
}
