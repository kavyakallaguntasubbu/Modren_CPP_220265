#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>

class Employee
{
private:
    unsigned int m_id{0};
    std::string m_name{""};
    float m_salary{0.0};
    unsigned int m_age;
    float m_experienced_value;
public:
    Employee()  = delete;
    ~Employee() = default;
    Employee(const Employee &) = delete;
    Employee(Employee &&) = delete;
    Employee & operator = (const Employee &)= delete;
    Employee & operator = (Employee &&) = delete;

    //parameterized constructor
    Employee(unsigned int id , std::string name , float salary , unsigned int age , float value)
    :m_id{id},m_name{name},m_salary{salary},m_age{age},m_experienced_value{value}{
        
    }

    std::string name() const { return m_name; }
    void setName(const std::string &name) { m_name = name; }

    float salary() const { return m_salary; }
    void setSalary(float salary) { m_salary = salary; }

    unsigned int age() const { return m_age; }
    void setAge(unsigned int age) { m_age = age; }

    float experiencedValue() const { return m_experienced_value; }
    void setExperiencedValue(float experienced_value) { m_experienced_value = experienced_value; }

    unsigned int id() const { return m_id; }
    void setId(unsigned int id) { m_id = id; }


    // check applicable tax

    void CheckApplicableTax(){
        if(m_salary > 0 && m_salary <= 500000.0f){
            std::cout << "Tax amount will be:" << 0.1f *m_salary ;
        }
        else if(m_salary > 500000 && m_salary <= 1500000.0f){
            std::cout << "Tax amount will be:" << 0.2f *m_salary ;
        }
        else{
            std::cout << "Tax amount will be:" << 0.3f *m_salary ;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
        os << "m_id: " << rhs.m_id
           << " m_name: " << rhs.m_name
           << " m_salary: " << rhs.m_salary
           << " m_age: " << rhs.m_age
           << " m_experienced_value: " << rhs.m_experienced_value;
        return os;
    }
    
};



#endif // EMPLOYEE_H
