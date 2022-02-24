//#define CATCH_CONFIG_MAIN

#include "../catch/catch.hpp"

#include "vector.h"

TEST_CASE("Test_Vector_mul_double", "[simple]") {
    Vector a(2);

    a[0] = 1.0;
    a[1] = 1.0;

    Vector b(2);

    b = 2 * a;

	REQUIRE(2.0 ==  b[0]);
	REQUIRE(2.0 ==  b[1]);
}
