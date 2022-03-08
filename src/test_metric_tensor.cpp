#include "MetricTensor.h"
#include <iostream>

void Test_Metric_Tensor()
{
    CoordTransfSphericalToCartesian     transf;
    MetricTensorFromCoordTransf<3>     mt(transf);

    Vector<3> point { 1.0, 1.0, 1.0 };

    double a = mt.Component(0, 0, point);

    std::cout << "g[0,0] = " << a << std::endl;
}