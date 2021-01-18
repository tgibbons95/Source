#include "MaxSubarray/FindMaxSubarray.h"
#include "MaxSubarray/FindMaxCrossingSubarray.h"

namespace AlgorithmT
{
    // Introduction to Algorithms 3e: 4.1 Find Max Subarray pg 72 
    template<typename T>
    std::tuple<int, int, T> FindMaxSubarray(T* array, int low, int high)
    {
        if (high == low)
        {
            return std::make_tuple(low, high, array[low]);
        }
        else
        {
            int mid = (low + high) / 2;
            auto [leftLow, leftHigh, leftSum] = FindMaxSubarray(array, low, mid);
            auto [rightLow, rightHigh, rightSum] = FindMaxSubarray(array, mid + 1, high);
            auto [crossLow, crossHigh, crossSum] = FindMaxCrossingSubarray(array, low, mid, high);

            if (leftSum >= rightSum && leftSum >= crossSum)
            {
                return std::make_tuple(leftLow, leftHigh, leftSum);
            }
            else if (rightSum >= crossSum)
            {
                return std::make_tuple(rightLow, rightHigh, rightSum);
            }
            else
            {
                return std::make_tuple(crossLow, crossHigh, crossSum);
            }
        }
    }
}