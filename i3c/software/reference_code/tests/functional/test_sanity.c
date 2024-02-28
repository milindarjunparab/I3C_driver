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
#include "test_sanity.h"

/**
 *Test Name: test_sanity_callbacks
 *Test Description: This test checks whether sanity functions check input value
 *Pass Conditions: operation passed
 *Fail Conditions: any other status
 *APIs called: internal functions only
 *Use Case: none
*/
int test_sanity_callbacks(void)
{
	I3C_Callbacks callbacks = {0};
	int status = CDN_EOK;
	int ret;

	ret = I3C_CallbacksSF(NULL);
	if (ret != CDN_EINVAL) {
		status = CDN_EINVAL;
	}
	ret = I3C_CallbacksSF(&callbacks);
	if (ret != CDN_EOK) {
		status = CDN_EINVAL;
	}
	return status;
}

/**
 *Test Name: test_sanity_function2
 *Test Description: This test checks whether internal function I3C_SanityFunction2 checks input values
 *Pass Conditions: operation passed
 *Fail Conditions: any other status
 *APIs called: internal functions only
 *Use Case: none
*/
int test_sanity_function2(void)
{
	I3C_PrivData private_data = {0};
	I3C_Config config = {0};
	I3C_Callbacks callbacks = {0};
	int status = CDN_EOK;
	int ret;

	ret = I3C_SanityFunction2(NULL, NULL, NULL);
	if (ret != CDN_EINVAL) {
		status = CDN_EINVAL;
	}

	private_data.dev_role = I3C_DEV_ROLE_SECONDARY_MASTER;
	ret = I3C_SanityFunction2(&private_data, NULL, NULL);
	if (ret != CDN_EINVAL) {
		status = CDN_EINVAL;
	}

	private_data.bus_mode = I3C_BUS_MODE_MIXED_FAST;
	ret = I3C_SanityFunction2(&private_data, NULL, NULL);
	if (ret != CDN_EINVAL) {
		status = CDN_EINVAL;
	}

	private_data.bus_mode = I3C_BUS_MODE_INVALID;
	ret = I3C_SanityFunction2(&private_data, NULL, NULL);
	if (ret != CDN_EINVAL) {
		status = CDN_EINVAL;
	}

	private_data.bus_mode = I3C_BUS_MODE_MIXED_SLOW;
	ret = I3C_SanityFunction2(&private_data, NULL, NULL);
	if (ret != CDN_EINVAL) {
		status = CDN_EINVAL;
	}

	ret = I3C_SanityFunction2(&private_data, &config, NULL);
	if (ret != CDN_EINVAL) {
		status = CDN_EINVAL;
	}
	ret = I3C_SanityFunction2(&private_data, &config, &callbacks);
	if (ret != CDN_EOK) {
		status = CDN_EINVAL;
	}
	return status;
}

/**
 *Test Name: test_sanity_function9
 *Test Description: This test checks whether internal function I3C_SanityFunction9 checks input values
 *Pass Conditions: operation passed
 *Fail Conditions: any other status
 *APIs called: internal functions only
 *Use Case: none
*/
int test_sanity_function9(void)
{
	I3C_PrivData private_data = {0};
	I3C_BusMode mode;
	int status = CDN_EOK;
	int ret;

	private_data.dev_role = I3C_DEV_ROLE_SECONDARY_MASTER;
	private_data.bus_mode = I3C_BUS_MODE_PURE;
	mode = I3C_BUS_MODE_PURE;
	ret = I3C_SanityFunction9(&private_data, mode);
	if (ret != CDN_EOK) {
		status = CDN_EINVAL;
	}

	mode = I3C_BUS_MODE_INVALID;
	ret = I3C_SanityFunction9(&private_data, mode);
	if (ret != CDN_EOK) {
		status = CDN_EINVAL;
	}

	mode = I3C_BUS_MODE_MIXED_FAST;
	ret = I3C_SanityFunction9(&private_data, mode);
	if (ret != CDN_EOK) {
		status = CDN_EINVAL;
	}

	mode = I3C_BUS_MODE_MIXED_SLOW;
	ret = I3C_SanityFunction9(&private_data, mode);
	if (ret != CDN_EOK) {
		status = CDN_EINVAL;
	}

	ret = I3C_SanityFunction9(&private_data, (I3C_BusMode)0xFFFF);
	if (ret != CDN_EINVAL) {
		status = CDN_EINVAL;
	}
	return status;
}

