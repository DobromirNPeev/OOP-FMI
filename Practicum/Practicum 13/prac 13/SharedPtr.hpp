#pragma once
#include <iostream>
#include <memory>
//Task3
template <typename T,unsigned S>
class SharedPtr
{
	T* data;
	unsigned* pointersCount;

	void free();
	void copyFrom(const SharedPtr<T,S>& other);

public:
	SharedPtr();
	SharedPtr(T* data);

	SharedPtr(const SharedPtr<T,S>& other);
	SharedPtr<T,S>& operator=(const SharedPtr<T,S>& other);

	const T& operator*() const;
	T& operator*();
	const T* operator->() const;
	T* operator->();

	~SharedPtr();
};

template <typename T, unsigned S>
void SharedPtr<T,S>::free()
{
	if (data == nullptr && pointersCount == nullptr)
	{
		return;
	}
	if (*pointersCount == 1)
	{
		delete data;
		delete pointersCount;
	}
	else
		(*pointersCount)--;
}

template <typename T, unsigned S>
void SharedPtr<T,S>::copyFrom(const SharedPtr<T,S>& other)
{
	data = other.data;
	pointersCount = other.pointersCount;
	(*pointersCount)++;
	if (*pointersCount > S) {
		throw std::out_of_range("Exception");
	}
}

template <typename T,unsigned S>
SharedPtr<T,S>::SharedPtr()
{
	data = nullptr;
	pointersCount = nullptr;
}

template <typename T,unsigned S>
SharedPtr<T,S>::SharedPtr(T* data)
{
	this->data = data;
	if (this->data)
	{
		pointersCount = new unsigned(1);
	}
}

template <typename T,unsigned S>
SharedPtr<T,S>::SharedPtr(const SharedPtr<T,S>& other)
{
	/*data = other.data;
	pointersCount = other.pointersCount;
	(*pointersCount)++;*/
	copyFrom(other);
}

template <typename T, unsigned S>
SharedPtr<T,S>& SharedPtr<T,S>::operator=(const SharedPtr<T,S>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template <typename T, unsigned S>
const T& SharedPtr<T,S>::operator*() const
{
	if (data == nullptr)
	{
		throw std::runtime_error("Pointer not set");
	}
	return *data;
}

template <typename T,unsigned S>
SharedPtr<T,S>::~SharedPtr()
{
	free();
}

template <typename T, unsigned S>
T* SharedPtr<T,S>::operator->() {
	return data;
}

template <typename T, unsigned S>
const T* SharedPtr<T,S>::operator->() const {
	return data;
}