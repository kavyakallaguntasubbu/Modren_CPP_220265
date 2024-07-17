/*
    1 . Create Bikes and Operationss
    2 . FindAvgCostOfVechicles : return the average price of all vechicles in our database
    3 . ReturnMatchingInstance : return the first vechicle whose id matches with the id parameter
        received
    4 . Deallocate : release heap allocation if any!
    5 . DisplayInsuranceAmount : show output of the insurance amount function for each instance
    6. FindSeatcountForGivenId : fetches vechicle based on ID and returns corresponding sest_count
*/

#include <list>
#include <variant>
#include <optional>
#include <iostream>
#include "Bike.h"
#include "Car.h"
#include <thread>
#include <mutex>


using VrType = std::variant<Car *, Bike *>;
using DataContainer = std::list<VrType>;
using ThreadContainer = std::list<std::thread>;

class Operations
{
private:
    /* data */
    static std::mutex mt;
    static DataContainer arr;
    static ThreadContainer threads;

public:
    Operations(/* args */) = default;
    ~Operations() = default;
    Operations(const Operations &) = delete;
    Operations(Operations &&) = delete;
    Operations &operator=(const Operations &) = delete;
    Operations &operator=(Operations &&) = delete;
    Operations(std::string id, float price);

    static void CreateCarsandBikes();

    /*
        FindAvgCost : Use visit function to do this . Both Car and Bike have a
        m_price attribute .
        we can use their getter function to caluculate total
    */

    static void FindAvegCost();

    /*
     ReturnMatchingInstance : Variant whose ID matches with id passed
    */

    static std::optional<VrType> ReturnMatchingInstance(std::string id);

    static void Deallocate();

    static void DiaplayInsuranceAmount();

    static std::optional<unsigned int> FindSeatCountForGivenID(std::string id);
    /*
      scenario 1 : id found , matches with Car . seat count returned
      scenario 2 : id found , matches with bike ---------> nullptr
      scenario 3 : id not found : nullptr(print a message before return)
    */

    static void MapThreads();

    static void JoinThreads();
};