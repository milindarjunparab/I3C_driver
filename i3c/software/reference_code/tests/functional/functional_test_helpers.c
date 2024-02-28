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
#include "functional_test_helpers.h"

void generate_uint8_test_data(uint8_t* data, int number_of_samples)
{
    int i;

    if (data != NULL) {
        for (i = 0; i < number_of_samples; i++) {
          data[i] = i+1;
        }
    }
}

void generate_uint16_test_data(uint16_t* data, int number_of_samples)
{
    uint16_t i;

    if (data != NULL) {
        for (i = 0; i < number_of_samples; i++) {
          data[i] = ((i * 2) | ((i * 2 + 1) << 8));
        }
    }
}

int check_if_i3c_device_is_of_role(fn_test_i3c_device* i3c_device,
           fn_test_i3c_role i3c_role)
{
    int status;
    if (i3c_device->role == i3c_role) {
      status = 0;
    } else {
      status = 1;
    }
    return status;
}

void print_status_before_return(int status,
        const char* function_name)
{
    if (status > 0) {
  cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "TEST ERROR: Failed at %s\n", function_name);
    } else {
  cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "STEP OK: Returning from %s\n", function_name);
    }
}

void print_data_compare(uint8_t *exp, uint8_t *act, size_t size)
{
  uint8_t i;
  for(i=0; i<size; i++) {
    DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Byte %d:\t Expected(0x%.2X), Actual(0x%.2X), Eq: %s\n", i, exp[i], act[i], exp[i] == act[i] ? "true":"false");
  }
}

uint32_t wait_for_global_status(volatile bool* i3c_status)
{
    int timeout = 10000;

    if (i3c_status == NULL) {
        cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "Status flag cannot be NULL.\n");
        return CDN_EINVAL;
    }

    while (!(*i3c_status) && timeout--) {
        CPS_DelayNs(10);
    }

    *i3c_status = false;

    if (timeout == -1) {
        cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "TIMEOUT\n");
        return CDN_ETIMEDOUT;
    }
    return CDN_EOK;
}

uint32_t i3c_reg_read(fn_test_i3c_device* i3c_device, uint32_t reg)
{
    return CPS_UncachedRead32(i3c_device->registers_base + reg);
}

void i3c_reg_write(fn_test_i3c_device* i3c_device, uint32_t reg, uint32_t val)
{
    CPS_UncachedWrite32(i3c_device->registers_base + reg, val);
}

static void I3CM_TH_InterruptHandler(uint32_t num)
{
    I3C_OBJ *drv = I3C_GetInstance();

    if (num != XT_LNX0_I3C_MST0_IRQ)
  return; //Received other interrupt

    if (!drv || !all_test_devices[MASTER]->private_data)
  return;

    drv->isr(all_test_devices[MASTER]->private_data);
}

void i2c_isr_set_handler(void (*handler)(void))
{
    i2c_post_isr_handler = handler;
}

static void I2CTH_InterruptHandler(uint32_t num)
{
    if (num != XT_LNX0_I2C1_IRQ)
        return; //Received other interrupt

    if (i2c_post_isr_handler)
        i2c_post_isr_handler();
}

static void I3CSM0_TH_InterruptHandler(uint32_t num)
{
    I3C_OBJ *drv = I3C_GetInstance();

    if (num != XT_LNX0_I3C_MST1_IRQ)
  return; //Received other interrupt

    if (!drv || !all_test_devices[SEC_MASTER_0]->private_data)
  return;

    drv->isr(all_test_devices[SEC_MASTER_0]->private_data);
}

static void I3CSM1_TH_InterruptHandler(uint32_t num)
{
    I3C_OBJ *drv = I3C_GetInstance();

    if (num != XT_LNX0_I3C_MST2_IRQ)
  return; //Received other interrupt

    if (!drv || !all_test_devices[SEC_MASTER_1]->private_data)
  return;

    drv->isr(all_test_devices[SEC_MASTER_1]->private_data);
}

