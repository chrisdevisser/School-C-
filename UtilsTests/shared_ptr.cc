#include "../Libraries/catch.hpp"
#include "../C++03 Utils/shared_ptr.h"

using school::SharedPtr;

bool g_mockObjectDestroyed;
struct MockObject {
	MockObject() : functionCalled_() {}

	~MockObject() {
		g_mockObjectDestroyed = true;
	}

	void function() {
		functionCalled_ = true; 
	}

	bool functionCalled() const {
		return functionCalled_;
	}

private:
	bool functionCalled_;
};

TEST_CASE("SharedPtr default is correct") {
	SharedPtr<MockObject> sp;

	SECTION("It's a null pointer") {
		REQUIRE(sp.get() == 0);
	}

	SECTION("It's empty") {
		REQUIRE(sp.empty());
	}

	SECTION("Dereferencing it throws an exception") {
		REQUIRE_THROWS_AS(*sp, std::logic_error);
	}

	SECTION("Calling a function on the pointee throws an exception") {
		REQUIRE_THROWS_AS(sp->function(), std::logic_error);
	}
}

TEST_CASE("SharedPtr copy of default is correct") {
	SharedPtr<MockObject> sp;
	SharedPtr<MockObject> copy(sp);

	SECTION("It's a null pointer") {
		REQUIRE(copy.get() == 0);
	}

	SECTION("It's empty") {
		REQUIRE(copy.empty());
	}

	SECTION("Dereferencing it throws an exception") {
		REQUIRE_THROWS_AS(*copy, std::logic_error);
	}

	SECTION("Calling a function on the pointee throws an exception") {
		REQUIRE_THROWS_AS(copy->function(), std::logic_error);
	}
}