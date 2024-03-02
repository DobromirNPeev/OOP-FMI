#pragma once
#include "Vector.hpp"

class DivisibleByExactlyOne {
    Vector<int> numbers;
public:
    DivisibleByExactlyOne(const Vector<int>& numbers);
    bool contains(int el) const;
    bool operator()(int number) const;
};