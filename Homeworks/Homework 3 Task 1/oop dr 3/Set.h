#pragma once
#include <iostream>
#include "Vector.hpp"

class Set
{
protected:
	Vector<int> numbers;

public:

	Set()=default;
	virtual ~Set()=default;

	Set(const Vector<int> other);
	size_t getSize() const;
	virtual bool contains(int) const=0;
	virtual Set* clone()  const = 0;
	const Vector<int>& getNumbers() const;
	friend std::ostream& operator<<(std::ostream& os, const Set& set);
};
std::ostream& operator<<(std::ostream& os, const Set& set);
