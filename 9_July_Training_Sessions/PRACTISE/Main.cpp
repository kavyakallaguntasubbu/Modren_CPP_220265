#include"Functionalities.h"

int main(){

    Container arr{};
    CreateObjects(arr);
    auto fn = [](const std::shared_ptr<const Engine>& e){
        return e->type() == EngineType::ALTERNATIVE_FUEL;
    };
    Container c = FilterFunction(fn,arr).value();
    for(const ptrContainer e : c){
        std::cout << *e << std::endl;
    }
    bool val = IfatleatOneFunctionMeet(fn,arr);
    std::cout<< "Function Meet: " << val << std::endl;
    float avg = AverageEngineCC(arr);
    std::cout << "Average :" << avg << std::endl;

}