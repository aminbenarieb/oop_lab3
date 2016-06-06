#include "transformmanager.h"
#include "concretetransformer.h"

#include "basemodel.h"
#include "basecamera.h"


TransformManager::TransformManager()
{
    this->transformer = new ConcreteTransformer();
}
TransformManager::~TransformManager()
{
    delete this->transformer;
}

void TransformManager::transformModel(BaseObject*, const TransformInfo*)
{

//    BaseModel *model = static_cast<BaseModel*>(object);

//    foreach modelPoint in modelPoint
//        this->transformer->transformPoint( modelPoint, tranformInfo );


}

void TransformManager::transformCamera(BaseObject*, const TransformInfo*)
{

//    this->transformer->transformParams( camera.params , transformInfo );

}
