#include "Union.h"


Set* Union::clone() const
{
	Set* newObj = new Union(*this);
	return newObj;
}

Union::Union(const SetCollection& sets)
{
	this->sets = sets;
}
Union::Union(const Union& other)
{
	numbers = other.numbers;
}

bool Union::contains(int el) const {
	for (size_t i = 0; i < sets.getSize(); i++)
	{
		if ((*sets[i]).contains(el)) {
			return  true;
		}
	}
	return false;
}
