#ifndef STACK_H
#define STACK_H

#include "List.h"

template<class T>
class Stack : public List<T>
{
    public:
        Stack() : List<T>() {}
        void Push(T item);
        T Pop();
};

template<class T>
void Stack<T>::Push(T item)  {
    this->InsertBefore(item);
}

template<class T>
T Stack<T>::Pop() {
    return this->RemoveFirst();
}

#endif