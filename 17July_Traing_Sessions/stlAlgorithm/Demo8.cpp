#include<algorithm>
#include<memory>
#include"Employee.h"
#include<list>
#include<iostream>
#include<numeric>// to use accumulate algorithm



using StackMemoryEmployees = std::list<Employee>;

using RawPointerHeapEmployee = std::list<Employee*>;

using EmployeePter = std::shared_ptr<Employee>;

using SmartPointerHeapEmployee = std::list<EmployeePter>;


void CreateObjects(StackMemoryEmployees & stackemployees){

    stackemployees.emplace_back(101,"kavya",90000.0f,28,11);//stack memoy
    stackemployees.emplace_back(102,"Dhanya",90000.0f,21,1);
    stackemployees.emplace_back(103,"Teju",90000.0f,2,11.1);
}

void CreateObjects(RawPointerHeapEmployee & rawpointeremployees){
    rawpointeremployees.emplace_back(new Employee(101,"kavya",90000.0f,28,11));//heap memoy
    rawpointeremployees.emplace_back(new Employee(102,"Dhanya",90000.0f,28,1));
    rawpointeremployees.emplace_back(new Employee(103,"Teju",90000.0f,28,11.1));
}

void CreateObjects(SmartPointerHeapEmployee & smartpointerEmployee){

    smartpointerEmployee.emplace_back(std::make_shared<Employee>(101,"kavya",90000.0f,28,11.1));//Shared memoy
    smartpointerEmployee.emplace_back(std::make_shared<Employee>(102,"Dhanya",90000.0f,28,1));
    smartpointerEmployee.emplace_back(std::make_shared<Employee>(103,"Teju",90000.0f,28,11));
}

int main(){

    StackMemoryEmployees stackemployees{};

    RawPointerHeapEmployee  rawpointeremployees{};

    SmartPointerHeapEmployee smartpointerEmployee{};

    CreateObjects(stackemployees);
    CreateObjects(rawpointeremployees);
    CreateObjects(smartpointerEmployee);

    //////////// Binary operation lambda

   float result = std::accumulate(
        stackemployees.begin(),
        stackemployees.end(),
        0.0f,//intial value
        [](float ans_upto_now , const Employee & e){
            return ans_upto_now + e.salary();
        }
    );

    std::cout <<" Total Salary" << result << std::endl;

    std::cout << "Average " << result / stackemployees.size() << std::endl;
    

}


