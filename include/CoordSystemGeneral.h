#include "MetricTensor.h"

/*

- imamo DVA koordinatna sustava - polazni i cljni

*/

class CoordSystemTransf3D
{
    public:
    virtual Vector<3> transf(Vector<3> in) = 0;

    // ako je definirana tranfromacija
    //      to mora biti kvalitenta funkcija, koja se po parametrima može derivirati numerički!!!
    // zna vratiti MetricTensor u točki!
};