#include "QuickSort.h"

void partition(Base bases[], int leftIndex, int rightIndex, int &i, int &j) {
    Base pivot, aux;
    i = leftIndex;
    j = rightIndex;
    pivot = bases[leftIndex];
    do {
        while(pivot.distance < bases[i].distance) i++;
        while(pivot.distance > bases[j].distance) j--;
        if(i <= j) {
            aux = bases[i];
            bases[i] = bases[j];
            bases[j] = aux;
            i++;
            j--;
        }
    } while(i <= j);
}

void sort(Base bases[], int leftIndex, int rightIndex) {
    int i, j;
    partition(bases, leftIndex, rightIndex, i, j);
    if(leftIndex < j) sort(bases, leftIndex, j);
    if(i < rightIndex) sort(bases, i, rightIndex);
}

void quickSort(Base bases[], int numberOfBases) {
    sort(bases, 0, numberOfBases - 1);
}