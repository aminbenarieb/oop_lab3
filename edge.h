#ifndef BASEEDGE_H
#define BASEEDGE_H


#include "baseobject.h"
#include "point.h"

class BaseTransformer;

class Edge : public BaseObject
{
private:
    Point* firstPoint;
    Point* lastPoint;

public:
    Edge();
    Edge(Point*, Point*);

    ~Edge();

    bool operator==(const Edge&);
    bool operator!=(const Edge&);

    Point *getFirstPoint() const;
    void setFirstPoint(Point *value);
    Point *getLastPoint() const;
    void setLastPoint(Point *value);
};

#endif // BASEEDGE_H
