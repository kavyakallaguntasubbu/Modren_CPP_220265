#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Device.h"
#include"Smartdevice.h"
#include<functional>

using Predicate = std::function<bool (const Smartdevice*)>;


void CreateObjects(Smartdevice **arr,int size);

void IndexValue(Smartdevice **arr, int size , int idxv);

std::string MaxGSTCost(Smartdevice **arr , int size);

void DeleteHeapobjects(Smartdevice **arr, int size);

void FindIthIndexValue(Smartdevice **arr, unsigned int idx);

void FindMaxGstDeviceId(Smartdevice **arr, unsigned int idx);

void FilterDevices(Predicate fn , const Smartdevice **arr , const unsigned int size);

/*
    filter smart devices and display details of devices passing the filter criteria
    Criteria is provided by the user

    example : show details of all devices whose with price over 6000.0f
*/

#endif // FUNCTIONALITIES_H
