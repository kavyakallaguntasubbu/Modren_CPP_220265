#include "Bike.h"

Bike::Bike(std::string id, float price) : m_id{id}, m_price{price}
{
}

float Bike::Insurance()
{
    return m_price * 0.01;
}