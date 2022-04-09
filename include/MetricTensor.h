#if !defined  __MML_METRIC_TENSOR_H
#define __MML_METRIC_TENSOR_H

#include "VectorStatic.h"
#include "MatrixStatic.h"
#include "Derivation.h"
#include "differential_geometry/CoordSystemGeneral.h"

template<int N>
class MetricTensor
{
    public:
    virtual double Component(int i, int j, Vector<N> &pos) const = 0;
    virtual Matrix<N, N> MetricAtPoint(Vector<N> &pos) const = 0;
};


template<int N>
class MetricTensorCartesian: public MetricTensor<N>
{
    public:
    virtual double Component(int i, int j, Vector<N> &pos) const
    {
        if( i == j )
            return 1.0;
        else
            return 0.0;
    }

    virtual Matrix<N, N> MetricAtPoint(Vector<N> &pos) const
    {
        Matrix<N, N> ret;

        for( int i=0; i<3; i++ )
            for( int j=0; j<N; j++ )
                ret(i,j) = Component(i,j, pos);

        return ret;
    }
};

template<int N>
class MetricTensorFromCoordTransf: public MetricTensor<N>
{
    CoordSystemTransf<N> &_coordTransf;

    public:
    MetricTensorFromCoordTransf(CoordSystemTransf<N> &inTransf) : _coordTransf(inTransf)
    { }

    virtual double Component(int i, int j, Vector<N> &pos) const
    {
        double g_ij = 0.0;
        for(int l=0; l<3; l++)
        {
            g_ij += Derivation::DerivePartial(_coordTransf.coordTransfFunc(l), i, pos) * Derivation::DerivePartial(_coordTransf.coordTransfFunc(l), j, pos);
        }
        return g_ij;
    }

    virtual Matrix<N, N> MetricAtPoint(Vector<N> &pos) const 
    {
        Matrix<N, N> ret;

        for( int i=0; i<3; i++ )
            for( int j=0; j<N; j++ )
                ret(i,j) = Component(i,j, pos);

        return ret;
    }
};

#endif