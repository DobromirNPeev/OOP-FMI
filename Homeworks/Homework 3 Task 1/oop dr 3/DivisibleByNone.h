#pragma once
#include "Vector.hpp"

class  DivisableByNone {
    Vector<int> numbers;
public:
    DivisableByNone(const Vector<int>& numbers);
    bool contains(int el) const;
    bool operator()(int number) const;
};
