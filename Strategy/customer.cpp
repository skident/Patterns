#include "customer.h"


Customer::Customer(std::shared_ptr<iPayment> paymentType)
    : m_paymentType(paymentType)
{

}

void Customer::pay(int bill)
{
    m_paymentType->pay(bill);
}
