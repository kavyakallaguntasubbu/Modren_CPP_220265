#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H
#include"Device.h"
#include"DeviceTechnology.h"
#include<iostream>
class SmartDevice : public Device
{
private:
    DeviceTechnology _device{DeviceTechnology::OTHER};
    float *_arr{0};

public:
    SmartDevice()  = default;
    ~SmartDevice() = default;

    SmartDevice (const SmartDevice &) = delete;
    SmartDevice ( SmartDevice &&) = delete;
    SmartDevice & operator = (const SmartDevice &) = delete;
    SmartDevice & operator = ( SmartDevice &&) = delete;

    SmartDevice(std::string id, std::string name, float price,DeviceTechnology technology,float *arr);

    float CalculateGstCost() const;

    friend std::ostream &operator<<(std::ostream &os, const SmartDevice &rhs) {
        os << static_cast<const Device &>(rhs)
           << " _device: " << static_cast<std::underlying_type<DeviceTechnology>::type>(rhs._device)
           << " _arr: " ;
           for(int i = 0 ; i < 3 ; i++){
            os << rhs._arr[i] << " " ;
           } os <<"\n";
        
        return os;
    }

    float operator[](int idx);

    float *getarr() const { return _arr; }

    DeviceTechnology device() const { return _device; }
    
};


#endif // SMARTDEVICE_H
