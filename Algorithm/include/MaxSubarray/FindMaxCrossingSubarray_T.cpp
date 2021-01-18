#include "MaxSubarray/FindMaxCrossingSubarray.h"

namespace AlgorithmT
{
    // Introduction to Algorithms 3e: 4.1 Find Max Crossing Subarray pg 71 
    template<typename T>
    std::tuple<int, int, T> FindMaxCrossingSubarray(T* array, int low, int mid, int high)
    {
        int maxLeft = mid;
        int maxRight = mid + 1;
        T leftSum = array[mid];
        T rightSum = array[mid + 1];

        T sum = leftSum;
        for (int i = mid - 1; i >= low; i--)
        {
            sum += array[i];
            if (sum > leftSum)
            {
                leftSum = sum;
                maxLeft = i;
            }
        }

        sum = array[mid+1];
        for (int i = mid + 2; i <= high; i++)
        {
            sum += array[i];
            if (sum > rightSum)
            {
                rightSum = sum;
                maxRight = i;
            }
        }

        return std::make_tuple(maxLeft, maxRight, leftSum + rightSum);
    }
}