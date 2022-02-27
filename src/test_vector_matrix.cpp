#include <iostream>

#include "VectorN.h"
#include "Matrix.h"
#include "MatrixOperations.h"
#include "Integration.h"

void Test_Vector_Matrix() 
{
    MML::VectorN a(2);

    a[0] = 1.0;
    a[1] = 1.0;

    MML::VectorN b{1.0/3.0, 2.0, 3.0};

    std::cout << b;

    //MML::VectorN c = 2 * a;

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

    int C = MML::MatrixOp::LUDecomp(m1, nullptr, nullptr);

    // std::cout << "Matrix = (" << m3[0][0] << ", " << m3[0][1] << ")" << std::endl;

    // Vector eigenValues(2);
    // Vector *eigenVectors;

    // CalcEigenvectors(m1, eigenValues, &eigenVectors);

    // std::cout << "Eigenvalues = (" << eigenValues[0] << ", " << eigenValues[1] << ")" << std::endl;

}