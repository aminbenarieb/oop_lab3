#include "concretefactory.h"

ConcreteFactory::ConcreteFactory()
{

}

ConcreteCamera * ConcreteFactory::createCamera(double x, double y, double z, double alpha, double beta, double scale)
{
    return new ConcreteCamera(new ConcreteCameraImp(Point(x,y,z),alpha,beta,scale));
}
ConcreteModel  *ConcreteFactory::createModel()
{
    return new ConcreteModel(new ConcreteModelImp);
}
