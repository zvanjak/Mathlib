#if !defined  __MML_METRIC_TENSOR_H
#define __MML_METRIC_TENSOR_H

#include "VectorStatic.h"
#include "MatrixStatic.h"
#include "Derivation.h"
#include "CoordSystemGeneral.h"

template<int N>
class MetricTensor
{
    public:
    virtual double Component(int i, int j, Vector<N> &pos) = 0;
    virtual Matrix<N, N> MetricAtPoint(Vector<N> &pos) = 0;
};

template<int N>
class MetricTensorFromCoordTransf
{
    CoordSystemTransf &_coordTransf;

    public:
    MetricTensorFromCoordTransf(CoordSystemTransf &inTransf) : _coordTransf(inTransf)
    {
        
    }

    virtual double Component(int i, int j, Vector<N> &pos)
    {
        double g_ij = 0.0;
        for(int l=0; l<3; l++)
        {
            g_ij += DerivePartial(_coordTransf)
        }
    }

    virtual Matrix<N, N> MetricAtPoint(Vector<N> &pos)
    {

    }
};

#endif