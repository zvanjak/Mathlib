#include <functional>

#include "Function.h"

#include "../lib/finite_difference.hpp"

double Derive(const ScalarFunction &f, double x)
{
    //auto f = [](double x) { return std::exp(x); };
    //double x = 1.7;
    double dfdx = boost::math::differentiation::finite_difference_derivative(f, x);

    return dfdx;
}