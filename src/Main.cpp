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

        for (int i = 0; i < numberOfBases; i++) {
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
        Base* bases = new Base[numberOfBases];
        populateBases(bases, file, numberOfBases);

        return 0;
    }
    catch (const char* exception) {
        std::cout << exception << std::endl;
        return -1;
    }
}