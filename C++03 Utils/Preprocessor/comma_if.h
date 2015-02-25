#pragma once

#include "comma.h"
#include "empty.h"
#include "if.h"

//Expands to a comma if condition expands to 1, or nothing if conditition expands to 0.
#define UW_COMMA_IF(condition) \
	UW_IF(condition, UW_COMMA, UW_EMPTY)()
