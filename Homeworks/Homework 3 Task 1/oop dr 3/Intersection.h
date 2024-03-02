#pragma once
#include "SetCollection.h"
class Intersection: public Set
{
	SetCollection sets;
public:
	Intersection() = default;
	Intersection(const SetCollection& sets);
	Intersection(const Intersection& other);
	bool contains(int) const override;
	Set* clone()  const override;
	~Intersection() = default;
};
