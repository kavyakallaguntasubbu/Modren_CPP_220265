#ifndef CAR_H
#define CAR_H

#include<iostream>

class Car
{
private:
    std::string m_id{""};
    float m_price{0};
    unsigned int m_seat_count{0};
public:
    Car()  = default;
    Car (const Car &) = delete;
    Car (Car &&) = delete;
    Car & operator = (const Car &) = delete;
    Car & operator = (Car &&) = delete;
    ~Car() = default;
    Car(std::string id , float price , unsigned int seatCount);

    float Insurance();

    float price() const { return m_price; }

    std::string id() const { return m_id; }

    unsigned int seatCount() const { return m_seat_count; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs) {
        os << "m_id: " << rhs.m_id
           << " m_price: " << rhs.m_price
           << " m_seat_count: " << rhs.m_seat_count;
        return os;
    }
    
};

#endif // CAR_H
