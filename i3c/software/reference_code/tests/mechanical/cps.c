 /******************************************************************************
 *
 * Copyright (C) 2012-2021 Cadence Design Systems, Inc.
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
 ******************************************************************************
 * cps.c
 *
 * Sample implementation of Cadence Platform Services for a bare-metal
 * system
 ******************************************************************************
 */


#include <cps.h>
#include <string.h>
#define _weak __attribute__((weak))


/* see cps.h */
_weak uint32_t CPS_ReadReg32(volatile uint32_t* address) {
    return *address;
}

/* see cps.h */
_weak void CPS_WriteReg32(volatile uint32_t* address, uint32_t value) {
    *address = value;
}

/* see cps.h */
_weak uint8_t CPS_UncachedRead8(volatile uint8_t* address) {
    return *address;
}

/* see cps.h */
_weak uint16_t CPS_UncachedRead16(volatile uint16_t* address) {
    return *address;
}

/* see cps.h */
_weak uint32_t CPS_UncachedRead32(volatile uint32_t* address) {
    return *address;
}

/* see cps.h */
_weak uint64_t CPS_UncachedRead64(volatile uint64_t* address) {
    return *address;
}

/* see cps.h */
_weak uint64_t CPS_ReadReg64(volatile uint64_t* address) {
    return *address;
}

/* see cps.h */
_weak void CPS_UncachedWrite8(volatile uint8_t* address, uint8_t value) {
    *address = value;
}

/* see cps.h */
_weak void CPS_UncachedWrite16(volatile uint16_t* address, uint16_t value) {
    *address = value;
}

/* see cps.h */
_weak void CPS_UncachedWrite32(volatile uint32_t* address, uint32_t value) {
    *address = value;
}

/* see cps.h */
_weak void CPS_UncachedWrite64(volatile uint64_t* address, uint64_t value) {
    *address = value;
}

/* see cps.h */
_weak void CPS_WriteReg64(volatile uint64_t* address, uint64_t value) {
    *address = value;
}

/* see cps.h */
_weak void CPS_WritePhysAddress32(volatile uint32_t* location, uint32_t addrValue) {
    *location = addrValue;
}

/* see cps.h */
_weak void CPS_BufferCopy(volatile uint8_t *dst, volatile const uint8_t *src, uint32_t size) {
    memcpy((void*)dst, (void*)src, size);
}

/* see cps.h */
_weak void CPS_CacheInvalidate(void* address, size_t size, uintptr_t devInfo) {
    (void) address;
    (void) size;
    (void) devInfo;
}

/* see cps.h */
_weak void CPS_CacheFlush(void* address, size_t size, uintptr_t devInfo) {
    (void) address;
    (void) size;
    (void) devInfo;
}

/* see cps.h */
_weak void CPS_DelayNs(uint32_t ns) {
    (void) ns;
}

/* see cps.h */
_weak void CPS_MemoryBarrier(void) {

}

/* see cps.h */
_weak void CPS_MemoryBarrierWrite(void) {

}

/* see cps.h */
_weak void CPS_MemoryBarrierRead(void) {

}