void i3c_IrqInit(void)
{
  _xtos_set_interrupt_handler_arg(XT_LNX0_I3C_MST0_IRQ,I3CM_TH_InterruptHandler,XT_LNX0_I3C_MST0_IRQ);
  _xtos_set_interrupt_handler_arg(XT_LNX0_I3C_MST1_IRQ,I3CSM0_TH_InterruptHandler,XT_LNX0_I3C_MST1_IRQ);
  _xtos_set_interrupt_handler_arg(XT_LNX0_I3C_MST2_IRQ,I3CSM1_TH_InterruptHandler,XT_LNX0_I3C_MST2_IRQ);
  _xtos_set_interrupt_handler_arg(XT_LNX0_I2C1_IRQ,I2CTH_InterruptHandler,XT_LNX0_I2C1_IRQ);
    _xtos_ints_on(1<<XT_LNX0_I3C_MST0_IRQ |
            1<<XT_LNX0_I3C_MST1_IRQ |
            1<<XT_LNX0_I3C_MST2_IRQ |
            1<<XT_LNX0_I2C1_IRQ
  );
}

#define ADDR_SCRATCH_REG_2 9

# define scratchled_write(val_)						\
    CPS_UncachedWrite32((volatile uint32_t *)((uintptr_t)(SYSREGS_IF_APB_BASE) + ADDR_SCRATCH_REG_2*4 ), (uint32_t)(val_))
# define scratchled_read()						\
    CPS_UncachedRead32((volatile uint32_t *)((uintptr_t)(SYSREGS_IF_APB_BASE) + ADDR_SCRATCH_REG_2*4 ))


void reset_devices(uint8_t rst_msk) {
    scratchled_write(~rst_msk);
    CPS_DelayNs(10000);
    scratchled_write(0xFF);
}

/* helpers */
void delay_us(unsigned int us) {
    unsigned int i;

    for (i=0; i<us; i++)
      CPS_DelayNs(1000);
}

void delay_ms(unsigned int ms) {
    unsigned int i;

    for (i=0; i<ms; i++)
      delay_us(1000);
}

int setup_device_descriptors(I3C_DeviceDescriptor** device_descriptors, int* device_descriptors_number,
           fn_test_i3c_device** all_test_devices, int number_of_all_test_devices){


    int i3c_device_descriptor_iterator = 0;


    *device_descriptors_number = number_of_all_test_devices;

    *device_descriptors = (I3C_DeviceDescriptor*)malloc(sizeof(I3C_DeviceDescriptor) * *device_descriptors_number);

    if (*device_descriptors == NULL) {
        return CDN_ENOMEM;
    }

    memset(*device_descriptors, 0, sizeof(I3C_DeviceDescriptor) * *device_descriptors_number);

    for(i3c_device_descriptor_iterator = 0;
  i3c_device_descriptor_iterator < *device_descriptors_number;
  ++i3c_device_descriptor_iterator) {


  fn_test_i3c_device* current_device = all_test_devices[i3c_device_descriptor_iterator];

  if (current_device->has_static_address == 1) {
      (*device_descriptors)[i3c_device_descriptor_iterator].addr =
    current_device->static_address;
  } else {
      (*device_descriptors)[i3c_device_descriptor_iterator].addr =
    current_device->dynamic_address;
  }
  (*device_descriptors)[i3c_device_descriptor_iterator].hdrCapable =
        current_device->hdr_capable;
  (*device_descriptors)[i3c_device_descriptor_iterator].isActive =
      current_device->is_active;
  (*device_descriptors)[i3c_device_descriptor_iterator].legacyI2CDev =
        current_device->is_legacy_i2c_device;
  (*device_descriptors)[i3c_device_descriptor_iterator].i2c10bAddr =
          current_device->is_i2c_10b_addr;
  (*device_descriptors)[i3c_device_descriptor_iterator].i2cFmPlusSpeed =
          current_device->is_i2c_fm_plus;
    }

    return 0;
}


