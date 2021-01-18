#include "Random/RandomizeInPlace.h"

#include <cstdlib>

namespace AlgorithmT
{
    // Introduction to Algorithms 3e: 5.3 Randomize In Place pg 126
    template<typename T>
    void RandomizeInPlace(T* array, int length)
    {
        T temp;
        int randomIndex = 0;
        for (int i = 0; i < length; i++)
        {
            randomIndex = (rand() % (length - i)) + i;
            if (randomIndex != i)
            {
                temp = array[randomIndex];
                array[randomIndex] = array[i];
                array[i] = temp;
            }
        }
    }
}