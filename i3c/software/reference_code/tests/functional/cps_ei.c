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
#include "cps_ei.h"

/* 
 * Types
 */
typedef struct {
    bool enableError; //Flag indicates if error should occur
    bool isWriteError; //Flag indicates if error is read (false) or write (true)
    bool skipHwRead; //Flag indicates if hardware register read should be skipped.
    uintptr_t * address; //Address for which the error will be generated.
    uint32_t errValue; //The value which should be read at this address (using mask)
    uint32_t errMask; //This mask should be used to determine which bits will be read correctly.  Bits which are zero will use the value in errValue.
    uint32_t count; //This value specifies how many times the value should be read/written correctly before error data is read/written
    uint32_t repeat; //This specifies how many times the value should be read/written incorrectly before reading/writing correctly again.
} ErrorStruct;

/* 
 * Global data
 */
ErrorStruct * errorArray;


/* 
 * Local functions
 */
/* Function sets row of error array to default values (zeros) */
static inline void ClearErrorArrayElement(ErrorStruct * element) {
    memset(element, 0, sizeof(ErrorStruct));
}

/* Function checks alignment of address */
static inline bool isAligned(const void * pointer, size_t byte_count) {
    return (((uintptr_t)pointer % byte_count) == 0U);
}

/* Function checks if error is enabled. Also checks alignment of address */
static bool IsErrorEnabled(ErrorStruct * err, uintptr_t * address, bool isWrite, size_t byte_count) {
    uint32_t result;
    /* if error is enabled and input address match this in error array and error is 'write' (true)*/
    if ( (err->enableError == true) &&
         (err->address == address) &&
         (isAligned(err->address, byte_count) == true) &&
         (err->isWriteError == isWrite) ) {
        result = true;
     }
     else {
        result = false;
     }
    return (result);
}

/* Function finds error information for the given address */
static ErrorStruct * FindAddr(uintptr_t * address, bool isWrite, size_t byte_count)
{
    ErrorStruct * result = NULL;
    uint32_t i;

    /* check all array elements for an initialized array */
    if (errorArray != NULL) {
        for (i = 0U; i < MAX_TEST_EXECUTION; i++) {
            if (IsErrorEnabled(&errorArray[i], address, isWrite, byte_count) == true) {
                result = &errorArray[i];
                break;
            }
        }
    }
    return (result);
}

static uint32_t ModifyErrorValue(uint32_t value, ErrorStruct * err)
{
    uint32_t val = value;
    val &= err->errMask;
    val |= (err->errValue & ~(err->errMask));
    return (val);
}

/* 
 * API functions 
 */
 
uint32_t CPSEI_Enable(void) {
    uint32_t result;

    /* check if errorArray was allocated before */
    if (errorArray == NULL) {
        /* allocate and clear memory */
        errorArray = calloc(MAX_TEST_EXECUTION, sizeof(ErrorStruct));
        if (errorArray == NULL) {
            /* allocation error */
            result = CDN_ENOMEM;
        }
        else {
            result = 0U;
        }
    }
    else {
        /* error array is already allocated, don't call Enable twice */
        result = CDN_EINVAL;
    }

    return (result);
}

uint32_t CPSEI_Disable(void) {
    uint32_t result;

    /* check if errorArray is allocated */
    if (errorArray != NULL) {
        free(errorArray);
        errorArray = NULL;
        result = 0U;
    }
    else {
        /* memory is already allocated, don't call Disable twice */
        result = CDN_EINVAL;
    }

    return (result);
}

/* Reset all data in errorArray to 0 */
void CPSEI_Reset(void) {
    if (errorArray != NULL) {
        memset(errorArray, 0, (MAX_TEST_EXECUTION * sizeof(ErrorStruct)));
    }
}

uint32_t CPSEI_SkipHwRead(uintptr_t * address, bool skip) {
    uint32_t result = CDN_EOK;
    ErrorStruct * err;

    /* Find address in error array. We do not have to check alignment,
     * checked previously in CPSEI_AddReadError */
    err = FindAddr((uintptr_t *)address, false, 1U);

    if (err != NULL) {
        err->skipHwRead = skip;
    }
    else {
        /* no element in array */
        result = CDN_ENOENT;
    }
    return result;
}

