#include<vector>
#include<iostream>
#include<functional>
#include<thread>
#include<mutex>// ordinary , binary , semaphore

std::mutex  mt ; 

using Operation = std::function<void(int number)>;
 
void Square(int number){
    mt.lock(); // ask for permission to access cout
    std::cout<< number * number ; // critical section 
    mt.unlock(); // release the lock when done
}
 

 
void Adaptor(Operation fn, const std::vector<int>& data){
    for(int val : data){
        std::this_thread::sleep_for(std::chrono::seconds(1)); //for every element in the data , it got delayed by 1 second.
        fn(val);
    }
}


int main(){
      
      auto cube_fn = [](int number) { 
        mt.lock();// ask for permission to access cout
        std::cout<<number * number * number<<"\n";
        mt.unlock();// release the lock when done
    };
 
     // Adaptor(Square, std::vector<int> { 1,2,3,4,5});
 
     //asking os to execute the adaptor function along with square function and a data container
 
     std::thread t1{&Adaptor, &Square, std::vector<int> { 1,2,3,4,5}};  
 
     std::thread t2{&Adaptor, cube_fn, std::vector<int> { 1,2,3,4,5}};
 
     t1.join();  //main cannot proceed beyond line 58 unless  t1 is terminated/completed.
     t2.join();  //main cannot proceed beyond line 59 unless  t2 is terminated/completed.
 
 
}

/*
    order of 
*/