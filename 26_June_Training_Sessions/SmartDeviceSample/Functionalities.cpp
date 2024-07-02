#include "Functionalities.h"
#include "DeviceTechnology.h"
#include "SmartDevice.h"
void CreateObjcets(Container &arr)
{
    std::string id;
    std::string name;
    float price;
    DeviceTechnology technology{DeviceTechnology::OTHER};
    int choice;
    for (int i = 0; i < 3; i++)
    {
        std::cin >> id;
        std::cin >> name;
        std::cin >> price;
        std::cin >> choice;
        switch (choice)
        {
        case 0:
            technology = DeviceTechnology::BLUETOOTH;
            break;
        case 1:
            technology = DeviceTechnology::WIFI;
            break;
        case 2:
            technology = DeviceTechnology::WIFI_BLUETOOTH;
            break;

        default:
            technology = DeviceTechnology::OTHER;
            break;
        }
        float *arr1 = new float[3];
        for (int i = 0; i < 3; i++)
        {
            float arrv;
            std::cin >> arrv;
            arr1[i] = arrv;
        }

        arr.emplace_back(new SmartDevice(id, name, price, technology, arr1));
    }
}

void FindSensorReadings(Container &arr, int idx)
{

    for (SmartDevice *e : arr)
    {
        if (idx >= 0 && idx < 3)
        {
            std::cout << (*e)[idx] << std::endl;
        }
    }
}

// void MaxGst(Container &arr)
// {
//     std::string id{""};
//     float Max{0.0};
//     for (SmartDevice *e : arr)
//     {
//         if (Max <= e->CalculateGstCost())
//         {
//             Max = e->CalculateGstCost();
//             id = e->iD();
//         }
//     }
//     std::cout << "The Max Cost ID :" << id << std::endl;
// }

void Adaptor(Predicate fn , Container&arr){

    float Max{0.0};
    SmartDevice *d;
    for(SmartDevice * e : arr){
        if(fn(e) > Max){
            Max = fn(e);
            d = e;
        }
    }
    std::cout<< d->iD() << std::endl;
}

void DeleteObjects(Container &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        delete[] arr[i]->getarr();
        delete arr[i];
    }
}


