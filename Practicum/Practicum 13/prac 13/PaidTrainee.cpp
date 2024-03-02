#include "PaidTrainee.h"

PaidTrainee::PaidTrainee(const MyString& name, unsigned age, double salary, unsigned monthsWorked, unsigned daysLeft, unsigned left) :Employee(name, age, salary), Worker(monthsWorked), Trainee(daysLeft)
{
	if (rating > 100) {
		rating = 100;
	}
	this->rating = rating;
}
Employee* PaidTrainee::clone() const{
	return new PaidTrainee(*this);
}

std::istream& operator>>(std::istream& is, PaidTrainee& emp) {
	std::cout << "Name: ";
	is >> emp.name;
	std::cout << "Age: ";
	is >> emp.age;
	std::cout << "Salary: ";
	is >> emp.salary;
	std::cout << "Days left: ";
	is >> emp.daysLeft;
	std::cout << "Months worked: ";
	is >> emp.monthsWorked;
	std::cout << "Rating: ";
	is >> emp.rating;
	return is;
}
std::ostream& operator<<(std::ostream& os, const PaidTrainee& emp) {
	os << emp.name << " " << emp.salary << " " << emp.age << " " << emp.daysLeft << " " << emp.monthsWorked << " " << emp.rating;
	return os;
}