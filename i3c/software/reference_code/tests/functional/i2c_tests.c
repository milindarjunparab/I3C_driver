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
#include "i2c_tests.h"

#include "cps_ei.h"

static bool i2c_isr_complete;
static uint8_t i2c_txbuf[32] = {0};
static uint8_t i2c_rxbuf[32] = {0};

static void initialize_bus_i2c(I3C_OBJ *master_driver,
        I3C_PrivData *master_privdata)
{
    master_driver->setBusMode(master_privdata, I3C_BUS_MODE_MIXED_FAST);
    master_driver->enableCore(master_privdata);
    I3C_BusMode bm;
    master_driver->getBusMode(master_privdata, &bm);

    master_driver->devPrint(master_privdata);
}

static void i2c_read_test_isr(void)
{
    uint32_t irq;
    int i;

    cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "I2C: ISR handler.\n");

    // Read and clear I2C interrupts.
    irq = CPS_REG_READ(I2C1_REGS_BASE + 0x10);
    CPS_REG_WRITE(I2C1_REGS_BASE + 0x10, irq);

    cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "IRQ(s): 0x%.8X\n", irq);

    if (i2c_isr_complete)
        return;

    // Check for COMP interrupt
    if (irq & 0x01) {
        cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "I2C: Transfer Complete.\n");
    }

    // Check for DATA interrupt
    if (irq & 0x02) {
        // Load slave's FIFO with data.
        for (i = 0; i < strlen(i2c_txbuf); ++i)
            CPS_REG_WRITE(I2C1_REGS_BASE + 0x0C, i2c_txbuf[i]);

        cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "I2C: Finished writing data to FIFO.\n");
    }

    i2c_isr_complete = true;
}

/**
 *Test Name: test_i2c_read
 *Test Description: This test transfer data from I2C device
 *Pass Conditions: data transfer is success
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_CmdAddPrivI2CWrite, I3C_CmdAddPrivI2CRead, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C bus management, I2C legacy devices
*/
int test_i2c_read(void)
{
    uint32_t status = 0;

    I3C_OBJ *I3CM_drv;
    I3C_OBJ *I3CS_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
     * descriptors that goes
     * to master driver and
     * is used for bus
     * configuration. */
    int device_descriptors_number = 0;

    i3c_IrqInit();

    I3CM_drv = I3C_GetInstance();
    I3CS_drv = I3C_GetInstance();

    reset_devices(RST_ALL);

    // wait for slave 1ms ON delay
    // additional 270us is needed
    // so for fclk=50MHz and actual clock 2.451
    /* following does the job */

    delay_ms(3);

    fn_test_i3c_device* i2c_config_devices[] = { &master_0_primary, &i2c_slave };

    setup_device_descriptors(&device_descriptors, &device_descriptors_number,
            i2c_config_devices, 2);

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            i2c_config_devices, 2);

    initialize_slave_i2c(i2c_config_devices[1]);

    // Clear all interrupts
    CPS_REG_READ(I2C1_REGS_BASE + 0x10);// cleared if cdnsi2c_read_clear is defined in RTL
    CPS_REG_WRITE(I2C1_REGS_BASE + 0x10, 0xFFFF);
    // Clear RX FIFO in I2C slave and set it to TX mode
    CPS_REG_WRITE(I2C1_REGS_BASE + 0x00, 0x0000074C);
    // Set ISR handler for I2C Slave
    i2c_isr_set_handler(i2c_read_test_isr);

    I3C_CsrData csr_data = { 0 };

    snprintf(i2c_txbuf, sizeof(i2c_txbuf), "Hello, Master!");
    uint8_t tx_data_len = strlen(i2c_txbuf);
    uint8_t *rx_data = (uint8_t*) malloc(sizeof(uint8_t) * (tx_data_len + 1));

    initialize_bus_i2c(I3CM_drv, i2c_config_devices[MASTER]->private_data);

    I3CM_drv->cmdAddPrivI2CRead(i2c_config_devices[MASTER]->private_data,
            i2c_config_devices[1]->static_address, rx_data, tx_data_len + 1);

    I3CM_drv->cmdExec(i2c_config_devices[MASTER]->private_data);

    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    if (memcmp(i2c_txbuf, rx_data + 1, tx_data_len) != 0) {
        cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Data mismatch!\n");

        uint8_t i;
        for (i = 0; i < tx_data_len; ++i) {
            cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "\trx[%d]: %.2X, tx[%d]: %.2X\n",
                    i, rx_data[i + 1], i, i2c_txbuf[i]);
        }

        status++;
    }

    free(rx_data);

    return status;
}

static void i2c_write_test_isr(void)
{
    uint32_t irq;
    uint32_t rcv_cnt;
    uint32_t err_cnt;
    int i;

    cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "I2C: ISR handler.\n");

    // Read and clear I2C interrupts.
    irq = CPS_REG_READ(I2C1_REGS_BASE + 0x10);
    CPS_REG_WRITE(I2C1_REGS_BASE + 0x10, irq);

    cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "IRQ(s): 0x%.8X\n", irq);

    // Check for COMP interrupt
    if (irq & 0x01) {
        cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "I2C: Transfer Complete.\n");

        // Get number of received valid data bytes
        rcv_cnt = (uint8_t) (CPS_REG_READ(I2C1_REGS_BASE + 0x14) & 0x000F);

        // value of rcv_cnt is always smaller than size of i2c_rxbuf buffer
        for (i = 0; i < rcv_cnt; ++i)
            i2c_rxbuf[i] = (uint8_t) CPS_REG_READ(I2C1_REGS_BASE + 0x0C);

        i2c_rxbuf[rcv_cnt] = '\0';
        cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "I2C: Slave received %d bytes: %s\n", rcv_cnt, i2c_rxbuf);

        i2c_isr_complete = true;
    }
}

