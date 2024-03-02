#pragma once
#include "Set.h"
class RegularSet :public Set
{
public:
	RegularSet(const RegularSet& other);
	RegularSet(const Vector<int>& other);
	bool contains(int el) const override;
	Set* clone()  const override;
};

