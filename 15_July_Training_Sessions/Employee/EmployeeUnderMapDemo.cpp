/*
 const : the size of data has no impact on const

 form a co-relation between 

*/

#include<iostream>
#include<unordered_map>
#include"Employee.h"
#include<functional>

//name of products attched to a numeric srial number for each

using Container = std::unordered_map<unsigned int,Employee>;

using Predicate = std::function<bool(const std::pair<const unsigned int , Employee > & )>;


void DisplayMapsUsingIterators(const Container & data){
    for(auto &[k,v] : data){//syntatic sugar
        std::cout << "Key id:" << k << "and value is:" << v <<"\n";
    }
}

void CreateEmployeeObjects(Container & data){
    data.emplace(
        std::piecewise_construct,//construct by considering by 2 pieces
        std::forward_as_tuple(101), // first piece is a tuple of 1 key
        std::forward_as_tuple(101,"kavya",700000,25,11.1f)//second piece is a tuple of 5 items
    );//emplace function accepts one key and value

    data.emplace(
        std::piecewise_construct,//construct by considering by 2 pieces
        std::forward_as_tuple(102), // first piece is a tuple of 1 key
        std::forward_as_tuple(102,"Teju",700000,21,11.1f)//second piece is a tuple of 5 items
    );

    data.emplace(
        std::piecewise_construct,//construct by considering by 2 pieces
        std::forward_as_tuple(103), // first piece is a tuple of 1 key
        std::forward_as_tuple(103,"Dhanya",700000,21,11.1f)//second piece is a tuple of 5 items
    );
}

void FindAverageSalary(const Container & data){
    /*
        for every pair of key and value,
        go to value section and use the getter to fetch salary
        add salary to total
        at the end of for loop , divide total by size of hash table
    */
   float total{0.0f};
   for(auto& [k,v] : data){
        total +=v.salary();
   }
   std::cout<<total/data.size() << "\n";
}

void FindEmployeeById(const Container & data , unsigned int key){
    auto itr = data.find(key);//bases on key
    //if key is not found , we get iterator to end the position (beyond the map conatainer)
    if( itr == data.end()){
        std::cerr << "Employee with given key :" << key << "is not found \n";
    }

    else{
        std::cout << itr->second << "\n";
    }
}

void FilterEmployeeByPredicate(const Container & data , Predicate fn){
    /*
        do nit apply filter key , condition is based on object's value 
    */
   // Note : while extracting pairs from an unordered map,
   // the key part shall always be constant

   for(const std::pair<const unsigned int , Employee> & p : data){
        if(fn(p)){
            std::cout << p.second << "\n";
        }
   }
}



int main(){
    Container data;
    CreateEmployeeObjects(data);
    DisplayMapsUsingIterators(data);
    FilterEmployeeByPredicate(
        data,
        [](const std::pair<const unsigned int , Employee > & p){
            return p.second.age() >= 25;
        }
    );
}