/*
    Terminologies
 
    1) CPU : Central Processing Unit
          - set of h/w responsible for exeuting tasks in a computing device ( laptops, mobiles.....) .
 
    2) System : any computing devices.
 
    3) Processor : h/w chip ( made of silicon) designed
                   for executing instructions given by the user of the computer.
                   e.g: intel - i5
 
    4) socket : point on the motherboard hwere processor is connected.
 
    5) Core : Every processor  is divided internally into units called as "units"
              Each core can execute instructions from one "processor"  at any given time.
 
    6) Process : A running task on the system.
 
    7) clock speed : how many instructions can my cpu execute in one second.  
 
*/
 
#include<vector>
#include<iostream>
#include<functional>
#include<thread>
 
using Operation = std::function<void(int number)>;
 
void Square(int number){
    std::cout<< number * number ;
}
 
void Cube(int number){
    std::cout<< number * number* number ;
}
 
void Adaptor(Operation fn, const std::vector<int>& data){
    for(int val : data){
        std::this_thread::sleep_for(std::chrono::seconds(1)); //for every element in the data , it got delayed by 1 second.
        fn(val);
    }
}
 
int main(){
      
      auto fn = [](int number) { std::cout<<number * number * number<<"\n";};
 
     // Adaptor(Square, std::vector<int> { 1,2,3,4,5});
 
     //asking os to execute the adaptor function along with square function and a data container
 
     std::thread t1{&Adaptor, &Square, std::vector<int> { 1,2,3,4,5}};  
 
     std::thread t2{&Adaptor, &Cube, std::vector<int> { 1,2,3,4,5}};
 
     t1.join();  //main cannot proceed beyond line 58 unless  t1 is terminated/completed.
     t2.join();  //main cannot proceed beyond line 59 unless  t2 is terminated/completed.
 
 
}