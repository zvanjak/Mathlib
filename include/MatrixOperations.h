#if !defined  __MML_MATRIX_OPERATIONS_H
#define __MML_MATRIX_OPERATIONS_H

#include "Matrix.h"
#include "VectorN.h"

namespace MML
{
    class MatrixOp
    {
        public:
            static int LUDecomp( Matrix &a, int *indx, double *d )
            {
                return 0;
            }
            static void	LUBackSubst( Matrix &a, int *indx, VectorN &b )
            {

            }
    };
}

#endif