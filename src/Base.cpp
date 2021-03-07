#include <iostream>
#include <fstream>
#include "Base.h"

void populateBases(Base *bases, char fileName[], int numberOfBases) {
    std::ifstream file(fileName);

    if (!file.is_open())
        throw  "Erro ao abrir arquivo de bases";

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