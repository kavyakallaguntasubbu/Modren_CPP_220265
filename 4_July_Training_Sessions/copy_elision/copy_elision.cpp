/*
    elision : not do something, not perform something,
                ignore/ avoid something

    Guranteed Copy Elision : cpp17

*/
#include <iostream>

class Data
{
private:
    int m_value{0};

public:
    Data() = default;
    ~Data() = default;
    Data(const Data &) = delete;
    Data(Data &&) = delete;
    Data &operator=(const Data &) = delete;
    Data &operator=(Data &&) = delete;
    explicit Data(int val) : m_value{val}
    {
    }

    friend std::ostream &operator<<(std::ostream &os, const Data &rhs)
    {
        os << "m_value: " << rhs.m_value;
        return os;
    }
};

void Magic(Data d1)
{
    std::cout << d1 << "\n";
}

// explicit cant be type convert
int main()
{

    // Data d1 {1000};
    // Magic(d1); // can access using reference //without reference cant work
    // Magic(99) // this will not work because conversion is disabled (explicit)

    Magic(Data{100}); // it can work by taking rvalues and without enabling copy constructor
    // compiler simply refactors/modifies the code as Data d1{100}
}