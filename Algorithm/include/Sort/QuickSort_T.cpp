#include "Sort/MergeSort.h"
#include "Utility/Macros.h"
#include <cstring>
#include <cstdlib>

namespace AlgorithmT
{
    // Introduction to Algorithms 3e: 7.1 Quick Sort pg 171 
    template<typename T>
    void QuickSort(T* array, int p, int r)
    {
        if (p < r)
        {
            int q = AlgorithmT::Partition(array, p, r);
            AlgorithmT::QuickSort(array, p, q - 1);
            AlgorithmT::QuickSort(array, q + 1, r);
        }
    }

    // Introduction to Algorithms 3e: 7.1 Partition pg 171 
    template<typename T>
    int Partition(T* array, int p, int r)
    {
        T x = array[r];
        T temp;
        int i = p;
        for (int j = p; j < r; j++)
        {
            if (array[j] <= x)
            {
                SWAP(array[i], array[j], temp);
                i++;
            }
        }
        SWAP(array[i], array[r], temp);

        return i;
    }

    // Introduction to Algorithms 3e: 7.3 Quick Sort pg 1779 
    template<typename T>
    void RandomizedQuickSort(T* array, int p, int r)
    {
        if (p < r)
        {
            int q = AlgorithmT::RandomizedPartition(array, p, r);
            AlgorithmT::RandomizedQuickSort(array, p, q - 1);
            AlgorithmT::RandomizedQuickSort(array, q + 1, r);
        }
    }

    // Introduction to Algorithms 3e: 7.3 Randomized Partition pg 179 
    template<typename T>
    int RandomizedPartition(T* array, int p, int r)
    {
        T temp;
        int i = rand() % (r - p + 1) + p;
        SWAP(array[i], array[r], temp);
        return Partition(array, p, r);
    }
}