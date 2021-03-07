#include <cstdlib>
#include <iostream>
#include "Base.h"
#include "insertionSort.h"
#include "MergeSort.h"
#include "NonRecursiveQuickSort.h"
#include "QuickSort.h"
#include "ShellSort.h"

int main(int argc, char* argv[]) {
    try {
        if(argc < 3)
            throw "Nome do arquivo ou número de bases não informados.";

        char *fileName = argv[1];

        int numberOfBases = atoi(argv[2]);
        if(numberOfBases < 7)
            throw "Mínimo de 7 bases devem ser analisadas";

        Base* bases = new Base[numberOfBases];
        populateBases(bases, fileName, numberOfBases);

        quickSort(bases, numberOfBases);

        printFirstBases(bases);

        delete[] bases;
        return 0;
    }
    catch (const char* exception) {
        std::cout << exception << std::endl;
        return -1;
    }
}