#ifndef BASE_LIST_H
#define BASE_LIST_H

#include "AlgorithmEnum.h"
#include "Base.h"

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