#include "Employee.h"

Employee::Employee(const MyString& name, unsigned age, double salary):name(name),age(age),salary(salary)
{
}

double Employee::getSalary() const
{
	return salary;
}

std::istream& operator>>(std::istream& is, Employee& emp) {
	std::cout << "Name: ";
	is >> emp.name;
	std::cout << "Age: ";
	is >> emp.age;
	std::cout << "Salary: ";
	is >> emp.salary;
	return is;
}
std::ostream& operator<<(std::ostream& os, const Employee& emp) {
	os << emp.name << " " << emp.salary << " " << emp.age;
	return os;
}
