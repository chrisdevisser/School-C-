#include <string>

#include "../../Libraries/catch.hpp"
#include "../../C++03 Utils/Preprocessor/preprocessor.h"

TEST_CASE("PAIR_FIRST expands to first element") {
	std::string result = UW_STRINGIFY(UW_PAIR_FIRST((first, second)));

	REQUIRE(result == "first");
}

TEST_CASE("PAIR_SECOND expands to second element") {
	std::string result = UW_STRINGIFY(UW_PAIR_SECOND((first, second)));

	REQUIRE(result == "second");
}

#define PAIR (first, second)

TEST_CASE("PAIR_FIRST expands macro to first element") {
	std::string result = UW_STRINGIFY(UW_PAIR_FIRST(PAIR));

	REQUIRE(result == "first");
}

TEST_CASE("PAIR_SECOND expands macro to second element") {
	std::string result = UW_STRINGIFY(UW_PAIR_SECOND(PAIR));

	REQUIRE(result == "second");
}

#undef PAIR