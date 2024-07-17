#include "Bike.h"

Bike::Bike(std::string id, float price):m_id{id},m_price{price}
{

}

float Bike::Insurance()
{
    return 0.50 * m_price;
}
