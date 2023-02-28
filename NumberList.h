#ifndef NUMBERLIST_H_INCLUDED
#define NUMBERLIST_H_INCLUDED
class NumberList
{
    int numbers[10];
    int count;

public:
    void Init();
    bool Add(int x);
    void Sort();
    void Print();
};



#endif // NUMBERLIST_H_INCLUDED
