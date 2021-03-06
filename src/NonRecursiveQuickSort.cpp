#include "NonRecursiveQuickSort.h"

Base getMedianPivot(Base bases[], int leftIndex, int rightIndex) {
    Base first = bases[leftIndex],
            last = bases[rightIndex],
            middle = bases[(leftIndex + rightIndex)/2];
    if((middle.distance >= last.distance && middle.distance <= first.distance) || (middle.distance <= last.distance && middle.distance >= first.distance))
        return middle;
    if((last.distance >= middle.distance && last.distance <= first.distance) || (last.distance <= middle.distance && last.distance >= first.distance))
        return last;
    else
        return first;
}

void partitionWithMedianPivot(Base bases[], int leftIndex, int rightIndex, int &i, int &j) {
    Base pivot, aux;
    i = leftIndex;
    j = rightIndex;
    pivot = getMedianPivot(bases, leftIndex, rightIndex);

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

void nonRecursiveQuickSort(Base bases[], int numberOfBases) {
    Stack<Interval> stack = Stack<Interval>();
    int leftIndex = 0;
    int rightIndex = numberOfBases - 1;
    int i, j;
    Interval currentInterval = Interval(leftIndex, rightIndex);
    stack.Push(currentInterval);
    do {
        if (rightIndex > leftIndex) {
            partitionWithMedianPivot(bases, leftIndex, rightIndex, i, j);
            if ((j-leftIndex)>(rightIndex-i)) {
                currentInterval.right = j;
                currentInterval.left = leftIndex;
                stack.Push(currentInterval);
                leftIndex = i;
            }
            else {
                currentInterval.left = i;
                currentInterval.right = rightIndex;
                stack.Push(currentInterval);
                rightIndex = j;
            }
        }
        else {
            currentInterval = stack.Pop();
            rightIndex = currentInterval.right;
            leftIndex = currentInterval.left;
        }
    } while (!stack.IsEmpty());
}
