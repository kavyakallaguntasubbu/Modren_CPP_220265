#include "Functionalities.h"

int main() {
    EmployeeContainer  employees;
    ProjectContainer projects;
    CreateObjects(employees, projects);

    //filter all employees whose project team count is above 10
    // auto fn = [](Employee *employees){
    //     return employees-> project().get().teamSize() > 10;
        
    // };
    FilterEmployees([](const Employee  *employees){
        return *employees;},
        employees
    );
    Deallocate(employees, projects);
}

/*
    from means passed values 
    conversion from "lambda [] (Employee * temp) -> void"

    to value means expected parameter as per function declaration 
    std::function<bool (const- Employee*)>

*/