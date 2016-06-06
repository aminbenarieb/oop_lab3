#ifndef REFINEDCAMERA_H
#define REFINEDCAMERA_H

#include "basecamera.h"

class ConcreteCameraImp : public CameraImp
{
private:
    Point center;
    double alpha;
    double beta;
    double scale;

public:
    ConcreteCameraImp(Point,double, double, double);
    ~ConcreteCameraImp();

    virtual double getAlpha();
    virtual double getBeta();
    virtual double getScale();
    virtual Point getCenter();

    virtual void transform(const BaseTransformer&);
};


class ConcreteCamera : public BaseCamera
{
public:
    ConcreteCamera(CameraImp*);
    ~ConcreteCamera();

    double getAlpha();
    double getBeta();
    double getScale();
    virtual Point getCenter();

    virtual void transform(const BaseTransformer&);

};

#endif // REFINEDCAMERA_H
