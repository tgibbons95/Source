#ifndef MATRIX_H
#define MATRIX_H

namespace DataStructureT
{
	template<typename T>
	struct SquareMatrixData
	{
		T* matrix;
		int n;
		int rowOffset;
		T operator [] (int i) const { return matrix[i]; }
		T& operator [] (int i) { return matrix[i]; }
		SquareMatrixData(T* matrix, int n, int rowOffset)
			: matrix(matrix)
			, n(n)
			, rowOffset(rowOffset)
		{

		}
	};

	template<typename T>
	struct MatrixData
	{
		T* matrix;
		int rows;
		int cols;
		int rowOffset;
		T operator [] (int i) const { return matrix[i]; }
		T& operator [] (int i) { return matrix[i]; }
		MatrixData(T* matrix, int rows, int cols, int rowOffset)
			: matrix(matrix)
			, rows(rows)
			, cols(cols)
			, rowOffset(rowOffset)
		{

		}
	};
}

#endif