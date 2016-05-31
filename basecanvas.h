#ifndef BASECANVAS_H
#define BASECANVAS_H

class BaseCanvas
{
public:
    virtual ~BaseCanvas() {}

    virtual void clear() = 0;
    virtual void draw_line(double x1, double y1, double x2, double y2) = 0;
    virtual void draw_point(double x, double y) = 0;

    virtual bool exists() = 0;
};

#endif // BASECANVAS_H
