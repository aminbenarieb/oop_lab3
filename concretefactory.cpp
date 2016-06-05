#include "concretefactory.h"

ConcreteFactory::ConcreteFactory()
{

}

RefinedCamera * ConcreteFactory::createCamera()
{
//    return new RefinedCamera(new RefinedCameraImp); //how to constuct?
}
RefinedModel  *ConcreteFactory::createModel()
{
    return new RefinedModel(new RefinedModelImp);
}
