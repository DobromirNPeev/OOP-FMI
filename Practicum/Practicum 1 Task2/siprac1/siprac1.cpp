#include <iostream>
#pragma warning(disable : 4996)
//Software Engineer, Senior Software Engineer, Engineer Manager, Lead Software Engineer.
const unsigned MAX_SIZE = 10;
const unsigned MAX_SIZE_NAME = 10;
const unsigned POS_SIZE = 4;
enum class Position {
    SoftwareEngineer,
    SeniorSoftwareEngineer,
    EngineerManager,
    LeadSoftwareEngineer,
    unknown
};
struct employee {
    char name[MAX_SIZE_NAME];
    Position pos;
    double salary;
    double grade;
};
struct Company
{
    employee employees[MAX_SIZE];
    double averageSalary;
};
void initEmployee(employee& emp){
    char name[MAX_SIZE_NAME];
    std::cin >> name;
    int position=0;
    double salary=0, grade=0;
    std::cin >> position >> salary >> grade;
    switch (position)
    {
        case 1:emp.pos = Position::SoftwareEngineer; break;
        case 2:emp.pos = Position::SeniorSoftwareEngineer; break;
        case 3:emp.pos = Position::EngineerManager; break;
        case 4:emp.pos = Position::LeadSoftwareEngineer; break;
        default:emp.pos = Position::unknown;
            break;
    }
    strcpy(emp.name, name);
    emp.salary = salary;
    emp.grade = grade;
}
void readEmployee(const employee& emp) {
    std::cout << emp.name << " ";
        switch (emp.pos)
        { 
        case Position::SoftwareEngineer:std::cout << "Software Engineer"<<" "; break;
        case Position::SeniorSoftwareEngineer:std::cout << "Senior Software Engineer"<<" "; break;
        case Position::EngineerManager:std::cout << "Engineer Manager"<<" "; break;
        case Position::LeadSoftwareEngineer:std::cout << "Lead Software Engineer"<<" "; break;
        default: std::cout << "unknown";
            break;
        }
        std::cout << emp.salary<<" " << emp.grade << std::endl;
        
}
void initCompany(Company& comp,int n) {
    double sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        initEmployee(comp.employees[i]);
        sum += comp.employees[i].salary;
    }
    comp.averageSalary = sum / n;
}

void readAboveAverageSalary(const Company& comp,int n) {
    Company* aboveAvg=new Company[n];
    int cnt = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (comp.employees[i].salary > comp.averageSalary) {
            (*aboveAvg).employees[cnt++] = comp.employees[i];
        }
    }
    for (size_t i = 0; i < cnt-1; i++)
    {
        for (size_t j = 0; j < cnt-1; j++)
        {
            if (strcmp((*aboveAvg).employees[j].name, (*aboveAvg).employees[j + 1].name)) {
                std::swap((*aboveAvg).employees[j], (*aboveAvg).employees[j + 1]);
            }
        }
    }
    for (size_t i = 0; i < cnt; i++)
    {
        readEmployee((*aboveAvg).employees[i]);
    }
    delete[] aboveAvg;
}
void readPosByPos(const Company& comp) {
    
}
void readAllGrades(const Company& comp,int n) {
    double min = INT16_MAX;
    double max = -1;
    for (size_t i = 0; i < n; i++)
    {
        if (comp.employees[i].pos == Position::SoftwareEngineer && comp.employees[i].grade>max) {
            max = comp.employees[i].grade;
        }
        if (comp.employees[i].pos == Position::SoftwareEngineer && comp.employees[i].grade < min) {
            min = comp.employees[i].grade;
        }
    }
    std::cout << "Max SE:"<<max << " " << "Min SE:" <<min<< std::endl;
    min = INT16_MAX;
    max = -1;
    for (size_t i = 0; i < n; i++)
    {
        if (comp.employees[i].pos == Position::SeniorSoftwareEngineer && comp.employees[i].grade > max) {
            max = comp.employees[i].grade;
        }
        if (comp.employees[i].pos == Position::SeniorSoftwareEngineer && comp.employees[i].grade < min) {
            min = comp.employees[i].grade;
        }
    }
    std::cout << "Max SSE:" <<max<< " " << "Min SSE:" <<min<< std::endl;
    min = INT16_MAX;
    max = -1;
    for (size_t i = 0; i < n; i++)
    {
        if (comp.employees[i].pos == Position::EngineerManager && comp.employees[i].grade > max) {
            max = comp.employees[i].grade;
        }
        if (comp.employees[i].pos == Position::EngineerManager && comp.employees[i].grade < min) {
            min = comp.employees[i].grade;
        }
    }
    std::cout << "Max EM:" <<max<< " " << "Min EM:" <<min<< std::endl;
    min = INT16_MAX;
    max = -1;
    for (size_t i = 0; i < n; i++)
    {
        if (comp.employees[i].pos == Position::LeadSoftwareEngineer && comp.employees[i].grade > max) {
            max = comp.employees[i].grade;
        }
        if (comp.employees[i].pos == Position::LeadSoftwareEngineer && comp.employees[i].grade < min) {
            min = comp.employees[i].grade;
        }
    }
    std::cout << "Max LSE:" <<max<< " " << "Min LSE:" <<min<< std::endl;
}
int main()
{
    Company comp;
    initCompany(comp,8);
    readAboveAverageSalary(comp, 8);
    readAllGrades(comp, 8);
}