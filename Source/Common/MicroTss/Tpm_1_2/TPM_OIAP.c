﻿/**
 *	@brief		Implements the TPM_OIAP command.
 *	@details	The module receives the input parameters, marshals these parameters
 *				to a byte array, sends the command to the TPM and unmarshals the response
 *				back to the out parameters.
 *	@file		TPM_OIAP.c
 *	@copyright	Copyright 2014 - 2017 Infineon Technologies AG ( www.infineon.com )
 *
 *	@copyright	All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *  1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 *  3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "TPM_OIAP.h"
#include "TPM_Marshal.h"
#include "TPM2_Marshal.h"
#include "DeviceManagement.h"
#include "Platform.h"

/**
 *	@brief		This function handles the TPM_OIAP command.
 *	@details	The function receives the input parameters, marshals these parameters
 *				to a byte array, sends the command to the TPM and unmarshals the response
 *				back to the out parameters.
 *
 *	@param		PpunAuthHandle		TPM-created handle that points to the authorization session.
 *	@param		PpsNonceEven		TPM-generated nonce that is associated with the session.
 *
 *	@retval		RC_SUCCESS			The operation completed successfully.
 *	@retval		RC_E_BAD_PARAMETER	An invalid parameter was passed to the function. E.g. NULL pointer
 *	@retval		...					Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM_OIAP(
	_Out_ TPM_AUTHHANDLE*	PpunAuthHandle,
	_Out_ TPM_NONCE*		PpsNonceEven)
{
	unsigned int unReturnValue = RC_SUCCESS;
	do
	{
		BYTE rgbRequest[MAX_COMMAND_SIZE] = {0};
		BYTE rgbResponse[MAX_RESPONSE_SIZE] = {0};
		BYTE* pbBuffer = NULL;
		INT32 nSizeRemaining = sizeof(rgbRequest);
		INT32 nSizeResponse = sizeof(rgbResponse);
		// Request parameters
		TPM_TAG tag = TPM_TAG_RQU_COMMAND;
		UINT32 unCommandSize = 0;
		TPM_COMMAND_CODE commandCode = TPM_ORD_OIAP;
		// Response parameters
		UINT32 unResponseSize = 0;
		TPM_RESULT responseCode = TPM_RC_SUCCESS;

		// Check parameters
		if (NULL == PpunAuthHandle || NULL == PpsNonceEven)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}

		// Initialize _Out_ parameters
		unReturnValue |= Platform_MemorySet(PpunAuthHandle, 0x00, sizeof(TPM_AUTHHANDLE));
		unReturnValue |= Platform_MemorySet(PpsNonceEven, 0x00, sizeof(TPM_NONCE));
		if (RC_SUCCESS != unReturnValue)
			break;

		// Marshal the request
		pbBuffer = rgbRequest;
		unReturnValue = TSS_TPM_TAG_Marshal(&tag, &pbBuffer, &nSizeRemaining);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_UINT32_Marshal(&unCommandSize, &pbBuffer, &nSizeRemaining);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_TPM_COMMAND_CODE_Marshal(&commandCode, &pbBuffer, &nSizeRemaining);
		if (RC_SUCCESS != unReturnValue)
			break;

		// Overwrite unCommandSize
		unCommandSize = sizeof(rgbRequest) - nSizeRemaining;
		pbBuffer = rgbRequest + 2;
		nSizeRemaining = 4;
		unReturnValue = TSS_UINT32_Marshal(&unCommandSize, &pbBuffer, &nSizeRemaining);
		if (RC_SUCCESS != unReturnValue)
			break;

		// Transmit the command over TDDL
		unReturnValue = DeviceManagement_Transmit(rgbRequest, unCommandSize, rgbResponse, (unsigned int*)&nSizeResponse);
		if (TPM_RC_SUCCESS != unReturnValue)
			break;

		// Unmarshal the response
		pbBuffer = rgbResponse;
		nSizeRemaining = nSizeResponse;
		unReturnValue = TSS_TPM_TAG_Unmarshal(&tag, &pbBuffer, &nSizeRemaining);
		if (TPM_RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_UINT32_Unmarshal(&unResponseSize, &pbBuffer, &nSizeRemaining);
		if (TPM_RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_TPM_RESULT_Unmarshal(&responseCode, &pbBuffer, &nSizeRemaining);
		if (TPM_RC_SUCCESS != unReturnValue)
			break;
		if (responseCode != TPM_RC_SUCCESS)
		{
			unReturnValue = RC_TPM_MASK | responseCode;
			break;
		}

		// Get response data
		{
			TPM_AUTHHANDLE unTempAuthHandle = 0;
			TPM_NONCE sTempNonceEven = {{0}};

			unReturnValue = TSS_UINT32_Unmarshal(&unTempAuthHandle, &pbBuffer, &nSizeRemaining);
			if (RC_SUCCESS != unReturnValue)
				break;

			unReturnValue = TSS_UINT8_Array_Unmarshal((UINT8*)&sTempNonceEven, &pbBuffer, &nSizeRemaining, sizeof(TPM_NONCE));
			if (RC_SUCCESS != unReturnValue)
				break;

			*PpunAuthHandle = unTempAuthHandle;
			*PpsNonceEven = sTempNonceEven;
		}
	}
	WHILE_FALSE_END;

	return unReturnValue;
}