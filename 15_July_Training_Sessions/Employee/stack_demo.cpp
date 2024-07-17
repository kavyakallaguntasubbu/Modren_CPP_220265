#include<stack>
#include<iostream>
#include"Employee.h"

/*
    a stack is never used for accessing all items together
    NO LOOPING operations!

*/

int main(){
    std::stack<Employee> s{};

    s.emplace(101,"kavay",9000,21,9.9);//push operation in the stack
    s.emplace(101,"kavay",9000,21,9.9);
    s.emplace(101,"kavay",9000,21,9.9);


    // POP

    std::cout<<s.top() << "\n";
    s.pop();

    std::cout << s.size() << "\n";

    std::cout << " Checking for Empty :" << std::boolalpha << s.empty() << "\n";
}