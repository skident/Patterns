#include "paycard.h"
#include <iostream>

using namespace std;

PayCard::PayCard(int availableMoney)
    : iPayment(availableMoney)
{

}

void PayCard::pay(int bill)
{
    cout << "=====CARD=====" << endl;
    if (m_money >= bill)
    {
        m_money -= bill;
        cout << "Customer paid for bill sucessfully" << endl;
    }
    else
        cout << "Customer used credit limit for pay" << endl;
}

