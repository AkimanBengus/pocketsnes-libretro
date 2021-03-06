/*
 * Snes9x - Portable Super Nintendo Entertainment System (TM) emulator.
 *
 * (c) Copyright 1996 - 2001 Gary Henderson (gary.henderson@ntlworld.com) and
 *                           Jerremy Koot (jkoot@snes9x.com)
 *
 * Super FX C emulator code 
 * (c) Copyright 1997 - 1999 Ivar (ivar@snes9x.com) and
 *                           Gary Henderson.
 * Super FX assembler emulator code (c) Copyright 1998 zsKnight and _Demo_.
 *
 * DSP1 emulator code (c) Copyright 1998 Ivar, _Demo_ and Gary Henderson.
 * C4 asm and some C emulation code (c) Copyright 2000 zsKnight and _Demo_.
 * C4 C code (c) Copyright 2001 Gary Henderson (gary.henderson@ntlworld.com).
 *
 * DOS port code contains the works of other authors. See headers in
 * individual files.
 *
 * Snes9x homepage: http://www.snes9x.com
 *
 * Permission to use, copy, modify and distribute Snes9x in both binary and
 * source form, for non-commercial purposes, is hereby granted without fee,
 * providing that this license information and copyright notice appear with
 * all copies and any derived work.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event shall the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Snes9x is freeware for PERSONAL USE only. Commercial users should
 * seek permission of the copyright holders first. Commercial use includes
 * charging money for Snes9x or software derived from Snes9x.
 *
 * The copyright holders request that bug fixes and improvements to the code
 * should be forwarded to them so everyone can benefit from the modifications
 * in future versions.
 *
 * Super NES and Super Nintendo Entertainment System are trademarks of
 * Nintendo Co., Limited and its subsidiary companies.
 */

// ARM V5 Assembly by bitrider

#define FIXEDCOLOUR	(GFX.FixedColour & (~0x01860))

#define ROPNAME	FixedAdd1_2

#define ROP \
			"	bic	r9, r9, #0b00000100000100000	\n"\
			"	bic	r9, r9, #0b00001000001000000	\n"\
			"	add	r9, r9, %[fixedcolour]		\n"\
			"	mov	r9, r9, lsr #1			\n"\
			"	tst	r9, #0b00000000000100000	\n"\
			"	orrne	r9, r9, #0b00000000000011111	\n"\
			"	tst	r9, #0b00000100000000000	\n"\
			"	orrne	r9, r9, #0b00000011111100000	\n"\
			"	tst	r9, #0b10000000000000000	\n"\
			"	orrne	r9, r9, #0b01111100000000000	\n"


#include "tile16f_t.h"
