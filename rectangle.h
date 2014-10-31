#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(float pw, float sx, float sy, float w,float h):Shape(pw,sx,sy),width(w),height(h){};
    ~Rectangle();
    void scale(float scalar);
    void offset(float a, float b);
    void draw();

private:
    float width;
    float height;
};

#endif // RECTANGLE_H
