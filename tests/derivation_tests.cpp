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

    REQUIRE(cos(1.0) == Approx(der).epsilon(1e-10));
}

double TestScalarField(Vector<3> x)
{
    return 0.0;
}

TEST_CASE("Test_Partial_Derivative", "[simple]") {
    std::function<double(Vector<3>)> func = TestScalarField;

    VectorFunction<3> f{func};

    Vector<3> point{1.0, 1.0, 1.0 };
    double c = func(point);

    double d = f(point);

    double der = DerivePartial(f, 0, point);

    REQUIRE(cos(1.0) == Approx(der).epsilon(1e-10));
}