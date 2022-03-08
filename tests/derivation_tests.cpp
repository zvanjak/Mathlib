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

    double der = Derivation::Derive(f, 1.0);

    REQUIRE(cos(1.0) == Approx(der).epsilon(1e-10));
}

double TestScalarField(Vector<3> x)
{
    return cos(x[0]) + sin(x[1]) + exp(x[2]);
}

TEST_CASE("Test_Partial_Derivative", "[simple]") {
    std::function<double(Vector<3>)> func = TestScalarField;

    VectorFunction<3> f{func};

    Vector<3> point{1.0, 1.0, 1.0 };
    double c = func(point);

    double d = f(point);

    // prva komponenta je cos() pa očekujemo derivaciju -sin()
    double der1 = Derivation::DerivePartial(f, 0, point);
    REQUIRE(-sin(1.0) == Approx(der1).epsilon(1e-10));

    // druga  komponenta je sin() pa očekujemo derivaciju cos()
    double der2 = Derivation::DerivePartial(f, 1, point);
    REQUIRE(cos(1.0) == Approx(der2).epsilon(1e-10));

    // treća komponenta je exp() pa očekujemo derivaciju exp()
    double der3 = Derivation::DerivePartial(f, 2, point);
    REQUIRE(exp(1.0) == Approx(der3).epsilon(1e-10));

}