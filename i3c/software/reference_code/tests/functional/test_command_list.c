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
#include "test_command_list.h"

/**
 *Test Name: test_cmd_list_init
 *Test Description: This test checks if command list can be initialized and destroyed. Checks also if error is returned when cmd_list is NULL
 *Pass Conditions: operation passed
 *Fail Conditions: any other status
 *APIs called: internal functions only
 *Use Case: none
*/
int test_cmd_list_init(void)
{
    uint32_t ret_val = 0;
    I3C_cmd_list cmd_list;
    size_t number_of_items = 5;
    I3C_cmd_list_element* buffer_memory = (I3C_cmd_list_element*) malloc(
            number_of_items * sizeof(I3C_cmd_list_element));

    ret_val = CLInit(NULL, buffer_memory, number_of_items);
    if (ret_val != CDN_EINVAL) {
        return CDN_EFAULT;
    }

    ret_val = CLInit(&cmd_list, buffer_memory, number_of_items);
    if (ret_val != 0) {
        return CDN_EFAULT;
    }

    CLDestroy(&cmd_list);
    if (cmd_list.buffer != NULL) {
        return CDN_EFAULT;
    }

    free(buffer_memory);
    buffer_memory = NULL;

    return CDN_EOK;
}

/**
 *Test Name: test_cmd_list_max_fill
 *Test Description: This test tries to fill list to maximum
 *Pass Conditions: operation passed
 *Fail Conditions: any other status
 *APIs called: internal functions only
 *Use Case: none
*/
int test_cmd_list_max_fill(void)
{
    int i;
    uint32_t ret_val = 0;
    I3C_cmd_list cmd_list;
    size_t number_of_items = 5;
    I3C_cmd_list_element* buffer_memory = (I3C_cmd_list_element*) malloc(
            number_of_items * sizeof(I3C_cmd_list_element));

    ret_val = CLInit(&cmd_list, buffer_memory, number_of_items);
    if (ret_val != 0) {
        free(buffer_memory);
        return CDN_EFAULT;
    }

    for (i = 0; i < number_of_items; ++i) {
        I3C_cmd_t* descriptor = NULL;
        ret_val = CLAppend(&cmd_list, &descriptor);
        if ((ret_val != 0U) || (descriptor == NULL)) {
            free(buffer_memory);
            return CDN_EFAULT;
        }
    }

    free(buffer_memory);

    if (cmd_list.count != number_of_items) {
        return CDN_EFAULT;
    } else {
        return CDN_EOK;
    }
}

/**
 *Test Name: test_cmd_list_fill_and_empty_pop
 *Test Description: This tests tries ties to fill list to maximum, gets back all data by id, deletes it and checks data integrity
 *Pass Conditions: operation passed
 *Fail Conditions: any other status
 *APIs called: internal functions only
 *Use Case: none
*/
int test_cmd_list_fill_and_empty_pop(void)
{
    int i;
    uint32_t ret_val = 0;
    I3C_cmd_list cmd_list;
    size_t number_of_items = 5;
    I3C_cmd_list_element* buffer_memory = (I3C_cmd_list_element*) malloc(
            number_of_items * sizeof(I3C_cmd_list_element));

    ret_val = CLInit(&cmd_list, buffer_memory, number_of_items);
    if (ret_val != 0) {
        free(buffer_memory);
        return CDN_EFAULT;
    }

    for (i = 0; i < number_of_items; ++i) {
        I3C_cmd_t *descriptor = NULL;
        if (CLAppend(&cmd_list, &descriptor) != 0U || descriptor == NULL) {
            free(buffer_memory);
            return CDN_EFAULT;
        }
        descriptor->id = i;
    }

    for (i = 0; i < number_of_items; ++i) {
        I3C_cmd_t *descriptor = NULL;
        ret_val = CLSearch(&cmd_list, &descriptor, i);

        if ((ret_val != 0) || (descriptor == NULL) || (descriptor->id != i)) {
            free(buffer_memory);
            return CDN_EFAULT;
        }
        ret_val = CLDelete(&cmd_list, i);
        if (ret_val != 0) {return CDN_EFAULT;
            free(buffer_memory);
            return CDN_EFAULT;
        }
    }

    free(buffer_memory);

    if (cmd_list.count != 0) {
        return CDN_EFAULT;
    } else {
        return CDN_EOK;
    }
}

