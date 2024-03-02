#include <iostream>
#include "MyString.h"

class Ticket {
    MyString name;
    double price;
public:
    Ticket() :name(""), price(0) {};
    Ticket(const char* name, double price) :name(name), price(price) {};
    const MyString& getName() const {
        return name;
    }
    double getPrice() const {
        return price;
    }
    void print() const{
        std::cout << name << " " << price<<std::endl;
    }
};

class StudentTicket : public Ticket {
public:
    StudentTicket(const char* name, double price) :Ticket(name, price / 2) {};
};

class GroupTicket : public Ticket {
public:
    GroupTicket(const char* name, double price) :Ticket(name, price*0.8) {};
};
int main()
{
    StudentTicket tik("FMI", 25.25);
    GroupTicket tik1("Zamuk", 48);
    tik.print();
    tik1.print();
}
