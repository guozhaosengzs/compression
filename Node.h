/**
    Coding Assignment 4: Compression
    Node.h
    November 22, 2019

    @author Zhaosen Guo
*/
#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
public:
    Node(T value);

    void set_value(T value);
    T get_value();

    Node *get_next();
    void set_next(Node *next);

private:
    Node<T>* _next;
    T _value;
};

#endif // NODE_H
