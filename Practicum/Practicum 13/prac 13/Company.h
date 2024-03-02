#pragma once
#include "Employee.h"
#include "Worker.h"
#include "Trainee.h"
#include "PaidTrainee.h"

class Company
{
	Employee** workers;
	size_t size;
	size_t capacity;

	void free();
	void copyFrom(const Company& other);
	void moveFrom(Company&& other);
	void resize();
	void selectionSort();
public:
	Company();
	Company(const Company& other);
	Company& operator=(const Company& other);
	~Company();

	Company(Company&& other);
	Company& operator=(Company&& other);

	void addWorker();
	void addTrainee();
	void addPaidTrainee();
	double getAverageSalary() const;
	Employee** getWorkers() const;
	bool TwoSum(double val) const;
};

