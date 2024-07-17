/*
    thred : Isolated unit of instructions
    executing in memory


*/
#include<iostream>
#include<thread>
#include<vector>
#include<mutex>

std::mutex mt;
class Dummy
{
private:
    /* data */
    
public:
    Dummy(/* args */) {}
    ~Dummy() {}


    void Facorial(int number){
        int result{1};
        if(number = 1 || number == 0){
             std::lock_guard<std::mutex> lk{mt};
            std::cout<< "No factorial";
        }
        else{
        for(int i = 2 ; i < number ; i++){
            result = result *i;
        }
        std::lock_guard<std::mutex> lk{mt};
        std::cout << result << "\n";
        }
        
    }

   static void MultiplyBy100(int number){
        if(number % 100 == 0){
            std::lock_guard<std::mutex> lk{mt};
            std::cout << "divisible by 100"<<std::endl;
        }
    }
};

auto fn = [](int number){std::cout << number * number * number<<std::endl;};
void square(int number){
    std::lock_guard<std::mutex> lk{mt};
    std::cout << number * number << std::endl;
}

void MapThreads(std::vector<std::thread> &threads){
    threads[0] = std::thread(&square,10);
    threads[1] = std::thread(fn,10);
    threads[2] = std::thread(Dummy::MultiplyBy100,100);
    Dummy dm{};
    threads[3] = std::thread(&Dummy::Facorial,&dm,10);
}

void JoinThreads(std::vector<std::thread> &threads){
    for(std::thread & th : threads){
        if(th.joinable()){
            th.join();
        }
    }
}

int main(){
    std::vector<std::thread> threads{4};
    MapThreads(threads);
    JoinThreads(threads);
}
