#include "Car.h"

Car::Car(std::string id, float price, unsigned int seatCount)
    :m_id{id},m_price{price},m_seat_count{seatCount}
{
}

float Car::Insurance()
{
    return 0.20 * m_price;
}
