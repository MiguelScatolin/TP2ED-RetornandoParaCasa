#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
#include "Base.h"
#include "insertionSort.h"
#include "MergeSort.h"
#include "NonRecursiveQuickSort.h"
#include "QuickSort.h"
#include "ShellSort.h"

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

        clock_t t = clock();
        shellSort(bases, numberOfBases);
        t = clock() - t;

        printFirstBases(bases);

        std::cout << "Tempo de execucao: " << ((double)t)/((CLOCKS_PER_SEC/1000)) << std::endl;
        return 0;
    }
    catch (const char* exception) {
        std::cout << exception << std::endl;
        return -1;
    }
}