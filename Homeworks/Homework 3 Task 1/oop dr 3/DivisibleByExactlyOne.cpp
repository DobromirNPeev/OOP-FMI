#include "DivisibleByExactlyOne.h"
DivisibleByExactlyOne::DivisibleByExactlyOne(const Vector<int>& numbers) :numbers(numbers) {};
bool DivisibleByExactlyOne::contains(int el) const {
    int count = 0;
    for (size_t i = 0; i < numbers.getSize(); i++)
    {
        if (numbers[i] == 0) {
            continue;
        }
        else if (el % numbers[i] == 0) {
            count++;
        }

    }
    return count == 1;
}
bool DivisibleByExactlyOne::operator()(int number) const {
    return contains(number);
}