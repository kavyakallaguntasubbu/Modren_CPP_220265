#include<iostream>
#include<functional>
/*
    std::function<t> is a wrapper that can be used to represent a callable of a certain
    signature T
    Since this entire data type declaration  is lengthy, we can create an allias for
    it with "using" keyword
 
 
    [](int32_t number){return number%2==0;}//lambda
 
    I want to put it in a wrapper
    so type T(Signature): bool(int32_t)
 
    so wrapper is: std::function<bool(int32_t)>;
    Now create an alias called "Predicate"
 
*/
using predicate = std::function<bool(int32_t)>;

void Adaptor(predicate fn, int32_t* arr, unsigned int size){
    /*
        for every index "i" in the range of size of arr,
        call fn passing arr[i] (ith position value in the array)
    */
    for(int32_t i =0; i< size; i++)
    {
        
        if(fn(arr[i])){
            std::cout<< arr[i] << "\t";
        }
    }
}
 
int main(){
    auto fn=[](int32_t number){return number%2 ==0;};
    int32_t arr[3] = { 1,2 ,3};
    Adaptor(fn, arr,3);
}