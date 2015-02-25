#pragma once

#include "concat.h"
#include "if.h"

//REPEAT supports two dimensions. This is harder because macros are not recursive.
//Using REPEAT with a macro that expands to a call to REPEAT will not expand REPEAT again.
//Instead of expanding REPEAT(...), we'll instead expand REPEAT_1(...) or REPEAT_2(...).
//By default, we want REPEAT_1. If we're inside a macro called from REPEAT_1, we want REPEAT_2.
//NEXT_AVAILABLE_DIMENSION expands to 1 or 2 based on these conditions.

//Calls the given macro the given number of times.
//The first argument to the macro is the index, 0..count-1.
//The second argument to the macro is the given data.
#define UW_REPEAT \
	UW_CONCAT(IMPL_UW_REPEAT_, IMPL_UW_NEXT_AVAILABLE_DIMENSION)

//NEXT_AVAILABLE_DIMENSION expands to 1 or 2 based on the conditions listed for REPEAT.
//We will test whether dimension 1 is in use via IS_DIMENSION_IN_USE.
//It will expand to 1 if it is, or 0 if it isn't.
//If dimension 1 is in use, this will expand to 2. Otherwise, it will expand to 1.
#define IMPL_UW_NEXT_AVAILABLE_DIMENSION \
	UW_IF(IMPL_UW_IS_DIMENSION_1_IN_USE, 2, 1)

//We will use the very same constraint that forces us into this situation to escape.
//Macros cannot be expanded recursively.
//This means that if REPEAT_1 is currently expanding, trying to expand it again will not work.
//Thus, we will literally end up with REPEAT_1(...).
//We will use two helper macros, similar to IF.

//If the dimension is in use, IMPL_UW_REPEAT_1(1, NO UW_DISCARD2, data) will remain the same.
//Thus, we end up with IMPL_UW_IS_DIMENSION_1_IN_USE_REPEAT_1(1, NO UW_DISCARD2, data).
//This is one of the helper macros. It expands to 1 because REPEAT_1 not expanding means dimension 1 is in use.

//If the dimension is not in use, IMPL_UW_REPEAT_1(1, NO UW_DISCARD2, data) will expand to IMPL_UW_REPEAT_1_1(NO UW_DISCARD2, data).
//This will expand to NO UW_DISCARD2(0, data).
//UW_DISCARD2(0, data) will expand to nothing.
//Thus, IMPL_UW_REPEAT_1(1, NO UW_DISCARD2, data) will expand to NO.
//Thus, we end up with IMPL_UW_IS_DIMENSION_1_IN_USE_NO.
//This is the other helper macro. It expands to 0 because dimension 1 is not in use.
#define IMPL_UW_IS_DIMENSION_1_IN_USE \
	UW_CONCAT(IMPL_UW_IS_DIMENSION_1_IN_USE_, IMPL_UW_REPEAT_1(1, NO UW_DISCARD2, data))

#define IMPL_UW_IS_DIMENSION_1_IN_USE_IMPL_UW_REPEAT_1(arg1, arg2, arg3) 1
#define IMPL_UW_IS_DIMENSION_1_IN_USE_NO 0

//REPEAT_1 is used when the first dimension is available. It selects a helper macro based on the value of count.
//The helper macro then calls one level below it until 1 or 0 is reached. On each level, the macro is called with the proper index.
#define IMPL_UW_REPEAT_1(count, macro, data) \
	UW_CONCAT(IMPL_UW_REPEAT_1_, count)(macro, data)

