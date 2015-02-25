#include <string>

#include "../../Libraries/catch.hpp"
#include "../../C++03 Utils/Preprocessor/preprocessor.h"

#define MACRO expanded

TEST_CASE("CONCAT macro first argument is expanded") {
	std::string result = UW_STRINGIFY(UW_CONCAT(MACRO, x));

	REQUIRE(result == "expandedx");
}

TEST_CASE("CONCAT macro second argument is expanded") {
	std::string result = UW_STRINGIFY(UW_CONCAT(x, MACRO));

	REQUIRE(result == "xexpanded");
}
