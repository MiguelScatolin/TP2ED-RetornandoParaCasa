#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Node.h"

template <class T>
class List
{
    public:
        List();
        ~List();
        int GetSize();
        bool IsEmpty();
        void InsertAfter(T item);
        void InsertBefore(T item);
        T RemoveFirst();
        void Print();

    protected:
        Node<T> *head;
        Node<T> *tail;
        int size;
};

template<class T>
List<T>::List() {
    size = 0;
    head = new Node<T>();
    tail = head;
}

template<class T>
List<T>::~List() {
    Node<T> *p;
    p = head->GetNext();
    while(p != nullptr){
        head->SetNext(p->GetNext());
        delete p;
        p = head->GetNext();
    }
    tail = head;
    size = 0;
    delete head;
}

template<class T>
int List<T>::GetSize() {
    return size;
}

template<class T>
bool List<T>::IsEmpty() {
    return size == 0;
}

template<class T>
void List<T>::InsertAfter(T item)  {
    Node<T> *newNode = new Node<T>(item);

    tail->SetNext(newNode);
    tail = newNode;
    size++;
}

template<class T>
void List<T>::InsertBefore(T item) {
    Node<T> *newNode = new Node<T>(item);

    newNode->SetNext(head->GetNext());
    head->SetNext(newNode);

    size++;
    if(newNode->GetNext() == nullptr)
        tail = newNode;
}

template<class T>
T List<T>::RemoveFirst() {
    if (IsEmpty())
        throw "Não tem nenhum item!";

    Node<T> *p;
    T poppedItem;

    poppedItem = head->GetNext()->GetItem();
    p = head;
    head = head->GetNext();
    delete p;
    size--;
    return poppedItem;
}

template<class T>
void List<T>::Print() {
    if(IsEmpty())
        return;

    Node<T> *p;
    p = head->GetNext();
    while(p != nullptr) {
        std::string s(p->GetItem());
        std::cout << s << std::endl;
        p = p->GetNext();
    }
}

#endif