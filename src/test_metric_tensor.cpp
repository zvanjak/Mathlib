#include "MetricTensor.h"
#include <iostream>

void Test_Metric_Tensor()
{
    std::cout << "TESTING METRIC TENSOR:\n";

    CoordTransfSphericalToCartesian     transf;
    MetricTensorFromCoordTransf<3>     mt(transf);

    Vector<3> point { 1.0, 1.0, 1.0 };

    double a = transf.coordTransfFunc(0)(point);
    a = mt.Component(0, 0, point);

    std::cout << "g[0,0] = " << a << std::endl;
}