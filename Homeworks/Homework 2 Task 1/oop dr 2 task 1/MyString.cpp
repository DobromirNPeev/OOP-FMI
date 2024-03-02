#include "MyString.h"


bool isSmall(size_t size) {
	return size < MyString::capacity;
}

MyString::MyString(size_t capacity)
{
	sso.size = capacity - 1;
	if (!isSmall(capacity)) {
		sso.heapData = new char[capacity];
	}
	else {
		sso.data[0] = '\0';
	}
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString result(lhs.sso.size + rhs.sso.size + 1);

	result[0] = '\0';
	if (isSmall(lhs.sso.size + rhs.sso.size)) {
			strcat(result.sso.data, lhs.sso.data);
			strcat(result.sso.data, rhs.sso.data);
	}
	else {
		if (isSmall(lhs.sso.size) && isSmall(rhs.sso.size)) {
			strcat(result.sso.heapData, lhs.sso.data);
			strcat(result.sso.heapData, rhs.sso.data);
		}
		else if (!isSmall(lhs.sso.size) && isSmall(rhs.sso.size)) {
			strcat(result.sso.heapData, lhs.sso.heapData);
			strcat(result.sso.heapData, rhs.sso.data);
		}
		else {
			strcat(result.sso.heapData, lhs.sso.data);
			strcat(result.sso.heapData, rhs.sso.heapData);
		}
	}


	return result;
}

MyString& MyString::operator+=(const MyString& other)
{
	if (!isSmall(sso.size + other.sso.size)) {
		char* result = new char[sso.size+other.sso.size + 1];
		result[0] = '\0';
		if (isSmall(sso.size)) {
			strcat(result, sso.data);
		}
		else {
			strcat(result, sso.heapData);
		}
		if (isSmall(other.sso.size)) {
			strcat(result, other.sso.data);
		}
		else {
			strcat(result, other.sso.heapData);
		}
		if (!isSmall(sso.size)) {
			delete[] sso.heapData;
		}
		sso.size += other.sso.size;
		sso.heapData = result;
	}
	else {
		sso.size += other.sso.size;
		strcat(sso.data, other.sso.data);
	}
	return *this;
}

MyString::MyString() : MyString(1)
{
	sso.data[0] = '\0';
}

MyString::MyString(const char* data) : MyString(strlen(data) + 1)
{
	if (isSmall(sso.size)) {
		strcpy(sso.data, data);
	}
	else {
		strcpy(sso.heapData, data);
	}

}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}


void MyString::free()
{
	if (!isSmall(sso.size)) {
		delete[] sso.heapData;
		sso.heapData= nullptr;
	}
	else {
		sso.data[0] = '\0';
	}
	sso.size = 0;
}

MyString::~MyString()
{
	free();
}

size_t MyString::length() const
{
	return sso.size;
}

void MyString::copyFrom(const MyString& other)
{
	sso.size = other.sso.size;
	if (isSmall(sso.size)) {
		strcpy(sso.data, other.sso.data);
	}
	else {
		sso.heapData = new char[sso.size + 1];
		strcpy(sso.heapData, other.sso.heapData);
	}

}

char& MyString::operator[](size_t index) //Неконстантен достъп
{
	if (index > sso.size)
		throw std::out_of_range("Non-existing index");
	if (isSmall(sso.size)) {
		return sso.data[index];
	}
	return sso.heapData[index];
}

char MyString::operator[](size_t index) const //Константен достъп 
{
	if (index > sso.size)
		throw std::out_of_range("Non-existing index");
	if (isSmall(sso.size)) {
		return sso.data[index];
	}
	return sso.heapData[index];
}
void MyString::getSubStr(size_t howMany, char* resData, size_t begin) const{
	if (isSmall(sso.size)) {
		for (int i = 0; i < howMany; i++)
			resData[i] = sso.data[begin + i];
	}
	else {
		for (int i = 0; i < howMany; i++)
			resData[i] = sso.heapData[begin + i];
	}
}
MyString MyString::substr(size_t begin, size_t howMany) const
{
	if (begin + howMany > sso.size)
		throw std::length_error("Error, Substr out of range");


	MyString res(howMany + 1);
	if (isSmall(res.sso.size)) {
		getSubStr(howMany, res.sso.data, begin);
	}
	else {
		getSubStr(howMany, res.sso.heapData, begin);
	}
	res[howMany] = '\0';
	return res;
}

const char* MyString::c_str() const
{
	if (isSmall(sso.size)) {
		return sso.data;
	}
	return sso.heapData;
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	return os << str.c_str();
}

std::istream& operator>>(std::istream& is, MyString& str)
{
	char buff[1024];
	is.getline(buff, 1024);
	if (!isSmall(str.sso.size)) {
		delete[] str.sso.heapData;
	}

	str.sso.size = strlen(buff);
	if (isSmall(str.sso.size)) {
		strcpy(str.sso.data, buff);

	}
	else {
		str.sso.heapData = new char[str.sso.size + 1];
		strcpy(str.sso.heapData, buff);
	}

	return is;
}


bool operator<(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}
bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}
bool operator>(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}
bool operator==(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}