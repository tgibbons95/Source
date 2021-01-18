#include "gtest/gtest.h"
#include "DataStructure/List.h"

TEST(List, InsertSearchDelete)
{
	const int TEST_ARRAY_LENGTH = 16;
	int testArray[TEST_ARRAY_LENGTH] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	DataStructureT::List<int> list;

	for (int i = 0; i < TEST_ARRAY_LENGTH; i++)
	{
		list.Insert(testArray[i]);
	}

	DataStructureT::ListNode<int>* node;
	for (int i = TEST_ARRAY_LENGTH - 1; i >= 0; i--)
	{
		node = list.Search(testArray[i]);
		EXPECT_NE(node, nullptr);
		list.Delete(node);

		node = list.Search(testArray[i]);
		EXPECT_EQ(node, nullptr);
	}
}