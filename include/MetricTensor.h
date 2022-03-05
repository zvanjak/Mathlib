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

class CoordTransf
{
    public:
    virtual Vector<3> transf(Vector<3> &vec) = 0;
};

class MetricTensor3D
{
    public:
    virtual double Component(int i, int j, Vector<3> pos) = 0;
};