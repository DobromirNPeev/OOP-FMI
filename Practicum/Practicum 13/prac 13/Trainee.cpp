#include "Trainee.h"

Trainee::Trainee(const MyString& name, unsigned age, double salary, unsigned daysLeft) :Employee(name, age, salary), daysLeft(daysLeft) {};

Trainee::Trainee(unsigned daysLeft) :daysLeft(daysLeft) {}
Employee* Trainee::clone() const
{
	return new Trainee(*this);
};

std::istream& operator>>(std::istream& is, Trainee& emp) {
	std::cout << "Name: ";
	is >> emp.name;
	std::cout << "Age: ";
	is >> emp.age;
	std::cout << "Salary: ";
	is >> emp.salary;
	std::cout << "Days left: ";
	is >> emp.daysLeft;
	return is;
}
std::ostream& operator<<(std::ostream& os, const Trainee& emp) {
	os << emp.name << " " << emp.salary << " " << emp.age << " " << emp.daysLeft;
	return os;
}

