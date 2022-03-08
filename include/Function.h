#if !defined  __MML_FUNCTION_H
#define __MML_FUNCTION_H

#include <functional>

#include "VectorStatic.h"


// TODO
template<typename _RetType, typename _ArgType>
class FunctionTemplate
{
    public:
    virtual _RetType operator()(_ArgType) = 0;
};

// napraviti specijalizaciju za double, double
// odnosno nekoliko njih! - jedna je std::function, druga je Tabulated
// Function1D

class ScalarFunction
{
    public:
    std::function<double(double)> &_func;

    ScalarFunction(std::function<double(double)> &inFunc) : _func(inFunc)
    {}

    double operator()(double x) const
    {
        return _func(x);
    }
};

template<int N>
class VectorFunction
{
    public:
    std::function<double(Vector<N>)> _func;

    VectorFunction(std::function<double(Vector<N>)> inFunc) : _func(inFunc)
    {}

    double operator()(Vector<N> x) const
    {
        return _func(x);
    }
};

class VectorToVectorFunction
{
    public:
    std::function<Vector<3>(Vector<3>)> &_func;

    VectorToVectorFunction(std::function<Vector<3>(Vector<3>)> &inFunc) : _func(inFunc)
    {}

    Vector<3> operator()(Vector<3> x) const
    {
        return _func(x);
    }

};

// VectorFunction!!!
// može se parcijalno derivirati
// može se inicijalizirati s Vector3 Transf(Vector3)!

#endif