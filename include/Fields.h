#if !defined  __MML_FIELDS_H
#define __MML_FIELDS_H

#include <cmath>
#include <numbers>
#include <iostream>
#include <iomanip>

#include "CoordSystems3D.h"

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

#endif