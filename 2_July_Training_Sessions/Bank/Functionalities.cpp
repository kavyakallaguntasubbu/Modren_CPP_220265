#include"Functionalities.h"

void CreateObjcets(Container & arr){
    arr.emplace_back(new BankAccount(2220265,"Kavya",23000.0,BankAccountType::SALARY,DebitCared(25,"12/3/25",345266,DebitCardtype::VISA)));
    arr.emplace_back(new BankAccount(2220266,"Kavya",23000.0,BankAccountType::SAVINGS,DebitCared(26,"12/3/25",345266,DebitCardtype::AMEX)));
    arr.emplace_back(new BankAccount(2220267,"Kavya",23000.0,BankAccountType::OTHER,DebitCared(27,"12/3/25",345266,DebitCardtype::DINERSCLUB)));
    arr.emplace_back(new BankAccount(2220268,"Kavya",23000.0,BankAccountType::SALARY,DebitCared(28,"12/3/25",345266,DebitCardtype::MASTERCARD)));
    arr.emplace_back(new BankAccount(2220269,"Kavya",23000.0,BankAccountType::SAVINGS,DebitCared(29,"12/3/25",345266,DebitCardtype::VISA)));
    
}

void ShowCreditCardDetails(Container & arr,  long no){

    for(BankAccount * e : arr){
        if(e ->accountNumber() == no){
            std::cout<< e->attachedCard() <<std::endl;
        }
    }
}

void ContOFDebitCardwithVISA(Container & arr){
    int count{0};
    for(BankAccount * e : arr){
        if(e->attachedCard().cardType() == DebitCardtype::VISA){
            count++;
        }
    }
    std::cout<<"Count :" << count << std::endl;
}

void DeleteObjects(Container  & arr){
    for(BankAccount * e : arr){
        delete e;
    }
}