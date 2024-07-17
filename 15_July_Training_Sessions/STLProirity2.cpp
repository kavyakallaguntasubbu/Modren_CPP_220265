#include"Employee2.h"
#include<queue>

/*
    1) what kind of data goes into prority queue?
    2) What is the backend of the queue to store the data? // vector is default
    3) what is the comaprision logic (also called "comaparator")

*/

int main(){
    
    //prority is reverse of comapartor : > mean min heap : < mean max heap 
    auto fn = [](const Employee & e1 , const Employee & e2){ return e1.experiencedValue() < e2.experiencedValue();};

    //declatype -- to capture the type of function
    std::priority_queue<Employee,std::vector<Employee>,decltype(fn)> pq {fn};

    pq.emplace(101,"kavya",80000,8,9);
    pq.emplace(101,"kavya",80000,8,90);
    pq.emplace(101,"kavya",80000,8,900);

    //doesnt need any vector we are not copiying here we re just moving
    //who is the employee with the "HIGHEST PRORITEY"

    std::cout << pq.top() << "\n";


}