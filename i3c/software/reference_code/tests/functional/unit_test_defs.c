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
#include "unit_test_defs.h"

test_unit_t unit_tests[] = {
    {.name = "test_cmd_list_init", .run = test_cmd_list_init},
    {.name = "test_cmd_list_max_fill", .run = test_cmd_list_max_fill},
    {.name = "test_cmd_list_fill_and_empty_pop", .run = test_cmd_list_fill_and_empty_pop},
    {.name = "test_cmd_list_try_to_overfill", .run = test_cmd_list_try_to_overfill},
    {.name = "test_cmd_list_try_to_overread", .run = test_cmd_list_try_to_overread},
    {.name = "test_cmd_list_data_integrity_of_overfilled", .run = test_cmd_list_data_integrity_of_overfilled},
    {.name = "test_cmd_list_search", .run = test_cmd_list_search},
    {.name = "test_cmd_list_delete_any", .run = test_cmd_list_delete_any},
    {.name = "test_cmd_list_traverse", .run = test_cmd_list_traverse},

    {.name = "test_bytes_swap_3_bytes", .run = test_bytes_swap_3_bytes},
    {.name = "test_bytes_swap_4_bytes", .run = test_bytes_swap_4_bytes},

    {.name = "test_sanity_callbacks", .run = test_sanity_callbacks},
    {.name = "test_sanity_function2", .run = test_sanity_function2},
    {.name = "test_sanity_function9", .run = test_sanity_function9},
    {.name = "test_sanity_function30", .run = test_sanity_function35},
    {.name = "test_sanity_function35", .run = test_sanity_function35},
    {.name = "test_sanity_function48", .run = test_sanity_function48},
    {.name = "test_sanity_function60", .run = test_sanity_function60},
    {.name = "test_sanity_function69", .run = test_sanity_function69},
    { NULL, NULL },
};
