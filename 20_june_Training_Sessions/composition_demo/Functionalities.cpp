#include "Functionalities.h"

void CreateObjects(BankAccount **accounts, const unsigned int size)
{
    accounts[0] = new BankAccount(908819191, "XYZ", 8990.0f, BankAccountType::SAVINGS, DebitCard(111, "19/12", 111122223333444, DebitCardType::MASTERCARD));
}


/*
    A function to find and display the details of debitcard for account whose number is provided as parameter
*/


void DisplayCardDetails(BankAccount** accounts, unsigned int size, long number){
    
    bool flag = false;
    for(unsigned int i = 0; i < size; i++) {
        if ( accounts[i]->accountNumber() == number   ) {
            std::cout << accounts[i]->attachedCard() << "\n";
            true;
            break;
        }
    }

    if (!flag){
        throw AccountNotFoundException("Invalid number");
    }
}

/*
    Find and display the count of DebitCard with type = VISA
*/


void CountVISACards( BankAccount** accounts, unsigned int size ){
    unsigned int count = 0;
    for(unsigned int i = 0; i < size; i++) {

        /*
            if i position account fetches debitcard and then checks type of debit
            card and it is VISA, increase count by 1
        */
        if (accounts[i]->attachedCard().cardType() == DebitCardType::VISA){
            count++;
        }
    }

    std::cout << "Count is: " << count << "\n";
}