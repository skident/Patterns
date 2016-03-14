#include <iostream>
#include "customer.h"
#include "paycard.h"
#include "paycash.h"

using namespace std;

int main()
{
    {
    std::shared_ptr<PayCard> card(new PayCard(250));
    Customer igor(card);
    igor.pay(100);
    igor.pay(150);
    igor.pay(10);
    }

    {
    Customer tolya(std::make_shared<PayCash>(130));
    tolya.pay(100);
    tolya.pay(30);
    tolya.pay(10);
    }

    return 0;
}

