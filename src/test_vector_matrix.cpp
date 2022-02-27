#include <iostream>

#include "VectorN.h"
#include "Matrix.h"
#include "MatrixOperations.h"
#include "Integration.h"

void Test_Vector_Matrix() 
{
    MML::VectorN vec1{1.0/3.0, 2.0, 3.0};

    std::cout << vec1;

    //MML::VectorN c = 2 * a;

    MML::Matrix m1(2,2), m2(2,2), m3;

    m1[0][0] = 1.0;
    m1[0][1] = -1.0;
    m1[1][0] = 1.5;
    m1[1][1] = 3.0;

    m2.MakeUnitMatrix();

    m3 = m1 + m2;

    // m1.Print();
    // m2.Print();
    // m3.Print();

    std::cout << "SOLVING VIA GAUSS-JORDAN ELIMINATION:\n";

    MML::Matrix     mat1(3, 3, { 1.0, 2.0, -1.0, -1.0, 5.0, 6.0, 3.0, 1.0, 1.0 });
    MML::Matrix     rhs1(3, 1, {1.0, 2.0, 1.0});

    MML::Matrix     mat1copy(mat1);

    MML::MatrixOp::gaussj(mat1copy, rhs1);

    std::cout << "Initial matrix:\n";
    mat1.Print();

    std::cout << "Solution:\n";
    rhs1.Print();

    // inicijaliziramo rhs1Vec sa rješenjem
    MML::VectorN    rhs1Vec({rhs1[0][0], rhs1[1][0], rhs1[2][0]});
    MML::VectorN    res = mat1 * rhs1Vec;

    std::cout << "Multiplying solution with matrix: " << res << std::endl;

    std::cout << "\nSOLVING VIA LU DECOMPOSITION:\n";
    
    MML::Matrix mat2copy(mat1);
    std::cout << "Matrix: " << std::endl;
    mat2copy.Print();

    double d = 0.0;
    std::vector<int> indx(3);
    MML::MatrixOp::ludcmp(mat2copy, indx, d);

    std::cout << "After LU: " << std::endl;
    mat2copy.Print();

    MML::VectorN vecC({1.0, 2.0, 1.0});
    MML::MatrixOp::lubksb(mat2copy, indx, vecC);

    std::cout << "Resulting vector: " << vecC << std::endl;

    std::cout << "\nINVERTING MATRIX:\n";
    MML::Matrix mat3copy(mat1), matInverted(mat1.RowNum(), mat1.ColNum());

    MML::MatrixOp::InvertMatrix(mat3copy, matInverted);

    std::cout << "Inverted matrix:\n";
    matInverted.Print();

    MML::Matrix mul = mat1 * matInverted;



    // std::cout << "Matrix = (" << m3[0][0] << ", " << m3[0][1] << ")" << std::endl;

    // Vector eigenValues(2);
    // Vector *eigenVectors;

    // CalcEigenvectors(m1, eigenValues, &eigenVectors);

    // std::cout << "Eigenvalues = (" << eigenValues[0] << ", " << eigenValues[1] << ")" << std::endl;

}