#include <algorithm>
#include <string>

#include "../../Libraries/catch.hpp"
#include "../../C++03 Utils/Preprocessor/preprocessor.h"

TEST_CASE("GENERATE_PARAMETERS 1 T parameter is T0") {
	std::string result = UW_STRINGIFY((UW_GENERATE_PARAMETERS(1, T)));
	result.erase(std::remove(result.begin(), result.end(), ' '), result.end());

	REQUIRE(result == "(T0)");
}

TEST_CASE("GENERATE_PARAMETERS 2 T parameters are T0, T1") {
	std::string result = UW_STRINGIFY((UW_GENERATE_PARAMETERS(2, T)));
	result.erase(std::remove(result.begin(), result.end(), ' '), result.end());

	REQUIRE(result == "(T0,T1)");
}