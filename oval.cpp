#include "oval.h"
Oval::Oval(QColor fillColor, QColor penColor, float penWidth, float startX , float startY , float radiusX, float radiusY):Shape(fillColor,penColor,penWidth,startX,startY)
{
    this->radiusX=radiusX;
    this->radiusY=radiusY;
};

Oval::~Oval()
{
}

float Oval::getRadiusX()
{
    return radiusX;
}

float Oval::getRadiusY()
{
    return radiusY;
}

void Oval::scale(float scalar)
{
    radiusX=radiusX/scalar;
    radiusY=radiusY/scalar;
}

void Oval::offset(float a, float b)
{
    startX=startX+a;
    startY=startY+b;
}

void Oval::draw()
{}
