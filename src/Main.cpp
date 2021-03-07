#include <cstdlib>
#include <iostream>
#include "Base.h"
#include "insertionSort.h"
#include "MergeSort.h"
#include "NonRecursiveQuickSort.h"
#include "QuickSort.h"
#include "ShellSort.h"

#define VALID_INTEGER_EXCEPTION
#define MIN_NUMBER_OF_BASES 7
#define MAX_NUMBER_OF_BASES 200000

enum AlgorithmEnum
{
    INSERTION_SORT,
    MERGE_SORT,
    QUICK_SORT,
    SHELL_SORT,
    IMPROVED_QUICK_SORT
};

int getNumberOfBases(char numberOfBasesString[]) {
    try {
        int numberOfBases = std::stoi(numberOfBasesString);
        if(numberOfBases < MIN_NUMBER_OF_BASES)
            throw "Mínimo de 7 bases devem ser analisadas";
        if(numberOfBases > MAX_NUMBER_OF_BASES)
            throw "Máximo de 200000 bases devem ser analisadas";
        return numberOfBases;
    }
    catch(std::invalid_argument& e){
        throw VALID_INTEGER_EXCEPTION;
    }
    catch(std::out_of_range& e){
        throw VALID_INTEGER_EXCEPTION;
    }
}

int getAlgorithmNumber(char algorithmNumberString[]) {
    int algorithmNumber;
    try {
        algorithmNumber = std::stoi(algorithmNumberString);
    }
    catch(...){
        algorithmNumber = QUICK_SORT;
    }
    return algorithmNumber;
}

int main(int argc, char* argv[]) {
    try {
        if(argc < 3)
            throw "Nome do arquivo ou número de bases não informados.";

        char *fileName = argv[1];

        int numberOfBases = getNumberOfBases(argv[2]);

        int algorithm = getAlgorithmNumber(argv[3]);

        Base* bases = new Base[numberOfBases];
        populateBases(bases, fileName, numberOfBases);

        switch (algorithm){
            case INSERTION_SORT:
                insertionSort(bases, numberOfBases);
                break;
            case MERGE_SORT:
                mergeSort(&bases, numberOfBases);
                break;
            case QUICK_SORT:
                quickSort(bases, numberOfBases);
                break;
            case SHELL_SORT:
                shellSort(bases, numberOfBases);
                break;
            case IMPROVED_QUICK_SORT:
                nonRecursiveQuickSort(bases, numberOfBases);
                break;
            default:
                quickSort(bases, numberOfBases);
        }

        printFirstBases(bases);

        delete[] bases;
        return 0;
    }
    catch (const char* exception) {
        std::cout << exception << std::endl;
        return -1;
    }
}