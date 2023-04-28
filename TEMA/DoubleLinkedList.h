#pragma once
#include "Node.h"
#include <iostream>

template<typename T>
class DoubleLinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
    int count;

public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    void PushOnFront(const T& v);
    void PushOnBack(const T& v);
    T PopFromBack();
    int GetCount();
    void PrintAll(void (*printFunc)(const T&));
};

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() : head(nullptr), tail(nullptr), count(0) {}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
    while (head)
    {
        Node<T>* tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = nullptr;
    count = 0;
}

template<typename T>
void DoubleLinkedList<T>::PushOnFront(const T& v)
{
    Node<T>* newNode = new Node<T>(v);
    if (head == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    count++;
}

template<typename T>
void DoubleLinkedList<T>::PushOnBack(const T& v)
{
    Node<T>* newNode = new Node<T>(v);
    if (tail == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    count++;
}

template<typename T>
T DoubleLinkedList<T>::PopFromBack()
{
    if (tail == nullptr)
    {
        throw std::out_of_range("List is empty");
    }

    T result = tail->value;

    if (tail == head)
    {
        delete tail;
        tail = head = nullptr;
    }
    else
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }

    count--;
    return result;
}

template<typename T>
int DoubleLinkedList<T>::GetCount()
{
    return count;
}

template<typename T>
void DoubleLinkedList<T>::PrintAll(void (*printFunc)(const T&))
{
    std::cout << "Elements: " << count << " => ";

    Node<T>* current = head;
    while (current)
    {
        (*printFunc)(current->value);
        current = current->next;
    }

    std::cout << std::endl;
}
