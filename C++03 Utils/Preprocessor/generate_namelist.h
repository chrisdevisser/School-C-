#pragma once

#include "concat.h"
#include "repeat_comma_separated.h"

//Expands to <prefix>0, <prefix>1, <prefix>2, ..., <prefix><count - 1>.
#define UW_GENERATE_NAMELIST(count, prefix) UW_REPEAT_COMMA_SEPARATED(count, IMPL_UW_GENERATE_NAMELIST_MACRO, prefix)

#define IMPL_UW_GENERATE_NAMELIST_MACRO(index, prefix) UW_CONCAT(prefix, index)