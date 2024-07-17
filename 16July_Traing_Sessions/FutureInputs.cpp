/*
    async has 2 cases
    1) you can use std::async to fetch data from thread if function returns a value

    2) Providing inputs to executing threads asynchronously,
    out of order in "future"
*/
#include <iostream>
#include <future>
#include <memory>
int *AllocateSpace()
{
    return (int *)new int(); // return the address of the new allocation
}

int *factorial(std::future<int> &number)
{
    /*
        1. primary task : caluculate factorial (dependent on input)
        2. make allocation on the heap where the answer will be stored

    */
    int *ans = AllocateSpace();
    /*
     ..........actual answer caluculation starts here!
    */

    // after the subtask is complete , inout value is MANDATORY NOW!
    int number_value = number.get(); // factorial thread will be blocked untill the user fulfills the promise

    int result = 1;
    for (int i = 2; i <= number_value; i++)
    {
        result *= i;
    }
    *ans = result; // copy the result on the heap in ans adress location
    return ans;
}

int main()
{

    std::promise<int> pr; // first , I make a promise to provide an "integer"

    std::future<int> ft = pr.get_future();

    std::future<int *> res = std::async(&factorial, std::ref(ft));

    //--------------------------------------------------------------------------------------
    // giving promising data

    int data{0};

    std::cin >> data;

    // fulfills promise. send a signal to future attched to this promise
    pr.set_value(data);
    //------ printing data
    std::cout << *res.get() << "\n";
}
