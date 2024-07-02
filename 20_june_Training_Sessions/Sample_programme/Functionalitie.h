#ifndef FUNCTIONALITIE_H
#define FUNCTIONALITIE_H

#include"Engine.h"
#include<vector>

// using keword 

using Container = std::vector<Engine *>;

void CreateObjects(Container&arr);

float AverageHorsePower(const Container&arr);

void FindTorqueById(Container&arr,int id);

void FindHorsepowerForMinTorqueEngine(Container&arr);

void DeleteObjects(Container&arr);

#endif 


