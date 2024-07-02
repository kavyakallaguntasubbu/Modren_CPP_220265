#include"Functionalitie.h"
#include"IdnotFond.h"
#include"NoValidEngineFoundException.h"

int main(){
    Container arr;
    CreateObjects(arr);
    try
    {
         float avg = AverageHorsePower(arr);
        std::cout<<"Avg Power :" <<avg <<std::endl;
    }
    catch(std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(NoValidEngineFoundException& e)
    {
        std::cerr << e.what() << '\n';
    }

    
    try
    {
        FindTorqueById(arr,1);
    }
    catch(std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(IdnotFond& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        FindHorsepowerForMinTorqueEngine(arr);   
    }
    catch(std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
   DeleteObjects(arr);
}