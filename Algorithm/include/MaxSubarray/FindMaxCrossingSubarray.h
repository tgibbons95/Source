#ifndef FIND_MAX_CROSSING_SUBARRAY_H
#define FIND_MAX_CROSSING_SUBARRAY_H

#include <tuple>

namespace AlgorithmT
{
	template<typename T>
	std::tuple<int, int, T> FindMaxCrossingSubarray(T* array, int low, int mid, int high);
}

#include "MaxSubarray/FindMaxCrossingSubarray_T.cpp"

#endif