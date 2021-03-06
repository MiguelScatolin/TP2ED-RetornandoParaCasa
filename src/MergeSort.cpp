#include "MergeSort.h"

Base *merge(Base leftList[], Base rightList[], int numberOfLeftElements, int numberOfRightElements) {
    int i = 0, j = 0, k = 0;
    Base* sortedMerge = new Base[numberOfRightElements + numberOfLeftElements];

    while (i < numberOfLeftElements && j < numberOfRightElements) {
        if (leftList[i].distance >= rightList[j].distance) {
            sortedMerge[k] = leftList[i];
            i++;
        } else {
            sortedMerge[k] = rightList[j];
            j++;
        }
        k++;
    }

    if (k < numberOfLeftElements + numberOfRightElements) {
        for(; i < numberOfLeftElements; i++) {
            sortedMerge[k] = leftList[i];
            k++;
        }
        for(; j < numberOfRightElements; j++) {
            sortedMerge[k] = rightList[j];
            k++;
        }
    }

    return sortedMerge;
}

Base *splitAndMergeSorted(Base bases[], int leftIndex, int rightIndex) {
    if(leftIndex < rightIndex) {
        int middleIndex = (leftIndex + rightIndex) / 2;
        Base *leftList = splitAndMergeSorted(bases, leftIndex, middleIndex);
        Base *rightList = splitAndMergeSorted(bases, middleIndex + 1, rightIndex);
        int numberOfLeftElements = middleIndex - leftIndex + 1;
        int numberOfRightElements = rightIndex - middleIndex;
        return merge(leftList, rightList, numberOfLeftElements, numberOfRightElements);
    }
    Base* singleElement = new Base[1];
    singleElement[0] = bases[leftIndex];
    return singleElement;
}

void mergeSort(Base *bases[], int numberOfBases) {
    *bases = splitAndMergeSorted(*bases, 0, numberOfBases - 1);
}
