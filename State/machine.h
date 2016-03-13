#ifndef MACHINE_H
#define MACHINE_H

#include "state.h"
#include <memory>

class Machine
{
    std::shared_ptr<State> current;

public:
    Machine();
    ~Machine();

    void setCurrent(std::shared_ptr<State> s);

    void on();
    void off();
};


#endif // MACHINE_H