int initialize_master(I3C_OBJ *master_driver,
          I3C_DeviceDescriptor* device_descriptors,
          int device_descriptors_number,
          fn_test_i3c_device** all_test_devices,
          int number_of_all_test_devices)
{
    int status = 0;

    I3C_Config cfg = { 0 };
    I3C_SysReq req = { 0 };
    I3C_Callbacks callbacks = {
    .cmdResponseThreshold = cmd_response_threshold_cb,
    .cmdDescriptorThreshold = cmd_descriptor_threshold_cb,
    .txFifoThreshold = tx_threshold_cb,
    .rxFifoThreshold = rx_threshold_cb,
    .ibiResponseThreshold = ibi_response_threshold_cb,
    .ibiDataThreshold = ibi_data_threshold_cb,
    .immComplete = immediate_command_complete_cb,
    .mastershipDone = mastership_done_cb,
    .halted = halted_cb,
    .commandBufferEmpty = cmd_buffer_empty_cb,
    .commandComplete = command_complete_cb,
    .daaComplete = daa_complete_cb,
    .mastershipRequest = mastership_request_cb,
    .hotjoin = hot_join_cb,
    .inbandInterrupt = inband_interrupt_cb
  };

    fn_test_i3c_device* master_0_primary = all_test_devices[0]; /* TODO bfolta: extract to function */

    cfg.devs = device_descriptors;
    cfg.numDevs = device_descriptors_number;

    cfg.regsBase = (MIPI_I3cRegs*)(master_0_primary->registers_base);
    // Frequency of the system clock
    cfg.sysClk = 50000000;
    // Frequency of the bus clock for i2c transfers
    cfg.i2cFreq = 400000;
    // Frequency of the bus clock for i3c transfers
    cfg.sdrFreq = 10000000;
    // Required SCL low period
    cfg.sclLowPeriod = 200;
    // Maximal frequesny supported by slave
    cfg.maxSclFreq = 8000000;
    // Size of the command queue (must not exceed
    // CDNSI3C_MASTER_CMD_QUEUE_DEPTH parameter of master controller
    // instance)
    cfg.cmdFifoSize = 4;
    /* Threshold level for command FIFO */
    cfg.cmdFifoThreshold = 2;
    // size of the hardware tx buffer
    cfg.txFifoSize = 128;
    // size of the hardware rx buffer
    cfg.rxFifoSize = 128;
    /* Threshold configuration - set threshold levels. */
    cfg.thresholdConfig = (I3C_ThresholdConfig) {
    .txFifoThreshold = 32,
    .rxFifoThreshold = 32,
    .cmdrFifoThreshold = 1,
    .ibirFifoThreshold = 1
    };
    /* Interrupt configuration - which interrupts should be enabled */
    cfg.interruptConfig = (I3C_InterruptConfig) {
    .cmdResponseOverflow = true,
    .cmdResponseThreshold = true,
    .cmdResponseUnderflow = true,

    .cmdDescriptorOverflow = true,
    .cmdDescriptorThreshold = true,
    .cmdDescriptorEmpty = true,

    .ibiResponseOverflow = true,
    .ibiResponseThreshold = true,
    .ibiResponseUnderflow = true,

    .ibiDataUnderflow = true,
    .ibiDataThreshold = true,

    .txDataFifoOverflow = true,
    .rxDataFifoUnderflow = true,
    .txFifoThreshold = true,
    .rxFifoThreshold = true,

    .immComplete = true,
    .mastershipDone = true,
    .halted = true,
  };
    // Probe memory requirements and allocate driver memory
    // I3C_SysReq req = { 0 }
    master_driver->probe(&cfg, &req);
    master_0_primary->private_data = (I3C_PrivData*)malloc(req.memReq);

    if (!master_0_primary->private_data) {
  status++;
  cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed to allocate driver private data.\n");
    }



    // Initialize driver
    if (master_driver->init(master_0_primary->private_data, &cfg, &callbacks)) {
  status++;
  cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed to initialize driver.\n");
    }

    //bus_report(cfg.numDevs);

    // Enable driver interrupt service routines
    status += master_driver->start(master_0_primary->private_data);

    print_status_before_return(status, __func__);
    return status;

}


