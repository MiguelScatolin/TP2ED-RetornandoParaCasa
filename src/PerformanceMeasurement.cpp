#include <time.h>
#include <iostream>
#include "Base.h"
#include "BaseList.h"
#include "PerformanceMeasurement.h"

double measureAndPrintPerformancePerformance(char fileName[], int numberOfBases, AlgorithmEnum algorithm) {
    double totalTime = 0;
    for(int i = 0; i < NUMBER_OF_MEASURES; i++) {
        BaseList baseList = BaseList(fileName, numberOfBases);

        clock_t t = clock();
        baseList.sort(algorithm);
        t = clock() - t;

        totalTime += ((double)t)/((CLOCKS_PER_SEC/1000));
    }
    std::cout << "Média do tempo de execução(" << numberOfBases << "): " << totalTime / NUMBER_OF_MEASURES << std::endl;
}

void measurePerformanceForAllInputSizes(char fileName[], AlgorithmEnum algorithm) {
    std::cout << "Número do algoritmo selecionado: " << algorithm << std::endl;
    int numberOfBasesToEvaluate[8] = {100, 500, 1000, 5000, 10000, 50000, 100000, 200000};
    for(int i = 0; i < 8; i++)
        measureAndPrintPerformancePerformance(fileName, numberOfBasesToEvaluate[i], algorithm);
}