/*
    elision : not do something, not perform something,
                ignore/ avoid something

    Guranteed Copy Elision : cpp17

*/
#include<iostream>

class Data
{
private:
    int m_value{0};
public:
    Data() = default;
    ~Data() = default;
    Data(const Data &) = delete;
    Data(Data &&) = default;
    Data & operator = (const Data &) = delete;
    Data &operator = (Data &&) = delete;
    Data(int val):m_value{val}{

    }

    friend std::ostream &operator<<(std::ostream &os, const Data &rhs) {
        os << "m_value: " << rhs.m_value;
        return os;
    }
    
};

Data Container(){
    return Data{1000};
}

Data Absorber(Data d1){
    std::cout << d1 << "\n";
    return d1;
}
int main(){
   Data obj =  Absorber(Container());
    std::cout << obj << "\n";

}