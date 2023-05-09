// lab10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Array.h"
#include "Array.cpp"
#include "Compare.h"

int main()
{
    Array<int> arr(10);
    for (int i = 0; i < 10; i++) {
        arr.Insert(i, i);
    }
    auto call = [](const int& x, const int& y) {
        return x < y;
    };

    arr.Sort(call);
    Compare* comp;
    comp = new Compare_Int<int>;
    arr.Sort(comp);
    std::cout << arr[0];

    return 0;
}