#ifndef OPERATION_H
#define OPERATION_H

#include "Bike.h"
#include "Car.h"
#include <iostream>
#include <variant>
#include <functional>
#include <vector>
#include<thread>
#include<mutex>
#include<unordered_map>
#include<memory>

using sharedptr1 = std::shared_ptr<Bike>;
using sharedptr2 = std::shared_ptr<Car>;
using Vrtype = std::variant<sharedptr1,sharedptr2>;
using Container = std::unordered_map<std::string , Vrtype>;
using ThredContainer = std::vector<std::thread>;
 
class Operation
{
private:
    std::mutex mt;
    std::string m_id{""};
    float m_price{0};

public:
    Operation() = default;
    Operation(const Operation &) = delete;
    Operation(Operation &&) = delete;
    Operation &operator=(const Operation &) = delete;
    Operation &operator=(Operation &&) = delete;
    ~Operation() = default;

    /*
        make variant object for both cars and bike
    */

    void CreateBikeAndCar(Container &arr);

    /*
     Find Average for both Cars and Bike
    */

    void Average(Container &arr);

    /*
      Returning th vechicle attributes whose id id matches with
      the given id
    */

    std::optional<Vrtype> FindMatchingInstance(Container &arr, std::string id);

    void DisplayInsuranceAmount(Container &arr);

    /*
     find seatcont id which matches with the given id
    */
    std::optional<unsigned int> FindSeatCount(Container &arr , std::string id);

    void MapThreads(ThredContainer & threads , Container & arr);

    void JoinThreads(ThredContainer & threads);

    void Deallocate(Container & arr);

};

#endif 