int initialize_secondary_master(I3C_OBJ *master_driver,
        I3C_DeviceDescriptor* device_descriptors,
        int device_descriptors_number,
        fn_test_i3c_device* secondary_master)
{
    int status = 0;

    I3C_Config cfg = { 0 };
    I3C_SysReq req = { 0 };
    I3C_Callbacks callbacks = {
    .slaveSdrRdComplete = slv_sdr_read_comp_cb,
    .slaveSdrWrComplete = slv_sdr_write_comp_cb,
    .slaveDdrRdComplete = slv_ddr_read_comp_cb,
    .slaveDdrWrComplete = slv_ddr_write_comp_cb,
    .slaveIBIDone = slv_ibi_done_cb,
    .slaveSdrError = slv_sdrError_cb,
    .testMode = slv_test_mode_cb,
    .slaveMwlChange = slv_mwlChange_cb,
    .slaveMrlChange = slv_mrlChange_cb,
    .slaveBusconUp  = slv_busconUp_cb,
    .slaveFlushDone = slv_flushDone_cb,
    .slaveResetDaa  = slv_resetDaa_cb
    };

    I3C_SlaveInterruptConfig intCfg = {
    .sdrWrComplete = true,
    .sdrRdComplete = true,
    .ddrWrComplete = true,
    .ddrRdComplete = true,
    .sdrTxDataFifoOverflow = true,
    .sdrRxDataFifoUnderflow = true,
    .ddrTxDataFifoOverflow = true,
    .ddrRxDataFifoUnderflow = true,
    .sdrTxFifoThreshold = true,
    .sdrRxFifoThreshold = true,
    .ddrTxFifoThreshold = true,
    .ddrRxFifoThreshold = true,
    .masterReadAbort = true,
    .ddrFail = true,
    .sdrFail = true,
    .dynamicAddrUpdated = true,
    .ibiDone = true,
    .ibiNack = true,
    .hotJoinDone = true,
    .hotJoinNack = true,
    .eventUpdate = true,
    .protocolError = true,
    .testMode = true,
    .mwl_up = true,
    .mrl_up = true,
    .resetDaa = true,
    .buscon_up = true,
    .flush_done = true
    };

    cfg.devs = device_descriptors;
    cfg.numDevs = device_descriptors_number;

    cfg.regsBase = (MIPI_I3cRegs*)(secondary_master->registers_base);
    // Frequency of the system clock
    cfg.sysClk = 50000000;
    // Frequency of the bus clock for i2c transfers
    cfg.i2cFreq = 100000;
    // Frequency of the bus clock for i3c transfers
    cfg.sdrFreq = 10000000;
    // Required SCL low period
    cfg.sclLowPeriod = 200;
    // Maximal frequesny supported by slave
    cfg.maxSclFreq = 8000000;
    // Size of the command queue (must not exceed
    // CDNSI3C_MASTER_CMD_QUEUE_DEPTH parameter of master controller
    // instance)
    cfg.cmdFifoSize = 10;
    // size of the software tx buffer
    cfg.txFifoSize = 256;
    // size of the software rx buffer
    cfg.rxFifoSize = 256;

    cfg.thresholdConfig = (I3C_ThresholdConfig) {
    .txFifoThreshold = 256,
    .rxFifoThreshold = 256
    };

    // Probe memory requirements and allocate driver memory
    master_driver->probe(&cfg, &req);
    secondary_master->private_data = (I3C_PrivData*)malloc(req.memReq);

    if (!secondary_master->private_data) {
  status++;
  cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed to allocate driver private data.\n");
    }

    // Initialize driver
    if (master_driver->init(secondary_master->private_data, &cfg, &callbacks)) {
  status++;
  cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed to initialize driver.\n");
    }

    //bus_report(cfg.numDevs);

    // Enable driver interrupt service routines
    status += master_driver->start(secondary_master->private_data);
    status += master_driver->slaveModeConfigure(secondary_master->private_data, &intCfg);

    print_status_before_return(status, __func__);
    return status;

}

