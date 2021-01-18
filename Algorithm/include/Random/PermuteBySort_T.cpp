#include "Random/PermuteBySort.h"
#include "Sort/MergeSort.h"

#include <cstdlib>

namespace AlgorithmT
{
    // Introduction to Algorithms 3e: 5.3 Permute By Sort pg 125 
    template<typename T>
    void PermuteBySort(T* array, int length)
    {
        int* priorities = new int[length];
        for (int i = 0; i < length; i++)
        {
            priorities[i] = rand() % (length * length * length) + 1;
        }

        AlgorithmT::MergeSortByPriorities(array, priorities, 0, length - 1);
        delete[] priorities;
    }
}