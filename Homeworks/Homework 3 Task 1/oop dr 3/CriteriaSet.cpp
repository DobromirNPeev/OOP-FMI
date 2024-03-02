#include "CriteriaSet.h"


CriteriaSet::CriteriaSet(bool (*func)(int)) :pred(func) {};

bool CriteriaSet::contains(int el) const {
	if (pred == nullptr) {
		return ((*predicate)(el));
	}
	else {
		return pred(el);
	}
}
CriteriaSet::CriteriaSet(const CriteriaSet& other) {
	numbers = other.numbers;
	predicate = other.predicate;
	pred = other.pred;
}
Set* CriteriaSet::clone()  const {
	Set* newObj = new CriteriaSet(*this);
	return newObj;
}