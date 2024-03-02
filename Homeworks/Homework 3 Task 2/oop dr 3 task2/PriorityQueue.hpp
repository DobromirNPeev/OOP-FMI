#pragma once
#include "Vector.hpp"
#include "Queue.hpp"

template <typename T>
class PriorityQueue {
public:
	Vector<MyQueue<T>> data;
	unsigned size=0;

	PriorityQueue(unsigned size);
	void push(const T& obj,unsigned ind);
	void push(T&& obj,unsigned ind);
	void pop();

	const T& peek() const;
	bool isEmpty() const;
};


template <typename T>
PriorityQueue<T>::PriorityQueue(unsigned size):data(size) {
	this->size = size;
}

template <typename T>
void PriorityQueue<T>::push(const T& obj, unsigned ind) {
	if (ind >= size) {
		throw std::out_of_range("No such priority");
	}
	data[ind].push(obj);
}

template <typename T>
void PriorityQueue<T>::push(T&& obj, unsigned ind) {
	if (ind >= size) {
		throw std::out_of_range("No such priority");
	}
	data[ind].push(std::move(obj));
}
template <typename T>
const T& PriorityQueue<T>::peek() const {
	for (int i = data.getSize()-1; i >= 0; i--)
	{
		if (!data[i].isEmpty()) {
			return data[i].peek();
		}
	}
}
template <typename T>
void PriorityQueue<T>::pop() {
	
	for (int i = data.getSize()-1; i >= 0; i--)
	{
		if (!data[i].isEmpty()) {
			data[i].pop();
			return;
		}
	}
}
template <typename T>
bool PriorityQueue<T>::isEmpty() const {
	return data.getSize();
}