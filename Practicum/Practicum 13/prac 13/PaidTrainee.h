#pragma once
#include "Trainee.h"
#include "Worker.h"

class PaidTrainee :public Trainee, public Worker
{
	unsigned rating=0;
public:
	PaidTrainee() = default;
	PaidTrainee(const MyString& name, unsigned age, double salary, unsigned monthsWorked, unsigned daysLeft, unsigned left);
	Employee* clone() const override;
	friend std::istream& operator>>(std::istream& is, PaidTrainee& emp);
	friend std::ostream& operator<<(std::ostream& os, const PaidTrainee& emp);
};
std::istream& operator>>(std::istream& is, PaidTrainee& emp);
std::ostream& operator<<(std::ostream& os, const PaidTrainee& emp);