/**
 *Test Name: test_sanity_function30
 *Test Description: This test checks whether internal function I3C_SanityFunction30 checks input values
 *Pass Conditions: operation passed
 *Fail Conditions: any other status
 *APIs called: internal functions only
 *Use Case: none
*/
int test_sanity_function30(void)
{
	I3C_PrivData private_data = {0};
	I3C_CsrData csr = {0};
	I3C_TransmitMode mode;
	I3C_PayloadData payload = {0};
	int status = CDN_EOK;
	int ret;

	private_data.dev_role = I3C_DEV_ROLE_SECONDARY_MASTER;
	private_data.bus_mode = I3C_BUS_MODE_PURE;
	mode = I3C_CMD_XMIT_MODE_SINGLE_CSR;
	ret = I3C_SanityFunction30(&private_data, &csr, &payload, mode);
	if (ret != CDN_EOK) {
		status = CDN_EINVAL;
	}

	mode = I3C_CMD_XMIT_MODE_MULTI_BYTE_INC;
	ret = I3C_SanityFunction30(&private_data, &csr, &payload, mode);
	if (ret != CDN_EOK) {
		status = CDN_EINVAL;
	}

	mode = I3C_CMD_XMIT_MODE_MULTI_BYTE_STATIC;
	ret = I3C_SanityFunction30(&private_data, &csr, &payload, mode);
	if (ret != CDN_EOK) {
		status = CDN_EINVAL;
	}

	mode = I3C_CMD_XMIT_MODE_NCA;
	ret = I3C_SanityFunction30(&private_data, &csr, &payload, mode);
	if (ret != CDN_EOK) {
		status = CDN_EINVAL;
	}

	mode = I3C_CMD_XMIT_MODE_SINGLE_CSR;
	ret = I3C_SanityFunction30(&private_data, &csr, &payload, (I3C_TransmitMode)0xFFFF);
	if (ret != CDN_EINVAL) {
		status = CDN_EINVAL;
	}
	return status;
}

/**
 *Test Name: test_sanity_function35
 *Test Description: This test checks whether internal function I3C_SanityFunction35 checks input values
 *Pass Conditions: operation passed
 *Fail Conditions: any other status
 *APIs called: internal functions only
 *Use Case: none
*/
int test_sanity_function35(void)
{
	I3C_PrivData private_data = {0};
	I3C_HdrMode mode;
	I3C_PayloadData payload = {0};
	int status = CDN_EOK;
	int ret;

	private_data.dev_role = I3C_DEV_ROLE_SECONDARY_MASTER;
	private_data.bus_mode = I3C_BUS_MODE_PURE;
	mode = I3C_HDR_MODE_DDR;
	ret = I3C_SanityFunction35(&private_data, mode, NULL);
	if (ret != CDN_EINVAL) {
		status = CDN_EINVAL;
	}

	mode = I3C_HDR_MODE_DDR;
	ret = I3C_SanityFunction35(&private_data, mode, &payload);
	if (ret != CDN_EOK) {
		status = CDN_EINVAL;
	}

	mode = I3C_HDR_MODE_TSP;
	ret = I3C_SanityFunction35(&private_data, mode, &payload);
	if (ret != CDN_EOK) {
		status = CDN_EINVAL;
	}

	mode = I3C_HDR_MODE_TSL;
	ret = I3C_SanityFunction35(&private_data, mode, &payload);
	if (ret != CDN_EOK) {
		status = CDN_EINVAL;
	}

	ret = I3C_SanityFunction35(&private_data, (I3C_HdrMode)0xFFFF, &payload);
	if (ret != CDN_EINVAL) {
		status = CDN_EINVAL;
	}
	return status;
}

/**
 *Test Name: test_sanity_function37
 *Test Description: This test checks whether internal function I3C_SanityFunction38 checks input values
 *Pass Conditions: operation passed
 *Fail Conditions: any other status
 *APIs called: internal functions only
 *Use Case: none
*/
int test_sanity_function37(void)
{
	I3C_PrivData private_data = {0};
	I3C_ActivityState state;
	I3C_TransmissionParameters params = {0};
	int status = CDN_EOK;
	int ret;

	private_data.dev_role = I3C_DEV_ROLE_SECONDARY_MASTER;
	private_data.bus_mode = I3C_BUS_MODE_PURE;
	state = I3C_ACTIVITY_STATE_0;
	ret = I3C_SanityFunction38(&private_data, state, &params);
	if (ret != CDN_EOK) {
		status = CDN_EINVAL;
	}

	state = I3C_ACTIVITY_STATE_1;
	ret = I3C_SanityFunction38(&private_data, state, &params);
	if (ret != CDN_EOK) {
		status = CDN_EINVAL;
	}

	state = I3C_ACTIVITY_STATE_2;
	ret = I3C_SanityFunction38(&private_data, state, &params);
	if (ret != CDN_EOK) {
		status = CDN_EINVAL;
	}

	state = I3C_ACTIVITY_STATE_3;
	ret = I3C_SanityFunction38(&private_data, state, &params);
	if (ret != CDN_EOK) {
		status = CDN_EINVAL;
	}

	ret = I3C_SanityFunction38(&private_data, (I3C_ActivityState)0xFFFF, &params);
	if (ret != CDN_EINVAL) {
		status = CDN_EINVAL;
	}
	return status;
}

