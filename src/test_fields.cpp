#include "Fields.h"

class RadialScalarPotentialCartesian : public ScalarField<3>
{
    public:
    double Value(Vector<3> &pos)
    {
        return 0.0;
    }

};

void Test_Fields()
{

}