#include <iostream>
#include <fstream>
#include "Base.h"
#include "BaseList.h"
#include "insertionSort.h"
#include "MergeSort.h"
#include "NonRecursiveQuickSort.h"
#include "QuickSort.h"
#include "ShellSort.h"

BaseList::BaseList(char fileName[], int numberOfBases) {
    this->numberOfBases = numberOfBases;
    populateBases(fileName);
}

BaseList::~BaseList() {
    delete[] bases;
}

void BaseList::populateBases(char fileName[]) {
    std::ifstream file(fileName);

    if (!file.is_open())
        throw  "Erro ao abrir arquivo de bases";

    bases = new Base[numberOfBases];

    for (int i = 0; i < numberOfBases; i++) {
            int distance;
            std::string name;
            file >> name;
            file >> distance;

            Base newBase = Base(name, distance);

            bases[i] = newBase;
        }
}

void BaseList::printFirstBases() {
    for (int i = 0; i < 7 && i < numberOfBases; i++) {
        std::cout << bases[i].name << " - " << bases[i].distance << std::endl;
    }
}

void BaseList::sort(AlgorithmEnum algorithm) {
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
}