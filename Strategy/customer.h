#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "ipayment.h"
#include <memory>

class Customer
{
    std::shared_ptr<iPayment> m_paymentType;
public:
    Customer(std::shared_ptr<iPayment> paymentType);

    void pay(int bill);
};

#endif // CUSTOMER_H
