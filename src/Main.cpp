#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Base.h"

int main(int argc, char* argv[]) {
    std::ifstream file(argv[1]);
    int numberOfBases = atoi(argv[2]);

    Base* bases = new Base[numberOfBases];

    if(file.is_open())
        for (int i = 0; i < numberOfBases; i++) {
            int id;
            std::string name;
            file >> name;
            file >> id;

            Base newBase = Base(name, id);

            bases[i] = newBase;
        }

    for (int i = 0; i < numberOfBases; i++) {
        std::cout << bases[i].name << " - " << bases[i].id << std::endl;
    }

    return 0;
}