/**
 *Test Name: test_i2c_write
 *Test Description: This test transfer data to I2C device
 *Pass Conditions: data transfer is success
 *Fail Conditions: any other status
 *APIs called: I3C_SetBcr, I3C_SetDcr, I3C_SetPid, I3C_ConfigureDevices, I3C_ConfigureDevice, I3C_CmdAddPrivI2CWrite, I3C_CmdAddPrivI2CRead, I3C_CmdAddEnterDaa, I3C_GetSlavesList, I3C_CmdSetDaFromSa, I3C_CmdAddGetProvisionalId, I3C_CmdAddGetBcr, I3C_CmdAddGetDcr, I3C_CmdAddGetStatus
 *Use Case: I3C bus management, I2C legacy devices
*/
int test_i2c_write(void)
{
    uint32_t status = 0;

    I3C_OBJ *I3CM_drv;
    I3C_OBJ *I3CS_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
     * descriptors that goes
     * to master driver and
     * is used for bus
     * configuration. */
    int device_descriptors_number = 0;

    i3c_IrqInit();

    I3CM_drv = I3C_GetInstance();
    I3CS_drv = I3C_GetInstance();

    reset_devices(RST_ALL);

    // wait for slave 1ms ON delay
    // additional 270us is needed
    // so for fclk=50MHz and actual clock 2.451
    /* following does the job */

    delay_ms(3);

    fn_test_i3c_device* i2c_config_devices[] = { &master_0_primary, &i2c_slave };

    setup_device_descriptors(&device_descriptors, &device_descriptors_number,
            i2c_config_devices, 2);

    initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            i2c_config_devices, 2);

    initialize_slave_i2c(i2c_config_devices[1]);

    // Clear Transfer Completed flag (Slave's side)
    i2c_isr_complete = false;
    // Set ISR handler for Slave
    i2c_isr_set_handler(i2c_write_test_isr);

    I3C_CsrData csr_data = { 0 };

    uint8_t *tx_data = "Hello from I3C!";
    uint8_t tx_data_len = strlen(tx_data);

    initialize_bus_i2c(I3CM_drv, i2c_config_devices[MASTER]->private_data);

    I3CM_drv->cmdAddPrivI2CWrite(i2c_config_devices[MASTER]->private_data,
            i2c_config_devices[1]->static_address, tx_data, tx_data_len);

    I3CM_drv->cmdExec(i2c_config_devices[MASTER]->private_data);

    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));
    status += wait_for_global_status(&(i2c_isr_complete));

    if (memcmp(tx_data, i2c_rxbuf, tx_data_len) != 0) {
        cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "Data mismatching!\n");
        status++;
    
    }
        uint8_t i;
        for (i = 0; i < tx_data_len; ++i) {
            cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "\ttx[%d]: %.2X, rx[%d]: %.2X\n",
                    i, tx_data[i], i, i2c_rxbuf[i]);
        }


    return status;
}

/**
 *Test Name: test_i2c_inactive_device_init
 *Test Description: This test tries to initialize inactive I2C device
 *Pass Conditions: operation passed
 *Fail Conditions: any other status
 *APIs called: I3C_Probe, I3C_Init, I3C_Start, I3C_SetBusMode, I3C_EnableCore, I3C_GetBusMode, I3C_DevPrint
 *Use Case: I2C legacy devices
*/
int test_i2c_inactive_device_init(void)
{
    uint32_t status = 0;

    I3C_OBJ *I3CM_drv;
    I3C_OBJ *I3CS_drv;

    I3C_DeviceDescriptor* device_descriptors; /**< Array of i3c device
     * descriptors that goes
     * to master driver and
     * is used for bus
     * configuration. */
    int device_descriptors_number = 0;

    i3c_IrqInit();

    I3CM_drv = I3C_GetInstance();
    I3CS_drv = I3C_GetInstance();

    reset_devices(RST_ALL);

    // wait for slave 1ms ON delay
    // additional 270us is needed
    // so for fclk=50MHz and actual clock 2.451
    /* following does the job */

    delay_ms(3);

    fn_test_i3c_device* i2c_config_devices[] = { &master_0_primary, &i2c_slave_fm };
    i2c_slave_fm.is_active = 0;

    setup_device_descriptors(&device_descriptors, &device_descriptors_number,
            i2c_config_devices, 2);

    status += initialize_master(I3CM_drv, device_descriptors, device_descriptors_number,
            i2c_config_devices, 2);

    initialize_slave_i2c(i2c_config_devices[1]);

    initialize_bus_i2c(I3CM_drv, i2c_config_devices[MASTER]->private_data);

    return status;
}
