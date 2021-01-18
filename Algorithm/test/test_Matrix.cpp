// Algorithms
#include "Matrix/MatrixMultiplication.h"

// Data Structure
#include "DataStructure/Matrix.h"

// Test
#include "gtest/gtest.h"
#include "test_VerifyMatrixMultiplication.h"

// Standard
#include <functional>

TEST(MatrixMultiplyTest, TestCase1)
{
	const int n = 4;
	int testMatrixA[n][n] = { {1,2,3,4},{4,3,2,1},{1,2,3,4},{4,3,2,1} };
	int testMatrixB[n][n] = { {1,2,3,4},{4,3,2,1},{1,2,3,4},{4,3,2,1} };
	int testMatrixProduct[n][n] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
	int expectedMatrixProduct[n][n] = { {28,26,24,22},{22,24,26,28},{28,26,24,22},{22,24,26,28} };

	auto algorithm = [](DataStructureT::MatrixData<int> a, DataStructureT::MatrixData<int> b, DataStructureT::MatrixData<int> c) { AlgorithmT::MatrixMultiply(a, b, c); };
	VerifyMatrixMultiply<int>(testMatrixA[0], n, n, testMatrixB[0], n, n, testMatrixProduct[0], expectedMatrixProduct[0], algorithm);
}

TEST(MatrixMultiplyTest, TestCase2)
{
	const int n = 4;
	int testMatrixA[n][n] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	int testMatrixB[n][n] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	int testMatrixProduct[n][n] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
	int expectedMatrixProduct[n][n] = { {90,100,110,120},{202,228,254,280},{314,356,398,440},{426,484,542,600} };

	auto algorithm = [](DataStructureT::MatrixData<int> a, DataStructureT::MatrixData<int> b, DataStructureT::MatrixData<int> c) { AlgorithmT::MatrixMultiply(a, b, c); };
	VerifyMatrixMultiply<int>(testMatrixA[0], n, n, testMatrixB[0], n, n, testMatrixProduct[0], expectedMatrixProduct[0], algorithm);
}

TEST(MatrixMultiplyTest, NonSquareTestCase)
{
	int testMatrixA[2][3] = { {1,2,3},{4,5,6} };
	int testMatrixB[3][2] = { {7,8},{9,10},{11,12} };
	int testMatrixProduct[2][2] = { {0,0},{0,0} };
	int expectedMatrixProduct[2][2] = { {58,64},{139,154} };

	auto algorithm = [](DataStructureT::MatrixData<int> a, DataStructureT::MatrixData<int> b, DataStructureT::MatrixData<int> c) { AlgorithmT::MatrixMultiply(a, b, c); };
	VerifyMatrixMultiply<int>(testMatrixA[0], 2, 3, testMatrixB[0], 3, 2, testMatrixProduct[0], expectedMatrixProduct[0], algorithm);
}

TEST(SquareMatrixMultiplyTest, TestCase1) 
{ 
	const int n = 4;
	int testMatrixA[n][n] = { {1,2,3,4},{4,3,2,1},{1,2,3,4},{4,3,2,1} };
	int testMatrixB[n][n] = { {1,2,3,4},{4,3,2,1},{1,2,3,4},{4,3,2,1} };
	int testMatrixProduct[n][n] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
	int expectedMatrixProduct[n][n] = { {28,26,24,22},{22,24,26,28},{28,26,24,22},{22,24,26,28} };

	auto algorithm = [](DataStructureT::SquareMatrixData<int> a, DataStructureT::SquareMatrixData<int> b, DataStructureT::SquareMatrixData<int> c) { AlgorithmT::SquareMatrixMultiply(a, b, c); };
	VerifySquareMatrixMultiply<int>(n, testMatrixA[0], testMatrixB[0], testMatrixProduct[0], expectedMatrixProduct[0], algorithm);
}

