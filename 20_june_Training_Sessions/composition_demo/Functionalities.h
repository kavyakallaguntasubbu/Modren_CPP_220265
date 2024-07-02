#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "BankAccount.h"
#include "AccountNotFoundException.h"

#include<vector>

using Container = std::vector<BankAccount *>;

void CreateObjects(Container & accounts);

void DisplayCardDetails(Container & accounts,long number);



#endif // FUNCTIONALITIES_H
