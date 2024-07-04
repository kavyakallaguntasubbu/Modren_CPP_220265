#include "Operations.h"

int main()
{

    // step 1 : Make Object
    Operations::CreateCarsandBikes();

    // step2 : Execute parallel functions
    Operations::MapThreads();
    Operations::JoinThreads();

    // step 3 : serial functions

    std::optional<unsigned int> result1 = Operations::FindSeatCountForGivenID("105");

    if (result1.has_value())
    {
        std::cout << "Seat count for id is :" << result1.value() << "\n";
    }

    std::optional<VrType> result2 = Operations::ReturnMatchingInstance("101");

    if (result2.has_value())
    {
        std::cout << "Matching instance found" << "\t";
        std::visit([](auto &&val)
                   { std::cout << *val << "\t"; }, result2.value());
    }
    Operations::Deallocate();
}