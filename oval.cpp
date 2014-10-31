#include "oval.h"

Oval::~Oval()
{
}

void Oval::scale(float scalar)
{
    radiusX=radiusX/scalar;
    radiusY=radiusY/scalar;
}

void Oval::offset(float a, float b)
{
    Shape::startX=startX+a;
    Shape::startY=startY+b;
}

void Oval::draw()
{}
