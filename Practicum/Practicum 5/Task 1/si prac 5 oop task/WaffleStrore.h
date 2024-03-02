#pragma once
#include "Waffle.h"
#include <iostream>
#pragma warning (disable:4996)

const unsigned MAXSIZEOFSTORE = 20;

class WaffleStore {
	Waffle waffles[MAXSIZEOFSTORE];
	size_t size = 0;
	double earnings = 0.0;
	double spending = 0.0;
public:
	WaffleStore() {

	}
	void setWaffleStore(unsigned n, const char* waffleName);
	size_t getWaffleSize(const char* waffleName);
	double Balance();
	void sellWaffle(const char* waffleName);
};