#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include"BankaccoutType.h"
#include<iostream>
#include"DebitCared.h"

class BankAccount
{
private:
    long m_accountNumber{0};
    std::string m_accountHolderName{""};
    float m_accountBalance{0.0};
    BankAccountType m_accountType{BankAccountType::OTHER};
    DebitCared m_attached_card;
public:
    BankAccount(/* args */)  = default;
    ~BankAccount() = default;
    BankAccount (const BankAccount &) = default;
    BankAccount ( BankAccount &&) = delete;
    BankAccount & operator = (const BankAccount &) = delete;
    BankAccount & operator = ( BankAccount &&) = delete;

    BankAccount(long long acno,std::string acname, float balance,BankAccountType btype, DebitCared card);

    long accountNumber() const { return m_accountNumber; }

    DebitCared attachedCard() const { return m_attached_card; }

    BankAccountType accountType() const { return m_accountType; }

    friend std::ostream &operator<<(std::ostream &os, const BankAccount &rhs) {
        os << "m_accountNumber: " << rhs.m_accountNumber
           << " m_accountHolderName: " << rhs.m_accountHolderName
           << " m_accountBalance: " << rhs.m_accountBalance
           << " m_accountType: " << static_cast<std::underlying_type<BankAccountType>::type>(rhs.accountType())
           << " m_attached_card: " << rhs.m_attached_card;
        return os;
    }

    

};

#endif // BANKACCOUNT_H
