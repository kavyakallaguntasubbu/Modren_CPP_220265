#ifndef DEBITCARED_H
#define DEBITCARED_H

#include<iostream>
#include"DebitCardType.h"

class DebitCared
{
private:
    short m_card_cvv{0};
    std::string m_card_expiry_date{""};
    long long m_card_number{0};
    DebitCardtype m_card_type{DebitCardtype::AMEX};
public:
    DebitCared() = default;
    ~DebitCared() = default;
    DebitCared (const DebitCared &) = default;
    DebitCared ( DebitCared &&) = default;
    DebitCared & operator = (const DebitCared &) = default;
    DebitCared & operator = ( DebitCared &&) = delete;

    DebitCared(short cvv, std::string expirydate, long long cardNumber,DebitCardtype type);

    DebitCardtype cardType() const { return m_card_type; }

    friend std::ostream &operator<<(std::ostream &os, const DebitCared &rhs) {
        os << "m_card_cvv: " << rhs.m_card_cvv
           << " m_card_expiry_date: " << rhs.m_card_expiry_date
           << " m_card_number: " << rhs.m_card_number
           << " m_card_type: " <<static_cast<std::underlying_type<DebitCardtype>::type>(rhs.cardType()) ;
        return os;
    }

    

};

#endif // DEBITCARED_H
