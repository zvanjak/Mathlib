#include "Fields.h"
#include "MetricTensor.h"
#include "CoordSystemGeneral.h"

class RadialScalarPotentialCartesian : public ScalarField<3>
{
    MetricTensorCartesian<3>     _mt;

    public:
    double Value(Vector<3> &pos) const
    {
        double r = sqrt(pos[0]*pos[0] + pos[1]*pos[1] + pos[2]*pos[2]);
        return 1/r;
    }

    const MetricTensor<3>& Metric() const
    {
        return _mt;
    }
};

class RadialScalarPotentialSpherical : public ScalarField<3>
{
    CoordTransfSphericalToCartesian     _transf;
    MetricTensorFromCoordTransf<3>     *_mt;

    public:
    RadialScalarPotentialSpherical()
    {
        _mt = new MetricTensorFromCoordTransf<3> (_transf);
    }

    double Value(Vector<3> &pos) const
    {
        return 1 / pos[0];
    }

    const MetricTensor<3>& Metric() const
    {
        return *_mt;
    }

};

void Test_Fields()
{
    RadialScalarPotentialCartesian      fieldCart;
    RadialScalarPotentialSpherical      fieldSpher;

    Vector<3> posC{1.0, 1.0, 1.0 };
    Vector<3> gradC = fieldCart.Gradient(posC);

    gradC.Print();
    
    Vector<3> posS{1.73, 0.785, 0.955 };            // LOL manualno izračunavanje :)
    Vector<3> gradS = fieldSpher.Gradient(posS);
}