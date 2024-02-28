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
#define FLOW_CONTROL
int sdr_master_write(I3C_OBJ* master_driver,
         I3C_PrivData* master_private_data,
         uint8_t receiver_dynamic_address,
         uint8_t* tx_data,
         size_t tx_data_size)
{
    int status = 0;			/**< Will hold a sum of errors in case any occur. */

    I3C_CsrData csr_data = {
        .csr = I3CS_SDR_RXFIFO_SUBOFFSET,
        .csr16 = false
    };

    I3C_PayloadData payload_data = {
        .sdr_payload = tx_data,
        .ddr_payload = NULL,
        .payloadSize = tx_data_size
    };

    I3C_TransmissionParameters params = { 0 };

    status += master_driver->cmdClearAll(master_private_data);

    status += master_driver->cmdAddSetMaxWriteLength(master_private_data,
                 tx_data_size+1,
                 receiver_dynamic_address,
                 &params);

    status += master_driver->cmdAddPrivWrite(master_private_data,
               receiver_dynamic_address,
               &csr_data,
               &payload_data,
               I3C_CMD_XMIT_MODE_SINGLE_CSR);

    status += master_driver->setBusMode(master_private_data,
          I3C_BUS_MODE_MIXED_FAST);

    status += master_driver->cmdExec(master_private_data);

    print_status_before_return(status, __func__);

    return status;
}

int sdr_master_write_no_clean(I3C_OBJ* master_driver,
            void* master_private_data,
            uint8_t receiver_dynamic_address,
            uint8_t* tx_data,
            size_t tx_data_size)
{
    int status = 0;			/**< Will hold a sum of errors in case any occur. */

    I3C_CsrData csr_data = {
        .csr = I3CS_SDR_RXFIFO_SUBOFFSET,
        .csr16 = false
    };

    I3C_PayloadData payload_data = {
        .sdr_payload = tx_data,
        .ddr_payload = NULL,
        .payloadSize = tx_data_size
    };

    I3C_TransmissionParameters params = { 0 };

    status += master_driver->cmdAddSetMaxWriteLength(master_private_data,
                     tx_data_size,
                     receiver_dynamic_address,
                     &params);

    status += master_driver->cmdAddPrivWrite(master_private_data,
                   receiver_dynamic_address,
                   &csr_data,
                   &payload_data,
                   I3C_CMD_XMIT_MODE_SINGLE_CSR);

    status += master_driver->setBusMode(master_private_data,
              I3C_BUS_MODE_MIXED_FAST);

    print_status_before_return(status, __func__);

    return status;
}

int sdr_master_read(I3C_OBJ* master_driver,
        void* master_private_data,
        uint8_t transmitter_dynamic_address,
        uint8_t* rx_data,
        size_t rx_data_size)
{
    I3C_CsrData csr_data = {
        .csr = I3CS_SDR_TXFIFO_SUBOFFSET,
        .csr16 = false
    };

    I3C_PayloadData payload_data = {
        .sdr_payload = rx_data,
        .ddr_payload = NULL,
        .payloadSize = rx_data_size
    };

    I3C_TransmissionParameters params = { 0 };

    int status = 0;			/**< Will hold a sum of errors in case any occur. */

    I3C_MaxReadLength max_read_length = { 0 };

    max_read_length.payload_length = rx_data_size;

    status += master_driver->cmdClearAll(master_private_data);

    status += master_driver->cmdAddSetMaxReadLength(master_private_data,
                max_read_length,
                2, /* bytes required to encode max read length */
                transmitter_dynamic_address,
                &params);

    status += master_driver->cmdAddPrivRead(master_private_data,
              transmitter_dynamic_address,
              &csr_data,
              &payload_data,
              I3C_CMD_XMIT_MODE_SINGLE_CSR);

    status += master_driver->setBusMode(master_private_data,
          I3C_BUS_MODE_MIXED_FAST);

    status += master_driver->cmdExec(master_private_data);

    print_status_before_return(status, __func__);

    return status;
}


int sdr_secondary_master_write(I3C_OBJ *master_driver,
             void* secondary_master_private_data,
             uint8_t* tx_data,
             size_t tx_data_size)
{
    int status = 0;			/**< Will hold errors if any occur. */



    status += master_driver->slaveModeReqSdrWrite(secondary_master_private_data,
              tx_data,
              tx_data_size);

    print_status_before_return(status, __func__);

    return status;
}


