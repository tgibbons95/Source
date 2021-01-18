#ifndef MATRIX_ADDITION_H
#define MATRIX_ADDITION_H

#include "DataStructure/Matrix.h"

namespace AlgorithmT
{
	template<typename T>
	void SquareMatrixAdd(const DataStructureT::SquareMatrixData<T>& matrixA, const DataStructureT::SquareMatrixData<T>& matrixB, DataStructureT::SquareMatrixData<T>& matrixC);
}

#include "Matrix/MatrixAddition_T.cpp"

#endif