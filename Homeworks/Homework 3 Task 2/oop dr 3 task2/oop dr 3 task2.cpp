
#include <iostream>
#include "PriorityQueue.hpp"
int main()
{
    try{
        PriorityQueue<char> q(5);
    q.push('A', 0); //adds A with lowest priority: 0
    q.push('B', 3);
    q.push('C', 2);
    q.push('D', 2);
    q.push('E', 1);

    q.push('F', 5); //error! No such priority!
    q.push('Z', 0); //error! No such priority!
    q.push('S', 3); //error! No such priority!
    q.push('Y', 2); //error! No such priority!


    std::cout << q.peek() << std::endl; // B
    q.pop();

    std::cout << q.peek() << std::endl; // B
    q.pop();

    std::cout << q.peek() << std::endl; // C
    q.pop();

    std::cout << q.peek() << std::endl; // D
    q.pop();

    std::cout << q.peek() << std::endl; // E
    q.pop();

    std::cout << q.peek() << std::endl; // A
    q.pop();
    }
    catch (std::out_of_range& exc) {
        std::cout << exc.what();
    }
    catch (std::logic_error& exc) {
        std::cout << exc.what();
    }
    catch (std::exception& exc) {
        std::cout << exc.what();
    }
    catch (...) {
        std::cout << "Exception caught";
    }
}