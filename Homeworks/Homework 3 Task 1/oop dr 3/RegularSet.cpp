#include "RegularSet.h"

RegularSet::RegularSet(const RegularSet& other)
{
    numbers = other.numbers;
}

RegularSet::RegularSet(const Vector<int>& other)
{
    numbers = other;
}

bool RegularSet::contains(int el) const
{
    for (size_t i = 0; i < numbers.getSize(); i++)
    {
        if (numbers[i] == el) {
            return true;
        }
    }
    return false;
}

Set* RegularSet::clone() const
{
    return new RegularSet(*this);
}
