#include "Car.h"

Car::Car(std::string id, float price, unsigned int count) : m_id{id}, m_price{price}, m_seat_count{count}
{
}

float Car::Insurance()
{
    return m_price * 0, 01;
}
