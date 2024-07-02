#include "Smartdevice.h"

Smartdevice::Smartdevice(std::string id, std::string ModelName, float price, DeviceType type, float *sensorreading)
    :Device(id,ModelName,price)
{
    this->_SensorReading = sensorreading;
    this->_type = type;
}

float Smartdevice::CalculateGstCost() const
{
    
    float result = 0.0;
    if(_type == DeviceType::BLUETOOTH){
        result = 0.1*price();
    }
    else if(_type == DeviceType::WIFI || _type == DeviceType::WIFI_BLUETOOTH){
        result = 0.15*price();
    }
    else{
        result = 0.20*price();
    }
    return result;
}

std::ostream &operator<<(std::ostream &os, const Smartdevice &rhs) {
        os << static_cast<const Device &>(rhs)
           << " _type: " << rhs._type
           << " _SensorReading: " ;
           for(int i = 0 ; i < 3 ; i++){
               os << rhs._SensorReading[i] << " " ;
           } os <<"\n";
        return os;
}

float Smartdevice ::operator[](int idx){

    return _SensorReading[idx];
}