/* Add read error to array */
uint32_t CPSEI_AddReadError(uintptr_t * address, uint32_t errValue, uint32_t errMask, uint32_t count, uint32_t repeat) {
    uint32_t result;
    uint32_t i;
    
    /* fill error structure with data */
    if (errorArray != NULL) {
        for (i = 0U; i < MAX_TEST_EXECUTION; i++) {
            if (errorArray[i].enableError == false) {
                errorArray[i].enableError = true;
                errorArray[i].address = address;
                errorArray[i].errValue = errValue;
                errorArray[i].errMask = errMask;
                errorArray[i].count = count;
                errorArray[i].repeat = repeat;
                errorArray[i].isWriteError = false;
                errorArray[i].skipHwRead = false;
                result = 0U;
                break;
            }
            else {
                /* array is full */
                result = CDN_EINVAL;
            }
        }
    } else {
        /* array is empty */
        result = CDN_ENOMEM;
    }

    return(result);
}

/* Read a (8-bit) byte. This function replaces production version of CPS_UncachedRead8 */
uint8_t CPS_UncachedRead8(volatile uint8_t * address) {
    uint8_t readValue = 0U;
    ErrorStruct * err;

    /* Find address in error array. Check also alignment of this address */
    err = FindAddr((uintptr_t *)address, false, sizeof(readValue));

    /* If address is in error array, inject error */
    if (err != NULL) {
        if(!err->skipHwRead) {
            readValue = (uint8_t)*address;
        }
        if (err->count == 0) {
            readValue = (uint8_t)ModifyErrorValue((uint32_t)readValue, err);
            if (err->repeat > 0U) {
                err->repeat--;
                /* if this was last execution with injected error, clear this part of array */
                if (err->repeat == 0) {
                    ClearErrorArrayElement(err);
                }
            }
        }
        else {
            err->count--;
        }
    }
    else {
        readValue = (uint8_t)*address;
    }
    return (readValue);
}

/* Read a (16-bit) short. This function replaces production version of CPS_UncachedRead16 */
uint16_t CPS_UncachedRead16(volatile uint16_t * address) {
    uint16_t readValue = 0U;

    ErrorStruct * err;

    /* Find address in error array. Check also alignment of this address */
    err = FindAddr((uintptr_t *)address, false, sizeof(readValue));

    /* If address is in error array, inject error */
    if (err != NULL) {
        if(!err->skipHwRead) {
            readValue = (uint16_t)*address;
        }
        if (err->count == 0) {
            readValue = (uint16_t)ModifyErrorValue((uint32_t)readValue, err);
            if (err->repeat > 0U) {
                err->repeat--;
                /* if this was last execution with injected error, clear this part of array */
                if (err->repeat == 0) {
                    ClearErrorArrayElement(err);
                }
            }
        }
        else {
            err->count--;
        }
    }
    else {
        readValue = (uint16_t)*address;
    }
    return (readValue);
}

/* Read a (32-bit) word. This function replaces production version of CPS_UncachedRead32 */
uint32_t CPS_UncachedRead32(volatile uint32_t * address) {
    uint32_t readValue = 0U;

    ErrorStruct * err;

    /* Find address in error array. Check also alignment of this address */
    err = FindAddr((uintptr_t *)address, false, sizeof(readValue));

    /* If address is in error array, inject error */
    if (err != NULL) {
        if(!err->skipHwRead) {
            readValue = (uint32_t)*address;
        }
        if (err->count == 0) {
            readValue = ModifyErrorValue(readValue, err);
            if (err->repeat > 0U) {
                err->repeat--;
                /* if this was last execution with injected error, clear this part of array */
                if (err->repeat == 0) {
                    ClearErrorArrayElement(err);
                }
            }
        }
        else {
            err->count--;
        }
    }
    else {
        readValue = (uint32_t)*address;
    }
    return (readValue);
}

