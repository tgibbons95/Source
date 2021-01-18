#ifndef QUICK_SORT_H
#define QUICK_SORT_H

namespace AlgorithmT
{
	template<typename T>
	int Partition(T* array, int p, int r);

	template<typename T>
	void QuickSort(T* array, int p, int r);

	template<typename T>
	int RandomizedPartition(T* array, int p, int r);

	template<typename T>
	void RandomizedQuickSort(T* array, int p, int r);

}

#include "Sort/QuickSort_T.cpp"

#endif