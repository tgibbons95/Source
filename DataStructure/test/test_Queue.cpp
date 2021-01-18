#include "gtest/gtest.h"
#include "DataStructure/Queue.h"

TEST(Stack, EnqueueDequeue)
{
	const int TEST_ARRAY_LENGTH = 20;
	int testArray[TEST_ARRAY_LENGTH] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	DataStructureT::Queue<int> queue;

	for (int i = 0; i < TEST_ARRAY_LENGTH; i++)
	{
		queue.Enqueue(testArray[i]);
	}

	for (int i = 0; i < TEST_ARRAY_LENGTH; i++)
	{
		EXPECT_EQ(testArray[i], queue.Dequeue());
	}
}