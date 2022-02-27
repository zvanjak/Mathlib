#include <iostream>

#include "VectorN.h"
#include "Matrix.h"
#include "MatrixOperations.h"
#include "Integration.h"

int main(int, char**) {
    MML::VectorN a(2);

    a[0] = 1.0;
    a[1] = 1.0;

    MML::VectorN b(2);

    //b = 2 * a;

    std::cout << "Vector = (" << b[0] << ", " << b[1] << ")" << std::endl;

    MML::Matrix m1(2,2), m2(2,2), m3;

    m1[0][0] = 1.0;
    m1[0][1] = -1.0;
    m1[1][0] = 1.5;
    m1[1][1] = 3.0;

    m2.MakeUnitMatrix();

    m3 = m1 + m2;

    m1.Print();
    m2.Print();
    m3.Print();

    int C = MML::LUDecomp(m1, nullptr, nullptr);

/* TODO
    1. Vector osnovne operacije
    2. Matrix formatirani ispis
    3. Matrix - LU rješavanje
    4. Matrix - eigenvalues & vectors
    5. Interpolacija - 
        - model TabulatedFunction
            - TabulatedFunction 2D, 3D, 4D
        - polint
        - rational polint
        - spline

- integracija
- root finding
- diff eq 

    - usporedba integracije diff jedn s poznatim rezultatom, 
*/
    // std::cout << "Matrix = (" << m3[0][0] << ", " << m3[0][1] << ")" << std::endl;

    // Vector eigenValues(2);
    // Vector *eigenVectors;

    // CalcEigenvectors(m1, eigenValues, &eigenVectors);

    // std::cout << "Eigenvalues = (" << eigenValues[0] << ", " << eigenValues[1] << ")" << std::endl;

}