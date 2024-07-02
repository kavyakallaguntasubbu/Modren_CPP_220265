#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include "DeviceTechnology.h"
#include"Device.h"
#include <ostream>

class Smartdevice : public Device
{
private:
    DeviceType _type;
    float *_SensorReading;
public:
    Smartdevice(std::string id, std::string ModelName, float price,DeviceType type, float *sensorreading);
    ~Smartdevice() {}
    float CalculateGstCost() const;

    friend std::ostream &operator<<(std::ostream &os, const Smartdevice &rhs);
    
    float operator[](int idx);

    float *sensorReading() const { return _SensorReading; }

    DeviceType type() const { return _type; }
  
};

#endif // SMARTDEVICE_H
