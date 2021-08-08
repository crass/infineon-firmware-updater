﻿/**
 *	@brief		Implements methods to initialize the business logic of TPMFactoryUpd.
 *	@details	This module performs all application-specific preparation steps required to get the business logic of TPMFactoryUpd working.
 *	@file		CommandFlow_Init.c
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

#include "CommandFlow_Init.h"
#include "Crypt.h"

/**
 *	@brief		Initializes the business logic of TPMFactoryUpd.
 *	@details	This method seeds the random number generator.
 *
 *	@retval		RC_SUCCESS					The operation completed successfully.
 *	@retval		RC_E_FAIL					An unexpected error occurred.
 *	@retval		...							Error codes from Crypt_SeedRandom().
 */
_Check_return_
unsigned int
CommandFlow_Init_Execute()
{
	unsigned int unReturnValue = RC_E_FAIL;

	LOGGING_WRITE_LEVEL4(LOGGING_METHOD_ENTRY_STRING);

	do
	{
		// Seed the random number generator
		unReturnValue = Crypt_SeedRandom(NULL, 0);
		if (RC_SUCCESS != unReturnValue)
			break;
	}
	WHILE_FALSE_END;

	LOGGING_WRITE_LEVEL4_FMT(LOGGING_METHOD_EXIT_STRING_RET_VAL, unReturnValue);

	return unReturnValue;
}
