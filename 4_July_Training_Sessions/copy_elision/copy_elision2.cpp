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
   explicit Data(int val):m_value{val}{

    }

    friend std::ostream &operator<<(std::ostream &os, const Data &rhs) {
        os << "m_value: " << rhs.m_value;
        return os;
    }
    
};

Data Magic( ){
    // return Data{1000};//it will work
    Data obj {100};
    return obj ; // it will work only when move constructor or copy constructor are enabled
}
 
//explicit cant be type convert
int main(){
    Data d1 = Magic(); // uses initialization 
}