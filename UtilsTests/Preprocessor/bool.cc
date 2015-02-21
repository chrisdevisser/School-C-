#include <string>

#include "../../Libraries/catch.hpp"
#include "../../C++03 Utils/Preprocessor/preprocessor.h"

TEST_CASE("BOOL 0 expands to 0") {
	std::string result = UW_STRINGIFY(UW_BOOL(0));

	REQUIRE(result == "0");
}

TEST_CASE("BOOL 1 expands to 1") {
	std::string result = UW_STRINGIFY(UW_BOOL(1));

	REQUIRE(result == "1");
}

TEST_CASE("BOOL 2 expands to 1") {
	std::string result = UW_STRINGIFY(UW_BOOL(2));

	REQUIRE(result == "1");
}

TEST_CASE("BOOL 16 expands to 1") {
	std::string result = UW_STRINGIFY(UW_BOOL(16));

	REQUIRE(result == "1");
}