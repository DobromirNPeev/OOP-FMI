#pragma once
#include "Flight.h"

class FlightsSystem
{
	Flight** flights;
	size_t size=0;
	size_t capacity;


	void free();
	void copyFrom(const FlightsSystem& other);

	void resize(size_t newCap);

public:
	FlightsSystem();
	FlightsSystem(const FlightsSystem& other);
	FlightsSystem& operator=(const FlightsSystem& other);
	~FlightsSystem();

	void pushBack(const Flight& current);
	void popBack();
	void removeAt(size_t index);
	void setAt(const Flight& obj, size_t index);

	size_t getSize() const;
	const Flight& operator[](size_t index) const;
	Flight& operator[](size_t index);

	void addFlight();
	const Flight& findFlight(unsigned id) const;
	void printFlighs() const;
};

