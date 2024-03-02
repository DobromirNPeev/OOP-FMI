#pragma once
#include "CarPart.h"
#include "insufficient_fuel_error.h"

class FuelTank: public CarPart
{
	double capacity;
	double fullness;
public:
	FuelTank(double capacity, const char* manufacturer, const char* desc);
	void useFuel(double fuel);
	void loadFuel(double fuel);
	double getFullness() const;
};

