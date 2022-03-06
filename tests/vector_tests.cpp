//#define CATCH_CONFIG_MAIN

#include "../catch/catch.hpp"

#include "VectorN.h"

TEST_CASE("Test_VectorN_mul_double", "[simple]") {
    MML::VectorN a(2);

    a[0] = 1.0;
    a[1] = 1.0;

    MML::VectorN b(2);

    //b = 2 * a;

	REQUIRE(1.0 ==  a[0]);
	REQUIRE(1.0 ==  a[1]);
}
