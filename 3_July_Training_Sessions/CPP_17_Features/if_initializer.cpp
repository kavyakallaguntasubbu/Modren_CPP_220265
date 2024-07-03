/*
    bool definition fn(){
        //////////
    
    }

*/

#include<iostream>

bool CheckDivisibility(int32_t number){
    return number;
}

int main(){
    int32_t n1{10};
    //if flag variuable is initialized and then flag is also true

    if(bool flag = CheckDivisibility(n1); flag ){
        std::cout << "number is divisible by 3";
    }
    else{
        std::cerr << "Flag is set at :" << std::boolalpha << flag << "Number not divisible \n";
    }
}