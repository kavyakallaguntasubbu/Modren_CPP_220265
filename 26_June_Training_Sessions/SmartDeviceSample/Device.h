#ifndef DEVICE_H
#define DEVICE_H

#include<iostream>

class Device
{
private:
    std::string _ID{0};
    std::string _name{""};
    float _price{0.0};
public:
    Device(/* args */) = default;
    virtual ~Device() = default;

    Device (const Device &) = delete;
    Device ( Device &&) = delete;
    Device & operator = (const Device &) = delete;
    Device & operator = ( Device &&) = delete;

    Device(std::string id, std::string name, float price);

    virtual float CalculateGstCost() const = 0;

    float price() const { return _price; }

    std::string iD() const { return _ID; }

    friend std::ostream &operator<<(std::ostream &os, const Device &rhs) {
        os << "_ID: " << rhs._ID
           << " _name: " << rhs._name
           << " _price: " << rhs._price;
        return os;
    }
    
};

#endif // DEVICE_H
