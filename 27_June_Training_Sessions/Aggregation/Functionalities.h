#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Employee.h"
#include "Project.h"
#include<list>
#include<functional>

using EmployeeContainer = std::list<Employee*>;

using ProjectContainer = std::list<Project*>;

using Predicate = std::function<Employee( const Employee*)>;


void CreateObjects(EmployeeContainer Employees, ProjectContainer projects);

void Deallocate(EmployeeContainer Employees, ProjectContainer projects);

/*
 Add a feature to filter employees based on filter predicates
 (functional style)[FILTER LAMBDA]

*/

void FilterEmployees(Predicate fn , const EmployeeContainer & Employees);

void DiaplayProjectBudgect( EmployeeContainer & Employees);

    


#endif // FUNCTIONALITIES_H
