/*(C) 2023 Cadence Design Systems, Inc. 
This file is licensed under the Cadence Public License Version 1.0 (the “License”), a copy of which is available at https://www.cadence.com/content/dam/cadence-www/global/en_US/documents/terms-and-conditions/Cadence-Public-License-Version-1.0.pdf, and is distributed "AS IS." TO THE  MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, CADENCE DISCLAIMS ALL WARRANTIES AND IN NO EVENT SHALL BE LIABLE TO ANY PARTY FOR ANY DAMAGES ARISING OUT OF OR RELATING TO USE OF THIS FILE. Please see the License for the full text of applicable terms.
*
**********************************************************************
* WARNING: This file is auto-generated using api-generator utility.
*          api-generator: 13.06.f48696b
*          Do not edit it manually.
**********************************************************************
* Cadence Core Driver for I3C Master Interface
**********************************************************************/
#ifndef I3C_OBJ_IF_H
#define I3C_OBJ_IF_H

#include "i3c_if.h"
#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup DriverObject Driver API Object
 *  API listing for the driver. The API is contained in the object as
 *  function pointers in the object structure. As the actual functions
 *  resides in the Driver Object, the client software must first use the
 *  global GetInstance function to obtain the Driver Object Pointer.
 *  The actual APIs then can be invoked using obj->(api_name)() syntax.
 *  These functions are defined in the header file of the core driver
 *  and utilized by the API.
 *  @{
 */

/**********************************************************************
* API methods
**********************************************************************/

/* parasoft-begin-suppress MISRA2012-DIR-4_8-4 "Consider hiding the implementation of the structure, DRV-4932" */
typedef struct I3C_OBJ_s
{
    /**
     * Returns the memory requirements for a driver instance.
     * @param[in] config Driver and hardware configuration.
     * @param[out] sysReq Returns the memory requirements for given configuration.
     * @return 0 On success.
     * @return EINVAL If config contains invalid values or not supported configuration.
     */
    uint32_t (*probe)(const I3C_Config* config, I3C_SysReq* sysReq);

    /**
     * Instantiates the I3C Core Driver, given the required blocks of
     * memory (this includes initializing the instance and the underlying
     * hardware). If a client configuration is required (likely to always
     * be true), it is passed in also. Returns an instance pointer, which
     * the client must maintain and pass to all other driver functions.
     * (except probe).
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] config Specifies driver/hardware configuration.
     * @param[in] callbacks Event Handlers and Callbacks.
     * @return CDN_EOK On success
     * @return CDN_EINVAL If illegal/inconsistent values in 'config' doesn't support feature(s) required by 'config' parameters.
     * @return CDN_EIO if operation failed
     */
    uint32_t (*init)(I3C_PrivData* pd, const I3C_Config* config, const I3C_Callbacks* callbacks);

    /**
     * I3C Core Driver's ISR. Platform-specific code is responsible for
     * ensuring this gets called when the corresponding hardware's
     * interrupt is asserted. Registering the ISR should be done after
     * calling init, and before calling start. The driver's ISR will not
     * attempt to lock any locks, but will perform client callbacks. If
     * the client wishes to defer processing to non-interrupt time, it is
     * responsible for doing so. This function must not be called after
     * calling destroy and releasing private data memory.
     * @param[in] pd Pointer to driver's private data object filled by init.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*isr)(I3C_PrivData* pd);

    /**
     * Start the I3C driver, enabling interrupts. This is called after
     * the client has successfully initialized the driver and hooked the
     * driver's ISR (the isr member of this struct) to the IRQ.
     * @param[in] pd Pointer to driver's private data object.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*start)(I3C_PrivData* pd);

    /**
     * The client may call this to disable the hardware (disabling its
     * IRQ at the source and disconnecting it if applicable). Also, a
     * best-effort is made to cancel any pending transactions.
     * @param[in] pd Pointer to driver's private data object.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*stop)(I3C_PrivData* pd);

    /**
     * This performs an automatic stop and then de-initializes the
     * driver. The client may not make further requests on this instance.
     * @param[in] pd Pointer to driver's private data object.
     * @return CDN_EOK on success
     * @return CDN_EIO if operation failed
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*destroy)(I3C_PrivData* pd);

    /**
     * Enables the I3C Master Core.
     * @param[in] pd Pointer to driver's private data object.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*enableCore)(I3C_PrivData* pd);

    /**
     * Waits for all operations to be completed and then it disables the
     * I3C Master Core.
     * @param[in] pd Pointer to driver's private data object.
     * @return CDN_EOK on success
     * @return CDN_EIO if operation failed
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*disableCore)(I3C_PrivData* pd);

    /**
     * Sets Bus Mode.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] mode Bus Mode.
     * @return CDN_EOK on success
     * @return CDN_EIO if operation failed
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*setBusMode)(I3C_PrivData* pd, I3C_BusMode mode);

    /**
     * Reads Bus Mode.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] mode Pointer to Bus Mode object.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*getBusMode)(I3C_PrivData* pd, I3C_BusMode* mode);

    /**
     * Sets BCR value in one of the retaining registers (DeviceIDx).
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] bcr BCR value.
     * @param[in] devId Retaining register number.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*setBcr)(I3C_PrivData* pd, uint8_t bcr, uint8_t devId);

    /**
     * Sets DCR value in one of the retaining registers (DeviceIDx).
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] dcr DCR value.
     * @param[in] devId Retaining register number.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*setDcr)(I3C_PrivData* pd, uint8_t dcr, uint8_t devId);

    /**
     * Sets Provisional ID value in one of the retaining registers
     * (DeviceIDx).
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] pid Ponter to buffer containing 48-bit Provisional ID value.
     * @param[in] devId Retaining register number.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*setPid)(I3C_PrivData* pd, const uint8_t* pid, uint8_t devId);

    /**
     * Configures Devices connected to the I3C Bus (including Master)
     * accordingly to the capabilities of these Devices. Configuration of
     * the Devices must be provided in following order: Master, I3C
     * Slaves with Dynamic Address support, I3C Slaves with static
     * addresses and at the end Legacy I2C Devices. Position of the
     * Device configuration in each group determines priority of the
     * Device. Configuration of at least two Devices (including Master)
     * need to be provided. I3C Master Core must be disabled before
     * calling this function.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] devs Pointer to the structure containing configuration and capabilities of the Devices.
     * @param[in] numDevs Total number of the Devices.
     * @return CDN_EOK on success
     * @return CDN_EIO if operation failed
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*configureDevices)(I3C_PrivData* pd, I3C_DeviceDescriptor* devs, uint8_t numDevs);

    /**
     * Configures Device connected to the I3C Bus (including Master)
     * accordingly to the capabilities of this device. I3C Master Core
     * must be disabled before calling this function.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] dev Pointer to the structure containing configuration and capabilities of the Device.
     * @param[in] index Index of the device corresponding to index of devs array (field of the I3C_PrivData structure).
     * @return CDN_EOK on success
     * @return CDN_EIO if operation failed
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*configureDevice)(I3C_PrivData* pd, I3C_DeviceDescriptor* dev, uint8_t index);

    /**
     * Calculates prescaler values for Legacy I2C and SDR frequencies.
     * Please make sure core is disabled.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] config Specifies driver/hardware configuration.
     * @return CDN_EOK on success
     * @return CDN_EIO if operation failed
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*configurePrescalers)(I3C_PrivData* pd, const I3C_Config* config);

    /**
     * This function clears retaining registers set for a chosen device.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] device_no Number corresponding to Device position in retaining register.
     * @return CDN_EOK on success
     * @return CDN_EIO if operation failed
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*clearRrOfDevice)(I3C_PrivData* pd, uint8_t device_no);

    /**
     * Returns devices which joined (by HJ) the bus since last check.
     * @param[in] pd Pointer to driver's private data object.
     * @param[out] hj_devices This mask indicates which devices joined the bus.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*getNewDevices)(I3C_PrivData* pd, uint16_t* hj_devices);

    /**
     * Enables interrupts chosen by user.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] interruptConfig Interrupt configuration.
     * @return CDN_EOK on success
     * @return CDN_EIO if operation failed
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*configureInterrupts)(I3C_PrivData* pd, const I3C_InterruptConfig* interruptConfig);

    /**
     * Sets thresholds to levels selected by user.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] thresholdConfig Threshold configuration.
     * @return CDN_EOK on success
     * @return CDN_EIO if operation failed
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*configureThresholds)(I3C_PrivData* pd, const I3C_ThresholdConfig* thresholdConfig);

    /**
     * Executes all queued Commands.
     * @param[in] pd Pointer to driver's private data object.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     * @return CDN_EBUSY if Commands are already being processed
     * @return CDN_EOPNOTSUPP if Command list is empty
     */
    uint32_t (*cmdExec)(I3C_PrivData* pd);

    /**
     * Executes Immediate Command.
     * @param[in] pd Pointer to driver's private data object.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*cmdExecImmediate)(I3C_PrivData* pd);

    /**
     * Enables Manual Command Start.
     * @param[in] pd Pointer to driver's private data object.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*enableMcs)(I3C_PrivData* pd);

    /**
     * Disabled Manual Command Start.
     * @param[in] pd Pointer to driver's private data object.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*disableMcs)(I3C_PrivData* pd);

    /**
     * Executes commands stored in HW.
     * @param[in] pd Pointer to driver's private data object.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*manualCommandStart)(I3C_PrivData* pd);

    /**
     * Returns number of queued Commands.
     * @param[in] pd Pointer to driver's private data object.
     * @return 0 if input parameters are invalid or if there are no queued Commands
     */
    uint32_t (*cmdCount)(const I3C_PrivData* pd);

    /**
     * Returns maximum number of Commands that can be put in queue.
     * @param[in] pd Pointer to driver's private data object.
     * @return 0 if input parameters are invalid or if there are no queued Commands
     */
    uint32_t (*cmdMaxCount)(const I3C_PrivData* pd);

    /**
     * Clears Commands queue.
     * @param[in] pd Pointer to driver's private data object.
     * @return CDN_EINVAL if input parameters are invalid
     * @return CDN_EOK on success
     */
    uint32_t (*cmdClearAll)(I3C_PrivData* pd);

    /**
     * Prints info on I3C devices on the bus.
     * @param[in] pd Pointer to driver's private data object.
     * @return CDN_EINVAL if input parameters are invalid
     * @return CDN_EOK on success
     */
    uint32_t (*devPrint)(const I3C_PrivData* pd);

    /**
     * Enables decoding of timing information in Master.
     * @param[in] pd Pointer to driver's private data object.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*enableTc)(I3C_PrivData* pd);

    /**
     * Adds SDR Mode private Write Command to the Commands queue.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] da Device Address to which data will be transferred.
     * @param[in] csr_data CSR information with CSR address and address lenght.
     * @param[in] payload_data Pointer to structure with payload information
     * @param[in] xmitMmode Transmission Mode.
     * @return CDN_EINVAL if input parameters are invalid
     * @return CDN_EBUSY if there is no space for new Command or payload
     * @return CDN_EOK on success
     */
    uint32_t (*cmdAddPrivWrite)(I3C_PrivData* pd, uint16_t da, const I3C_CsrData* csr_data, const I3C_PayloadData* payload_data, I3C_TransmitMode xmitMmode);

    /**
     * Adds SDR Mode private Read Command to the Commands queue.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] da Device Address from which data will be transferred.
     * @param[in] csr_data CSR information with CSR address and address lenght.
     * @param[in] payload_data Pointer to structure with payload information
     * @param[in] xmitMmode Transmission Mode.
     * @return CDN_EINVAL if input parameters are invalid
     * @return CDN_EBUSY if there is no space for new Command or payload
     * @return CDN_EOK on success
     */
    uint32_t (*cmdAddPrivRead)(I3C_PrivData* pd, uint16_t da, const I3C_CsrData* csr_data, const I3C_PayloadData* payload_data, I3C_TransmitMode xmitMmode);

    /**
     * Adds Legacy I2C SDR Mode private Write Command to the Commands
     * queue.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] da Device Address to which data will be transferred.
     * @param[in] payload Pointer to buffer containing payload to be sent.
     * @param[in] payloadSize Size of the payload [B].
     * @return CDN_EINVAL if input parameters are invalid
     * @return CDN_EBUSY if there is no space for new Command or payload
     * @return CDN_EOK on success
     */
    uint32_t (*cmdAddPrivI2CWrite)(I3C_PrivData* pd, uint16_t da, uint8_t* payload, uint16_t payloadSize);

    /**
     * Adds Legacy I2C SDR Mode private Read Command to the Commands
     * queue.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] da Device Address from which data will be transferred.
     * @param[in] payload Pointer to buffer containing payload to be sent.
     * @param[in] payloadSize Size of the payload [B].
     * @return CDN_EINVAL if input parameters are invalid
     * @return CDN_EBUSY if there is no space for new Command or payload
     * @return CDN_EOK on success
     */
    uint32_t (*cmdAddPrivI2CRead)(I3C_PrivData* pd, uint16_t da, uint8_t* payload, uint16_t payloadSize);

    /**
     * Adds DDR Mode private Write Command to the Commands queue. I3C
     * Core Driver will automatically calculate CRC, Preambles and Parity
     * Bits for the DDR Command and its Payload.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] da Device Address to which data will be transferred.
     * @param[in] command DDR Command.
     * @param[in] hdrMode Specifies which one of the HDR modes to use.
     * @param[in] payload_data Pointer to structure with payload information
     * @return CDN_EINVAL if input parameters are invalid
     * @return CDN_EBUSY if there is no space for new Command or payload
     * @return CDN_EOK on success
     */
    uint32_t (*cmdAddDdrWrite)(I3C_PrivData* pd, uint8_t da, uint8_t command, I3C_HdrMode hdrMode, I3C_PayloadData* payload_data);

    /**
     * Adds DDR Mode private Read Command to the Commands queue. I3C Core
     * Driver will automatically check CRC, Preambles and Parity Bits for
     * the DDR Command and its Payload.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] da Device Address from which data will be transferred.
     * @param[in] command DDR Command.
     * @param[in] hdrMode Specifies which one of the HDR modes to use.
     * @param[in] payload_data Pointer to structure with payload information
     * @return CDN_EINVAL if input parameters are invalid
     * @return CDN_EBUSY if there is no space for new Command or payload
     * @return CDN_EOK on success
     */
    uint32_t (*cmdAddDdrRead)(I3C_PrivData* pd, uint8_t da, uint8_t command, I3C_HdrMode hdrMode, I3C_PayloadData* payload_data);

    /**
     * Adds to queue Command to that sends message to I3C Device (or to
     * all I3C Devices in case of a broadcast) which event interrupts
     * should be enabled or disabled.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] eventsMask Mask of Events to be enabled or disabled.
     * @param[in] enable If true, specified events will be enabled; if false, specified events will be disabled.
     * @param[in] devAddr Address of the I3C Device in case of Direct Message.
     * @param[in] tx_params Transmission parameters - command descriptors
     * @return CDN_EOK on success
     * @return CDN_EPROTO if slave event mask is not valid
     * @return CDN_EINVAL if input parameters are invalid
     * @return CDN_EBUSY if there is no space for new Command or payload
     */
    uint32_t (*cmdAddSetSlaveEvents)(I3C_PrivData* pd, uint8_t eventsMask, bool enable, uint8_t devAddr, const I3C_TransmissionParameters* tx_params);

    /**
     * Creates Enter Activity State Command to be sent to the I3C Slaves.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] state Activity State value.
     * @param[in] devAddr Address of the I3C Device in case of Direct Message.
     * @param[in] tx_params Transmission parameters - command descriptor
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     * @return CDN_EBUSY if there is no space for new Command or payload
     */
    uint32_t (*cmdAddEnterActivityState)(I3C_PrivData* pd, I3C_ActivityState state, uint8_t devAddr, const I3C_TransmissionParameters* tx_params);

    /**
     * This function adds CCC for Dynamic Address Assignment process to
     * the Commands queue.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] devAddr Address of the I3C Device in case of Direct Command. This parameter is ignored in case of Broadcast Command.
     * @param[in] tx_params Transmission parameters - command descriptor
     * @return CDN_EOK on success
     * @return CDN_EBUSY if Commands are being processed by the Core Driver
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*cmdAddResetDaa)(I3C_PrivData* pd, uint8_t devAddr, const I3C_TransmissionParameters* tx_params);

    /**
     * This function adds CCC for Dynamic Address Assignment process to
     * the Commands queue.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] tx_params Transmission parameters - command descriptor
     * @return CDN_EOK on success
     * @return CDN_EBUSY if Commands are being processed by the Core Driver
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*cmdAddEnterDaa)(I3C_PrivData* pd, const I3C_TransmissionParameters* tx_params);

    /**
     * This function adds CCC for setting the Maximum Write Length for
     * all or specific device.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] length Maximum Write Length to be set.
     * @param[in] devAddr Address of the I3C Device in case of Direct Message.
     * @param[in] tx_params Transmission parameters - command descriptor
     * @return CDN_EOK on success
     * @return CDN_EBUSY if Commands are being processed by the Core Driver
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*cmdAddSetMaxWriteLength)(I3C_PrivData* pd, uint16_t length, uint8_t devAddr, const I3C_TransmissionParameters* tx_params);

    /**
     * This function adds CCC for obtaining the Maximum Write Length
     * value for a specific device.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] length Pointer to 16-bit variable to which Maximum Write Length will be written.
     * @param[in] devAddr Address of the I3C Device to which Command will be sent.
     * @param[in] tx_params Transmission parameters - command descriptor
     * @return CDN_EOK on success
     * @return CDN_EBUSY if Commands are being processed by the Core Driver
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*cmdAddGetMaxWriteLength)(I3C_PrivData* pd, uint16_t* length, uint8_t devAddr, const I3C_TransmissionParameters* tx_params);

    /**
     * This function adds CCC for setting the Maximum Read Length for all
     * or specific device.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] max_read_length Maximum Read Length to be set.
     * @param[in] length_size Number of bytes required to store Maximum Read Length. Alloved values are 2 or 3.
     * @param[in] devAddr Address of the I3C Device in case of Direct Message.
     * @param[in] tx_params Transmission parameters - command descriptors
     * @return CDN_EOK on success
     * @return CDN_EBUSY if Commands are being processed by the Core Driver
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*cmdAddSetMaxReadLength)(I3C_PrivData* pd, I3C_MaxReadLength max_read_length, uint8_t length_size, uint8_t devAddr, const I3C_TransmissionParameters* tx_params);

    /**
     * This function adds CCC for obtaining the Maximum Read Length value
     * for a specific device.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] max_read_length Pointer to a structure where Maximum Read Length.
     * @param[in] length_size Number of bytes required to store Maximum Read Length. Alloved values are 2 or 3.
     * @param[in] devAddr Address of the I3C Device to which Command will be sent.
     * @param[in] tx_params Transmission parameters - command descriptor
     * @return CDN_EOK on success
     * @return CDN_EBUSY if Commands are being processed by the Core Driver
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*cmdAddGetMaxReadLength)(I3C_PrivData* pd, I3C_MaxReadLength* max_read_length, uint8_t length_size, uint8_t devAddr, const I3C_TransmissionParameters* tx_params);

    /**
     * This function adds CCC for obtaining the Maximum Data Speed (SCL
     * Frequency of the slave)
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] max_data_speed Pointer to structure with max data speeds.
     * @param[in] devAddr Address of the I3C Device to which Command will be sent.
     * @param[in] tx_params Transmission parameters - command descriptor
     * @return CDN_EOK on success
     * @return CDN_EBUSY if Commands are being processed by the Core Driver
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*cmdAddGetMaxDataSpeed)(I3C_PrivData* pd, I3C_MaxDataSpeed* max_data_speed, uint8_t devAddr, const I3C_TransmissionParameters* tx_params);

    /**
     * This function gets information about Slaves present on the bus.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] slaveDescs Pointer the structure of Slave descriptors. Memory will be written with slave count and slave data.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*getSlavesList)(const I3C_PrivData* pd, I3C_SlaveDescriptors* slaveDescs);

    /**
     * This function adds CCC for informing Secondary Masters about
     * Slaves present on the bus.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] slaveDescs Pointer the structure of Slave descriptors.
     * @param[in] tx_params Transmission parameters - command descriptor
     * @return CDN_EOK on success
     * @return CDN_EBUSY if Commands are being processed by the Core Driver
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*cmdAddDefineSlavesList)(I3C_PrivData* pd, I3C_SlaveDescriptors* slaveDescs, const I3C_TransmissionParameters* tx_params);

    /**
     * Prepares CCC broadcast Command for all I3C Devices that the Master
     * is entering specific Test Mode.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] mode Test mode code. 0x00 - Exit Test Mode. 0x01 - Vendor Test Mode. 0x02 - General Test Mode. 0x03-0x0F - MIPI Reserved. 0x10-0xFF - Vendor Definable.
     * @param[in] tx_params Transmission parameters - command descriptor
     * @return CDN_EOK on success
     * @return CDN_EBUSY if Commands are being processed by the Core Driver
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*cmdAddEnterTestMode)(I3C_PrivData* pd, uint8_t mode, const I3C_TransmissionParameters* tx_params);

    /**
     * Prepares CCC broadcast Command for all I3C Devices to set bus
     * context(i3c specification version that bus will use)
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] context_buf Pointer to bus context data
     * @param[in] length_size length of context data
     * @param[in] tx_params Transmission parameters - command descriptor
     * @return CDN_EOK on success
     * @return CDN_EBUSY if Commands are being processed by the Core Driver
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*cmdAddSetBuscon)(I3C_PrivData* pd, uint8_t* context_buf, uint8_t length_size, const I3C_TransmissionParameters* tx_params);

    /**
     * Sends broadcast message to all I3C Devices that the Bus is being
     * switched over to the indicated HDR Mode.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] mode
     * @param[in] tx_params Transmission parameters - command descriptor
     * @return CDN_EOK on success
     * @return CDN_EBUSY if Commands are being processed by the Core Driver
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*cmdAddEnterHdrMode)(I3C_PrivData* pd, I3C_HdrMode mode, const I3C_TransmissionParameters* tx_params);

    /**
     * This function adds CCC for Dynamic Address Assignment using static
     * address to all target devices in broadcast mode.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] tx_params Transmission parameters - command descriptor
     * @return CDN_EOK on success
     * @return CDN_EBUSY if Commands are being processed by the Core Driver
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*cmdAddSetAaSa)(I3C_PrivData* pd, const I3C_TransmissionParameters* tx_params);

    /**
     * Sends Command that addresses specific Device with Dynamic Address
     * using its I2C Address.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] address Dynamic Address to be set.
     * @param[in] devAddr Address of the I3C Device to which Command will be sent.
     * @param[in] tx_params Transmission parameters - command descriptor
     * @return CDN_EOK on success
     * @return CDN_EBUSY if Commands are being processed by the Core Driver
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*cmdSetDaFromSa)(I3C_PrivData* pd, uint8_t address, uint8_t devAddr, const I3C_TransmissionParameters* tx_params);

    /**
     * Sends Command that sets a new Dynamic Address for specific I3C
     * Slave Device.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] da Dynamic Address to be set.
     * @param[in] devAddr Address of the I3C Device to which Command will be sent.
     * @param[in] tx_params Transmission parameters - command descriptor
     * @return CDN_EOK on success
     * @return CDN_EBUSY if Commands are being processed by the Core Driver
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*cmdAddSetNewDa)(I3C_PrivData* pd, uint8_t da, uint8_t devAddr, const I3C_TransmissionParameters* tx_params);

    /**
     * Configure the next reset action for following reset pattern in I3C
     * Device (or in all I3C Devices in case of a broadcast).
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] DefiningByte Value corressponding to reset action.
     * @param[in] devAddr Address of the I3C Device in case of Direct Message.
     * @param[in] tx_params Transmission parameters - command descriptors
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     * @return CDN_EBUSY if there is no space for new Command or payload
     */
    uint32_t (*cmdAddSetRstAct)(I3C_PrivData* pd, uint8_t DefiningByte, uint8_t devAddr, const I3C_TransmissionParameters* tx_params);

    /**
     * Exchange event timing information (for Timing Control Async Mode)
     * with  I3C Device (or with all I3C Devices in case of a broadcast)
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] SubCommandByte Value of sub command code.
     * @param[in] devAddr Address of the I3C Device in case of Direct Message.
     * @param[in] tx_params Transmission parameters - command descriptors
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     * @return CDN_EBUSY if there is no space for new Command or payload
     */
    uint32_t (*cmdAddSetXTime)(I3C_PrivData* pd, uint8_t SubCommandByte, uint8_t devAddr, const I3C_TransmissionParameters* tx_params);

    /**
     * Sends Command that assign a Group Address to an I3C Target
     * supporting the Group Address feature.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] grpaddr Group address value.
     * @param[in] devAddr Address of the I3C Device to which Command will be sent.
     * @param[in] tx_params Transmission parameters - command descriptor
     * @return CDN_EOK on success
     * @return CDN_EBUSY if Commands are being processed by the Core Driver
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*cmdAddSetGroupAddr)(I3C_PrivData* pd, uint8_t grpaddr, uint8_t devAddr, const I3C_TransmissionParameters* tx_params);

    /**
     * This function adds CCC for informing Secondary Masters mode
     * details about a particular Group,including the list of I3C Targets
     * that are m embers of the Group.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] groupDescs Pointer the structure of Group descriptors.
     * @param[in] tx_params Transmission parameters - command descriptor
     * @return CDN_EOK on success
     * @return CDN_EBUSY if Commands are being processed by the Core Driver
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*cmdAddDefineGroupList)(I3C_PrivData* pd, I3C_GroupDescriptors* groupDescs, const I3C_TransmissionParameters* tx_params);

    /**
     * This function add CC to remove one or more I3C target devices from
     * a Group by resetting their assigned Group Address.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] grpAddr value of group address
     * @param[in] devAddr Address of the I3C Device in case of Direct Message.
     * @param[in] tx_params Transmission parameters - command descriptor
     * @return CDN_EOK on success
     * @return CDN_EBUSY if Commands are being processed by the Core Driver
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*cmdAddResetGrpa)(I3C_PrivData* pd, uint8_t grpAddr, uint8_t devAddr, const I3C_TransmissionParameters* tx_params);

    /**
     * This function adds CCC for obtaining provisional ID of device.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] buff Pointer to variable to which 48-bit Provisional ID will be written.
     * @param[in] devAddr Address of the I3C Device to which Command will be sent.
     * @param[in] tx_params Transmission parameters - command descriptor
     * @return CDN_EOK on success
     * @return CDN_EBUSY if Commands are being processed by the Core Driver
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*cmdAddGetProvisionalId)(I3C_PrivData* pd, uint8_t* buff, uint8_t devAddr, const I3C_TransmissionParameters* tx_params);

    /**
     * This function adds CCC for obtaining the Bus Characteristics
     * Register.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] bcr Pointer to variable to which 8-bit DCR value will be written.
     * @param[in] devAddr Address of the I3C Device to which Command will be sent.
     * @param[in] tx_params Transmission parameters - command descriptor
     * @return CDN_EOK on success
     * @return CDN_EBUSY if Commands are being processed by the Core Driver
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*cmdAddGetBcr)(I3C_PrivData* pd, uint8_t* bcr, uint8_t devAddr, const I3C_TransmissionParameters* tx_params);

    /**
     * This function adds CCC for obtaining the Device Characteristics
     * Register.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] dcr Pointer to variable to which 8-bit BCR value will be written.
     * @param[in] devAddr Address of the I3C Device to which Command will be sent.
     * @param[in] tx_params Transmission parameters - command descriptor
     * @return CDN_EOK on success
     * @return CDN_EBUSY if Commands are being processed by the Core Driver
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*cmdAddGetDcr)(I3C_PrivData* pd, uint8_t* dcr, uint8_t devAddr, const I3C_TransmissionParameters* tx_params);

    /**
     * This function adds CCC for obtaining status of the I3C Device.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] status Pointer to variable to which 16-bit status value will be written.
     * @param[in] devAddr Address of the I3C Device to which Command will be sent.
     * @param[in] tx_params Transmission parameters - command descriptor
     * @return CDN_EOK on success
     * @return CDN_EBUSY if Commands are being processed by the Core Driver
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*cmdAddGetStatus)(I3C_PrivData* pd, uint16_t* status, uint8_t devAddr, const I3C_TransmissionParameters* tx_params);

    /**
     * This function adds CCC for granting Mastership.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] recData Pointer to data received from device that GETACCMST CCC is sent to. After command execution this should hold address of receiving device.
     * @param[in] devAddr Address of the I3C Device to which Command will be sent.
     * @param[in] tx_params Transmission parameters - command descriptor
     * @return CDN_EOK on success
     * @return CDN_EBUSY if Commands are being processed by the Core Driver
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*cmdAddGetAccMst)(I3C_PrivData* pd, uint8_t* recData, uint8_t devAddr, const I3C_TransmissionParameters* tx_params);

    /**
     * This function adds CCC for obtaining the timing control Aysnc Mode
     * 0 data.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] tCamData Pointer to buf which stores data bytes
     * @param[in] devAddr Address of the I3C Device to which Command will be sent.
     * @param[in] tx_params Transmission parameters - command descriptor
     * @return CDN_EOK on success
     * @return CDN_EBUSY if Commands are being processed by the Core Driver
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*cmdAddGetXTime)(I3C_PrivData* pd, I3C_Tcam0Data* tCamData, uint8_t devAddr, const I3C_TransmissionParameters* tx_params);

    /**
     * This function adds CCC for enabling NCA mode in private write.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] mode Mode value for enabling/disabling data pattern with sub framing.
     * @param[in] devAddr Address of the I3C Device to which Command will be sent.
     * @param[in] tx_params Transmission parameters - command descriptor
     * @return CDN_EOK on success
     * @return CDN_EBUSY if Commands are being processed by the Core Driver
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*CmdSetNCAMode)(I3C_PrivData* pd, uint8_t mode, uint8_t devAddr, const I3C_TransmissionParameters* tx_params);

    /**
     * This function configures devices issuing IBI.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] ibi_sir_cfg Pointer to array that will hold configuration of IBI related devices.
     * @param[in] num_sir_cfgs Size of configuration array.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*ibiConfigureDevices)(const I3C_PrivData* pd, const I3C_IbiSirConfiguration* ibi_sir_cfg, uint32_t num_sir_cfgs);

    /**
     * This function modifies device configuration issuing IBI.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] ibi_sir_cfg Pointer to struct that holds configuration of IBI device.
     * @param[in] da Device DA.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     * @return CDN_ENOENT if device with DA not found
     */
    uint32_t (*ibiModifyDeviceConfig)(const I3C_PrivData* pd, const I3C_IbiSirConfiguration* ibi_sir_cfg, uint8_t da);

    /**
     * This function extracts address of device that issued IBI.
     * @param[in] pd Pointer to driver's private data object.
     * @return 0 on error invalid
     * @return valid I3C address on success
     */
    uint32_t (*ibiGetAddressOfIssuer)(I3C_PrivData* pd);

    /**
     * This function extracts IBI payload.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] buf Pointer to buffer that will hold received payload.
     * @param[in] payload_size Size of payload.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*ibiGetData)(I3C_PrivData* pd, uint8_t* buf, uint16_t payload_size);

    /**
     * This function configures response of I3C conftroller to Hot Join
     * request.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] hj_response Should I3C controller ACK or NACK Hot Join request.
     * @param[in] hj_disable_set Should I3C controller disable slaves from requesting Hot Join.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*hjConfigureResponse)(I3C_PrivData* pd, I3C_HjResponse hj_response, I3C_HjDisableSet hj_disable_set);

    /**
     * Enables chosen interrupts in slave mode.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] slaveInterruptConfig Interrupt configuration.
     * @return CDN_EOK on success
     * @return CDN_EIO if operation failed
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*configureSlaveInterrupts)(I3C_PrivData* pd, const I3C_SlaveInterruptConfig* slaveInterruptConfig);

    /**
     * Configures Hardware and Software to operate in Slave mode.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] slaveInterruptConfig Pointer to slave mode interrupt configuration.
     * @return CDN_EOK on success
     * @return CDN_EIO if operation failed
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*slaveModeConfigure)(I3C_PrivData* pd, const I3C_SlaveInterruptConfig* slaveInterruptConfig);

    /**
     * Adds SDR Read request to the queue.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] buf Pointer to buffer where data will be stored.
     * @param[in] num_bytes Number of bytes to read.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*slaveModeReqSdrRead)(I3C_PrivData* pd, uint8_t* buf, uint16_t num_bytes);

    /**
     * Adds SDR Write request to the queue.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] buf Pointer to buffer with data to be sent.
     * @param[in] num_bytes Number of bytes to send.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*slaveModeReqSdrWrite)(I3C_PrivData* pd, const uint8_t* buf, uint16_t num_bytes);

    /**
     * Adds DDR Read request to the queue.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] buf Pointer to buffer where data will be stored.
     * @param[in] num_words Number of bytes to read.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     * @return CDN_ENOENT if no DDR data is available for read
     * @return CDN_EPROTO if reveived command code is not to DDR Write
     */
    uint32_t (*slaveModeReqDdrRead)(I3C_PrivData* pd, uint16_t* buf, uint16_t num_words);

    /**
     * Adds DDR Write request to the queue.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] buf_in Pointer to buffer with data to be sent.
     * @param[in] num_words_in Number of 16-bit words to send.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     * @return CDN_ENOTSUP if DDR FIFOs are not implemented
     */
    uint32_t (*slaveModeReqDdrWrite)(I3C_PrivData* pd, const uint16_t* buf_in, uint16_t num_words_in);

    /**
     * Sends Hot Join request.
     * @param[in] pd Pointer to driver's private data object.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*slaveModeRequestHotJoin)(I3C_PrivData* pd);

    /**
     * Sends Mastership request.
     * @param[in] pd Pointer to driver's private data object.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*slaveModeMastershipReq)(I3C_PrivData* pd);

    /**
     * Sends In-Band Interrupt request.
     * @param[in] pd
     * @param[in] tCam0Event TCAM0_EVENT value to sent in ctrl register.
     * @param[in] ibiTCam0 If IBI request is specific to TCAM0.
     * @return CDN_EOK on success
     * @return CDN_EIO if operation failed
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*slaveModeRequestIbi)(I3C_PrivData* pd, uint8_t tCam0Event, bool ibiTCam0);

    /**
     * Writes Payload for In-Band Interrupt.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] buf Pointer to buffer with In-Band Interrupt Payload.
     * @param[in] numbytes Number of bytes to write.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*slaveModeWriteIbiPayload)(I3C_PrivData* pd, const uint8_t* buf, uint8_t numbytes);

    /**
     * Read Payload from IBI.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] buf Pointer to buffer to capture IBI playload
     * @param[in] numbytes Number of bytes to read
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*slaveModeReadIbiPayload)(I3C_PrivData* pd, uint8_t* buf, uint8_t numbytes);

    /**
     * Control flow control NACK/ACK request for next private transfer.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] mode flow control mode param
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*slaveModeReqFlowControl)(I3C_PrivData* pd, I3C_FlowControlMode mode);

    /**
     * Reads APB RO register value.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] idx Index of the APB RO register.
     * @param[out] val Pointer to variable where APB RO register value will be stored.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     * @return CDN_ENOTSUP if there are no APB RO CSRS
     */
    uint32_t (*slaveModeReadApbRo)(I3C_PrivData* pd, uint16_t idx, uint8_t* val);

    /**
     * Reads APB RW register value.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] idx Index of the APB RW register.
     * @param[out] val Pointer to variable where APB RW register value will be stored.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     * @return CDN_ENOTSUP if there are no APB RW CSRS
     */
    uint32_t (*slaveModeReadApbRw)(I3C_PrivData* pd, uint16_t idx, uint8_t* val);

    /**
     * Writes value to APB RW register.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] idx Index of the APB RW register.
     * @param[in] val Value to be written in the APB RW register.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     * @return CDN_ENOTSUP if there are no APB RW CSRS
     */
    uint32_t (*slaveModeWriteApbRw)(I3C_PrivData* pd, uint16_t idx, uint8_t val);

    /**
     * Reads GPO register value.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] idx Index of the GPO register.
     * @param[out] val Pointer to variable where GPO register value will be stored.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     * @return CDN_ENOTSUP if there are no GPO CSRS
     */
    uint32_t (*slaveModeReadGpo)(I3C_PrivData* pd, uint16_t idx, uint8_t* val);

    /**
     * Reads GPI register value.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] idx Index of the GPI register.
     * @param[out] val Pointer to variable where GPI register value will be stored.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     * @return CDN_ENOTSUP if there are no GPI CSRS
     */
    uint32_t (*slaveModeReadGpi)(I3C_PrivData* pd, uint16_t idx, uint8_t* val);

    /**
     * This function is for obtaining the Maximum Write Length.
     * @param[in] pd Pointer to driver's private data object.
     * @param[int] maxWriteLength Maximum write Length value.
     * @return CDN_EOK on success
     * @return CDN_EBUSY if operation failed
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*slaveModeReadMWL)(I3C_PrivData* pd, uint16_t* maxWriteLength);

    /**
     * This function is for obtaining the Maximum Read Length.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] maxReadLength Maximum Read Length value.
     * @param[in] ibiPayloadSize ibi payload size.
     * @return CDN_EOK on success
     * @return CDN_EBUSY if operation failed
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*slaveModeReadMRL)(I3C_PrivData* pd, uint16_t* maxReadLength, uint8_t* ibiPayloadSize);

    /**
     * This function is for obtaining the fill level for TX_FIFO and
     * RX_FIFO in SDR.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] fillLvl_tx no of words available in TX FIFO.
     * @param[in] fillLvl_rx no of words availale in RX FIFO.
     * @return CDN_EOK on success
     * @return CDN_EBUSY if operation failed
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*getFifoFillLvl)(I3C_PrivData* pd, uint16_t* fillLvl_tx, uint16_t* fillLvl_rx);

    /**
     * This function is flush TX and RX fifo in SDR.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] flush_tx flush TX FIFO.
     * @param[in] flush_rx flush RX FIFO.
     * @return CDN_EOK on success
     * @return CDN_EBUSY if operation failed
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*setSdrFifoFlush)(I3C_PrivData* pd, bool flush_tx, bool flush_rx);

    /**
     * This function is for obtaining the IBI/HJ/MR request status.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] ibi_stat IBI pending status.
     * @param[in] hj_stat Hot join request pending status.
     * @param[in] mr_stat Mastership change request pending status.
     * @return CDN_EOK on success
     * @return CDN_EBUSY if operation failed
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*slaveGetIbiStatus)(I3C_PrivData* pd, uint8_t* ibi_stat, uint8_t* hj_stat, uint8_t* mr_stat);

    /**
     * Retrieves ASF information from I3C controller.
     * @param[in] pd Pointer to driver's private data object.
     * @param[in] asf_info Pointer to ASF information structure.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*getAsfInfo)(I3C_PrivData* pd, I3C_AsfInfo* asf_info);

    /**
     * Checks controller operation mode
     * @param[in] pd Pointer to driver's private data object.
     * @param[out] opMode Pointer to OperationMode structure.
     * @return CDN_EOK on success
     * @return CDN_EINVAL if input parameters are invalid
     */
    uint32_t (*checkOperationMode)(const I3C_PrivData* pd, I3C_OperationMode* opMode);

} I3C_OBJ;
/* parasoft-end-suppress MISRA2012-DIR-4_8-4 */

/* parasoft-begin-suppress METRICS-36-3 "A function should not be called from more than 5 different functions, DRV-3666" */
/**
 * In order to access the I3C APIs, the upper layer software must call
 * this global function to obtain the pointer to the driver object.
 * @return I3C_OBJ* Driver Object Pointer
 */
extern I3C_OBJ *I3C_GetInstance(void);

/**
 *  @}
 */
#ifdef __cplusplus
}
#endif

/* parasoft-end-suppress METRICS-36-3 */

#endif  /* I3C_OBJ_IF_H */
