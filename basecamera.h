#ifndef BASECAMERA_H
#define BASECAMERA_H

#include "baseobject.h"
#include "point.h"

class CameraImp
{
public:
    virtual ~CameraImp() {}

    virtual Point getCenter() = 0;
    virtual double getAlpha() = 0;
    virtual double getBeta() = 0;
    virtual double getScale() = 0;

    virtual void transform(const BaseTransformer&) = 0;
};

class BaseCamera : public BaseObject
{
protected:
    CameraImp* imp;

public:
    virtual ~BaseCamera(){};

    virtual Point getCenter() = 0;
    virtual void transform(const BaseTransformer&) = 0;
};

#endif // BASECAMERA_H
