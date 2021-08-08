﻿/**
 *	@brief		Implements the TPM2_PolicySecret method
 *	@file		TPM2_PolicySecret.c
 *	@details	This file was auto-generated based on TPM2.0 specification revision 116.
 */
#include "TPM2_PolicySecret.h"
#include "TPM2_Marshal.h"
#include "DeviceManagement.h"
#include "Platform.h"
#include "StdInclude.h"

/**
 *	@brief	Implementation of TPM2_PolicySecret command.
 *
 *	@retval TPM_RC_CPHASH					cpHash for policy was previously set to a value that is not the same as cpHashA
 *	@retval TPM_RC_EXPIRED					expiration indicates a time in the past
 *	@retval TPM_RC_NONCE					nonceTPM does not match the nonce associated with policySession
 *	@retval TPM_RC_SIZE						cpHashA is not the size of a digest for the hash associated with policySession
 *	@retval TPM_RC_VALUE					input policyID or expiration does not match the internal data in policy session
 */
_Check_return_
unsigned int
TSS_TPM2_PolicySecret(
	_In_	TPMI_DH_ENTITY					authHandle,
	_In_	AuthorizationCommandData		authHandleSessionRequestData,
	_In_	TPMI_SH_POLICY					policySession,
	_In_	TPM2B_NONCE						nonceTPM,
	_In_	TPM2B_DIGEST					cpHashA,
	_In_	TPM2B_NONCE						policyRef,
	_In_	INT32							expiration,
	_Out_	TPM2B_TIMEOUT*					pTimeout,
	_Out_	TPMT_TK_AUTH*					pPolicyTicket,
	_Out_	AcknowledgmentResponseData*		pAuthHandleSessionResponseData
)
{
	unsigned int unReturnValue = RC_SUCCESS;
	do
	{
		BYTE rgbRequest[MAX_COMMAND_SIZE] = {0};
		BYTE rgbResponse[MAX_RESPONSE_SIZE] = {0};
		BYTE* pbBuffer = NULL;
		INT32 nSizeRemaining = sizeof(rgbRequest);
		INT32 nSizeResponse = sizeof(rgbResponse);
		UINT32 unParameterSize = 0;
		// Request parameters
		TPM_ST tag = TPM_ST_SESSIONS;
		UINT32 unCommandSize = 0;
		TPM_CC commandCode = TPM_CC_PolicySecret;
		// Response parameters
		UINT32 unResponseSize = 0;
		TPM_RC responseCode = TPM_RC_SUCCESS;

		// Initialize _Out_ parameters
		unReturnValue |= Platform_MemorySet(pTimeout, 0x00, sizeof(TPM2B_TIMEOUT));
		unReturnValue |= Platform_MemorySet(pPolicyTicket, 0x00, sizeof(TPMT_TK_AUTH));
		unReturnValue |= Platform_MemorySet(pAuthHandleSessionResponseData, 0x00, sizeof(AcknowledgmentResponseData));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Marshal the request
		pbBuffer = rgbRequest;
		unReturnValue = TSS_TPMI_ST_COMMAND_TAG_Marshal(&tag, &pbBuffer, &nSizeRemaining);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_UINT32_Marshal(&unCommandSize, &pbBuffer, &nSizeRemaining);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_TPM_CC_Marshal(&commandCode, &pbBuffer, &nSizeRemaining);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_TPMI_DH_ENTITY_Marshal(&authHandle, &pbBuffer, &nSizeRemaining);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_TPMI_SH_POLICY_Marshal(&policySession, &pbBuffer, &nSizeRemaining);
		if (RC_SUCCESS != unReturnValue)
			break;
		// Marshal Session Context
		{
			UINT32 unSizeSessionData = 0;
			INT32 nSizeRemain = sizeof(UINT32);
			BYTE* prgbPositionOfSize = pbBuffer;
			unReturnValue = TSS_UINT32_Marshal(&unSizeSessionData, &pbBuffer, &nSizeRemaining);
			if (RC_SUCCESS != unReturnValue)
				break;
			unReturnValue = TSS_AuthorizationCommandData_Marshal(&authHandleSessionRequestData, &pbBuffer, &nSizeRemaining);
			if (RC_SUCCESS != unReturnValue)
				break;
			// Overwrite authorization data size
			unSizeSessionData = (UINT32) (pbBuffer - (prgbPositionOfSize + nSizeRemain));
			unReturnValue = TSS_UINT32_Marshal(&unSizeSessionData, &prgbPositionOfSize, &nSizeRemain);
			if (RC_SUCCESS != unReturnValue)
				break;
		}
		unReturnValue = TSS_TPM2B_NONCE_Marshal(&nonceTPM, &pbBuffer, &nSizeRemaining);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_TPM2B_DIGEST_Marshal(&cpHashA, &pbBuffer, &nSizeRemaining);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_TPM2B_NONCE_Marshal(&policyRef, &pbBuffer, &nSizeRemaining);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_INT32_Marshal(&expiration, &pbBuffer, &nSizeRemaining);
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
		// Unmarshal the parameter size
		unReturnValue = TSS_UINT32_Unmarshal(&unParameterSize, &pbBuffer, &nSizeRemaining);
		if (TPM_RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_TPM2B_TIMEOUT_Unmarshal(pTimeout, &pbBuffer, &nSizeRemaining);
		if (TPM_RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_TPMT_TK_AUTH_Unmarshal(pPolicyTicket, &pbBuffer, &nSizeRemaining);
		if (TPM_RC_SUCCESS != unReturnValue)
			break;
		// Unmarshal Session Context
		{
			unReturnValue = TSS_AcknowledgmentResponseData_Unmarshal(pAuthHandleSessionResponseData, &pbBuffer, &nSizeRemaining);
			if (RC_SUCCESS != unReturnValue)
				break;
		}
	}
	WHILE_FALSE_END;
	return unReturnValue;
}