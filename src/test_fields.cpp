#include "Fields.h"

class RadialScalarPotentialCartesian : public ScalarField<3>
{
    public:
    double Value(Vector<3> &pos)
    {
        double r = sqrt(pos[0]*pos[0] + pos[1]*pos[1] + pos[2]*pos[2]);
        return 1/r;
    }

};

class RadialScalarPotentialSpherical : public ScalarField<3>
{
    public:
    double Value(Vector<3> &pos)
    {
        return 1 / pos[0];
    }

};

void Test_Fields()
{

}