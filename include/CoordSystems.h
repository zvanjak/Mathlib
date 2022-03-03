
class Vector3D
{
    public:
    double _x, _y, _z;
};

class Vector3DSpherical
{
    public:
    double _r, _rho, _theta;
};

static class CoordTransf
{

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