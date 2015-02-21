#include <string>

#include "../../Libraries/catch.hpp"
#include "../../C++03 Utils/Preprocessor/preprocessor.h"

TEST_CASE("IF 1 expands to true replacement") {
	std::string result = UW_STRINGIFY(UW_IF(1, true text, false text));

	REQUIRE(result == "true text");
}

TEST_CASE("IF 0 expands to false replacement") {
	std::string result = UW_STRINGIFY(UW_IF(0, true text, false text));

	REQUIRE(result == "false text");
}

#define MACRO 1
TEST_CASE("IF macro condition is expanded") {
	std::string result = UW_STRINGIFY(UW_IF(MACRO, true text, false text));

	REQUIRE(result == "true text");
}
#undef MACRO