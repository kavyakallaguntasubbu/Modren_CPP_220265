#include "Functionalitie.h"
#include "IdnotFond.h"
#include"NoValidEngineFoundException.h"

void CreateObjects(Container&arr)
{
    // // arr[0] = new Engine(0,21,2.0);
    // // arr[1] = new Engine(102,22,3.0);
    // // arr[2] = new Engine(103,23,4.0);
    // // arr[3] = new Engine(104,24,5.0);
    // int id;
    // int horsepower;
    // float torque;
    // for( int i = 0; i < arr.size() ; i++){
    //     std::cin>>id;
    //     std::cin>>horsepower;
    //     std::cin>>torque;
    //     arr[i] = new Engine(id,horsepower,torque);
    // }

    //type : vector of Engine pointers -----> we need materials to make a new Engine 
    arr.emplace_back(new Engine(0,120,0));
    arr.emplace_back(new Engine(1,120,22));
    arr.emplace_back(new Engine(2,120,22));
    arr.emplace_back(nullptr); // if we dont use these in function it will get segmentation fault
     

}

float AverageHorsePower( const Container&arr)
{
    if(arr.size() < 0){
        throw std::invalid_argument("Size Cannot be Negative");
    }
    float total{0};
    std::size_t ValidPointerCount {0};

    //range- based for loop 
    // for each - loop
    // for each const Engine pointer "called e " present in arr
    for(const Engine* e : arr){
        if(e){
        total = total + e ->horsepower();
        ValidPointerCount++;
        }
    }
//     for(std::size_t i = 0; i < arr.size() ; i++){
//         if(arr[i]){
//         total = total + arr[i] ->horsepower();
//         ValidPointerCount++;
//     }
// }
    if(ValidPointerCount == 0){
        throw NoValidEngineFoundException("all poinetrs are null");
    }
    else{
        return total/ValidPointerCount;
    }
    
}

void FindTorqueById(Container&arr, int id)
{
    // if(arr.size() < 0){
    //     throw std::invalid_argument("Size Cannot be Negative");
    //     return;
    // }
    bool value {false} ;
     int count {0};
    for(const Engine* e : arr){
        if(e->id() == 0){
            count++;
        }
        if(count == arr.size()){
            throw std::invalid_argument("Id Cannot be null");
            break;
        }
        if(e->id()== id){
            std::cout<<"Torque :"<< e->torque()<<std::endl;
            value = true;
            
        }
        if(!value){
        throw IdnotFond("Id Not Found");
        }
    }
}

void FindHorsepowerForMinTorqueEngine(Container&arr)
{
    // if(arr.size() < 0){
    //     throw std::invalid_argument("Size Cannot be Negative");
    //     return;
    // }
    // int min = 0;
    // int horsep = 0;
    // for(const Engine*e : arr){
    //     if(e -> torque() > min){
    //         min = e->torque();
    //         horsep = e->horsepower();
    //     }
        
    // }
    // std::cout<<"Horse Power:"<< horsep <<std::endl;

    bool IdnotFond {false};
     float currentMinTorque{arr[0]->torque()};
    //float currentMinTorque{0};
    // for(const Engine *e : arr){
    //     if(e->torque() == 0){
    //         currentMinTorque = ->horsepower();
    //     }
    // }
    

    std::size_t indexOfMinToreque {0};
    std::size_t k = 0;

    for(const Engine * e : arr){
        if(e == 0){
            throw std::invalid_argument("First element is zero");
            break;
        }
        currentMinTorque = arr[1]->torque();
        if(e){
            IdnotFond = true;

            if(e->torque() < currentMinTorque){

                currentMinTorque = e->torque();
                indexOfMinToreque = k;
            }
        }
        k++;
    }
    
    std::cout<<"Min Torque corresponding Horsepower :" << arr[indexOfMinToreque]->horsepower() << std::endl;
}

void DeleteObjects(Container&arr)
{
    for(const Engine *e: arr){
        delete e;
    }
}
