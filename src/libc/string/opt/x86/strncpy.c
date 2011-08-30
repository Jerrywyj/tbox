/*!The Tiny Box Library
 * 
 * TBox is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 * 
 * TBox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with TBox; 
 * If not, see <a href="http://www.gnu.org/licenses/"> http://www.gnu.org/licenses/</a>
 * 
 * Copyright (C) 2009 - 2011, ruki All rights reserved.
 *
 * \author		ruki
 * \file		strncpy.c
 *
 */

/* /////////////////////////////////////////////////////////
 * includes
 */
#include "prefix.h"

/* /////////////////////////////////////////////////////////
 * macros
 */
#ifdef TB_CONFIG_ASSEMBLER_GAS
//# 	define TB_LIBC_STRING_OPT_STRNCPY
#endif

/* /////////////////////////////////////////////////////////
 * implemention
 */
#if 0//def TB_CONFIG_ASSEMBLER_GAS
tb_char_t* tb_strncpy(tb_char_t* s1, tb_char_t const* s2, tb_size_t n)
{
	TB_ASSERT_RETURN_VAL(s1 && s2, TB_NULL);

	tb_size_t d0, d1, d2, d3;
	__tb_asm__ __tb_volatile__
	(
		"1:\n"
		" 	decl %2\n"
		" 	js 2f\n"
		" 	lodsb\n"
		" 	stosb\n"
		" 	testb %%al, %%al\n"
		" 	jne 1b\n"
		" 	rep\n"
		" 	stosb\n"
		"2:"

		: "=&S" (d0), "=&D" (d1), "=&c" (d2), "=&a" (d3)
		: "0" (s2), "1" (s1), "2" (n) 
		: "memory"
	);
	return s1;
}
#endif
