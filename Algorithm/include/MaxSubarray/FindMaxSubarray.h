#ifndef FIND_MAX_SUBARRAY_H
#define FIND_MAX_SUBARRAY_H

#include <tuple>

namespace AlgorithmT
{
	template<typename T>
	std::tuple<int, int, T> FindMaxSubarray(T* array, int low, int high);
}

#include "MaxSubarray/FindMaxSubarray_T.cpp"

#endif