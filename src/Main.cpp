#include <iostream>
#include "BaseList.h"
#include "PerformanceMeasurement.h"

#define VALID_INTEGER_EXCEPTION
#define MAX_NUMBER_OF_BASES 200000

int getNumberOfBases(char numberOfBasesString[]) {
    try {
        int numberOfBases = std::stoi(numberOfBasesString);
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

AlgorithmEnum getAlgorithmNumber(char algorithmNumberString[]) {
    AlgorithmEnum algorithm;
    try {
        int algorithmNumber = std::stoi(algorithmNumberString);
        algorithm = static_cast<AlgorithmEnum>(algorithmNumber);
    }
    catch(...){
        algorithm = QUICK_SORT;
    }
    return algorithm;
}

int main(int argc, char* argv[]) {
    try {
        if(argc < 3)
            throw "Nome do arquivo ou número de bases não informados.";

        char *fileName = argv[1];
        int numberOfBases = getNumberOfBases(argv[2]);
        AlgorithmEnum algorithm = getAlgorithmNumber(argv[3]);

        BaseList baseList = BaseList(fileName, numberOfBases);

        if(numberOfBases) {
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