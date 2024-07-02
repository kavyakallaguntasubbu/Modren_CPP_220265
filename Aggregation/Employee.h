#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include "Project.h"


class Employee
{
private:
    int _id;
    std::string _name;
    Project& _project;
public:
    Employee(int id, std::string name, Project& pr);
    ~Employee();
};

#endif // EMPLOYEE_H

/*
    Project&

    lvalue Reference to a Project
*/
