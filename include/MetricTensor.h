#include "VectorStatic.h"


template<int N, int M> 
class Matrix
{
};


class MetricTensor3D
{
    public:
    virtual double Component(int i, int j, Vector<3> pos) = 0;
};