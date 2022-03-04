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

class Cartesian3DDomain
{
    virtual bool IsInDomain(Vector3D &pos) = 0;
};

class ScalarFieldCartesian
{
public:
    // domain???
    virtual double Value(Vector3D &pos) = 0;
    virtual Vector3D Gradient(Vector3D &pos)
    {
        double eps = 1e-6;

        Vector3D pos_x_h1{pos.X() - eps, pos.Y(), pos.Z()};
        Vector3D pos_x_h2{pos.X() + eps, pos.Y(), pos.Z()};
        double val_x = (Value(pos_x_h2) - Value(pos_x_h1)) / (2 * eps);

        Vector3D pos_y_h1{pos.X(), pos.Y() - eps, pos.Z()};
        Vector3D pos_y_h2{pos.X(), pos.Y() + eps, pos.Z()};
        double val_y = (Value(pos_y_h2) - Value(pos_y_h1)) / (2 * eps);

        Vector3D pos_z_h1{pos.X(), pos.Y(), pos.Z() - eps};
        Vector3D pos_z_h2{pos.X(), pos.Y(), pos.Z() + eps};
        double val_z = (Value(pos_z_h2) - Value(pos_z_h1)) / (2 * eps);

        return Vector3D{val_x, val_y, val_z};
    }
};

class GradientFieldCartesian
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
}

class ScalarFieldSpherical
{
public:
    // domain???
    virtual double Value(Vector3DSpherical &pos) = 0;
    virtual Vector3DSpherical Gradient(Vector3DSpherical &pos)
    {
        double eps = 1e-6;

        Vector3DSpherical pos_r_h1{pos.R() - eps, pos.Rho(), pos.Theta()};
        Vector3DSpherical pos_r_h2{pos.R() + eps, pos.Rho(), pos.Theta()};
        double val_r = (Value(pos_r_h2) - Value(pos_r_h1)) / (2 * eps);

        Vector3DSpherical pos_rho_h1{pos.R(), pos.Rho() - eps, pos.Theta()};
        Vector3DSpherical pos_rho_h2{pos.R(), pos.Rho() + eps, pos.Theta()};
        double val_rho = (Value(pos_rho_h2) - Value(pos_rho_h1)) / (2 * eps);

        Vector3DSpherical pos_theta_h1{pos.R(), pos.Rho(), pos.Theta() - eps};
        Vector3DSpherical pos_theta_h2{pos.R(), pos.Rho(), pos.Theta() + eps};
        double val_theta = (Value(pos_theta_h2) - Value(pos_theta_h1)) / (2 * eps);

        return Vector3DSpherical{val_r, val_rho, val_theta};
    }
};