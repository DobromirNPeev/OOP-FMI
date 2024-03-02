#include <iostream>
#pragma warning(disable:4996)

const char* OFFSET = "     ";

class Employee {
    char* name = nullptr;
    double salary=0;

    void free();
    void copyFrom(const Employee& other);
    void moveFrom(Employee&& other);

public:
    Employee() = default;
    Employee(const char* name, double salary);
    Employee(const Employee& other);
    Employee& operator=(const Employee& other);
    virtual ~Employee();

    Employee(Employee&& other);
    Employee& operator=(Employee&& other);

    virtual Employee* clone() const=0;
    virtual void print() const;
};
Employee::Employee(const char* name, double salary):salary(salary) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}
Employee::Employee(const Employee& other) {
    copyFrom(other);
}
Employee& Employee::operator=(const Employee& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}
Employee::~Employee() {
    free();
}

Employee::Employee(Employee&& other) {
    moveFrom(std::move(other));
}
Employee& Employee::operator=(Employee&& other) {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

void Employee::free() {
    delete[] name;
}
void Employee::copyFrom(const Employee& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    salary = other.salary;
}
void Employee::moveFrom(Employee&& other) {
    name = other.name;
    salary = other.salary;
    other.name = nullptr;
    salary = 0;
}

void Employee::print() const {
    std::cout << name << " " << salary;
}
class  Manager: public Employee {
    Employee** myEmps;
    size_t size=0;
    size_t capacity=8;
    char* position=nullptr;

    void free();
    void copyFrom(const Manager& other);
    void moveFrom(Manager&& other);
    void resize();
public:
    Manager() = default;
    Manager(const char* name, double salary, const char* position);
    Manager(const Manager& other);
    Manager& operator=(const Manager& other);
    ~Manager();
    void addSubordinate(Employee* subordinate);

    Manager(Manager&& other);
    Manager& operator=(Manager&& other);
    Employee* clone() const override;
    void print() const override;
};
 
void Manager::addSubordinate(Employee* subordinate) {
    if (size >= capacity)
        resize();
    myEmps[size++] = subordinate->clone();
}
void Manager::free() {
    for (size_t i = 0; i < size; i++)
    {
        delete myEmps[i];
    }
    delete[] myEmps;
    delete[] position;
}
void Manager::resize() {
    Employee** newEmps = new Employee * [capacity *= 2];
    for (size_t i = 0; i < size; i++)
    {
        newEmps[i] = myEmps[i];
    }
    delete[] myEmps;
    myEmps = newEmps;
}
void Manager::copyFrom(const Manager& other){
    myEmps = new Employee * [other.size];
    position = new char[strlen(other.position)+1];
    strcpy(position, other.position);
    for (size_t i = 0; i < size; i++)
    {
        myEmps[i] = other.myEmps[i]->clone();
    }
}
void Manager::moveFrom(Manager&& other) {
    myEmps = other.myEmps;
    position = other.position;
    other.myEmps = nullptr;
    other.position = nullptr;
}

Manager::Manager(const char* name, double salary, const char* position):Employee(name,salary) {
    this->position = new char[strlen(position) + 1];

    strcpy(this->position, position);
    myEmps = new Employee*[capacity];
}
Manager::Manager(const Manager& other): Employee(other) {
    copyFrom(other);
}
Manager& Manager::operator=(const Manager& other) {
    if (this != &other) {
        Employee::operator=(other);
        free();
        copyFrom(other);
    }
    return *this;
}
Manager::~Manager() {
    free();
    }

Manager::Manager(Manager&& other):Employee(std::move(other)) {
    moveFrom(std::move(other));
    }
Manager& Manager::operator=(Manager&& other) {
    if (this != &other) {
        Employee::operator=(std::move(other));
        free();
        moveFrom(std::move(other));
    }
    return *this;
    }

Employee* Manager::clone() const {
    return new Manager(*this);
}
void Manager::print() const {
    Employee::print();
    std::cout << " " << position;
    std::cout << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        std::cout << OFFSET;
        myEmps[i]->print();
        std::cout << std::endl;
    }
}

class NormalWorker: public Employee {

public:
    NormalWorker(const char* name, double salary);
    Employee* clone() const override;
};

Employee* NormalWorker::clone() const {
    return new NormalWorker(*this);
}
NormalWorker::NormalWorker(const char* name, double salary) :Employee(name, salary) {};
int main()
{
    Employee* ceo = new Manager ("Georgi", 10000,"CEO");
    Employee* nm1 = new NormalWorker ("Plami", 1500);
    Employee* nm2 = new NormalWorker ("Aleksander", 2000);
    Employee* nm3 = new NormalWorker ("Denis", 2100);
    Manager* m = (Manager*)ceo;
    m->addSubordinate(nm1);
    m->addSubordinate(nm2);
    m->addSubordinate(nm3);
    ceo->print();

    delete ceo;
    delete nm1;
    delete nm2;
    delete nm3;
}