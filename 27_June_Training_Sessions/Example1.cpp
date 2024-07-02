#include<iostream>
#include<functional>

void formula(int x, int y, int z){
    std::cout<<((x + y) - z);
}

int main(){

    auto partial_formula = std::bind(&formula , 100 , std::placeholders::_1,std::placeholders::_2);

    partial_formula(10,90); // formula(100,10,90);

    auto swapped_formula = std::bind(&formula,std::placeholders::_2,std::placeholders::_3,std::placeholders::_1);

    swapped_formula(10,20,30); // formula(20,30,10)

    auto weirdly_formula = std::bind(&formula,100,90,std::placeholders::_2);

    weirdly_formula(10,99); // 10 is discarded because _1 was not used

}