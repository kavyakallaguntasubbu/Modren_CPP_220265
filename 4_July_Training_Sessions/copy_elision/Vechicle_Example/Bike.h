#ifndef BIKE_H
#define BIKE_H

#include <iostream>

class Bike
{
private:
    std::string m_id{""};
    float m_price{0};

public:
    Bike(/* args */) = default;
    ~Bike() = default;
    Bike(const Bike &) = delete;
    Bike(Bike &&) = delete;
    Bike &operator=(const Bike &) = delete;
    Bike &operator=(Bike &&) = delete;
    Bike(std::string id, float price);
    float Insurance();

    float price() const { return m_price; }

    std::string id() const { return m_id; }

    friend std::ostream &operator<<(std::ostream &os, const Bike &rhs)
    {
        os << "m_id: " << rhs.m_id
           << " m_price: " << rhs.m_price;
        return os;
    }
};
#endif // BIKE_H