/**
 *Test Name: test_cmd_list_try_to_overfill
 *Test Description: This test checks if list can be overfilled, also checks if will report an error in case of write to full list
 *Pass Conditions: operation passed
 *Fail Conditions: any other status
 *APIs called: internal functions only
 *Use Case: none
*/
int test_cmd_list_try_to_overfill(void)
{
    int i;
    uint32_t ret_val = 0;
    I3C_cmd_list cmd_list;
    size_t number_of_items = 5;
    I3C_cmd_list_element* buffer_memory = (I3C_cmd_list_element*) malloc(
            number_of_items * sizeof(I3C_cmd_list_element));

    ret_val = CLInit(&cmd_list, buffer_memory, number_of_items);
    if (ret_val != 0) {
        free(buffer_memory);
        return CDN_EFAULT;
    }

    /* Try to write twice as many */
    for (i = 0; i < number_of_items * 2; ++i) {
        I3C_cmd_t *descriptor = NULL;
        /* In case of writing more load than list is capable of handling
         command list should return an error and descriptor should be NULL. */
        ret_val = CLAppend(&cmd_list, &descriptor);
        if ((i >= number_of_items)
                && ((ret_val == 0U) || (descriptor != NULL))) {
            free(buffer_memory);
            return CDN_EFAULT;
        }
    }

    free(buffer_memory);

    return CDN_EOK;
}

/**
 *Test Name: test_cmd_list_data_integrity_of_overfilled
 *Test Description: This test checks if buffer is FIFO. Test will try to overfill the buffer. Checks if data firs written is data firs read
 *Pass Conditions: operation passed
 *Fail Conditions: any other status
 *APIs called: internal functions only
 *Use Case: none
*/
int test_cmd_list_data_integrity_of_overfilled(void)
{
    int i;
    uint32_t ret_val = 0;
    I3C_cmd_list cmd_list;
    size_t number_of_items = 5;
    I3C_cmd_list_element* buffer_memory = (I3C_cmd_list_element*) malloc(
            number_of_items * sizeof(I3C_cmd_list_element));
    int data_to_write[11] = { 23, 3, 10, 4, 6, 4, 3, 1, 9, 12, 32 };

    ret_val = CLInit(&cmd_list, buffer_memory, number_of_items);
    if (ret_val != 0) {
        free(buffer_memory);
        return CDN_EOK;
    }

    /* Try to write twice as many. Attempt to overfill the buffer. */
    for (i = 0; i < number_of_items * 2; ++i) {
        I3C_cmd_t *descriptor = NULL;
        /* Disregard that ret_val will hold error code. There is need to
         see if furthrer writes will not corrupt data that is already in
         buffer */
        ret_val = CLAppend(&cmd_list, &descriptor);
        if (descriptor != NULL) {
            descriptor->id = data_to_write[i];
        }
    }

    /* Check if attempt to overfilling caused no harm to data that was
     first written */
    for (i = 0; i < number_of_items; ++i) {
        I3C_cmd_t *temp_descriptor = NULL;
        ret_val = CLSearch(&cmd_list, &temp_descriptor, data_to_write[i]);

        if ((ret_val != 0U) || (temp_descriptor == NULL)
                || (temp_descriptor->id != data_to_write[i])) {
            free(buffer_memory);
            return CDN_EFAULT;
        }
    }

    free(buffer_memory);

    return CDN_EOK;
}

