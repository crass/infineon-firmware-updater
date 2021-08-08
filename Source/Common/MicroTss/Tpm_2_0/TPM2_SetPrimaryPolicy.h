﻿/**
 *	@brief		Declares the TPM2_SetPrimaryPolicy method
 *	@file		TPM2_SetPrimaryPolicy.h
 *	@details	This file was auto-generated based on TPM2.0 specification revision 116.
 */
#pragma once
#include "TPM2_Types.h"

/**
 *	@brief	Implementation of TPM2_SetPrimaryPolicy command.
 *
 *	@retval TPM_RC_SIZE						size of input authPolicy is not consistent with input hash algorithm
 */
_Check_return_
unsigned int
TSS_TPM2_SetPrimaryPolicy(
	_In_	TPMI_RH_HIERARCHY_AUTH			authHandle,
	_In_	AuthorizationCommandData		authHandleSessionRequestData,
	_In_	TPM2B_DIGEST					authPolicy,
	_In_	TPMI_ALG_HASH					hashAlg,
	_Out_	AcknowledgmentResponseData*		pAuthHandleSessionResponseData
);