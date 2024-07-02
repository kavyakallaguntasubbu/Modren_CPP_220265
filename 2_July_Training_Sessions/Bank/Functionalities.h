#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include<vector>
#include"BankAccount.h"

using Container = std::vector<BankAccount*>;

void CreateObjcets(Container & arr);

void ShowCreditCardDetails(Container & arr,  long no);

void ContOFDebitCardwithVISA(Container & arr);

void DeleteObjects(Container  & arr);

void Debit()

#endif // FUNCTIONALITIES_H
