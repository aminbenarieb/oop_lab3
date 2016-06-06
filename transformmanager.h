#ifndef TRANSFORMMANAGER_H
#define TRANSFORMMANAGER_H

#include "basemanager.h"
#include "concretetransformer.h"

class TransformManager : BaseManager
{
private:
    BaseTransformer *transformer;

public:
    TransformManager(BaseTransformer *);
    ~TransformManager();

    void transformModel(BaseObject*, const TransformInfo*);
    void transformCamera(BaseObject*, const TransformInfo*);
};

#endif // TRANSFORMMANAGER_H
