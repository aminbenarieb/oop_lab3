#include "transformmanager.h"

#include "basemodel.h"
#include "basecamera.h"


TransformManager::TransformManager(BaseTransformer *transformer)
{
    this->transformer = transformer;
}
TransformManager::~TransformManager()
{
    delete this->transformer;
}

void TransformManager::transformModel(BaseObject* object, const TransformInfo *transformInfo)
{

    BaseModel *model = static_cast<BaseModel*>(object);
    for (Iterator<Point> it(model->getPoints()); !it.isDone(); it++)
    {
        this->transformer->transformPoint(&(*it), transformInfo);
    }

}

void TransformManager::transformCamera(BaseObject*, const TransformInfo*)
{

//    this->transformer->transformParams( camera.params , transformInfo );

}
