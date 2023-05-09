#pragma once
template <class T>
class ArrayIterator

{
private:
    int Current; // mai adaugati si alte date si functii necesare pentru iterator
    T* ptr;
public:
    ArrayIterator() {
        Current = 0;
        //ptr = List[0];
    }

    ArrayIterator& operator++() {
        Current++;
        // ptr += sizeof(List[0]);
        return *this;
    }

    ArrayIterator& operator--() {
        Current--;
        //ptr -= sizeof(List[0]);
        return *this;
    }

    bool operator=(ArrayIterator<T>& it) {
        return (ptr == it.ptr);
    }


    bool operator!=(ArrayIterator<T>& it) {
        return (ptr != it.ptr);
    }

    T* GetElement() {
        //return List[Current];
    }
};