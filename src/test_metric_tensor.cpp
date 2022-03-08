#include "MetricTensor.h"
#include <iostream>

void Test_Metric_Tensor()
{
    std::cout << "TESTING METRIC TENSOR:\n";

    CoordTransfSphericalToCartesian     transf;
    MetricTensorFromCoordTransf<3>     mt(transf);

    Vector<3> point { 1.0, 1.0, 1.0 };

    for( int i=0; i<3; i++ )
        for( int j=0; j<3; j++ )
        {
            double a = mt.Component(i, j, point);
            std::cout << "g[" << i << "," << j << "] = " << a << std::endl;
        }

    auto metric = mt.MetricAtPoint(point);

    metric.Print();
}