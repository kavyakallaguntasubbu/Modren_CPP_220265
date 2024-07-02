#ifndef DEVICE_H
#define DEVICE_H

#include<iostream>

class Device
{
private:
    std::string _id;
    std::string _modelname;
    float _price;
public:
    Device(std::string id, std::string ModelName,float price);
    virtual ~Device() {}
    virtual float CalculateGstCost() const = 0;

    float price() const { return _price; }

    std::string id() const { return _id; }

    friend std::ostream &operator<<(std::ostream &os, const Device &rhs) {
        os << "_id: " << rhs._id
           << " _modelname: " << rhs._modelname
           << " _price: " << rhs._price;
        return os;
    }
    
};

#endif // DEVICE_H
