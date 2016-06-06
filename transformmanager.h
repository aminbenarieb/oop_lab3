#ifndef TRANSFORMMANAGER_H
#define TRANSFORMMANAGER_H

#include "basemanager.h"
#include "basetransformer.h"

class TransformManager : BaseManager
{
private:
    BaseTransformer *transformer;

public:
    TransformManager();
    ~TransformManager();

    void transformModel(BaseObject*, const TransformInfo*);
    void transformCamera(BaseObject*, const TransformInfo*);
};

#endif // TRANSFORMMANAGER_H
