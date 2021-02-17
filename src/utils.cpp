#include "utils.hpp"

void initRandomArr(float* arr, int size)
{
    // random seed
    srand (time(NULL));

    for (int i = 0; i < size; i++)
    {
        // random number in the range -1.000 to 1.000
        float normalizedR = (float) (rand() % 2001 - 1000) / 1000.f;

        arr[i] = normalizedR;
    }
}