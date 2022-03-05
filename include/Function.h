#include <functional>

// Function1D

class Function
{
    public:
    std::function<double(double)> &_func;

    Function(std::function<double(double)> inFunc) : _func(inFunc)
    {}

};

class VectorFunction
{

};

// VectorFunction!!!
// može se parcijalno derivirati
// može se inicijalizirati s Vector3 Transf(Vector3)!