int sdr_secondary_master_read(I3C_OBJ *master_driver,
            void* secondary_master_private_data,
            uint8_t* rx_data,
            size_t rx_data_size)
{
    int status = 0;			/**< Will hold errors if any occur. */

    status += master_driver->slaveModeReqSdrRead(secondary_master_private_data,
             rx_data,
             rx_data_size);

    print_status_before_return(status, __func__);

    return status;
}


int sdr_slave_write(I3CS_OBJ* slave_driver,
        I3CS_PrivData* slave_private_data,
        uint8_t* tx_data,
        size_t tx_data_size)
{
    int status = 0;
    status += slave_driver->reqSdrWrite(slave_private_data,
          tx_data,
          tx_data_size);

    print_status_before_return(status, __func__);

    return status;
}


int sdr_slave_read(I3CS_OBJ* slave_driver,
       I3CS_PrivData* slave_private_data,
       uint8_t* rx_data,
       size_t rx_data_size)
{
    int status = 0;
    status += slave_driver->reqSdrRead(slave_private_data,
               rx_data,
               rx_data_size);

    print_status_before_return(status, __func__);

    return status;

}

int sdr_secondary_master_flow_control(I3C_OBJ *master_driver,
            void* secondary_master_private_data,
            uint8_t mode)
{
    int status = 0;                     /**< Will hold errors if any occur. */

    status += master_driver->slaveModeReqFlowControl(secondary_master_private_data,
             mode);

    print_status_before_return(status, __func__);

    return status;
}


int sdr_send_to_secondary_master(I3C_OBJ *master_driver,
         fn_test_i3c_device* master,
         fn_test_i3c_device* secondary_master,
         uint8_t* tx_data,
         size_t data_size)
{
    int status = 0;   /**< Will hold errors if any occur. */
    uint8_t* rx_data; /**< Buffer for data received by secondaty slave. */

    rx_data = (uint8_t*)malloc(sizeof(uint8_t) * data_size);

    if (check_if_i3c_device_is_of_role(master, I3C_ROLE_MASTER)) {
        cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "%s, i3c device passed as master is not master\n", __func__);
    }

#ifdef FLOW_CONTROL
    status += sdr_secondary_master_flow_control(master_driver,
          secondary_master->private_data,
          I3C_NACK_NXT_PW_DISABLE);     
#endif
    status += sdr_master_write(master_driver,
             master->private_data,
             secondary_master->dynamic_address,
             tx_data,
             data_size);

    /* waiting for all transfers to be finished*/
    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    status += sdr_secondary_master_read(master_driver,
          secondary_master->private_data,
          rx_data,
          data_size);

    if (memcmp(tx_data, rx_data, sizeof(uint8_t) * data_size)) {
        status++;
    }
    free(rx_data);

    print_status_before_return(status, __func__);

    return status;
}

int sdr_send_from_secondary_master(I3C_OBJ *master_driver,
           fn_test_i3c_device* master,
           fn_test_i3c_device* secondary_master,
           uint8_t* tx_data,
           size_t data_size)
{
    int status = 0;   /**< Will hold errors if any occur. */
    uint8_t* rx_data; /**< Buffer for data received by master. */

    rx_data = (uint8_t*)malloc(sizeof(uint8_t) * data_size);

    if (check_if_i3c_device_is_of_role(master, I3C_ROLE_MASTER)) {
        cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "%s, i3c device passed as master is not master\n", __func__);
    }

    status += sdr_secondary_master_write(master_driver,
           secondary_master->private_data,
           tx_data,
           data_size);
#ifdef FLOW_CONTROL
    status += sdr_secondary_master_flow_control(master_driver,
          secondary_master->private_data,
          I3C_NACK_NXT_PR_DISABLE);
#endif

    status += sdr_master_read(master_driver,
            master->private_data,
            secondary_master->dynamic_address,
            rx_data,
            data_size);

    /* waiting for command to be completed */
    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    if (memcmp(tx_data, rx_data, sizeof(uint8_t) * data_size)) {
        status++;
        print_data_compare(tx_data, rx_data, data_size);
    }

    free(rx_data);

    print_status_before_return(status, __func__);

    return status;
}


uint32_t sdr_master_exec_command(I3C_OBJ* master_driver,
         void* master_private_data)
{
    int status = 0;   /**< Will hold errors if any occur. */

    status += master_driver->cmdClearAll(master_private_data); /* TODO: is this line really required? */

    status += master_driver->cmdExec(master_private_data);

    print_status_before_return(status, __func__);

    return status;
}


