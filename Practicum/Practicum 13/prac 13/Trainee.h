#pragma once
#include "Employee.h"
class Trainee :virtual public Employee
{
protected:
	unsigned daysLeft=0;
public:
	Trainee() = default;
	Trainee(const MyString& name, unsigned age, double salary, unsigned daysLeft);
	Trainee(unsigned daysLeft);
	Employee* clone() const override;
	friend std::istream& operator>>(std::istream& is, Trainee& emp);
	friend std::ostream& operator<<(std::ostream& os, const Trainee& emp);
};
std::istream& operator>>(std::istream& is, Trainee& emp);
std::ostream& operator<<(std::ostream& os, const Trainee& emp);
