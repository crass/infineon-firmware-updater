﻿/**
 *	@brief		Declares standard includes for project Platform
 *	@details
 *	@file		Common/Platform/StdInclude.h
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

// UEFI
#ifdef UEFI

#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/PrintLib.h>						// .. UnicodeVSPrint
#include <Library/UefiRuntimeServicesTableLib.h>	// .. GetTime
#include <Library/MemoryAllocationLib.h>			// .. AllocateZeroPool, FreePool
#include <Library/BaseMemoryLib.h>					// .. CopyMem
#include <Library/UefiBootServicesTableLib.h>

#include "Globals_UEFI.h"

#endif // UEFI

// Linux
#ifdef LINUX

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include <wchar.h>
#include <time.h>
#include <sys/types.h>
#include <sys/timeb.h>

#include "Globals_Linux.h"
#endif // LINUX

// Windows
#ifdef WINDOWS

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <sys/types.h>
#include <sys/timeb.h>

#include "Globals.h"

#endif // WINDOWS

#include "ErrorCodes.h"
