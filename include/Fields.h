#if !defined  __MML_FIELDS_H
#define __MML_FIELDS_H

#include <cmath>
#include <numbers>
#include <iostream>
#include <iomanip>

#include "CoordSystems3D.h"
#include "VectorStatic.h"
#include "Function.h"

template<int N>
class ScalarField
{
    public:
    virtual double Value(Vector<N> &pos) = 0;
// treba dodati metrički tenzor da bude generičko?
};

template<int N>
class ScalarFieldWithFunction: public ScalarField<N> 
{
    VectorFunction<N> &_func;

    public:
    virtual double Value(Vector<N> &pos) = 0;

    ScalarFieldWithFunction(VectorFunction<N> &inFunc) : _func(inFunc)
    {}

// treba dodati metrički tenzor da bude generičko?
};


#endif