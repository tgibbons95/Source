#include "Matrix/MatrixSubtraction.h"
#include <cassert>

namespace AlgorithmT
{
    template<typename T>
    void SquareMatrixSub(const DataStructureT::SquareMatrixData<T>& matrixA, const DataStructureT::SquareMatrixData<T>& matrixB, DataStructureT::SquareMatrixData<T>& matrixC)
    {
        assert(matrixA.n == matrixB.n);
        assert(matrixA.n && !(matrixA.n & (matrixA.n - 1)));

        matrixC.n = matrixA.n;
        for (int i = 0; i < matrixC.n; i++)
        {
            for (int j = 0; j < matrixC.n; j++)
            {
                matrixC[i + j * matrixC.rowOffset] = (matrixA[i + j * matrixA.rowOffset] - matrixB[i + j * matrixB.rowOffset]);
            }
        }
    }
}