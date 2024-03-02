#include "Engine.h"

Engine::Engine(size_t horsePower, const char* manufacturer, const char* desc) :horsePower(horsePower), CarPart(manufacturer, desc) {};

std::ostream& operator<<(std::ostream& os, const Engine& engine) {
	os << (const CarPart&)engine << engine.horsePower<<" hp" << std::endl;
	return os;
}
size_t Engine::getHorsePower() const {
	return horsePower;
}
