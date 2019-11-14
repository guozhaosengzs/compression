/**
    Coding Assignment 4: Compression
    Node.cpp
    November 22, 2019

    @author Zhaosen Guo
*/
#include "Node.h"

/**
    Constructor of Node, initializes the local member variables.
*/
template <class T>
Node<T>::Node(T value) {
    _next = nullptr;
    _value = value;
}

/**
    Sets the value in this node.

    @param T type value.
*/
template <class T>
void Node<T>::set_value(T value) {
    _value = value;
}

/**
    Give the value.

    @return The value of this node.
*/
template <class T>
T Node<T>::get_value() {
    return _value;
}

/**
    Provide a pointer for the following node.

    @return The next node's pointer.
*/
template <class T>
Node<T>* Node<T>::get_next() {
    return _next;
}

/**
    Set the next pointer to the given node.

    @param The next given node's pointer.
*/
template <class T>
void Node<T>::set_next(Node<T> *next) {
    _next = next;
}

template class Node<int>;
