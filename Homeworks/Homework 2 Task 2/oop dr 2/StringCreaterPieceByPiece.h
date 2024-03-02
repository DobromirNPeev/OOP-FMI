#pragma once
#include "StringPiece.h"

class StringCreaterPieceByPiece
{
	StringPiece** pieces;
	size_t count;
	size_t capacity;

	void resize();
	void copyFrom(const StringCreaterPieceByPiece& other);
	void free();
public:
	StringCreaterPieceByPiece(size_t size);
	StringCreaterPieceByPiece();
	StringCreaterPieceByPiece(const StringCreaterPieceByPiece& other);
	StringCreaterPieceByPiece& operator=(const StringCreaterPieceByPiece& other);
	~StringCreaterPieceByPiece();

	void fillSpaces(MyString& str);
	void addPiece(const char* value);
	void addPiece();
	void addPiece(size_t index, const char* value);
	void swap(size_t firstIndex, size_t secondIndex);
	void deleteByIndex(size_t index);
	size_t getStringSize();
	MyString getString();
	StringPiece& operator[](size_t index);
};

