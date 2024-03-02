#pragma once
#include <iostream>
#pragma warning(disable: 4996);

class MyString
{
	char* _data;
	size_t _length;

	void copyFrom(const MyString& data);
	void free();

	 //for memory allocation. How much bytes to allocate
	MyString(size_t capacity);
public:

	MyString();
	MyString(const char* data);

	MyString(const MyString& other);
	MyString& operator=(const MyString& other);


	//move semantics on the next lecture
	//MyString(MyString&& other) = delete; 
	//MyString& operator=(MyString&& other) = delete; 
	///

	size_t length() const;
	MyString& operator+=(const MyString& other);

	MyString substr(size_t begin, size_t howMany) const;

	char& operator[](size_t index);
	char operator[](size_t index) const;
	~MyString();

	const char* c_str() const;

	friend MyString operator+(const MyString& lhs, const MyString& rhs);
	friend std::istream& operator>>(std::istream&, MyString& str);
	friend class StringPiece;
};
MyString operator+(const MyString& lhs, const MyString& rhs);

std::ostream& operator<<(std::ostream& os, const MyString& str);

std::istream& operator>>(std::istream& os, const MyString& str);

