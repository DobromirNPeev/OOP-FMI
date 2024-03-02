#include "StringCreaterPieceByPiece.h"

void StringCreaterPieceByPiece::copyFrom(const StringCreaterPieceByPiece& other) {
	count = other.count;
	capacity = other.capacity;
	pieces = new StringPiece*[capacity];
	for (size_t i = 0; i < other.count; i++)
	{
		pieces[i] =new StringPiece(*(other.pieces[i]));
	}
}
void StringCreaterPieceByPiece::free() {
	for (size_t i = 0; i < count; i++)
	{
		delete pieces[i];
	}
	delete[] pieces;
	count = capacity = 0;
}
StringCreaterPieceByPiece::StringCreaterPieceByPiece():count(0), capacity(0), pieces (nullptr) {
};

StringCreaterPieceByPiece::StringCreaterPieceByPiece(size_t size):count(0),capacity(size) {
	pieces = new StringPiece*[capacity];
}
StringCreaterPieceByPiece::StringCreaterPieceByPiece(const StringCreaterPieceByPiece& other) {
	copyFrom(other);
}
StringCreaterPieceByPiece& StringCreaterPieceByPiece::operator=(const StringCreaterPieceByPiece& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
StringCreaterPieceByPiece::~StringCreaterPieceByPiece() {
	free();
}
void StringCreaterPieceByPiece::resize() {
	capacity *= 2;
	StringPiece** temp = new StringPiece*[capacity];
	for (size_t i = 0; i < count; i++) {
		temp[i] = pieces[i];
	}

	delete[] pieces;
	pieces = temp;
}
void StringCreaterPieceByPiece::addPiece(const char* value) {
		if (count >= capacity) {
			resize();
		}
		pieces[count++] = new StringPiece(value);
}
void StringCreaterPieceByPiece::addPiece() {
	if (count >= capacity) {
		resize();
	}
	pieces[count++]=new StringPiece();
}

void StringCreaterPieceByPiece::swap(size_t firstIndex, size_t secondIndex) {
	StringPiece* temp = pieces[firstIndex];
	pieces[firstIndex]= pieces[secondIndex];
	pieces[secondIndex] = temp;
}
void StringCreaterPieceByPiece::deleteByIndex(size_t index) {
	if (index >= count) {
		throw "Invalid index";
	}
	delete pieces[index];
	pieces[index]=nullptr;
}
void StringCreaterPieceByPiece::addPiece(size_t index, const char* value) {
	if (value == nullptr)
		throw "Invalid value";
	if (pieces[index] != nullptr) {
		delete pieces[index];
		pieces[index] = new StringPiece(value);
	}
	else {
		pieces[index] = new StringPiece(value);
	}
}

size_t StringCreaterPieceByPiece::getStringSize() {
	size_t len = 0;
	for (size_t i = 0; i < count; i++)
	{
		len +=pieces[i]->getLength();
	}
	return len;
}
void StringCreaterPieceByPiece::fillSpaces(MyString& str) {
	for (size_t i = 0; i < 21; i++)
	{
		str += " ";
	}
}
MyString StringCreaterPieceByPiece::getString() {
	MyString str;

	for (size_t i = 0; i < count; i++)
	{

		if (i == count - 2 && pieces[i] == nullptr) {
			fillSpaces(str);
		}
		else {

			str += pieces[i]->getValue();
		}
	}
	return str;
}
StringPiece& StringCreaterPieceByPiece::operator[](size_t index) {
	return *(pieces[index]);
}
