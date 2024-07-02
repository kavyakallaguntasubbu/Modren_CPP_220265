/*
    More about lambdas :

        1) What ate thry exactly?
            -objects of an anonymous class in the background created by the compilet
        
        2) what is [] with lambda?
        

*/


#include<iostream>
#include<functional>

// void add(int32_t n1, int32_t n2){
//     std::cout << n1 + n2 << "\n";
// }
// void add(int32_t n1, int32_t n2 , int32_t data){
//     std::cout << n1 + n2 *data << "\n";
// }

void Demo(void(*ptr)(int n1 , int n2)){
    ptr(10,20);
}

int main(){

    auto fn = [](int n1, int n2) {std::cout << n1 + n2;};
    Demo(+fn); // + symbol before lambda varialble converts lambda to function pointer


    /*
        lambda objects is bound to fun variable in the scope of main function

    */

   //auto fn = [] (int32_t n1 , int32_t n2) { std::cout << n1 + n2 << "\n";};

//    int  data = 20;

//    auto fn = [data] (int32_t n1 , int32_t n2) { std::cout << n1 + n2 << "\n";};

//     fn(10,20); // overload() operator of a class created in the background
}

/*
    captures :[data] --- written inside the data

    int n1 = 10;
    int n2 = 20;
    int n3 = 30;

example 1 : use of no captured variables
    auto fn = [] { std::cout << "hello world"};
    fn;

example 2 : use of captured variables but passed parameters
    auto fn = [](int n1 , int n2) {std::cout << n1+n2;};
    fn(n1,n2);

example 3 : use n1 as captured variable. n1 should be copied into the lambds
    auto fn = [n1] (int n2) { std:: cout << n1 + n2;};
    fn(n2);

example 4 : use n1 as captured variable. n1 should be referred into the lambda
    auto fn = [&n1] (int n2) { std:: cout << n1 + n2;};
    fn(n2);

example 5 : captures all variables from the suroondings (make them all accessible in the lambda).
    (copied every thing into the lambda when they are accessed in the body of the lambda)
    auto fn = [=] (int n2) { std:: cout << n1 + n2;}; // = means keeping variables are constants
    fn(n2);

example 5 : captures all variables from the surrondings using reference(make them all accessible in the lambda).
    (copied every thing into the lambda when they are accessed in the body of the lambda)

    auto fn = [&] (int n2) { std:: cout << n1 + n2;}; // & means variables can change
    fn(n2);

*/