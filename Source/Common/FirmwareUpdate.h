﻿/**
 *	@brief		Declares common firmware update functionality used by different tools
 *	@details	Declares the internal firmware update interface used by IFXTPMUpdate and TPMFactoryUpd.
 *	@file		FirmwareUpdate.h
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
#pragma once

#include "StdInclude.h"
#include "TPM2_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// This value is the policy for TPM20 firmware update
static const BYTE rgbTpm20FirmwareUpdatePolicyDigest[] = {0x6D, 0x9B, 0x4B, 0x75, 0x61, 0xCA, 0xC7, 0x7B,
															0x26, 0x1B, 0x31, 0xE2, 0x42, 0x31, 0xBD, 0x87,
															0x09, 0x7B, 0x47, 0x2E, 0x45, 0xF0, 0x7D, 0x4D,
															0x8F, 0xED, 0xDD, 0xB0, 0x4B, 0x91, 0x89, 0xF4};

/**
 *	@brief		TPM state attributes used in FirmwareUpdate interface methods.
 *	@details	TPM state attributes used in FirmwareUpdate interface methods (Bits tpm12, tpm20, and bootLoader are mutually exclusive).
 */
typedef struct tdBITFIELD_TPM_ATTRIBUTES
{
	/// The TPM is a TPM1.2.
	unsigned int tpm12 : 1;
	/// The TPM is a TPM2.0.
	unsigned int tpm20 : 1;
	/// The TPM is in invalid firmware mode because a previous update was interrupted. Firmware update must be retried
	/// with the same firmware image.
	unsigned int bootLoader : 1;
	/// The TPM is manufactured by Infineon.
	unsigned int infineon : 1;
	/// The TPM1.2 has an owner.
	unsigned int tpm12owner : 1;
	/// The TPM1.2 is enabled.
	unsigned int tpm12enabled : 1;
	/// The TPM1.2 is activated.
	unsigned int tpm12activated : 1;
	/// A reboot is required so that the TPM reaches functional state (usually after update to TPM2.0).
	unsigned int tpm20restartRequired : 1;
	/// The platform hierarchy is disabled for the TPM2.0.
	unsigned int tpm20phDisabled : 1;
	/// The platformAuth is the empty buffer for TPM2.0 (field is applicable only if tpm20phDisabled = 0)
	unsigned int tpm20emptyPlatformAuth : 1;
	/// The TPM is manufactured by Infineon but not supported by Firmware Update Tools.
	unsigned int unsupportedChip : 1;
	/// Physical Presence is set for TPM1.2.
	unsigned int tpm12PhysicalPresence : 1;
	/// Physical Presence is locked for the boot cycle for TPM1.2.
	unsigned int tpm12PhysicalPresenceLock : 1;
	/// Deferred Physical Presence is set for TPM1.2.
	unsigned int tpm12DeferredPhysicalPresence : 1;
	/// HW enable for Physical Presence command for TPM1.2.
	unsigned int tpm12PhysicalPresenceHWEnable : 1;
	/// CMD enable for Physical Presence command for TPM1.2.
	unsigned int tpm12PhysicalPresenceCMDEnable : 1;
	/// Physical Presence lifetime lock for TPM1.2.
	unsigned int tpm12PhysicalPresenceLifetimeLock : 1;
	/// TPM2.0 in failure mode
	unsigned int tpm20InFailureMode : 1;
	/// TPM1.2 in self-test failed mode
	unsigned int tpm12FailedSelfTest : 1;
	/// TPM1.2 could not read TPM_FieldUpgradeInfo2() command
	unsigned int tpm12FieldUpgradeInfo2Failed : 1;
} BITFIELD_TPM_ATTRIBUTES;

/**
 *	@brief		TPM state
 *	@details	TPM state
 */
typedef struct tdTPM_STATE
{
	/// Buffer to hold TPM test result for either TPM1.2 or TPM2.0
	BYTE testResult[64];
	/// Size of the test result
	unsigned int unTestResultLen;
	/// TPM attributes
	BITFIELD_TPM_ATTRIBUTES attribs;
} TPM_STATE;

/**
 *	@brief		TPM state after firmware update used in FirmwareUpdate interface methods.
 *	@details	TPM state after firmware update used in FirmwareUpdate interface methods.
 */
