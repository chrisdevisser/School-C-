#include <string>

#include "../../Libraries/catch.hpp"
#include "../../C++03 Utils/Preprocessor/stringify.h"

TEST_CASE("STRINGIFY letter expands to string") {
	std::string result = UW_STRINGIFY(x);

	REQUIRE(result == "x");
}

#define MACRO text
TEST_CASE("STRINGIFY macro argument is evaluated") {
	std::string result = UW_STRINGIFY(MACRO);

	REQUIRE(result == "text");
}
#undef MACRO
