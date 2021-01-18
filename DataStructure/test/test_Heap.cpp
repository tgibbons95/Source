#include "gtest/gtest.h"
#include "DataStructure/Heap.h"

TEST(MaxHeap, MaxExtract) 
{ 
	const int TEST_ARRAY_LENGTH = 20;
	int testArray[TEST_ARRAY_LENGTH] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	DataStructureT::MaxHeap<int> maxHeap;

	for (int i = 1; i <= TEST_ARRAY_LENGTH; i++)
	{
		maxHeap.Insert(i);
		EXPECT_EQ(i, maxHeap.Root());
	}

	for(int i = TEST_ARRAY_LENGTH; i > 0; i--)
	{
		EXPECT_EQ (i, maxHeap.Extract());
	}
}

TEST(MaxHeap, BuildHeap)
{
	const int TEST_ARRAY_LENGTH = 20;
	int testArray[TEST_ARRAY_LENGTH] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	DataStructureT::MaxHeap<int> maxHeap(testArray, TEST_ARRAY_LENGTH);

	for (int i = TEST_ARRAY_LENGTH; i > 0; i--)
	{
		EXPECT_EQ(i, maxHeap.Extract());
	}
}