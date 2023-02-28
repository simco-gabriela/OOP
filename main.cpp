#include <iostream>
#include "NumberList.h"

using namespace std;
int main()
{
    NumberList list;

    list.Init();
int n;
 for(int i=0;i<10;i++)
 {
     cin>>n;
     list.Add(n);
 }

    list.Print();

    list.Sort();

    list.Print();

    return 0;
}
