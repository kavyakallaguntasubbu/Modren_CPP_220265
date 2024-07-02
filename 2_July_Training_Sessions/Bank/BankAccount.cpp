#include "BankAccount.h"

BankAccount::BankAccount(long long acno, std::string acname, float balance, BankAccountType btype, DebitCared card)
    :m_accountNumber{acno},m_accountHolderName{acname},m_accountBalance{balance},m_accountType{btype},m_attached_card{card}
{
}