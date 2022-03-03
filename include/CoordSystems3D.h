#include <cmath>

class Vector3D
{
private:
    double _x, _y, _z;

public:
    Vector3D(double x, double y, double z) : _x{x}, _y{y}, _z{z}    { }

    double& X() { return _x; }
    double& Y() { return _y; }
    double& Z() { return _z; }
};

class Vector3DSpherical
{
 private:
    double _r, _rho, _theta;

public:
    Vector3DSpherical(double r, double rho, double theta) : _r{r}, _rho{rho}, _theta{theta}    {}

    double& R() { return _r; }
    double& Rho() { return _rho; }
    double& Theta() { return _theta; }
};

class CoordTransf
{
   static void SphericalToCartesian(double radius, double polar, double elevation, Vector3D &outCart)
    {
      double a = radius * cos(elevation);
      outCart.X = radius * sin(elevation) * cos(polar);
      outCart.Y = radius * sin(elevation) * sin(polar);
      outCart.Z = radius * cos(elevation);
    }

    static void CartesianToSpherical(const Vector3D &cartCoords, double &outRadius, double &outPolar, double &outElevation)
    {
      if (cartCoords.X == 0)
        cartCoords.X = 1e-10;
      outRadius = Math.Sqrt((cartCoords.X * cartCoords.X)
                      + (cartCoords.Y * cartCoords.Y)
                      + (cartCoords.Z * cartCoords.Z));
      outPolar = Math.Atan(cartCoords.Y / cartCoords.X);
      if (cartCoords.X < 0)
        outPolar += Math.PI;
      outElevation = Math.Acos(cartCoords.Z / outRadius);
    }
};

class Cartesian3DDomain
{
    virtual bool IsInDomain(Vector3D &pos) = 0;
};

class ScalarFieldCartesian
{
    // domain???
    virtual double Value(Vector3D &pos) = 0;
    virtual Vector3D Gradient(Vector3D &pos)
    {
        return Vector3D{0, 0, 0};
    }
};

class ScalarFieldSpherical
{
    // domain???
    virtual double Value(Vector3DSpherical &pos) = 0;
    virtual Vector3D Gradient(Vector3DSpherical &pos)
    {
        return Vector3D{0, 0, 0};
    }
};