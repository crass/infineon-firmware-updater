﻿/**
 *	@brief		Implements the TPM2_Marshal method
 *	@file		TPM2_Marshal.c
 *	@details	This file was auto-generated based on TPM2.0 specification revision 116.
 */

#include "TPM2_Marshal.h"
#include "swap.h"
#include "Platform.h"
#include "../StdInclude.h"
#include "TPM2_FieldUpgradeMarshal.h"
/**
 *	@brief		Marshals a UINT8 type
 *	@details	Refer to: Table 3 - Definition of Base Types
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_UINT8_Marshal(
	_In_	const UINT8*	PpSource,
	_Inout_	BYTE**			PprgbBuffer,
	_Inout_	INT32*			PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	// Check parameters
	if ((NULL == PpSource) || (NULL == PprgbBuffer) || (NULL == PpnSize))
	{
		unReturnValue = RC_E_BAD_PARAMETER;
	}
	else
	{
		// Check size
		if (*PpnSize < 1)
			unReturnValue = RC_E_BUFFER_TOO_SMALL;
		else
		{
			UINT8_TO_BYTE_ARRAY(*PpSource, *PprgbBuffer);
			*PprgbBuffer += 1;
			*PpnSize -= 1;
			unReturnValue = RC_SUCCESS;
		}
	}
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a UINT8 type
 *	@details	Refer to: Table 3 - Definition of Base Types
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_UINT8_Unmarshal(
	_Out_	UINT8*		PpTarget,
	_Inout_	BYTE**		PprgbBuffer,
	_Inout_	INT32*		PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(UINT8));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		// Check size
		if (*PpnSize < 1)
		{
			unReturnValue = RC_E_BUFFER_TOO_SMALL;
			break;
		}
		*PpTarget = BYTE_ARRAY_TO_UINT8(*PprgbBuffer);
		*PprgbBuffer += 1;
		*PpnSize -= 1;
		unReturnValue = RC_SUCCESS;
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Marshals a UINT8 array
 *	@details	Refer to: Table 3 - Definition of Base Types
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *	@param		PnCount		Number of elements
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_UINT8_Array_Marshal(
	_In_	const UINT8*	PpSource,
	_Inout_	BYTE**			PprgbBuffer,
	_Inout_	INT32*			PpnSize,
	_In_	INT32			PnCount)
{
	unsigned int unReturnValue = RC_E_FAIL;
	// Check parameters
	if ((NULL == PpSource) || (NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
	{
		unReturnValue = RC_E_BAD_PARAMETER;
	}
	else
	{
		INT32 nPos;
		unReturnValue = RC_SUCCESS;
		// Marshal byte by byte to the buffer
		for (nPos = 0; nPos < PnCount; nPos++)
		{
			unReturnValue = TSS_UINT8_Marshal(&PpSource[nPos], PprgbBuffer, PpnSize);
			if (RC_SUCCESS != unReturnValue)
				break;
		}
	}
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a UINT8 array
 *	@details	Refer to: Table 3 - Definition of Base Types
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *	@param		PnCount		Number of elements
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_UINT8_Array_Unmarshal(
	_Out_	UINT8*		PpTarget,
	_Inout_	BYTE**		PprgbBuffer,
	_Inout_	INT32*		PpnSize,
	_In_	INT32		PnCount)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(UINT8));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		{
			INT32 nPos;
			for (nPos = 0; nPos < PnCount; nPos++)
			{
				unReturnValue = TSS_UINT8_Unmarshal(&PpTarget[nPos], PprgbBuffer, PpnSize);
				if (RC_SUCCESS != unReturnValue)
					break;
			}
		}
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Marshals a BYTE type
 *	@details	Refer to: Table 3 - Definition of Base Types
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_BYTE_Marshal(
	_In_	const BYTE*		PpSource,
	_Inout_	BYTE**			PprgbBuffer,
	_Inout_	INT32*			PpnSize)
{
	return TSS_UINT8_Marshal((UINT8*) PpSource, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Unmarshals a BYTE type
 *	@details	Refer to: Table 3 - Definition of Base Types
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_BYTE_Unmarshal(
	_Out_	BYTE*		PpTarget,
	_Inout_	BYTE**		PprgbBuffer,
	_Inout_	INT32*		PpnSize)
{
	return TSS_UINT8_Unmarshal((UINT8*) PpTarget, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Marshals a BYTE array
 *	@details	Refer to: Table 3 - Definition of Base Types
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *	@param		PnCount		Number of elements
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_BYTE_Array_Marshal(
	_In_	const BYTE*		PpSource,
	_Inout_	BYTE**			PprgbBuffer,
	_Inout_	INT32*			PpnSize,
	_In_	INT32			PnCount)
{
	unsigned int unReturnValue = RC_E_FAIL;
	// Check parameters
	if ((NULL == PpSource) || (NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
	{
		unReturnValue = RC_E_BAD_PARAMETER;
	}
	else
	{
		INT32 nPos;
		unReturnValue = RC_SUCCESS;
		// Marshal byte by byte to the buffer
		for (nPos = 0; nPos < PnCount; nPos++)
		{
			unReturnValue = TSS_BYTE_Marshal(&PpSource[nPos], PprgbBuffer, PpnSize);
			if (RC_SUCCESS != unReturnValue)
				break;
		}
	}
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a BYTE array
 *	@details	Refer to: Table 3 - Definition of Base Types
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *	@param		PnCount		Number of elements
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_BYTE_Array_Unmarshal(
	_Out_	BYTE*		PpTarget,
	_Inout_	BYTE**		PprgbBuffer,
	_Inout_	INT32*		PpnSize,
	_In_	INT32		PnCount)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(BYTE));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		{
			INT32 nPos;
			for (nPos = 0; nPos < PnCount; nPos++)
			{
				unReturnValue = TSS_BYTE_Unmarshal(&PpTarget[nPos], PprgbBuffer, PpnSize);
				if (RC_SUCCESS != unReturnValue)
					break;
			}
		}
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Marshals a BOOL type
 *	@details	Refer to: Table 3 - Definition of Base Types
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_BOOL_Marshal(
	_In_	const BOOL*		PpSource,
	_Inout_	BYTE**			PprgbBuffer,
	_Inout_	INT32*			PpnSize)
{
	return TSS_UINT8_Marshal((UINT8*) PpSource, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Unmarshals a BOOL type
 *	@details	Refer to: Table 3 - Definition of Base Types
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_BOOL_Unmarshal(
	_Out_	BOOL*		PpTarget,
	_Inout_	BYTE**		PprgbBuffer,
	_Inout_	INT32*		PpnSize)
{
	return TSS_UINT8_Unmarshal((UINT8*) PpTarget, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Marshals a UINT16 type
 *	@details	Refer to: Table 3 - Definition of Base Types
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_UINT16_Marshal(
	_In_	const UINT16*		PpSource,
	_Inout_	BYTE**				PprgbBuffer,
	_Inout_	INT32*				PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	// Check parameters
	if ((NULL == PpSource) || (NULL == PprgbBuffer) || (NULL == PpnSize))
	{
		unReturnValue = RC_E_BAD_PARAMETER;
	}
	else
	{
		// Check size
		if (*PpnSize < 2)
			unReturnValue = RC_E_BUFFER_TOO_SMALL;
		else
		{
			UINT16_TO_BYTE_ARRAY(*PpSource, *PprgbBuffer);
			*PprgbBuffer += 2;
			*PpnSize -= 2;
			unReturnValue = RC_SUCCESS;
		}
	}
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a UINT16 type
 *	@details	Refer to: Table 3 - Definition of Base Types
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_UINT16_Unmarshal(
	_Out_	UINT16*		PpTarget,
	_Inout_	BYTE**		PprgbBuffer,
	_Inout_	INT32*		PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(UINT16));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		// Check size
		if (*PpnSize < 2)
		{
			unReturnValue = RC_E_BUFFER_TOO_SMALL;
			break;
		}
		*PpTarget = BYTE_ARRAY_TO_UINT16(*PprgbBuffer);
		*PprgbBuffer += 2;
		*PpnSize -= 2;
		unReturnValue = RC_SUCCESS;
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Marshals a UINT32 type
 *	@details	Refer to: Table 3 - Definition of Base Types
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_UINT32_Marshal(
	_In_	const UINT32*		PpSource,
	_Inout_	BYTE**				PprgbBuffer,
	_Inout_	INT32*				PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	// Check parameters
	if ((NULL == PpSource) || (NULL == PprgbBuffer) || (NULL == PpnSize))
	{
		unReturnValue = RC_E_BAD_PARAMETER;
	}
	else
	{
		// Check size
		if (*PpnSize < 4)
			unReturnValue = RC_E_BUFFER_TOO_SMALL;
		else
		{
			UINT32_TO_BYTE_ARRAY(*PpSource, *PprgbBuffer);
			*PprgbBuffer += 4;
			*PpnSize -= 4;
			unReturnValue = RC_SUCCESS;
		}
	}
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a UINT32 type
 *	@details	Refer to: Table 3 - Definition of Base Types
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_UINT32_Unmarshal(
	_Out_	UINT32*		PpTarget,
	_Inout_	BYTE**		PprgbBuffer,
	_Inout_	INT32*		PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(UINT32));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		// Check size
		if (*PpnSize < 4)
		{
			unReturnValue = RC_E_BUFFER_TOO_SMALL;
			break;
		}
		*PpTarget = BYTE_ARRAY_TO_UINT32(*PprgbBuffer);
		*PprgbBuffer += 4;
		*PpnSize -= 4;
		unReturnValue = RC_SUCCESS;
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Marshals a UINT32 array
 *	@details	Refer to: Table 3 - Definition of Base Types
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *	@param		PnCount		Number of elements
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_UINT32_Array_Marshal(
	_In_	const UINT32*		PpSource,
	_Inout_	BYTE**				PprgbBuffer,
	_Inout_	INT32*				PpnSize,
	_In_	INT32				PnCount)
{
	unsigned int unReturnValue = RC_E_FAIL;
	// Check parameters
	if ((NULL == PpSource) || (NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
	{
		unReturnValue = RC_E_BAD_PARAMETER;
	}
	else
	{
		INT32 nPos;
		unReturnValue = RC_SUCCESS;
		// Marshal byte by byte to the buffer
		for (nPos = 0; nPos < PnCount; nPos++)
		{
			unReturnValue = TSS_UINT32_Marshal(&PpSource[nPos], PprgbBuffer, PpnSize);
			if (RC_SUCCESS != unReturnValue)
				break;
		}
	}
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a UINT32 array
 *	@details	Refer to: Table 3 - Definition of Base Types
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *	@param		PnCount		Number of elements
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_UINT32_Array_Unmarshal(
	_Out_	UINT32*		PpTarget,
	_Inout_	BYTE**		PprgbBuffer,
	_Inout_	INT32*		PpnSize,
	_In_	INT32		PnCount)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(UINT32));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		{
			INT32 nPos;
			for (nPos = 0; nPos < PnCount; nPos++)
			{
				unReturnValue = TSS_UINT32_Unmarshal(&PpTarget[nPos], PprgbBuffer, PpnSize);
				if (RC_SUCCESS != unReturnValue)
					break;
			}
		}
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Marshals a INT32 type
 *	@details	Refer to: Table 3 - Definition of Base Types
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_INT32_Marshal(
	_In_	const INT32*	PpSource,
	_Inout_	BYTE**			PprgbBuffer,
	_Inout_	INT32*			PpnSize)
{
	return TSS_UINT32_Marshal((UINT32*) PpSource, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Marshals a TPM_ALGORITHM_ID type
 *	@details	Refer to: Table 5 - Definition of Types for Documentation Clarity
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM_ALGORITHM_ID_Marshal(
	_In_	const TPM_ALGORITHM_ID*		PpSource,
	_Inout_	BYTE**						PprgbBuffer,
	_Inout_	INT32*						PpnSize)
{
	return TSS_UINT32_Marshal((UINT32*) PpSource, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Unmarshals a TPM_ALGORITHM_ID type
 *	@details	Refer to: Table 5 - Definition of Types for Documentation Clarity
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM_ALGORITHM_ID_Unmarshal(
	_Out_	TPM_ALGORITHM_ID*		PpTarget,
	_Inout_	BYTE**					PprgbBuffer,
	_Inout_	INT32*					PpnSize)
{
	return TSS_UINT32_Unmarshal((UINT32 *)PpTarget, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Marshals a TPM_KEY_BITS type
 *	@details	Refer to: Table 5 - Definition of Types for Documentation Clarity
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM_KEY_BITS_Marshal(
	_In_	const TPM_KEY_BITS*		PpSource,
	_Inout_	BYTE**					PprgbBuffer,
	_Inout_	INT32*					PpnSize)
{
	return TSS_UINT16_Marshal((UINT16*) PpSource, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Marshals a TPM_ALG_ID type
 *	@details	Refer to: Table 9 - Definition of (UINT16) TPM_ALG_ID Constants [IN/OUT, S]
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM_ALG_ID_Marshal(
	_In_	const TPM_ALG_ID*		PpSource,
	_Inout_	BYTE**					PprgbBuffer,
	_Inout_	INT32*					PpnSize)
{
	return TSS_UINT16_Marshal((UINT16*) PpSource, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Unmarshals a TPM_ALG_ID type
 *	@details	Refer to: Table 9 - Definition of (UINT16) TPM_ALG_ID Constants [IN/OUT, S]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM_ALG_ID_Unmarshal(
	_Out_	TPM_ALG_ID*		PpTarget,
	_Inout_	BYTE**			PprgbBuffer,
	_Inout_	INT32*			PpnSize)
{
	return TSS_UINT16_Unmarshal((UINT16 *)PpTarget, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Unmarshals a TPM_ECC_CURVE type
 *	@details	Refer to: Table 10 - Definition of (UINT16) {ECC} TPM_ECC_CURVE Constants [IN/OUT, S]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM_ECC_CURVE_Unmarshal(
	_Out_	TPM_ECC_CURVE*		PpTarget,
	_Inout_	BYTE**				PprgbBuffer,
	_Inout_	INT32*				PpnSize)
{
	return TSS_UINT16_Unmarshal((UINT16 *)PpTarget, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Unmarshals a TPM_ECC_CURVE array
 *	@details	Refer to: Table 10 - Definition of (UINT16) {ECC} TPM_ECC_CURVE Constants [IN/OUT, S]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *	@param		PnCount		Number of elements
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM_ECC_CURVE_Array_Unmarshal(
	_Out_	TPM_ECC_CURVE*		PpTarget,
	_Inout_	BYTE**				PprgbBuffer,
	_Inout_	INT32*				PpnSize,
	_In_	INT32				PnCount)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(TPM_ECC_CURVE));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		{
			INT32 nPos;
			for (nPos = 0; nPos < PnCount; nPos++)
			{
				unReturnValue = TSS_TPM_ECC_CURVE_Unmarshal(&PpTarget[nPos], PprgbBuffer, PpnSize);
				if (RC_SUCCESS != unReturnValue)
					break;
			}
		}
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Marshals a TPM_CC type
 *	@details	Refer to: Table 13 - Definition of (UINT32) TPM_CC Constants (Numeric Order) [IN/OUT, S]
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM_CC_Marshal(
	_In_	const TPM_CC*		PpSource,
	_Inout_	BYTE**				PprgbBuffer,
	_Inout_	INT32*				PpnSize)
{
	return TSS_UINT32_Marshal((UINT32*) PpSource, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Unmarshals a TPM_CC type
 *	@details	Refer to: Table 13 - Definition of (UINT32) TPM_CC Constants (Numeric Order) [IN/OUT, S]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM_CC_Unmarshal(
	_Out_	TPM_CC*		PpTarget,
	_Inout_	BYTE**		PprgbBuffer,
	_Inout_	INT32*		PpnSize)
{
	return TSS_UINT32_Unmarshal((UINT32 *)PpTarget, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Unmarshals a TPM_CC array
 *	@details	Refer to: Table 13 - Definition of (UINT32) TPM_CC Constants (Numeric Order) [IN/OUT, S]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *	@param		PnCount		Number of elements
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM_CC_Array_Unmarshal(
	_Out_	TPM_CC*		PpTarget,
	_Inout_	BYTE**		PprgbBuffer,
	_Inout_	INT32*		PpnSize,
	_In_	INT32		PnCount)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(TPM_CC));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		{
			INT32 nPos;
			for (nPos = 0; nPos < PnCount; nPos++)
			{
				unReturnValue = TSS_TPM_CC_Unmarshal(&PpTarget[nPos], PprgbBuffer, PpnSize);
				if (RC_SUCCESS != unReturnValue)
					break;
			}
		}
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a TPM_RC type
 *	@details	Refer to: Table 17 - Definition of (UINT32) TPM_RC Constants (Actions) [OUT]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM_RC_Unmarshal(
	_Out_	TPM_RC*		PpTarget,
	_Inout_	BYTE**		PprgbBuffer,
	_Inout_	INT32*		PpnSize)
{
	return TSS_UINT32_Unmarshal((UINT32 *)PpTarget, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Marshals a TPM_ST type
 *	@details	Refer to: Table 20 - Definition of (UINT16) TPM_ST Constants [IN/OUT, S]
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM_ST_Marshal(
	_In_	const TPM_ST*		PpSource,
	_Inout_	BYTE**				PprgbBuffer,
	_Inout_	INT32*				PpnSize)
{
	return TSS_UINT16_Marshal((UINT16*) PpSource, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Unmarshals a TPM_ST type
 *	@details	Refer to: Table 20 - Definition of (UINT16) TPM_ST Constants [IN/OUT, S]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM_ST_Unmarshal(
	_Out_	TPM_ST*		PpTarget,
	_Inout_	BYTE**		PprgbBuffer,
	_Inout_	INT32*		PpnSize)
{
	return TSS_UINT16_Unmarshal((UINT16 *)PpTarget, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Marshals a TPM_SU type
 *	@details	Refer to: Table 21 - Definition of (UINT16) TPM_SU Constants [IN]
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM_SU_Marshal(
	_In_	const TPM_SU*		PpSource,
	_Inout_	BYTE**				PprgbBuffer,
	_Inout_	INT32*				PpnSize)
{
	return TSS_UINT16_Marshal((UINT16*) PpSource, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Marshals a TPM_SE type
 *	@details	Refer to: Table 22 - Definition of (UINT8) TPM_SE Constants [IN]
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM_SE_Marshal(
	_In_	const TPM_SE*		PpSource,
	_Inout_	BYTE**				PprgbBuffer,
	_Inout_	INT32*				PpnSize)
{
	return TSS_UINT8_Marshal((UINT8*) PpSource, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Marshals a TPM_CAP type
 *	@details	Refer to: Table 23 - Definition of (UINT32) TPM_CAP Constants
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM_CAP_Marshal(
	_In_	const TPM_CAP*		PpSource,
	_Inout_	BYTE**				PprgbBuffer,
	_Inout_	INT32*				PpnSize)
{
	return TSS_UINT32_Marshal((UINT32*) PpSource, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Unmarshals a TPM_CAP type
 *	@details	Refer to: Table 23 - Definition of (UINT32) TPM_CAP Constants
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM_CAP_Unmarshal(
	_Out_	TPM_CAP*	PpTarget,
	_Inout_	BYTE**		PprgbBuffer,
	_Inout_	INT32*		PpnSize)
{
	return TSS_UINT32_Unmarshal((UINT32 *)PpTarget, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Unmarshals a TPM_PT type
 *	@details	Refer to: Table 24 - Definition of (UINT32) TPM_PT Constants [IN/OUT, S]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM_PT_Unmarshal(
	_Out_	TPM_PT*		PpTarget,
	_Inout_	BYTE**		PprgbBuffer,
	_Inout_	INT32*		PpnSize)
{
	return TSS_UINT32_Unmarshal((UINT32 *)PpTarget, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Marshals a TPM_HANDLE type
 *	@details	Refer to: Table 27 - Definition of Types for Handles
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM_HANDLE_Marshal(
	_In_	const TPM_HANDLE*		PpSource,
	_Inout_	BYTE**					PprgbBuffer,
	_Inout_	INT32*					PpnSize)
{
	return TSS_UINT32_Marshal((UINT32*) PpSource, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Unmarshals a TPM_HANDLE type
 *	@details	Refer to: Table 27 - Definition of Types for Handles
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM_HANDLE_Unmarshal(
	_Out_	TPM_HANDLE*		PpTarget,
	_Inout_	BYTE**			PprgbBuffer,
	_Inout_	INT32*			PpnSize)
{
	return TSS_UINT32_Unmarshal((UINT32 *)PpTarget, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Unmarshals a TPM_HANDLE array
 *	@details	Refer to: Table 27 - Definition of Types for Handles
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *	@param		PnCount		Number of elements
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM_HANDLE_Array_Unmarshal(
	_Out_	TPM_HANDLE*		PpTarget,
	_Inout_	BYTE**			PprgbBuffer,
	_Inout_	INT32*			PpnSize,
	_In_	INT32			PnCount)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(TPM_HANDLE));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		{
			INT32 nPos;
			for (nPos = 0; nPos < PnCount; nPos++)
			{
				unReturnValue = TSS_TPM_HANDLE_Unmarshal(&PpTarget[nPos], PprgbBuffer, PpnSize);
				if (RC_SUCCESS != unReturnValue)
					break;
			}
		}
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a TPMA_ALGORITHM type
 *	@details	Refer to: Table 31 - Definition of (UINT32) TPMA_ALGORITHM Bits
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMA_ALGORITHM_Unmarshal(
	_Out_	TPMA_ALGORITHM*		PpTarget,
	_Inout_	BYTE**				PprgbBuffer,
	_Inout_	INT32*				PpnSize)
{
	return TSS_UINT32_Unmarshal((UINT32 *)PpTarget, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Marshals a TPMA_SESSION type
 *	@details	Refer to: Table 33 - Definition of (UINT8) TPMA_SESSION Bits [IN/OUT]
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMA_SESSION_Marshal(
	_In_	const TPMA_SESSION*		PpSource,
	_Inout_	BYTE**					PprgbBuffer,
	_Inout_	INT32*					PpnSize)
{
	return TSS_UINT8_Marshal((UINT8*) PpSource, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Unmarshals a TPMA_SESSION type
 *	@details	Refer to: Table 33 - Definition of (UINT8) TPMA_SESSION Bits [IN/OUT]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMA_SESSION_Unmarshal(
	_Out_	TPMA_SESSION*		PpTarget,
	_Inout_	BYTE**				PprgbBuffer,
	_Inout_	INT32*				PpnSize)
{
	return TSS_UINT8_Unmarshal((UINT8 *)PpTarget, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Unmarshals a TPMA_CC type
 *	@details	Refer to: Table 38 - Definition of (TPM_CC) TPMA_CC Bits [OUT]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMA_CC_Unmarshal(
	_Out_	TPMA_CC*	PpTarget,
	_Inout_	BYTE**		PprgbBuffer,
	_Inout_	INT32*		PpnSize)
{
	return TSS_TPM_CC_Unmarshal((TPM_CC *)PpTarget, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Unmarshals a TPMA_CC array
 *	@details	Refer to: Table 38 - Definition of (TPM_CC) TPMA_CC Bits [OUT]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *	@param		PnCount		Number of elements
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMA_CC_Array_Unmarshal(
	_Out_	TPMA_CC*	PpTarget,
	_Inout_	BYTE**		PprgbBuffer,
	_Inout_	INT32*		PpnSize,
	_In_	INT32		PnCount)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(TPMA_CC));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		{
			INT32 nPos;
			for (nPos = 0; nPos < PnCount; nPos++)
			{
				unReturnValue = TSS_TPMA_CC_Unmarshal(&PpTarget[nPos], PprgbBuffer, PpnSize);
				if (RC_SUCCESS != unReturnValue)
					break;
			}
		}
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a TPMI_YES_NO type
 *	@details	Refer to: Table 39 - Definition of (BYTE) TPMI_YES_NO Type
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMI_YES_NO_Unmarshal(
	_Out_	TPMI_YES_NO*	PpTarget,
	_Inout_	BYTE**			PprgbBuffer,
	_Inout_	INT32*			PpnSize)
{
	return TSS_BYTE_Unmarshal((BYTE *)PpTarget, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Marshals a TPMI_DH_OBJECT type
 *	@details	Refer to: Table 40 - Definition of (TPM_HANDLE) TPMI_DH_OBJECT Type
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMI_DH_OBJECT_Marshal(
	_In_	const TPMI_DH_OBJECT*		PpSource,
	_Inout_	BYTE**						PprgbBuffer,
	_Inout_	INT32*						PpnSize)
{
	return TSS_TPM_HANDLE_Marshal((TPM_HANDLE*) PpSource, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Marshals a TPMI_DH_ENTITY type
 *	@details	Refer to: Table 42 - Definition of (TPM_HANDLE) TPMI_DH_ENTITY Type [IN]
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMI_DH_ENTITY_Marshal(
	_In_	const TPMI_DH_ENTITY*		PpSource,
	_Inout_	BYTE**						PprgbBuffer,
	_Inout_	INT32*						PpnSize)
{
	return TSS_TPM_HANDLE_Marshal((TPM_HANDLE*) PpSource, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Marshals a TPMI_SH_AUTH_SESSION type
 *	@details	Refer to: Table 44 - Definition of (TPM_HANDLE) TPMI_SH_AUTH_SESSION Type [IN/OUT]
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMI_SH_AUTH_SESSION_Marshal(
	_In_	const TPMI_SH_AUTH_SESSION*		PpSource,
	_Inout_	BYTE**							PprgbBuffer,
	_Inout_	INT32*							PpnSize)
{
	return TSS_TPM_HANDLE_Marshal((TPM_HANDLE*) PpSource, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Unmarshals a TPMI_SH_AUTH_SESSION type
 *	@details	Refer to: Table 44 - Definition of (TPM_HANDLE) TPMI_SH_AUTH_SESSION Type [IN/OUT]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMI_SH_AUTH_SESSION_Unmarshal(
	_Out_	TPMI_SH_AUTH_SESSION*		PpTarget,
	_Inout_	BYTE**						PprgbBuffer,
	_Inout_	INT32*						PpnSize)
{
	return TSS_TPM_HANDLE_Unmarshal((TPM_HANDLE *)PpTarget, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Marshals a TPMI_SH_POLICY type
 *	@details	Refer to: Table 46 - Definition of (TPM_HANDLE) TPMI_SH_POLICY Type [IN/OUT]
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMI_SH_POLICY_Marshal(
	_In_	const TPMI_SH_POLICY*		PpSource,
	_Inout_	BYTE**						PprgbBuffer,
	_Inout_	INT32*						PpnSize)
{
	return TSS_TPM_HANDLE_Marshal((TPM_HANDLE*) PpSource, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Marshals a TPMI_DH_CONTEXT type
 *	@details	Refer to: Table 47 - Definition of (TPM_HANDLE) TPMI_DH_CONTEXT Type
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMI_DH_CONTEXT_Marshal(
	_In_	const TPMI_DH_CONTEXT*		PpSource,
	_Inout_	BYTE**						PprgbBuffer,
	_Inout_	INT32*						PpnSize)
{
	return TSS_TPM_HANDLE_Marshal((TPM_HANDLE*) PpSource, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Unmarshals a TPMI_RH_HIERARCHY type
 *	@details	Refer to: Table 48 - Definition of (TPM_HANDLE) TPMI_RH_HIERARCHY Type
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMI_RH_HIERARCHY_Unmarshal(
	_Out_	TPMI_RH_HIERARCHY*		PpTarget,
	_Inout_	BYTE**					PprgbBuffer,
	_Inout_	INT32*					PpnSize)
{
	return TSS_TPM_HANDLE_Unmarshal((TPM_HANDLE *)PpTarget, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Marshals a TPMI_RH_HIERARCHY_AUTH type
 *	@details	Refer to: Table 50 - Definition of (TPM_HANDLE) TPMI_RH_HIERARCHY_AUTH Type [IN]
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMI_RH_HIERARCHY_AUTH_Marshal(
	_In_	const TPMI_RH_HIERARCHY_AUTH*		PpSource,
	_Inout_	BYTE**								PprgbBuffer,
	_Inout_	INT32*								PpnSize)
{
	return TSS_TPM_HANDLE_Marshal((TPM_HANDLE*) PpSource, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Marshals a TPMI_RH_PLATFORM type
 *	@details	Refer to: Table 51 - Definition of (TPM_HANDLE) TPMI_RH_PLATFORM Type [IN]
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMI_RH_PLATFORM_Marshal(
	_In_	const TPMI_RH_PLATFORM*		PpSource,
	_Inout_	BYTE**						PprgbBuffer,
	_Inout_	INT32*						PpnSize)
{
	return TSS_TPM_HANDLE_Marshal((TPM_HANDLE*) PpSource, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Marshals a TPMI_ALG_HASH type
 *	@details	Refer to: Table 59 - Definition of (TPM_ALG_ID) TPMI_ALG_HASH Type
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMI_ALG_HASH_Marshal(
	_In_	const TPMI_ALG_HASH*	PpSource,
	_Inout_	BYTE**					PprgbBuffer,
	_Inout_	INT32*					PpnSize)
{
	return TSS_TPM_ALG_ID_Marshal((TPM_ALG_ID*) PpSource, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Unmarshals a TPMI_ALG_HASH type
 *	@details	Refer to: Table 59 - Definition of (TPM_ALG_ID) TPMI_ALG_HASH Type
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMI_ALG_HASH_Unmarshal(
	_Out_	TPMI_ALG_HASH*		PpTarget,
	_Inout_	BYTE**				PprgbBuffer,
	_Inout_	INT32*				PpnSize)
{
	return TSS_TPM_ALG_ID_Unmarshal((TPM_ALG_ID *)PpTarget, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Marshals a TPMI_ALG_SYM type
 *	@details	Refer to: Table 61 - Definition of (TPM_ALG_ID) TPMI_ALG_SYM Type
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMI_ALG_SYM_Marshal(
	_In_	const TPMI_ALG_SYM*		PpSource,
	_Inout_	BYTE**					PprgbBuffer,
	_Inout_	INT32*					PpnSize)
{
	return TSS_TPM_ALG_ID_Marshal((TPM_ALG_ID*) PpSource, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Marshals a TPMI_ALG_SYM_MODE type
 *	@details	Refer to: Table 63 - Definition of (TPM_ALG_ID) TPMI_ALG_SYM_MODE Type
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMI_ALG_SYM_MODE_Marshal(
	_In_	const TPMI_ALG_SYM_MODE*	PpSource,
	_Inout_	BYTE**						PprgbBuffer,
	_Inout_	INT32*						PpnSize)
{
	return TSS_TPM_ALG_ID_Marshal((TPM_ALG_ID*) PpSource, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Marshals a TPMI_ST_COMMAND_TAG type
 *	@details	Refer to: Table 67 - Definition of (TPM_ST) TPMI_ST_COMMAND_TAG Type
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMI_ST_COMMAND_TAG_Marshal(
	_In_	const TPMI_ST_COMMAND_TAG*		PpSource,
	_Inout_	BYTE**							PprgbBuffer,
	_Inout_	INT32*							PpnSize)
{
	return TSS_TPM_ST_Marshal((TPM_ST*) PpSource, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Unmarshals a TPMI_ST_COMMAND_TAG type
 *	@details	Refer to: Table 67 - Definition of (TPM_ST) TPMI_ST_COMMAND_TAG Type
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMI_ST_COMMAND_TAG_Unmarshal(
	_Out_	TPMI_ST_COMMAND_TAG*	PpTarget,
	_Inout_	BYTE**					PprgbBuffer,
	_Inout_	INT32*					PpnSize)
{
	return TSS_TPM_ST_Unmarshal((TPM_ST *)PpTarget, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Marshals a TPM2B_DIGEST structure
 *	@details	Refer to: Table 72 - Definition of TPM2B_DIGEST Structure
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM2B_DIGEST_Marshal(
	_In_	const TPM2B_DIGEST*		PpSource,
	_Inout_	BYTE**					PprgbBuffer,
	_Inout_	INT32*					PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check parameters
		if ((NULL == PpSource) || (NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		// Check size for PpnSize parameter
		if (*PpnSize < (INT32) sizeof(PpSource->size))
		{
			unReturnValue = RC_E_BUFFER_TOO_SMALL;
			break;
		}
		// Marshal size
		unReturnValue = TSS_UINT16_Marshal((UINT16 *) & (PpSource->size), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check size for array
		if (*PpnSize < (INT32) PpSource->size)
		{
			unReturnValue = RC_E_BUFFER_TOO_SMALL;
			break;
		}
		// Marshal array
		unReturnValue = TSS_BYTE_Array_Marshal((BYTE *) & (PpSource->buffer), PprgbBuffer, PpnSize, PpSource->size);
		if (RC_SUCCESS != unReturnValue)
			break;
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a TPM2B_DIGEST structure
 *	@details	Refer to: Table 72 - Definition of TPM2B_DIGEST Structure
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM2B_DIGEST_Unmarshal(
	_Out_	TPM2B_DIGEST*		PpTarget,
	_Inout_	BYTE**				PprgbBuffer,
	_Inout_	INT32*				PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(TPM2B_DIGEST));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = TSS_UINT16_Unmarshal((UINT16 *) & (PpTarget->size), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_BYTE_Array_Unmarshal((BYTE *) & (PpTarget->buffer), PprgbBuffer, PpnSize, PpTarget->size);
		if (RC_SUCCESS != unReturnValue)
			break;
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Marshals a TPM2B_NONCE type
 *	@details	Refer to: Table 74 - Definition of Types for TPM2B_NONCE
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM2B_NONCE_Marshal(
	_In_	const TPM2B_NONCE*		PpSource,
	_Inout_	BYTE**					PprgbBuffer,
	_Inout_	INT32*					PpnSize)
{
	return TSS_TPM2B_DIGEST_Marshal((TPM2B_DIGEST*) PpSource, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Unmarshals a TPM2B_NONCE type
 *	@details	Refer to: Table 74 - Definition of Types for TPM2B_NONCE
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM2B_NONCE_Unmarshal(
	_Out_	TPM2B_NONCE*	PpTarget,
	_Inout_	BYTE**			PprgbBuffer,
	_Inout_	INT32*			PpnSize)
{
	return TSS_TPM2B_DIGEST_Unmarshal((TPM2B_DIGEST *)PpTarget, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Marshals a TPM2B_AUTH type
 *	@details	Refer to: Table 75 - Definition of Types for TPM2B_AUTH
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM2B_AUTH_Marshal(
	_In_	const TPM2B_AUTH*		PpSource,
	_Inout_	BYTE**					PprgbBuffer,
	_Inout_	INT32*					PpnSize)
{
	return TSS_TPM2B_DIGEST_Marshal((TPM2B_DIGEST*) PpSource, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Unmarshals a TPM2B_AUTH type
 *	@details	Refer to: Table 75 - Definition of Types for TPM2B_AUTH
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM2B_AUTH_Unmarshal(
	_Out_	TPM2B_AUTH*		PpTarget,
	_Inout_	BYTE**			PprgbBuffer,
	_Inout_	INT32*			PpnSize)
{
	return TSS_TPM2B_DIGEST_Unmarshal((TPM2B_DIGEST *)PpTarget, PprgbBuffer, PpnSize);
}

/**
 *	@brief		Unmarshals a TPM2B_MAX_BUFFER structure
 *	@details	Refer to: Table 78 - Definition of TPM2B_MAX_BUFFER Structure
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM2B_MAX_BUFFER_Unmarshal(
	_Out_	TPM2B_MAX_BUFFER*		PpTarget,
	_Inout_	BYTE**					PprgbBuffer,
	_Inout_	INT32*					PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(TPM2B_MAX_BUFFER));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = TSS_UINT16_Unmarshal((UINT16 *) & (PpTarget->size), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_BYTE_Array_Unmarshal((BYTE *) & (PpTarget->buffer), PprgbBuffer, PpnSize, PpTarget->size);
		if (RC_SUCCESS != unReturnValue)
			break;
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a TPM2B_MAX_BUFFER array
 *	@details	Refer to: Table 78 - Definition of TPM2B_MAX_BUFFER Structure
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *	@param		PnCount		Number of elements
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM2B_MAX_BUFFER_Array_Unmarshal(
	_Out_	TPM2B_MAX_BUFFER*		PpTarget,
	_Inout_	BYTE**					PprgbBuffer,
	_Inout_	INT32*					PpnSize,
	_In_	INT32					PnCount)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(TPM2B_MAX_BUFFER));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		{
			INT32 nPos;
			for (nPos = 0; nPos < PnCount; nPos++)
			{
				unReturnValue = TSS_TPM2B_MAX_BUFFER_Unmarshal(&PpTarget[nPos], PprgbBuffer, PpnSize);
				if (RC_SUCCESS != unReturnValue)
					break;
			}
		}
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a TPM2B_TIMEOUT structure
 *	@details	Refer to: Table 80 - Definition of TPM2B_TIMEOUT Structure [IN/OUT]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM2B_TIMEOUT_Unmarshal(
	_Out_	TPM2B_TIMEOUT*		PpTarget,
	_Inout_	BYTE**				PprgbBuffer,
	_Inout_	INT32*				PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(TPM2B_TIMEOUT));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = TSS_UINT16_Unmarshal((UINT16 *) & (PpTarget->size), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_BYTE_Array_Unmarshal((BYTE *) & (PpTarget->buffer), PprgbBuffer, PpnSize, PpTarget->size);
		if (RC_SUCCESS != unReturnValue)
			break;
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a TPMS_PCR_SELECTION structure
 *	@details	Refer to: Table 85 - Definition of TPMS_PCR_SELECTION Structure
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMS_PCR_SELECTION_Unmarshal(
	_Out_	TPMS_PCR_SELECTION*		PpTarget,
	_Inout_	BYTE**					PprgbBuffer,
	_Inout_	INT32*					PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(TPMS_PCR_SELECTION));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = TSS_TPMI_ALG_HASH_Unmarshal((TPMI_ALG_HASH *) & (PpTarget->hash), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_UINT8_Unmarshal((UINT8 *) & (PpTarget->sizeofSelect), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_BYTE_Array_Unmarshal((BYTE *) & (PpTarget->pcrSelect), PprgbBuffer, PpnSize, PpTarget->sizeofSelect);
		if (RC_SUCCESS != unReturnValue)
			break;
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a TPMS_PCR_SELECTION array
 *	@details	Refer to: Table 85 - Definition of TPMS_PCR_SELECTION Structure
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *	@param		PnCount		Number of elements
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMS_PCR_SELECTION_Array_Unmarshal(
	_Out_	TPMS_PCR_SELECTION*		PpTarget,
	_Inout_	BYTE**					PprgbBuffer,
	_Inout_	INT32*					PpnSize,
	_In_	INT32					PnCount)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(TPMS_PCR_SELECTION));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		{
			INT32 nPos;
			for (nPos = 0; nPos < PnCount; nPos++)
			{
				unReturnValue = TSS_TPMS_PCR_SELECTION_Unmarshal(&PpTarget[nPos], PprgbBuffer, PpnSize);
				if (RC_SUCCESS != unReturnValue)
					break;
			}
		}
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a TPMT_TK_AUTH structure
 *	@details	Refer to: Table 90 - Definition of TPMT_TK_AUTH Structure
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMT_TK_AUTH_Unmarshal(
	_Out_	TPMT_TK_AUTH*		PpTarget,
	_Inout_	BYTE**				PprgbBuffer,
	_Inout_	INT32*				PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(TPMT_TK_AUTH));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = TSS_TPM_ST_Unmarshal((TPM_ST *) & (PpTarget->tag), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_TPMI_RH_HIERARCHY_Unmarshal((TPMI_RH_HIERARCHY *) & (PpTarget->hierarchy), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_TPM2B_DIGEST_Unmarshal((TPM2B_DIGEST *) & (PpTarget->digest), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a TPMS_ALG_PROPERTY structure
 *	@details	Refer to: Table 92 - Definition of TPMS_ALG_PROPERTY Structure [OUT]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMS_ALG_PROPERTY_Unmarshal(
	_Out_	TPMS_ALG_PROPERTY*		PpTarget,
	_Inout_	BYTE**					PprgbBuffer,
	_Inout_	INT32*					PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(TPMS_ALG_PROPERTY));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = TSS_TPM_ALG_ID_Unmarshal((TPM_ALG_ID *) & (PpTarget->alg), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_TPMA_ALGORITHM_Unmarshal((TPMA_ALGORITHM *) & (PpTarget->algProperties), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a TPMS_ALG_PROPERTY array
 *	@details	Refer to: Table 92 - Definition of TPMS_ALG_PROPERTY Structure [OUT]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *	@param		PnCount		Number of elements
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMS_ALG_PROPERTY_Array_Unmarshal(
	_Out_	TPMS_ALG_PROPERTY*		PpTarget,
	_Inout_	BYTE**					PprgbBuffer,
	_Inout_	INT32*					PpnSize,
	_In_	INT32					PnCount)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(TPMS_ALG_PROPERTY));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		{
			INT32 nPos;
			for (nPos = 0; nPos < PnCount; nPos++)
			{
				unReturnValue = TSS_TPMS_ALG_PROPERTY_Unmarshal(&PpTarget[nPos], PprgbBuffer, PpnSize);
				if (RC_SUCCESS != unReturnValue)
					break;
			}
		}
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a TPMS_TAGGED_PROPERTY structure
 *	@details	Refer to: Table 93 - Definition of TPMS_TAGGED_PROPERTY Structure [OUT]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMS_TAGGED_PROPERTY_Unmarshal(
	_Out_	TPMS_TAGGED_PROPERTY*		PpTarget,
	_Inout_	BYTE**						PprgbBuffer,
	_Inout_	INT32*						PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(TPMS_TAGGED_PROPERTY));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = TSS_TPM_PT_Unmarshal((TPM_PT *) & (PpTarget->property), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_UINT32_Unmarshal((UINT32 *) & (PpTarget->value), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a TPMS_TAGGED_PROPERTY array
 *	@details	Refer to: Table 93 - Definition of TPMS_TAGGED_PROPERTY Structure [OUT]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *	@param		PnCount		Number of elements
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMS_TAGGED_PROPERTY_Array_Unmarshal(
	_Out_	TPMS_TAGGED_PROPERTY*		PpTarget,
	_Inout_	BYTE**						PprgbBuffer,
	_Inout_	INT32*						PpnSize,
	_In_	INT32						PnCount)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(TPMS_TAGGED_PROPERTY));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		{
			INT32 nPos;
			for (nPos = 0; nPos < PnCount; nPos++)
			{
				unReturnValue = TSS_TPMS_TAGGED_PROPERTY_Unmarshal(&PpTarget[nPos], PprgbBuffer, PpnSize);
				if (RC_SUCCESS != unReturnValue)
					break;
			}
		}
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a TPMS_TAGGED_PCR_SELECT structure
 *	@details	Refer to: Table 94 - Definition of TPMS_TAGGED_PCR_SELECT Structure [OUT]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMS_TAGGED_PCR_SELECT_Unmarshal(
	_Out_	TPMS_TAGGED_PCR_SELECT*		PpTarget,
	_Inout_	BYTE**						PprgbBuffer,
	_Inout_	INT32*						PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(TPMS_TAGGED_PCR_SELECT));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = TSS_TPM_PT_Unmarshal((TPM_PT *) & (PpTarget->tag), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_UINT8_Unmarshal((UINT8 *) & (PpTarget->sizeofSelect), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_BYTE_Array_Unmarshal((BYTE *) & (PpTarget->pcrSelect), PprgbBuffer, PpnSize, PpTarget->sizeofSelect);
		if (RC_SUCCESS != unReturnValue)
			break;
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a TPMS_TAGGED_PCR_SELECT array
 *	@details	Refer to: Table 94 - Definition of TPMS_TAGGED_PCR_SELECT Structure [OUT]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *	@param		PnCount		Number of elements
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMS_TAGGED_PCR_SELECT_Array_Unmarshal(
	_Out_	TPMS_TAGGED_PCR_SELECT*		PpTarget,
	_Inout_	BYTE**						PprgbBuffer,
	_Inout_	INT32*						PpnSize,
	_In_	INT32						PnCount)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(TPMS_TAGGED_PCR_SELECT));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		{
			INT32 nPos;
			for (nPos = 0; nPos < PnCount; nPos++)
			{
				unReturnValue = TSS_TPMS_TAGGED_PCR_SELECT_Unmarshal(&PpTarget[nPos], PprgbBuffer, PpnSize);
				if (RC_SUCCESS != unReturnValue)
					break;
			}
		}
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a TPML_CC structure
 *	@details	Refer to: Table 95 - Definition of TPML_CC Structure
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPML_CC_Unmarshal(
	_Out_	TPML_CC*	PpTarget,
	_Inout_	BYTE**		PprgbBuffer,
	_Inout_	INT32*		PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(TPML_CC));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = TSS_UINT32_Unmarshal((UINT32 *) & (PpTarget->count), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_TPM_CC_Array_Unmarshal((TPM_CC *) & (PpTarget->commandCodes), PprgbBuffer, PpnSize, PpTarget->count);
		if (RC_SUCCESS != unReturnValue)
			break;
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a TPML_CCA structure
 *	@details	Refer to: Table 96 - Definition of TPML_CCA Structure [OUT]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPML_CCA_Unmarshal(
	_Out_	TPML_CCA*		PpTarget,
	_Inout_	BYTE**			PprgbBuffer,
	_Inout_	INT32*			PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(TPML_CCA));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = TSS_UINT32_Unmarshal((UINT32 *) & (PpTarget->count), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_TPMA_CC_Array_Unmarshal((TPMA_CC *) & (PpTarget->commandAttributes), PprgbBuffer, PpnSize, PpTarget->count);
		if (RC_SUCCESS != unReturnValue)
			break;
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a TPML_HANDLE structure
 *	@details	Refer to: Table 98 - Definition of TPML_HANDLE Structure [OUT]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPML_HANDLE_Unmarshal(
	_Out_	TPML_HANDLE*	PpTarget,
	_Inout_	BYTE**			PprgbBuffer,
	_Inout_	INT32*			PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(TPML_HANDLE));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = TSS_UINT32_Unmarshal((UINT32 *) & (PpTarget->count), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_TPM_HANDLE_Array_Unmarshal((TPM_HANDLE *) & (PpTarget->handle), PprgbBuffer, PpnSize, PpTarget->count);
		if (RC_SUCCESS != unReturnValue)
			break;
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a TPML_PCR_SELECTION structure
 *	@details	Refer to: Table 102 - Definition of TPML_PCR_SELECTION Structure
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPML_PCR_SELECTION_Unmarshal(
	_Out_	TPML_PCR_SELECTION*		PpTarget,
	_Inout_	BYTE**					PprgbBuffer,
	_Inout_	INT32*					PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(TPML_PCR_SELECTION));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = TSS_UINT32_Unmarshal((UINT32 *) & (PpTarget->count), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_TPMS_PCR_SELECTION_Array_Unmarshal((TPMS_PCR_SELECTION *) & (PpTarget->pcrSelections), PprgbBuffer, PpnSize, PpTarget->count);
		if (RC_SUCCESS != unReturnValue)
			break;
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a TPML_ALG_PROPERTY structure
 *	@details	Refer to: Table 103 - Definition of TPML_ALG_PROPERTY Structure [OUT]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPML_ALG_PROPERTY_Unmarshal(
	_Out_	TPML_ALG_PROPERTY*		PpTarget,
	_Inout_	BYTE**					PprgbBuffer,
	_Inout_	INT32*					PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(TPML_ALG_PROPERTY));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = TSS_UINT32_Unmarshal((UINT32 *) & (PpTarget->count), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_TPMS_ALG_PROPERTY_Array_Unmarshal((TPMS_ALG_PROPERTY *) & (PpTarget->algProperties), PprgbBuffer, PpnSize, PpTarget->count);
		if (RC_SUCCESS != unReturnValue)
			break;
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a TPML_TAGGED_TPM_PROPERTY structure
 *	@details	Refer to: Table 104 - Definition of TPML_TAGGED_TPM_PROPERTY Structure [OUT]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPML_TAGGED_TPM_PROPERTY_Unmarshal(
	_Out_	TPML_TAGGED_TPM_PROPERTY*		PpTarget,
	_Inout_	BYTE**							PprgbBuffer,
	_Inout_	INT32*							PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(TPML_TAGGED_TPM_PROPERTY));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = TSS_UINT32_Unmarshal((UINT32 *) & (PpTarget->count), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_TPMS_TAGGED_PROPERTY_Array_Unmarshal((TPMS_TAGGED_PROPERTY *) & (PpTarget->tpmProperty), PprgbBuffer, PpnSize, PpTarget->count);
		if (RC_SUCCESS != unReturnValue)
			break;
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a TPML_TAGGED_PCR_PROPERTY structure
 *	@details	Refer to: Table 105 - Definition of TPML_TAGGED_PCR_PROPERTY Structure [OUT]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPML_TAGGED_PCR_PROPERTY_Unmarshal(
	_Out_	TPML_TAGGED_PCR_PROPERTY*		PpTarget,
	_Inout_	BYTE**							PprgbBuffer,
	_Inout_	INT32*							PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(TPML_TAGGED_PCR_PROPERTY));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = TSS_UINT32_Unmarshal((UINT32 *) & (PpTarget->count), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_TPMS_TAGGED_PCR_SELECT_Array_Unmarshal((TPMS_TAGGED_PCR_SELECT *) & (PpTarget->pcrProperty), PprgbBuffer, PpnSize, PpTarget->count);
		if (RC_SUCCESS != unReturnValue)
			break;
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a TPML_ECC_CURVE structure
 *	@details	Refer to: Table 106 - Definition of {ECC} TPML_ECC_CURVE Structure [OUT]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPML_ECC_CURVE_Unmarshal(
	_Out_	TPML_ECC_CURVE*		PpTarget,
	_Inout_	BYTE**				PprgbBuffer,
	_Inout_	INT32*				PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(TPML_ECC_CURVE));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = TSS_UINT32_Unmarshal((UINT32 *) & (PpTarget->count), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_TPM_ECC_CURVE_Array_Unmarshal((TPM_ECC_CURVE *) & (PpTarget->eccCurves), PprgbBuffer, PpnSize, PpTarget->count);
		if (RC_SUCCESS != unReturnValue)
			break;
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a TPMU_CAPABILITIES union
 *	@details	Refer to: Table 107 - Definition of TPMU_CAPABILITIES Union [OUT]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *	@param		PunSelector	Selector for the target
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMU_CAPABILITIES_Unmarshal(
	_Inout_	TPMU_CAPABILITIES*		PpTarget,
	_Inout_	BYTE**					PprgbBuffer,
	_Inout_	INT32*					PpnSize,
	_In_	UINT32					PunSelector)
{
	switch (PunSelector) {
		case TPM_CAP_ALGS:
			return TSS_TPML_ALG_PROPERTY_Unmarshal((TPML_ALG_PROPERTY *) & (PpTarget->algorithms), PprgbBuffer, PpnSize);
		case TPM_CAP_HANDLES:
			return TSS_TPML_HANDLE_Unmarshal((TPML_HANDLE *) & (PpTarget->handles), PprgbBuffer, PpnSize);
		case TPM_CAP_COMMANDS:
			return TSS_TPML_CCA_Unmarshal((TPML_CCA *) & (PpTarget->command), PprgbBuffer, PpnSize);
		case TPM_CAP_PP_COMMANDS:
			return TSS_TPML_CC_Unmarshal((TPML_CC *) & (PpTarget->ppCommands), PprgbBuffer, PpnSize);
		case TPM_CAP_AUDIT_COMMANDS:
			return TSS_TPML_CC_Unmarshal((TPML_CC *) & (PpTarget->auditCommands), PprgbBuffer, PpnSize);
		case TPM_CAP_PCRS:
			return TSS_TPML_PCR_SELECTION_Unmarshal((TPML_PCR_SELECTION *) & (PpTarget->assignedPCR), PprgbBuffer, PpnSize);
		case TPM_CAP_TPM_PROPERTIES:
			return TSS_TPML_TAGGED_TPM_PROPERTY_Unmarshal((TPML_TAGGED_TPM_PROPERTY *) & (PpTarget->tpmProperties), PprgbBuffer, PpnSize);
		case TPM_CAP_PCR_PROPERTIES:
			return TSS_TPML_TAGGED_PCR_PROPERTY_Unmarshal((TPML_TAGGED_PCR_PROPERTY *) & (PpTarget->pcrProperties), PprgbBuffer, PpnSize);
		case TPM_CAP_ECC_CURVES:
			return TSS_TPML_ECC_CURVE_Unmarshal((TPML_ECC_CURVE *) & (PpTarget->eccCurves), PprgbBuffer, PpnSize);
		// Vendor specific capability handling is done in a vendor specific implementation
		case TPM_CAP_VENDOR_PROPERTY:
			return TSS_TPMU_VENDOR_CAPABILITY_Unmarshal(PpTarget, PprgbBuffer, PpnSize);
		default:
			assert(FALSE);
			return RC_E_FAIL;
	}
}

/**
 *	@brief		Unmarshals a TPMS_CAPABILITY_DATA structure
 *	@details	Refer to: Table 108 - Definition of TPMS_CAPABILITY_DATA Structure [OUT]
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMS_CAPABILITY_DATA_Unmarshal(
	_Out_	TPMS_CAPABILITY_DATA*		PpTarget,
	_Inout_	BYTE**						PprgbBuffer,
	_Inout_	INT32*						PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(TPMS_CAPABILITY_DATA));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = TSS_TPM_CAP_Unmarshal((TPM_CAP *) & (PpTarget->capability), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_TPMU_CAPABILITIES_Unmarshal((TPMU_CAPABILITIES *) & (PpTarget->data), PprgbBuffer, PpnSize, PpTarget->capability);
		if (RC_SUCCESS != unReturnValue)
			break;
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Marshals a TPMU_SYM_KEY_BITS union
 *	@details	Refer to: Table 125 - Definition of TPMU_SYM_KEY_BITS Union
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *	@param		PunSelector	Selector for the source
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMU_SYM_KEY_BITS_Marshal(
	_In_	const TPMU_SYM_KEY_BITS*	PpSource,
	_Inout_	BYTE**						PprgbBuffer,
	_Inout_	INT32*						PpnSize,
	_In_	UINT32						PunSelector)
{
	switch (PunSelector) {
		case TPM_ALG_AES:
			return TSS_TPMI_AES_KEY_BITS_Marshal((TPMI_AES_KEY_BITS *) & (PpSource->aes), PprgbBuffer, PpnSize);
		case TPM_ALG_SM4:
			return TSS_TPMI_SM4_KEY_BITS_Marshal((TPMI_SM4_KEY_BITS *) & (PpSource->sm4), PprgbBuffer, PpnSize);
		case TPM_ALG_CAMELLIA:
			return TSS_TPMI_CAMELLIA_KEY_BITS_Marshal((TPMI_CAMELLIA_KEY_BITS *) & (PpSource->camellia), PprgbBuffer, PpnSize);
		case TPM_ALG_XOR:
			return TSS_TPMI_ALG_HASH_Marshal((TPMI_ALG_HASH *) & (PpSource->xor), PprgbBuffer, PpnSize);
		case TPM_ALG_NULL:
			return RC_SUCCESS;
		default:
			assert(FALSE);
			return RC_E_FAIL;
	}
}

/**
 *	@brief		Marshals a TPMU_SYM_MODE union
 *	@details	Refer to: Table 126 - Definition of TPMU_SYM_MODE Union
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *	@param		PunSelector	Selector for the source
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMU_SYM_MODE_Marshal(
	_In_	const TPMU_SYM_MODE*	PpSource,
	_Inout_	BYTE**					PprgbBuffer,
	_Inout_	INT32*					PpnSize,
	_In_	UINT32					PunSelector)
{
	switch (PunSelector) {
		case TPM_ALG_AES:
			return TSS_TPMI_ALG_SYM_MODE_Marshal((TPMI_ALG_SYM_MODE *) & (PpSource->aes), PprgbBuffer, PpnSize);
		case TPM_ALG_SM4:
			return TSS_TPMI_ALG_SYM_MODE_Marshal((TPMI_ALG_SYM_MODE *) & (PpSource->sm4), PprgbBuffer, PpnSize);
		case TPM_ALG_CAMELLIA:
			return TSS_TPMI_ALG_SYM_MODE_Marshal((TPMI_ALG_SYM_MODE *) & (PpSource->camellia), PprgbBuffer, PpnSize);
		case TPM_ALG_NULL:
			return RC_SUCCESS;
		default:
			assert(FALSE);
			return RC_E_FAIL;
	}
}

/**
 *	@brief		Marshals a TPMT_SYM_DEF structure
 *	@details	Refer to: Table 128 - Definition of TPMT_SYM_DEF Structure
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPMT_SYM_DEF_Marshal(
	_In_	const TPMT_SYM_DEF*		PpSource,
	_Inout_	BYTE**					PprgbBuffer,
	_Inout_	INT32*					PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check parameters
		if ((NULL == PpSource) || (NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		// Check size for PpnSize parameter
		if (*PpnSize < (INT32) sizeof(PpSource->algorithm))
		{
			unReturnValue = RC_E_BUFFER_TOO_SMALL;
			break;
		}
		// Marshal size
		unReturnValue = TSS_TPMI_ALG_SYM_Marshal((TPMI_ALG_SYM *) & (PpSource->algorithm), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check size for array
		if (*PpnSize < (INT32) PpSource->algorithm)
		{
			unReturnValue = RC_E_BUFFER_TOO_SMALL;
			break;
		}
		// Marshal array
		unReturnValue = TSS_TPMU_SYM_KEY_BITS_Marshal((TPMU_SYM_KEY_BITS *) & (PpSource->keyBits), PprgbBuffer, PpnSize, PpSource->algorithm);
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check size for array
		if (*PpnSize < (INT32) PpSource->algorithm)
		{
			unReturnValue = RC_E_BUFFER_TOO_SMALL;
			break;
		}
		// Marshal array
		unReturnValue = TSS_TPMU_SYM_MODE_Marshal((TPMU_SYM_MODE *) & (PpSource->mode), PprgbBuffer, PpnSize, PpSource->algorithm);
		if (RC_SUCCESS != unReturnValue)
			break;
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Marshals a TPM2B_ENCRYPTED_SECRET structure
 *	@details	Refer to: Table 175 - Definition of TPM2B_ENCRYPTED_SECRET Structure
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM2B_ENCRYPTED_SECRET_Marshal(
	_In_	const TPM2B_ENCRYPTED_SECRET*		PpSource,
	_Inout_	BYTE**								PprgbBuffer,
	_Inout_	INT32*								PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check parameters
		if ((NULL == PpSource) || (NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		// Check size for PpnSize parameter
		if (*PpnSize < (INT32) sizeof(PpSource->size))
		{
			unReturnValue = RC_E_BUFFER_TOO_SMALL;
			break;
		}
		// Marshal size
		unReturnValue = TSS_UINT16_Marshal((UINT16 *) & (PpSource->size), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check size for array
		if (*PpnSize < (INT32) PpSource->size)
		{
			unReturnValue = RC_E_BUFFER_TOO_SMALL;
			break;
		}
		// Marshal array
		unReturnValue = TSS_BYTE_Array_Marshal((BYTE *) & (PpSource->secret), PprgbBuffer, PpnSize, PpSource->size);
		if (RC_SUCCESS != unReturnValue)
			break;
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Marshals a AuthorizationCommandData structure
 *	@details	Refer to: Table 14 - Session-Based Authorization of Command
 *
 *	@param		PpSource	Location containing the value that is to be marshaled in to the designated buffer
 *	@param		PprgbBuffer	Location in the output buffer where the first octet of the TYPE is to be placed
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_AuthorizationCommandData_Marshal(
	_In_	const AuthorizationCommandData*		PpSource,
	_Inout_	BYTE**								PprgbBuffer,
	_Inout_	INT32*								PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check parameters
		if ((NULL == PpSource) || (NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		// Check size for PpnSize parameter
		if (*PpnSize < (INT32) sizeof(PpSource->authHandle))
		{
			unReturnValue = RC_E_BUFFER_TOO_SMALL;
			break;
		}
		// Marshal size
		unReturnValue = TSS_TPMI_SH_AUTH_SESSION_Marshal((TPMI_SH_AUTH_SESSION *) & (PpSource->authHandle), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check size for PpnSize parameter
		if (*PpnSize < (INT32) sizeof(PpSource->nonceCaller))
		{
			unReturnValue = RC_E_BUFFER_TOO_SMALL;
			break;
		}
		// Marshal size
		unReturnValue = TSS_TPM2B_NONCE_Marshal((TPM2B_NONCE *) & (PpSource->nonceCaller), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check size for PpnSize parameter
		if (*PpnSize < (INT32) sizeof(PpSource->sessionAttributes))
		{
			unReturnValue = RC_E_BUFFER_TOO_SMALL;
			break;
		}
		// Marshal size
		unReturnValue = TSS_TPMA_SESSION_Marshal((TPMA_SESSION *) & (PpSource->sessionAttributes), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check size for PpnSize parameter
		if (*PpnSize < (INT32) sizeof(PpSource->hmac))
		{
			unReturnValue = RC_E_BUFFER_TOO_SMALL;
			break;
		}
		// Marshal size
		unReturnValue = TSS_TPM2B_AUTH_Marshal((TPM2B_AUTH *) & (PpSource->hmac), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
	}
	WHILE_FALSE_END;
	return unReturnValue;
}

/**
 *	@brief		Unmarshals a AcknowledgmentResponseData structure
 *	@details	Refer to: Table 15 - Session-Based Acknowledgment in Response
 *
 *	@param		PpTarget	Location into which the data from **PprgbBuffer is placed
 *	@param		PprgbBuffer	Location in the output buffer containing the most significant octet (MSO) of *PpTarget
 *	@param		PpnSize		Number of octets remaining in **PprgbBuffer
 *
 *	@retval		RC_SUCCESS	The operation completed successfully.
 *	@retval		...			Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_AcknowledgmentResponseData_Unmarshal(
	_Out_	AcknowledgmentResponseData*		PpTarget,
	_Inout_	BYTE**							PprgbBuffer,
	_Inout_	INT32*							PpnSize)
{
	unsigned int unReturnValue = RC_E_FAIL;
	do
	{
		// Check and initialize _Out_ parameters
		if (NULL == PpTarget)
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = Platform_MemorySet(PpTarget, 0x00, sizeof(AcknowledgmentResponseData));
		if (RC_SUCCESS != unReturnValue)
			break;
		// Check _Inout_ parameters
		if ((NULL == PprgbBuffer) || (NULL == *PprgbBuffer) || (NULL == PpnSize))
		{
			unReturnValue = RC_E_BAD_PARAMETER;
			break;
		}
		unReturnValue = TSS_TPM2B_NONCE_Unmarshal((TPM2B_NONCE *) & (PpTarget->nonceTPM), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_TPMA_SESSION_Unmarshal((TPMA_SESSION *) & (PpTarget->sessionAttributes), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
		unReturnValue = TSS_TPM2B_AUTH_Unmarshal((TPM2B_AUTH *) & (PpTarget->hmac), PprgbBuffer, PpnSize);
		if (RC_SUCCESS != unReturnValue)
			break;
	}
	WHILE_FALSE_END;
	return unReturnValue;
}