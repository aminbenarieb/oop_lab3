#ifndef BASECAMERA_H
#define BASECAMERA_H

#include "baseobject.h"
#include "basepoint.h"

class CameraImp
{
    virtual ~CameraImp() {}
    virtual BasePoint devGetCenter() = 0;
    virtual double devGetAlpha() = 0;
    virtual double devGetBeta() = 0;
    virtual double devGetScale() = 0;
    virtual void transform(const TransformerManager&) = 0;
};

class BaseCamera : public BaseObject
{
protected:
    CameraImp* imp;

public:
    virtual ~BaseCamera() {}
//    virtual BaseCamera(CameraImp *);
    virtual BasePoint getCenter() = 0;
    virtual void transform(const TransformerManager&) = 0;
};

#endif // BASECAMERA_H
