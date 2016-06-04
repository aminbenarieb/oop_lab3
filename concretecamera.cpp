#include "concretecamera.h"


RefinedCameraImp::RefinedCameraImp(Point,double, double, double)
{
}
RefinedCameraImp::~RefinedCameraImp()
{
}

double    RefinedCameraImp::getAlpha(){

}
double    RefinedCameraImp::getBeta(){

}
double    RefinedCameraImp::getScale(){

}
Point RefinedCameraImp::getCenter(){

}
void      RefinedCameraImp::transform(const BaseTransformer&){

}



RefinedCamera::RefinedCamera(CameraImp* imp)
{
    this->imp = imp;
}
RefinedCamera::~RefinedCamera()
{
    delete this->imp;
}

double    RefinedCamera::getAlpha()
{
    return this->imp->getAlpha();
}
double    RefinedCamera::getBeta()
{
    return this->imp->geetBeta();
}
double    RefinedCamera::getScale()
{
    return this->imp->getScale();
}
Point RefinedCamera::getCenter()
{
    return this->imp->getCenter();
}
void      RefinedCamera::transform(const BaseTransformer& transformManager)
{
    this->imp->transform(transformManager);
}
