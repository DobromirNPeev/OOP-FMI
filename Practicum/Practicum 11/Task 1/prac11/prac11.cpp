// prac11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Computer.h"
#include <iostream>

int main()
{
    Computer** c = new Computer * [3];
    c[0] = new PC();
    c[1] = new Laptop();
    c[2] = new GamingConsole();
    for (size_t i = 0; i < 3; i++)
    {
        c[i]->getType(); std:: cout << std::endl;
    }
    for (size_t i = 0; i < 3; i++)
    {
        std::cout << c[i]->canConnect()->c_str()<<std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
