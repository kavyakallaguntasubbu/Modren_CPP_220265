#include "DebitCared.h"

DebitCared::DebitCared(short cvv, std::string expirydate, long long cardNumber, DebitCardtype type)
    :m_card_cvv{cvv},m_card_expiry_date{expirydate},m_card_number{cardNumber},m_card_type{type}
{
}