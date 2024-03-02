#include "Worker.h"

Worker::Worker(const MyString& name, unsigned age, double salary, unsigned monthsWorked) :Employee(name, age, salary), monthsWorked(monthsWorked) {};

Worker::Worker(unsigned monthsWorked) :monthsWorked(monthsWorked) {}
Employee* Worker::clone() const
{
	return new Worker(*this);
}
;

std::istream& operator>>(std::istream& is, Worker& emp) {
	std::cout << "Name: ";
	is >> emp.name;
	std::cout << "Age: ";
	is >> emp.age;
	std::cout << "Salary: ";
	is >> emp.salary;
	std::cout << "Months worked: ";
	is >> emp.monthsWorked;
	return is;
}
std::ostream& operator<<(std::ostream& os, const Worker& emp) {
	os << emp.name << " " << emp.salary << " " << emp.age<<" "<<emp.monthsWorked;
	return os;
}
