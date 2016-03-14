#ifndef PAYCASH_H
#define PAYCASH_H

#include "ipayment.h"

class PayCash : public iPayment
{
public:
    explicit PayCash(int availableMoney);

    virtual void pay(int bill) override;
};

#endif // PAYCASH_H
