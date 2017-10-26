﻿/**
 *	@brief		Declares the TPM_OSAP command.
 *	@details	The module receives the input parameters, marshals these parameters
 *				to a byte array, sends the command to the TPM and unmarshals the response
 *				back to the out parameters.
 *	@file		TPM_OSAP.h
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

#include "TPM_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *	@brief		This function handles the TPM_OSAP command.
 *	@details	The function receives the input parameters, marshals these parameters
 *				to a byte array, sends the command to the TPM and unmarshals the response
 *				back to the out parameters.
 *
 *	@param		PentityType			The type of entity in use
 *	@param		PunEntityValue		The selection value based on entityType, e.g. a keyHandle #
 *	@param		PsNonceOddOSAP		The nonce generated by the caller associated with the shared secret.
 *	@param		PpunAuthHandle		Handle that TPM creates that points to the authorization state.
 *	@param		PpsNonceEven		Nonce generated by TPM and associated with session.
 *	@param		PpsNonceEvenOSAP	Nonce generated by TPM and associated with shared secret.
 *
 *	@retval		RC_SUCCESS			The operation completed successfully.
 *	@retval		RC_E_BAD_PARAMETER	An invalid parameter was passed to the function. E.g. NULL pointer
 *	@retval		...					Error codes from called functions.
 */
_Check_return_
unsigned int
TSS_TPM_OSAP(
	_In_ TPM_ENTITY_TYPE	PentityType,
	_In_ UINT32				PunEntityValue,
	_In_ TPM_NONCE			PsNonceOddOSAP,
	_Out_ TPM_AUTHHANDLE*	PpunAuthHandle,
	_Out_ TPM_NONCE*		PpsNonceEven,
	_Out_ TPM_NONCE*		PpsNonceEvenOSAP);

#ifdef __cplusplus
}
#endif
