#pragma once
#include "MyString.h"
class Flight
{
	static unsigned idCount;
	unsigned id;
	MyString departLoc="";
	MyString dest="";
	double price=0;
	unsigned departHour=0;

	bool isValidString(const MyString& str);
public:
	Flight() = default;
	Flight(const MyString& departLoc, const MyString& dest, double price, unsigned departHour);
	friend std::istream& operator>>(std::istream& is, Flight& flight);
	friend std::ostream& operator<<(std::ostream& os, const Flight& flight);

	unsigned getID() const;
	unsigned getHour() const;
};
std::istream& operator>>(std::istream& is, Flight& flight);
std::ostream& operator<<(std::ostream& os, const Flight& flight);


