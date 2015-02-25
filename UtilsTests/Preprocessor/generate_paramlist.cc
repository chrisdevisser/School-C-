#include <algorithm>
#include <string>

#include "../../Libraries/catch.hpp"
#include "../../C++03 Utils/Preprocessor/preprocessor.h"

TEST_CASE("GENERATE_PARAMLIST 1 T and arg parameter is T0 arg0") {
	std::string result = UW_STRINGIFY((UW_GENERATE_PARAMLIST(1, T, arg)));
	result.erase(std::remove(result.begin(), result.end(), ' '), result.end());

	REQUIRE(result == "(T0arg0)");
}

TEST_CASE("GENERATE_PARAMLIST 2 T and arg parameters are T0 arg0, T1 arg1") {
	std::string result = UW_STRINGIFY((UW_GENERATE_PARAMLIST(2, T, arg)));
	result.erase(std::remove(result.begin(), result.end(), ' '), result.end());

	REQUIRE(result == "(T0arg0,T1arg1)");
}
