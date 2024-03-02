#pragma once
#include <iostream>
#include "SmallStringOptimization.h"
#pragma warning  (disable:4996)

class MyString
{
	SmallStringOptimization sso;
	static const size_t capacity = sizeof(char*);

	void copyFrom(const MyString& other);
	void free();

	explicit MyString(size_t capacity); //for memory allocation. How much bytes to allocate
	void getSubStr(size_t howMany, char* data, size_t begin) const;
public:

	MyString();
	MyString(const char* data);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();
	size_t length() const;
	MyString& operator+=(const MyString& other);

	MyString substr(size_t begin, size_t howMany) const;

	char& operator[](size_t index);
	char operator[](size_t index) const;

	const char* c_str() const;

	friend MyString operator+(const MyString& lhs, const MyString& rhs);
	friend std::istream& operator>>(std::istream&, MyString& str);
	friend bool isSmall(size_t size);
};

MyString operator+(const MyString& lhs, const MyString& rhs);

std::ostream& operator<<(std::ostream& os, const MyString& str);

std::istream& operator>>(std::istream& os, MyString& str);

bool operator<(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);
bool isSmall(size_t size);