uint32_t sdr_master_send_multiple(I3C_OBJ *master_driver,
          fn_test_i3c_device* master,
          fn_test_i3c_device* secondary_master)
{
    uint32_t status = 0;
	uint32_t i = 0;
    uint16_t i3c_tx_buf_size = 8;

    uint8_t* i3c_tx_buf1 = (uint8_t*)malloc(sizeof(uint8_t) * i3c_tx_buf_size);
    uint8_t* i3c_tx_buf2 = (uint8_t*)malloc(sizeof(uint8_t) * i3c_tx_buf_size);
    uint8_t* i3c_tx_buf3 = (uint8_t*)malloc(sizeof(uint8_t) * i3c_tx_buf_size);

    uint8_t* i3c_rx_buf1 = (uint8_t*)malloc(sizeof(uint8_t) * i3c_tx_buf_size);
    uint8_t* i3c_rx_buf2 = (uint8_t*)malloc(sizeof(uint8_t) * i3c_tx_buf_size);
    uint8_t* i3c_rx_buf3 = (uint8_t*)malloc(sizeof(uint8_t) * i3c_tx_buf_size);

    generate_uint8_test_data(i3c_tx_buf1, i3c_tx_buf_size);
    generate_uint8_test_data(i3c_tx_buf2, i3c_tx_buf_size);
    generate_uint8_test_data(i3c_tx_buf3, i3c_tx_buf_size);
#ifdef FLOW_CONTROL
	for(i = 0; i < 3;i++)
	{
    	status += sdr_secondary_master_flow_control(master_driver,
        	secondary_master->private_data,
         	I3C_NACK_NXT_PW_DISABLE);     
    	status += sdr_master_write_no_clean(master_driver,
          	master->private_data,
          	secondary_master->dynamic_address,
          	i3c_tx_buf1,
          	i3c_tx_buf_size);
    	status += sdr_master_exec_command(master_driver,
              master->private_data);

    	/* waiting for all transfers to be finished*/
    	status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));
    	status += sdr_secondary_master_read(master_driver,
          secondary_master->private_data,
          i3c_rx_buf1,
          i3c_tx_buf_size);

    	status += sdr_secondary_master_flow_control(master_driver,
        	secondary_master->private_data,
         	I3C_NACK_NXT_PW_DISABLE);     
    	status += sdr_master_write_no_clean(master_driver,
          	master->private_data,
          	secondary_master->dynamic_address,
          	i3c_tx_buf2,
          	i3c_tx_buf_size);
    	status += sdr_master_exec_command(master_driver,
              master->private_data);

    	/* waiting for all transfers to be finished*/
    	status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));
    	status += sdr_secondary_master_read(master_driver,
          secondary_master->private_data,
          i3c_rx_buf2,
          i3c_tx_buf_size);

    	status += sdr_secondary_master_flow_control(master_driver,
        	secondary_master->private_data,
         	I3C_NACK_NXT_PW_DISABLE);     
    	status += sdr_master_write_no_clean(master_driver,
          	master->private_data,
          	secondary_master->dynamic_address,
          	i3c_tx_buf3,
          	i3c_tx_buf_size);
    	status += sdr_master_exec_command(master_driver,
              master->private_data);

    	/* waiting for all transfers to be finished*/
    	status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));
    	status += sdr_secondary_master_read(master_driver,
          secondary_master->private_data,
          i3c_rx_buf3,
          i3c_tx_buf_size);
	}
#else
    status += sdr_master_write_no_clean(master_driver,
          master->private_data,
          secondary_master->dynamic_address,
          i3c_tx_buf1,
          i3c_tx_buf_size);

    status += sdr_master_write_no_clean(master_driver,
              master->private_data,
              secondary_master->dynamic_address,
              i3c_tx_buf2,
              i3c_tx_buf_size);

    status += sdr_master_write_no_clean(master_driver,
              master->private_data,
              secondary_master->dynamic_address,
              i3c_tx_buf3,
              i3c_tx_buf_size);

    status += sdr_master_exec_command(master_driver,
              master->private_data);

    /* waiting for all transfers to be finished*/
    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    status += sdr_secondary_master_read(master_driver,
          secondary_master->private_data,
          i3c_rx_buf1,
          i3c_tx_buf_size);

    status += sdr_secondary_master_read(master_driver,
          secondary_master->private_data,
          i3c_rx_buf2,
          i3c_tx_buf_size);

    status += sdr_secondary_master_read(master_driver,
          secondary_master->private_data,
          i3c_rx_buf3,
          i3c_tx_buf_size);
