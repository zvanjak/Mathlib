#include <cmath>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

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

struct FuncToEval
{
    double (*_func)(double);
    std::string _name;
    double _low;
    double _up;
};

// static const int num_func = 4;
// double (*func[])(double) = {sin, cos, tan, eval_hermite_1};
// std::string func_name[] = { "sin", "cos", "tan", "Hermite 1"};

std::vector<FuncToEval> vec_func = {
    { exp, "exp", -10, 10 },
    { log, "log", 0.0, 1e6 },
    { log10, "log10", 0.0, 1e6 },
    { sin, "sin", -3.14159, 3.14159 },
    { cos, "cos", -3.14159, 3.14159 },
    { tan, "tan", -3.14159, 3.14159 },
    { eval_hermite_1, "Hermite 1", -3.14159, 3.14159 }
};

static const int num_evals = 1000000;

void Test_Speed_Functions()
{
    std::cout << "TESTING SPEED OF FUNCTIONS\n";

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    double x = 0.0;
    double y = 0.0;

    for(auto f : vec_func)
    {
        auto t1 = high_resolution_clock::now();
        for (int i = 0; i < num_evals; i++)
        {
            x = rand() % 1000 * (f._up - f._low) / 1000.0 + f._low;
            y = f._func(x);
        }

        auto t2 = high_resolution_clock::now();

        /* Getting number of milliseconds as a double. */
        duration<double, std::milli> ms_double = t2 - t1;
        std::cout << f._name << " - " << ms_double.count() << " ms\n";

    }
}