/**
 *Test Name: test_sanity_function48
 *Test Description: This test checks whether internal function I3C_SanityFunction50 checks input values
 *Pass Conditions: operation passed
 *Fail Conditions: any other status
 *APIs called: internal functions only
 *Use Case: none
*/
int test_sanity_function48(void)
{
	I3C_PrivData private_data = {0};
	I3C_HdrMode mode;
	I3C_TransmissionParameters params = {0};
	int status = CDN_EOK;
	int ret;

	private_data.dev_role = I3C_DEV_ROLE_SECONDARY_MASTER;
	private_data.bus_mode = I3C_BUS_MODE_PURE;
	mode = I3C_HDR_MODE_DDR;
	ret = I3C_SanityFunction50(&private_data, mode, &params);
	if (ret != CDN_EOK) {
		status = CDN_EINVAL;
	}

	mode = I3C_HDR_MODE_TSP;
	ret = I3C_SanityFunction50(&private_data, mode, &params);
	if (ret != CDN_EOK) {
		status = CDN_EINVAL;
	}

	mode = I3C_HDR_MODE_TSL;
	ret = I3C_SanityFunction50(&private_data, mode, &params);
	if (ret != CDN_EOK) {
		status = CDN_EINVAL;
	}

	mode = I3C_HDR_MODE_DDR;
	ret = I3C_SanityFunction50(&private_data, (I3C_HdrMode)0xFFFF, &params);
	if (ret != CDN_EINVAL) {
		status = CDN_EINVAL;
	}
	return status;
}

/**
 *Test Name: test_sanity_function60
 *Test Description: This test checks whether internal function I3C_SanityFunction70 checks input values
 *Pass Conditions: operation passed
 *Fail Conditions: any other status
 *APIs called: internal functions only
 *Use Case: none
*/
int test_sanity_function60(void)
{
	I3C_PrivData private_data = {0};
	I3C_HjResponse response;
	I3C_HjDisableSet disable;
	int status = CDN_EOK;
	int ret;

	private_data.dev_role = I3C_DEV_ROLE_SECONDARY_MASTER;
	private_data.bus_mode = I3C_BUS_MODE_PURE;
	response = I3C_HJ_RESP_NACK;
	disable = I3C_HJ_REQ_SLAVE_DISABLE;
	ret = I3C_SanityFunction70(&private_data, response, disable);
	if (ret != CDN_EOK) {
		status = CDN_EINVAL;
	}

	response = I3C_HJ_RESP_ACK;
	ret = I3C_SanityFunction70(&private_data, response, disable);
	if (ret != CDN_EOK) {
		status = CDN_EINVAL;
	}

	response = I3C_HJ_RESP_NACK;
	disable = I3C_HJ_REQ_SLAVE_NOT_DISABLE;
	ret = I3C_SanityFunction70(&private_data, response, disable);
	if (ret != CDN_EOK) {
		status = CDN_EINVAL;
	}

	response = I3C_HJ_RESP_ACK;
	ret = I3C_SanityFunction70(&private_data, response, disable);
	if (ret != CDN_EOK) {
		status = CDN_EINVAL;
	}

	ret = I3C_SanityFunction70(&private_data, response, (I3C_HjDisableSet)0xFFFF);
	if (ret != CDN_EINVAL) {
		status = CDN_EINVAL;
	}

	ret = I3C_SanityFunction70(&private_data, (I3C_HjResponse)0xFFFF, disable);
	if (ret != CDN_EINVAL) {
		status = CDN_EINVAL;
	}
	return status;
}

/**
 *Test Name: test_sanity_function69
 *Test Description: This test checks whether internal function I3C_SanityFunction93 checks input values
 *Pass Conditions: operation passed
 *Fail Conditions: any other status
 *APIs called: internal functions only
 *Use Case: none
*/
int test_sanity_function69(void)
{
	I3C_PrivData private_data = {0};
	I3C_AsfInfo asf = {0};
	int status = CDN_EOK;
	int ret;

	ret = I3C_SanityFunction93(&private_data, NULL);
	if (ret != CDN_EINVAL) {
		status = CDN_EINVAL;
	}

	private_data.dev_role = I3C_DEV_ROLE_SECONDARY_MASTER;
	private_data.bus_mode = I3C_BUS_MODE_PURE;
	ret = I3C_SanityFunction93(&private_data, NULL);
	if (ret != CDN_EINVAL) {
		status = CDN_EINVAL;
	}

	ret = I3C_SanityFunction93(&private_data, &asf);
	if (ret != CDN_EOK) {
		status = CDN_EINVAL;
	}
	return status;
}
