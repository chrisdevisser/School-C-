#include "../Libraries/catch.hpp"
#include "../C++03 Utils/smart_ptr.h"

using school::SmartPtr;

TEST_CASE("SmartPtr default is null pointer") {
	SmartPtr<int> sp;
	
	REQUIRE(sp.get() == 0);
}