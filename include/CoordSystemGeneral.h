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

    // ako je definirana tranfromacija
    //      to mora biti kvalitenta funkcija, koja se po parametrima može derivirati numerički!!!
    // zna vratiti MetricTensor u točki!
};

class CoordTransfSphericalToCartesian : public CoordSystemTransf<3>
{
    public:
    Vector<3> transf(Vector<3> in)
    {
        Vector<3> ret;

        ret[0] = in[0] * sin(in[1]) * cos(in[2]);

        return ret;

    }
};

class CoordTransfCartesianToSpherical : public CoordSystemTransf<3>
{

};

