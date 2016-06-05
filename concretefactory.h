#ifndef CONCRETEFABRIC_H
#define CONCRETEFABRIC_H

#include "abstractfactory.h"
#include "concretecamera.h"
#include "concretemodel.h"

class ConcreteFactory : public AbstractFactory
{
public:
    ConcreteFactory();

    virtual RefinedCamera *createCamera();
    virtual RefinedModel  *createModel();

};

#endif // CONCRETEFABRIC_H
