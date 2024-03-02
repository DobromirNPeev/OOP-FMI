#include "SoftwareEngineer.h"
#include <iostream>

void SoftwareEngineer::copyName(const char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void SoftwareEngineer::copyPosition(const char* position) {
	this->position = new char[strlen(position) + 1];
	strcpy(this->position, position);
}

void SoftwareEngineer::copyFrom(const SoftwareEngineer& other) {
	copyName(other.name);
	copyPosition(other.position);
	this->salary = other.salary;
}

SoftwareEngineer::SoftwareEngineer(const char* playerName, const char* playerPosition,unsigned salary) {
	setName(playerName);
	setPosition(playerPosition);
	setSalary(salary);
}

void SoftwareEngineer::free() {
	delete[] name;
	delete[] position;
	name = position = nullptr;
}
SoftwareEngineer::SoftwareEngineer() {
	this->name = new char[1];
	name[0] = '\0';
	this->position = new char[1];
	position[0] = '\0';
	salary = 0;
}
SoftwareEngineer::SoftwareEngineer(const SoftwareEngineer& other) {
	copyFrom(other);
}
SoftwareEngineer::~SoftwareEngineer() {
	free();
}
SoftwareEngineer& SoftwareEngineer::operator=(const SoftwareEngineer& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

const char* SoftwareEngineer::getName() const {
	return name;
}
const char* SoftwareEngineer::getPosition() const {
	return position;
}

unsigned SoftwareEngineer::getSalary() const
{
	return salary;
}

void SoftwareEngineer::setName(const char* name){
	if (name == nullptr || this->name == name)
		return;

	delete[] this->name;
	size_t nameLen = strlen(name);
	this->name = new char[nameLen + 1];
	strcpy(this->name, name);
}
void SoftwareEngineer::setPosition(const char* position){
	if (position == nullptr || this->position == position)
		return;

	delete[] this->position;
	size_t positionLen = strlen(position);
	this->position = new char[positionLen + 1];
	strcpy(this->position, position);
}

void SoftwareEngineer::setSalary(unsigned salary)
{
	this->salary = salary;
}

void SoftwareEngineer::print() const
{
	std::cout << name << std::endl;
	std::cout << position << std::endl;
}
