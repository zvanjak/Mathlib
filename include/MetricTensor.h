#include "CoordSystems3D.h"

template<int N> 
class Vector
{
    public:
    double  _val[N];

    Vector operator+(Vector &b )
    {
        Vector ret;
        for(int i=0; i<N; i++)
            ret._val[i] = _val[i] + b._val[i];
        return ret;
    }

    Vector operator-(Vector &b )
    {
        Vector ret;
        for(int i=0; i<N; i++)
            ret._val[i] = _val[i] - b._val[i];
        return ret;
    }

};

template<>
class Vector<3>
{

};

template<int N, int M> 
class Matrix
{
};

template<int N>
class CoordTransfNew
{
    public:
    virtual Vector<N> transf(Vector<N> &vec) = 0;
};


class CoordTransfSphericalToCartesian : public CoordTransfNew<3>
{

};

class MetricTensor3D
{
    public:
    virtual double Component(int i, int j, Vector<3> pos) = 0;
};