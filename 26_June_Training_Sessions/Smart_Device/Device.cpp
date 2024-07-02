#include "Device.h"

Device::Device(std::string id, std::string ModelName, float price)
{
    this->_id = id;
    this->_modelname = ModelName;
    this->_price = price;
}
