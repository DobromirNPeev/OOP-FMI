#include "FlightsSystem.h"

void FlightsSystem::free() {
	
	for (size_t i = 0; i < size; i++)
	{
		delete flights[i];
	}
	delete[] flights;
}
void FlightsSystem::copyFrom(const FlightsSystem& other) {
	size = other.size;
	capacity = other.capacity;

	flights = new Flight*[capacity];
	for (int i = 0; i < size; i++)
	{
		if (other.flights[i] == nullptr)
			flights[i] = nullptr;
		else
			flights[i] = new Flight(*other.flights[i]);
	}
}

void FlightsSystem::resize(size_t newCap) {
	Flight** newDataPtr = new Flight * [newCap] {nullptr};

	for (int i = 0; i < size; i++)
		newDataPtr[i] = flights[i];

	delete[] flights;
	flights = newDataPtr;

	capacity = newCap;
}


FlightsSystem::FlightsSystem() {

	capacity = 8;
	flights = new Flight*[capacity] {nullptr};
}
FlightsSystem::FlightsSystem(const FlightsSystem& other) {
	copyFrom(other);

}
FlightsSystem& FlightsSystem::operator=(const FlightsSystem& other) {
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
FlightsSystem::~FlightsSystem() {
	free();
}

void FlightsSystem::pushBack(const Flight& current) {
	if (size >= capacity)
		resize(capacity * 2);

	flights[size++] = new Flight(current);
}
void FlightsSystem::popBack() {
	if (size == 0)
		return;

	delete flights[size - 1];
	size--;
}

const Flight& FlightsSystem::findFlight(unsigned id) const {
	for (size_t i = 0; i < size; i++)
	{
		if (flights[i]->getID() == id) {
			return *flights[i];
		}
	}
	throw std::invalid_argument("Invalid id");
}
void FlightsSystem::printFlighs() const {
	for (size_t i = 0; i < size; i++)
	{
		std::cout << *flights[i];
	}
}
void FlightsSystem::addFlight() {
	Flight newFlight;
	std::cin >> newFlight;
	flights[size++] = new Flight(newFlight);
	for (size_t i = 0; i < size- 1; i++) {
		size_t minIndex = i;

		// first i numbers are already ordered
		for (size_t j = i + 1; j < size; j++) {
			if (flights[minIndex]->getHour() > flights[j]->getHour()) {
				minIndex = j;
			}
		}

		if (minIndex != i) { // if minIndex changed - swap
			std::swap(flights[i], flights[minIndex]);
		}
	}
	//currentIndex + 1 е позицията

	//if (currentIndex + 1 > 0 && lastStrcmpRes == 0)
	//{
	//	flights[currentIndex + 1] = flights[currentIndex];
	//}
	//else
	//{
	//	flights[currentIndex + 1] = new Flight(newFlight);
	//}
	//data[currentIndex + 1]->incrementRefCount();

	//size++;
	
}
void FlightsSystem::removeAt(size_t index) {
	if (index >= size)
		return;

	delete flights[index];
	flights[index] = nullptr;
	size--;
}
void FlightsSystem::setAt(const Flight& obj, size_t index) {
	if (flights[index] != nullptr)
		*flights[index] = obj;
	else
	{
		flights[index] = new Flight(obj);
		size++;
	}
}

size_t FlightsSystem::getSize() const {
	return size;
}
const Flight& FlightsSystem::operator[](size_t index) const {
	return *flights[index];
}
Flight& FlightsSystem::operator[](size_t index) {
	return *flights[index];
}