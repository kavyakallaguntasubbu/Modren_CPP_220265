/*
    3 styles of programming
        - structure oriented
        - object oriented
        - functional

    functions have categories based on what they do
        In map function application , number of inputs and outputs in same 
        [101 2700 ][102  90000] [ 103  880000]
        fn = (e) -> salary * 0.1f // as tax

        result = 2700 , 9000, 188000

        example 2 : a function that "removes / identifies" from the input, a select number of values 
        based on a criteria [filter functuon]

        e.g : data = [1,2,3,4]
        fn = n -> n % 2 == 0


        example 3 : a function that accumulates/gathers/aggregates multiple input values into one , final 
        singular output value [reduce/accumulate functions]
        e.g : data = [1,2,3,4,5]
        fn = (x,y)->x + y

        result = 15
*/


#include<iostream>
#include<functional>

using Operation = std::function<int32_t(int32_t)>;

void Adaptor(Operation fn , int32_t value){

    std::cout << fn(value);
}

int main(){
    //takes one input of type int32_t by value
    //and returns an int32_t value 
    //the function should multiply input number by 100

   auto fn = [](int32_t n){ return n*100;};

    int n1 = 99;
    auto demo_fn = [n1] (int32_t num) {return num*n1;};
    
    // if we want to change the n1 value  ------- use mutable 

     auto demo_fn = [n1] (int32_t num) mutable { n1 = 90 ; return num*n1;};

    Adaptor(fn , 10);
}

/*
    if we want to use 

*/