int initialize_slave(I3CS_OBJ *slave_driver,
         fn_test_i3c_device* slave)
{
    int status = 0;

    I3CS_SysReq req = { 0 };
    I3CS_Config cfg = { 0 };
    I3CS_Callbacks callbacks = { 0 };

    uint32_t reg_val;

    /** Base address of the register space. */
    cfg.regsBase = (MIPI_I3cRegs*)slave->registers_base;
    /** Maximum number of bytes that can be put in the TX FIFO. */
    cfg.txFifoSize = 128;
    /** Maximum number of bytes that can be put in the RX FIFO. */
    cfg.rxFifoSize = 128;
    /** Determines if the SDR FIFOs are implemented. */
    cfg.hasSdrFifos = 1;
    /** Determines if the DDR FIFOs are implemented. */
    cfg.hasDdrFifos = 1;
    /** Specifies the number of the 8-bit APB RW CSRs. Value for this field must be multiple of four. */
    cfg.numApbRwCsrs = 0;
    /** Specifies the number of the 8-bit APB RO CSRs. Value for this field must be multiple of four. */
    cfg.numApbRoCsrs = 0;
    /** Specifies the number of the 8-bit GPI CSRs. Value for this field must be multiple of four. */
    cfg.numGpiCsrs = 20;
    /** Specifies the number of the 8-bit GPO CSRs. Value for this field must be multiple of four. */
    cfg.numGpoCsrs = 20;
    /** Specifies the maximum Payload size in bytes for In-Band Interrupt. */
    cfg.maxIbiPayloadSize= 10;
    /** Specifies maximum sustained read data rate. */
    cfg.maxRd = 5;
    /** Specifies maximum sustained write data rate. */
    cfg.maxWr = 5;
    /** Specifies clock to data turnarround time. */
    cfg.clkToData = 5;

    slave_driver->probe(&cfg, &req);
    slave->private_data = (I3CS_PrivData*)malloc(req.memReq);

    if (!slave->private_data) {
  status++;
  cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed to allocate driver private data.\n");
    }

    if (slave_driver->init(slave->private_data, &cfg, &callbacks)) {
  status++;
  cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed to initialize driver.\n");
    }

    if (slave_driver->start(slave->private_data)) {
  status++;
  cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "Error. Failed to start driver.\n");
    }

    print_status_before_return(status, __func__);
    return 0;
}

int initialize_other_test_devs(I3C_OBJ *master_driver,
             I3CS_OBJ *slave_driver,
             I3C_DeviceDescriptor* device_descriptors,
             int device_descriptors_number,
             fn_test_i3c_device** all_test_devices,
             int number_of_all_test_devices)
{
    int status = 0;
    int i;

    for (i = 0; i <  number_of_all_test_devices; ++i) {
  switch (all_test_devices[i]->role) {
  case I3C_ROLE_SECONDAY_MASTER:
      initialize_secondary_master(master_driver,
          device_descriptors,
          device_descriptors_number,
          all_test_devices[i]);
      break;
  case I3C_ROLE_SLAVE:
      initialize_slave(slave_driver,
           all_test_devices[i]);
      break;
  default:
      break;
  }

    }

    // I2C has to be always initialized. This enables glitch filter
    initialize_slave_i2c(&i2c_slave_fm);

    return status;
}

void initialize_slave_i2c(fn_test_i3c_device* i2c_dev)
{
    CPS_UncachedWrite32(i2c_dev->registers_base + 0x2C, 0x00000005); // glitch filter
    CPS_UncachedWrite32(i2c_dev->registers_base + 0x00, 0x0000040D); // ack+norm+slv+rd
    CPS_UncachedWrite32(i2c_dev->registers_base + 0x24, 0x0000FFFF); // en all interrupts
    CPS_UncachedWrite32(i2c_dev->registers_base + 0x08, i2c_dev->static_address); // normal mode slv addr
}

