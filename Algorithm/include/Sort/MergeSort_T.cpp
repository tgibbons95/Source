#include "Sort/MergeSort.h"
#include <cstring>

namespace AlgorithmT
{
    // Introduction to Algorithms 3e: 2.3 Merge Sort pg 34 
    template<typename T>
    void MergeSort(T* array, int p, int r)
    {
        if (p < r)
        {
            int q = (p + r) / 2;
            AlgorithmT::MergeSort(array, p, q);
            AlgorithmT::MergeSort(array, q + 1, r);
            AlgorithmT::Merge(array, p, q, r);
        }
    }

    // Introduction to Algorithms 3e: 2.3 Merge pg 31 
    template<typename T>
    void Merge(T* array, int p, int q, int r)
    {
        const int n1 = q - p + 1;
        const int n2 = r - q;
        int i = 0;
        int j = 0;
        int k = 0;
        T* newArray = new T[n1 + n2];
        T* left = &newArray[0];
        T* right = &newArray[n1];

        ::memcpy(left, &array[p], n1 * sizeof(T));
        ::memcpy(right, &array[q + 1], n2 * sizeof(T));

        for (k = p; k <= r; k++)
        {
            if (i < n1 && (j >= n2 || left[i] < right[j]))
            {
                array[k] = left[i++];
            }
            else
            {
                array[k] = right[j++];
            }
        }

        delete[] newArray;
    }

    template<typename T>
    void MergeSortByPriorities(T* array, int* priorities, int p, int r)
    {
        if (p < r)
        {
            int q = (p + r) / 2;
            AlgorithmT::MergeSortByPriorities(array, priorities, p, q);
            AlgorithmT::MergeSortByPriorities(array, priorities, q + 1, r);
            AlgorithmT::MergeByPriorities(array, priorities, p, q, r);
        }
    }

    template<typename T>
    void MergeByPriorities(T* array, int* priorities, int p, int q, int r)
    {
        const int n1 = q - p + 1;
        const int n2 = r - q;
        int i = 0;
        int j = 0;
        int k = 0;
        T* newArray = new T[n1 + n2];
        T* left = &newArray[0];
        T* right = &newArray[n1];
        int* newP = new int[n1 + n2];
        int* leftP = &newP[0];
        int* rightP = &newP[n1];

        ::memcpy(left, &array[p], n1 * sizeof(T));
        ::memcpy(right, &array[q + 1], n2 * sizeof(T));

        ::memcpy(leftP, &priorities[p], n1 * sizeof(int));
        ::memcpy(rightP, &priorities[q + 1], n2 * sizeof(int));

        for (k = p; k <= r; k++)
        {
            if (i < n1 && (j >= n2 || leftP[i] < rightP[j]))
            {
                array[k] = left[i];
                priorities[k] = leftP[i++];
            }
            else
            {
                array[k] = right[j];
                priorities[k] = rightP[j++];
            }
        }

        delete[] newArray;
        delete[] newP;
    }

}