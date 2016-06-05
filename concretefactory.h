#ifndef CONCRETEFABRIC_H
#define CONCRETEFABRIC_H

#include "abstractfactory.h"
#include "concretecamera.h"
#include "concretemodel.h"

class ConcreteFactory : public AbstractFactory
{
public:
    ConcreteFactory();

    virtual RefinedCamera *createCamera(double, double, double, double, double, double);
    virtual RefinedModel  *createModel();

};

#endif // CONCRETEFABRIC_H
