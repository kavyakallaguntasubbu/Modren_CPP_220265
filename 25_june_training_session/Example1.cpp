#include<iostream>
#include<vector>

void Square(int32_t number){
    std::cout<< number * number << "\n";
}

void Cube(int32_t number){
    std::cout<< number * number  * number<< "\n";
}

void Adaptor(

    void (*fn)(int32_t number),   // we have adaptor function which takes two values one is function (*fn)
    std::vector<int32_t>& data      // another one is vector 
){
    //for each number in data , run the function with the number
    for(int32_t val: data){
        (*fn)(val);
    }
}

int main(){

    // int n1 = 10;
    // int *ptr = &n1;
    // function ka pointer -----> address of a function

    // void (*ptr)(int32_t number) = & Square;

    // void (*temp)(int32_t number) = & Cube;

    // (*temp)(10) ; // call Cube function as Cube(10)

    // (*ptr) (9) ; // Square function as Square(9)


    std::vector<int32_t>data {1,2,3,4};
    Adaptor(&Cube,data);
    Adaptor(&Square,data);

    //if user wants they can design their own function and logic to process "data"

}