/*
    std::reference_wrapper<T> :
        This is Wrapper class to hold
        reference ow

*/

// #include<iostream>
// #include<vector>
// #include<functional>

// void Magic(std::reference_wrapper<int>data){
//     std::cout<<data.get(); // get actual value from the wrapper
// }

// int main(){

//     int n1 = 10;
//     std::reference_wrapper<int> ref  = n1; // ref is a reference to n1

//     //ref is an alterative name for n1 in main function

//     Magic(n1); // std::reference_wrapper<int>

//     std::reference_wrapper<int> arr[1] {ref};

//     std::vector<std::reference_wrapper<int>>v1;

//     std::cout << v1[0].get(); //get the value inside the wrapper in 0 position of vector
// }



#include<iostream>
#include<vector>
#include<functional>

void Magic(int &data){
    std::cout<<data; // get actual value from the wrapper
}

int main(){

    int n1 = 10;
    std::reference_wrapper<int> ref {n1}; // ref is a reference to n1
    Magic(ref); 


}