#pragma once

#include "concat.h"

#define UW_IF(conditionInteger, trueReplacement, falseReplacement) IMPL_UW_IF(conditionInteger, trueReplacement, falseReplacement)
#define IMPL_UW_IF(conditionInteger, trueReplacement, falseReplacement) UW_CONCAT(IMPL_UW_IF_, conditionInteger)(trueReplacement, falseReplacement)

#define IMPL_UW_IF_1(trueReplacement, falseReplacement) trueReplacement
#define IMPL_UW_IF_0(trueReplacement, falseReplacement) falseReplacement