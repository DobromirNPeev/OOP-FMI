#pragma once
#include "Accumulator.h"
#include "Engine.h"
#include "FuelTank.h"
#include"Tyre.h"

static const double dist= 0.4;
class Car
{
	FuelTank tank;
	Engine eng;
	Tyre tyres[4];
	Accumulator acc;
	double kmDriven=0;
	double weight=0;
public:
	Car(const FuelTank& tank, const Engine& eng, const Tyre* tyres, const Accumulator& acc, double weight);
	FuelTank& getTank();
	void drive(double km);
	friend Car* dragRace(Car* car1, Car* car2);
	friend std::ostream& operator<<(std::ostream& os, const Car& car);
};
std::ostream& operator<<(std::ostream& os, const Car& car);
Car* dragRace(Car* car1, Car* car2);

