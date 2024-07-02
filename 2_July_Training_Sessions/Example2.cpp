#include<iostream>
#include<thread>
#include<mutex>

class MathOprtaion
{
private:
    std::mutex mt{}; // declaration is enough no need to intialize in constructor
    int32_t m_value{0};
public:
    MathOprtaion(const MathOprtaion &) = default;
    MathOprtaion(MathOprtaion &&) = delete;
    MathOprtaion & operator = (const MathOprtaion &) = delete;
    MathOprtaion & operator = (MathOprtaion &) = delete;
    MathOprtaion() = default;
    MathOprtaion(int val) : m_value{val}{}
    ~MathOprtaion() {}

    void square(){
        mt.lock();
        std::cout << "ID : of the thresd Square :" << std::this_thread::get_id() << "\n";
        std::cout << "Square of :" << m_value * m_value << std::endl;
        mt.unlock();

    }
    int32_t addition(int other){
        mt.lock();
        std::cout << "ID : of the thresd Addition :" << std::this_thread::get_id() << "\n";
        mt.unlock(); // should must before return statement otherwise it will be unreachable code
        return m_value + other;
    }
    // para para operator
    ino64_t operator()(){
        mt.lock();
        std::cout << "ID : of the thresd Operator :" << std::this_thread::get_id() << "\n";
        mt.unlock();
        return m_value * m_value * m_value;
    }
};
// an object that behaves like a function (can be invoked like a function)
// is called a "functor " object

int main(){
    MathOprtaion m1 {100};
    std::thread t1{&MathOprtaion::square,&m1};

    
    // using ref
     std::thread t2{ std::ref(m1)}; // thread created by a functor object -- using object of a class in function called is functor

    //you cannot capture return values from a function when executing them via std::thread
     
     std::thread t3{&MathOprtaion::addition, & m1,10};

    t1.join();
    t2.join();// it will work because it has no return statement
    t3.join();

    // note: t2 and t3 outputs are discareded . no way to capture it

    //Note 2 : all parameters passed to std::thread constructor are taken as "call - by-value"


}