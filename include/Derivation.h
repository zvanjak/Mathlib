#include <functional>

#include "Function.h"

#include "../lib/finite_difference.hpp"

double Derivation(ScalarFunction &f2)
{
    auto f = [](double x) { return std::exp(x); };
    double x = 1.7;
    double dfdx = boost::math::differentiation::finite_difference_derivative(f, x);

    return 0.0;
}