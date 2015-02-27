#include "../Libraries/catch.hpp"
#include "../C++03 Utils/shared_ptr.h"

using school::SharedPtr;
using school::makeShared;

bool g_mockObjectDestroyed;
struct MockObject {
	MockObject() : functionCallCount_() {}

	virtual ~MockObject() {
		g_mockObjectDestroyed = true;
	}

	void function() {
		++functionCallCount_; 
	}

	int functionCallCount() const {
		return functionCallCount_;
	}

private:
	int functionCallCount_;
};

bool g_mockObjectDerivedDestroyed;
struct MockObjectDerived : MockObject {
	~MockObjectDerived() {
		g_mockObjectDerivedDestroyed = true;
	}
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

TEST_CASE("SharedPtr managed object is correct") {
	SharedPtr<MockObject> spMakeShared = makeShared<MockObject>();
	SharedPtr<MockObject> spNew = SharedPtr<MockObject>(new MockObject());

	SECTION("It's not a null pointer") {
		REQUIRE(spMakeShared.get() != 0);
		REQUIRE(spNew.get() != 0);
	}

	SECTION("It's not empty") {
		REQUIRE(!spMakeShared.empty());
		REQUIRE(!spNew.empty());
	}

	SECTION("Dereferencing it does not throw an exception") {
		REQUIRE_NOTHROW(*spMakeShared);
		REQUIRE_NOTHROW(*spNew);
	}

	SECTION("A function can be called") {
		REQUIRE(spMakeShared->functionCallCount() == 0);
		REQUIRE(spNew->functionCallCount() == 0);

		spMakeShared->function();
		spNew->function();
		
		REQUIRE(spNew->functionCallCount() == 1);
		REQUIRE(spMakeShared->functionCallCount() == 1);
	}
}

TEST_CASE("Copy of managed object is correct") {
	SharedPtr<MockObject> sp = makeShared<MockObject>();
	SharedPtr<MockObject> copy(sp);

	SECTION("The pointers are equal") {
		REQUIRE(sp.get() == copy.get());
	}

	SECTION("The pointers are not empty") {
		REQUIRE(!sp.empty());
		REQUIRE(!copy.empty());
	}

	SECTION("Dereferencing them gives the same object") {
		REQUIRE(&*sp == &*copy);
	}

	SECTION("The same function is called") {
		sp->function();
		copy->function();

		REQUIRE(sp->functionCallCount() == 2);
		REQUIRE(copy->functionCallCount() == 2);
	}
}

TEST_CASE("SharedPtr make shared object is destroyed at end of scope") {
	g_mockObjectDestroyed = false;
	{
		SharedPtr<MockObject> sp = makeShared<MockObject>();
	}

	REQUIRE(g_mockObjectDestroyed);
}

TEST_CASE("SharedPtr manual object is destroyed at end of scope") {
	g_mockObjectDestroyed = false;
	{
		SharedPtr<MockObject> sp = SharedPtr<MockObject>(new MockObject());
	}

	REQUIRE(g_mockObjectDestroyed);
}

TEST_CASE("SharedPtr copy object is destroyed at end of both scopes") {
	g_mockObjectDestroyed = false;
	{
		SharedPtr<MockObject> sp = makeShared<MockObject>();
		{
			SharedPtr<MockObject> copy(sp);

			REQUIRE(!g_mockObjectDestroyed);
		}

		REQUIRE(!g_mockObjectDestroyed);
	}

	REQUIRE(g_mockObjectDestroyed);
}

TEST_CASE("SharedPtr to base destroys derived") {
	g_mockObjectDestroyed = false;
	g_mockObjectDerivedDestroyed = false;
	{
		SharedPtr<MockObject> sp = makeShared<MockObjectDerived>();
	}

	REQUIRE(g_mockObjectDestroyed);
	REQUIRE(g_mockObjectDerivedDestroyed);
}