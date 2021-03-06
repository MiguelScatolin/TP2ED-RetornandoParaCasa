#ifndef NODE_H
#define NODE_H

template<class T>
class Node
{
    public:
        Node() {};
        Node(T item) : item(item), next(nullptr) {}
        T GetItem() { return item; };
        void SetItem(T newItem) { item = newItem; };
        Node<T>* GetNext() { return next; };
        void SetNext(Node<T> *newNext) { next = newNext; };

    private:
        T item;
        Node<T> *next;
};

#endif