#ifndef BASE_H
#define BASE_H

#include <string>

class Base
{
    public:
        Base() {};
        Base(std::string name, int id) : name(name), id(id) {};
        int id;
        std::string name;
};

#endif