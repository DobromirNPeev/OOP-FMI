#include "Car.h"

Car::Car(const FuelTank& tank, const Engine& eng, const Tyre* tyres, const Accumulator& acc, double weight) :tank(tank), eng(eng), acc(acc), weight(weight) {
	for (size_t i = 0; i < 4; i++)
	{
		this->tyres[i] = tyres[i];
	}
}

FuelTank& Car::getTank()
{
	return tank;
}
std::ostream& operator<<(std::ostream& os, const Car& car) {
	os << car.acc << car.eng;
	for (size_t i = 0; i < 4; i++)
	{
		os<<car.tyres[i];
	}
	os << car.kmDriven << " " << car.weight;
	return os;
}

void Car::drive(double km) {
	if (tank.getFullness() - km<0) {
		return;
	}
	tank.useFuel(km);
	kmDriven += km;
}
Car* dragRace(Car* car1, Car* car2) {
	if (car1->tank.getFullness() - dist < 0 && car2->tank.getFullness() - dist < 0) {
		return nullptr;
	}
	else if (car1->tank.getFullness() - dist<0) {
		return car2;
	}
	else if (car2->tank.getFullness() - dist < 0) {
		return car1;
	}
	return car1->weight / car1->eng.getHorsePower() > car2->weight / car2->eng.getHorsePower() ? car1 : car2;

}