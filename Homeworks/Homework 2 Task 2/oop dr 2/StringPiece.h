#pragma once
#include <iostream>
#include "MyString.h"
#include "NumbertToString.h"
#pragma warning(disable: 4996)


class StringPiece
{
	static const size_t size=16;
	char piece[size];
	mutable char* begin;
	mutable char* end;
	size_t length;
	friend void concatOnTheLeft(const char* value, StringPiece& piece);
	friend void concatOnTheRight(const char* value, StringPiece& piece);
	friend bool isValidValue(const char* value);

public:

	StringPiece();
	StringPiece(const char* value);

	MyString getValue() const;

	size_t getLength() const;
	friend void operator>>(const char* value, StringPiece& piece);
	friend void operator>>(int value, StringPiece& piece);
	friend void operator<<(StringPiece& piece, const char* value);
	friend void operator<<(StringPiece& piece, int value);

	void setValue(const char* value);
	void removeFirstKsymbols(unsigned k);
	void removeLastKsymbols(unsigned k);
	void changeSymbol(unsigned index,char ch);
};

void operator>>(const char* value, StringPiece& piece);
void operator>>(int value, StringPiece& piece);
void operator<<(StringPiece& piece, const char* value);
void operator<<(StringPiece& piece, int value);
void concatOnTheLeft(const char* value, StringPiece& piece);
void concatOnTheRight(const char* value, StringPiece& piece);
bool isValidValue(const char* value);
