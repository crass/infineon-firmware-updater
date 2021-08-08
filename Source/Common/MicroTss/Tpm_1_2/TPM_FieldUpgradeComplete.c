﻿/**
 *	@brief		Implements the TPM_FieldUpgradeComplete command (TPM1.2 vendor specific command)
 *	@details	The module receives the input parameters marshals these parameters
 *				to a byte array sends the command to the TPM and unmarshals the response
 *				back to the out parameters
 *	@file		TPM_FieldUpgradeComplete.c
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

#include "TPM_FieldUpgradeComplete.h"
#include "TPM2_Marshal.h"
#include "TPM2_FieldUpgradeMarshal.h"
#include "DeviceManagement.h"
#include "TPM_Types.h"
#include "Platform.h"

/**
 *	@brief		This function handles the TPM_FieldUpgradeComplete command (TPM1.2 vendor specific command)
 *	@details	The function receives the input parameters marshals these parameters
 *				to a byte array sends the command to the TPM and unmarshals the response
 *				back to the out parameters
 *
 *	@param		PusCompleteSize			Size of the byte complete data (should be zero)
 *	@param		PrgbComplete			Byte array with the complete data (should be empty)
 *	@param		PpusOutCompleteSize		Pointer to the complete size return value (should be zero)
 */
_Check_return_
unsigned int
TSS_TPM_FieldUpgradeComplete(
	_In_							uint16_t		PusCompleteSize,
	_In_bytecount_(PusCompleteSize)	const uint8_t*	PrgbComplete,
	_Out_							uint16_t*		PpusOutCompleteSize)
{
	unsigned int unReturnValue = RC_SUCCESS;

	do
	{
		BYTE rgbRequest[MAX_COMMAND_SIZE] = {0};
		BYTE rgbResponse[MAX_RESPONSE_SIZE] = {0};
		BYTE* pbBuffer = rgbRequest;
		INT32 nSizeRemaining = sizeof(rgbRequest), nSizeResponse = sizeof(rgbResponse);

		// Request parameters
		TPM_ST tag = TPM_TAG_RQU_COMMAND;
		UINT32 unCommandSize = 0;
		TPM_CC commandCode = TPM_CC_FieldUpgradeCommand;
		SubCmd_d subCommand = TPM_FieldUpgradeComplete;

		// Response parameters
		UINT32 unResponseSize = 0;
		TPM_RC responseCode = TPM_RC_SUCCESS;

		// LRC
		BYTE bLRC = 0;
		BYTE* pbLRCBuffer = NULL;

		// Initialize _Out_ parameters
		unReturnValue = Platform_MemorySet(PpusOutCompleteSize, 0x00, sizeof(uint16_t));
		if (RC_SUCCESS != unReturnValue)
			break;

		// Marshal the request
		unReturnValue = TSS_TPMI_ST_COMMAND_TAG_Marshal(&tag, &pbBuffer, &nSizeRemaining);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_UINT32_Marshal(&unCommandSize, &pbBuffer, &nSizeRemaining);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_TPM_CC_Marshal(&commandCode, &pbBuffer, &nSizeRemaining);
		if (RC_SUCCESS != unReturnValue)
			break;

		// Store position for LRC calculation
		pbLRCBuffer = pbBuffer;

		// Sub Command
		unReturnValue = TSS_SubCmd_d_Marshal(&subCommand, &pbBuffer, &nSizeRemaining);
		if (RC_SUCCESS != unReturnValue)
			break;

		// Complete Data Size
		unReturnValue = TSS_UINT16_Marshal(&PusCompleteSize, &pbBuffer, &nSizeRemaining);
		if (RC_SUCCESS != unReturnValue)
			break;
		// Complete Data
		unReturnValue = TSS_UINT8_Array_Marshal(PrgbComplete, &pbBuffer, &nSizeRemaining, PusCompleteSize);
		if (RC_SUCCESS != unReturnValue)
			break;

		// Calculate and marshal LRC
		bLRC = TSS_CalcLRC(pbLRCBuffer, (uint32_t) (pbBuffer - pbLRCBuffer));
		unReturnValue = TSS_UINT8_Marshal(&bLRC, &pbBuffer, &nSizeRemaining);
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
		unReturnValue = TSS_TPM_ST_Unmarshal(&tag, &pbBuffer, &nSizeRemaining);
		if (TPM_RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_UINT32_Unmarshal(&unResponseSize, &pbBuffer, &nSizeRemaining);
		if (TPM_RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_TPM_RC_Unmarshal(&responseCode, &pbBuffer, &nSizeRemaining);
		if (TPM_RC_SUCCESS != unReturnValue)
			break;
		if (responseCode != TPM_RC_SUCCESS)
		{
			unReturnValue = RC_TPM_MASK | responseCode;
			break;
		}
		// Unmarshal out complete size
		unReturnValue = TSS_UINT16_Unmarshal(PpusOutCompleteSize, &pbBuffer, &nSizeRemaining);
		if (TPM_RC_SUCCESS != unReturnValue)
			break;
	}
	WHILE_FALSE_END;

	return unReturnValue;
}
