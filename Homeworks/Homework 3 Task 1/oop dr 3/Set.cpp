#include "Set.h"


std::ostream& operator<<(std::ostream& os, const Set& set){
	    for (size_t i = 0; i < set.getSize(); i++)
	    {

			std::cout << set.numbers[i] << " ";
	    }
	    std::cout << std::endl;
	    return os;
}

Set::Set(const Vector<int> other):numbers(other)
{
}

size_t Set::getSize() const
{
	return numbers.getSize();
}

const Vector<int>& Set::getNumbers() const
{
	return numbers;
}
