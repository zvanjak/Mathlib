#if !defined  __MML_COORD_SYSTEMS_H
#define __MML_COORD_SYSTEMS_H

#include <cmath>
#include <numbers>
#include <iostream>
#include <sstream>
#include <iomanip>

/*
    Kompletno modelirati sve u 3D koordinatnom sistemu
    - kartezijeve, sferne i cilindrične koordinate, konkreten
    - definirani i gradijenti i operatori točni
    - rotacije i konkretne transformacije?
*/

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

    double X() const { return _x; }
    double Y() const { return _y; }
    double Z() const { return _z; }

    Vector3D operator+(Vector3D &b)
    {
        return Vector3D{X()+b.X(), Y() + b.Y(), Z() + b.Z()};
    }

    friend std::ostream &operator<<(std::ostream &stream, const Vector3D &a)
    {
        stream << "[" << std::setw(8) << a._x << ", " << a._y << ", " << a._z << "]";

        return stream;
    }
};

class Vector3DSpherical
{
private:
    double _r, _theta, _phi;

public:
    Vector3DSpherical(double r, double theta, double phi) : _r{r}, _theta{theta}, _phi{phi} {}

    double &R() { return _r; }
    double &Theta() { return _theta; }
    double &Phi() { return _phi; }

    double R() const { return _r; }
    double Theta() const { return _theta; }
    double Phi() const { return _phi; }

    Vector3DSpherical operator+(Vector3DSpherical &b)
    {
        return Vector3DSpherical{R()+b.R(), Theta() + b.Theta(), Phi() + b.Phi()};
    }

    friend std::ostream &operator<<(std::ostream &stream, const Vector3DSpherical &a)
    {
        stream << "[" << std::setw(8) << a._r << ", " << a._theta << ", " << a._phi << "]";

        return stream;
    }
};

class CoordTransf
{
public:
    static Vector3D SphericalToCartesian(const Vector3DSpherical &vec)
    {
        Vector3D outCart;

        outCart.X() = vec.R() * sin(vec.Theta()) * cos(vec.Phi());
        outCart.Y() = vec.R() * sin(vec.Theta()) * sin(vec.Phi());
        outCart.Z() = vec.R() * cos(vec.Theta());

        return outCart;
    }

    static Vector3DSpherical CartesianToSpherical(const Vector3D &cartCoords)
    {
        double outRadius = sqrt(cartCoords.X() * cartCoords.X() + cartCoords.Y() * cartCoords.Y() + cartCoords.Z() * cartCoords.Z());
        double outTheta = acos(cartCoords.Z() / outRadius);
        double outPhi = atan2(cartCoords.Y(), cartCoords.X());

        return Vector3DSpherical{outRadius, outTheta, outPhi};
    }
};


class Cartesian3DDomain
{
    virtual bool IsInDomain(Vector3D &pos) = 0;
};

class ScalarFieldCartesian
{
public:
    // domain???
    virtual double Value(Vector3D &pos) = 0;
};

class VectorFieldCartesian
{
public:
    // domain???
    virtual Vector3D Value(Vector3D &pos) = 0;
};

class GradientFieldCartesian : public VectorFieldCartesian
{
    public:
    ScalarFieldCartesian &_scalarField;

    public:
    GradientFieldCartesian(ScalarFieldCartesian &scalarField) : _scalarField(scalarField)
    {}

    virtual Vector3D Value(Vector3D &pos)
    {
        double eps = 1e-6;

        Vector3D pos_x_h1{pos.X() - eps, pos.Y(), pos.Z()};
        Vector3D pos_x_h2{pos.X() + eps, pos.Y(), pos.Z()};
        double val_x = (_scalarField.Value(pos_x_h2) - _scalarField.Value(pos_x_h1)) / (2 * eps);

        Vector3D pos_y_h1{pos.X(), pos.Y() - eps, pos.Z()};
        Vector3D pos_y_h2{pos.X(), pos.Y() + eps, pos.Z()};
        double val_y = (_scalarField.Value(pos_y_h2) - _scalarField.Value(pos_y_h1)) / (2 * eps);

        Vector3D pos_z_h1{pos.X(), pos.Y(), pos.Z() - eps};
        Vector3D pos_z_h2{pos.X(), pos.Y(), pos.Z() + eps};
        double val_z = (_scalarField.Value(pos_z_h2) - _scalarField.Value(pos_z_h1)) / (2 * eps);

        return Vector3D{val_x, val_y, val_z};
    }
};

class ScalarFieldSpherical
{
public:
    // domain???
    virtual double Value(Vector3DSpherical &pos) = 0;
    virtual Vector3DSpherical Gradient(Vector3DSpherical &pos)
    {
        double eps = 1e-6;

        Vector3DSpherical pos_r_h1{pos.R() - eps, pos.Phi(), pos.Theta()};
        Vector3DSpherical pos_r_h2{pos.R() + eps, pos.Phi(), pos.Theta()};
        double val_r = (Value(pos_r_h2) - Value(pos_r_h1)) / (2 * eps);

        Vector3DSpherical pos_rho_h1{pos.R(), pos.Phi() - eps, pos.Theta()};
        Vector3DSpherical pos_rho_h2{pos.R(), pos.Phi() + eps, pos.Theta()};
        double val_rho = (Value(pos_rho_h2) - Value(pos_rho_h1)) / (2 * eps);

        Vector3DSpherical pos_theta_h1{pos.R(), pos.Phi(), pos.Theta() - eps};
        Vector3DSpherical pos_theta_h2{pos.R(), pos.Phi(), pos.Theta() + eps};
        double val_theta = (Value(pos_theta_h2) - Value(pos_theta_h1)) / (2 * eps);

        return Vector3DSpherical{val_r, val_rho, val_theta};
    }
};

#endif