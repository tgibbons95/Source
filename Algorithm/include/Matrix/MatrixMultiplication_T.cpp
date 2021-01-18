#include "Matrix/MatrixMultiplication.h"

#include "Matrix/MatrixSubtraction.h"
#include "Matrix/MatrixAddition.h"

#include <cassert>

namespace AlgorithmT
{
    // Introduction to Algorithms 3e: 4.2 Square Matrix Multiply pg 75 
    template<typename T>
    void SquareMatrixMultiply(const DataStructureT::SquareMatrixData<T>& matrixA, const DataStructureT::SquareMatrixData<T>& matrixB, DataStructureT::SquareMatrixData<T>& matrixC)
    {
        assert(matrixA.n == matrixB.n);
        assert(matrixA.n && !(matrixA.n & (matrixA.n - 1)));
        assert(matrixC.rowOffset >= matrixA.n);

        matrixC.n = matrixA.n;
        for (int i = 0; i < matrixC.n; i++)
        {
            for (int j = 0; j < matrixC.n; j++)
            {
                matrixC[j + i * matrixC.rowOffset] = 0;
                for (int k = 0; k < matrixC.n; k++)
                {
                    matrixC[j + i * matrixC.rowOffset] += (matrixA[k + i * matrixA.rowOffset] * matrixB[j + k * matrixB.rowOffset]);
                }
            }
        }
    }

    template<typename T>
    void SquareMatrixMultiplyRecursive(const DataStructureT::SquareMatrixData<T>& matrixA, const DataStructureT::SquareMatrixData<T>& matrixB, DataStructureT::SquareMatrixData<T>& matrixC)
    {
        assert(matrixA.n == matrixB.n);
        assert(matrixA.n && !(matrixA.n & (matrixA.n - 1)));
        assert(matrixC.rowOffset >= matrixA.n);

        matrixC.n = matrixA.n;
        if (matrixC.n == 1)
        {
            matrixC[0] = matrixA[0] * matrixB[0];
        }
        else
        {
            T* tempMatrix = new T[matrixC.n * matrixC.n];

            int subN = matrixC.n >> 1;
            DataStructureT::SquareMatrixData<T> a11(&matrixA.matrix[0], subN, matrixA.rowOffset);
            DataStructureT::SquareMatrixData<T> a12(&matrixA.matrix[subN], subN, matrixA.rowOffset);
            DataStructureT::SquareMatrixData<T> a21(&matrixA.matrix[matrixA.rowOffset * subN], subN, matrixA.rowOffset);
            DataStructureT::SquareMatrixData<T> a22(&matrixA.matrix[matrixA.rowOffset * subN + subN], subN, matrixA.rowOffset);

            DataStructureT::SquareMatrixData<T> b11(&matrixB.matrix[0], subN, matrixB.rowOffset);
            DataStructureT::SquareMatrixData<T> b12(&matrixB.matrix[subN], subN, matrixB.rowOffset);
            DataStructureT::SquareMatrixData<T> b21(&matrixB.matrix[matrixB.rowOffset * subN], subN, matrixB.rowOffset);
            DataStructureT::SquareMatrixData<T> b22(&matrixB.matrix[matrixB.rowOffset * subN + subN], subN, matrixB.rowOffset);
            
            DataStructureT::SquareMatrixData<T> c11(&matrixC.matrix[0], subN, matrixC.rowOffset);
            DataStructureT::SquareMatrixData<T> c12(&matrixC.matrix[subN], subN, matrixC.rowOffset);
            DataStructureT::SquareMatrixData<T> c21(&matrixC.matrix[matrixC.rowOffset * subN], subN, matrixC.rowOffset);
            DataStructureT::SquareMatrixData<T> c22(&matrixC.matrix[matrixC.rowOffset * subN + subN], subN, matrixC.rowOffset);

            DataStructureT::SquareMatrixData<T> t11(&tempMatrix[0], subN, matrixC.n);
            DataStructureT::SquareMatrixData<T> t12(&tempMatrix[subN], subN, matrixC.n);
            DataStructureT::SquareMatrixData<T> t21(&tempMatrix[matrixC.n * subN], subN, matrixC.n);
            DataStructureT::SquareMatrixData<T> t22(&tempMatrix[matrixC.n * subN + subN], subN, matrixC.n);

            SquareMatrixMultiplyRecursive(a11, b11, c11);
            SquareMatrixMultiplyRecursive(a12, b21, t11);
            SquareMatrixAdd(c11, t11, c11);

            SquareMatrixMultiplyRecursive(a11, b12, c12);
            SquareMatrixMultiplyRecursive(a12, b22, t12);
            SquareMatrixAdd(c12, t12, c12);

            SquareMatrixMultiplyRecursive(a21, b11, c21);
            SquareMatrixMultiplyRecursive(a22, b21, t21);
            SquareMatrixAdd(c21, t21, c21);

            SquareMatrixMultiplyRecursive(a21, b12, c22);
            SquareMatrixMultiplyRecursive(a22, b22, t22);
            SquareMatrixAdd(c22, t22, c22);

            delete[] tempMatrix;
        }
    }

