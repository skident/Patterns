#include "machine.h"

Machine::Machine()
{
    current = std::shared_ptr<State>(new OFF());
}

Machine::~Machine()
{

}

void Machine::setCurrent(std::shared_ptr<State> s)
{
    current = s;
}

void Machine::on()
{
    current->on(this);
}

void Machine::off()
{
    current->off(this);
}

