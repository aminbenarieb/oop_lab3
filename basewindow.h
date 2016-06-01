#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include "facade.h"

class BaseWindow
{

protected:
    Facade *facade;

public:
    virtual ~BaseWindow(){}

    virtual void display() = 0;

};

#endif // BASEWINDOW_H
