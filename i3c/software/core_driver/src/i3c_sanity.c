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

/* parasoft-begin-suppress METRICS-18-3 "Follow the Cyclomatic Complexity limit of 10, DRV-4789" */
/* parasoft-begin-suppress METRIC.CC-3 "Follow the Cyclomatic Complexity limit of 30, DRV-4417" */
/* parasoft-begin-suppress METRICS-36-3 "A function should not be called from more than 5 different functions, DRV-3823" */
/* parasoft-begin-suppress METRICS-39-3 "The value of VOCF metric for a function should not be higher than 4, DRV-4790" */
/* parasoft-begin-suppress METRICS-41-3 "Number of blocks of comments per statement, DRV-4926" */
/* parasoft-begin-suppress MISRA2012-RULE-8_7 "Functions and objects should not be defined with external linkage if they are referenced in only one translation unit, DRV-4139" */

/**
 * This file contains sanity API functions. The purpose of sanity functions
 * is to check input parameters validity. They take the same parameters as
 * original API functions and return 0 on success or CDN_EINVAL on wrong parameter
 * value(s).
 */

#include "cdn_stdtypes.h"
#include "cdn_errno.h"
#include "i3c_if.h"
#include "i3c_structs_if.h"
#include "i3c_sanity.h"

/**
 * Function to validate struct InterruptConfig
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t I3C_InterruptConfigSF(const I3C_InterruptConfig *obj)
{
    uint32_t ret = 0;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}

/**
 * Function to validate struct SlaveInterruptConfig
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t I3C_SlaveInterruptConfigSF(const I3C_SlaveInterruptConfig *obj)
{
    uint32_t ret = 0;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}

/**
 * Function to validate struct ThresholdConfig
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t I3C_ThresholdConfigSF(const I3C_ThresholdConfig *obj)
{
    uint32_t ret = 0;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}

/**
 * Function to validate struct Config
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t I3C_ConfigSF(const I3C_Config *obj)
{
    uint32_t ret = 0;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}

/**
 * Function to validate struct Callbacks
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t I3C_CallbacksSF(const I3C_Callbacks *obj)
{
    uint32_t ret = 0;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}

/**
 * Function to validate struct DeviceDescriptor
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t I3C_DeviceDescriptorSF(const I3C_DeviceDescriptor *obj)
{
    uint32_t ret = 0;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}

/**
 * Function to validate struct SlaveDescriptors
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t I3C_SlaveDescriptorsSF(const I3C_SlaveDescriptors *obj)
{
    uint32_t ret = 0;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}

/**
 * Function to validate struct IbiSirConfiguration
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t I3C_IbiSirConfigurationSF(const I3C_IbiSirConfiguration *obj)
{
    uint32_t ret = 0;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        if (
            (obj->ibiResp != I3C_IBI_RESP_NACK) &&
            (obj->ibiResp != I3C_IBI_RESP_ACK)
            )
        {
            ret = CDN_EINVAL;
        }
        if (
            (obj->ibiPayloadSpeedLimit != I3C_IBI_DATA_SPEED_NOT_LIMITED) &&
            (obj->ibiPayloadSpeedLimit != I3C_IBI_DATA_SPEED_LIMITED)
            )
        {
            ret = CDN_EINVAL;
        }
        if (
            (obj->ibiReqDevRole != I3C_IBI_REQUESTING_DEV_ROLE_SLAVE) &&
            (obj->ibiReqDevRole != I3C_IBI_REQUESTING_DEV_ROLE_MASTER)
            )
        {
            ret = CDN_EINVAL;
        }
    }

    return ret;
}

/**
 * Function to validate struct CsrData
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t I3C_CsrDataSF(const I3C_CsrData *obj)
{
    uint32_t ret = 0;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}

/**
 * Function to validate struct PayloadData
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t I3C_PayloadDataSF(const I3C_PayloadData *obj)
{
    uint32_t ret = 0;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}

/**
 * Function to validate struct TransmissionParameters
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t I3C_TransmissionParametersSF(const I3C_TransmissionParameters *obj)
{
    uint32_t ret = 0;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}

/**
 * Function to validate struct PrivData
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t I3C_PrivDataSF(const I3C_PrivData *obj)
{
    uint32_t ret = 0;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        if (
            (obj->dev_role != I3C_DEV_ROLE_MASTER) &&
            (obj->dev_role != I3C_DEV_ROLE_SECONDARY_MASTER)
            )
        {
            ret = CDN_EINVAL;
        }
        if (
            (obj->bus_mode != I3C_BUS_MODE_PURE) &&
            (obj->bus_mode != I3C_BUS_MODE_INVALID) &&
            (obj->bus_mode != I3C_BUS_MODE_MIXED_FAST) &&
            (obj->bus_mode != I3C_BUS_MODE_MIXED_SLOW)
            )
        {
            ret = CDN_EINVAL;
        }
    }

    return ret;
}

/**
 * Function to validate struct AsfInfo
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t I3C_AsfInfoSF(const I3C_AsfInfo *obj)
{
    uint32_t ret = 0;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}

/**
 * Function to validate struct MaxReadLength
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t I3C_MaxReadLengthSF(const I3C_MaxReadLength *obj)
{
    uint32_t ret = 0;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}

/**
 * Function to validate struct MaxDataSpeed
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t I3C_MaxDataSpeedSF(const I3C_MaxDataSpeed *obj)
{
    uint32_t ret = 0;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}

/**
 * Function to validate struct Tcam0Data
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t I3C_Tcam0DataSF(const I3C_Tcam0Data *obj)
{
    uint32_t ret = 0;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}

/**
 * Function to validate struct GroupDescriptors
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t I3C_GroupDescriptorsSF(const I3C_GroupDescriptors *obj)
{
    uint32_t ret = 0;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] config Driver and hardware configuration.
 * @param[out] sysReq Returns the memory requirements for given configuration.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction1(const I3C_Config* config, const I3C_SysReq* sysReq)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (sysReq == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_ConfigSF(config) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] config Specifies driver/hardware configuration.
 * @param[in] callbacks Event Handlers and Callbacks.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction2(const I3C_PrivData* pd, const I3C_Config* config, const I3C_Callbacks* callbacks)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_ConfigSF(config) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_CallbacksSF(callbacks) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object filled by init.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction3(const I3C_PrivData* pd)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] mode Bus Mode.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction9(const I3C_PrivData* pd, const I3C_BusMode mode)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (
        (mode != I3C_BUS_MODE_PURE) &&
        (mode != I3C_BUS_MODE_INVALID) &&
        (mode != I3C_BUS_MODE_MIXED_FAST) &&
        (mode != I3C_BUS_MODE_MIXED_SLOW)
        )
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] mode Pointer to Bus Mode object.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction10(const I3C_PrivData* pd, const I3C_BusMode* mode)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (mode == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (
        (*mode != I3C_BUS_MODE_PURE) &&
        (*mode != I3C_BUS_MODE_INVALID) &&
        (*mode != I3C_BUS_MODE_MIXED_FAST) &&
        (*mode != I3C_BUS_MODE_MIXED_SLOW)
        )
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] pid Ponter to buffer containing 48-bit Provisional ID value.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction13(const I3C_PrivData* pd, const uint8_t* pid)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (pid == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] devs Pointer to the structure containing configuration and capabilities of the Devices.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction14(const I3C_PrivData* pd, const I3C_DeviceDescriptor* devs)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_DeviceDescriptorSF(devs) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] config Specifies driver/hardware configuration.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction16(const I3C_PrivData* pd, const I3C_Config* config)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_ConfigSF(config) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[out] hj_devices This mask indicates which devices joined the bus.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction18(const I3C_PrivData* pd, const uint16_t* hj_devices)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (hj_devices == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] interruptConfig Interrupt configuration.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction19(const I3C_PrivData* pd, const I3C_InterruptConfig* interruptConfig)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_InterruptConfigSF(interruptConfig) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] thresholdConfig Threshold configuration.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction20(const I3C_PrivData* pd, const I3C_ThresholdConfig* thresholdConfig)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_ThresholdConfigSF(thresholdConfig) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] csr_data CSR information with CSR address and address lenght.
 * @param[in] payload_data Pointer to structure with payload information
 * @param[in] xmitMmode Transmission Mode.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction31(const I3C_PrivData* pd, const I3C_CsrData* csr_data, const I3C_PayloadData* payload_data, const I3C_TransmitMode xmitMmode)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_CsrDataSF(csr_data) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_PayloadDataSF(payload_data) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (
        (xmitMmode != I3C_CMD_XMIT_MODE_SINGLE_CSR) &&
        (xmitMmode != I3C_CMD_XMIT_MODE_MULTI_BYTE_INC) &&
        (xmitMmode != I3C_CMD_XMIT_MODE_MULTI_BYTE_STATIC) &&
        (xmitMmode != I3C_CMD_XMIT_MODE_NCA)
        )
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] hdrMode Specifies which one of the HDR modes to use.
 * @param[in] payload_data Pointer to structure with payload information
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction35(const I3C_PrivData* pd, const I3C_HdrMode hdrMode, const I3C_PayloadData* payload_data)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (
        (hdrMode != I3C_HDR_MODE_DDR) &&
        (hdrMode != I3C_HDR_MODE_TSP) &&
        (hdrMode != I3C_HDR_MODE_TSL)
        )
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_PayloadDataSF(payload_data) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] tx_params Transmission parameters - command descriptors
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction37(const I3C_PrivData* pd, const I3C_TransmissionParameters* tx_params)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_TransmissionParametersSF(tx_params) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] state Activity State value.
 * @param[in] tx_params Transmission parameters - command descriptor
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction38(const I3C_PrivData* pd, const I3C_ActivityState state, const I3C_TransmissionParameters* tx_params)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (
        (state != I3C_ACTIVITY_STATE_0) &&
        (state != I3C_ACTIVITY_STATE_1) &&
        (state != I3C_ACTIVITY_STATE_2) &&
        (state != I3C_ACTIVITY_STATE_3)
        )
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_TransmissionParametersSF(tx_params) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] length Pointer to 16-bit variable to which Maximum Write Length will be written.
 * @param[in] tx_params Transmission parameters - command descriptor
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction42(const I3C_PrivData* pd, const uint16_t* length, const I3C_TransmissionParameters* tx_params)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (length == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_TransmissionParametersSF(tx_params) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] max_read_length Pointer to a structure where Maximum Read Length.
 * @param[in] tx_params Transmission parameters - command descriptor
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction44(const I3C_PrivData* pd, const I3C_MaxReadLength* max_read_length, const I3C_TransmissionParameters* tx_params)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_MaxReadLengthSF(max_read_length) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_TransmissionParametersSF(tx_params) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] max_data_speed Pointer to structure with max data speeds.
 * @param[in] tx_params Transmission parameters - command descriptor
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction45(const I3C_PrivData* pd, const I3C_MaxDataSpeed* max_data_speed, const I3C_TransmissionParameters* tx_params)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_MaxDataSpeedSF(max_data_speed) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_TransmissionParametersSF(tx_params) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] slaveDescs Pointer the structure of Slave descriptors. Memory will be written with slave count and slave data.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction46(const I3C_PrivData* pd, const I3C_SlaveDescriptors* slaveDescs)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_SlaveDescriptorsSF(slaveDescs) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] slaveDescs Pointer the structure of Slave descriptors.
 * @param[in] tx_params Transmission parameters - command descriptor
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction47(const I3C_PrivData* pd, const I3C_SlaveDescriptors* slaveDescs, const I3C_TransmissionParameters* tx_params)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_SlaveDescriptorsSF(slaveDescs) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_TransmissionParametersSF(tx_params) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] context_buf Pointer to bus context data
 * @param[in] tx_params Transmission parameters - command descriptor
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction49(const I3C_PrivData* pd, const uint8_t* context_buf, const I3C_TransmissionParameters* tx_params)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (context_buf == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_TransmissionParametersSF(tx_params) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] mode
 * @param[in] tx_params Transmission parameters - command descriptor
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction50(const I3C_PrivData* pd, const I3C_HdrMode mode, const I3C_TransmissionParameters* tx_params)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (
        (mode != I3C_HDR_MODE_DDR) &&
        (mode != I3C_HDR_MODE_TSP) &&
        (mode != I3C_HDR_MODE_TSL)
        )
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_TransmissionParametersSF(tx_params) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] groupDescs Pointer the structure of Group descriptors.
 * @param[in] tx_params Transmission parameters - command descriptor
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction57(const I3C_PrivData* pd, const I3C_GroupDescriptors* groupDescs, const I3C_TransmissionParameters* tx_params)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_GroupDescriptorsSF(groupDescs) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_TransmissionParametersSF(tx_params) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] tCamData Pointer to buf which stores data bytes
 * @param[in] tx_params Transmission parameters - command descriptor
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction64(const I3C_PrivData* pd, const I3C_Tcam0Data* tCamData, const I3C_TransmissionParameters* tx_params)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_Tcam0DataSF(tCamData) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_TransmissionParametersSF(tx_params) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] ibi_sir_cfg Pointer to array that will hold configuration of IBI related devices.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction66(const I3C_PrivData* pd, const I3C_IbiSirConfiguration* ibi_sir_cfg)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_IbiSirConfigurationSF(ibi_sir_cfg) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] hj_response Should I3C controller ACK or NACK Hot Join request.
 * @param[in] hj_disable_set Should I3C controller disable slaves from requesting Hot Join.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction70(const I3C_PrivData* pd, const I3C_HjResponse hj_response, const I3C_HjDisableSet hj_disable_set)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (
        (hj_response != I3C_HJ_RESP_NACK) &&
        (hj_response != I3C_HJ_RESP_ACK)
        )
    {
        ret = CDN_EINVAL;
    }
    else if (
        (hj_disable_set != I3C_HJ_REQ_SLAVE_NOT_DISABLE) &&
        (hj_disable_set != I3C_HJ_REQ_SLAVE_DISABLE)
        )
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] slaveInterruptConfig Interrupt configuration.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction71(const I3C_PrivData* pd, const I3C_SlaveInterruptConfig* slaveInterruptConfig)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_SlaveInterruptConfigSF(slaveInterruptConfig) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] mode flow control mode param
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction82(const I3C_PrivData* pd, const I3C_FlowControlMode mode)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (
        (mode != I3C_NACK_NXT_PW_DISABLE) &&
        (mode != I3C_NACK_NXT_PR_DISABLE)
        )
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] maxReadLength Maximum Read Length value.
 * @param[in] ibiPayloadSize ibi payload size.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction89(const I3C_PrivData* pd, const uint16_t* maxReadLength, const uint8_t* ibiPayloadSize)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (maxReadLength == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (ibiPayloadSize == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] fillLvl_tx no of words available in TX FIFO.
 * @param[in] fillLvl_rx no of words availale in RX FIFO.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction90(const I3C_PrivData* pd, const uint16_t* fillLvl_tx, const uint16_t* fillLvl_rx)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (fillLvl_tx == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (fillLvl_rx == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] ibi_stat IBI pending status.
 * @param[in] hj_stat Hot join request pending status.
 * @param[in] mr_stat Mastership change request pending status.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction92(const I3C_PrivData* pd, const uint8_t* ibi_stat, const uint8_t* hj_stat, const uint8_t* mr_stat)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (ibi_stat == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (hj_stat == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (mr_stat == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[in] asf_info Pointer to ASF information structure.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction93(const I3C_PrivData* pd, const I3C_AsfInfo* asf_info)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_AsfInfoSF(asf_info) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pd Pointer to driver's private data object.
 * @param[out] opMode Pointer to OperationMode structure.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
uint32_t I3C_SanityFunction94(const I3C_PrivData* pd, const I3C_OperationMode* opMode)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (opMode == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (I3C_PrivDataSF(pd) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/* parasoft-end-suppress MISRA2012-RULE-8_7 */
/* parasoft-end-suppress METRICS-41-3 */
/* parasoft-end-suppress METRICS-39-3 */
/* parasoft-end-suppress METRICS-36-3 */
/* parasoft-end-suppress METRIC.CC-3 */
/* parasoft-end-suppress METRICS-18-3 */
