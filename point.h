#ifndef POINT_H
#define POINT_H

#include "baseobject.h"

class Point : public BaseObject
{
private:
    double x;
    double y;
    double z;

public:
    Point();
    Point(double, double, double);
    Point(const Point&);
    Point& operator=(const Point&);

    ~Point();


    bool operator==(const Point&);
    bool operator!=(const Point&);


    void getCoordList(double lst[4]);
    void setCoordList(double lst[4]);

    void transform(const BaseTransformer&);

    double getX() const;
    void setX(double value);
    double getY() const;
    void setY(double value);
    double getZ() const;
    void setZ(double value);
};

#endif // POINT_H
