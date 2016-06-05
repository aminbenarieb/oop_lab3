#ifndef TESTER_H
#define TESTER_H

#include "facade.h"

class Tester
{
private:
    Facade *facade;

public:
    Tester(Facade *);
    ~Tester();

    void setFacade(Facade *);
    void loadModel();
};

#endif // TESTER_H
