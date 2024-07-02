#include "Functionalities.h"

int main()
{
    Container arr;
    CreateObjcets(arr);
    FindSensorReadings(arr, 104);
    auto fn = [](SmartDevice *arr)
    {
        float percentage{0};
        if (arr->device() == DeviceTechnology::BLUETOOTH)
        {
            percentage = arr->price() * 0.10;
        }
        else if (arr->device() == DeviceTechnology::WIFI || arr->device() == DeviceTechnology::WIFI_BLUETOOTH)
        {
            percentage = arr->price() * 0.05;
        }
        else
        {
            percentage = arr->price() * 0.03;
        }
        return percentage;
    };
    Adaptor(fn,arr);
    
    DeleteObjects(arr);
}