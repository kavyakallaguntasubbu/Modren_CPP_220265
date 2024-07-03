#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>

class Employee
{
private:
    std::string m_name{""};
    float m_salary{0.0f};
public:
    Employee(/* args */) = default;
    ~Employee()  = default;

    Employee(Employee &&) = delete;
    Employee(const Employee&) = delete;
    Employee &operator = (Employee &&) = delete;
    Employee &operator = ( const Employee &) = delete;

    Employee(std::string name , float salary):m_name{name},m_salary{salary}{

    }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
        os << "m_name: " << rhs.m_name
           << " m_salary: " << rhs.m_salary;
        return os;
    }

    void CaluculateMonthlyPF(){
        std::cout<<0.11f * m_salary << "\n";
    }

    void CaluculateTaxAmount(){
        std::cout<<0.15f * m_salary << "\n";
    }
};


#endif // EMPLOYEE_H
