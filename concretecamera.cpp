#include "concretecamera.h"
#include "basetransformer.h"

ConcreteCameraImp::ConcreteCameraImp(Point center, double alpha, double beta, double scale)
{
    this->center = center;
    this->alpha = alpha;
    this->beta = beta;
    this->scale = scale;
}
ConcreteCameraImp::~ConcreteCameraImp()
{
}

double    ConcreteCameraImp::getAlpha()
{
    return this->alpha;
}
double    ConcreteCameraImp::getBeta()
{
    return this->beta;
}
double    ConcreteCameraImp::getScale()
{
    return this->scale;
}
Point ConcreteCameraImp::getCenter()
{
    return this->center;
}



ConcreteCamera::ConcreteCamera(CameraImp* imp)
{
    this->imp = imp;
}
ConcreteCamera::~ConcreteCamera()
{
    delete this->imp;
}

double    ConcreteCamera::getAlpha()
{
    return this->imp->getAlpha();
}
double    ConcreteCamera::getBeta()
{
    return this->imp->getBeta();
}
double    ConcreteCamera::getScale()
{
    return this->imp->getScale();
}
Point ConcreteCamera::getCenter()
{
    return this->imp->getCenter();
}
