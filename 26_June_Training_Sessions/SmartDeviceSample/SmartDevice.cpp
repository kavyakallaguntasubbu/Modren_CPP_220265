#include "SmartDevice.h"

SmartDevice::SmartDevice(std::string id, std::string name, float price, DeviceTechnology technology, float *arr)
    :Device{id,name,price}, _device{technology},_arr{arr}
{
}

float SmartDevice::CalculateGstCost() const
{
    float percentage {0};
    if(_device == DeviceTechnology::BLUETOOTH){
        percentage = this->price()*0.10;
    }
    else if (_device == DeviceTechnology::WIFI || _device == DeviceTechnology::WIFI_BLUETOOTH)
    {
        percentage = this->price()*0.05;
    }
    else{
        percentage = this->price()*0.03;
    }
    return percentage;
}

float SmartDevice::operator[](int idx)
{
    return _arr[idx];
}
