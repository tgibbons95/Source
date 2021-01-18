#include "gtest/gtest.h"
#include "Random/PermuteBySort.h"

TEST(PermuteBySortTest, TestCase1) 
{ 
	const int n = 10;
	int testArray[n] = {1,2,3,4,5,6,7,8,9,10};

	AlgorithmT::PermuteBySort(testArray, n);

	AlgorithmT::PermuteBySort(testArray, n);

	AlgorithmT::PermuteBySort(testArray,n );

}
