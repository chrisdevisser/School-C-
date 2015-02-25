#pragma once

#define UW_CONCAT(arg1, arg2) \
	IMPL_UW_CONCAT(arg1, arg2)

#define IMPL_UW_CONCAT(arg1, arg2) \
	arg1##arg2
