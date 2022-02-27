#include "Integration.h"
#include <iostream>

/* TODO
    - definirati skup testnih funkcija
    - 
*/
double TestFunc(double x)
{
    return sin(x);
}

double TestFunc2(double x)
{
    return x;
}

void Test_Integration()
{
    double res = qtrap<double>(TestFunc2, 0, 1.0);

    std::cout << "Integration result: " << res << std::endl;
}