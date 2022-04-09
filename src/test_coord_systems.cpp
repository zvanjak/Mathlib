#include "geometry/CoordSystems3D.h"
#include "Fields.h"
#include "MetricTensor.h"

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

    Vector3DSpherical posSpher = CoordTransf::CartesianToSpherical(pos);
    std::cout << "Spherical point: " << posSpher << std::endl;

    SimpleScalarField   field;
    GradientFieldCartesian  fieldGrad(field);
    Vector3D grad = fieldGrad.Value(pos);
    std::cout << "Cartesian gradient: " << grad << std::endl;

    SimpleScalarFieldSpherical   fieldSpher;
    Vector3DSpherical gradSpher = fieldSpher.Gradient(posSpher);
    std::cout << "Spherical gradient: " << gradSpher << std::endl;

    Vector3D spherGradTrans = CoordTransf::SphericalToCartesian(gradSpher);
    std::cout << "Sph. grad. to Cart: " << spherGradTrans << std::endl;    

    std::cout << "Cartesian gradient tip point: " << pos + grad << std::endl;
    std::cout << "Spherical gradient tip point: " << posSpher + gradSpher << std::endl;

    Vector3D spherTipTrans = CoordTransf::SphericalToCartesian(posSpher + gradSpher);
    std::cout << "Sph. grad. tip conv. to Cart: " << spherTipTrans << std::endl;    

}

// TODO - dodati 2D - Cart + Polar

// TODO - sferne koordinate u dvije konvencije

/*
HMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
    - krenuti SAMO od transformacijskih funkcija za koordinate???
    -> odatle se može izračunati metrički tenzor u svakoj točki!!!!!

*/
// TODO - apstrakcija Polynom - QuadraticForm2D? -. potencije x i y?
//      - Polynom2D - input je Vector2D?

// TODO - AUTOMATIC DIFFERENTIATORS
//      - traže samo Value( X ) funkciju

// TODO - SKALARNA POLJA
//      - gravitacijski potencijal (gradijent je vektor sile)

// TODO - vector field
//    - konstantni po jednoj osi
//    - koncentrični oko osi (dugi vodič)
// TODO  - vector field primjer - laminarni flow u cilindričnoj cijevi!

