#include "ShellSort.h"

void shellSort(Base bases[], int numberOfBases)
{
    for (int gap = numberOfBases/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < numberOfBases; i += 1)
        {
            Base temp = bases[i];

            int j;
            for (j = i; j >= gap && bases[j - gap].distance < temp.distance; j -= gap)
                bases[j] = bases[j - gap];

            bases[j] = temp;
        }
    }
}
