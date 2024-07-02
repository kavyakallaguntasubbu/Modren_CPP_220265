#include"Functionalities.h"

int main(){
    Smartdevice *arr[3];
    CreateObjects(arr,3);
    try
    {
        IndexValue(arr,3,1);
    }
    catch( std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        std::string gst = MaxGSTCost(arr,3);
        std::cout<<"Max Gst " << gst << std::endl;
    }
    catch( std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    for(int i = 0 ; i< 3;i++){
        std::cout<< *arr[i] << std::endl;
    }

    FilterDevices([](const Smartdevice *s) { return s->price() > 6000.0f;} , arr ,3);
    FilterDevices([](const Smartdevice *s) {
         return s->type() == DeviceType::BLUETOOTH ;} ,
          arr ,
          3
        );


    DeleteHeapobjects(arr,3);
}