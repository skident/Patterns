#ifndef IPAYMENT_H
#define IPAYMENT_H

class iPayment
{
protected:
    int m_money;

public:
    explicit iPayment(int availableMoney);
    virtual ~iPayment();

    virtual void pay(int bill) = 0;
};

#endif // IPAYMENT_H
