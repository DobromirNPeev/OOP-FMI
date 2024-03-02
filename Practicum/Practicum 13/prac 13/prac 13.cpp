#include <iostream>
#include "SharedPtr.hpp"
//Task3
#include "Company.h"

//Task 1
template <typename T>
void print(const T* arr, int length) {
    for (size_t i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


template <typename T>
void sort(T* arr,int length)
{
    for (int i = 1; i < length; i++) {
        int currentNumber = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > currentNumber) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = currentNumber;
    }
   // return arr;
}

template <>
void sort(char* str,int length)
{
    int hist[256] = { 0 };
    //size_t size = strlen(str);

    char* newStr = new char[length + 1];
    size_t strIter = 0;

    for (size_t i = 0; i < length; i++)
    {
        hist[str[i]]++;
    }
    for (size_t i = 1; i < 256; i++)
    {
        hist[i] += hist[i - 1];
    }
    for (size_t i = 0; i < length; i++)
    {
        newStr[hist[str[i]] - 1] = str[i];
        hist[str[i]]--;
    }
    for (size_t i = 0; i < length; i++)
    {
        str[i] = newStr[i];
    }
    delete[] newStr;

   // return newStr;
}

int main()
{
	Company comp;
	comp.addPaidTrainee();
	comp.addTrainee();
	comp.addWorker();
	std::cout << comp.TwoSum(100.25);

}