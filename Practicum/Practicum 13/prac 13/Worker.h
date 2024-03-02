#pragma once
#include "Employee.h"
class Worker: virtual public Employee
{
protected:
	unsigned monthsWorked=0;
public:
	Worker() = default;
	Worker(const MyString& name, unsigned age, double salary, unsigned monthsWorked);
	Worker(unsigned monthsWorked);
	Employee* clone() const override;
	friend std::istream& operator>>(std::istream& is, Worker& emp);
	friend std::ostream& operator<<(std::ostream& os, const Worker& emp);
};
std::istream& operator>>(std::istream& is, Worker& emp);
std::ostream& operator<<(std::ostream& os, const Worker& emp);

