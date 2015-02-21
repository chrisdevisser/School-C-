#pragma once

#include "concat.h"

//We will delegate to the implementation macro so that conditionInteger is expanded if it is a macro.
#define UW_IF(conditionInteger, trueReplacement, falseReplacement) IMPL_UW_IF(conditionInteger, trueReplacement, falseReplacement)

//We will use two helper macros to determine whether conditionInteger is 1 or 0.
//We concatenate a common prefix with the value.
//Below are two macros representing the two possible results.
#define IMPL_UW_IF(conditionInteger, trueReplacement, falseReplacement) UW_CONCAT(IMPL_UW_IF_, conditionInteger)(trueReplacement, falseReplacement)

#define IMPL_UW_IF_1(trueReplacement, falseReplacement) trueReplacement
#define IMPL_UW_IF_0(trueReplacement, falseReplacement) falseReplacement