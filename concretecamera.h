#ifndef REFINEDCAMERA_H
#define REFINEDCAMERA_H

#include "basecamera.h"

class RefinedCameraImp : public CameraImp
{
private:
    Point center;
    double alpha;
    double beta;
    double scale;

public:
    RefinedCameraImp(Point,double, double, double);
    ~RefinedCameraImp();

    virtual double getAlpha();
    virtual double getBeta();
    virtual double getScale();
    virtual Point getCenter();

    virtual void transform(const BaseTransformer&);
};


class RefinedCamera : public BaseCamera
{
public:
    RefinedCamera(CameraImp*);
    ~RefinedCamera();

    double getAlpha();
    double getBeta();
    double getScale();
    virtual Point getCenter();

    virtual void transform(const BaseTransformer&);

};

#endif // REFINEDCAMERA_H
