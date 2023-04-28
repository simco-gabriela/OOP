#pragma once

template<typename T>
class Node
{
public:
    Node<T>* next;
    Node<T>* prev;
    T value;

    Node(const T& v) : value(v), next(nullptr), prev(nullptr) {}
};
