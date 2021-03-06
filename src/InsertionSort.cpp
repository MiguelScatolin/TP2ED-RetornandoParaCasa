#include "InsertionSort.h"

void insertionSort(Base *bases, int numberOfBases) {
    int i,j;
    Base aux;
    for(i = 1; i < numberOfBases; i++) {
        aux = bases[i];
        j = i - 1;

        while(j >= 0 && aux.distance > bases[j].distance) {
            bases[j + 1] = bases[j];
            j--;
        }

        bases[j + 1] = aux;
    }
}