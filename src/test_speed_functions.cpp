#include <cmath>

/*
FUNKCIJA
- exp, log, log10, log2, 
- pow, sqrt, cbrt
- sin, cos, tan, asin, acos, atan
- sinh, cosh, tanh, asinh, acosh, atanh
- Error and gamma func - erf, tgamma, lgamma
- Special func - assoc_laguerre, assoc_legendre, beta, comp_ellint_1(2,3), cyl_bessel_I(j,k)
                - hermite, legendre, lagurre, riemann_zeta, sph_bessel, sph_legendre
*/
double (*func[])(double) = { sin, cos };

void Test_Speed_Functions()
{
    double x = 0.0;
    double y = 0.0;
    for(int i=0; i<10000000; i++)
    {
        x = rand() % 1000 * 3.14159 / 500.0;
        y = sin(x);
        y = std::hermite(1,x);
    }

}