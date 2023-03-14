#include "Sort.h"
#include <algorithm>
#include <stdarg.h>
#include <iostream>
#include <sstream>
#include <time.h>

using namespace std;

Sort::Sort() {}

Sort::Sort(int count, int min, int max) {
    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        int value = rand() % (max - min + 1) + min;
        elements.push_back(value);
    }
}

Sort::Sort(initializer_list<int> ilist) {
    for (int x : ilist) {
        elements.push_back(x);
    }
}

Sort::Sort(vector<int>& vec, int count) {
    for (int i = 0; i < count; i++) {
        elements.push_back(vec[i]);
    }
}

Sort::Sort(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        int value = va_arg(args, int);
        elements.push_back(value);
    }
    va_end(args);
}

Sort::Sort(string str) {
    stringstream ss(str);
    int value;
    char delimiter;
    while (ss >> value) {
        elements.push_back(value);
        ss >> delimiter;
    }
}

void Sort::InsertSort(bool ascendent) {
    int n = elements.size();
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && (ascendent ? elements[j - 1] > elements[j] : elements[j - 1] < elements[j])) {
            swap(elements[j], elements[j - 1]);
            j--;
        }
    }
}

void Sort::QuickSort(bool ascendent) {
    quickSortHelper(0, elements.size() - 1, ascendent);
}

void Sort::quickSortHelper(int low, int high, bool ascendent) {
    if (low < high) {
        int p = partition(low, high, ascendent);
        quickSortHelper(low, p - 1, ascendent);
        quickSortHelper(p + 1, high, ascendent);
    }
}

int Sort::partition(int low, int high, bool ascendent) {
    int pivot = elements[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (ascendent ? elements[j] < pivot : elements[j] > pivot) {
            i++;
            swap(elements[i], elements[j]);
        }
    }
    swap(elements[i + 1], elements[high]);
    return i + 1;
}

void Sort::BubbleSort(bool ascendent) {
int n = elements.size();
for (int i = 0; i < n - 1; i++) {
for (int j = 0; j < n - i - 1; j++) {
if (ascendent ? elements[j] > elements[j + 1] : elements[j] < elements[j + 1]) {
swap(elements[j], elements[j + 1]);
}
}
}
}

void Sort::Print() {
for (int x : elements) {
cout << x << " ";
}
cout << endl;
}

int Sort::GetElementsCount() {
return elements.size();
}

int Sort::GetElementFromIndex(int index) {
if (index < 0 || index >= elements.size()) {
return -1;
}
return elements[index];
}

