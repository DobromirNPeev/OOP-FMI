#include "Intersection.h"

Intersection::Intersection(const SetCollection& sets)
{
    this->sets = sets;
}
Set* Intersection::clone() const
{
    Set* newObj = new Intersection(*this);
    return newObj;
}

Intersection::Intersection(const Intersection& other)
{
    numbers = other.numbers;
}


bool Intersection::contains(int el) const {
    bool inAll = false;
    for (size_t i = 0; i < sets.getSize(); i++)
    {
        if ((*sets[i]).contains(el)) {
            inAll = true;
        }
        else {
            return false;
        }
    }
    return inAll;
}

