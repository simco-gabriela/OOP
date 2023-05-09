#pragma once
class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template <class T>
class Compare_Int : public Compare {
    int CompareElements(void* e1, void* e2) override {
        return *(T*)e1 > *(T*)e2;
    }
};