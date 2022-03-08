#include <cmath>

#include "MetricTensor.h"

/*

- imamo DVA koordinatna sustava - polazni i cljni

*/

template<int N>
class CoordSystemTransf
{
    public:
    virtual Vector<N> transf(Vector<N> in) = 0;
    virtual VectorFunction<N> coordTransfFunc(int i) = 0;

    // ako je definirana transformacija
    //      to mora biti kvalitenta funkcija, koja se po parametrima može derivirati numerički!!!
    // zna vratiti MetricTensor u točki!
};

class CoordTransfSphericalToCartesian : public CoordSystemTransf<3>
{
    static double func1(Vector<3> q) { return q[0] * sin(q[1]) * cos(q[2]); }

    inline static VectorFunction<3> _func = { VectorFunction<3>{std::function<double(Vector<3>)>{func1}}};
    // q1 = r     - radial distance
    // q2 = theta - polar angle
    // q3 = phi   - azimuthal angle

    public:
    Vector<3> transf(Vector<3> q)
    {
        Vector<3> ret;

        ret[0] = q[0] * sin(q[1]) * cos(q[2]);
        ret[1] = q[0] * sin(q[1]) * sin(q[2]);
        ret[2] = q[0] * cos(q[1]);

        return ret;

    }

    VectorFunction<3> coordTransfFunc(int i)
    {
        return _func;

    }
};

class CoordTransfCartesianToSpherical : public CoordSystemTransf<3>
{

};

class CoordTransfCylindricalToCartesian : public CoordSystemTransf<3>
{
    // q1 = r     - distance from symmetry axis
    // q2 = theta - angle to symmetry axis
    // q3 = z     - z
    public:
    Vector<3> transf(Vector<3> q)
    {
        Vector<3> ret;

        ret[0] = q[0] * cos(q[1]);
        ret[1] = q[0] * sin(q[1]);
        ret[2] = q[2];

        return ret;

    }
};

