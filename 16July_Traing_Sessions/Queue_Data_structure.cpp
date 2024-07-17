/*
    10 20 30 40

    I would like to data continuously / I want to access previous
    and next element of a certain element in the fastest time

    API : a mechanism to access something or anything

*/

// DeQueue is same syntax . place dequeue instead of queue
#include "Employee.h"
#include <memory>
#include <vector>
#include <queue>

using EmployeePtr = std::shared_ptr<Employee>;
using DataContainer = std::queue<EmployeePtr>;

void CreateEntriesForQueue(DataContainer &data)
{
    data.emplace(std::make_shared<Employee>(101, "kavya", 90000, 21, 4.0));
    data.emplace(std::make_shared<Employee>(102, "kavya", 90000, 21, 4.0));
    data.emplace(std::make_shared<Employee>(103, "kavya", 90000, 21, 4.0));
}
/*
                            101 , "kavya" , 9000 , 21 , 4
                            ^
                            |
                            |
                            |


// background container as like --- list and dequeue
*/

int main()
{
    DataContainer employees{};
    CreateEntriesForQueue(employees);

    /*
        Queue is a FIF0 data structure
        Insertion of items from one end and deletion from other
    */
    std::cout << *employees.front() << std::endl; // first item in the queue

    /*
     we can check size
    */

    std::cout << employees.size() << "\n";

    std::cout << *employees.back() << "\n"; // last item in the queue
}