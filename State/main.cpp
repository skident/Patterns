#include <iostream>
#include "machine.h"
#include "state.h"

int main()
{
    Machine fsm;
    int num;
    while (1)
    {
        std::cout << "Enter 0/1: ";
        std::cin >> num;
        if (num == 0)
            fsm.off();
        else
            fsm.on();
    }
}
