#ifndef TESTER_H
#define TESTER_H

#include "facade.h"

class Tester
{
private:
    Facade *facade;
    QApplication *app;

public:
    Tester(Facade *, QApplication*);
    ~Tester();

    void setFacade(Facade *);
    void loadModel();
    void loadCamera();
    void drawScene();
    void transformModel();
    void transformCamera();
};

#endif // TESTER_H
