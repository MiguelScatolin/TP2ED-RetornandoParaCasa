#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Base.h"

void populateBases(Base *bases, std::ifstream &file, int numberOfBases) {
    for (int i = 0; i < numberOfBases; i++) {
            int distance;
            std::string name;
            file >> name;
            file >> distance;

            Base newBase = Base(name, distance);

            bases[i] = newBase;
        }
}

void insertionSort(Base *bases, int numberOfBases) {
    int i,j;
    Base aux;
    for(i = 1; i < numberOfBases; i++) {
        aux = bases[i];
        j = i - 1;

        while(j >= 0 && aux.distance > bases[j].distance) {
            bases[j + 1] = bases[j];
            j--;
        }

        bases[j + 1] = aux;
    }
}

Base *merge(Base leftList[], Base rightList[], int numberOfLeftElements, int numberOfRightElements) {
    int i = 0, j = 0, k = 0;
    Base* sortedMerge = new Base[numberOfRightElements + numberOfLeftElements];

    while (i < numberOfLeftElements && j < numberOfRightElements) {
        if (leftList[i].distance >= rightList[j].distance) {
            sortedMerge[k] = leftList[i];
            i++;
        } else {
            sortedMerge[k] = rightList[j];
            j++;
        }
        k++;
    }

    if (k < numberOfLeftElements + numberOfRightElements) {
        for(; i < numberOfLeftElements; i++) {
            sortedMerge[k] = leftList[i];
            k++;
        }
        for(; j < numberOfRightElements; j++) {
            sortedMerge[k] = rightList[j];
            k++;
        }
    }

    return sortedMerge;
}

Base *splitAndMergeSorted(Base bases[], int leftIndex, int rightIndex) {
    if(leftIndex < rightIndex) {
        int middleIndex = (leftIndex + rightIndex) / 2;
        Base *leftList = splitAndMergeSorted(bases, leftIndex, middleIndex);
        Base *rightList = splitAndMergeSorted(bases, middleIndex + 1, rightIndex);
        int numberOfLeftElements = middleIndex - leftIndex + 1;
        int numberOfRightElements = rightIndex - middleIndex;
        return merge(leftList, rightList, numberOfLeftElements, numberOfRightElements);
    }
    Base* singleElement = new Base[1];
    singleElement[0] = bases[leftIndex];
    return singleElement;
}

void mergeSort(Base bases[], int numberOfBases) {
    bases = splitAndMergeSorted(bases, 0, numberOfBases - 1);
}

void printFirstBases(Base *bases) {
    for (int i = 0; i < 7; i++) {
        std::cout << bases[i].name << " - " << bases[i].distance << std::endl;
    }
}

int main(int argc, char* argv[]) {
    try {
        if(argc < 3)
            throw "Nome do arquivo ou número de bases não informados.";

        std::ifstream file(argv[1]);

        if (!file.is_open())
            throw  "Erro ao abrir arquivo de mapa";

        int numberOfBases = atoi(argv[2]);
        if(numberOfBases < 7)
            throw "Mínimo de 7 bases devem ser analisadas";

        Base* bases = new Base[numberOfBases];
        populateBases(bases, file, numberOfBases);
        mergeSort(bases, numberOfBases);
        printFirstBases(bases);

        return 0;
    }
    catch (const char* exception) {
        std::cout << exception << std::endl;
        return -1;
    }
}