#if !defined  __MML_FIELDS_H
#define __MML_FIELDS_H

#include <cmath>
#include <numbers>
#include <iostream>
#include <iomanip>

#include "CoordSystems3D.h"
#include "VectorStatic.h"

template<int N>
class ScalarField
{
    virtual double Value(Vector<N> &pos) = 0;
// treba dodati metrički tenzor da bude generičko?
};


#endif