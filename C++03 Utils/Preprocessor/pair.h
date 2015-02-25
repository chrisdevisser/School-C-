#pragma once

#include "concat.h"

#if _MSC_VER
	#define UW_PAIR_FIRST(pair) IMPL_UW_PAIR_FIRST(pair)
	#define UW_PAIR_SECOND(pair) IMPL_UW_PAIR_SECOND(pair)
#else
	#define UW_PAIR_FIRST(pair) IMPL2_UW_PAIR_FIRST pair
	#define UW_PAIR_SECOND(pair) IMPL2_UW_PAIR_SECOND pair
#endif

//these are necessary for MSVC to get a clue
#define IMPL_UW_PAIR_FIRST(pair) UW_CONCAT(IMPL2_UW_PAIR_FIRST##pair,)
#define IMPL_UW_PAIR_SECOND(pair) UW_CONCAT(IMPL2_UW_PAIR_SECOND##pair,)

#define IMPL2_UW_PAIR_FIRST(first, second) first
#define IMPL2_UW_PAIR_SECOND(first, second) second
