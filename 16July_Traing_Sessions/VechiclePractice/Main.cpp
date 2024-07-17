#include "Operation.h"
#include<future>

int main(){

    Container arr{};
//    // ThredContainer threads{};
    Operation op{};
    op.CreateBikeAndCar(arr);
    // op.MapThreads(threads,arr);
    // op.JoinThreads(threads);


    // //std::future<std::optional<unsigned int>> result1 = std::async(FindSeatCount(arr,"1"));
    // std::future<std::optional<Vrtype>>  result1 = std::async(&Operation::FindMatchingInstance, &op, std::ref(arr), "101");
    // std::optional<Vrtype> res1 = result1.get();
    // if(res1.has_value()){
    //     std::visit([](auto && val){
    //         std::cout << *val << std::endl;
    //     },res1.value());
    // }

    // std::future<std::optional<unsigned int>> result2 = std::async(&Operation::FindSeatCount,&op,std::ref(arr),"105");
    // std::optional<unsigned int> res2 = result2.get();
    // if(res2.has_value()){
    //     std::cout<< "Seat Count :" << res2.value() << std::endl;
    // }
    // // std::optional<Vrtype> result1 = op.FindMatchingInstance(arr,"101");
    // // if(result1.has_value()){
    // //     std::visit([](auto && val){
    // //         std::cout<< *val<< std::endl;
    // //     },result1.value());
    // // }
    
    // // std::optional<unsigned int> result2 = op.FindSeatCount(arr,"104");
    // // if(result2.has_value()){
    // //     std::cout << "Seat Count :" << result2.value() << std::endl;
    // // }
   // op.Deallocate(arr);
}