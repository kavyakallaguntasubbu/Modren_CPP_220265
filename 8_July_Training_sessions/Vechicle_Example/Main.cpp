#include <future>
#include "Operations.h"

int main()
{

    // step 1 : Make Object
    Operations::CreateCarsandBikes();

    // step2 : Execute parallel functions
    Operations::MapThreads();
    Operations::JoinThreads();

    // step 3 : serial functions

    std::future<std::optional<unsigned int>> result1 = std::async(Operations::FindSeatCountForGivenID, "105");

    std::future<std::optional<VrType>> result2 = std::async(Operations::ReturnMatchingInstance, "105");

    std::optional<unsigned int> res1 = result1.get();

    std::optional<VrType> res2 = result2.get();

    if (res1.has_value())
    {
        std::cout << "Seat count for id is :" << res1.value() << "\n";
    }

    if (res2.has_value())
    {
        std::cout << "Matching instance found" << "\t";
        std::visit([](auto &&val)
                   { std::cout << *val << "\t"; }, res2.value());
    }
    Operations::Deallocate();
}