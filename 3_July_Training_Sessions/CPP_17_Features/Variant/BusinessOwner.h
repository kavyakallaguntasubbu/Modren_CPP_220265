#ifndef BUSINESSOWNER_H
#define BUSINESSOWNER_H

#include<iostream>

class BusinessOwner
{
private:
    std::string m_name{""};
    float m_income{0.0f};
public:
    BusinessOwner(/* args */) = default;
    ~BusinessOwner()  = default;

    BusinessOwner(BusinessOwner &&) = delete;
    BusinessOwner(const BusinessOwner&) = delete;
    BusinessOwner &operator = (BusinessOwner &&) = delete;
    BusinessOwner &operator = ( const BusinessOwner &) = delete;

    BusinessOwner(std::string name , float income):m_name{name},m_income{income}{
        
    }

    friend std::ostream &operator<<(std::ostream &os, const BusinessOwner &rhs) {
        os << "m_name: " << rhs.m_name
           << " m_income: " << rhs.m_income;
        return os;
    }

    void CaluculateTaxAmount(){
        std::cout<<0.15f * m_income<< "\n";
    }
    
};


#endif // BUSINESSOWNER_H
