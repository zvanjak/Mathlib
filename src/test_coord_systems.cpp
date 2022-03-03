#include "CoordSystems3D.h"

class SimpleScalarField: public ScalarFieldCartesian
{
    public:
     double Value(Vector3D &pos)
     {
         return pos.X() * pos.X() + pos.Y() * pos.Y() + pos.Z() * pos.Z();
     }

};

void Test_Coord_Systems()
{
    std::cout << "TESTING COORDINATE SYSTEMS" << std::endl;
    
    // zadam skalarno polje - parabola obrnuta s vrhom u centru
    SimpleScalarField   field;

    // odaberem točku (1, 1, 1)
    Vector3D pos(1.0, 1.0, 1.0);

    Vector3D grad = field.Gradient(pos);

    std::cout << grad << std::endl;
    // ispis
    
}