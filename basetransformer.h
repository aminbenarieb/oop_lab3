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
    virtual void transformPoint(Point* const) const = 0;
    virtual void transformParams(double*,double*,double*) const = 0;

    virtual double getBeta() const
    {
        return beta;
    }
    virtual void setBeta(double value)
    {
        this->beta = value;
    }

    virtual double getDelta() const
    {
        return delta;
    }
    virtual void setDelta(double value)
    {
        this->delta = value;
    }

    virtual double getScale() const
    {
        return scale;
    }
    virtual void setScale(double value)
    {
        this->scale = value;
    }

};

#endif // BASETRANSFORMER_H
