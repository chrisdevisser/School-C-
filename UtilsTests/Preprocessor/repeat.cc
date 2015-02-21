#include <string>

#include "../../C++03 Utils/Preprocessor/preprocessor.h"
#include "../../Libraries/catch.hpp"

#define MACRO_1D_CONSTANT(index, data) text1d

TEST_CASE("REPEAT 1D 1 time calls macro once") {
	std::string result = UW_STRINGIFY(UW_REPEAT(1, MACRO_1D_CONSTANT, data));

	REQUIRE(result == "text1d");
}

TEST_CASE("REPEAT 1D 2 times calls macro twice") {
	std::string result = UW_STRINGIFY(UW_REPEAT(2, MACRO_1D_CONSTANT, data));

	REQUIRE(result == "text1d text1d");
}

#define MACRO_2D_CONSTANT(index, data) text2d UW_REPEAT(1, MACRO_1D_CONSTANT, data)

TEST_CASE("REPEAT 2D 1 time calls each macro once") {
	std::string result = UW_STRINGIFY(UW_REPEAT(1, MACRO_2D_CONSTANT, data));

	REQUIRE(result == "text2d text1d");
}

TEST_CASE("REPEAT 2D 2 times calls each macro twice") {
	std::string result = UW_STRINGIFY(UW_REPEAT(2, MACRO_2D_CONSTANT, data));

	REQUIRE(result == "text2d text1d text2d text1d");
}

#undef MACRO_1D_CONSTANT
#undef MACRO_2D_CONSTANT

#define MACRO_1D_ARGS(index, data) (index, data)

TEST_CASE("REPEAT 1D 1 time gives macro correct arguments") {
	std::string result = UW_STRINGIFY(UW_REPEAT(1, MACRO_1D_ARGS, datatext));

	REQUIRE(result == "(0, datatext)");
}

TEST_CASE("REPEAT 1D 2 times gives macro correct arguments") {
	std::string result = UW_STRINGIFY(UW_REPEAT(2, MACRO_1D_ARGS, datatext));

	REQUIRE(result == "(0, datatext) (1, datatext)");
}

#define MACRO_2D_ARGS(index, data) (index, data)->UW_REPEAT(1, MACRO_1D_ARGS, innerdata)

TEST_CASE("REPEAT 2D 1 time gives macros correct arguments") {
	std::string result = UW_STRINGIFY(UW_REPEAT(1, MACRO_2D_ARGS, datatext));

	REQUIRE(result == "(0, datatext)->(0, innerdata)");
}

TEST_CASE("REPEAT 2D 2 times gives macros correct arguments") {
	std::string result = UW_STRINGIFY(UW_REPEAT(2, MACRO_2D_ARGS, datatext));

	REQUIRE(result == "(0, datatext)->(0, innerdata) (1, datatext)->(0, innerdata)");
}

#undef MACRO_1D_ARGS
#undef MACRO_2D_ARGS