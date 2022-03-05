#if !defined  __MML_COORD_SYSTEMS_H
#define __MML_COORD_SYSTEMS_H

#include <cmath>
#include <numbers>
#include <iostream>
#include <iomanip>

class Vector3D
{
private:
    double _x, _y, _z;

public:
    Vector3D() : _x{0.0}, _y{0.0}, _z{0.0} {}
    Vector3D(double x, double y, double z) : _x{x}, _y{y}, _z{z} {}

    double &X() { return _x; }
    double &Y() { return _y; }
    double &Z() { return _z; }

    Vector3D operator+(Vector3D &b)
    {
        return Vector3D{X()+b.X(), Y() + b.Y(), Z() + b.Z()};
    }

    friend std::ostream &operator<<(std::ostream &stream, Vector3D &a)
    {
        stream << "[" << std::setw(8) << a.X() << ", " << a.Y() << ", " << a.Z() << "]";

        return stream;
    }
};

class Vector3DSpherical
{
private:
    double _r, _rho, _theta;

public:
    Vector3DSpherical(double r, double rho, double theta) : _r{r}, _rho{rho}, _theta{theta} {}

    double &R() { return _r; }
    double &Rho() { return _rho; }
    double &Theta() { return _theta; }

    Vector3DSpherical operator+(Vector3DSpherical &b)
    {
        return Vector3DSpherical{R()+b.R(), Rho() + b.Rho(), Theta() + b.Theta()};
    }

    friend std::ostream &operator<<(std::ostream &stream, Vector3DSpherical &a)
    {
        stream << "[" << std::setw(8) << a.R() << ", " << a.Rho() << ", " << a.Theta() << "]";

        return stream;
    }
};

class CoordTransf
{
public:
    static Vector3D SphericalToCartesian(Vector3DSpherical &vec)
    {
        Vector3D outCart;

        outCart.X() = vec.R() * sin(vec.Theta()) * cos(vec.Rho());
        outCart.Y() = vec.R() * sin(vec.Theta()) * sin(vec.Rho());
        outCart.Z() = vec.R() * cos(vec.Theta());

        return outCart;
    }

    static Vector3DSpherical CartesianToSpherical(Vector3D &cartCoords)
    {
        if (cartCoords.X() == 0)
            cartCoords.X() = 1e-10;

        double outRadius = sqrt((cartCoords.X() * cartCoords.X()) + (cartCoords.Y() * cartCoords.Y()) + (cartCoords.Z() * cartCoords.Z()));
        double outPolar = atan2(cartCoords.Y(), cartCoords.X());

        if (cartCoords.X() < 0)
            outPolar += 3.1415963;

        double outElevation = acos(cartCoords.Z() / outRadius);

        return Vector3DSpherical{outRadius, outPolar, outElevation};
    }
};


#endif