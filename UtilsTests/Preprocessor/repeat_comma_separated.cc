#include <algorithm>
#include <string>

#include "../../Libraries/catch.hpp"
#include "../../C++03 Utils/Preprocessor/preprocessor.h"

#define MACRO_CONSTANT(index, data) text

TEST_CASE("REPEAT_COMMA_SEPARATED 1 time has no commas") {
	std::string result = UW_STRINGIFY((UW_REPEAT_COMMA_SEPARATED(1, MACRO_CONSTANT, data)));
	result.erase(std::remove(result.begin(), result.end(), ' '), result.end());

	REQUIRE(result == "(text)");
}

TEST_CASE("REPEAT_COMMA_SEPARATED 2 times has comma") {
	std::string result = UW_STRINGIFY((UW_REPEAT_COMMA_SEPARATED(2, MACRO_CONSTANT, data)));
	result.erase(std::remove(result.begin(), result.end(), ' '), result.end());

	REQUIRE(result == "(text,text)");
}

#undef MACRO_CONSTANT

#define MACRO_ARGS(index, data) (index, data)

TEST_CASE("REPEAT_COMMA_SEPARATED 1 time passes data") {
	std::string result = UW_STRINGIFY((UW_REPEAT_COMMA_SEPARATED(1, MACRO_ARGS, textdata)));
	result.erase(std::remove(result.begin(), result.end(), ' '), result.end());

	REQUIRE(result == "((0,textdata))");
}

TEST_CASE("REPEAT_COMMA_SEPARATED 2 times passes data") {
	std::string result = UW_STRINGIFY((UW_REPEAT_COMMA_SEPARATED(2, MACRO_ARGS, textdata)));
	result.erase(std::remove(result.begin(), result.end(), ' '), result.end());

	REQUIRE(result == "((0,textdata),(1,textdata))");
}

#undef MACRO_ARGS