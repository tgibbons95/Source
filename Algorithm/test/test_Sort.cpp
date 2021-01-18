#include "gtest/gtest.h"
#include "Sort/InsertionSort.h"
#include "Sort/MergeSort.h"
#include "Sort/QuickSort.h"
#include "Sort/HeapSort.h"
#include "test_VerifySort.h"

TEST(QuickSortTest, Int)
{
	const int TEST_ARRAY_LENGTH = 8;
	int testArray[TEST_ARRAY_LENGTH] = { 2,5,7,3,1,8,4,6 };
	auto algorithm = [](auto array, int length) { AlgorithmT::QuickSort(array, 0, length - 1); };
	VerifySort<int>(testArray, TEST_ARRAY_LENGTH, algorithm);
}

TEST(QuickSortTest, Double)
{
	const int TEST_ARRAY_LENGTH = 8;
	double testArray[TEST_ARRAY_LENGTH] = { 3.0,1.0,2.0,5.0,7.0,8.0,4.0,6.0 };
	auto algorithm = [](auto array, int length) { AlgorithmT::QuickSort(array, 0, length - 1); };
	VerifySort<double>(testArray, TEST_ARRAY_LENGTH, algorithm);
}

TEST(QuickSortTest, Float)
{
	const int TEST_ARRAY_LENGTH = 8;
	float testArray[TEST_ARRAY_LENGTH] = { 2.0f,3.0f,1.0f,4.0f,6.0f,8.0f,5.0f,7.0f };
	auto algorithm = [](auto array, int length) { AlgorithmT::QuickSort(array, 0, length - 1); };
	VerifySort<float>(testArray, TEST_ARRAY_LENGTH, algorithm);
}

TEST(RandomizedQuickSortTest, Int)
{
	const int TEST_ARRAY_LENGTH = 8;
	int testArray[TEST_ARRAY_LENGTH] = { 2,5,7,3,1,8,4,6 };
	auto algorithm = [](auto array, int length) { AlgorithmT::RandomizedQuickSort(array, 0, length - 1); };
	VerifySort<int>(testArray, TEST_ARRAY_LENGTH, algorithm);
}

TEST(RandomizedQuickSortTest, Double)
{
	const int TEST_ARRAY_LENGTH = 8;
	double testArray[TEST_ARRAY_LENGTH] = { 3.0,1.0,2.0,5.0,7.0,8.0,4.0,6.0 };
	auto algorithm = [](auto array, int length) { AlgorithmT::RandomizedQuickSort(array, 0, length - 1); };
	VerifySort<double>(testArray, TEST_ARRAY_LENGTH, algorithm);
}

TEST(RandomizedQuickSortTest, Float)
{
	const int TEST_ARRAY_LENGTH = 8;
	float testArray[TEST_ARRAY_LENGTH] = { 2.0f,3.0f,1.0f,4.0f,6.0f,8.0f,5.0f,7.0f };
	auto algorithm = [](auto array, int length) { AlgorithmT::RandomizedQuickSort(array, 0, length - 1); };
	VerifySort<float>(testArray, TEST_ARRAY_LENGTH, algorithm);
}

TEST(MergeSortTest, Int)
{
	const int TEST_ARRAY_LENGTH = 8;
	int testArray[TEST_ARRAY_LENGTH] = { 2,5,7,3,1,8,4,6 };
	auto algorithm = [](auto array, int length) { AlgorithmT::MergeSort(array, 0, length - 1); };
	VerifySort<int>(testArray, TEST_ARRAY_LENGTH, algorithm);
}

TEST(MergeSortTest, Double)
{
	const int TEST_ARRAY_LENGTH = 8;
	double testArray[TEST_ARRAY_LENGTH] = { 3.0,1.0,2.0,5.0,7.0,8.0,4.0,6.0 };
	auto algorithm = [](auto array, int length) { AlgorithmT::MergeSort(array, 0, length - 1); };
	VerifySort<double>(testArray, TEST_ARRAY_LENGTH, algorithm);
}

TEST(MergeSortTest, Float)
{
	const int TEST_ARRAY_LENGTH = 8;
	float testArray[TEST_ARRAY_LENGTH] = { 2.0f,3.0f,1.0f,4.0f,6.0f,8.0f,5.0f,7.0f };
	auto algorithm = [](auto array, int length) { AlgorithmT::MergeSort(array, 0, length - 1); };
	VerifySort<float>(testArray, TEST_ARRAY_LENGTH, algorithm);
}

TEST(InsertionSortTest, Int)
{
	const int TEST_ARRAY_LENGTH = 8;
	int testArray[TEST_ARRAY_LENGTH] = { 2,5,7,3,1,8,4,6 };
	auto algorithm = [](auto array, int length) { AlgorithmT::InsertionSort(array, length); };
	VerifySort<int>(testArray, TEST_ARRAY_LENGTH, algorithm);
}

TEST(InsertionSortTest, Double)
{
	const int TEST_ARRAY_LENGTH = 8;
	double testArray[TEST_ARRAY_LENGTH] = { 3.0,1.0,2.0,5.0,7.0,8.0,4.0,6.0 };
	auto algorithm = [](auto array, int length) { AlgorithmT::InsertionSort(array, length); };
	VerifySort<double>(testArray, TEST_ARRAY_LENGTH, algorithm);
}

TEST(InsertionSortTest, Float)
{
	const int TEST_ARRAY_LENGTH = 8;
	float testArray[TEST_ARRAY_LENGTH] = { 2.0f,3.0f,1.0f,4.0f,6.0f,8.0f,5.0f,7.0f };
	auto algorithm = [](auto array, int length) { AlgorithmT::InsertionSort(array, length); };
	VerifySort<float>(testArray, TEST_ARRAY_LENGTH, algorithm);
}

TEST(HeapSortTest, Int)
{
	const int TEST_ARRAY_LENGTH = 8;
	int testArray[TEST_ARRAY_LENGTH] = { 2,5,7,3,1,8,4,6 };
	auto algorithm = [](auto array, int length) { AlgorithmT::HeapSort(array, length); };
	VerifySort<int>(testArray, TEST_ARRAY_LENGTH, algorithm);
}

TEST(HeapSortTest, Double)
{
	const int TEST_ARRAY_LENGTH = 8;
	double testArray[TEST_ARRAY_LENGTH] = { 3.0,1.0,2.0,5.0,7.0,8.0,4.0,6.0 };
	auto algorithm = [](auto array, int length) { AlgorithmT::HeapSort(array, length); };
	VerifySort<double>(testArray, TEST_ARRAY_LENGTH, algorithm);
}

TEST(HeapSortTest, Float)
{
	const int TEST_ARRAY_LENGTH = 8;
	float testArray[TEST_ARRAY_LENGTH] = { 2.0f,3.0f,1.0f,4.0f,6.0f,8.0f,5.0f,7.0f };
	auto algorithm = [](auto array, int length) { AlgorithmT::HeapSort(array, length); };
	VerifySort<float>(testArray, TEST_ARRAY_LENGTH, algorithm);
}