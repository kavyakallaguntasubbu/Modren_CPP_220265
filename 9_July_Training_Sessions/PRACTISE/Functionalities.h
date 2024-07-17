#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Engine.h"
#include<list>
#include<memory>
#include<functional>


using ptrContainer = std::shared_ptr<const Engine>;
using Container = std::list<ptrContainer>;
using Predicate = std::function<bool(const ptrContainer)>;


/*
    CreateObjects
    input : Empty container reference
    output : void
*/
void CreateObjects(Container & arr);

/*
    ReturnMatchingInstances
    input : Data container refernce , function wrapper for predicate
    output : DataContainer OF Matching instances
*/

std::optional<Container> FilterFunction(const Predicate &fn ,const Container & arr);

/*
    ifatleastOnefunctionmeet

    input : Data container refernce , function wrapper for predicate
    ouput : bool
*/

bool IfatleatOneFunctionMeet(const Predicate &fn , const Container & arr);

/*
    AverageEngineCC

    input : Data Container refernce
    output : value
*/

float AverageEngineCC(const Container & arr);


#endif // FUNCTIONALITIES_H
