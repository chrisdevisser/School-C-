#include <string>

#include "../../Libraries/catch.hpp"
#include "../../C++03 Utils/Preprocessor/preprocessor.h"

TEST_CASE("CONCAT empty first argument is second") {
	std::string result = UW_STRINGIFY(UW_CONCAT(, x));

	REQUIRE(result == "x");
}

TEST_CASE("CONCAT empty second argument is first") {
	std::string result = UW_STRINGIFY(UW_CONCAT(x, ));

	REQUIRE(result == "x");
}