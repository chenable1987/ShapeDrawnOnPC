#ifndef SHAPE_H
#define SHAPE_H
#include <qcolor.h>

class Shape
{
public:
    Shape(QColor fillColor=Qt::white, QColor penColor=Qt::blue, float penWidth=1.0f, float startX=0, float startY=0);
    virtual ~Shape();
    QColor getFillColor();
    QColor getPenColor();
    float getPenWidth();
    float getStartX();
    float getStartY();
    virtual void scale(float scalar);
    virtual void offset(float a, float b);
    virtual void draw();

protected:
    QColor fillColor;
    QColor penColor;
    float penWidth;

    float startX;
    float startY;
};

#endif // SHAPE_H
