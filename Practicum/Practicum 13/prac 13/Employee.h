#pragma once
#include "MyString.h"

class Employee
{
protected:
	MyString name="";
	unsigned age=0;
	double salary=0;
public:
	Employee() = default;
	Employee(const MyString& name, unsigned age, double salary);
	virtual ~Employee()=default;
	virtual Employee* clone() const = 0;
	double getSalary() const;
	friend std::istream& operator>>(std::istream& is, Employee& emp);
	friend std::ostream& operator<<(std::ostream& os, const Employee& emp);

};
std::istream& operator>>(std::istream& is, Employee& emp);
std::ostream& operator<<(std::ostream& os,const Employee& emp);
