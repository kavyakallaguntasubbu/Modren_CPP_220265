#include "Operation.h"
Operation op;
void Operation::CreateBikeAndCar(Container &arr)
{
   
    arr.emplace(
        std::piecewise_construct,
        std::forward_as_tuple("101"),
        std::forward_as_tuple(std::make_shared<Bike>("101",12000))
    );
    // arr.emplace(std::make_shared<Bike>("101","102",12000));
    // // arr.emplace(std::make_shared<Bike>("103",12000));
    // // arr.emplace(std::make_shared<Car>("104",2300,5));
    // // arr.emplace(std::make_shared<Car>("105",2300,7));    
    // // arr.emplace(std::make_shared<Car>("106",2300,8));
}

void Operation::Average(Container &arr)
{
    if(arr.empty()){
        std::lock_guard<std::mutex> lk{mt};
        std::cerr<< "Array is empty";
    }
    int result{0};
    for(auto & [k,v] : arr ){
        std::visit([&] (auto && val){ result = result + val -> price();},v);
    }
    if(!arr.empty()){
        std::lock_guard<std::mutex> lk{mt};
        std::cout<<"Average :" << result / arr.size() << std::endl;
    }
}

std::optional<Vrtype> Operation::FindMatchingInstance(Container &arr, std::string id)
{
    if(arr.empty()){
        std::lock_guard<std::mutex> lk{mt};
        std::cerr<< "Array is empty";
    }
    std::optional<Vrtype>result {std::nullopt};
    bool m_id_found{false};
    for(auto &[k,v] : arr){
        std::visit([&] (auto && val){
            if(val ->id()==id){
                result = v ; 
                m_id_found = true;
            }
        },v);
    }
    if(!arr.empty() && !m_id_found){
        std::lock_guard<std::mutex> lk{mt};
        std::cerr<<"Not Found"<<std::endl;
    }
    
    return result;
    
}



void Operation::DisplayInsuranceAmount(Container &arr)
{
    if(arr.empty()){
        std::lock_guard<std::mutex> lk{mt};
        std::cerr<< "Array is empty";
    }
    float result{0.0};
    for(auto & [k,v] : arr){
        std::visit([&] (auto && val){
            std::lock_guard<std::mutex> lk{mt};
            std::cout << val->Insurance()<<std::endl;
        },v);
    }
}

// std::optional<unsigned int> Operation::FindSeatCount(Container &arr , std::string id)
// {
//     if(arr.empty()){
//         std::lock_guard<std::mutex> lk{mt};
//         std::cerr<< "Array is empty";
//     }
//     std::optional<unsigned int>result {std::nullopt};
//     bool m_id_found{false};
//     for(Vrtype v : arr){
//         std::visit([&](auto && val){
//             if(std::holds_alternative<Car *>(v)){
//                 Car *temp = std::get<Car*>(v);
//                 if(temp->id() == id){
//                     result = temp->seatCount();
//                     m_id_found = true;
//                 }
//             }
//         },v);
    
//     }
//     if(!arr.empty() && !m_id_found){
//         std::lock_guard<std::mutex> lk{mt};
//         std::cerr<<"Not Found"<<std::endl;
//     }
    
//     return result;
    
// }

// void Operation::MapThreads(ThredContainer &threads, Container &arr)
// {
//     threads.emplace_back(&Operation::Average,&op,std::ref(arr));
//     threads.emplace_back(&Operation::DisplayInsuranceAmount,&op,std::ref(arr));
// }

// void Operation::JoinThreads(ThredContainer &threads)
// {
//     for(std::thread & th : threads){
//         if(th.joinable()){
//             th.join();
//         }
//     }
// }

// void Operation::Deallocate(Container &arr)
// {
//     for(Vrtype & v : arr){
//         std::visit([] (auto && val){ delete val;},v);
//     }
// }
