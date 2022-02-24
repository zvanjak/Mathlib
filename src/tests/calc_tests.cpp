//#define CATCH_CONFIG_MAIN

#include "../catch/catch.hpp"

#include "calc.h"
#include "vector.h"

TEST_CASE("Test_Calc", "[simple]") {
    Calculator c;

    Vector a(2);

    a[0] = 1.0;
    a[1] = 1.0;

    Vector b(2);

    b = 2 * a;

	REQUIRE(4.0 ==  c.Add(2,2));
}
