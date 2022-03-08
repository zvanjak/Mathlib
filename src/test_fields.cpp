#include "Fields.h"
#include "MetricTensor.h"
class RadialScalarPotentialCartesian : public ScalarField<3>
{
    CoordTransfSphericalToCartesian     _transf;
    MetricTensorFromCoordTransf<3>     _mt(transf);

    public:
    double Value(Vector<3> &pos)
    {
        double r = sqrt(pos[0]*pos[0] + pos[1]*pos[1] + pos[2]*pos[2]);
        return 1/r;
    }

    MetricTensor<N>& Metric(Vector<3> &pos)
    {

    }
};

class RadialScalarPotentialSpherical : public ScalarField<3>
{
    CoordTransfSphericalToCartesian     _transf;
    MetricTensorFromCoordTransf<3>     _mt(transf);

    public:
    double Value(Vector<3> &pos)
    {
        return 1 / pos[0];
    }

    MetricTensor<N>& Metric(Vector<3> &pos)
    {

    }

};

void Test_Fields()
{

}