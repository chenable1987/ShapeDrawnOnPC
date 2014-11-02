#include "oval.h"

Oval::~Oval()
{
}
float Oval::getStartX()
{
    return startX;
}

float Oval::getStartY()
{
    return startY;
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
