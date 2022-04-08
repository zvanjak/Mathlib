#include <cmath>
#include <chrono>
#include <iostream>

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
inline double eval_hermite_1(double x ) { return std::hermite(1, x); }

static const int num_func = 4;
double (*func[])(double) = {sin, cos, tan, eval_hermite_1};

void Test_Speed_Functions()
{
    std::cout << "TESTING SPEED OF FUNCTIONS\n";

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    for (int f = 0; f < num_func; f++)
    {
        auto t1 = high_resolution_clock::now();
        double x = 0.0;
        double y = 0.0;
        for (int i = 0; i < 10000000; i++)
        {
            x = rand() % 1000 * 3.14159 / 500.0;
            y = func[f](x);
            //y = std::hermite(1, x);
        }

        auto t2 = high_resolution_clock::now();

        /* Getting number of milliseconds as an integer. */
        auto ms_int = duration_cast<milliseconds>(t2 - t1);

        /* Getting number of milliseconds as a double. */
        duration<double, std::milli> ms_double = t2 - t1;

        std::cout << ms_int.count() << "ms\n";
        std::cout << ms_double.count() << "ms\n";
    }
}
