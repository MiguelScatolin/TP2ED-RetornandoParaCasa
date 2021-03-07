#ifndef INPUT_HANDLING_H
#define INPUT_HANDLING_H

#include "AlgorithmEnum.h"

#define VALID_INTEGER_EXCEPTION
#define MAX_NUMBER_OF_BASES 200000

int getNumberOfBases(char numberOfBasesString[]);

AlgorithmEnum getAlgorithmNumber(char algorithmNumberString[]);

#endif