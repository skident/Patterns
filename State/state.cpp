#include "state.h"
#include <iostream>
#include "machine.h"

using namespace std;


void State::on(Machine *m)
{
    cout << "   already ON\n";
}

void State::off(Machine *m)
{
    cout << "   already OFF\n";
}


ON::ON()
{
    cout << "   ON-ctor " << endl;
}

ON::~ON()
{
    cout << "   dtor-ON" << endl;;
}

void ON::off(Machine *m)
{
    cout << "   going from ON to OFF" << endl;;
    m->setCurrent(shared_ptr<State>(new OFF()));
}


OFF::OFF()
{
    cout << "   OFF-ctor " << endl;;
}

OFF::~OFF()
{
    cout << "   dtor-OFF" << endl;;
}

void OFF::on(Machine *m)
{
    cout << "   going from OFF to ON" << endl;;
    m->setCurrent(shared_ptr<State>(new ON()));
}
