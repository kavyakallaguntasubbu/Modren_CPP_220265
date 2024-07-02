/*
    first class functions

    A language is said to trat "sunctions" as first- class if the
    following things are possible in the language

    a) functions have a properly recognizable types.
    b) functions can be passed as parameters to the function
    c) functions can be returned as parameters from the functions (closures)
    d) functions can be addressed/copied into other variables
    e) functions can be stored in a container
*/

#include<iostream>
#include<functional>
#include<vector>

void Magic(std::function<void(const int32_t)> fn){
    fn(10); // square of 10
}
// rule 3
std::function<void(int32_t)>Demo(){

}

int main(){

    // Types of fn:
    /*
        a function which accepts on int32_t by value , returns void
    */

    auto fn = [](const int32_t val) {std::cout << val * val ;};

    //rule2
    Magic(fn);
    
    //rule 3
    auto ans = Demo(); // accepts the function returned in a variable

    //rule 4

    auto temp = ans ; // 'function' copied

    auto *ptr = & ans ; // addressing also works

    //rule 5: functions can be saved in other containers

    std::vector<std::function<void(int32_t)>  >fns{fn};



}