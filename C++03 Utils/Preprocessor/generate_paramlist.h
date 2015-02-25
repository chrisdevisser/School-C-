#pragma once

#include "concat.h"
#include "pair.h"
#include "repeat_comma_separated.h"

//Generates <prefix1>0 <prefix2>0, <prefix1>1 <prefix2>1, ..., <prefix1><count - 1> <prefix2><count - 1>.
#define UW_GENERATE_PARAMLIST(count, prefix1, prefix2) \
	UW_REPEAT_COMMA_SEPARATED(count, IMPL_UW_GENERATE_PARAMLIST_MACRO, (prefix1, prefix2))

#define IMPL_UW_GENERATE_PARAMLIST_MACRO(index, prefixPair) \
	UW_CONCAT(UW_PAIR_FIRST(prefixPair), index) UW_CONCAT(UW_PAIR_SECOND(prefixPair), index)
