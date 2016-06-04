#include "point.h"
#include "basetransformer.h"

Point::Point() {}
Point::Point(const Point &point)
{
    *this = point;
}
Point::Point(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
Point& Point::operator =(const Point& point)
{
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;
    return *this;
}

Point::~Point() {}


double Point::getX() const
{
    return x;
}
void Point::setX(double value)
{
    x = value;
}

double Point::getY() const
{
    return y;
}
void Point::setY(double value)
{
    y = value;
}

double Point::getZ() const
{
    return z;
}
void Point::setZ(double value)
{
    z = value;
}


bool Point::operator==(const Point& point)
{
    return ( this->x == point.getX()) && (this->y ==  point.getY()) && ( this->z == point.getZ() );
}
bool Point::operator!=(const Point& point)
{
    return !(*this == point);
}


void Point::getCoordList(double list[4])
{
    list[0] = this->x;
    list[1] = this->y;
    list[2] = this->z;
    list[3] = 1;
}
void Point::setCoordList(double list[4])
{
    this->x = list[0];
    this->y = list[1];
    this->z = list[2];
}

void Point::transform(const BaseTransformer& transformer)
{
    transformer.transformPoint(this);
}
