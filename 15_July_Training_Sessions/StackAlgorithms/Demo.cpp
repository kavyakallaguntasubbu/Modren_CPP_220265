#include<memory>
#include"Employee.h"
#include<list>
#include<algorithm>

using StackMemoryEmployees = std::list<Employee>;

using RawPointerHeapEmployee = std::list<Employee*>;

using EmployeePter = std::shared_ptr<Employee>;

using SmartPointerHeapEmployee = std::list<EmployeePter>;


void CreateObjects(StackMemoryEmployees & stackemployees){

    stackemployees.emplace_back(101,"kavya",90000.0f,28,11.1);//stack memoy
    stackemployees.emplace_back(102,"Dhanya",90000.0f,28,11.1);
    stackemployees.emplace_back(103,"Teju",90000.0f,28,11.1);
}

void CreateObjects(RawPointerHeapEmployee & rawpointeremployees){
    rawpointeremployees.emplace_back(new Employee(101,"kavya",90000.0f,28,11.1));//heap memoy
    rawpointeremployees.emplace_back(new Employee(102,"Dhanya",90000.0f,28,11.1));
    rawpointeremployees.emplace_back(new Employee(103,"Teju",90000.0f,28,11.1));
}

void CreateObjects(SmartPointerHeapEmployee & smartpointerEmployee){

    smartpointerEmployee.emplace_back(std::make_shared<Employee>(101,"kavya",90000.0f,28,11.1));//Shared memoy
    smartpointerEmployee.emplace_back(std::make_shared<Employee>(102,"Dhanya",90000.0f,28,11.1));
    smartpointerEmployee.emplace_back(std::make_shared<Employee>(103,"Teju",90000.0f,28,11.1));
}

int main(){

    StackMemoryEmployees stackemployees{};

    RawPointerHeapEmployee  rawpointeremployees{};

    SmartPointerHeapEmployee smartpointerEmployee{};

    CreateObjects(stackemployees);
    CreateObjects(rawpointeremployees);
    CreateObjects(smartpointerEmployee);

    //any_of ---- atleast one condition is true
    // none_of --- none of ongects meet the condition
    bool result1 = std::all_of( // considering all objects in my container if all objects meet the condition then returns true
        stackemployees.begin(),
        stackemployees.end(),
        [](const Employee & e) {return e.age() > 25;}
    );

    bool result2 = std::all_of(
        rawpointeremployees.begin(),
        rawpointeremployees.end(),
        [](const Employee * e) { return e->age() > 25;}
    );

    bool result3 = std::all_of(
        smartpointerEmployee.begin(),
        smartpointerEmployee.end(),
        [](const EmployeePter & e) { return e->age() > 25;}
    );


}

//check if all employees have above age 25

// check all items from begin to end of my conatiner

