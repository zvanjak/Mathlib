#include "CoordSystems3D.h"

class SimpleScalarField: public ScalarFieldCartesian
{
    public:
     double Value(Vector3D &pos)
     {
         return pos.X() * pos.X() + pos.Y() * pos.Y() + pos.Z() * pos.Z();
     }

};

class SimpleScalarFieldSpherical: public ScalarFieldSpherical
{
    public:
     double Value(Vector3DSpherical &pos)
     {
         Vector3D posCart = CoordTransf::SphericalToCartesian(pos);

         return posCart.X() * posCart.X() + posCart.Y() * posCart.Y() + posCart.Z() * posCart.Z();
     }

};

void Test_Coord_Systems()
{
    std::cout << "TESTING COORDINATE SYSTEMS" << std::endl;

    // odaberem točku (1, 1, 1)
    Vector3D pos(1.0, 1.0, 1.0);
    std::cout << "Cartesian point: " << pos << std::endl;
    std::cout << "Spherical point: " << CoordTransf::CartesianToSpherical(pos) << std::endl;

    SimpleScalarField   field;
    Vector3D grad = field.Gradient(pos);
    std::cout << "Cartesian gradient: " << grad << std::endl;

    SimpleScalarFieldSpherical   fieldSpher;
    Vector3DSpherical gradSpher = fieldSpher.Gradient(CoordTransf::CartesianToSpherical(pos));
    std::cout << "Spherical gradient: " << gradSpher << std::endl;

    Vector3D spherGradTrans = CoordTransf::SphericalToCartesian(gradSpher);
    std::cout << "Sph. grad. to Cart: " << spherGradTrans << std::endl;    
}

// TODO - vector field
//    - konstantni po jednoj osi
//    - koncentrični oko osi (dugi vodič)
// TODO  - vector field primjer - laminarni flow u cilindričnoj cijevi!

// kontrast vector fielda koji dobijem od gradijenta, i ovih gore!!!