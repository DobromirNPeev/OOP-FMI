#include "Company.h"


void Company::free() {
	for (size_t i = 0; i < size; i++)
	{
		delete workers[i];
	}
	delete[] workers;
}
void Company::copyFrom(const Company& other) {
	size = other.size;
	capacity = other.capacity;
	workers = new Employee * [capacity];
	for (size_t i = 0; i < size; i++)
	{
		workers[i] = other.workers[i]->clone();
	}

}
void Company::moveFrom(Company&& other) {
	size = other.size;
	capacity = other.capacity;
	workers = other.workers;
	other.workers = nullptr;
	other.size = other.capacity = 0;
}
void Company::resize() {
	Employee** newWorkers = new Employee * [capacity *= 2];
	for (size_t i = 0; i < size; i++)
	{
		newWorkers[i] = workers[i];
	}
	delete[] workers;
	workers = newWorkers;
}

Company::Company() {
	capacity = 8;
	size = 0;
	workers = new Employee * [capacity];
}
Company::Company(const Company& other) {
	copyFrom(other);

}
Company& Company::operator=(const Company& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
Company::~Company() {
	free();
	}

Company::Company(Company&& other) {
	moveFrom(std::move(other));
	}
Company& Company::operator=(Company&& other) {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
	}
void Company::addWorker() {
	if (size >= capacity)
		resize();
	Worker newWorker;
	std::cin >> newWorker;
	std::cout << std::endl;
	workers[size++] = std::move(newWorker.clone());
	selectionSort();
}
void Company::addTrainee() {
	if (size >= capacity)
		resize();
	Trainee newTrainee;
	std::cin >> newTrainee;
	std::cout << std::endl;
	workers[size++] = std::move(newTrainee.clone());
	selectionSort();
}
void Company::addPaidTrainee() {
	if (size >= capacity)
		resize();
	PaidTrainee newPaidTrainee;
	std::cin >> newPaidTrainee;
	std::cout << std::endl;
	workers[size++] = std::move(newPaidTrainee.clone());
	selectionSort();

}
double Company::getAverageSalary() const {
	double sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		sum += workers[i]->getSalary();
	}
	return sum / size;
}

Employee** Company::getWorkers() const
{
	return workers;
}

bool Company::TwoSum(double val) const {
	for (size_t i = 0; i < size; i++)
	{
		//double sum = workers[i]->getSalary();
		for (size_t j = i+1; j < size; j++)
		{
			if ((workers[i]->getSalary() + workers[j]->getSalary()) - val < 0.00001) {
				return true;
			}
		}
	}
	return false;
}

void Company::selectionSort()
{
	for (size_t i = 0; i < size; i++)
	{
		int minInd = i;
		for (size_t j = i + 1; j < size; j++)
		{
			if (workers[minInd]->getSalary() > workers[j]->getSalary()) {
				minInd = j;
			}
		}
		if (minInd != i) {
			std::swap(workers[minInd], workers[i]);
		}
	}
}