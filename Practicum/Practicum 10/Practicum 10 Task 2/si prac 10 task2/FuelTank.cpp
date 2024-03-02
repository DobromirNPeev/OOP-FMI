#include "FuelTank.h"


FuelTank::FuelTank(double capacity,  const char* manufacturer, const char* desc):CarPart(manufacturer,desc),capacity(capacity),fullness(capacity) {
};

void FuelTank::useFuel(double fuel) {
	if (fullness - fuel < 0) {
		throw insufficient_fuel_error("Overusage of fuel");
	}
	fullness -= fuel;
}
void FuelTank::loadFuel(double fuel) {
	if (fullness + fuel>capacity) {
		fullness = capacity;
	}
	else {
		fullness += fuel;
	}
}

double FuelTank::getFullness() const
{
	return fullness;
}
