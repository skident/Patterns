#ifndef STATE_H
#define STATE_H

class Machine;

class State
{
public:
    virtual void on(Machine *m);
    virtual void off(Machine *m);

    virtual ~State(){}
};

class ON: public State
{
public:
    ON();
    ~ON();
    void off(Machine *m);
};

class OFF: public State
{
public:
    OFF();
    ~OFF();
    void on(Machine *m);
};



#endif // STATE_H
