#include <iostream>

#include "vector.h"

int main(int, char**) {
    Vector a(2);

    a[0] = 1.0;
    a[1] = 1.0;

    Vector b(2);

    b = 2 * a;

    std::cout << "Vector = (" << b[0] << ", " << b[1] << ")" << std::endl;
}