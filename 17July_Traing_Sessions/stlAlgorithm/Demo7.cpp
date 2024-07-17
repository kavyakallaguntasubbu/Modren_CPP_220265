#include<algorithm>
#include<memory>
#include"Employee.h"
#include<list>
#include<iostream>



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

    /////////////////////////////
    /*
        Data : 11 28 19 0

        Result : even number
    */
   //copy constructor and operator sholud be enabled
    std::vector<Employee> result{};

    std::copy_if(
        stackemployees.begin(),
        stackemployees.end(),
        std::inserter(result, result.begin()), // if result has memory then inserter will inserted into result automatically
        [](const Employee & e){return e.age() > 20;}
    );
    for(Employee & e : result){
        std::cout << e << std::endl;
    }

    ////////////////////////////////////////////////////////////
    //copy n number of items

    std::vector<Employee> n_result{};

    std::copy_n(
        stackemployees.begin(),
        2,
        std::inserter(n_result,n_result.begin())
    );
    for(Employee & e : n_result){
        std::cout << e << std::endl;
    }

   
    //example3 : copy all items from rawpointers into destinaton

    std::vector<Employee *> result_pointer{rawpointeremployees.size()};
    std::copy(
        rawpointeremployees.begin(),
        rawpointeremployees.end(),
        result_pointer.begin()
    );

    for(Employee * e : result_pointer){
        std::cout << *e << std::endl;
    }


    

}


