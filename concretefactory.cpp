#include "concretefactory.h"

ConcreteFactory::ConcreteFactory()
{

}

RefinedCamera * ConcreteFactory::createCamera(double x, double y, double z, double alpha, double beta, double scale)
{
    return new RefinedCamera(new RefinedCameraImp(Point(x,y,z),alpha,beta,scale));
}
RefinedModel  *ConcreteFactory::createModel()
{
    return new RefinedModel(new RefinedModelImp);
}
