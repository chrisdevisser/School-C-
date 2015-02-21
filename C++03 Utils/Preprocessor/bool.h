#pragma once

#include "concat.h"

//Expands to 0 if integer is 0, or 1 if integer is 1, 2, ..., 16
#define UW_BOOL(integer) UW_CONCAT(IMPL_UW_BOOL_, integer)

#define IMPL_UW_BOOL_0 0
#define IMPL_UW_BOOL_1 1
#define IMPL_UW_BOOL_2 1
#define IMPL_UW_BOOL_3 1
#define IMPL_UW_BOOL_4 1
#define IMPL_UW_BOOL_5 1
#define IMPL_UW_BOOL_6 1
#define IMPL_UW_BOOL_7 1
#define IMPL_UW_BOOL_8 1
#define IMPL_UW_BOOL_9 1
#define IMPL_UW_BOOL_10 1
#define IMPL_UW_BOOL_11 1
#define IMPL_UW_BOOL_12 1
#define IMPL_UW_BOOL_13 1
#define IMPL_UW_BOOL_14 1
#define IMPL_UW_BOOL_15 1
#define IMPL_UW_BOOL_16 1
