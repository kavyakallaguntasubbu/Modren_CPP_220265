#include "Employee.h"

Employee::Employee(int id, std::string name, Project &pr)
    : _project(pr)
{
    this->_id = id;
    this->_name = name;
    this->_project = pr;
}

Employee::~Employee()
{
    std::cout << "Employee with ID: " << _id << " deleted\n";
}
