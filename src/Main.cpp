#include <iostream>
#include "AlgorithmEnum.h"
#include "BaseList.h"
#include "InputHandling.h"
#include "PerformanceMeasurement.h"

int main(int argc, char* argv[]) {
    try {
        if(argc < 3)
            throw "Nome do arquivo ou número de bases não informados.";

        char *fileName = argv[1];
        int numberOfBases = getNumberOfBases(argv[2]);
        AlgorithmEnum algorithm = getAlgorithmNumber(argv[3]);

        if(numberOfBases) {
            BaseList baseList = BaseList(fileName, numberOfBases);
            baseList.sort(algorithm);
            baseList.printFirstBases();
        }
        else {
            measurePerformanceForAllInputSizes(fileName, algorithm);
        }

        return 0;
    }
    catch (const char* exception) {
        std::cout << exception << std::endl;
        return -1;
    }
}