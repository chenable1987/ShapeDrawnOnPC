#include "rectangle.h"

Rectangle::~Rectangle()
{}

void Rectangle::scale(float scalar)
{
    width=width/scalar;
    height=height/scalar;
}

void Rectangle::offset(float a, float b)
{
    Shape::startX=startX+a;
    Shape::startY=startY+b;
}

void Rectangle::draw()
{}
