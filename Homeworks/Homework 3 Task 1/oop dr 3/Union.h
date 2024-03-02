#pragma once
#include "SetCollection.h"
class Union: public Set
{
	SetCollection sets;
public:
	Union()=default;
	Union(const SetCollection& sets);
	Union(const Union& other);
	bool contains(int el) const override;
	Set* clone() const override;
	~Union() = default;

};
