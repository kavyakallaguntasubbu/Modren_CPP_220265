/*
    thred : Isolated unit of instructions
    executing in memory


*/
#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
#include<memory>
#include<future>

std::mutex mt;
class Dummy
{
private:
    /* data */
    
public:
    Dummy(/* args */) {}
    ~Dummy() {}


    int Facorial(int number){
        int result{1};
        if(number = 1 || number == 0){
             std::lock_guard<std::mutex> lk{mt};
            return 1;
        }
        else{
        for(int i = 2 ; i < number ; i++){
            result = result *i;
        }
        std::lock_guard<std::mutex> lk{mt};
        return result;
    }
        
    }

   static int MultiplyBy100(int number){
        return number*100;
    }
};

auto fn = [](int &number){return  number * number * number ;};
int square(int number){
    std::lock_guard<std::mutex> lk{mt};
    return number * number ;
}



int main(){
    
   std::future<int> res1 = std::async(&square , 10);

   int n1{10};
   std::future<int> res2 = std::async(fn,std::ref(n1));

    Dummy d1{};
   std::future<int> res3 = std::async(&Dummy::Facorial , &d1 , 10);

   std::future<int> res4 = std::async(Dummy::MultiplyBy100,10);

   std::cout << res1.get() << std::endl;
   std::cout << res2.get() << std::endl;
   std::cout << res3.get() << std::endl;
   std::cout << res4.get() << std::endl;
    
}