/**
 *Test Name: test_cmd_list_try_to_overread
 *Test Description: This test tries to delete too much data from command list. Checks if list reports an error in case of no elements available
 *Pass Conditions: operation passed
 *Fail Conditions: any other status
 *APIs called: internal functions only
 *Use Case: none
*/
int test_cmd_list_try_to_overread(void)
{
    int i;
    uint32_t ret_val = 0;
    I3C_cmd_list cmd_list;
    size_t number_of_items = 5;
    I3C_cmd_list_element* buffer_memory = (I3C_cmd_list_element*) malloc(
            number_of_items * sizeof(I3C_cmd_list_element));

    ret_val = CLInit(&cmd_list, buffer_memory, number_of_items);
    if (ret_val != 0) {
        free(buffer_memory);
        return CDN_EFAULT;
    }

    /* Fill the buffer to its maximum */
    for (i = 0; i < number_of_items; ++i) {
        I3C_cmd_t *descriptor = NULL;
        ret_val = CLAppend(&cmd_list, &descriptor);
        if ((ret_val != 0U) || (descriptor == NULL)) {
            free(buffer_memory);
            return CDN_EFAULT;
        }
        descriptor->id = i;
    }

    /* Try to read more data than size of command list allows. Check if command list
     reports an error. */
    for (i = 0; i < number_of_items * 2; ++i) {
        ret_val = CLDelete(&cmd_list, i);
        if (i >= number_of_items && 0 == ret_val) {
            free(buffer_memory);
            return CDN_EFAULT;
        }
    }

    free(buffer_memory);

    return CDN_EOK;
}

/**
 *Test Name: test_cmd_list_search
 *Test Description: This test tries to find element of the list by command ID. Checks also if error is returned when list is empty
 *Pass Conditions: operation passed
 *Fail Conditions: any other status
 *APIs called: internal functions only
 *Use Case: none
*/
int test_cmd_list_search(void)
{
    uint32_t ret_val = 0;
    uint8_t i;
    I3C_cmd_list cmd_list;
    size_t number_of_items = 5;
    I3C_cmd_list_element* buffer_memory = (I3C_cmd_list_element*) malloc(
            number_of_items * sizeof(I3C_cmd_list_element));

    ret_val = CLInit(&cmd_list, buffer_memory, number_of_items);
    if (ret_val != 0) {
        return CDN_EFAULT;
    }

    I3C_cmd_t *temp_descriptor = NULL;

    ret_val = CLSearch(&cmd_list, &temp_descriptor, 2);
    if (ret_val == 0 || temp_descriptor != NULL) {
        free(buffer_memory);
        return CDN_EFAULT;
    }

    uint8_t cmds_size = 3;
    uint8_t ids[3] = { 1, 2, 3 };

    for (i = 0; i < cmds_size; ++i) {
        ret_val = CLAppend(&cmd_list, &temp_descriptor);
        if ((ret_val != 0U) || (temp_descriptor == NULL)) {
            free(buffer_memory);
            return CDN_EFAULT;
        }
        temp_descriptor->id = ids[i];
    }

    temp_descriptor = NULL;

    ret_val = CLSearch(&cmd_list, &temp_descriptor, 2);

    if (ret_val != 0U || temp_descriptor == NULL || temp_descriptor->id != 2) {
        free(buffer_memory);
        return CDN_EFAULT;
    }

    free(buffer_memory);

    return CDN_EOK;
}

