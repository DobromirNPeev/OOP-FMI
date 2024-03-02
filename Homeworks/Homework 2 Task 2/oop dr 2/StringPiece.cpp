#include "StringPiece.h"


bool isValidValue(const char* value) {

	return strlen(value) > StringPiece::size;
}

StringPiece::StringPiece() :piece(""), length(0),begin(piece),end(piece) {};
StringPiece::StringPiece(const char* value) {
	setValue(value);

}

MyString StringPiece::getValue() const {
	MyString str(length + 1);
	const char* iter = begin;
	for (size_t i = 0; i < length; i++)
	{
		if (iter == piece + StringPiece::size) {
			iter -= StringPiece::size;
		}
		str[i] = *iter++;
	}
	str[length] = '\0';
	return str;
}


size_t StringPiece::getLength() const {
	return length;
}

void StringPiece::setValue(const char* value) {
		if (isValidValue(value))
			throw std::length_error("String longer the expected");
		length = strlen(value);
		begin = piece;
		for (size_t i = 0; i < length; i++)
		{
			*begin++ = value[i];
		}
		begin -= length;
		end = begin + length;
}
void concatOnTheLeft(const char* value, StringPiece& piece) {
	size_t valueLength = strlen(value);
	piece.length += valueLength;
	if (piece.begin == piece.piece) {
		piece.begin = piece.piece + StringPiece::size - valueLength;
	}
	else {
		piece.begin -= valueLength;
	}
	char* beginSave = piece.begin;
	for (size_t i = 0; i < valueLength; i++)
	{
		*(piece.begin++) = value[i];
	}
	piece.begin = beginSave;
}
void operator>>(const char* value, StringPiece& piece){
	if (strlen(value) + piece.length > StringPiece::size)
			throw std::length_error("StringPiece gets too long");
	concatOnTheLeft(value, piece);
}


void operator>>(int value, StringPiece& piece) {
	if (getNumberLength(value) + piece.length > StringPiece::size)
		throw std::length_error("StringPiece gets too long");
	char numberAsStr[StringPiece::size];
	toString(value, numberAsStr);
	concatOnTheLeft(numberAsStr, piece);
}
void concatOnTheRight(const char* value, StringPiece& piece) {
	size_t valueLength = strlen(value);
	piece.length += valueLength;
	for (size_t i = 0; i < valueLength; i++)
	{
		*(piece.end++) = value[i];
	}
}
void operator<<(StringPiece& piece, const char* value) {
	if (strlen(value) + piece.length > StringPiece::size)
		throw std::length_error("StringPiece gets too long");
	concatOnTheRight(value, piece);
}
void operator<<(StringPiece& piece, int value) {
		if (getNumberLength(value) + piece.length > StringPiece::size)
			throw std::length_error("StringPiece gets too long");
	char numberAsStr[StringPiece::size];
	toString(value, numberAsStr);
	concatOnTheRight(numberAsStr, piece);
}

void StringPiece::removeFirstKsymbols(unsigned k) {
		if (k > length)
			throw std::out_of_range("Symbols to remove is/are more than symbols in piece");
	if (begin + k >= piece + StringPiece::size) {
		unsigned diff = piece + StringPiece::size - begin;
		begin = piece;
		begin += k-diff;
	}
	else {
		begin += k;
	}
	length -= k;
}
void StringPiece::removeLastKsymbols(unsigned k) {
		if (k > length)
			throw std::out_of_range("Symbols to remove is/are more than symbols in piece");
	if (end - k <= piece) {
		unsigned diff = piece + StringPiece::size - begin;
		end = piece+StringPiece::size;
		end -= diff;
	}
	else {
		end -= k;
	}
	length -= k;
}

void StringPiece::changeSymbol(unsigned index,char ch) {
		if (index > length)
			throw std::out_of_range("Index is bigger than size of piece");
	piece[index] = ch;
}