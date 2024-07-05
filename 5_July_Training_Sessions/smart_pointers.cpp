#include<iostream>
#include<memory>//cpp11


// unique_pointers cant copy and cnt be used in any problems if we have to do copy  objects
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

/*
    resource : 4 bytes of memoory on the heap used by the Data object with value 100

*/
void magic(std::unique_ptr<Data> temp){

}

int main(){
    int32_t x {10};
    
    //int *ptr = (int * )malloc(4);

    // std::unique_ptr<int> ptr1{(int *)malloc(4)};
    // std::unique_ptr<int> ptr2{new int()};
    // std::unique_ptr<char> ptr3{(char *)malloc(1)};

    std::unique_ptr<Data> ptr4{new Data{100}};
   // std::unique_ptr<Data> ptr4{ptr4};// cant work using copy constructor
  // magic(ptr4);// can't work 

  magic(std::move(ptr4)); // cant't use after moving

  ptr4.reset(new Data{9}); // assigning after moving restting

}

/*
    stack main function 



*/

/*
    smart pointer
    unique pointer
    shared pointer
    weak pointer

*/