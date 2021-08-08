﻿/**
 *	@file		swap.h
 *	@brief		Declares byte array swap methods..
 *	@details	This file was auto-generated based on TPM2.0 specification revision 116.
 */
#pragma once

#define BYTE_ARRAY_TO_UINT8(b)	(UINT8)((b)[0])

#define BYTE_ARRAY_TO_UINT16(b)	(UINT16)(((b)[0] << 8) + (b)[1])

#define BYTE_ARRAY_TO_UINT32(b)	(UINT32)(((b)[0] << 24) \
										+ ((b)[1] << 16) \
										+ ((b)[2] << 8) \
										+ (b)[3])

#define BYTE_ARRAY_TO_UINT64(b)	(UINT64)(((UINT64)(b)[0] << 56) \
										+ ((UINT64)(b)[1] << 48) \
										+ ((UINT64)(b)[2] << 40) \
										+ ((UINT64)(b)[3] << 32) \
										+ ((UINT64)(b)[4] << 24) \
										+ ((UINT64)(b)[5] << 16) \
										+ ((UINT64)(b)[6] << 8) \
										+ (UINT64)(b)[7])

#define UINT8_TO_BYTE_ARRAY(i, b)		((b)[0] = (BYTE)(i))

#define UINT16_TO_BYTE_ARRAY(i, b)		((b)[0] = (BYTE)((i) >> 8), \
										(b)[1] = (BYTE) (i))

#define UINT32_TO_BYTE_ARRAY(i, b)		((b)[0] = (BYTE)((i) >> 24), \
										(b)[1] = (BYTE)((i) >> 16), \
										(b)[2] = (BYTE)((i) >> 8), \
										(b)[3] = (BYTE) (i))

#define UINT64_TO_BYTE_ARRAY(i, b)		((b)[0] = (BYTE)((i) >> 56), \
										(b)[1] = (BYTE)((i) >> 48), \
										(b)[2] = (BYTE)((i) >> 40), \
										(b)[3] = (BYTE)((i) >> 32), \
										(b)[4] = (BYTE)((i) >> 24), \
										(b)[5] = (BYTE)((i) >> 16), \
										(b)[6] = (BYTE)((i) >> 8), \
										(b)[7] = (BYTE) (i))
