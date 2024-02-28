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
 *
 * mechanical_test_defs.h
 *
 * Helper Functions for I3C Master mechanical tests
 *
 ******************************************************************************
 */


#ifndef MECHANICAL_TEST_DEFS_H_
# define MECHANICAL_TEST_DEFS_H_

# ifdef MECHANICAL_TESTS

#  include <cdn_stdint.h>
#  include <i3c_if.h>
#  include <i3c_structs_if.h>
#  include <i3c_obj_if.h>
#  include <i3c_sanity.h>

/**
 * Test set-up for mechanical testing.
 * @param[in] i3c Pointer to driver object.
 * @param[out] privateDataPtr Returned pointer to driver private data.
 * @returns 0 for success.
 * @returns ENOMEM for memory allocation error.
 * @returns EINVAL for invalid input.
 */
uint32_t API_TEST_testSetup(I3C_OBJ *i3c, I3C_PrivData **pd);

/**
 * Test tear-down for mechanical testing.
 * @param[in] i3c Pointer to driver object.
 * @param[in] privateData Pointer to driver's private data.
 */
void API_TEST_testTearDown(I3C_OBJ *i3c, I3C_PrivData *pd);

# endif /* MECHANICAL_TESTS */

#endif

