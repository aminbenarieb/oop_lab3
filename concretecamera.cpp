#include "concretecamera.h"
#include "basetransformer.h"

RefinedCameraImp::RefinedCameraImp(Point center, double alpha, double beta, double scale)
{
    this->center = center;
    this->alpha = alpha;
    this->beta = beta;
    this->scale = scale;
}
RefinedCameraImp::~RefinedCameraImp()
{
}

double    RefinedCameraImp::getAlpha()
{
    return this->alpha;
}
double    RefinedCameraImp::getBeta()
{
    return this->beta;
}
double    RefinedCameraImp::getScale()
{
    return this->scale;
}
Point RefinedCameraImp::getCenter()
{
    return this->center;
}
void      RefinedCameraImp::transform(const BaseTransformer& transformer)
{
    transformer.transformParams(&alpha, &beta, &scale);
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
    return this->imp->getBeta();
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
