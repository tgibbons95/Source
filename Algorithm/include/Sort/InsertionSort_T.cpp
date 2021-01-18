#include "Sort/InsertionSort.h"

namespace AlgorithmT
{
    // Introduction to Algorithms 3e: 2.1 Insertion Sort pg 18 
    template<typename T>
    void InsertionSort(T* array, int length)
    {
        int i = 0;
        int j = 0;
        T key;
        for(j = 1; j < length; j++)
        {
            key = array[j];
            i = j - 1;
            while (i >= 0 && array[i] > key)
            {
            array[i+1] = array[i];
            i--;
            }
            array[i + 1] = key;   
        }
    }
}