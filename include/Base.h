#ifndef BASE_H
#define BASE_H

#include <string>

class Base
{
    public:
        Base() {};
        Base(std::string name, int distance) : distance(distance), name(name) {}
        std::string name;
        int distance;
};

#endif