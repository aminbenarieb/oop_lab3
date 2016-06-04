#ifndef BASEMODEL_H
#define BASEMODEL_H

#include "baseobject.h"

class ModelImp
{
    virtual ~ModelImp() {}
    virtual void transform(const TransformerManager&) = 0;
};

class BaseModel : public BaseObject
{
protected:
    ModelImp* imp;

public:
    virtual void transform(const TransformerManager&) = 0;

    virtual void addPoint(Point&) = 0;
    virtual void addEdge(Edge&) = 0;

    virtual size_t pointCount() const = 0;
    virtual size_t edgeCount() const = 0;

};

#endif // BASEMODEL_H
