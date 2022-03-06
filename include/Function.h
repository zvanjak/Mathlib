#include <functional>

#include "VectorStatic.h"

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

class VectorToScalarFunction
{
    public:
    std::function<double(Vector<3>)> &_func;

    VectorToScalarFunction(std::function<double(double)> &inFunc) : _func(inFunc)
    {}

    double operator()(double x) const
    {
        return _func(x);
    }
};

class VectorToVectorFunction
{
    public:
    std::function<Vector<3>(Vector<3>)> &_func;

    VectorToVectorFunction(std::function<double(double)> &inFunc) : _func(inFunc)
    {}

    double operator()(double x) const
    {
        return _func(x);
    }

};

// VectorFunction!!!
// može se parcijalno derivirati
// može se inicijalizirati s Vector3 Transf(Vector3)!