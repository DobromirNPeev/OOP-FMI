#include "SetCollection.h"

void SetCollection::free() {
	for (size_t i = 0; i < size; i++)
	{
		delete sets[i];
	}
	delete[] sets;
}
void SetCollection::copyFrom(const SetCollection& other) {
	sets = new Set * [other.capacity];
	size = other.size;
	capacity = other.capacity;
	for (size_t i = 0; i < other.size; i++)
	{
		sets[i] = other.sets[i]->clone();
	}
}
void SetCollection::moveFrom(SetCollection&& other) {
	size= other.size;
	capacity = other.capacity;

	sets = other.sets;
	other.sets = nullptr;

	other.size = other.capacity = 0;
}

SetCollection::SetCollection(const SetCollection& other) {
	copyFrom(other);
}
SetCollection& SetCollection::operator=(const SetCollection& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
SetCollection::SetCollection() {
	capacity = 8;
	size = 0;
	sets = new Set * [capacity];
}
void SetCollection::resize() {
	Set** newCollection = new Set*[capacity *= 2];
	for (size_t i = 0; i < size; i++)
		newCollection[i] = sets[i];
	delete[] sets;
	sets = newCollection;
}
SetCollection::~SetCollection() {
	free();
}
SetCollection::SetCollection(SetCollection&& other){
	moveFrom(std::move(other));
}
SetCollection& SetCollection::operator=(SetCollection&& other) {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}
size_t SetCollection::getSize() const
{
	return size;
}
void SetCollection::addSet(const Set& setType) {
	if (size == capacity) {
		resize();
	}
	sets[size++] = setType.clone();
}


void SetCollection::addSet(Set&& setType)
{
	if (size == capacity) {
		resize();
	}
	sets[size++] = std::move(setType.clone());
}

const Set* SetCollection::operator[](int ind) const
{
	return sets[ind];
}

Set* SetCollection::operator[](int ind)
{
	return sets[ind];

}
