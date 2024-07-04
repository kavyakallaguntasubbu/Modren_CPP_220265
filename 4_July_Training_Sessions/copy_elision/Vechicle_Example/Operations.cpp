#include "Operations.h"
DataContainer Operations::arr{};
ThreadContainer Operations::threads{};
std::mutex Operations::mt{};

void Operations::CreateCarsandBikes()
{
    arr.emplace_back(new Bike("101", 120000));
    arr.emplace_back(new Bike("102", 120000));
    arr.emplace_back(new Bike("103", 120000));
    arr.emplace_back(new Car("104", 13000, 4));
    arr.emplace_back(new Car("105", 13000, 5));
    arr.emplace_back(new Car("106", 13000, 6));
}

void Operations::FindAvegCost()
{
    if (arr.empty())
    {
        mt.lock();
        std::cerr << "Empty data Container";
        mt.unlock();
    }
    float total{0.0f};
    for (const VrType &v : arr)
    {
        std::visit([&](auto &&val)
                   { total = total + val->price(); },
                   v);
    }
    if (!arr.empty())
    {
        mt.lock();
        std::cout << "Average Cost is: " << total / arr.size() << std::endl;
        mt.unlock();
    }
}

std::optional<VrType> Operations::ReturnMatchingInstance(std::string id)
{
    if (arr.empty())
    {
        mt.lock();
        std::cerr << "Empty data Container";
        mt.unlock();
    }
    std::optional<VrType> result{std::nullopt};
    bool m_id_found{false};

    for (const VrType &v : arr)
    {
        std::visit([&](auto &&val)
                   {
            if(val->id() == id){
                result = v;
                m_id_found = true;
            } }, v);
        if (!m_id_found)
        {
            break;
        }
    }
    return result;
}

void Operations::Deallocate()
{

    if (arr.empty())
    {
        mt.lock();
        std::cerr << "Empty data Container";
        mt.unlock();
    }
    for (VrType &v : arr)
    {
        std::visit([](auto &&val)
                   { delete val; }, v);
    }
}

void Operations::DiaplayInsuranceAmount()
{
    if (arr.empty())
    {
        mt.lock();
        std::cerr << "Empty data container";
        mt.unlock();
    }

    for (const VrType v : arr)
    {
        std::visit([](auto &&val)
                   {mt.lock();std::cout<<val->Insurance() << "\n";mt.unlock(); }, v);
    }
}

std::optional<unsigned int> Operations::FindSeatCountForGivenID(std::string id)
{
    if (arr.empty())
    {
        std::cerr << "Empty data container";
    }
    std::optional<unsigned int> result{std::nullopt};
    bool m_id_Found{false};
    for (VrType v : arr)
    {
        if (std::holds_alternative<Car *>(v))
        {
            Car *temp = std::get<Car *>(v);
            if (temp->id() == id)
            {
                result = temp->seatCount();
                m_id_Found = true;
            }
        }
    }
    if (!m_id_Found)
    {
        std::cerr << "id not found" << "\n";
    }
    return result;
}

void Operations::MapThreads()
{
    threads.emplace_back(Operations::FindAvegCost);

    threads.emplace_back(Operations::DiaplayInsuranceAmount);
}

void Operations::JoinThreads()
{
    for (std::thread &th : threads)
    {
        if (th.joinable())
        {
            th.join();
        }
    }
}
