#include <cstdlib>
#include <iostream>
#include <string>
#include <time.h>
#include "Base.h"
#include "insertionSort.h"
#include "MergeSort.h"
#include "NonRecursiveQuickSort.h"
#include "QuickSort.h"
#include "ShellSort.h"

#define NUMBER_OF_MEASURES 3

double measureAndPrintPerformancePerformance(char fileName[], int numberOfBases) {
    double totalTime = 0;
    for(int i = 0; i < NUMBER_OF_MEASURES; i++) {
        Base* bases = new Base[numberOfBases];
        populateBases(bases, fileName, numberOfBases);

        clock_t t = clock();
        quickSort(bases, numberOfBases);
        t = clock() - t;
        totalTime += ((double)t)/((CLOCKS_PER_SEC/1000));
    }
    std::cout << "Média do tempo de execução(" << numberOfBases << "): " << totalTime / NUMBER_OF_MEASURES << std::endl;
}

void measurePerformanceForAllInputSizes(char fileName[]) {
    int numberOfBasesToEvaluate[8] = {100, 500, 1000, 5000, 10000, 50000, 100000, 200000};
    for(int i = 0; i < 8; i++)
        measureAndPrintPerformancePerformance(fileName, numberOfBasesToEvaluate[i]);
}

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
        //measurePerformanceForAllInputSizes(fileName);

        printFirstBases(bases);

        delete[] bases;
        return 0;
    }
    catch (const char* exception) {
        std::cout << exception << std::endl;
        return -1;
    }
}