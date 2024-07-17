#include "Functionalities.h"

void CreateObjects(Container &arr)
{
    std::shared_ptr<Engine> sptr{new Engine("101", EngineType::ALTERNATIVE_FUEL, 1200, 20, 90)};
    arr.emplace_back(new Engine("101", EngineType::ALTERNATIVE_FUEL, 1200, 20, 90));
    arr.emplace_back(new Engine("102", EngineType::HYBRID, 1200, 20, 90));
    arr.emplace_back(new Engine("103", EngineType::ICE, 1200, 20, 90));
    arr.emplace_back(new Engine("104", EngineType::ALTERNATIVE_FUEL, 1200, 20, 90));
}

std::optional<Container> FilterFunction(const Predicate &fn, const Container &arr)
{
    bool m_input_empty{false}; // falg to check empty continer
    if (arr.empty())
    {
        std::cerr << "Empty Container";
        m_input_empty = true; // set it to true
    }
    Container result{};
    /*
        check if prediCATE_FN IS applicable on the pointer
        if yes, store it in the result
    */
    for (const ptrContainer &ptr : arr)
    {
        if (fn(ptr))
        {
            result.emplace_back(ptr);
        }
    }
    // if input is not empty but result is empty
    if (!m_input_empty && arr.empty())
    {
        return std::nullopt;
    }
    // input is not empty but result has some data
    else if (!m_input_empty && !arr.empty())
    {
        return result;
    }
    else
    {
        return std::nullopt;
    }
}

bool IfatleatOneFunctionMeet(const Predicate &fn, const Container &arr)
{

    if (arr.empty())
    {
        std::cerr << "Empty Container";
    }

    for (const ptrContainer &ptr : arr)
    {
        if (fn(ptr))
        {
            return true;
        }
    }
    return false;
}

float AverageEngineCC(const Container &arr)
{
    bool m_input_empty{false};
    if (arr.empty())
    {
        std::cerr << "Empty Container";
        m_input_empty = true;
    }
    float total{0.0};
    for (const ptrContainer &ptr : arr)
    {
        total = total + ptr->cc();
    }
    if (m_input_empty)
    {
        return 0;
    }
    return total / arr.size();
}
