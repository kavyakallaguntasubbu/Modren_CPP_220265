/*
 const : the size of data has no impact on const

 form a co-relation between 

*/

#include<iostream>
#include<unordered_map>

//name of products attched to a numeric srial number for each

using Container = std::unordered_map<unsigned int,std::string>;


//iterators : idea of going one element to other without worrying about
//the actual implementation 

//old way
void DisplayMapsUsingIterators(const Container & data){
    for(auto itr = data.begin(); itr != data.end(); itr++){
        std::cout << "Key id:" << << "and value is:" <<  <<"\n";
    }
}

//c++17
void DisplayMapsUsingIterators(const Container & data){
    for(auto &[k,v] : data){//syntatic sugar
        std::cout << "Key id:" << k << "and value is:" << v <<"\n";
    }
}

//old way but different
void DisplayMapsUsingPirs(const Container & data){
    for(const std::pair<unsigned int , std::string> & p: data){
        std::cout << "Key id:" << p.first << "and value is:" << p.second <<"\n";
    }
}


int main(){
    Container data{
        {101 , "Steering Wheel"}, // pair of 1 key attched to 1 value
        {102 , "Alloy Wheels"},
        {103 , "Smart Mirrors"},
        {104 , "360 Camera setup"}
    };
    DisplayMapsUsingIterators(data);
}