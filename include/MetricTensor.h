#include "VectorStatic.h"
#include "MatrixStatic.h"

template<int N>
class MetricTensor
{
    public:
    virtual double Component(int i, int j, Vector<N> &pos) = 0;
    virtual Matrix<N, N> MetricAtPoint(Vector<N> &pos) = 0;
};
