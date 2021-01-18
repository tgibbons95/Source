#ifndef MERGE_SORT_H
#define MERGE_SORT_H

namespace AlgorithmT
{
	template<typename T>
	void Merge(T* array, int p, int q, int r);

	template<typename T>
	void MergeByPriorities(T* array, int* priorities, int p, int q, int r);

	template<typename T>
	void MergeSort(T* array, int p, int r);

	template<typename T>
	void MergeSortByPriorities(T* array, int* priorities, int p, int r);
}

#include "Sort/MergeSort_T.cpp"

#endif