#endif
    /* check if data sent equals to data read */
    if (memcmp(i3c_rx_buf1, i3c_tx_buf1, i3c_tx_buf_size)) {
        cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "%s, error: i3c_rx_buf1 != i3c_tx_buf1\n", __func__);
        status++;
    }

    if (memcmp(i3c_rx_buf2, i3c_tx_buf2, i3c_tx_buf_size)) {
        cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "%s, error: i3c_rx_buf2 != i3c_tx_buf2\n", __func__);
        status++;
    }

    if (memcmp(i3c_rx_buf3, i3c_tx_buf3, i3c_tx_buf_size)) {
        cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "%s, error: i3c_rx_buf3 != i3c_tx_buf3\n", __func__);
        status++;
    }

    free(i3c_tx_buf1);
    free(i3c_tx_buf2);
    free(i3c_tx_buf3);

    free(i3c_rx_buf1);
    free(i3c_rx_buf2);
    free(i3c_rx_buf3);

    print_status_before_return(status, __func__);

    return status;

}


int sdr_send_to_slave(I3C_OBJ *master_driver,
          I3CS_OBJ* slave_driver,
          fn_test_i3c_device* master,
          fn_test_i3c_device* slave,
          uint8_t* tx_data,
          size_t data_size)
{
    int status = 0;   /**< Will hold errors if any occur. */
    uint8_t* rx_data; /**< Buffer for data received by secondaty slave. */

    rx_data = (uint8_t*)malloc(sizeof(uint8_t) * data_size);

    if (check_if_i3c_device_is_of_role(master, I3C_ROLE_MASTER)) {
        cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "%s, i3c device passed as master is not master\n", __func__);
    }

    status += sdr_master_write(master_driver,
             master->private_data,
             slave->dynamic_address,
             tx_data,
             data_size);

    /* waiting for all transfers to be finished*/
    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    status += sdr_slave_read(slave_driver,
           (I3CS_PrivData*)slave->private_data,
           rx_data,
           data_size);

    if (memcmp(tx_data, rx_data, sizeof(uint8_t) * data_size)) {
        status++;
        print_data_compare(tx_data, rx_data, data_size);
    }

    free(rx_data);

    print_status_before_return(status, __func__);

    return status;
}

int sdr_send_from_slave(I3C_OBJ *master_driver,
      I3CS_OBJ* slave_driver,
      fn_test_i3c_device* master,
      fn_test_i3c_device* slave,
      uint8_t* tx_data,
      size_t data_size)
{
    int status = 0;   /**< Will hold errors if any occur. */
    uint8_t* rx_data; /**< Buffer for data received by master. */

    rx_data = (uint8_t*)malloc(sizeof(uint8_t) * data_size);

    if (check_if_i3c_device_is_of_role(master, I3C_ROLE_MASTER)) {
        cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "%s, i3c device passed as master is not master\n", __func__);
    }

    status += sdr_slave_write(slave_driver,
           (I3CS_PrivData*)slave->private_data,
           tx_data,
           data_size);

    status += sdr_master_read(master_driver,
            master->private_data,
            slave->dynamic_address,
            rx_data,
            data_size);

    /* waiting for all transfers to be finished*/
    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    if (memcmp(tx_data, rx_data, sizeof(uint8_t) * data_size)) {
        status++;
    }

    free(rx_data);

    print_status_before_return(status, __func__);

    return status;
}

/**
 *Test Name: test_sdr_master_sec_master_tx
 *Test Description: This test transfers data from master to secondary master
 *Pass Conditions: data transfer is success
 *Fail Conditions: data mismatch
 *APIs called: I3C_SlaveModeReqSdrRead, I3C_CmdClearAll, I3C_CmdAddPrivWrite, I3C_CmdExec
 *Use Case: I3C bus management, Interrupts, SDR mode support
*/
int test_sdr_master_sec_master_tx(void)
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
             all_test_devices[MASTER],
             all_test_devices[SEC_MASTER_0],
             i3c_tx_buf,
             i3c_tx_buf_size);

    free(i3c_tx_buf);

    return status;
}

/**
 *Test Name: test_sdr_master_sec_master_rx
 *Test Description: This test transfers data from secondary master to master
 *Pass Conditions: data transfer is success
 *Fail Conditions: data mismatch
 *APIs called: I3C_SlaveModeReqSdrRead, I3C_CmdClearAll, I3C_CmdAddPrivWrite, I3C_CmdExec
 *Use Case: I3C bus management, Interrupts, SDR mode support
*/
int test_sdr_master_sec_master_rx(void)
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

    int i3c_tx_buf_size = 12;
    uint8_t* i3c_tx_buf = (uint8_t*)malloc(sizeof(uint8_t) * i3c_tx_buf_size);

    generate_uint8_test_data(i3c_tx_buf, i3c_tx_buf_size);

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


    /*****************/
    /* SDR Transfers */
    /*****************/
    status = 0;
    status += sdr_send_from_secondary_master(I3CM_drv,
               all_test_devices[MASTER],
               all_test_devices[SEC_MASTER_0],
               i3c_tx_buf,
               i3c_tx_buf_size);

    free(i3c_tx_buf);

    return status;
}

