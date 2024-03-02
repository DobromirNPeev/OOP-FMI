#include "Flight.h"
unsigned Flight::idCount = 0;

static bool isLower(char ch)
{
	return ch >= 'a' && ch <= 'z';
}
static bool isCapital(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}


bool Flight::isValidString(const MyString& str) {
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isLower(str[i]) || !isCapital(str[i]) || str[i] != ' ') {
			return false;
		}
	}
	return true;
}

Flight::Flight(const MyString& departLoc, const MyString& dest, double price, unsigned departHour):id(idCount++) {
	if (!isValidString(departLoc) || !isValidString(dest) || departHour>=24 || price<0) {
		throw std::invalid_argument("Invalid argument");
	}
	this->departLoc = departLoc;
	this->dest = dest;
	this->departHour = departHour;
	this->price = price;
}

std::ostream& operator<<(std::ostream& os,const Flight& flight) {
	std::cout << "Departing location: ";
	os << flight.departLoc;
	std::cout << std::endl;
	std::cout << "Destination: ";
	os << flight.dest;
	std::cout << std::endl;
	std::cout << "Depart hour:";
	os << flight.departHour;
	std::cout << std::endl;
	std::cout << "Price: ";
	os << flight.price;
	std::cout << std::endl;
	return os;
}
unsigned Flight::getID() const {
	return id;
}
unsigned Flight::getHour() const {
	return departHour;
}

std::istream& operator>>(std::istream& is, Flight& flight) {
	std::cout << "Departing location: ";
	is >> flight.departLoc;
	std::cout << "Destination: ";
	is >> flight.dest;
	std::cout << "Depart hour:";
	is >> flight.departHour;
	std::cout << "Price: ";
	is >> flight.price;
	return is;
}