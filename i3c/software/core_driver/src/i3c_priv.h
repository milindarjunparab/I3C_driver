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

#ifndef I3C_PRIV_H
#define I3C_PRIV_H

/* parasoft-begin-suppress MISRA2012-RULE-1_1_a_c90-2 "C90 - limits, DRV-3906" */
/* parasoft-begin-suppress MISRA2012-RULE-1_1_b_c90-2 "C90 - limits, DRV-3906" */
/* parasoft suppress item  MISRA2012-DIR-4_8 "Consider hiding implementation of structure, DRV-4932" */

/** @defgroup ConfigInfo  Configuration and Hardware Operation Information
 *  The following definitions specify the driver operation environment that
 *  is defined by hardware configuration or client code. These defines are
 *  located in the header file of the core driver.
 *  @{
 */

/**********************************************************************
* Defines
**********************************************************************/
/** Offset between two successive DeviceID<n>_reg registers (uint32_t as unit). */
#define I3C_DEVS_OFF ((uint32_t)((offsetof(MIPI_I3cRegs, DEV_ID1_RR0) - offsetof(MIPI_I3cRegs, DEV_ID0_RR0)) / sizeof(volatile uint32_t)))

/** Offset between two successive SIR_MAP<n> registers. */
#define I3C_SIR_MAP_OFF ((uint32_t)((offsetof(MIPI_I3cRegs, SIR_MAP1) - offsetof(MIPI_I3cRegs, SIR_MAP0)) / sizeof(volatile uint32_t)))

/**
 *  @}
 */

/* parasoft-end-suppress MISRA2012-RULE-1_1_b_c90-2 */
/* parasoft-end-suppress MISRA2012-RULE-1_1_a_c90-2 */

#endif  /* I3C_PRIV_H */
