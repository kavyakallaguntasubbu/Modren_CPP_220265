#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Employee.h"
#include "Project.h"
#include"vector"
#include"functional"

using Container = std::vector<Employee*>;

using Predicate = std::function<void(const Employee *)>;

void CreateObjects(Container & employees, Project** projects, unsigned int size);

void Deallocate(Container & employees, Project** projects, unsigned int size);

void FilterEmployee( );

#endif // FUNCTIONALITIES_H
