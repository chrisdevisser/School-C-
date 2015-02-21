#include <string>

#include "../../Libraries/catch.hpp"
#include "../../C++03 Utils/Preprocessor/preprocessor.h"

TEST_CASE("COMMA_IF 1 expands to comma") {
	std::string result = UW_STRINGIFY(UW_COMMA_IF(1));

	REQUIRE(result == ",");
}

TEST_CASE("COMMA_IF 0 expands to nothing") {
	REQUIRE(UW_COMMA_IF(0) true);
}