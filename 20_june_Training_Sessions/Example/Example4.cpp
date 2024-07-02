#include<iostream>

void Magic(int dtat){ // call by value

}

// void Magic(int &data){ // callby refernce lvalue

// }

// void Magic(int &&data){ // call by rvalue reference

// }

// void Magic(const int &data){ // calling by reference

// }

// void Magic(const int &&data){ // only shifts the data --- calling lvalue && rvalue

// }

int main(){

    Magic(10);
    int n1 = 10;
    Magic(n1);
}