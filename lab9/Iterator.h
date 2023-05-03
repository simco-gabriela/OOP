#pragma once
template <class T1, class T2>
class Iterator {
public:
    T1* keys;
    T2* values;
    int index;
    Iterator& operator++() {
        keys++;
        values++;
        index++;
        return *this;
    }
    bool operator!=(Iterator& it) {
        return (keys != it.keys && values != it.values && index != it.index);
    }
    auto operator*() {
        return std::make_tuple(*keys, *values, index);
    }
};