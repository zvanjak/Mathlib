#if !defined __MML_COORD_SYSTEM_GENERAL_H
#define __MML_COORD_SYSTEM_GENERAL_H

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
    // q[0] = r     - radial distance
    // q[1] = theta - polar angle
    // q[2] = phi   - azimuthal angle
    public:
    static double func1(Vector<3> q) { return q[0] * sin(q[1]) * cos(q[2]); }
    static double func2(Vector<3> q) { return q[0] * sin(q[1]) * sin(q[2]); }
    static double func3(Vector<3> q) { return q[0] * cos(q[1]); }

    inline static VectorFunction<3> _func[3] = { 
                                                VectorFunctionFromStdFunction<3>{std::function<double(Vector<3>)>{func1}},
                                                VectorFunctionFromStdFunction<3>{std::function<double(Vector<3>)>{func2}},
                                                VectorFunctionFromStdFunction<3>{std::function<double(Vector<3>)>{func3}}
                                               };
    Vector<3> transf(Vector<3> q)
    {
        return Vector<3>{ func1(q), func2(q), func3(q) };
    }

    VectorFunction<3> coordTransfFunc(int i)
    {
        return _func[i];
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

#endif