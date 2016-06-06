#ifndef CONCRETEFABRIC_H
#define CONCRETEFABRIC_H

#include "abstractfactory.h"
#include "concretecamera.h"
#include "concretemodel.h"

class ConcreteFactory : public AbstractFactory
{
public:
    ConcreteFactory();

    virtual ConcreteCamera *createCamera(double, double, double, double, double, double);
    virtual ConcreteModel  *createModel();

};

#endif // CONCRETEFABRIC_H
