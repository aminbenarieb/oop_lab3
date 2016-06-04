#ifndef BASETRANSFORMER_H
#define BASETRANSFORMER_H

#include "matrix.h"
#include "point.h"

class BaseTransformer
{
protected:
    double delta;
    double beta;
    double scale;

public:
    BaseTransformer() : delta(0), beta(0), scale(0) {}
    BaseTransformer(double _delta) : delta(_delta), beta(0), scale(0) {}
    BaseTransformer(double _delta, double _beta, double _scale) : delta(_delta), beta(_beta), scale(_scale) {}

    virtual ~BaseTransformer() {}

    static double convertRadToDeg(double angle) { return (angle * M_PI) / 180.0; }
    virtual void transformPoint(Point* const p) const = 0;

    virtual double getBeta() const;
    virtual void setBeta(double value);

    virtual double getDelta() const;
    virtual void setDelta(double value);

    virtual double getScale() const;
    virtual void setScale(double value);

};

#endif // BASETRANSFORMER_H

double BaseTransformer::getDelta() const
{
    return delta;
}
void BaseTransformer::setDelta(double value)
{
    delta = value;
}

double BaseTransformer::getScale() const
{
return scale;
}
void BaseTransformer::setScale(double value)
{
scale = value;
}

double BaseTransformer::getBeta() const
{
    return beta;
}
void BaseTransformer::setBeta(double value)
{
    beta = value;
}