#define IMPL_UW_REPEAT_1_0(macro, data)
#define IMPL_UW_REPEAT_1_1(macro, data) macro(0, data)
#define IMPL_UW_REPEAT_1_2(macro, data) IMPL_UW_REPEAT_1_1(macro, data) macro(1, data)
#define IMPL_UW_REPEAT_1_3(macro, data) IMPL_UW_REPEAT_1_2(macro, data) macro(2, data)
#define IMPL_UW_REPEAT_1_4(macro, data) IMPL_UW_REPEAT_1_3(macro, data) macro(3, data)
#define IMPL_UW_REPEAT_1_5(macro, data) IMPL_UW_REPEAT_1_4(macro, data) macro(4, data)
#define IMPL_UW_REPEAT_1_6(macro, data) IMPL_UW_REPEAT_1_5(macro, data) macro(5, data)
#define IMPL_UW_REPEAT_1_7(macro, data) IMPL_UW_REPEAT_1_6(macro, data) macro(6, data)
#define IMPL_UW_REPEAT_1_8(macro, data) IMPL_UW_REPEAT_1_7(macro, data) macro(7, data)
#define IMPL_UW_REPEAT_1_9(macro, data) IMPL_UW_REPEAT_1_8(macro, data) macro(8, data)
#define IMPL_UW_REPEAT_1_10(macro, data) IMPL_UW_REPEAT_1_9(macro, data) macro(9, data)
#define IMPL_UW_REPEAT_1_11(macro, data) IMPL_UW_REPEAT_1_10(macro, data) macro(10, data)
#define IMPL_UW_REPEAT_1_12(macro, data) IMPL_UW_REPEAT_1_11(macro, data) macro(11, data)
#define IMPL_UW_REPEAT_1_13(macro, data) IMPL_UW_REPEAT_1_12(macro, data) macro(12, data)
#define IMPL_UW_REPEAT_1_14(macro, data) IMPL_UW_REPEAT_1_13(macro, data) macro(13, data)
#define IMPL_UW_REPEAT_1_15(macro, data) IMPL_UW_REPEAT_1_14(macro, data) macro(14, data)
#define IMPL_UW_REPEAT_1_16(macro, data) IMPL_UW_REPEAT_1_15(macro, data) macro(15, data)

//REPEAT_2 is used when the second dimension is available. It works just like REPEAT_1.
#define IMPL_UW_REPEAT_2(count, macro, data) \
	UW_CONCAT(IMPL_UW_REPEAT_2_, count)(macro, data)

#define IMPL_UW_REPEAT_2_0(macro, data)
#define IMPL_UW_REPEAT_2_1(macro, data) macro(0, data)
#define IMPL_UW_REPEAT_2_2(macro, data) IMPL_UW_REPEAT_2_1(macro, data) macro(1, data)
#define IMPL_UW_REPEAT_2_3(macro, data) IMPL_UW_REPEAT_2_2(macro, data) macro(2, data)
#define IMPL_UW_REPEAT_2_4(macro, data) IMPL_UW_REPEAT_2_3(macro, data) macro(3, data)
#define IMPL_UW_REPEAT_2_5(macro, data) IMPL_UW_REPEAT_2_4(macro, data) macro(4, data)
#define IMPL_UW_REPEAT_2_6(macro, data) IMPL_UW_REPEAT_2_5(macro, data) macro(5, data)
#define IMPL_UW_REPEAT_2_7(macro, data) IMPL_UW_REPEAT_2_6(macro, data) macro(6, data)
#define IMPL_UW_REPEAT_2_8(macro, data) IMPL_UW_REPEAT_2_7(macro, data) macro(7, data)
#define IMPL_UW_REPEAT_2_9(macro, data) IMPL_UW_REPEAT_2_8(macro, data) macro(8, data)
#define IMPL_UW_REPEAT_2_10(macro, data) IMPL_UW_REPEAT_2_9(macro, data) macro(9, data)
#define IMPL_UW_REPEAT_2_11(macro, data) IMPL_UW_REPEAT_2_10(macro, data) macro(10, data)
#define IMPL_UW_REPEAT_2_12(macro, data) IMPL_UW_REPEAT_2_11(macro, data) macro(11, data)
#define IMPL_UW_REPEAT_2_13(macro, data) IMPL_UW_REPEAT_2_12(macro, data) macro(12, data)
#define IMPL_UW_REPEAT_2_14(macro, data) IMPL_UW_REPEAT_2_13(macro, data) macro(13, data)
#define IMPL_UW_REPEAT_2_15(macro, data) IMPL_UW_REPEAT_2_14(macro, data) macro(14, data)
#define IMPL_UW_REPEAT_2_16(macro, data) IMPL_UW_REPEAT_2_15(macro, data) macro(15, data)
