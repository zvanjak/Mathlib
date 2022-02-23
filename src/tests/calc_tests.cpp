//#define CATCH_CONFIG_MAIN

#include "../catch/catch.hpp"

#include "calc.h"

TEST_CASE("Test_Calc", "[simple]") {
    Calculator c;
	

	REQUIRE(4.0 ==  c.Add(2,2));
}