void initialize_bus_non_imm_cmds(I3C_OBJ *drv,
         fn_test_i3c_device** all_test_devices,
         int number_of_all_test_devices)
{
    int status = 0;

    I3C_BusMode bm;
    int i;
    uint8_t bcr;
    uint8_t dcr;
    uint8_t pid[8];
    int timeout = 10000;
    I3C_TransmissionParameters params = { 0 };

    fn_test_i3c_device* primary_master = all_test_devices[0];

    drv->setBusMode(primary_master->private_data,I3C_BUS_MODE_MIXED_FAST);
    drv->enableCore(primary_master->private_data);
    drv->getBusMode(primary_master->private_data,&bm);

    /* Assign dynamic addresses to slaves with static addresses - SETDASA CCC */
    for (i = 1; i <  number_of_all_test_devices; ++i) {
  /* i starts from 1 because we want to ommit primary master */
  if (all_test_devices[i]->has_static_address == 1) {

      global_i3c_status.cmd_buffer_empty = false;
      status += drv->cmdSetDaFromSa(primary_master->private_data,
            all_test_devices[i]->dynamic_address,
            all_test_devices[i]->static_address,
            &params);
      status += drv->cmdExec(primary_master->private_data);

      status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

      status += drv->cmdAddGetBcr(primary_master->private_data,
          &bcr,
          all_test_devices[i]->dynamic_address,
          &params);
      status += drv->cmdAddGetDcr(primary_master->private_data,
          &dcr,
          all_test_devices[i]->dynamic_address,
          &params);
      status += drv->cmdAddGetProvisionalId(primary_master->private_data,
          pid,
          all_test_devices[i]->dynamic_address,
          &params);

      drv->enableMcs(primary_master->private_data);
      status += drv->cmdExec(primary_master->private_data);
      drv->manualCommandStart(primary_master->private_data);

      status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

      cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s, setBcr\n", __func__);
      status += drv->setBcr(primary_master->private_data, bcr, i);
      cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s, setDcr\n", __func__);
      status += drv->setDcr(primary_master->private_data, dcr, i);
      cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s, setPid\n", __func__);
      status += drv->setPid(primary_master->private_data, pid, i);
  }
    }

    /* ENTDAA CCC */
    cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s, cmdAddEnterDaa\n", __func__);
    timeout = 10000;
    status += drv->cmdClearAll(primary_master->private_data);
    status += drv->cmdAddEnterDaa(primary_master->private_data, &params);
    status += drv->cmdExec(primary_master->private_data);

    /* waiting for all transfers to be finished*/
    status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

    drv->devPrint(primary_master->private_data);

    print_status_before_return(status, __func__);
    return status;
}

void initialize_bus_imm_cmds(I3C_OBJ *drv,
          fn_test_i3c_device** all_test_devices,
          int number_of_all_test_devices)
{
    int status = 0;

    I3C_BusMode bm;
    int i;
    uint8_t bcr;
    uint8_t dcr;
    uint8_t pid[8];
    int timeout = 10000;
    I3C_TransmissionParameters paramsImm = {
      .immediate = true
    };
    I3C_TransmissionParameters params = { 0 };

    fn_test_i3c_device* primary_master = all_test_devices[0];

    drv->setBusMode(primary_master->private_data,I3C_BUS_MODE_MIXED_FAST);
    drv->enableCore(primary_master->private_data);
    drv->getBusMode(primary_master->private_data,&bm);

    /* Assign dynamic addresses to slaves with static addresses - SETDASA CCC */
    for (i = 1; i <  number_of_all_test_devices; ++i) {
  /* i starts from 1 because we want to ommit primary master */
  if (all_test_devices[i]->has_static_address == 1) {
      cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s, cmdSetDaFromSa\n", __func__);

      status += drv->cmdSetDaFromSa(primary_master->private_data,
            all_test_devices[i]->dynamic_address,
            all_test_devices[i]->static_address,
            &paramsImm);
      status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));

      timeout = 10000;
      cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s, cmdAddGetBcr\n", __func__);
      status += drv->cmdAddGetBcr(primary_master->private_data,
          &bcr,
          all_test_devices[i]->dynamic_address,
          &paramsImm);
      status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));

      status += drv->cmdAddGetDcr(primary_master->private_data,
          &dcr,
          all_test_devices[i]->dynamic_address,
          &paramsImm);
      status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));

      status += drv->cmdAddGetProvisionalId(primary_master->private_data,
          pid,
          all_test_devices[i]->dynamic_address,
          &params);
      status += drv->cmdExec(primary_master->private_data);

      status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

      cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s, setBcr\n", __func__);
      status += drv->setBcr(primary_master->private_data, bcr, i);
      cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s, setDcr\n", __func__);
      status += drv->setDcr(primary_master->private_data, dcr, i);
      cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s, setPid\n", __func__);
      status += drv->setPid(primary_master->private_data, pid, i);
  }
    }

    /* ENTDAA CCC */
    cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s, cmdAddEnterDaa\n", __func__);
    timeout = 10000;
    status += drv->cmdClearAll(primary_master->private_data);
    status += drv->cmdAddEnterDaa(primary_master->private_data, &paramsImm);

    /* waiting for all transfers to be finished*/
    status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));

    print_status_before_return(status, __func__);
    return status;
}

