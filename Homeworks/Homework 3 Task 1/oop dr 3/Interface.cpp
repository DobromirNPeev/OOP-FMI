#include "Interface.h"

void search(const Set& set, int& counter) {
    while (true) {
        if (set.contains(counter++) || counter == INT_MAX) {
            break;
        }
    }
}

void mode2(const Set& set) {
    int counter = INT_MIN;
    search(set, counter);
    std::cout << "Number: ";
    std::cout << counter - 1 << std::endl;
    std::cout << "Would you to see more numbers ?" << std::endl;
    while (1) {
        char answer;
        std::cout << "Answer:";
        std::cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            search(set, counter);
            if (counter == INT_MAX) {
                std::cout << "Infinity reached" << std::endl;
                break;
            }
            std::cout << "Number: ";
            std::cout << counter - 1 << std::endl;
            std::cout << "Would you to see more numbers ?" << std::endl;

        }
        else if (answer == 'n' || answer == 'N') {
            std::cout << "Bye" << std::endl;
            break;
        }
        else {
            throw std::logic_error("No such answer");
        }
    }
}

void mode1(const Set& set) {
    int a, b;
    std::cout << "a:";
    std::cin >> a;
    std::cout << "b:";
    std::cin >> b;
    for (int j = a; j <= b; j++)
    {
        if (set.contains(j))
            std::cout << j << " ";
    }
}