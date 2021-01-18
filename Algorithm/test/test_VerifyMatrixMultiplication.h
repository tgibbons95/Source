#ifndef TEST_VERIFY_MATRIX_MULTIPLICATION_H
#define TEST_VERIFY_MATRIX_MULTIPLICATION_H

#include "gtest/gtest.h"
#include <functional>

template<typename T>
void VerifySquareMatrixMultiply(
	const int n,
	T* testMatrixA,
	T* testMatrixB,
	T* testMatrixProduct,
	T* expectedMatrixProduct,
	std::function<void(DataStructureT::SquareMatrixData<T>, DataStructureT::SquareMatrixData<T>, DataStructureT::SquareMatrixData<T>)> matrixMultiplyAlgorithm)
{
	DataStructureT::SquareMatrixData<T> matrixA(testMatrixA, n, n);
	DataStructureT::SquareMatrixData<T> matrixB(testMatrixB, n, n);
	DataStructureT::SquareMatrixData<T> matrixProduct(testMatrixProduct, n, n);

	matrixMultiplyAlgorithm(matrixA, matrixB, matrixProduct);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			EXPECT_EQ(expectedMatrixProduct[i + j * n], matrixProduct[i + j * n]);
		}
	}
}

template<typename T>
void VerifyMatrixMultiply(
	T* testMatrixA, int rowsA, int colsA,
	T* testMatrixB, int rowsB, int colsB,
	T* testMatrixProduct,
	T* expectedMatrixProduct,
	std::function<void(DataStructureT::MatrixData<T>, DataStructureT::MatrixData<T>, DataStructureT::MatrixData<T>)> matrixMultiplyAlgorithm)
{
	DataStructureT::MatrixData<T> matrixA(testMatrixA, rowsA, colsA, colsA);
	DataStructureT::MatrixData<T> matrixB(testMatrixB, rowsB, colsB, colsB);
	DataStructureT::MatrixData<T> matrixProduct(testMatrixProduct, rowsA, colsB, colsB);

	matrixMultiplyAlgorithm(matrixA, matrixB, matrixProduct);

	for (int i = 0; i < rowsA; i++)
	{
		for (int j = 0; j < colsB; j++)
		{
			EXPECT_EQ(expectedMatrixProduct[j + i * colsB], matrixProduct[j + i * colsB]);
		}
	}
}

#endif