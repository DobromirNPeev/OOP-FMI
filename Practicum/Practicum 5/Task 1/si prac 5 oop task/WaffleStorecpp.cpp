#include "WaffleStrore.h"

void WaffleStore::setWaffleStore(unsigned n, const char* waffleName) {
	for (size_t i = 0; i < size; i++)
	{
		if (!strcmp(waffles[i].getWaffleName(), waffleName)) {
			for (size_t j = 0; j < n; j++)
			{
				spending += waffles[i].getPriceForBusiness();
			}
			size++;
			return;
		}
	}
}
size_t WaffleStore::getWaffleSize(const char* waffleName) {
	size_t count = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (!strcmp(waffles[i].getWaffleName(), waffleName)) {
			count++;
		}
	}
	return count;
}
double WaffleStore::Balance() {
	return earnings - spending;
}
void WaffleStore::sellWaffle(const char* waffleName) {
	size_t waffleCount = getWaffleSize(waffleName);
	for (size_t i = 0; i < size; i++)
	{
		if (!strcmp(waffles[i].getWaffleName(), waffleName)) {
			earnings += waffles[i].getPriceForClient();
			std::swap(waffles[i], waffles[size - 1]);
			size--;
			return;
		}
	}
}