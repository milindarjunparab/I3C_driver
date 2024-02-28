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

#ifndef I3C_SANITY_H
#define I3C_SANITY_H

#include "cdn_stdtypes.h"
#include "cdn_errno.h"
#include "i3c_if.h"
#ifdef __cplusplus
extern "C" {
#endif

uint32_t I3C_AsfInfoSF(const I3C_AsfInfo *obj);
uint32_t I3C_CallbacksSF(const I3C_Callbacks *obj);
uint32_t I3C_ConfigSF(const I3C_Config *obj);
uint32_t I3C_CsrDataSF(const I3C_CsrData *obj);
uint32_t I3C_DeviceDescriptorSF(const I3C_DeviceDescriptor *obj);
uint32_t I3C_GroupDescriptorsSF(const I3C_GroupDescriptors *obj);
uint32_t I3C_IbiSirConfigurationSF(const I3C_IbiSirConfiguration *obj);
uint32_t I3C_InterruptConfigSF(const I3C_InterruptConfig *obj);
uint32_t I3C_MaxDataSpeedSF(const I3C_MaxDataSpeed *obj);
uint32_t I3C_MaxReadLengthSF(const I3C_MaxReadLength *obj);
uint32_t I3C_PayloadDataSF(const I3C_PayloadData *obj);
uint32_t I3C_PrivDataSF(const I3C_PrivData *obj);
uint32_t I3C_SlaveDescriptorsSF(const I3C_SlaveDescriptors *obj);
uint32_t I3C_SlaveInterruptConfigSF(const I3C_SlaveInterruptConfig *obj);
uint32_t I3C_Tcam0DataSF(const I3C_Tcam0Data *obj);
uint32_t I3C_ThresholdConfigSF(const I3C_ThresholdConfig *obj);
uint32_t I3C_TransmissionParametersSF(const I3C_TransmissionParameters *obj);

uint32_t I3C_SanityFunction1(const I3C_Config* config, const I3C_SysReq* sysReq);
uint32_t I3C_SanityFunction2(const I3C_PrivData* pd, const I3C_Config* config, const I3C_Callbacks* callbacks);
uint32_t I3C_SanityFunction3(const I3C_PrivData* pd);
uint32_t I3C_SanityFunction9(const I3C_PrivData* pd, const I3C_BusMode mode);
uint32_t I3C_SanityFunction10(const I3C_PrivData* pd, const I3C_BusMode* mode);
uint32_t I3C_SanityFunction13(const I3C_PrivData* pd, const uint8_t* pid);
uint32_t I3C_SanityFunction14(const I3C_PrivData* pd, const I3C_DeviceDescriptor* devs);
uint32_t I3C_SanityFunction16(const I3C_PrivData* pd, const I3C_Config* config);
uint32_t I3C_SanityFunction18(const I3C_PrivData* pd, const uint16_t* hj_devices);
uint32_t I3C_SanityFunction19(const I3C_PrivData* pd, const I3C_InterruptConfig* interruptConfig);
uint32_t I3C_SanityFunction20(const I3C_PrivData* pd, const I3C_ThresholdConfig* thresholdConfig);
uint32_t I3C_SanityFunction31(const I3C_PrivData* pd, const I3C_CsrData* csr_data, const I3C_PayloadData* payload_data, const I3C_TransmitMode xmitMmode);
uint32_t I3C_SanityFunction35(const I3C_PrivData* pd, const I3C_HdrMode hdrMode, const I3C_PayloadData* payload_data);
uint32_t I3C_SanityFunction37(const I3C_PrivData* pd, const I3C_TransmissionParameters* tx_params);
uint32_t I3C_SanityFunction38(const I3C_PrivData* pd, const I3C_ActivityState state, const I3C_TransmissionParameters* tx_params);
uint32_t I3C_SanityFunction42(const I3C_PrivData* pd, const uint16_t* length, const I3C_TransmissionParameters* tx_params);
uint32_t I3C_SanityFunction44(const I3C_PrivData* pd, const I3C_MaxReadLength* max_read_length, const I3C_TransmissionParameters* tx_params);
uint32_t I3C_SanityFunction45(const I3C_PrivData* pd, const I3C_MaxDataSpeed* max_data_speed, const I3C_TransmissionParameters* tx_params);
uint32_t I3C_SanityFunction46(const I3C_PrivData* pd, const I3C_SlaveDescriptors* slaveDescs);
uint32_t I3C_SanityFunction47(const I3C_PrivData* pd, const I3C_SlaveDescriptors* slaveDescs, const I3C_TransmissionParameters* tx_params);
uint32_t I3C_SanityFunction49(const I3C_PrivData* pd, const uint8_t* context_buf, const I3C_TransmissionParameters* tx_params);
uint32_t I3C_SanityFunction50(const I3C_PrivData* pd, const I3C_HdrMode mode, const I3C_TransmissionParameters* tx_params);
uint32_t I3C_SanityFunction57(const I3C_PrivData* pd, const I3C_GroupDescriptors* groupDescs, const I3C_TransmissionParameters* tx_params);
uint32_t I3C_SanityFunction64(const I3C_PrivData* pd, const I3C_Tcam0Data* tCamData, const I3C_TransmissionParameters* tx_params);
uint32_t I3C_SanityFunction66(const I3C_PrivData* pd, const I3C_IbiSirConfiguration* ibi_sir_cfg);
uint32_t I3C_SanityFunction70(const I3C_PrivData* pd, const I3C_HjResponse hj_response, const I3C_HjDisableSet hj_disable_set);
uint32_t I3C_SanityFunction71(const I3C_PrivData* pd, const I3C_SlaveInterruptConfig* slaveInterruptConfig);
uint32_t I3C_SanityFunction82(const I3C_PrivData* pd, const I3C_FlowControlMode mode);
uint32_t I3C_SanityFunction89(const I3C_PrivData* pd, const uint16_t* maxReadLength, const uint8_t* ibiPayloadSize);
uint32_t I3C_SanityFunction90(const I3C_PrivData* pd, const uint16_t* fillLvl_tx, const uint16_t* fillLvl_rx);
uint32_t I3C_SanityFunction92(const I3C_PrivData* pd, const uint8_t* ibi_stat, const uint8_t* hj_stat, const uint8_t* mr_stat);
uint32_t I3C_SanityFunction93(const I3C_PrivData* pd, const I3C_AsfInfo* asf_info);
uint32_t I3C_SanityFunction94(const I3C_PrivData* pd, const I3C_OperationMode* opMode);

#define I3C_ProbeSF I3C_SanityFunction1
#define I3C_InitSF I3C_SanityFunction2
#define I3C_IsrSF I3C_SanityFunction3
#define I3C_StartSF I3C_SanityFunction3
#define I3C_StopSF I3C_SanityFunction3
#define I3C_DestroySF I3C_SanityFunction3
#define I3C_EnableCoreSF I3C_SanityFunction3
#define I3C_DisableCoreSF I3C_SanityFunction3
#define I3C_SetBusModeSF I3C_SanityFunction9
#define I3C_GetBusModeSF I3C_SanityFunction10
#define I3C_SetBcrSF I3C_SanityFunction3
#define I3C_SetDcrSF I3C_SanityFunction3
#define I3C_SetPidSF I3C_SanityFunction13
#define I3C_ConfigureDevicesSF I3C_SanityFunction14
#define I3C_ConfigureDeviceSF I3C_SanityFunction14
#define I3C_ConfigurePrescalersSF I3C_SanityFunction16
#define I3C_ClearRrOfDeviceSF I3C_SanityFunction3
#define I3C_GetNewDevicesSF I3C_SanityFunction18
#define I3C_ConfigureInterruptsSF I3C_SanityFunction19
#define I3C_ConfigureThresholdsSF I3C_SanityFunction20
#define I3C_CmdExecSF I3C_SanityFunction3
#define I3C_CmdExecImmediateSF I3C_SanityFunction3
#define I3C_EnableMcsSF I3C_SanityFunction3
#define I3C_DisableMcsSF I3C_SanityFunction3
#define I3C_ManualCommandStartSF I3C_SanityFunction3
#define I3C_CmdCountSF I3C_SanityFunction3
#define I3C_CmdMaxCountSF I3C_SanityFunction3
#define I3C_CmdClearAllSF I3C_SanityFunction3
#define I3C_DevPrintSF I3C_SanityFunction3
#define I3C_EnableTcSF I3C_SanityFunction3
#define I3C_CmdAddPrivWriteSF I3C_SanityFunction31
#define I3C_CmdAddPrivReadSF I3C_SanityFunction31
#define I3C_CmdAddPrivI2CWriteSF I3C_SanityFunction13
#define I3C_CmdAddPrivI2CReadSF I3C_SanityFunction13
#define I3C_CmdAddDdrWriteSF I3C_SanityFunction35
#define I3C_CmdAddDdrReadSF I3C_SanityFunction35
#define I3C_CmdAddSetSlaveEventsSF I3C_SanityFunction37
#define I3C_CmdAddEnterActivityStateSF I3C_SanityFunction38
#define I3C_CmdAddResetDaaSF I3C_SanityFunction37
#define I3C_CmdAddEnterDaaSF I3C_SanityFunction37
#define I3C_CmdAddSetMaxWriteLengthSF I3C_SanityFunction37
#define I3C_CmdAddGetMaxWriteLengthSF I3C_SanityFunction42
#define I3C_CmdAddSetMaxReadLengthSF I3C_SanityFunction37
#define I3C_CmdAddGetMaxReadLengthSF I3C_SanityFunction44
#define I3C_CmdAddGetMaxDataSpeedSF I3C_SanityFunction45
#define I3C_GetSlavesListSF I3C_SanityFunction46
#define I3C_CmdAddDefineSlavesListSF I3C_SanityFunction47
#define I3C_CmdAddEnterTestModeSF I3C_SanityFunction37
#define I3C_CmdAddSetBusconSF I3C_SanityFunction49
#define I3C_CmdAddEnterHdrModeSF I3C_SanityFunction50
#define I3C_CmdAddSetAaSaSF I3C_SanityFunction37
#define I3C_CmdSetDaFromSaSF I3C_SanityFunction37
#define I3C_CmdAddSetNewDaSF I3C_SanityFunction37
#define I3C_CmdAddSetRstActSF I3C_SanityFunction37
#define I3C_CmdAddSetXTimeSF I3C_SanityFunction37
#define I3C_CmdAddSetGroupAddrSF I3C_SanityFunction37
#define I3C_CmdAddDefineGroupListSF I3C_SanityFunction57
#define I3C_CmdAddResetGrpaSF I3C_SanityFunction37
#define I3C_CmdAddGetProvisionalIdSF I3C_SanityFunction49
#define I3C_CmdAddGetBcrSF I3C_SanityFunction49
#define I3C_CmdAddGetDcrSF I3C_SanityFunction49
#define I3C_CmdAddGetStatusSF I3C_SanityFunction42
#define I3C_CmdAddGetAccMstSF I3C_SanityFunction49
#define I3C_CmdAddGetXTimeSF I3C_SanityFunction64
#define I3C_CmdSetNCAModeSF I3C_SanityFunction37
#define I3C_IbiConfigureDevicesSF I3C_SanityFunction66
#define I3C_IbiModifyDeviceConfigSF I3C_SanityFunction66
#define I3C_IbiGetAddressOfIssuerSF I3C_SanityFunction3
#define I3C_IbiGetDataSF I3C_SanityFunction13
#define I3C_HjConfigureResponseSF I3C_SanityFunction70
#define I3C_ConfigureSlaveInterruptsSF I3C_SanityFunction71
#define I3C_SlaveModeConfigureSF I3C_SanityFunction71
#define I3C_SlaveModeReqSdrReadSF I3C_SanityFunction13
#define I3C_SlaveModeReqSdrWriteSF I3C_SanityFunction13
#define I3C_SlaveModeReqDdrReadSF I3C_SanityFunction18
#define I3C_SlaveModeReqDdrWriteSF I3C_SanityFunction18
#define I3C_SlaveModeRequestHotJoinSF I3C_SanityFunction3
#define I3C_SlaveModeMastershipReqSF I3C_SanityFunction3
#define I3C_SlaveModeRequestIbiSF I3C_SanityFunction3
#define I3C_SlaveModeWriteIbiPayloadSF I3C_SanityFunction13
#define I3C_SlaveModeReadIbiPayloadSF I3C_SanityFunction13
#define I3C_SlaveModeReqFlowControlSF I3C_SanityFunction82
#define I3C_SlaveModeReadApbRoSF I3C_SanityFunction13
#define I3C_SlaveModeReadApbRwSF I3C_SanityFunction13
#define I3C_SlaveModeWriteApbRwSF I3C_SanityFunction3
#define I3C_SlaveModeReadGpoSF I3C_SanityFunction13
#define I3C_SlaveModeReadGpiSF I3C_SanityFunction13
#define I3C_SlaveModeReadMWLSF I3C_SanityFunction18
#define I3C_SlaveModeReadMRLSF I3C_SanityFunction89
#define I3C_GetFifoFillLvlSF I3C_SanityFunction90
#define I3C_SetSdrFifoFlushSF I3C_SanityFunction3
#define I3C_SlaveGetIbiStatusSF I3C_SanityFunction92
#define I3C_GetAsfInfoSF I3C_SanityFunction93
#define I3C_CheckOperationModeSF I3C_SanityFunction94

#ifdef __cplusplus
}
#endif

#endif  /* I3C_SANITY_H */

/* parasoft-end-suppress MISRA2012-RULE-8_7 */
/* parasoft-end-suppress METRICS-41-3 */
/* parasoft-end-suppress METRICS-39-3 */
/* parasoft-end-suppress METRICS-36-3 */
/* parasoft-end-suppress METRIC.CC-3 */
/* parasoft-end-suppress METRICS-18-3 */
