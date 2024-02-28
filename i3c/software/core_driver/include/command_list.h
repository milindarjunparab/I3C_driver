/*(C) 2023 Cadence Design Systems, Inc. 
This file is licensed under the Cadence Public License Version 1.0 (the “License”), a copy of which is available at https://www.cadence.com/content/dam/cadence-www/global/en_US/documents/terms-and-conditions/Cadence-Public-License-Version-1.0.pdf, and is distributed "AS IS." TO THE  MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, CADENCE DISCLAIMS ALL WARRANTIES AND IN NO EVENT SHALL BE LIABLE TO ANY PARTY FOR ANY DAMAGES ARISING OUT OF OR RELATING TO USE OF THIS FILE. Please see the License for the full text of applicable terms.
*
 ******************************************************************************
 *
 * command_list.h
 *
 * This file holds declarations and definitions for linked list
 *
 ******************************************************************************
 */

#ifndef COMMAND_LIST_H
#define COMMAND_LIST_H

#include <string.h>
#include <cdn_errno.h>
#include "i3c_structs_if.h"
#ifdef __cplusplus
extern "C" {
#endif

uint32_t CLInit(I3C_cmd_list* cmd_list, I3C_cmd_list_element* buffer, size_t capacity);
void CLDestroy(I3C_cmd_list* cmd_list);
uint32_t CLAppend(I3C_cmd_list* cmd_list, volatile I3C_cmd_t** descriptor);
uint32_t CLDelete(I3C_cmd_list* cmd_list, uint8_t cmd_id);
uint32_t CLSearch(const I3C_cmd_list* cmd_list, volatile I3C_cmd_t** descriptor, uint8_t cmd_id);
size_t CLGetNumberOfUsedLocations(const I3C_cmd_list* cmd_list);
bool CLEmpty(const I3C_cmd_list* cmd_list);
uint32_t CLTraverse(I3C_cmd_list* cmd_list, I3C_PrivData *pd,
                    uint32_t (*callback)(I3C_PrivData *pd, volatile I3C_cmd_t *cmd), size_t max);

#ifdef __cplusplus
}
#endif

#endif /* COMMAND_LIST_H */
