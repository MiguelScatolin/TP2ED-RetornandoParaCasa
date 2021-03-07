#ifndef BASE_LIST_H
#define BASE_LIST_H

#include <string>
#include "Base.h"

enum AlgorithmEnum
{
    INSERTION_SORT,
    MERGE_SORT,
    QUICK_SORT,
    SHELL_SORT,
    IMPROVED_QUICK_SORT
};

class BaseList
{
    public:
        BaseList(char fileName[], int numberOfBases);
        ~BaseList();
        void printFirstBases();
        void sort(AlgorithmEnum algorithm);

    private:
        void populateBases(char fileName[]);
        Base* bases;
        int numberOfBases;
};

#endif