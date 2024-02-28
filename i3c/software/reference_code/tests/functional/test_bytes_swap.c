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
#include "test_bytes_swap.h"

/**
 *Test Name: test_bytes_swap_3_bytes
 *Test Description: Test Bytes swap - 3 bytes
 *Pass Conditions: Array of bytes is reversed as expected.
 *Fail Conditions: All other status
 *APIs called: internal functions only
 *Use Case: none
*/
int test_bytes_swap_3_bytes(void)
{

  uint8_t data[] = {
    0x01,
    0x02,
    0x03,
  };

  uint8_t data_swapped_expected[] = {
    0x03,
    0x02,
    0x01,
};

  uint8_t data_size = 3;

  swap_bytes_sdr(data, data_size);

  if (memcmp(data, data_swapped_expected, data_size)) {
    return CDN_EFAULT;
  } else {
    return CDN_EOK;
  }
}

/**
 *Test Name: test_bytes_swap_4_bytes
 *Test Description: Test Bytes swap - 4 bytes
 *Pass Conditions: Array of bytes is reversed as expected.
 *Fail Conditions: All other status
 *APIs called: internal functions only
 *Use Case: none
*/
int test_bytes_swap_4_bytes(void)
{

  uint8_t data[] = {
    0xA1,
    0xA2,
    0xA3,
    0xA4,
  };

  uint8_t data_swapped_expected[] = {
    0xA4,
    0xA3,
    0xA2,
    0xA1,
};

  uint8_t data_size = 4;

  swap_bytes_sdr(data, data_size);

  if (memcmp(data, data_swapped_expected, data_size)) {
    return CDN_EFAULT;
  } else {
    return CDN_EOK;
  }

}

