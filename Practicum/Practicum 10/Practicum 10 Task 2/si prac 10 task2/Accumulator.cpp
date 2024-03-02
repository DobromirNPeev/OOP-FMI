#include "Accumulator.h"

Accumulator::Accumulator(size_t capacity, const char* batteryId, const char* manufacturer, const char* desc) :capacity(capacity), CarPart(manufacturer, desc) {
	this->batterryId = new char[strlen(batteryId)+1];
	strcpy(this->batterryId, batteryId);
}
std::ostream& operator<<(std::ostream& os, const Accumulator& acc) {
	os << (const CarPart&)acc << acc.capacity << " Ah" << std::endl;
	return os;
}