TEST(SquareMatrixMultiplyTest, TestCase2)
{
	const int n = 4;
	int testMatrixA[n][n] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	int testMatrixB[n][n] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	int testMatrixProduct[n][n] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
	int expectedMatrixProduct[n][n] = { {90,100,110,120},{202,228,254,280},{314,356,398,440},{426,484,542,600} };

	auto algorithm = [](DataStructureT::SquareMatrixData<int> a, DataStructureT::SquareMatrixData<int> b, DataStructureT::SquareMatrixData<int> c) { AlgorithmT::SquareMatrixMultiply(a, b, c); };
	VerifySquareMatrixMultiply<int>(n, testMatrixA[0], testMatrixB[0], testMatrixProduct[0], expectedMatrixProduct[0], algorithm);
}

TEST(SquareMatrixMultiplyRecursiveTest, TestCase1)
{
	const int n = 4;
	int testMatrixA[n][n] = { {1,2,3,4},{4,3,2,1},{1,2,3,4},{4,3,2,1} };
	int testMatrixB[n][n] = { {1,2,3,4},{4,3,2,1},{1,2,3,4},{4,3,2,1} };
	int testMatrixProduct[n][n] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
	int expectedMatrixProduct[n][n] = { {28,26,24,22},{22,24,26,28},{28,26,24,22},{22,24,26,28} };

	auto algorithm = [](DataStructureT::SquareMatrixData<int> a, DataStructureT::SquareMatrixData<int> b, DataStructureT::SquareMatrixData<int> c) { AlgorithmT::SquareMatrixMultiplyRecursive(a, b, c); };
	VerifySquareMatrixMultiply<int>(n, testMatrixA[0], testMatrixB[0], testMatrixProduct[0], expectedMatrixProduct[0], algorithm);
}

TEST(SquareMatrixMultiplyRecursiveTest, TestCase2)
{
	const int n = 4;
	int testMatrixA[n][n] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	int testMatrixB[n][n] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	int testMatrixProduct[n][n] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
	int expectedMatrixProduct[n][n] = { {90,100,110,120},{202,228,254,280},{314,356,398,440},{426,484,542,600} };

	auto algorithm = [](DataStructureT::SquareMatrixData<int> a, DataStructureT::SquareMatrixData<int> b, DataStructureT::SquareMatrixData<int> c) { AlgorithmT::SquareMatrixMultiplyRecursive(a, b, c); };
	VerifySquareMatrixMultiply<int>(n, testMatrixA[0], testMatrixB[0], testMatrixProduct[0], expectedMatrixProduct[0], algorithm);
}

TEST(StrassenSquareMatrixMultiplyTest, TestCase1)
{
	const int n = 4;
	int testMatrixA[n][n] = { {1,2,3,4},{4,3,2,1},{1,2,3,4},{4,3,2,1} };
	int testMatrixB[n][n] = { {1,2,3,4},{4,3,2,1},{1,2,3,4},{4,3,2,1} };
	int testMatrixProduct[n][n] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
	int expectedMatrixProduct[n][n] = { {28,26,24,22},{22,24,26,28},{28,26,24,22},{22,24,26,28} };

	auto algorithm = [](DataStructureT::SquareMatrixData<int> a, DataStructureT::SquareMatrixData<int> b, DataStructureT::SquareMatrixData<int> c) { AlgorithmT::StrassenSquareMatrixMultiply(a, b, c); };
	VerifySquareMatrixMultiply<int>(n, testMatrixA[0], testMatrixB[0], testMatrixProduct[0], expectedMatrixProduct[0], algorithm);
}

TEST(StrassenSquareMatrixMultiplyTest, TestCase2)
{
	const int n = 4;
	int testMatrixA[n][n] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	int testMatrixB[n][n] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	int testMatrixProduct[n][n] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
	int expectedMatrixProduct[n][n] = { {90,100,110,120},{202,228,254,280},{314,356,398,440},{426,484,542,600} };

	auto algorithm = [](DataStructureT::SquareMatrixData<int> a, DataStructureT::SquareMatrixData<int> b, DataStructureT::SquareMatrixData<int> c) { AlgorithmT::StrassenSquareMatrixMultiply(a, b, c); };
	VerifySquareMatrixMultiply<int>(n, testMatrixA[0], testMatrixB[0], testMatrixProduct[0], expectedMatrixProduct[0], algorithm);
}