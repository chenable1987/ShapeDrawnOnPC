#ifndef OVAL_H
#define OVAL_H
#include "shape.h"

class Oval : public Shape
{
public:
    Oval(QColor fillColor=Qt::red, QColor penColor=Qt::blue, float penWidth=1.0f, float startX=0 , float startY=0 , float radiusX=80, float radiusY=40);
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
