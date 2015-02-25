#pragma once

#include "comma_if.h"
#include "pair.h"
#include "repeat.h"

//Acts like REPEAT, but inserts a comma between results
#define UW_REPEAT_COMMA_SEPARATED(count, macro, data) \
	UW_REPEAT(count, IMPL_UW_REPEAT_COMMA_SEPARATED_MACRO, (macro, data))

//COMMA_IF inserts a comma if index is not 0, which is only true for the first call.
//PAIR_FIRST gets the macro to call and PAIR_SECOND gets the data to pass in.
#define IMPL_UW_REPEAT_COMMA_SEPARATED_MACRO(index, pair) \
	UW_COMMA_IF(index) UW_PAIR_FIRST(pair)(index, UW_PAIR_SECOND(pair))
