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
    stackemployees.emplace_back(102,"Dhanya",90000.0f,28,1);
    stackemployees.emplace_back(103,"Teju",90000.0f,28,11.1);
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

    //find the positio  where minimum element is located
    //if there are multiple minimums , then consider the first on found
    // 11,9,7,10,18,7

    auto result1 = std::min_element(
        stackemployees.begin(),
        stackemployees.end(),
        [](const Employee & e1 , Employee & e2){
            return e1.experiencedValue() < e2.experiencedValue();
        }
    );

    std::cout << "The name of the Employee with minimum experience is:" << (*result1).name() << "\n";

    auto result2 = std::min_element(
        rawpointeremployees.begin(),
        rawpointeremployees.end(),
        [](const Employee * e1 ,  Employee * e2){
            return e1->experiencedValue() > e2->experiencedValue() ;
        }
    );

     std::cout << "The name of the Employee with maximum experience is:" << (*result2)->name() << "\n";

////////////////////////////////////////////////////////////////////////////////////////////////////////

    auto result3 = std::max_element(
        stackemployees.begin(),
        stackemployees.end(),
        [](const Employee & e1 , Employee & e2){
            return e1.experiencedValue() < e2.experiencedValue();
        }
    );

    std::cout << "The name of the Employee with maximum experience is:" << (*result3).name() << "\n";

    auto result4 = std::max_element(
        rawpointeremployees.begin(),
        rawpointeremployees.end(),
        [](const Employee * e1 ,  Employee * e2){
            return e1->experiencedValue() > e2->experiencedValue() ;
        }
    );

     std::cout << "The name of the Employee with minimu experience is:" << (*result4)->name() << "\n";


     ////////////////////////////////////////////////////////////////////////////////////

     auto result5 = std::count_if(
        stackemployees.begin(),
        stackemployees.end(),
        [](const Employee & e1){
            return e1.experiencedValue() > 8.0f;
        }
    );

    std::cout << "The count of the Employee with  experience greater than 8:" << result5 << "\n";

    auto result6 = std::count_if(
        rawpointeremployees.begin(),
        rawpointeremployees.end(),
        [](const Employee * e1){
            return e1->experiencedValue() > 8.0f ;
        }
    );

     std::cout << "The count of the Employee with  experience is more than 8:" << result6 << "\n";
}


