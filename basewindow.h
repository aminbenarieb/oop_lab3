#ifndef BASEWINDOW_H
#define BASEWINDOW_H

class BaseWindow
{

public:
    virtual ~BaseWindow(){}

    virtual void display() = 0;

};

#endif // BASEWINDOW_H
