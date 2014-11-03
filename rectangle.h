#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(QColor fillColor=Qt::red, QColor penColor=Qt::blue, float penWidth=1.0f, float startX=0 , float startY=0 , float width=200, float height=200);
    ~Rectangle();
    float getStartX();
    float getStartY();
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
