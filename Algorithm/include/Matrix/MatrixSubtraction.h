#ifndef MATRIX_SUBTRACTION_H
#define MATRIX_SUBTRACTION_H

#include "DataStructure/Matrix.h"

namespace AlgorithmT
{
	template<typename T>
	void SquareMatrixSub(const DataStructureT::SquareMatrixData<T>& matrixA, const DataStructureT::SquareMatrixData<T>& matrixB, DataStructureT::SquareMatrixData<T>& matrixC);
}

#include "Matrix/MatrixSubtraction_T.cpp"

#endif