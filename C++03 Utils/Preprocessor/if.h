#pragma once

#include "bool.h"
#include "concat.h"

//We will use two helper macros to determine whether conditionInteger is effectively 1 or 0.
//We concatenate a common prefix with the value.
//Below are two macros representing the two possible results.
#define UW_IF(conditionInteger, trueReplacement, falseReplacement) UW_CONCAT(IMPL_UW_IF_, UW_BOOL(conditionInteger))(trueReplacement, falseReplacement)

#define IMPL_UW_IF_1(trueReplacement, falseReplacement) trueReplacement
#define IMPL_UW_IF_0(trueReplacement, falseReplacement) falseReplacement