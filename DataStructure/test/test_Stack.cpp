#include "gtest/gtest.h"
#include "DataStructure/Stack.h"

TEST(Stack, PushPop) 
{ 
	const int TEST_ARRAY_LENGTH = 20;
	int testArray[TEST_ARRAY_LENGTH] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	DataStructureT::Stack<int> stack;

	for (int i = 0; i < TEST_ARRAY_LENGTH; i++)
	{
		stack.Push(testArray[i]);
	}

	for(int i = TEST_ARRAY_LENGTH - 1; i >= 0; i--)
	{
		EXPECT_EQ(testArray[i], stack.Pop());
	}
}