#include <iostream>

#include "VectorN.h"
#include "Matrix.h"
#include "MatrixOperations.h"
#include "Integration.h"

void Test_Vector_Matrix();
void Test_Integration();
void Test_Polynom();

int main(int, char**) 
{
    Test_Vector_Matrix();

    Test_Integration();

    Test_Polynom();
    

/* TODO
    1. Vector osnovne operacije
    2. Matrix formatirani ispis
        - da se može inicijalizirati s vector<vector<double>>
        - inicijalizacija s initializer list?
    3. Matrix - LU rješavanje
    4. Matrix - eigenvalues & vectors
    5. Interpolacija - 
        - model TabulatedFunction
            - TabulatedFunction 2D, 3D, 4D
        - polint
        - rational polint
        - spline
    6. CoordinateSystems
        - Point3D, Point3DSpherical, Cylindrical, 
        - constexpr za izračune izraza transformacije koordinata?
        - Vector ... sve varijante
        - METRIKA!!!

- integracija
    - multidimensional integratio n over regular domains
    - usporediti integraciju u Kartezijevim i sfernim koord nekog volumnog integrala preko kugle!
- root finding
- diff eq 

- i onda, rješenje diff Maxwella npr je neka vektorska funkcija
    - i onda idem izračunati Gaussa i Stokesa numerički

    - usporedba integracije diff jedn s poznatim rezultatom, 
*/
    // std::cout << "Matrix = (" << m3[0][0] << ", " << m3[0][1] << ")" << std::endl;

    // Vector eigenValues(2);
    // Vector *eigenVectors;

    // CalcEigenvectors(m1, eigenValues, &eigenVectors);

    // std::cout << "Eigenvalues = (" << eigenValues[0] << ", " << eigenValues[1] << ")" << std::endl;

}