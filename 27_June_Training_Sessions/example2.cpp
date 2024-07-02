#include<iostream>
#include<functional>

int main(){
    auto fn = [] (int32_t number , int32_t factor){
        return number * factor;
    };

    // while binding lambda functions , don't use & symbole for function name
    auto partailly_implemented = std::bind(fn , 100 , std::placeholders::_1);

    partailly_implemented(20); // fn(100,20)

    partailly_implemented(20,10,20,30); // fn(100,20); // all other inputs are discarded

}