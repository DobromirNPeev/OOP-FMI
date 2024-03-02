#pragma once
#include <iostream>
#pragma warning(disable: 4996)

class SoftwareEngineer
{
	char* name;
	char* position;
	unsigned salary;

	void copyFrom(const SoftwareEngineer& other);
	void copyName(const char* name);
	void copyPosition(const char* position);
	void free();
public:
	//The Big Four
	SoftwareEngineer();
	SoftwareEngineer(const SoftwareEngineer& other);
	SoftwareEngineer& operator=(const SoftwareEngineer& other);
	~SoftwareEngineer();
	SoftwareEngineer(const char* playerName, const char* playerPosition,unsigned salary);

	const char* getName() const;
	const char* getPosition() const;
	unsigned getSalary() const;

	void setName(const char* name);
	void setPosition(const char* position);
	void setSalary(unsigned);

	void print() const;
};