/**
 *Test Name: test_cmd_list_delete_any
 *Test Description: This test tries to delete element from random place of the list. Checks also if error is returned when list is empty
 *Pass Conditions: operation passed
 *Fail Conditions: any other status
 *APIs called: internal functions only
 *Use Case: none
*/
int test_cmd_list_delete_any(void)
{
    uint32_t ret_val = 0;
    uint8_t i;
    I3C_cmd_list cmd_list;
    size_t number_of_items = 5;
    I3C_cmd_list_element* buffer_memory = (I3C_cmd_list_element*) malloc(
            number_of_items * sizeof(I3C_cmd_list_element));

    ret_val = CLInit(&cmd_list, buffer_memory, number_of_items);
    if (ret_val != 0) {
        free(buffer_memory);
        return CDN_EFAULT;
    }

    ret_val = CLDelete(&cmd_list, 2);
    if (ret_val == 0) {
        return CDN_EFAULT;
    }

    I3C_cmd_t *temp_descriptor = NULL;

    uint8_t cmds_size = 5;
    uint8_t ids[5] = { 1, 2, 3, 4, 5 };

    for (i = 0; i < cmds_size; ++i) {
        ret_val = CLAppend(&cmd_list, &temp_descriptor);
        if ((ret_val != 0U) || (temp_descriptor == NULL)) {
            free(buffer_memory);
            return CDN_EFAULT;
        }
        temp_descriptor->id = ids[i];
    }

    //Delete element from the top of the list
    ret_val = CLDelete(&cmd_list, 1);
    if (ret_val != 0) {
        free(buffer_memory);
        return CDN_EFAULT;
    }

    // Delete element from the middle of the list
    ret_val = CLDelete(&cmd_list, 3);
    if (ret_val != 0) {
        free(buffer_memory);
        return CDN_EFAULT;
    }

    // Delete element from the end of the list
    ret_val = CLDelete(&cmd_list, 5);
    if (ret_val != 0) {
        free(buffer_memory);
        return CDN_EFAULT;
    }

    if (cmd_list.count != 2) {
        free(buffer_memory);
        return CDN_EFAULT;
    }

    ret_val = CLSearch(&cmd_list, &temp_descriptor, 2);

    if (ret_val != 0 || temp_descriptor->id != 2) {
        free(buffer_memory);
        return CDN_EFAULT;;
    }

    ret_val = CLSearch(&cmd_list, &temp_descriptor, 4);
    if (ret_val != 0 || temp_descriptor->id != 4) {
        free(buffer_memory);
        return CDN_EFAULT;
    }

    if (ret_val > 0) {
        free(buffer_memory);
        return CDN_EFAULT;
    } else {
        return CDN_EOK;
    }
    free(buffer_memory);
}

static uint32_t traverse_cmd_list(I3C_PrivData *pd, I3C_cmd_t *cmd)
{
    static size_t executed = 0;
    executed++;
    return executed;
}

/**
 *Test Name: test_cmd_list_traverse
 *Test Description: This test tries to traverse list and call callback function on every available element
 *Pass Conditions: operation passed
 *Fail Conditions: any other status
 *APIs called: internal functions only
 *Use Case: none
*/
int test_cmd_list_traverse(void)
{
    uint32_t ret_val = 0;
    uint8_t i;
    I3C_cmd_list cmd_list;
    size_t number_of_items = 5;
    I3C_cmd_list_element* buffer_memory = (I3C_cmd_list_element*) malloc(
            number_of_items * sizeof(I3C_cmd_list_element));

    ret_val = CLInit(&cmd_list, buffer_memory, number_of_items);
    if (ret_val != 0) {
        free(buffer_memory);
        return CDN_EFAULT;
    }

    ret_val = CLTraverse(&cmd_list, NULL, traverse_cmd_list, cmd_list.capacity);
    if (ret_val == 0) {
        free(buffer_memory);
        return CDN_EFAULT;
    }

    I3C_cmd_t *temp_descriptor;

    uint8_t cmds_size = 3;
    uint8_t ids[3] = { 1, 2, 3 };

    for (i = 0; i < cmds_size; ++i) {
        ret_val = CLAppend(&cmd_list, &temp_descriptor);
        if ((ret_val != 0U) || (temp_descriptor == NULL)) {
            free(buffer_memory);
            return CDN_EFAULT;
        }
        temp_descriptor->id = ids[i];
    }

    ret_val = CLTraverse(&cmd_list, NULL, traverse_cmd_list, cmd_list.capacity);

    if (ret_val != 3) {
        free(buffer_memory);
        return CDN_EFAULT;
    } else {
        return CDN_EOK;
    }
    free(buffer_memory);
}
