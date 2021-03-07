#include <time.h>
#include "insertionSort.h"
#include "MergeSort.h"
#include "NonRecursiveQuickSort.h"
#include "QuickSort.h"
#include "PerformanceMeasurement.h"
#include "ShellSort.h"
#include "Base.h"

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