    template<typename T>
    void StrassenSquareMatrixMultiply(const DataStructureT::SquareMatrixData<T>& matrixA, const DataStructureT::SquareMatrixData<T>& matrixB, DataStructureT::SquareMatrixData<T>& matrixC, int smallSize)
    {
        assert(matrixA.n == matrixB.n);
        assert(matrixA.n && !(matrixA.n & (matrixA.n - 1)));
        assert(matrixC.rowOffset >= matrixA.n);

        matrixC.n = matrixA.n;
        if (matrixC.n == 1)
        {
            matrixC[0] = matrixA[0] * matrixB[0];

        }
        else if (matrixC.n < smallSize)
        {
            SquareMatrixMultiply(matrixA, matrixB, matrixC);
        }
        else
        {
            int subN = matrixC.n >> 1;
            int matrixSize = subN * subN;
            T* tempMatrix = new T[matrixSize * 21];

            DataStructureT::SquareMatrixData<T> a11(&matrixA.matrix[0], subN, matrixA.rowOffset);
            DataStructureT::SquareMatrixData<T> a12(&matrixA.matrix[subN], subN, matrixA.rowOffset);
            DataStructureT::SquareMatrixData<T> a21(&matrixA.matrix[matrixA.rowOffset * subN], subN, matrixA.rowOffset);
            DataStructureT::SquareMatrixData<T> a22(&matrixA.matrix[matrixA.rowOffset * subN + subN], subN, matrixA.rowOffset);

            DataStructureT::SquareMatrixData<T> b11(&matrixB.matrix[0], subN, matrixB.rowOffset);
            DataStructureT::SquareMatrixData<T> b12(&matrixB.matrix[subN], subN, matrixB.rowOffset);
            DataStructureT::SquareMatrixData<T> b21(&matrixB.matrix[matrixB.rowOffset * subN], subN, matrixB.rowOffset);
            DataStructureT::SquareMatrixData<T> b22(&matrixB.matrix[matrixB.rowOffset * subN + subN], subN, matrixB.rowOffset);

            DataStructureT::SquareMatrixData<T> c11(&matrixC.matrix[0], subN, matrixC.rowOffset);
            DataStructureT::SquareMatrixData<T> c12(&matrixC.matrix[subN], subN, matrixC.rowOffset);
            DataStructureT::SquareMatrixData<T> c21(&matrixC.matrix[matrixC.rowOffset * subN], subN, matrixC.rowOffset);
            DataStructureT::SquareMatrixData<T> c22(&matrixC.matrix[matrixC.rowOffset * subN + subN], subN, matrixC.rowOffset);

            DataStructureT::SquareMatrixData<T> s1(&tempMatrix[0 * matrixSize], subN, subN);
            DataStructureT::SquareMatrixData<T> s2(&tempMatrix[1 * matrixSize], subN, subN);
            DataStructureT::SquareMatrixData<T> s3(&tempMatrix[2 * matrixSize], subN, subN);
            DataStructureT::SquareMatrixData<T> s4(&tempMatrix[3 * matrixSize], subN, subN);
            DataStructureT::SquareMatrixData<T> s5(&tempMatrix[4 * matrixSize], subN, subN);
            DataStructureT::SquareMatrixData<T> s6(&tempMatrix[5 * matrixSize], subN, subN);
            DataStructureT::SquareMatrixData<T> s7(&tempMatrix[6 * matrixSize], subN, subN);
            DataStructureT::SquareMatrixData<T> s8(&tempMatrix[7 * matrixSize], subN, subN);
            DataStructureT::SquareMatrixData<T> s9(&tempMatrix[8 * matrixSize], subN, subN);
            DataStructureT::SquareMatrixData<T> s10(&tempMatrix[9 * matrixSize], subN, subN);
            DataStructureT::SquareMatrixData<T> p1(&tempMatrix[10 * matrixSize], subN, subN);
            DataStructureT::SquareMatrixData<T> p2(&tempMatrix[11 * matrixSize], subN, subN);
            DataStructureT::SquareMatrixData<T> p3(&tempMatrix[12 * matrixSize], subN, subN);
            DataStructureT::SquareMatrixData<T> p4(&tempMatrix[13 * matrixSize], subN, subN);
            DataStructureT::SquareMatrixData<T> p5(&tempMatrix[14 * matrixSize], subN, subN);
            DataStructureT::SquareMatrixData<T> p6(&tempMatrix[15 * matrixSize], subN, subN);
            DataStructureT::SquareMatrixData<T> p7(&tempMatrix[16 * matrixSize], subN, subN);
            DataStructureT::SquareMatrixData<T> s11(&tempMatrix[17 * matrixSize], subN, subN);
            DataStructureT::SquareMatrixData<T> s12(&tempMatrix[18 * matrixSize], subN, subN);
            DataStructureT::SquareMatrixData<T> s13(&tempMatrix[19 * matrixSize], subN, subN);
            DataStructureT::SquareMatrixData<T> s14(&tempMatrix[20 * matrixSize], subN, subN);

            SquareMatrixSub(b12, b22, s1);
            SquareMatrixAdd(a11, a12, s2);
            SquareMatrixAdd(a21, a22, s3);
            SquareMatrixSub(b21, b11, s4);
            SquareMatrixAdd(a11, a22, s5);
            SquareMatrixAdd(b11, b22, s6);
            SquareMatrixSub(a12, a22, s7);
            SquareMatrixAdd(b21, b22, s8);
            SquareMatrixSub(a11, a21, s9);
            SquareMatrixAdd(b11, b12, s10);

            StrassenSquareMatrixMultiply(a11, s1, p1);
            StrassenSquareMatrixMultiply(s2, b22, p2);
            StrassenSquareMatrixMultiply(s3, b11, p3);
            StrassenSquareMatrixMultiply(a22, s4, p4);
            StrassenSquareMatrixMultiply(s5, s6, p5);
            StrassenSquareMatrixMultiply(s7, s8, p6);
            StrassenSquareMatrixMultiply(s9, s10, p7);

            SquareMatrixSub(p4, p2, s11);
            SquareMatrixAdd(p5, p6, s12);
            SquareMatrixSub(p5, p3, s13);
            SquareMatrixSub(p1, p7, s14);

            SquareMatrixAdd(s11, s12, c11);
            SquareMatrixAdd(p1, p2, c12);
            SquareMatrixAdd(p3, p4, c21);
            SquareMatrixAdd(s13, s14, c22);

            delete[] tempMatrix;
        }
    }

    // Introduction to Algorithms 3e: 15.2 Matrix Multiply pg 371 
    template<typename T>
    void MatrixMultiply(const DataStructureT::MatrixData<T>& matrixA, const DataStructureT::MatrixData<T>& matrixB, DataStructureT::MatrixData<T>& matrixC)
    {
        assert(matrixA.cols == matrixB.rows);
        assert(matrixC.rowOffset >= matrixB.cols);

        matrixC.rows = matrixA.rows;
        matrixC.cols = matrixB.cols;

        for (int i = 0; i < matrixC.rows; i++)
        {
            for (int j = 0; j < matrixC.cols; j++)
            {
                matrixC[j + i * matrixC.rowOffset] = 0;
                for (int k = 0; k < matrixA.cols; k++)
                {
                    matrixC[j + i * matrixC.rowOffset] += (matrixA[k + i * matrixA.rowOffset] * matrixB[j + k * matrixB.rowOffset]);
                }
            }
        }
    }
}