#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include "basecamera.h"
#include "basemodel.h"

class AbstractFactory
{
public:
    ~AbstractFactory();

    virtual BaseCamera *createCamera(double, double, double, double, double, double) = 0;
    virtual BaseModel  *createModel() = 0;

};

#endif // ABSTRACTFACTORY_H
