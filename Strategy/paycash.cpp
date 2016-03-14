#include "paycash.h"

#include <iostream>

using namespace std;

PayCash::PayCash(int availableMoney)
    : iPayment(availableMoney)
{

}

void PayCash::pay(int bill)
{
    cout << "======CASH======" << endl;
    if (m_money < bill)
    {
        cout << "Customer doesn't have enough money!" << endl;
        return;
    }

    if (m_money > bill)
        cout << "Customer needs change $" << m_money - bill << endl;
    else
        cout << "Customer paid bill sucessfully" << endl;
    m_money -= bill;
}
