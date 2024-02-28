/*(C) 2023 Cadence Design Systems, Inc. 
This file is licensed under the Cadence Public License Version 1.0 (the “License”), a copy of which is available at https://www.cadence.com/content/dam/cadence-www/global/en_US/documents/terms-and-conditions/Cadence-Public-License-Version-1.0.pdf, and is distributed "AS IS." TO THE  MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, CADENCE DISCLAIMS ALL WARRANTIES AND IN NO EVENT SHALL BE LIABLE TO ANY PARTY FOR ANY DAMAGES ARISING OUT OF OR RELATING TO USE OF THIS FILE. Please see the License for the full text of applicable terms.
*
 ******************************************************************************
 * cdn_stdint.h
 ******************************************************************************
 */
#ifndef CDN_STDINT
#define CDN_STDINT

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

/* NOTE - The driver uses fixed width types as defined in C99

    If not provided by your environment, these are typical definitions for the
 *        fixed width types used in the driver, and should be provided here.
 * typedef signed char            int8_t
 * typedef unsigned char          uint8_t
 * typedef signed short           int16_t
 * typedef unsigned short         uint16_t
 * typedef signed long int        int32_t
 * typedef unsigned long int      uint32_t
 * typedef signed long long int   int64_t
 * typedef unsigned long long int uint64_t
 * typedef int32_t                intptr_t
 * typedef uint32_t               uintptr_t

 * These definitions are for a 32bit system with 32bit int, and should be adjusted
 * for your actual target system and toolchain.

   Under Linux, these will be available in:
   linux/types.h

 */

#ifdef __cplusplus
}
#endif

#endif
