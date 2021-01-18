#include "Sort/HeapSort.h"
#include "DataStructure/Heap.h"

namespace AlgorithmT
{
    // Introduction to Algorithms 3e: 6.4 Heap Sort pg 161 
    template<typename T>
    void HeapSort(T* array, int length)
    {
        DataStructureT::MaxHeap maxHeap(array, length);
        for (int i = length - 1; i > 0; i--)
        {
            array[i] = maxHeap.Extract();
        }
        array[0] = maxHeap.Root();
    }
}