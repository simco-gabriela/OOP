#include "Sort.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    Sort sort1(5, 0, 100);
    cout << "Lista originala:\n";
    sort1.Print();

    sort1.InsertSort();
    cout << "Lista sortata(descendent):\n";
    sort1.Print();

    Sort sort2 {7, 1, 5, 3, 6, 2, 4};
    cout << "Original list:\n";
    sort2.Print();

    sort2.QuickSort(false);
    cout << "Lista sortata (descendent):\n";
    sort2.Print();

    int arr[] = {9, 7, 5, 3, 1, 2, 4, 6, 8, 10};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    Sort sort4(6, 8, 5, 2, 9, 3, 7);
    cout << "Lista originala:\n";
    sort4.Print();
    sort4.QuickSort(false);
    cout << "Lista sortata (descendent):\n";
    sort4.Print();

    Sort sort5("10, 40, 100, 5, 70");
    cout << "Lista originala:\n";
    sort5.Print();
    sort5.BubbleSort(true);
    cout << "Lista sortata (ascendent):\n";
    sort5.Print();

return 0;
}