typedef struct tdBITFIELD_NEW_TPM_FIRMWARE_INFO
{
	/// Firmware update will change the TPM device type. For example:\n
	/// - Firmware update will update a TPM1.2 to a TPM2.0.
	/// - Firmware update will update a TPM2.0 to a TPM1.2.
	unsigned int deviceTypeChange : 1;
	/// Firmware update will update the TPM and reset the TPM to factory defaults. All data and state from the
	/// old TPM firmware will be lost. The appearance of this depends on the actual source and target
	/// firmware of the firmware update and can occur in both, cross version and normal update paths.
	unsigned int factoryDefaults : 1;
} BITFIELD_NEW_TPM_FIRMWARE_INFO;

/// Function pointer type definition for Response_ProgressCallback
typedef unsigned long long (*PFN_FIRMWAREUPDATE_PROGRESSCALLBACK)(
	unsigned long long PullCompletion);

/// Function pointer type definition for UpdateStarted_Callback
typedef void (*PFN_FIRMWAREUPDATE_UPDATESTARTEDCALLBACK)(
	);

/// This value indicates that the number of remaining firmware updates is unknown
#define REMAINING_UPDATES_UNAVAILABLE (unsigned int)(-1)

/**
 *	@brief		Returns the TPM state attributes
 *	@details
 *
 *	@param		PpsTpmState					Pointer to a variable representing the TPM state
 *
 *	@retval		RC_SUCCESS					The operation completed successfully.
 *	@retval		RC_E_BAD_PARAMETER			An invalid parameter was passed to the function. PpsTpmState is NULL.
 *	@retval		RC_E_FAIL					An unexpected error occurred. E.g. more than one property returned from TPM2_GetCapability call
 *	@retval		...							Error codes from called functions.
 */
_Check_return_
unsigned int
FirmwareUpdate_CalculateState(
	_Out_ TPM_STATE* PpsTpmState);

/**
 *	@brief		Returns information about the current state of TPM
 *	@details
 *
 *	@param		PwszVersionName				A pointer to a null-terminated string representing the firmware image version name.
 *	@param		PpunVersionNameSize			IN: Capacity of the PwszVersionName parameter in wide characters including zero termination
 *											OUT: Length of written wide character string (excluding zero termination)
 *	@param		PpsTpmState					Receives TPM state.
 *	@param		PpunRemainingUpdates		Receives the number of remaining updates or -1 in case the value could not be detected.
 *
 *	@retval		RC_SUCCESS					The operation completed successfully.
 *	@retval		RC_E_FAIL					An unexpected error occurred.
 *	@retval		RC_E_BAD_PARAMETER			An invalid parameter was passed to the function.
 *	@retval		RC_E_NO_IFX_TPM				The TPM is not manufactured by Infineon.
 *	@retval		...							Error codes from called functions.
 */
_Check_return_
unsigned int
FirmwareUpdate_GetImageInfo(
	_Inout_bytecap_(*PpunVersionNameSize)	wchar_t*					PwszVersionName,
	_Inout_									unsigned int*				PpunVersionNameSize,
	_Inout_									TPM_STATE*					PpsTpmState,
	_Inout_									unsigned int*				PpunRemainingUpdates);

/**
 *	@brief		Checks if the firmware image is valid for the TPM
 *	@details	Performs integrity, consistency and content checks to determine if the given firmware image can be applied to the installed TPM.
 *
 *	@param		PrgbImage					Firmware image byte stream
 *	@param		PullImageSize				Size of firmware image byte stream
 *	@param		PpfValid					TRUE in case the image is valid, FALSE otherwise.
 *	@param		PpbfNewTpmFirmwareInfo		Pointer to a bit field to return info data for the new firmware image.
 *	@param		PpunErrorDetails			Pointer to an unsigned int to return error details. Possible values are:\n
 *												RC_E_FW_UPDATE_BLOCKED in case the field upgrade counter value has been exceeded.\n
 *												RC_E_WRONG_FW_IMAGE in case the TPM is not updatable with the given image.\n
 *												RC_E_CORRUPT_FW_IMAGE in case the firmware image is corrupt.\n
 *												RC_E_NEWER_TOOL_REQUIRED in case a newer version of the tool is required to parse the firmware image.\n
 *												RC_E_WRONG_DECRYPT_KEYS in case the TPM2.0 does not have decrypt keys matching to the firmware image.
 *
 *	@retval		RC_SUCCESS					The operation completed successfully
 *	@retval		RC_E_BAD_PARAMETER			An invalid parameter was passed to the function.
 *	@retval		RC_E_TPM20_FAILURE_MODE		The TPM2.0 is in failure mode.
 *	@retval		RC_E_RESTART_REQUIRED		In case a restart is required to get back to a functional TPM
 *	@retval		RC_E_NO_IFX_TPM				In case TPM vendor is not IFX
 *	@retval		RC_E_FAIL					An unexpected error occurred.
 *	@retval		...							Error codes from called functions.
 */
