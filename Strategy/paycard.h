#ifndef PAYCARD_H
#define PAYCARD_H

#include "ipayment.h"

class PayCard : public iPayment
{
public:
    explicit PayCard(int availableMoney);

    virtual void pay(int bill) override;
};

#endif // PAYCARD_H
