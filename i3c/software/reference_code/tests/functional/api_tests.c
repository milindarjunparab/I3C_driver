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
#include "api_tests.h"

/**
 *Test Name: test_getasfinfo
 *Test Description: This test checks whether ASF info is provided
 *Pass Conditions: asf info provided
 *Fail Conditions: any other status
 *APIs called: I3C_GetAsfInfo
 *Use Case: ASF fault events
*/
int test_getasfinfo(void)
{
	I3C_PrivData private_data = {0};
	I3C_AsfInfo asf_info = {0};
	int status = CDN_EOK;
	int ret;

	private_data.dev_role = I3C_DEV_ROLE_SECONDARY_MASTER;
	private_data.bus_mode = I3C_BUS_MODE_MIXED_FAST;
	ret = I3C_GetAsfInfo(&private_data, &asf_info);
	if (ret != CDN_EOK) {
		status = CDN_EINVAL;
	}

	return status;
}

/**
 *Test Name: test_cmdaddddrread
 *Test Description: This test checks ID range of DDR IDs in for read operation
 *Pass Conditions: id checked as expected
 *Fail Conditions: any other status
 *APIs called: I3C_CmdAddDdrRead
 *Use Case: Transfer data using DDR mode
*/
int test_cmdaddddrread(void)
{
	I3C_PrivData private_data = {0};
	I3C_HdrMode hdr_mode = I3C_HDR_MODE_DDR;
	I3C_PayloadData payload_data = {0};
	uint8_t da = 0;
	uint8_t command;
	int status = CDN_EOK;
	int ret;

	private_data.dev_role = I3C_DEV_ROLE_SECONDARY_MASTER;
	private_data.bus_mode = I3C_BUS_MODE_MIXED_FAST;
	private_data.use_fifos = true;
	command = 0x7FU;	// bad command, too low ID

	ret = I3C_CmdAddDdrRead(&private_data, da, command, hdr_mode, &payload_data);
	if (ret != CDN_EINVAL) {
		status = CDN_EINVAL;
	}

	command = 0x91U;	// bad command, too high ID

	ret = I3C_CmdAddDdrRead(&private_data, da, command, hdr_mode, &payload_data);
	if (ret != CDN_EINVAL) {
		status = CDN_EINVAL;
	}

	return status;
}

/**
 *Test Name: test_cmdaddddrwrite
 *Test Description: This test checks ID range of DDR IDs in for write operation
 *Pass Conditions: id checked as expected
 *Fail Conditions: any other status
 *APIs called: I3C_CmdAddDdrWrite
 *Use Case: Transfer data using DDR mode
*/
int test_cmdaddddrwrite(void)
{
	I3C_PrivData private_data = {0};
	I3C_HdrMode hdr_mode = I3C_HDR_MODE_DDR;
	I3C_PayloadData payload_data = {0};
	uint8_t da = 0;
	uint8_t command;
	int status = CDN_EOK;
	int ret;

	private_data.dev_role = I3C_DEV_ROLE_SECONDARY_MASTER;
	private_data.bus_mode = I3C_BUS_MODE_MIXED_FAST;
	private_data.use_fifos = true;
	command = 0x80U;	// bad command, too low ID

	ret = I3C_CmdAddDdrWrite(&private_data, da, command, hdr_mode, &payload_data);
	if (ret != CDN_EINVAL) {
		status = CDN_EINVAL;
	}

	return status;
}

/**
 *Test Name: test_cmdexec
 *Test Description: This test checks whether CMD_IN_PROGRESS flag is checked properly
 *Pass Conditions: status is checked as expected
 *Fail Conditions: any other status
 *APIs called: I3C_CmdExec
 *Use Case: Commands support
*/
int test_cmdexec(void)
{
	I3C_PrivData private_data = {0};
	int status = CDN_EOK;
	int ret;

	private_data.dev_role = I3C_DEV_ROLE_SECONDARY_MASTER;
	private_data.bus_mode = I3C_BUS_MODE_MIXED_FAST;
	private_data.cmd_in_progress = true;

	ret = I3C_CmdExec(&private_data);
	if (ret != CDN_EBUSY) {
		status = CDN_EINVAL;
	}

	return status;
}
