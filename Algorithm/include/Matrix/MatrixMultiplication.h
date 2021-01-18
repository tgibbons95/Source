#ifndef MATRIX_MULTIPLICATION_H
#define MATRIX_MULTIPLICATION_H

#include "DataStructure/Matrix.h"

namespace AlgorithmT
{
	template<typename T>
	void SquareMatrixMultiply(const DataStructureT::SquareMatrixData<T>& matrixA, const DataStructureT::SquareMatrixData<T>& matrixB, DataStructureT::SquareMatrixData<T>& matrixC);

	template<typename T>
	void SquareMatrixMultiplyRecursive(const DataStructureT::SquareMatrixData<T>& matrixA, const DataStructureT::SquareMatrixData<T>& matrixB, DataStructureT::SquareMatrixData<T>& matrixC);

	template<typename T>
	void StrassenSquareMatrixMultiply(const DataStructureT::SquareMatrixData<T>& matrixA, const DataStructureT::SquareMatrixData<T>& matrixB, DataStructureT::SquareMatrixData<T>& matrixC, int smallSize = 1);

	template<typename T>
	void MatrixMultiply(const DataStructureT::MatrixData<T>& matrixA, const DataStructureT::MatrixData<T>& matrixB, DataStructureT::MatrixData<T>& matrixC);
}

#include "Matrix/MatrixMultiplication_T.cpp"

#endif