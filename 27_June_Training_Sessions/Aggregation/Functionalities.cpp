#include "Functionalities.h"

void CreateObjects(EmployeeContainer Employees, ProjectContainer projects)
{
    projects.emplace_back(new Project("c.111", 10, 1000.0f));
    projects.emplace_back(new Project("c.221", 50, 11000.0f));
    projects.emplace_back(new Project("c.331", 20, 10000.0f));

    ///////////////////////////////////////////////////////////
    auto itr = projects.begin(); // itr++ is pointing to the beginning of the project list

    Employees.emplace_back(new Employee(101, "Harshit", **itr++));
    Employees.emplace_back(new Employee(101, "Rohan", **itr++));
    Employees.emplace_back(new Employee(101, "Rohan", **itr++));

}

void Deallocate(EmployeeContainer Employees, ProjectContainer projects)
{
    for(Employee * emp : Employees){
        delete emp;
    }
    for(Project * pr : projects){
        delete pr;
    }
}

void FilterEmployees(Predicate fn, const EmployeeContainer &Employees)
{
    for(Employee * emp : Employees){
        if(emp){
            std::cout << *emp <<"\n";
        }
        
    }
}

// void DiaplayProjectBudgect(EmployeeContainer &Employees)
// {
//     for(Employee *emp : Employees){
//         std::cout << emp->project().get().budget() << "\n";
//     }
// }
