#include <iostream>
#include "Interface.h"
#include "fileOperations.h"

int main()
{
    Set* set=nullptr;
    try {
        set = readSetFile("set.dat");
        std::cout << "Choose mode:" << std::endl;
        std::cout << "1. Interval from a to b" << std::endl;
        std::cout << "2. Sequentially generating all elements of the set, with each subsequent element generated upon user request(from -infinity to +infinity)" << std::endl;
        std::cout << "Enter mode:";
        int request;
        std::cin >> request;
        if (request == 1) {
            mode1(*set);
        }
        else if (request == 2) {
            mode2(*set);
        }
        else {
            throw std::logic_error("No such regime");
        }
    }
    catch (std::logic_error& exc) {
        std::cout << exc.what();

    }
    catch (std::invalid_argument& exc) {
        std::cout << exc.what();
    }
    catch (std::exception& exc) {
        std::cout << exc.what();
    }
    catch (...) {
        std::cout << "Exception caught";
    }
    delete set;

}