/* Read a (32-bit) word. This function replaces production version of CPS_ReadReg32 */
uint32_t CPS_ReadReg32(volatile uint32_t * address) {
    return (CPS_UncachedRead32(address));
}

/* Add write error to array */
uint32_t CPSEI_AddWriteError(uintptr_t * address, uint32_t errValue, uint32_t errMask, uint32_t count, uint32_t repeat) {
    uint32_t result;
    uint32_t i;
    
    /* fill error structure with data */
    if (errorArray != NULL) {
        for (i = 0U; i < MAX_TEST_EXECUTION; i++) {
            if (errorArray[i].enableError == false) {
                errorArray[i].enableError = true;
                errorArray[i].address = address;
                errorArray[i].errValue = errValue;
                errorArray[i].errMask = errMask;
                errorArray[i].count = count;
                errorArray[i].repeat = repeat;
                errorArray[i].isWriteError = true;
                result = 0U;
                break;
            }
            else {
                /* array is full */
                result = CDN_EINVAL;
            }
        }
    } else {
        /* array is empty */
        result = CDN_ENOMEM;
    }

    return(result);
}


/* Write a (8-bit) byte to memory and inject error. This function replaces production version of CPS_UncachedWrite8 */
void CPS_UncachedWrite8(volatile uint8_t * address, uint8_t value) {
    uint8_t writeValue = value;

    ErrorStruct * err;

    /* Find address in error array. Check also alignment of this address */
    err = FindAddr((uintptr_t *)address, true, sizeof(writeValue));

    /* If address is in error array, inject error */
    if (err != NULL) {
        if (err->count == 0) {
            writeValue = (uint8_t)ModifyErrorValue((uint32_t)writeValue, err);
            if (err->repeat > 0U) {
                err->repeat--;
                /* if this was last execution with injected error, clear this part of array */
                if (err->repeat == 0) {
                    ClearErrorArrayElement(err);
                }
            }
        }
        else {
            err->count--;
        }
    }

    *address = writeValue;
}

/* Write a (16-bit) short to memory and inject error. This function replaces production version of CPS_UncachedWrite16 */
void CPS_UncachedWrite16(volatile uint16_t * address, uint16_t value) {
    uint16_t writeValue = value;

    ErrorStruct * err;

    /* Find address in error array. Check also alignment of this address */
    err = FindAddr((uintptr_t *)address, true, sizeof(writeValue));

    /* If address is in error array, inject error */
    if (err != NULL) {
        if (err->count == 0) {
            writeValue = (uint16_t)ModifyErrorValue((uint32_t)writeValue, err);
            if (err->repeat > 0U) {
                err->repeat--;
                /* if this was last execution with injected error, clear this part of array */
                if (err->repeat == 0) {
                    ClearErrorArrayElement(err);
                }
            }
        }
        else {
            err->count--;
        }
    }

    *address = writeValue;
}

/* Write a (32-bit) word to memory and inject error. This function replaces production version of CPS_UncachedWrite32 */
void CPS_UncachedWrite32(volatile uint32_t * address, uint32_t value) {
    uint32_t writeValue = value;

    ErrorStruct * err;

    /* Find address in error array. Check also alignment of this address */
    err = FindAddr((uintptr_t *)address, true, sizeof(writeValue));

    /* If address is in error array, inject error */
    if (err != NULL) {
        if (err->count == 0) {
            writeValue = ModifyErrorValue(writeValue, err);
            if (err->repeat > 0U) {
                err->repeat--;
                /* if this was last execution with injected error, clear this part of array */
                if (err->repeat == 0) {
                    ClearErrorArrayElement(err);
                }
            }
        }
        else {
            err->count--;
        }
    }

    *address = writeValue;
}

/* Write a (32-bit) word to memory and inject error. This function replaces production version of CPS_WriteReg32 */
void CPS_WriteReg32(volatile uint32_t * address, uint32_t value) {
    CPS_UncachedWrite32(address, value);
}

