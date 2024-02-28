/*(C) 2023 Cadence Design Systems, Inc. 
This file is licensed under the Cadence Public License Version 1.0 (the “License”), a copy of which is available at https://www.cadence.com/content/dam/cadence-www/global/en_US/documents/terms-and-conditions/Cadence-Public-License-Version-1.0.pdf, and is distributed "AS IS." TO THE  MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, CADENCE DISCLAIMS ALL WARRANTIES AND IN NO EVENT SHALL BE LIABLE TO ANY PARTY FOR ANY DAMAGES ARISING OUT OF OR RELATING TO USE OF THIS FILE. Please see the License for the full text of applicable terms.
*
 *
 ******************************************************************************
 *
 * command_list.c
 *
 * This file holds implementation of linked list.
 *
 ******************************************************************************
 */

#include "command_list.h"

/**
 * Instantiates the Command List
 * @param[in] cmd_list Pointer to I3C_cmd_list object.
 * @param[in] buffer Pointer to buffer for command stored on list
 * @param[in] capacity Maximum capacity of the list
 * @return CDN_EOK On success
 * @return CDN_EINVAL If cmd_list points to NULL
 */
uint32_t CLInit(I3C_cmd_list* cmd_list, I3C_cmd_list_element* buffer,
                size_t capacity) {
    uint32_t ret_val = CDN_EINVAL;
    size_t i;

    if (cmd_list != NULL) {
        cmd_list->buffer = buffer;
        cmd_list->capacity = capacity;
        cmd_list->count = 0U;
        /* All buffer elements are unused */
        for (i = 0U; i < cmd_list->capacity; i++) {
            cmd_list->buffer[i].used = false;
        }
        ret_val = CDN_EOK;
    }
    return ret_val;
}

/**
 * Clear all fields
 * @param[in] cmd_list Pointer to I3C_cmd_list object.
 */
void CLDestroy(I3C_cmd_list* cmd_list) {
    cmd_list->buffer = NULL;
    cmd_list->count = 0U;
    cmd_list->capacity = 0U;
}

/**
 * Returns unused buffer element
 * @param[in] cmd_list Pointer to I3C_cmd_list object.
 * @return Buffer element
 */
static I3C_cmd_list_element* get_free_node(const I3C_cmd_list* cmd_list) {
    static const I3C_cmd_t zeroed_descriptor = { 0 };
    I3C_cmd_list_element* elem = NULL;
    size_t i;
    for (i = 0U; i < cmd_list->capacity; i++) {
        if (cmd_list->buffer[i].used == false) {
            elem = &cmd_list->buffer[i];
            /* Mark this element as used */
            elem->used = true;
            /* Reset all fields */
            elem->cmd = zeroed_descriptor;
            break;
        }
    }
    return elem;
}

/**
 * Adds element to the list and returns pointer to added command
 * @param[in] cmd_list Pointer to I3C_cmd_list object.
 * @param[out] descriptor Pointer to command added to list
 * @return CDN_EOK On success
 * @return CDN_ENOMEM If list is full
 */
uint32_t CLAppend(I3C_cmd_list* cmd_list, volatile I3C_cmd_t** descriptor) {
    uint32_t ret_val;
    I3C_cmd_list_element* elem;

    if (cmd_list->count >= cmd_list->capacity) {
        ret_val = CDN_ENOMEM;
    } else {
        elem = get_free_node(cmd_list);
        /* Check if returned element is not null */
        if (elem != NULL) {
            *descriptor = &(elem->cmd);
            /* Increment number of list elements */
            cmd_list->count++;
            ret_val = CDN_EOK;
        } else {
            ret_val = CDN_ENOMEM;
        }
    }

    return ret_val;
}

/**
 * Removes element from the list
 * @param[in] cmd_list Pointer to I3C_cmd_list object.
 * @param[in] cmd_id ID of command to delete
 * @return CDN_EOK On success
 * @return CDN_ENOENT If list command with given ID was not found
 * @return CDN_EOPNOTSUPP If list is empty
 */
uint32_t CLDelete(I3C_cmd_list* cmd_list, uint8_t cmd_id) {
    uint32_t ret_val;
    size_t i;

    /* Don't do anything if list is empty */
    if (cmd_list->count == 0U) {
        ret_val = CDN_EOPNOTSUPP;
    } else {
        /* No entry if command with given ID not found */
        ret_val = CDN_ENOENT;

        for (i = 0U; i < cmd_list->capacity; i++) {
            if ((cmd_list->buffer[i].used == true)
                && (cmd_list->buffer[i].cmd.id == cmd_id)) {
                /* Free this element, reset when allocated again */
                cmd_list->buffer[i].used = false;
                ret_val = CDN_EOK;
                cmd_list->count--;
            }
        }
    }

    return ret_val;
}

/**
 * Search and returns command with given ID
 * @param[in] cmd_list Pointer to I3C_cmd_list object.
 * @param[out] descriptor Pointer to command added to list
 * @param[in] cmd_id ID of command to delete
 * @return CDN_EOK On success
 * @return CDN_ENOENT If list command with given ID was not found
 * @return CDN_EOPNOTSUPP If list is empty
 */
uint32_t CLSearch(const I3C_cmd_list* cmd_list, volatile I3C_cmd_t** descriptor,
                  uint8_t cmd_id) {
    uint32_t ret_val;
    size_t i;

    /* Don't do anything if list is empty */
    if (cmd_list->count == 0U) {
        ret_val = CDN_EOPNOTSUPP;
    } else {
        /* No entry if command with given ID not found */
        ret_val = CDN_ENOENT;

        for (i = 0U; i < cmd_list->capacity; i++) {
            if ((cmd_list->buffer[i].used == true)
                && (cmd_list->buffer[i].cmd.id == cmd_id)) {
                *descriptor = &(cmd_list->buffer[i].cmd);
                ret_val = CDN_EOK;
            }
        }
    }

    return ret_val;
}

/**
 * Returns number of elements on the list
 * @param[in] cmd_list Pointer to I3C_cmd_list object.
 * @return number of elements
 */
size_t CLGetNumberOfUsedLocations(const I3C_cmd_list* cmd_list) {
    return cmd_list->count;
}

/**
 * Returns if lsit is empty or not
 * @param[in] cmd_list Pointer to I3C_cmd_list object.
 * @return If list is empty
 */
bool CLEmpty(const I3C_cmd_list* cmd_list) {
    return (cmd_list->count == 0U);
}

/**
 * Allows to traverse all used elements of the list calling callback function
 * @param[in] cmd_list Pointer to I3C_cmd_list object.
 * @param[in] pd Pointer to I3C_PrivData object.
 * @patam[in] callback Callback function which is called for every command
 * @return CDN_EOK On success
 * @return CDN_EOPNOTSUPP If list is empty
 */
uint32_t CLTraverse(I3C_cmd_list* cmd_list, I3C_PrivData *pd,
                    uint32_t (*callback)(I3C_PrivData *pd, volatile I3C_cmd_t *cmd), size_t max) {
    uint32_t ret_val = CDN_EOK;
    size_t i;
    size_t executed = 0;

    /* Don't do anything if list is empty */
    if (cmd_list->count == 0U) {
        ret_val = CDN_EOPNOTSUPP;
    } else {
        for (i = 0U; i < cmd_list->capacity; i++) {
            if ((cmd_list->buffer[i].used == true) &&
                (executed < max)) {
                /* Execute callback with command from list as a parameter */
                ret_val = callback(pd, &(cmd_list->buffer[i].cmd));
                executed++;
            }
        }
    }

    return ret_val;
}

