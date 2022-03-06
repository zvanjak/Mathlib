#include <functional>

// Function1D

class ScalarFunction
{
    public:
    std::function<double(double)> &_func;

    ScalarFunction(std::function<double(double)> inFunc) : _func(inFunc)
    {}

    double operator()(double x)
    {
        return _func(x);
    }

};

class VectorToScalarFunction
{

};

class VectorToVectorFunction
{

};

// VectorFunction!!!
// može se parcijalno derivirati
// može se inicijalizirati s Vector3 Transf(Vector3)!