#if !defined __MML_DERIVATION_H
#define __MML_DERIVATION_H

#include <functional>

#include "Function.h"

#include "../lib/finite_difference.hpp"

class Derivation
{
public:
    static double Derive(const ScalarFunction &f, double x)
    {
        // auto f = [](double x) { return std::exp(x); };
        // double x = 1.7;
        double dfdx = boost::math::differentiation::finite_difference_derivative(f, x);

        return dfdx;
    }

    template <int N>
    class HelperFunc
    {
        const VectorFunction<N> &_func;
        Vector<N> &_x;
        int _der_ind;

    public:
        HelperFunc(const VectorFunction<N> &inFunc, Vector<N> &x) : _func(inFunc), _x(x)
        { }
        HelperFunc(const VectorFunction<N> &inFunc, Vector<N> &x, int der_ind) : _func(inFunc), _x(x), _der_ind(der_ind)
        { }

        void setDerInd(int ind) { _der_ind = ind; }

        double operator()(double x) const
        {
            Vector<N> copy{_x};

            copy[_der_ind] = x;

            return _func(copy);
        }
    };

    template <int N>
    static double DerivePartial(const VectorFunction<N> &f, int deriv_index, Vector<N> &point)
    {
        double x = point[deriv_index];
        HelperFunc<N> helper{f, point, deriv_index};

        double dfdx = boost::math::differentiation::finite_difference_derivative(helper, x);

        return dfdx;
    }

    // BIG TODO - derivacija vektorskog polja PO ODREĐENOM SMJERU
    template <int N>
    static double DeriveDirectional(const VectorFunction<N> &f, Vector<N> &deriv_direction, Vector<N> &point)
    {
        double x = point[deriv_index];
        HelperFunc<N> helper{f, point, deriv_index};

        double dfdx = boost::math::differentiation::finite_difference_derivative(helper, x);

        return dfdx;
    }

    template <int N>
    static Vector<N> DerivePartialByAll(const VectorFunction<N> &f, Vector<N> &point)
    {
        Vector<N> ret;

        HelperFunc<N> helper{f, point};
        for (int i = 0; i < N; i++)
        {
            double x = point[i];
            helper.setDerInd(i);

            ret[i] = boost::math::differentiation::finite_difference_derivative(helper, x);
        }

        return ret;
    }
};

#endif