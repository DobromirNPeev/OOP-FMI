#pragma once
#include "Set.h"

class SetCollection
{
	Set** sets;
	size_t size;
	size_t capacity;

	void free();
	void copyFrom(const SetCollection& other);
	void moveFrom(SetCollection&& other);
	void resize();
public:
	SetCollection();
	SetCollection(const SetCollection& other);
	SetCollection& operator=(const SetCollection& other);
	~SetCollection();

	SetCollection(SetCollection&& other);
	SetCollection& operator=(SetCollection&& other);
	size_t getSize() const;
	void addSet(const Set& setType);
	void addSet(Set&& setType);
	const Set* operator[](int ind) const;
	Set* operator[](int ind);
};

