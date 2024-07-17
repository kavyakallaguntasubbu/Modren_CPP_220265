#include"Employee.h"
#include<queue>

/*
    1) what kind of data goes into prority queue?
    2) What is the backend of the queue to store the data? // vector is default
    3) what is the comaprision logic (also called "comaparator")

*/

int main(){
    std::vector<Employee> employees{};
    employees.emplace_back(101,"kavya",80000,8,9);//push operation 
    employees.emplace_back(102,"kavya",80000,8,90);
    employees.emplace_back(103,"kavya",80000,8,900);
    //employees.emplace(101,"",900,)

    // all employees which are in the vector must be inserted into the heap using heapify()

    //comaprators
    auto fn = [](const Employee & e1 , const Employee & e2){ return e1.experiencedValue() > e2.experiencedValue();};

    //declatype -- to capture the type of function
    std::priority_queue<Employee,std::vector<Employee>,decltype(fn)> pq {employees.begin(),employees.end(),fn};

//prority queue has three -- Type , backend type , function type is my wish
}