#include<iostream>
#include<variant>

int main(){
    int32_t n1 {10000};
    std::string s1 {"kavya"};

    //variants : are categorical types which allows either or principle of typing

    std::variant<int32_t , std::string> vr;

    vr = n1; // n1 is asiigned to the variant.

    std::cout<<" Variant is working \n";

    vr = s1;

}

/*
        int32_t       std::string
    [             /               ] //24 bytes

    bad varient 32
*/