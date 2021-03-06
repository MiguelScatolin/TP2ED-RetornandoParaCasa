#ifndef NON_RECURSIVE_QUICK_SORT_H
#define NON_RECURSIVE_QUICK_SORT_H

#include "Base.h"
#include "Stack.h"

class Interval
{
    public:
        Interval() {}
        Interval(int left, int right) : left(left), right(right) {}
        int left;
        int right;
};

void nonRecursiveQuickSort(Base bases[], int numberOfBases);

#endif