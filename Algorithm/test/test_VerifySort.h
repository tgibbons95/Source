#ifndef TEST_VERIFY_SORT_H
#define TEST_VERIFY_SORT_H

#include "gtest/gtest.h"
#include <functional>

template<typename T>
void VerifySort(
	T* testArray,
	int length,
	std::function<void(T* testArray, int length)> sortAlgorithm)
{
	sortAlgorithm(testArray, length);
	for (int i = 1; i <= length; i++)
	{
		EXPECT_EQ(static_cast<T>(i), testArray[i - 1]);
	}
}

#endif