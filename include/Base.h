#ifndef BASE_H
#define BASE_H

#include <string>

class Base
{
    public:
        Base() {};
        Base(std::string name, int distance) : name(name), distance(distance) {}
        int distance;
        std::string name;
};

#endif