_Check_return_
unsigned int
FirmwareUpdate_CheckImage(
	_In_bytecount_(PullImageSize)	BYTE*							PrgbImage,
	_In_							UINT64							PullImageSize,
	_Out_							BOOL*							PpfValid,
	_Out_							BITFIELD_NEW_TPM_FIRMWARE_INFO*	PpbfNewTpmFirmwareInfo,
	_Out_							UINT32*							PpunErrorDetails);

/**
 *	@brief		Firmware Update Data structure
 *	@details	This structure is used to hand over the firmware update related data.
 */
typedef struct tdIfxFirmwareUpdateData
{
	/// Firmware image size
	UINT32 unFirmwareImageSize;
	/// Pointer to a Firmware image
	BYTE* rgbFirmwareImage;
	/// Progress call back function pointer
	PFN_FIRMWAREUPDATE_PROGRESSCALLBACK fnProgressCallback;
	/// Update started call back function pointer
	PFN_FIRMWAREUPDATE_UPDATESTARTEDCALLBACK fnUpdateStartedCallback;
	/// Session handle used for updating a TPM2.0
	unsigned int unSessionHandle;
	/// TPM Owner authentication hash value used for updating a TPM1.2 with TPM Owner authorization
	BYTE rgbOwnerAuthHash[SHA1_DIGEST_SIZE];
} IfxFirmwareUpdateData;

/**
 *	@brief		Function to update the firmware with the given firmware image
 *	@details	This function updates the TPM firmware with the image given in the parameters.
 *				A check if the firmware can be updated with the image is done before.
 *
 *	@param		PpsFirmwareUpdateData	Pointer to structure containing all relevant data for a firmware update
 *
 *	@retval		RC_SUCCESS						The operation completed successfully.
 *	@retval		RC_E_CORRUPT_FW_IMAGE			Policy parameter block is corrupt and/or cannot be unmarshalled.
 *	@retval		RC_E_NO_IFX_TPM					The TPM is not manufactured by Infineon.
 *	@retval		RC_E_TPM12_MISSING_OWNERAUTH	The TPM has an owner but TPM Owner authorization was not provided (TPM1.2 only).
 *	@retval		RC_E_TPM12_NO_OWNER				The TPM does not have an owner but TPM Owner authorization was provided (TPM1.2 only).
 *	@retval		RC_E_FAIL						TPM connection or command error.
 *	@retval		...								Error codes from called functions.
 *	@retval		RC_E_FIRMWARE_UPDATE_FAILED		The update operation was started but failed.
 */
_Check_return_
unsigned int
FirmwareUpdate_UpdateImage(
	_In_	const IfxFirmwareUpdateData* const	PpsFirmwareUpdateData);

/**
 *	@brief		Checks TPM Owner authorization on TPM1.2.
 *	@details	The function checks TPM Owner authorization on TPM1.2 by calling TPM_ChangeAuthOwner with old and new TPM Owner authorization value set to the same value.
 *
 *	@param		PrgbOwnerAuthHash				TPM Owner Authentication hash (sha1)
 *
 *	@retval		RC_SUCCESS						The operation completed successfully.
 *	@retval		RC_E_FAIL						An internal error occurred.
 *	@retval		...								Error codes from called functions.
 */
_Check_return_
unsigned int
FirmwareUpdate_CheckOwnerAuthorization(
	_In_bytecount_(SHA1_DIGEST_SIZE)	const BYTE	PrgbOwnerAuthHash[SHA1_DIGEST_SIZE]);

/**
 *	@brief		Prepares a policy session for TPM firmware.
 *	@details	The function prepares a policy session for TPM Firmware Update.
 *
 *	@param		PphPolicySession					Pointer to session handle that will be filled in by this method.
 *
 *	@retval		RC_SUCCESS							The operation completed successfully.
 *	@retval		RC_E_BAD_PARAMETER					An invalid parameter was passed to the function. It is invalid or NULL.
 *	@retval		RC_E_FAIL							An unexpected error occurred.
 *	@retval		RC_E_PLATFORM_AUTH_NOT_EMPTY		In case PlatformAuth is not the Empty Buffer.
 *	@retval		RC_E_PLATFORM_HIERARCHY_DISABLED	In case platform hierarchy has been disabled.
 *	@retval		...									Error codes from called functions. like TPM error codes
 */
_Check_return_
unsigned int
FirmwareUpdate_PrepareTPM20Policy(
	_Out_ TPMI_SH_AUTH_SESSION* PphPolicySession);

#ifdef __cplusplus
}
#endif
