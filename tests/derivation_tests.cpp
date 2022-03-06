#include "../catch/catch.hpp"

#include "Derivation.h"

double TestSin(double x)
{
    return sin(x);
}

TEST_CASE("Test_Derivative", "[simple]") {
    std::function<double(double)> func = TestSin;

    ScalarFunction f{func};

    double c = func(1.0);
    
    double d = f(1.0);

    double der = Derive(f, 1.0);

    REQUIRE(cos(1.0) == der);
}