#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<vector>
#include"Device.h"
#include"SmartDevice.h"
#include<functional>
using Predicate = std::function<bool(SmartDevice*)>;

using Container = std::vector<SmartDevice *>;

void CreateObjcets(Container & arr);

void FindSensorReadings(Container & arr, int idx);

void MaxGst(Container & arr);

void Adaptor(Predicate fn , Container&arr);

void DeleteObjects(Container & arr);

#endif // FUNCTIONALITIES_H
