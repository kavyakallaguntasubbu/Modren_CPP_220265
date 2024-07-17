#include "Employee.h"
#include "BusinessOwner.h"
#include <variant>
#include <iostream>

/*
    A function which either accepts another function as a parameter or returns a function
    is called "Hogher-order" function
*/

using vrType = std::variant<BusinessOwner *, Employee *>;

void Display(vrType &v)
{
    std::visit([](auto &&val)
               { std::cout << *val << "\n"; },
               v);
}

// holds_alternative using because spfamount function is only present in Employees
void ShowPFAmount(vrType &v)
{
    bool flag{false};
    if (std::holds_alternative<Employee *>(v))
    {
        flag = true;
        Employee *e = std::get<1>(v); // get<1> is accessing Employee in vrType
        e->CaluculateMonthlyPF();
    }
    if(!flag)
    {
        throw std::runtime_error("Not valid for Businessowner type data");
    }
}

// visit is using because spfamount function is  present in both BusinessOwner and Employee
void ShowTaxAmount(vrType &v)
{
    std::visit([](auto &&val)
               { val->CaluculateTaxAmount(); }, v);
}

int main()
{
    vrType vr;

    vr = new BusinessOwner{"kavya", 1201000};
    Display(vr);

    vr = new Employee{"kk", 90000};
    Display(vr);

    try
    {
        ShowPFAmount(vr);
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << e.what() << '\n';
    }

    ShowTaxAmount(vr);
}