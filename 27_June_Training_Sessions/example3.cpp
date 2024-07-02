#include<iostream>
#include<functional>

class Data
{
private:
    int m_value{0};
public:
    Data ()= default;
    ~Data() =default;

    Data (const Data& ) = delete;
    Data (Data && ) = delete;
    Data & operator = (const Data& ) = delete;
    Data & operator = (Data&& ) = delete;

    Data(int value):m_value{value}{

    }

    void Display(int factor){
        std::cout<<m_value*factor;
    }

    static void DisplayReading(int times){
        std::cout << "hello" << times << std::endl;
    }
};

int main(){

    Data obj{18}; // m_value is 18

    obj.Display(100); // 100 is the factor

    auto fn = std::bind(&Data::Display,&obj,100);
    fn(); // obj.Display(100);

    Data::DisplayReading(10) ; // hello 10 times

    auto static_display = std::bind(Data::DisplayReading,10);
    static_display(); // Data::diaplayReading(10)
}

/*
    for non-static member functions
    a) objects address is mandatory
    b) It must be the first argument after specifying the name of the function in binding
    c) You "must" use "&" symbol with the name of the member function in bind

    for static member functions

    a) No object involved so no address required
    b) ypu "SHOULD NOT USE & " with the function name
*/