/**
 *Test Name: test_sdr_master_sec_master_tx_multiple
 *Test Description: This test transfers data from master to secondary master multiple times
 *Pass Conditions: data transfer is success
 *Fail Conditions: data mismatch
 *APIs called: I3C_SlaveModeReqSdrRead, I3C_CmdClearAll, I3C_CmdAddPrivWrite, I3C_CmdExec
 *Use Case: I3C bus management, Interrupts, SDR mode support
*/
int test_sdr_master_sec_master_tx_multiple(void)
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

    /* Multiple write to commad queue */
    status = 0;

    status += sdr_master_send_multiple(I3CM_drv,
               all_test_devices[MASTER],
               all_test_devices[SEC_MASTER_0]);


    return status;

}

/**
 *Test Name: test_sdr_master_sec_master_tx_threshold
 *Test Description: This test transfers data to secondary master using threshold mechanism
 *Pass Conditions: data transfer is success
 *Fail Conditions: data mismatch
 *APIs called: I3C_SlaveModeReqSdrRead, I3C_CmdClearAll, I3C_CmdAddPrivWrite, I3C_CmdExec
 *Use Case: I3C bus management, Interrupts, SDR mode support
*/
int test_sdr_master_sec_master_tx_threshold(void)
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

    uint16_t i3c_tx_buf_size = 64;
    uint8_t* i3c_tx_buf = (uint8_t*)malloc(sizeof(uint8_t) * i3c_tx_buf_size);

    generate_uint8_test_data(i3c_tx_buf, i3c_tx_buf_size);

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


    /* SDR transfer */
    status = 0;
    status += sdr_send_to_secondary_master(I3CM_drv,
             all_test_devices[MASTER],
             all_test_devices[SEC_MASTER_0],
             i3c_tx_buf,
             i3c_tx_buf_size);

    free(i3c_tx_buf);

    return status;
}

/**
 *Test Name: test_sdr_master_sec_master_rx_threshold
 *Test Description: This test transfers data from secondary master using threshold mechanism
 *Pass Conditions: data transfer is success
 *Fail Conditions: data mismatch
 *APIs called: I3C_SlaveModeReqSdrRead, I3C_CmdClearAll, I3C_CmdAddPrivWrite, I3C_CmdExec
 *Use Case: I3C bus management, Interrupts, SDR mode support
*/
int test_sdr_master_sec_master_rx_threshold(void)
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

    uint16_t i3c_tx_buf_size = 64;
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


    /*****************/
    /* SDR Transfers */
    /*****************/
    status = 0;
    status += sdr_send_from_secondary_master(I3CM_drv,
            all_test_devices[MASTER],
            all_test_devices[SEC_MASTER_0],
            i3c_tx_buf,
            i3c_tx_buf_size);

    free(i3c_tx_buf);

    return status;
}

/**
 *Test Name: test_sdr_master_slave_tx
 *Test Description: This test transfers data to slave
 *Pass Conditions: data transfer is success
 *Fail Conditions: data mismatch
 *APIs called: I3C_SlaveModeReqSdrRead, I3C_CmdClearAll, I3C_CmdAddPrivWrite, I3C_CmdExec
 *Use Case: I3C bus management, Interrupts, SDR mode support
*/
int test_sdr_master_slave_tx(void)
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
    status += sdr_send_to_slave(I3CM_drv,
        I3CS_drv,
        all_test_devices[MASTER],
        all_test_devices[SLAVE_1],
        i3c_tx_buf,
        i3c_tx_buf_size);

    free(i3c_tx_buf);

    return status;
}

/**
 *Test Name: test_sdr_master_slave_rx
 *Test Description: This test transfers data from slave
 *Pass Conditions: data transfer is success
 *Fail Conditions: data mismatch
 *APIs called: I3C_SlaveModeReqSdrRead, I3C_CmdClearAll, I3C_CmdAddPrivWrite, I3C_CmdExec
 *Use Case: I3C bus management, Interrupts, SDR mode support
*/
int test_sdr_master_slave_rx(void)
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
    status += sdr_send_from_slave(I3CM_drv,
          I3CS_drv,
          all_test_devices[MASTER],
          all_test_devices[SLAVE_1],
          i3c_tx_buf,
          i3c_tx_buf_size);

    free(i3c_tx_buf);

    return status;
}
