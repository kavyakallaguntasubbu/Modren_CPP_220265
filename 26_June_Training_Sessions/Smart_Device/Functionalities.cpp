#include"Functionalities.h"

void CreateObjects(Smartdevice **arr,int size){

    std::string id;
    std::string name;
    float price;
    int choice ;
    
    for(int i = 0 ; i < size ; i++){
        std::cin>>id;
        std::cin>>name;
        std::cin>>price;
        std::cin>>choice;
        float *inarr  = new float[3];
        for(int i = 0 ; i< 3; i++){
            float val;
            std::cin>>val;
           inarr[i] = val;
        }

        arr[i] = new Smartdevice(id,name,price,(DeviceType)choice,inarr);
        
    }

}

void IndexValue(Smartdevice **arr, int size , int idxv){

    if(size < 0){
        throw std::invalid_argument("Negative Number");
    }
    for(int i = 0 ; i< size ; i++){
        if(idxv > 0 && idxv <=3){
            std::cout<<"Reading"<<*(arr)[idxv]<<"x\n";
            break;
        }
        else{
            std::cout<<"INvalid id value"<<"\n";
        }
    }
}

std::string MaxGSTCost(Smartdevice **arr , int size){
    if(size < 0){
        throw std::invalid_argument("Negative Number");
    }
    float max = 0.0;
    std::string id =""; 
    for(int i = 0; i< size ; i++){
        if(max <= arr[i]->CalculateGstCost()){
            max = arr[i]->CalculateGstCost();
            id = arr[i] ->id();
        }
    }
    return id;
}

void FilterDevices(Predicate fn, const Smartdevice **arr, const unsigned int size)
{
    bool atleatOneMatchingDeviceFound{false};

    for(unsigned int i = 0 ; i < size ; i++){
        if(fn(arr[i])){
            std::cout << *arr[i];
            atleatOneMatchingDeviceFound = true;
        }
    }
    if(!atleatOneMatchingDeviceFound){
        std::cerr<< "No matching instance found \n";
    }
}

void DeleteHeapobjects(Smartdevice **arr, int size){
    for(int i = 0; i < size ; i++){
        delete[] arr[i]->sensorReading();

        delete arr[i];
    }
}