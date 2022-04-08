#include <cmath>

void Test_Speed_Function()
{
    double x = 0.0;
    double y = 0.0;
    for(int i=0; i<1000000; i++)
    {
        x = rand() % 1000 * 3.14159 / 500.0;
        y = sin(x);
    }

}