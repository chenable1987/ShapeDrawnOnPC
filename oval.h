#ifndef OVAL_H
#define OVAL_H
#include "shape.h"

class Oval : public Shape
{
public:
    Oval(float pw, float sx, float sy, float rx, float ry):Shape(pw,sx,sy),radiusX(rx),radiusY(ry){};
    ~Oval();
    float getStartX();
    float getStartY();
    float getRadiusX();
    float getRadiusY();
    void scale(float scalar);
    void offset(float a, float b);
    void draw();
private:
    float radiusX;
    float radiusY;
};

#endif // OVAL_H
