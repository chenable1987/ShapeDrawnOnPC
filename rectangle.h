#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(QColor fillColor, QColor penColor, float penWidth, float startX, float startY, float width,float height);
    ~Rectangle();
    float getWidth();
    float getHeight();
    void scale(float scalar);
    void offset(float a, float b);
    void draw();

private:
    float width;
    float height;
};

#endif // RECTANGLE_H
