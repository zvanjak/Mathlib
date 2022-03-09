#if !defined  __MML_FIELDS_H
#define __MML_FIELDS_H

#include <cmath>
#include <numbers>
#include <iostream>
#include <iomanip>

#include "CoordSystems3D.h"
#include "VectorStatic.h"
#include "Function.h"
#include "MetricTensor.h"

template<int N>
class ScalarField : VectorFunction<N>
{
    public:
    virtual double Value(Vector<N> &pos) const = 0;
    virtual const MetricTensor<N>& Metric() const = 0;

    virtual double operator()(Vector<N> x) const
    {
        return Value(x);
    }

    Vector<N> Gradient(Vector<N> &pos) const
    {
        Vector<N> ret;

        Vector<N> derivsAtPoint = Derivation::DerivePartialByAll(*this, pos);

        //Matrix<N,N> metricAtPoint = 
        Metric().MetricAtPoint(pos);

        return ret;
    }
};

template<int N>
class ScalarFieldWithFunction: public ScalarField<N> 
{
    VectorFunction<N> &_func;

    public:
    virtual double Value(Vector<N> &pos) = 0;

    ScalarFieldWithFunction(VectorFunction<N> &inFunc) : _func(inFunc)
    {}
};

template<int N>
class VectorField
{
public:
    // domain???
    virtual Vector<N> Value(Vector<N> &pos) = 0;
};

template<int N>
class GradientField : public VectorField<N>
{
    ScalarField<N> _scalarField;
public:
    GradientField(ScalarField<N> &inField) : _scalarField(inField)
    {}

    Vector<N> Value(Vector<N> &pos) 
    {
        return Vector<N>{};
    }
};

#endif