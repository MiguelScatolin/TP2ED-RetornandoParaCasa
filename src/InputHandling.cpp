#include <string>
#include <stdexcept>
#include "InputHandling.h"

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