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

class HelperFunc
{
    const VectorFunction &_func;
    Vector<3> &_x;
    int _der_ind;

    public:
    HelperFunc(const VectorFunction &inFunc, Vector<3> &x, int der_ind) : _func(inFunc), _x(x), _der_ind(der_ind)
    {}

    double operator() (double x) const
    {
        Vector<3> copy{_x};

        copy[_der_ind] = x;

        return _func(copy);
    }
};

double DerivePartial(const VectorFunction &f, int deriv_index, Vector<3> &point)
{
    double x = point[deriv_index];
    HelperFunc helper{f, point, deriv_index};

    double dfdx = boost::math::differentiation::finite_difference_derivative(helper, x);

    return dfdx;
}
