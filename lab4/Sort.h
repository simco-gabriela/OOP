#ifndef SORT_H
#define SORT_H

#include <vector>
#include <string>

class Sort {
private:
    std::vector<int> elements;
    void quickSortHelper(int low, int high, bool ascendent);
    int partition(int low, int high, bool ascendent);


public:
    Sort();
    Sort(int count, int min, int max);
    Sort(std::initializer_list<int> ilist);
    Sort(std::vector<int>& vec, int count);
    Sort(int count, ...);
    Sort(std::string str);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};

#endif
