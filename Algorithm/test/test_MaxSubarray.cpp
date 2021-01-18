#include "gtest/gtest.h"
#include "MaxSubarray/FindMaxCrossingSubarray.h"
#include "MaxSubarray/FindMaxSubarray.h"

TEST(FindMaxSubarrayTest, Int)
{
	const int TEST_ARRAY_LENGTH = 16;
	int testArray[TEST_ARRAY_LENGTH] = { 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };

	auto [maxLeft, maxRight, sum] = AlgorithmT::FindMaxSubarray<int>(testArray, 0, TEST_ARRAY_LENGTH - 1);
	EXPECT_EQ(7, maxLeft);
	EXPECT_EQ(10, maxRight);
	EXPECT_EQ(43, sum);
}

TEST(FindMaxCrossingSubarrayTest, MidPointWithinMaxSubarray) 
{ 
	const int TEST_ARRAY_LENGTH = 16;
	int testArray[TEST_ARRAY_LENGTH] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	int maxLeft = 0;
	int maxRight = 0;
	int sum = 0;
	for (int i = 7; i < 10; i++)
	{
		std::tie(maxLeft, maxRight, sum) = AlgorithmT::FindMaxCrossingSubarray<int>(testArray, 0, i, TEST_ARRAY_LENGTH - 1);
		EXPECT_EQ(7, maxLeft);
		EXPECT_EQ(10, maxRight);
		EXPECT_EQ(43, sum);
	}
}
