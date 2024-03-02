#include "DivisibleByNone.h"
DivisableByNone::DivisableByNone(const Vector<int>& numbers): numbers(numbers) {};
bool DivisableByNone::contains(int el) const {
    for (size_t i = 0; i < numbers.getSize(); i++)
    {
        if (numbers[i] == 0) {
            continue;
        }
        else if (el % numbers[i] == 0) {
            return false;
        }
    }
    return true;
}
bool DivisableByNone::operator()(int number) const {
    return contains(number);
}
