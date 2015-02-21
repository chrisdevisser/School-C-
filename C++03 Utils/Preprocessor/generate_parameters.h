#pragma once

#include "concat.h"
#include "repeat_comma_separated.h"

#define UW_GENERATE_PARAMETERS(count, prefix) UW_REPEAT_COMMA_SEPARATED(count, IMPL_UW_GENERATE_PARAMETERS_MACRO, prefix)

#define IMPL_UW_GENERATE_PARAMETERS_MACRO(index, prefix) UW_CONCAT(prefix, index)