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
    RadialScalarPotentialSpherical() { _mt = new MetricTensorFromCoordTransf<3> (_transf); }
    const MetricTensor<3>& Metric() const { return *_mt; }

    double Value(Vector<3> &pos) const  { return 1 / pos[0]; }
};

class RadialScalarPotentialSpherical_R_squared : public ScalarField<3>
{
    CoordTransfSphericalToCartesian     _transf;
    MetricTensorFromCoordTransf<3>     *_mt;

    public:
    RadialScalarPotentialSpherical_R_squared() { _mt = new MetricTensorFromCoordTransf<3> (_transf); }
    const MetricTensor<3>& Metric() const { return *_mt; }

    double Value(Vector<3> &pos) const  { return pos[0] * pos[2]; }
};

void Test_Fields()
{
    std::cout << "TESTING FIELDS:\n";

    RadialScalarPotentialCartesian      fieldCart;
    RadialScalarPotentialSpherical      fieldSpher;

    Vector<3> posC{1.0, 1.0, 1.0 };
    Vector<3> gradC = fieldCart.Gradient(posC);

    std::cout << gradC << std::endl;
    
    CoordTransfCartesianToSpherical cartToSpher;

    auto posS = cartToSpher.transf(posC);
    std::cout << posS << std::endl;

    Vector<3> gradS = fieldSpher.Gradient(posS);

    std::cout << gradS << std::endl;

}