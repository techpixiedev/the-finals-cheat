/*
 *  MinHook - The Minimalistic API Hooking Library for x64/x86
 *  Copyright (C) 2009-2017 Tsuda Kageyu.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   1. Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 *  TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 *  PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER
 *  OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 *  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 *  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 *  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdint.h>

// Structs for writing x86/x64 instructions.
typedef struct _JMP_REL_SHORT
{
    uint8_t opcode;
    uint8_t operand;
} JMP_REL_SHORT, *PJMP_REL_SHORT;

typedef struct _JMP_REL
{
    uint8_t opcode;
    uint32_t operand;
} JMP_REL, *PJMP_REL, CALL_REL;

typedef struct _JMP_ABS
{
    uint8_t opcode0;
    uint8_t opcode1;
    uint32_t dummy;
    uint64_t address;
} JMP_ABS, *PJMP_ABS;

typedef struct _CALL_ABS
{
    uint8_t opcode0;
    uint8_t opcode1;
    uint32_t dummy0;
    uint8_t dummy1;
    uint8_t dummy2;
    uint64_t address;
} CALL_ABS;

typedef struct _JCC_REL
{
    uint8_t opcode0;
    uint8_t opcode1;
    uint32_t operand;
} JCC_REL;

typedef struct _JCC_ABS
{
    uint8_t opcode;
    uint8_t dummy0;
    uint8_t dummy1;
    uint8_t dummy2;
    uint32_t dummy3;
    uint64_t address;
} JCC_ABS;

#pragma pack(push, 1)
typedef struct _TRAMPOLINE
{
    void* pTarget;
    void* pDetour;
    void* pTrampoline;

#if defined(_M_X64) || defined(__x86_64__)
    void* pRelay;
#endif
    int patchAbove;
    unsigned int nIP;
    uint8_t oldIPs[8];
    uint8_t newIPs[8];
} TRAMPOLINE, *PTRAMPOLINE;
#pragma pack(pop)

int CreateTrampolineFunction(PTRAMPOLINE ct);