void initialize_bus_imm_non_imm_mix(I3C_OBJ *drv,
            fn_test_i3c_device** all_test_devices,
            int number_of_all_test_devices)
{
    int status = 0;

    I3C_BusMode bm;
    int i;
    uint8_t bcr;
    uint8_t dcr;
    uint8_t pid[8];
    int timeout = 10000;
    I3C_TransmissionParameters paramsImm = {
    .immediate = true
  };
  I3C_TransmissionParameters params = { 0 };

    fn_test_i3c_device* primary_master = all_test_devices[0];

    drv->setBusMode(primary_master->private_data,I3C_BUS_MODE_MIXED_FAST);
    drv->enableCore(primary_master->private_data);
    drv->getBusMode(primary_master->private_data,&bm);

    /* Assign dynamic addresses to slaves with static addresses - SETDASA CCC */
    for (i = 1; i <  number_of_all_test_devices; ++i) {
  /* i starts from 1 because we want to ommit primary master */
  if (all_test_devices[i]->has_static_address == 1) {
      cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s, cmdSetDaFromSa\n", __func__);

      timeout = 10000;
      status += drv->cmdSetDaFromSa(primary_master->private_data,
            all_test_devices[i]->dynamic_address,
            all_test_devices[i]->static_address,
            &paramsImm);

      status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));

      status += drv->cmdAddGetBcr(primary_master->private_data,
          &bcr,
          all_test_devices[i]->dynamic_address,
          &params);
      status += drv->cmdAddGetDcr(primary_master->private_data,
          &dcr,
          all_test_devices[i]->dynamic_address,
          &params);
      status += drv->cmdAddGetProvisionalId(primary_master->private_data,
          pid,
          all_test_devices[i]->dynamic_address,
          &params);
      status += drv->cmdExec(primary_master->private_data);

      status += wait_for_global_status(&(global_i3c_status.cmd_buffer_empty));

      cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s, setBcr\n", __func__);
      status += drv->setBcr(primary_master->private_data, bcr, i);
      cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s, setDcr\n", __func__);
      status += drv->setDcr(primary_master->private_data, dcr, i);
      cDbgMsg(DBG_GEN_MSG, DBG_HIVERB, "%s, setPid\n", __func__);
      status += drv->setPid(primary_master->private_data, pid, i);
  }
    }

    /* ENTDAA CCC */
    cDbgMsg(DBG_GEN_MSG, DBG_CRIT, "%s, cmdAddEnterDaa\n", __func__);
    timeout = 10000;
    status += drv->cmdClearAll(primary_master->private_data);
    status += drv->cmdAddEnterDaa(primary_master->private_data, &paramsImm);

    status += wait_for_global_status(&(global_i3c_status.immediate_command_complete));

    print_status_before_return(status, __func__);
    return status;
}
